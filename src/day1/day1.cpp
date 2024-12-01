//
// Created by Patryk Szczypień on 01/12/2024.
//
#include <day1/day1.hpp>
#include <day1/input.hpp>
#include <cstdio>

int main() {
    const auto sorted_columns = sorted_vectors_from_number_pairs(input);

    std::printf("Accumulated distance is: %u\n", accumulated_distance( sorted_columns ));
    std::printf("Similarity score: %u\n", accumulated_similarity_score( sorted_columns ));

    return 0;
}
