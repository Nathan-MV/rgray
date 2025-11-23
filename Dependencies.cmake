include(cmake/CPM.cmake)

# Done as a function so that updates to variables like
# CMAKE_CXX_FLAGS don't propagate out to other
# targets
function(myproject_setup_dependencies)

  # For each dependency, see if it's
  # already been provided to us by a parent project

    # raylib
    CPMAddPackage(NAME raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG f1719480e0f61418bf5f5e2a2c2f8bc20b1c3074
    )

    # raygui
    CPMAddPackage(NAME raygui
        GIT_REPOSITORY https://github.com/Nathan-MV/raygui.git
        GIT_TAG a8974423a2274ed84dea5a2c692587e0f9697e9e
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
