# ----- Add Files -----

set(SRC_FILES
  math/vec2.cpp
  system/kernel.cpp
  graphics/color.cpp
)

# ---- Dependencies ----
set_target_properties(raylib PROPERTIES POSITION_INDEPENDENT_CODE ON)
#set(PLATFORM_CPP "PLATFORM_DESKTOP_RGFW")
#set(GRAPHICS "GRAPHICS_API_OPENGL_43")
#set(OPENGL_VERSION "4.3")
target_compile_definitions(raygui PRIVATE RAYGUI_IMPLEMENTATION)
set_target_properties(raygui PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(reasings PROPERTIES POSITION_INDEPENDENT_CODE ON)

# ---- Add Libraries ----

add_library(${PROJECT_NAME}_static STATIC ${SRC_FILES})
#add_library(${PROJECT_NAME}::${PROJECT_NAME}_static ALIAS ${PROJECT_NAME}_static)

# ---- Setup common library properties ----

function(setup_library target)
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

  target_link_libraries(${target} 
    myproject_options
    #myproject_warnings
    rapidcsv raylib raygui reasings
    ${LINK_LIBS}
  )

  target_include_directories(${target}
    ${WARNING_GUARD}
    PUBLIC
      $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
      $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
      $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/include
      ${raylib_SOURCE_DIR}/src
      ${raygui_SOURCE_DIR}/src
      ${reasings_SOURCE_DIR}/src
  )

  target_compile_features(${target} PUBLIC cxx_std_23)

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
endfunction()

# ---- Setup static (for executables) and shared (for CRuby extension) libraries ----

setup_library(${PROJECT_NAME}_static)
