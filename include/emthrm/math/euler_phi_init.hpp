/**
 * @brief オイラーの $\varphi$ 関数の数表
 * @docs docs/math/euler_phi.md
 */

#ifndef EMTHRM_MATH_EULER_PHI_INIT_HPP_
#define EMTHRM_MATH_EULER_PHI_INIT_HPP_

#include <numeric>
#include <vector>

namespace emthrm {

std::vector<int> euler_phi_init(const int n) {
  std::vector<int> phi(n + 1);
  std::iota(phi.begin(), phi.end(), 0);
  for (int i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
  return phi;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_EULER_PHI_INIT_HPP_