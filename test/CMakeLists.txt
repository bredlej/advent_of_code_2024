set(INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/src
)
add_executable(test_day1 ./day1.cpp)
target_link_libraries(test_day1 gtest)
target_include_directories(test_day1 PRIVATE ${INCLUDE_DIRS})

add_test(Test-AOC test_day1)