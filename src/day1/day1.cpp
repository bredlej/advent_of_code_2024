//
// Created by Patryk Szczypień on 01/12/2024.
//
#include <day1/day1.hpp>
#include <day1/input.hpp>
#include <cstdio>

int main() {
    std::printf("Accumulated distance is: %u\n", accumulated_distance( sorted_number_columns_from_pairs(input)) );
    std::printf("Similarity score: %u\n", accumulated_similarity_score( sorted_number_columns_from_pairs(input)) );
    return 0;
}
