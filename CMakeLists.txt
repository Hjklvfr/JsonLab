cmake_minimum_required(VERSION 2.8.12)
project(JsonLab)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(${CMAKE_BINARY_DIR} "main.cpp")

add_subdirectory(lib)
# add_subdirectory(testLib)

include_directories("lib")
include_directories("lib/src")
link_directories("lib")
# include_directories("testLib")
# link_directories("testLib")

add_executable(JsonLab main.cpp)
add_executable(Tests test/ParserTest.cpp)

target_link_libraries(JsonLab JsonLabLib)
target_link_libraries(Tests JsonLabLib)
# target_link_libraries(Tests gtest)
# target_link_libraries(Tests gtest_main)