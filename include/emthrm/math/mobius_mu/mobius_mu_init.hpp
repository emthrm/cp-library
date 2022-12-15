/**
 * @brief メビウス関数の数表
 * @docs docs/math/mobius_mu/mobius_mu.md
 */

#ifndef EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_INIT_HPP_
#define EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_INIT_HPP_

#include <vector>

namespace emthrm {

std::vector<int> mobius_mu_init(const int n) {
  std::vector<bool> is_prime(n + 1, true);
  is_prime[0] = false;
  if (n >= 1) is_prime[1] = false;
  std::vector<int> mu(n + 1, 1);
  mu[0] = 0;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      mu[i] = -mu[i];
      for (int j = i * 2; j <= n; j += i) {
        is_prime[j] = false;
        mu[j] = ((j / i) % i == 0 ? 0 : -mu[j]);
      }
    }
  }
  return mu;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_INIT_HPP_
