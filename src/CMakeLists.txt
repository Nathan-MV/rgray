# ----- Add Files -----

set(SRC_FILES
  math/vec2.cpp
  system/kernel.cpp
  graphics/color.cpp
)

# ---- Dependencies ----

# raylib
CPMAddPackage(NAME raylib
  GIT_REPOSITORY https://github.com/Nathan-MV/raylib.git
  GIT_TAG ba8460d74cd5086fbdc47a49ce5bb91b1377d1d5
)

# set(PLATFORM_CPP "PLATFORM_DESKTOP_RGFW")
#set(GRAPHICS "GRAPHICS_API_OPENGL_43")
#set(OPENGL_VERSION "4.3")

# raygui
CPMAddPackage(NAME raygui
  GIT_REPOSITORY https://github.com/Nathan-MV/raygui.git
  GIT_TAG e496ee4430aed72ab8edb477568507b230da69bd
)

target_compile_definitions(raygui PRIVATE RAYGUI_IMPLEMENTATION)

# reasings
CPMAddPackage(NAME reasings
  GIT_REPOSITORY https://github.com/Nathan-MV/reasings.git
  GIT_TAG 919079c7a9fb883399f4d4a801ad4132f1f442f5
)

# rapidcsv
CPMAddPackage(NAME rapidcsv
  GIT_REPOSITORY https://github.com/d99kris/rapidcsv.git
  GIT_TAG a98b85e663114b8fdc9c0dc03abf22c296f38241
)

# ---- Add Libraries ----

add_library(${PROJECT_NAME}_static STATIC ${SRC_FILES})

# ---- Setup common library properties ----

function(setup_library target)
  target_include_directories(${target}
    PUBLIC
      $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/include
      ${raylib_SOURCE_DIR}/src
      ${raygui_SOURCE_DIR}/src
      ${reasings_SOURCE_DIR}/src
  )

  set_target_properties(${target} PROPERTIES
    INTERPROCEDURAL_OPTIMIZATION TRUE
  )

  # Define libraries required on linking
  if (WIN32)
    # Libraries for Windows desktop compilation
    # NOTE: WinMM library required to set high-res timer resolution
    set(LINK_LIBS opengl32 gdi32 winmm comdlg32 ole32)
    # Required for physac examples
    list(APPEND LINK_LIBS pthread)
  elseif (LINUX)
    # Libraries for Debian GNU/Linux desktop compiling
    # NOTE: Required packages: libegl1-mesa-dev
    set(LINK_LIBS GL m pthread dl rt)
    if (WAYLAND)
      # On Wayland windowing system, additional libraries requires
      list(APPEND LINK_LIBS wayland-client wayland-cursor wayland-egl xkbcommon)
    else()
      # On X11 requires also below libraries
      list(APPEND LINK_LIBS X11)
      # NOTE: It seems additional libraries are not required any more, latest GLFW just dlopen them
      # list(APPEND LINK_LIBS Xrandr Xinerama Xi Xxf86vm Xcursor)
    endif()
    if (${RAYLIB_LIBTYPE} STREQUAL SHARED)
      list(APPEND LINK_LIBS c)
    endif()
  elseif (APPLE)
    # Libraries for OSX 10.9 desktop compiling
    # NOTE: Required packages: libopenal-dev libegl1-mesa-dev
    set(LINK_LIBS "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreAudio" "-framework CoreVideo")
  elseif (BSD)
    # Libraries for FreeBSD, OpenBSD, NetBSD, DragonFly desktop compiling
    # NOTE: Required packages: mesa-libs
    set(LINK_LIBS GL pthread m)
    # On XWindow requires also below libraries
    list(APPEND LINK_LIBS X11 Xrandr Xinerama Xi Xxf86vm Xcursor)
  endif()

  target_link_libraries(${target} rapidcsv raylib raygui reasings ${LINK_LIBS})
endfunction()

# ---- Setup static (for executables) and shared (for CRuby extension) libraries ----

setup_library(${PROJECT_NAME}_static)
