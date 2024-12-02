set(INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/src
)
add_executable(test_day1 ./day1.cpp)
target_link_libraries(test_day1 gtest)
target_include_directories(test_day1 PRIVATE ${INCLUDE_DIRS})

add_executable(test_day2 ./day2.cpp)
target_link_libraries(test_day2 gtest)
target_include_directories(test_day2 PRIVATE ${INCLUDE_DIRS})
add_custom_command(
        TARGET test_day2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/test/input_day2
        ${CMAKE_CURRENT_BINARY_DIR}/input_day2
)


add_test(Test-AOC2024 test_day1)
add_test(Test-AOC2024 test_day2)