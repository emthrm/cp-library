/**
 * @brief 分割数
 * @docs docs/math/twelvefold_way/partition_function.md
 */

#pragma once
#include <vector>

template <typename T>
std::vector<std::vector<T>> partition_function_init(int group, int sum) {
  std::vector<std::vector<T>> pf(group + 1, std::vector<T>(sum + 1, 0));
  pf[0][0] = 1;
  for (int i = 1; i <= group; ++i) for (int j = 0; j <= sum; ++j) {
    pf[i][j] = j - i >= 0 ? pf[i][j - i] + pf[i - 1][j] : pf[i - 1][j];
  }
  return pf;
}
