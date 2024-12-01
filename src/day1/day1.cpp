//
// Created by Patryk Szczypień on 01/12/2024.
//
#include <day1/day1.hpp>
#include <day1/input.hpp>
#include <cstdio>

int main() {
    std::printf("Accumulated distance is: %u\n", accumulated_abs_difference(sorted_uint_columns(input)));
    std::printf("Similarity score: %u\n", total_similarity_score(sorted_uint_columns(input)));
    return 0;
}