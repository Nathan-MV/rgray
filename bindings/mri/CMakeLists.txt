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
  src/math/triangle_bindings.cpp
  src/math/vec2_bindings.cpp
  src/math/vec3_bindings.cpp
  src/math/vec4_bindings.cpp
  src/math/math_bindings.cpp
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

# ---- Add Source Libraries ----

add_library(${PROJECT_NAME}_mri_static STATIC ${SRC_FILES})
add_library(${PROJECT_NAME} SHARED ${SRC_FILES})

# ---- Common Compile Options ----

set(COMMON_COMPILE_OPTIONS
  -Wno-deprecated-declarations
)

# ---- Setup Library Function ----

function(setup_library target)
  target_link_libraries(${target}
    myproject_options
    #myproject_warnings
    ${PROJECT_NAME}_static
    ${RUBY_LIBRARY}
  )

  target_include_directories(${target}
    ${WARNING_GUARD}
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

  target_compile_features(${target} PUBLIC cxx_std_23)

  target_compile_options(${target}
    PRIVATE ${COMMON_COMPILE_OPTIONS}
  )

  set_target_properties(
    ${target}
    PROPERTIES VERSION ${PROJECT_VERSION}
              CXX_VISIBILITY_PRESET hidden
              #VISIBILITY_INLINES_HIDDEN YES
  )

  #generate_export_header(${target} EXPORT_FILE_NAME ${PROJECT_BINARY_DIR}/include/myproject/sample_library_export.hpp)

  if(NOT BUILD_SHARED_LIBS)
    target_compile_definitions(${target} PUBLIC SAMPLE_LIBRARY_STATIC_DEFINE)
  endif()

  # Apply shared lib properties if this is the shared lib target
  if("${target}" STREQUAL "${PROJECT_NAME}")
    set_target_properties(${target}
      PROPERTIES PREFIX "" SUFFIX ".so"
    )
  endif()
endfunction()

# ---- Apply Setup to Targets ----

setup_library(${PROJECT_NAME}_mri_static)
setup_library(${PROJECT_NAME})

# Copy Ruby library to output directory
if(Ruby_FOUND)
  add_custom_command(TARGET ${PROJECT_NAME}_mri_static POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${RUBY_LIBRARY}
      ${CMAKE_BINARY_DIR}/out
  )
endif()

# ---- YARD Documentation Generator ----

set(DOC_OUTPUTS "")
foreach(src_file IN LISTS SRC_FILES)
  get_filename_component(src_name ${src_file} NAME_WE)
  string(REPLACE "_bindings" "" cleaned_name ${src_name})
  set(out_file "${CMAKE_SOURCE_DIR}/doc/${cleaned_name}.rb")
  list(APPEND DOC_OUTPUTS ${out_file})

  add_custom_command(
    OUTPUT ${out_file}
    COMMAND ${RUBY_EXECUTABLE} ${CMAKE_SOURCE_DIR}/tools/generate_yard_docs.rb "${CMAKE_CURRENT_SOURCE_DIR}/${src_file}"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS ${src_file} ${CMAKE_SOURCE_DIR}/tools/generate_yard_docs.rb
    COMMENT "Generating YARD doc for ${src_file}"
  )
endforeach()

add_custom_target(generate_docs ALL
  DEPENDS ${DOC_OUTPUTS}
)

