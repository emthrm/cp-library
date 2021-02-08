/**
 * @brief パスカルの三角形
 * @docs docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md
 */

#pragma once
#include <vector>

template <typename T>
std::vector<std::vector<T>> pascal(int val) {
  std::vector<std::vector<T>> c(val + 1, std::vector<T>(val + 1, 0));
  for (int i = 0; i <= val; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  return c;
}
