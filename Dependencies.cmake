include(cmake/CPM.cmake)

# Done as a function so that updates to variables like
# CMAKE_CXX_FLAGS don't propagate out to other
# targets
function(myproject_setup_dependencies)

  # For each dependency, see if it's
  # already been provided to us by a parent project

    # raylib
    CPMAddPackage(NAME raylib
        GIT_REPOSITORY https://github.com/Nathan-MV/raylib.git
        GIT_TAG 9e2591e612bcf651ed8dca0d4ba242b64c694f25
    )

    if(DEFINED raylib_SOURCE_DIR)
        message(STATUS "Patching raylib symbols...")

        file(GLOB_RECURSE RAYLIB_SRC
            "${raylib_SOURCE_DIR}/src/*.c"
            "${raylib_SOURCE_DIR}/src/*.h"
        )

        foreach(F IN LISTS RAYLIB_SRC)
            file(READ "${F}" CONTENT)

            set(NEW "${CONTENT}")

            # ShowCursor -> RayShowCursor
            string(REGEX REPLACE "([^A-Za-z0-9_])ShowCursor[ \t]*\\("
                                "\\1RayShowCursor("
                                NEW "${NEW}")
            string(REGEX REPLACE "^ShowCursor[ \t]*\\("
                                "RayShowCursor("
                                NEW "${NEW}")

            # Rectangle -> RayRectangle
            string(REGEX REPLACE "([^A-Za-z0-9_])Rectangle([^A-Za-z0-9_])"
                                "\\1RayRectangle\\2"
                                NEW "${NEW}")

            # CloseWindow -> RayCloseWindow
            string(REGEX REPLACE "([^A-Za-z0-9_])CloseWindow([^A-Za-z0-9_])"
                                "\\1RayCloseWindow\\2"
                                NEW "${NEW}")

            # DrawText -> RayDrawText
            string(REGEX REPLACE "([^A-Za-z0-9_])DrawText([^A-Za-z0-9_])"
                                "\\1RayDrawText\\2"
                                NEW "${NEW}")

            # DrawTextEx -> RayDrawTextEx
            string(REGEX REPLACE "([^A-Za-z0-9_])DrawTextEx([^A-Za-z0-9_])"
                                "\\1RayDrawTextEx\\2"
                                NEW "${NEW}")

            # PlaySound -> RayPlaySound
            string(REGEX REPLACE "([^A-Za-z0-9_])PlaySound([^A-Za-z0-9_])"
                                "\\1RayPlaySound\\2"
                                NEW "${NEW}")

            # LoadImage -> RayLoadImage
            string(REGEX REPLACE "([^A-Za-z0-9_])LoadImage([^A-Za-z0-9_])"
                                "\\1RayLoadImage\\2"
                                NEW "${NEW}")

            if(NOT NEW STREQUAL CONTENT)
                # Backup simples opcional
                if(NOT EXISTS "${F}.orig")
                    file(COPY "${F}" DESTINATION "${F}.orig")
                endif()

                file(WRITE "${F}" "${NEW}")
                message(STATUS "Patched: ${F}")
            endif()
        endforeach()

        message(STATUS "Raylib patch done.")
    endif()

    # raygui
    CPMAddPackage(NAME raygui
        GIT_REPOSITORY https://github.com/Nathan-MV/raygui.git
        GIT_TAG c2f53e0fee5fdadc9e21c128af5d51cf22862462
    )

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

endfunction()
