cmake_minimum_required(VERSION 3.20)

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 23)
endif()

set(CMAKE_CXX_EXTENSIONS ON)

project(rgray
        VERSION 0.0.1
        DESCRIPTION "Ruby Gaming with Raylib"
        #HOMEPAGE_URL "%%https://github.com/Nathan-MV/rgray%%"
        LANGUAGES CXX C)

include(Dependencies.cmake)
myproject_setup_dependencies()

# don't know if this should be set globally from here or not...
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

set(GIT_SHA
    "Unknown"
    CACHE STRING "SHA this build was generated from")
string(
  SUBSTRING "${GIT_SHA}"
            0
            8
            GIT_SHORT_SHA)

# ---- Set Rpath ----

set(CMAKE_SKIP_BUILD_RPATH  FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "\${ORIGIN}")

# ---- Set output directories ----

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

# ---- Add subdirectories ----

add_subdirectory(src)
add_subdirectory(bindings/mri)

# ---- Setup common executable properties ----

function(setup_executable target)
  set_target_properties(${target} PROPERTIES
    CXX_STANDARD 23
    OUTPUT_NAME "${target}"
    INTERPROCEDURAL_OPTIMIZATION TRUE
  )
  target_link_libraries(${target}
    ${PROJECT_NAME}_mri_static
  )
  target_include_directories(${target} PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")
endfunction()

# ---- Create rgray executables ----

set(ICON_FILE "${CMAKE_CURRENT_SOURCE_DIR}/resources/rgray.ico")

if(WIN32)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/rgray.rc.in
                 ${CMAKE_CURRENT_BINARY_DIR}/rgray.rc @ONLY)

  # WIN32: for GUI mode (attachable console)
  add_executable(${PROJECT_NAME}_release WIN32
      $<TARGET_OBJECTS:${PROJECT_NAME}_static>
      ${CMAKE_CURRENT_BINARY_DIR}/rgray.rc
  )
  setup_executable(${PROJECT_NAME}_release)
elseif(UNIX)
  configure_file(
      ${CMAKE_CURRENT_SOURCE_DIR}/resources/rgray.desktop.in
      ${CMAKE_CURRENT_BINARY_DIR}/rgray.desktop @ONLY
  )

  add_executable(${PROJECT_NAME}_release $<TARGET_OBJECTS:${PROJECT_NAME}_static>)
  setup_executable(${PROJECT_NAME}_release)
else()
  add_executable(${PROJECT_NAME}_release $<TARGET_OBJECTS:${PROJECT_NAME}_static>)
  setup_executable(${PROJECT_NAME}_release)
endif()

# If MSVC is being used, and ASAN is enabled, we need to set the debugger environment
# so that it behaves well with MSVC's debugger, and we can run the target from visual studio
if(MSVC)
  get_all_installable_targets(all_targets)
  message("all_targets=${all_targets}")
  set_target_properties(${all_targets} PROPERTIES VS_DEBUGGER_ENVIRONMENT "PATH=$(VC_ExecutablePath_x64);%PATH%")
endif()

# set the startup project for the "play" button in MSVC
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}_console)
