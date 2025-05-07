macro(myproject_enable_cppcheck WARNINGS_AS_ERRORS CPPCHECK_OPTIONS)
  find_program(CPPCHECK cppcheck)

  if(CPPCHECK)
    if(CMAKE_GENERATOR MATCHES ".*Visual Studio.*")
      set(CPPCHECK_TEMPLATE "vs")
    else()
      set(CPPCHECK_TEMPLATE "gcc")
    endif()

    set(SUPPRESS_PATTERN "*:${CMAKE_CURRENT_BINARY_DIR}/_deps/*")

    if("${CPPCHECK_OPTIONS}" STREQUAL "")
      message(STATUS "Using default cppcheck options. Suppressing: ${SUPPRESS_PATTERN}")

      set(CMAKE_CXX_CPPCHECK
        ${CPPCHECK}
        --template=${CPPCHECK_TEMPLATE}
        --enable=style,performance,warning,portability
        --inline-suppr
        --inconclusive
        --suppress=cppcheckError
        --suppress=internalAstError
        --suppress=unmatchedSuppression
        --suppress=passedByValue
        --suppress=syntaxError
        --suppress=preprocessorErrorDirective
        --suppress=knownConditionTrueFalse
        --suppress=unknownMacro
        --suppress=${SUPPRESS_PATTERN}
      )
    else()
      message(STATUS "Using user-defined cppcheck options: ${CPPCHECK_OPTIONS}")
      set(CMAKE_CXX_CPPCHECK
        ${CPPCHECK}
        --template=${CPPCHECK_TEMPLATE}
        ${CPPCHECK_OPTIONS}
      )
    endif()

    if(DEFINED CMAKE_CXX_STANDARD AND NOT "${CMAKE_CXX_STANDARD}" STREQUAL "")
      list(APPEND CMAKE_CXX_CPPCHECK --std=c++${CMAKE_CXX_STANDARD})
    endif()

    if(WARNINGS_AS_ERRORS)
      list(APPEND CMAKE_CXX_CPPCHECK --error-exitcode=2)
    endif()

  else()
    message(WARNING "cppcheck requested but executable not found")
  endif()
endmacro()

macro(myproject_enable_clang_tidy target WARNINGS_AS_ERRORS)

  find_program(CLANGTIDY clang-tidy)
  if(CLANGTIDY)
    if(NOT
       CMAKE_CXX_COMPILER_ID
       MATCHES
       ".*Clang")

      get_target_property(TARGET_PCH ${target} INTERFACE_PRECOMPILE_HEADERS)

      if("${TARGET_PCH}" STREQUAL "TARGET_PCH-NOTFOUND")
        get_target_property(TARGET_PCH ${target} PRECOMPILE_HEADERS)
      endif()

      if(NOT ("${TARGET_PCH}" STREQUAL "TARGET_PCH-NOTFOUND"))
        message(
          SEND_ERROR
            "clang-tidy cannot be enabled with non-clang compiler and PCH, clang-tidy fails to handle gcc's PCH file")
      endif()
    endif()

    # construct the clang-tidy command line
    set(CLANG_TIDY_OPTIONS
        ${CLANGTIDY}
        -extra-arg=-Wno-unknown-warning-option
        -extra-arg=-Wno-ignored-optimization-argument
        -extra-arg=-Wno-unused-command-line-argument
        -p)
    # set standard
    if(NOT
       "${CMAKE_CXX_STANDARD}"
       STREQUAL
       "")
      if("${CLANG_TIDY_OPTIONS_DRIVER_MODE}" STREQUAL "cl")
        set(CLANG_TIDY_OPTIONS ${CLANG_TIDY_OPTIONS} -extra-arg=/std:c++${CMAKE_CXX_STANDARD})
      else()
        set(CLANG_TIDY_OPTIONS ${CLANG_TIDY_OPTIONS} -extra-arg=-std=c++${CMAKE_CXX_STANDARD})
      endif()
    endif()

    # set warnings as errors
    if(${WARNINGS_AS_ERRORS})
      list(APPEND CLANG_TIDY_OPTIONS -warnings-as-errors=*)
    endif()

    message("Also setting clang-tidy globally")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_OPTIONS}")
  else()
    message(${WARNING_MESSAGE} "clang-tidy requested but executable not found")
  endif()
endmacro()

macro(myproject_enable_include_what_you_use)
  find_program(INCLUDE_WHAT_YOU_USE include-what-you-use)
  if(INCLUDE_WHAT_YOU_USE)
    set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE ${INCLUDE_WHAT_YOU_USE})
  else()
    message(${WARNING_MESSAGE} "include-what-you-use requested but executable not found")
  endif()
endmacro()