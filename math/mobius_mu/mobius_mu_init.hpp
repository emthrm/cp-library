/**
 * @brief メビウス関数の数表
 * @docs docs/math/mobius_mu/mobius_mu.md
 */

#pragma once
#include <vector>

std::vector<int> mobius_mu_init(int val) {
  std::vector<bool> is_prime(val + 1, true);
  is_prime[0] = false;
  if (val >= 1) is_prime[1] = false;
  std::vector<int> mu(val + 1, 1);
  mu[0] = 0;
  for (int i = 2; i <= val; ++i) {
    if (is_prime[i]) {
      mu[i] = -mu[i];
      for (int j = i * 2; j <= val; j += i) {
        is_prime[j] = false;
        mu[j] = (j / i) % i == 0 ? 0 : -mu[j];
      }
    }
  }
  return mu;
}
