# CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
project(HelloWorld DESCRIPTION "A hello world project" VERSION 0.0.1)

# ———————————————————————————
# find 3rd party dependencies
# ———————————————————————————

find_package(fmt CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

# —————————————————————————
# create target for library
# —————————————————————————
add_library(hellolib src/hello.cpp)
target_compile_features(hellolib PUBLIC cxx_std_17)
target_link_libraries(hellolib PRIVATE fmt::fmt)

target_include_directories(hellolib
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# —————————————————————————————
# create target for main binary
# —————————————————————————————
add_executable(main src/main.cpp)
target_compile_features(main PUBLIC cxx_std_17)
target_link_libraries(main PRIVATE hellolib fmt::fmt)

# —————————————————————————————————————————
# create target for test, enable testing, and register a test "RunAllTests"
# —————————————————————————————————————————
add_executable(run_tests tests/tests.cpp)
target_compile_features(run_tests PUBLIC cxx_std_17)
target_link_libraries(run_tests PRIVATE hellolib Catch2::Catch2)

enable_testing()
add_test(RunAllTests run_tests)