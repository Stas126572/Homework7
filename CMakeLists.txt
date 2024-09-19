
if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    # "googletest"
)

add_executable(
    containers
    Main.cpp
    src/NodesList.hpp
    src/Vector.hpp
)

add_executable(
    conteiners_tests
    tests/NodesList_tests.cpp
    tests/Vector_tests.cpp
)

target_include_directories(
    conteiners_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(conteiners_tests PRIVATE
    gtest
    gtest_main
)

set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(conteiners_tests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(
        containers PRIVATE
        /W4
    )
    target_compile_options(
        conteiners_tests PRIVATE
        /W4
    )
else ()
    target_compile_options(
        containers PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        conteiners_tests PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()