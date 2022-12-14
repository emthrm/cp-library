/**
 * @brief 第2種スターリング数の数表
 * @docs docs/math/twelvefold_way/stirling_number/stirling_number.md
 */

#pragma once
#include <vector>

#include "emthrm/math/modint.hpp"

template <typename T>
std::vector<std::vector<T>> stirling_number_of_the_second_kind_init(
    const int n, const int k) {
  std::vector<std::vector<T>> s(n + 1, std::vector<T>(k + 1, 0));
  s[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i && j <= k; ++j) {
      s[i][j] = s[i - 1][j - 1] + s[i - 1][j] * j;
    }
  }
  return s;
}
