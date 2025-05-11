#include "main.h"
#include <array>
#include <filesystem>
#include <iostream>
#include <string>

VALUE rb_mRGRAY = Qnil;
VALUE rb_eRGRAYError = Qnil;

extern "C" void Init_rgray(void) {
  rb_mRGRAY = rb_define_module("RGRAY");
  rb_eRGRAYError = rb_define_class_under(rb_mRGRAY, "Error", rb_eStandardError);

  Init_Kernel();

  // Modules
  Init_Graphics();
  Init_Keyboard();
  Init_Mouse();
  Init_Gamepad();
  Init_Touch();
  Init_Gestures();
  Init_Draw();
  Init_Shapes();
  Init_Audio();
  Init_Math();

  // Classes
  Init_Color();
  Init_Rect();
  Init_Circle();
  Init_Vec2();
  Init_Vec3();
  Init_Vec4();
  Init_Shader();
  Init_Sprite();
  Init_RenderTexture();
  Init_Bitmap();
  Init_Font();
  Init_Camera();

  // External
  Init_Gui();
  Init_Ease();
}

std::string determineScriptPath(int argc, char** argv) {
  namespace fs = std::filesystem;

  if (argc > 1) {
    fs::path scriptPath = argv[1];
    if (!scriptPath.has_filename() || scriptPath.extension() != ".rb") {
      if (scriptPath.string().back() != fs::path::preferred_separator) scriptPath += fs::path::preferred_separator;
      scriptPath /= "main.rb";
    }

    if (fs::exists(scriptPath)) return scriptPath.string();
  }

  fs::path fallback = "./main.rb";
  if (fs::exists(fallback)) return fallback.string();

  return {};
}

int initializeRubyInterpreter(const std::string& scriptPath) {
  RUBY_INIT_STACK;
  ruby_init();
  Init_rgray();

  const std::array<const char*, 3> args = {"ruby", scriptPath.c_str(), "--yjit"};

  return ruby_run_node(ruby_options(static_cast<int>(args.size()), const_cast<char**>(args.data())));
}

#ifdef _WIN32
void attachToConsoleIfNeeded() {
  // Attach to parent console if present
  if (AttachConsole(ATTACH_PARENT_PROCESS)) {
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
  }
}
#endif

int main(int argc, char** argv) {
#ifdef HAVE_LOCALE_H
  std::setlocale(LC_CTYPE, "");
#endif

#ifdef _WIN32
  attachToConsoleIfNeeded();
#endif

  std::string scriptPath = determineScriptPath(argc, argv);
  if (scriptPath.empty()) {
    std::cerr << "Error: No valid script found." << std::endl;
    return 1;
  }

  ruby_sysinit(&argc, reinterpret_cast<char***>(&argv));
  return initializeRubyInterpreter(scriptPath);
}
