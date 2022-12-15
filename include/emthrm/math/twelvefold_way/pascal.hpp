/**
 * @brief パスカルの三角形
 * @docs docs/math/twelvefold_way/binomial_coefficients.md
 */

#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_PASCAL_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_PASCAL_HPP_

#include <vector>

namespace emthrm {

template <typename T>
std::vector<std::vector<T>> pascal(const int n) {
  std::vector<std::vector<T>> c(n + 1, std::vector<T>(n + 1, 0));
  for (int i = 0; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
  return c;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_PASCAL_HPP_
