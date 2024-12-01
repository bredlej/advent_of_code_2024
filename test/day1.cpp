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

    ASSERT_EQ(1, abs_difference_between_uints({1, 2}));
}

TEST_F(Day1Test, Sorts_Locations) {
    const std::vector<std::pair<uint32_t, uint32_t>> locs = {
        {2, 1},
        {3, 4},
        {1, 2}
    };

    const auto [first, second] = sorted_uint_columns(locs);

    ASSERT_EQ(1, first[0]);
    ASSERT_EQ(2, first[1]);
    ASSERT_EQ(3, first[2]);

    ASSERT_EQ(1, second[0]);
    ASSERT_EQ(2, second[1]);
    ASSERT_EQ(4, second[2]);
}

TEST_F(Day1Test, Accumulates_Distance) {
    const std::vector<std::pair<uint32_t, uint32_t>> locs = {
        {3, 4},
        {4, 3},
        {2, 5},
        {1, 3},
        {3, 9},
        {3, 3},
    };

    ASSERT_EQ(11, accumulated_abs_difference(sorted_uint_columns(locs)));
}

TEST_F(Day1Test, Accumulates_Similarity) {
    const std::vector<std::pair<uint32_t, uint32_t>> locs = {
        {3, 4},
        {4, 3},
        {2, 5},
        {1, 3},
        {3, 9},
        {3, 3},
    };

    ASSERT_EQ(31, total_similarity_score(sorted_uint_columns(locs)));
}

int main(int ac, char *av[]) {
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}
