/**
 * @title 第1種スターリング数の数表
 * @docs docs/math/twelvefold_way/stirling_number/stirling_number.md
 */

#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_FIRST_KIND_INIT_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_FIRST_KIND_INIT_HPP_

#include <vector>

namespace emthrm {

template <typename T>
std::vector<std::vector<T>> stirling_number_of_the_first_kind_init(
    const int n, const int k) {
  std::vector<std::vector<T>> s(n + 1, std::vector<T>(k + 1, 0));
  s[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i && j <= k; ++j) {
      s[i][j] = s[i - 1][j - 1] + s[i - 1][j] * (i - 1);
    }
  }
  return s;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_FIRST_KIND_INIT_HPP_
