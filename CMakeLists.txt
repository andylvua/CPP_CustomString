cmake_minimum_required(VERSION 3.14)
set(PROJECT_NAME lab1_cstring-zinchukkryvenyaroshevychkharabara)
project(${PROJECT_NAME} C CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} src/mystring.cpp include/mystring.h examples/example.cpp)

add_subdirectory(tests)
add_subdirectory(benchmark)

enable_testing()
