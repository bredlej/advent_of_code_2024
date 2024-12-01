//
// Created by Patryk Szczypień on 01/12/2024.
//

#ifndef DAY1_HPP
#define DAY1_HPP
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <type_traits>

template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

/**
 * @brief Computes the absolute difference between two numbers.
 *
 * @param pair_of_numbers A pair of two numbers.
 * @return The absolute difference between the two numbers.
 */
template<Numeric T>
constexpr T abs_difference_between_numbers(const std::pair<T, T> &pair_of_numbers) {
    if constexpr (std::is_floating_point_v<T>) {
        return std::abs(pair_of_numbers.first - pair_of_numbers.second);
    }
    else {
        using SignedT = std::make_signed_t<T>;
        return std::abs(static_cast<SignedT>(pair_of_numbers.first) - static_cast<SignedT>(pair_of_numbers.second));
    }

}

/**
 * @brief Converts a vector of pairs of numbers into a pair of two vectors, where each vector has the numbers occuring in each pair in sorted order.
 *
 * @param pair_of_numbers A vector of pairs of numbers.
 * @return A pair containing two vectors with sorted numbers.
 */
template<Numeric T>
constexpr std::pair<std::vector<T>, std::vector<T> > sorted_vectors_from_number_pairs_t(const std::initializer_list<std::pair<T, T> > &pair_of_numbers) {
    std::vector<T> first;
    std::vector<T> second;
    for (const auto &[fst, snd]: pair_of_numbers) {
        first.push_back(fst);
        second.push_back(snd);
    }
    std::ranges::sort(first);
    std::ranges::sort(second);

    return {first, second};
}

/**
* @brief Helper function to deduce the template argument for sorted_number_columns_from_pairs_t
*/
template<Numeric T>
constexpr std::pair<std::vector<T>, std::vector<T> > sorted_vectors_from_number_pairs(const std::initializer_list<std::pair<T, T> > &pair_of_numbers) {
    return sorted_vectors_from_number_pairs_t<T>(pair_of_numbers);
}

/**
 * @brief Computes the accumulated distance between two columns of numbers.
 *
 * @param pair_of_number_vectors A pair of vectors containing the columns of numbers.
 * @return The accumulated distance.
 */
template <Numeric T>
constexpr T accumulated_distance_t(const std::pair<std::vector<T>, std::vector<T> > &pair_of_number_vectors) {
    return std::accumulate(pair_of_number_vectors.first.begin(), pair_of_number_vectors.first.end(), T{0},
                           [&pair_of_number_vectors, col_idx = 0u](const T sum, T val) mutable {
                               return sum + abs_difference_between_numbers<T>({val, pair_of_number_vectors.second[col_idx++]});
                           });
}

/**
 * @brief Helper function to deduce the template argument for accumulated_distance_t
 */
template<Numeric T>
constexpr T accumulated_distance(const std::pair<std::vector<T>, std::vector<T> > &pair_of_number_vectors) {
    return accumulated_distance_t<T>(pair_of_number_vectors);
}

/**
 * @brief Computes the accumulated similarity score between two columns of numbers.
 *
 * @param pair_of_number_vectors A pair of vectors containing the columns of numbers.
 * @return The accumulated similarity score.
 */
template <Numeric T>
constexpr T accumulated_similarity_score_t(const std::pair<std::vector<T>, std::vector<T> > &pair_of_number_vectors) {
    return std::accumulate(pair_of_number_vectors.first.begin(), pair_of_number_vectors.first.end(), T{0},
                           [&pair_of_number_vectors](const T sum, const T val) {
                               return sum + val * std::ranges::count(pair_of_number_vectors.second, val);
                           });
}

/**
 * @brief Helper function to deduce the template argument for accumulated_similarity_score_t
 */
template<Numeric T>
constexpr T accumulated_similarity_score(const std::pair<std::vector<T>, std::vector<T> > &pair_of_number_vectors) {
    return accumulated_similarity_score_t<T>(pair_of_number_vectors);
}
#endif //DAY1_HPP
