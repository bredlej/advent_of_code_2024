#ifndef DAY2_HPP
#define DAY2_HPP

#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>

/**
 * @brief Creates variations of a vector where each variation has one element removed.
 *
 * @tparam T The type of elements in the vector.
 * @param original The original vector.
 * @return A vector of vectors, each missing one element from the original vector.
 */
template<typename T>
constexpr std::vector<std::vector<T>> create_variations_of_numbers(const std::vector<T>& original) {
    std::vector<std::vector<T>> variations;
    for (size_t i = 0; i < original.size(); ++i) {
        std::vector<T> variation;
        for (size_t j = 0; j < original.size(); ++j) {
            if (j != i) {
                variation.push_back(original[j]);
            }
        }
        variations.push_back(variation);
    }
    return variations;
}

/**
 * @brief Checks if the numbers in the vector have a problem based on the given maximum deviation.
 *
 * @tparam T The type of elements in the vector.
 * @param max_deviation The maximum allowed deviation between consecutive numbers.
 * @param numbers The vector of numbers to check.
 * @return true if the numbers have a problem, false otherwise.
 */
template<typename T>
constexpr bool is_problem_in_numbers(T max_deviation, const std::vector<T>& numbers) {
    bool increasing = numbers[0] < numbers[1];
    using SignedT = std::make_signed_t<T>;
    for (size_t i = 0; i < numbers.size() - 1; ++i) {
        T current = numbers[i];
        T next = numbers[i + 1];
        if (current == next || (i != 0 && increasing != (current < next))) {
            return true;
        }
        if (std::abs(static_cast<SignedT>(current) - static_cast<SignedT>(next)) > max_deviation) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks if the numbers in the vector are safe based on the given maximum deviation.
 *
 * @tparam T The type of elements in the vector.
 * @param max_deviation The maximum allowed deviation between consecutive numbers.
 * @param numbers The vector of numbers to check.
 * @param check_variations If true, checks variations of the vector to see if any are safe.
 * @return true if the numbers are safe, false otherwise.
 */
template<typename T>
constexpr bool are_numbers_safe(T max_deviation, const std::vector<T>& numbers, bool check_variations = false) {
    if (is_problem_in_numbers(max_deviation, numbers)) {
        if (check_variations) {
            for (const auto& variation : create_variations_of_numbers(numbers)) {
                if (!is_problem_in_numbers(max_deviation, variation)) {
                    return true;
                }
            }
        }
        return false;
    }
    return true;
}

/**
 * @brief Counts the number of safe and unsafe vectors in a file based on the given maximum deviation.
 *
 * @tparam T The type of elements in the vectors.
 * @param max_deviation The maximum allowed deviation between consecutive numbers.
 * @param filename The name of the file containing the vectors.
 * @param check_variations If true, checks variations of the vectors to see if any are safe.
 * @return A pair where the first element is the count of safe vectors and the second element is the count of unsafe vectors.
 */
template<typename T>
std::pair<uint32_t, uint32_t> count_safety_of(T max_deviation, const std::string& filename, bool check_variations = false) {
    std::ifstream input_file(filename);
    std::pair<uint32_t, uint32_t> result = {0, 0};
    if (input_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            std::istringstream iss(line);
            std::vector<T> numbers;
            T number;
            while (iss >> number) {
                numbers.push_back(number);
            }
            if (are_numbers_safe(max_deviation, numbers, check_variations)) {
                result.first++;
            } else {
                result.second++;
            }
        }
        input_file.close();
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
    return result;
}

#endif // DAY2_HPP