/**
 * @brief オイラーの $\varphi$ 関数の数表
 * @docs docs/math/euler_phi/euler_phi.md
 */

#pragma once
#include <vector>

std::vector<int> euler_phi_init(int n) {
  std::vector<int> phi(n + 1);
  for (int i = 0; i <= n; ++i) phi[i] = i;
  for (int i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
    }
  }
  return phi;
}
