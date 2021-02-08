/**
 * @brief オイラーの $\varphi$ 関数の数表
 * @docs docs/math/euler_phi/euler_phi.md
 */

#pragma once
#include <vector>

std::vector<int> euler_phi_init(int val) {
  std::vector<int> phi(val + 1);
  for (int i = 0; i <= val; ++i) phi[i] = i;
  for (int i = 2; i <= val; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= val; j += i) phi[j] -= phi[j] / i;
    }
  }
  return phi;
}
