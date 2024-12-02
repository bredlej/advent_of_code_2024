//
// Created by Patryk Szczypień on 02/12/2024.
//
#include <day2/day2.hpp>

int main () {
    const auto safety_count = count_safety_of(3, "input_day2");
    std::cout << "Safe: " << safety_count.first << ", Not safe: " << safety_count.second << std::endl;
    const auto safety_count_dampened = count_safety_of(3, "input_day2", true);
    std::cout << "Safe with dampener: " << safety_count_dampened.first << ", Not safe with dampener: " << safety_count_dampened.second << std::endl;

    return 0;
}