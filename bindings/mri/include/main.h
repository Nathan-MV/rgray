#ifndef RAYLIBCRUBY_H
#define RAYLIBCRUBY_H 1

#include "ruby_values.h"
#include "ruby_adapter.h"
#include "rgray/raylib_values.h"

#include "math/rect_bindings.h"
#include "graphics/color_bindings.h"
#include "graphics/draw_bindings.h"
#include "graphics/bitmap_bindings.h"
#include "system/kernel_bindings.h"
#include "graphics/sprite_bindings.h"
#include "graphics/render_texture_bindings.h"
#include "graphics/shader_bindings.h"
#include "math/vec2_bindings.h"
#include "math/vec3_bindings.h"
#include "math/vec4_bindings.h"
#include "math/math_bindings.h"
#include "system/graphics_bindings.h"
#include "graphics/gui_bindings.h"
#include "math/ease_bindings.h"
#include "input/keyboard_bindings.h"
#include "input/mouse_bindings.h"
#include "input/gamepad_bindings.h"
#include "input/touch_bindings.h"
#include "input/gestures_bindings.h"
#include "graphics/shapes_bindings.h"
#include "graphics/font_bindings.h"
#include "audio/audio_bindings.h"
#include "physics/camera_bindings.h"

extern VALUE rb_mRGRAY;
extern VALUE rb_eRGRAYError;

extern "C" {
  void Init_rgray(void);
}

#endif // RAYLIBCRUBY_H
