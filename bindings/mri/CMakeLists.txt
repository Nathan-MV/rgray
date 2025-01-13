# ----- Add Files -----

set(SRC_FILES
  src/audio/audio_stream_bindings.cpp
  src/audio/audio_bindings.cpp
  src/audio/music_bindings.cpp
  src/audio/sound_bindings.cpp
  src/graphics/bitmap_bindings.cpp
  src/graphics/color_bindings.cpp
  src/graphics/draw_bindings.cpp
  src/graphics/font_bindings.cpp
  src/graphics/gui_bindings.cpp
  src/graphics/material_bindings.cpp
  src/graphics/mesh_bindings.cpp
  src/graphics/model_bindings.cpp
  src/graphics/render_texture_bindings.cpp
  src/graphics/shader_bindings.cpp
  src/graphics/shapes_bindings.cpp
  src/graphics/sprite_bindings.cpp
  src/input/gamepad_bindings.cpp
  src/input/gestures_bindings.cpp
  src/input/keyboard_bindings.cpp
  src/input/mouse_bindings.cpp
  src/input/touch_bindings.cpp
  src/input/vr_bindings.cpp
  src/math/circle_bindings.cpp
  src/math/ease_bindings.cpp
  src/math/ellipse_bindings.cpp
  src/math/line_bindings.cpp
  src/math/pixel_bindings.cpp
  src/math/polygon_bindings.cpp
  src/math/rect_bindings.cpp
  src/math/ring_bindings.cpp
  src/math/spline_bindings.cpp
  src/math/table_bindings.cpp
  src/math/triangle_bindings.cpp
  src/math/vec2_bindings.cpp
  src/math/vec3_bindings.cpp
  src/math/vec4_bindings.cpp
  src/physics/camera_bindings.cpp
  src/system/automation_event_bindings.cpp
  src/system/files_bindings.cpp
  src/system/graphics_bindings.cpp
  src/system/kernel_bindings.cpp
  src/system/log_bindings.cpp
  src/main.cpp
)

# ---- Dependencies ----
find_package(Ruby 3.0 REQUIRED)

# ---- Add Libraries ----

# Static library (with -fPIC)
add_library(${PROJECT_NAME}_mri_static STATIC ${SRC_FILES})
target_compile_options(${PROJECT_NAME}_mri_static PRIVATE -fPIC)

# Shared library
add_library(${PROJECT_NAME}_mri SHARED ${SRC_FILES})

# ---- Setup common library properties ----

function(setup_library target)
  target_include_directories(${target}
    PUBLIC
      $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
    PRIVATE
      ${PROJECT_SOURCE_DIR}/include
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/include
      ${raylib_SOURCE_DIR}/src
      ${raygui_SOURCE_DIR}/src
      ${reasings_SOURCE_DIR}/src
      ${RUBY_INCLUDE_PATH}
  )
endfunction()

# ---- Setup static (for executables) and shared (for CRuby extension) libraries ----
setup_library(${PROJECT_NAME}_mri_static)
setup_library(${PROJECT_NAME}_mri)

# Link dependencies properly
target_link_libraries(${PROJECT_NAME}_mri PRIVATE ${PROJECT_NAME}_mri_static ${RUBY_LIBRARY})

# Set the output extension to `.so` on Windows
if(WIN32)
  set_target_properties(${PROJECT_NAME}_mri PROPERTIES SUFFIX ".so")
endif()

# Copy Ruby library to output directory
if(Ruby_FOUND)
  add_custom_command(TARGET ${PROJECT_NAME}_mri POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${RUBY_LIBRARY}
      ${CMAKE_BINARY_DIR}/out
  )
endif()
