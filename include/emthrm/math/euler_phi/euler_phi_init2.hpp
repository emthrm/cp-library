/**
 * @brief オイラーの $\varphi$ 関数の数表2
 * @docs docs/math/euler_phi/euler_phi.md
 */

#pragma once
#include <numeric>
#include <vector>

#include "../prime_sieve.hpp"

std::vector<long long> euler_phi_init2(const long long low,
                                       const long long high) {
  std::vector<long long> phi(high - low), rem(high - low);
  std::iota(phi.begin(), phi.end(), low);
  std::iota(rem.begin(), rem.end(), low);
  long long root = 1;
  while ((root + 1) * (root + 1) < high) ++root;
  for (const int p : prime_sieve(root, true)) {
    for (long long i = (low + p - 1) / p * p; i < high; i += p) {
      phi[i - low] -= phi[i - low] / p;
      while (rem[i - low] % p == 0) rem[i - low] /= p;
    }
  }
  for (int i = 0; i < high - low; ++i) {
    if (rem[i] > 1) phi[i] -= phi[i] / rem[i];
  }
  return phi;
}
