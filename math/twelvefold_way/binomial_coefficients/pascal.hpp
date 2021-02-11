/**
 * @brief パスカルの三角形
 * @docs docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md
 */

#pragma once
#include <vector>

template <typename T>
std::vector<std::vector<T>> pascal(int n) {
  std::vector<std::vector<T>> c(n + 1, std::vector<T>(n + 1, 0));
  for (int i = 0; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  return c;
}
