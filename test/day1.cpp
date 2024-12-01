//
// Created by Patryk Szczypień on 01/12/2024.
//
#include <gtest/gtest.h>
#include <day1/day1.hpp>

class Day1Test : public testing::Test {
protected:
    Day1Test() = default;
};

TEST_F(Day1Test, Calculates_Distance_Between_Locations) {

    ASSERT_EQ(1, abs_difference_between_numbers<uint32_t>({1, 2}));
}

TEST_F(Day1Test, Sorts_Locations) {
    const std::initializer_list<std::pair<uint32_t, uint32_t>> number_pairs = {
        {2, 1},
        {3, 4},
        {1, 2}
    };

    const auto [first, second] = sorted_vectors_from_number_pairs( number_pairs );

    ASSERT_EQ(1, first[0]);
    ASSERT_EQ(2, first[1]);
    ASSERT_EQ(3, first[2]);

    ASSERT_EQ(1, second[0]);
    ASSERT_EQ(2, second[1]);
    ASSERT_EQ(4, second[2]);
}

TEST_F(Day1Test, Accumulates_Distance) {
    const std::initializer_list<std::pair<uint32_t, uint32_t>> number_pairs = {
        {3, 4},
        {4, 3},
        {2, 5},
        {1, 3},
        {3, 9},
        {3, 3}
    };

    ASSERT_EQ(11, accumulated_distance( sorted_vectors_from_number_pairs( number_pairs )) );
}

TEST_F(Day1Test, Accumulates_Distance_With_Floats) {
    const std::initializer_list<std::pair<float, float>> number_pairs = {
        {0.5f, 1.0f},
        {0.4f, 0.5f},
    };

    ASSERT_EQ(0.6f, accumulated_distance( sorted_vectors_from_number_pairs( number_pairs )) );
}

TEST_F(Day1Test, Accumulates_Similarity) {
    const std::initializer_list<std::pair<uint32_t, uint32_t>> number_pairs = {
        {3, 4},
        {4, 3},
        {2, 5},
        {1, 3},
        {3, 9},
        {3, 3}
    };

    ASSERT_EQ(31, accumulated_similarity_score( sorted_vectors_from_number_pairs( number_pairs ) ));
}

TEST_F(Day1Test, Accumulates_Similarity_With_Floats) {
    const std::initializer_list<std::pair<float, float>> number_pairs = {
        {1.4f, 1.4f},
        {2.0f, 3.0},
        {3.0f, 1.4f},
        {4.0f, 2.0f}
    };

    ASSERT_EQ(7.8f, accumulated_similarity_score( sorted_vectors_from_number_pairs( number_pairs ) ));
}

int main(int ac, char *av[]) {
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}
