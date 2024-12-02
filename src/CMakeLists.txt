set(INCLUDE_DIRS
        .
)
add_executable(day1 ./day1/day1.cpp)
target_include_directories(day1 PRIVATE ${INCLUDE_DIRS})

add_executable(day2 ./day2/day2.cpp)
target_include_directories(day2 PRIVATE ${INCLUDE_DIRS})
add_custom_command(
        TARGET day2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/day2/input_day2
        ${CMAKE_CURRENT_BINARY_DIR}/input_day2
)