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

constexpr uint32_t abs_difference_between_uints(const PairOfUnsignedInt &locs_pair) {
    return std::abs(static_cast<int32_t>(locs_pair.first) - static_cast<int32_t>(locs_pair.second));
}

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

constexpr uint32_t accumulated_abs_difference(const TwoUnsignedIntColumns &two_uint_columns) {
    return std::accumulate(two_uint_columns.first.begin(), two_uint_columns.first.end(), 0u,
                           [&two_uint_columns, col_idx = 0u](const uint32_t sum, uint32_t val) mutable {
                               return sum + abs_difference_between_uints({val, two_uint_columns.second[col_idx++]});
                           });
}

constexpr uint32_t similarity_score(const uint32_t value, const std::vector<uint32_t> &column) {
    return std::ranges::count(column, value);
}
constexpr uint32_t total_similarity_score(const TwoUnsignedIntColumns &two_uint_columns) {
    return std::accumulate(two_uint_columns.first.begin(), two_uint_columns.first.end(), 0u,
                           [&two_uint_columns](const uint32_t sum, const uint32_t val) {
                               return sum + val * std::ranges::count(two_uint_columns.second, val);
                           });
}
#endif //DAY1_HPP
