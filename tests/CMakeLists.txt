include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_include_directories(${PROJECT_NAME} PUBLIC include)

enable_testing()

add_executable(${PROJECT_NAME}_test ./mystring_test.cpp ../src/mystring.cpp ../include/mystring.h)
target_link_libraries(${PROJECT_NAME}_test gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)
