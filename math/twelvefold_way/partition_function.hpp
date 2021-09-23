/**
 * @brief 分割数
 * @docs docs/math/twelvefold_way/partition_function.md
 */

#pragma once
#include <algorithm>
#include <vector>

template <typename T>
std::vector<std::vector<T>> partition_function(const int n, const int m) {
  std::vector<std::vector<T>> p(n + 1, std::vector<T>(m + 1, 0));
  p[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    std::copy(p[i - 1].begin(), p[i - 1].end(), p[i].begin());
    for (int j = i; j <= m; ++j) {
      p[i][j] += p[i][j - i];
    }
  }
  return p;
}
