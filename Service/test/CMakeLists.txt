cmake_minimum_required(VERSION 2.6)
project(AndroidKviz_TEST)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(AndroidKviz-test
    main.cpp
)

target_link_libraries(AndroidKviz-test gtest gtest_main)

add_test (
    NAME AndroidKviz-test
    COMMAND AndroidKviz-test
)