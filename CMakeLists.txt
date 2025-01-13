cmake_minimum_required(VERSION 3.20)

project(rgray
        VERSION 0.0.1
        DESCRIPTION "Ruby Gaming with Raylib"
        LANGUAGES CXX)

# ---- Set Rpath ----

set(CMAKE_SKIP_BUILD_RPATH  FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "\${ORIGIN}")

# ---- Set output directories ----

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

# ---- Import tools ----

include(cmake/tools.cmake)
include(cmake/CPM.cmake)

CPMAddPackage(NAME ${PROJECT_NAME} SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

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
  target_link_libraries(${target} ${PROJECT_NAME}_mri_static)
endfunction()

# ---- Create rgray executables ----

if(WIN32)
  # WIN32 keyword to disable the console on Windows
  add_executable(${PROJECT_NAME}_release WIN32 $<TARGET_OBJECTS:${PROJECT_NAME}_static>)
  setup_executable(${PROJECT_NAME}_release)
  add_executable(${PROJECT_NAME}_console $<TARGET_OBJECTS:${PROJECT_NAME}_static>)
  setup_executable(${PROJECT_NAME}_console)
else()
  add_executable(${PROJECT_NAME} $<TARGET_OBJECTS:${PROJECT_NAME}_static>)
  setup_executable(${PROJECT_NAME})
endif()
