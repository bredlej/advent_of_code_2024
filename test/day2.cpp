//
// Created by Patryk Szczypień on 02/12/2024.
//
//
// Created by Patryk Szczypień on 01/12/2024.
//
#include <gtest/gtest.h>
#include <day2/day2.hpp>

class Day2Test : public testing::Test {
protected:
    Day2Test() = default;
};

TEST_F(Day2Test, NumbersNotSafeIfDeviationIsTooHigh_IncreasingNumbers) {
    std::vector<uint32_t> numbers = {1, 3, 5};
    ASSERT_FALSE(are_numbers_safe<uint32_t>(1, numbers));
}

TEST_F(Day2Test, NumbersNotSafeIfDeviationIsTooHigh_DecreasingNumbers) {
    std::vector<uint32_t> numbers = {5, 3, 1};
    ASSERT_FALSE(are_numbers_safe<uint32_t>(1, numbers));
}

TEST_F(Day2Test, NumbersNotSafeIfDecreasingAfterIncreasing) {
    std::vector<uint32_t> numbers = {1, 3, 2};
    ASSERT_FALSE(are_numbers_safe<uint32_t>(2, numbers));
}

TEST_F(Day2Test, NumbersNotSafeIfIncreasingAfterDecreasing) {
    std::vector<uint32_t> numbers = {5, 3, 4};
    ASSERT_FALSE(are_numbers_safe<uint32_t>(2, numbers));
}

TEST_F(Day2Test, NumbersSafeIfWithinDeviation_Increasing) {
    std::vector<uint32_t> numbers = {1, 3, 5};
    ASSERT_TRUE(are_numbers_safe<uint32_t>(2, numbers));
}

TEST_F(Day2Test, NumbersSafeIfWithinDeviation_Decreasing) {
    std::vector<uint32_t> numbers = {5, 3, 1};
    ASSERT_TRUE(are_numbers_safe<uint32_t>(2, numbers));
}

TEST_F(Day2Test, CountsSafetyOfDataInFile_NoProblemDampener) {

    ASSERT_EQ(2, count_safety_of(3, "input_day2").first);
}

TEST_F(Day2Test, CountsSafetyOfDataInFile_WithProblemDampener) {

    ASSERT_EQ(4, count_safety_of(3, "input_day2", true).first);
}

TEST_F(Day2Test, CreatesVariationsOfVector) {
    auto variations = create_variations_of_numbers(std::vector<uint32_t>{8, 11, 13, 14, 15, 18, 17});
    ASSERT_EQ(std::vector<uint32_t>({11, 13, 14, 15, 18, 17}), variations[0]);
    ASSERT_EQ(std::vector<uint32_t>({8, 13, 14, 15, 18, 17}), variations[1]);
    ASSERT_EQ(std::vector<uint32_t>({8, 11, 14, 15, 18, 17}), variations[2]);
    ASSERT_EQ(std::vector<uint32_t>({8, 11, 13, 15, 18, 17}), variations[3]);
    ASSERT_EQ(std::vector<uint32_t>({8, 11, 13, 14, 18, 17}), variations[4]);
    ASSERT_EQ(std::vector<uint32_t>({8, 11, 13, 14, 15, 17}), variations[5]);
    ASSERT_EQ(std::vector<uint32_t>({8, 11, 13, 14, 15, 18}), variations[6]);
    ASSERT_EQ(7, variations.size());
}

int main(int ac, char *av[]) {
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}
