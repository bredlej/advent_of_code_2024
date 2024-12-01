set(INCLUDE_DIRS
        .
)
add_executable(day1 ./day1/day1.cpp)
target_include_directories(day1 PRIVATE ${INCLUDE_DIRS})