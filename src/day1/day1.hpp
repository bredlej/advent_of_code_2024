//
// Created by Patryk Szczypień on 01/12/2024.
//

#ifndef DAY1_HPP
#define DAY1_HPP
#include <algorithm>
#include <numeric>
#include <__algorithm/ranges_sort.h>

#include <cstdint>
#include <utility>
#include <vector>

using PairOfUnsignedInt = std::pair<uint32_t, uint32_t>;
using TwoUnsignedIntColumns = std::pair<std::vector<uint32_t>, std::vector<uint32_t> >;

/**
 * @brief Computes the absolute difference between two unsigned integers.
 *
 * @param uint_pair A pair of unsigned integers.
 * @return The absolute difference between the two integers.
 */
constexpr uint32_t abs_difference_between_uints(const PairOfUnsignedInt &uint_pair) {
    return std::abs(static_cast<int32_t>(uint_pair.first) - static_cast<int32_t>(uint_pair.second));
}

/**
 * @brief Sorts two columns of unsigned integers.
 *
 * @param locs A vector of pairs of unsigned integers.
 * @return A pair of vectors containing the sorted columns.
 */
constexpr TwoUnsignedIntColumns sorted_uint_columns(
    const std::vector<std::pair<uint32_t, uint32_t> > &locs) {
    std::vector<uint32_t> first;
    std::vector<uint32_t> second;
    for (const auto &[fst, snd]: locs) {
        first.push_back(fst);
        second.push_back(snd);
    }
    std::ranges::sort(first);
    std::ranges::sort(second);

    return {first, second};
}

/**
 * @brief Computes the accumulated distance between two columns of unsigned integers.
 *
 * @param two_uint_columns A pair of vectors containing the columns of unsigned integers.
 * @return The accumulated distance.
 */
constexpr uint32_t accumulated_distance(const TwoUnsignedIntColumns &two_uint_columns) {
    return std::accumulate(two_uint_columns.first.begin(), two_uint_columns.first.end(), 0u,
                           [&two_uint_columns, col_idx = 0u](const uint32_t sum, uint32_t val) mutable {
                               return sum + abs_difference_between_uints({val, two_uint_columns.second[col_idx++]});
                           });
}

/**
 * @brief Computes the accumulated similarity score between two columns of unsigned integers.
 *
 * @param two_uint_columns A pair of vectors containing the columns of unsigned integers.
 * @return The accumulated similarity score.
 */
constexpr uint32_t accumulated_similarity_score(const TwoUnsignedIntColumns &two_uint_columns) {
    return std::accumulate(two_uint_columns.first.begin(), two_uint_columns.first.end(), 0u,
                           [&two_uint_columns](const uint32_t sum, const uint32_t val) {
                               return sum + val * std::ranges::count(two_uint_columns.second, val);
                           });
}
#endif //DAY1_HPP