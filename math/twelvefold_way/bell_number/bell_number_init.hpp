/**
 * @brief ベル数の数表
 * @docs docs/math/twelvefold_way/bell_number/bell_number.md
 */

#pragma once
#include <vector>
#include "../stirling_number/stirling_number_of_the_second_kind_init.hpp"

template <typename T>
std::vector<std::vector<T>> bell_number_init(int n, int k) {
  std::vector<std::vector<T>> bell(n + 1, std::vector<T>(k + 1)), stirling = stirling_number_of_the_second_kind_init<T>(n, k);
  for (int i = 0; i <= n; ++i) {
    bell[i][0] = stirling[i][0];
    for (int j = 1; j <= k; ++j) bell[i][j] = bell[i][j - 1] + stirling[i][j];
  }
  return bell;
}
