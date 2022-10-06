cmake_minimum_required(VERSION 3.14)
set(PROJECT_NAME lab1_cstring-zinchukkryvenyaroshevychkharabara)
project(${PROJECT_NAME} C CXX)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} src/mystring.cpp include/mystring.h examples/example.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

# target_compile_options(${PROJECT_NAME} PRIVATE -Werror=vla)

enable_testing()

add_executable(${PROJECT_NAME}_test tests/mystring_test.cpp src/mystring.cpp include/mystring.h)
target_link_libraries(${PROJECT_NAME}_test gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)
