/**
 * @brief Eulerian number の数表
 * @docs docs/math/fps/eulerian_number.md
 */

#pragma once
#include <vector>

template <typename T>
std::vector<std::vector<T>> eulerian_number_init(int n, int m) {
  std::vector<std::vector<T>> a(n + 1, std::vector<T>(m + 1, 0));
  a[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    a[i][0] = 1;
    for (int j = 1; j < i; ++j) a[i][j] = a[i - 1][j - 1] * (i - j) + a[i - 1][j] * (j + 1);
  }
  return a;
}
