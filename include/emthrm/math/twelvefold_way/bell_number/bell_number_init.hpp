/**
 * @brief ベル数の数表
 * @docs docs/math/twelvefold_way/bell_number/bell_number.md
 */

#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_

#include <vector>

#include "emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp"

namespace emthrm {

template <typename T>
std::vector<std::vector<T>> bell_number_init(const int n, const int k) {
  std::vector<std::vector<T>> b(n + 1, std::vector<T>(k + 1));
  const std::vector<std::vector<T>> s =
      stirling_number_of_the_second_kind_init<T>(n, k);
  for (int i = 0; i <= n; ++i) {
    b[i].front() = s[i].front();
    for (int j = 1; j <= k; ++j) {
      b[i][j] = b[i][j - 1] + s[i][j];
    }
  }
  return b;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_
