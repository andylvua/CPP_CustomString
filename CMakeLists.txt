cmake_minimum_required(VERSION 3.24)
set(PROJECT_NAME lab1_cstring-zinchukkryvenyaroshevychkharabara)
project(${PROJECT_NAME} C CXX)

set(CMAKE_CXX_STANDARD 14)


add_executable(${PROJECT_NAME} src/main.cpp src/mystring.cpp include/mystring.h)
