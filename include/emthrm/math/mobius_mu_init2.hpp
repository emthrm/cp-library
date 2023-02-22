/**
 * @brief メビウス関数の数表2
 * @docs docs/math/mobius_mu.md
 */

#ifndef EMTHRM_MATH_MOBIUS_MU_INIT2_HPP_
#define EMTHRM_MATH_MOBIUS_MU_INIT2_HPP_

#include <numeric>
#include <vector>

#include "emthrm/math/prime_sieve.hpp"

namespace emthrm {

std::vector<int> mobius_mu_init2(const long long low, const long long high) {
  std::vector<int> mu(high - low, 1);
  std::vector<long long> tmp(high - low);
  std::iota(tmp.begin(), tmp.end(), low);
  if (low == 0 && high > 0) mu[0] = 0;
  long long root = 1;
  while ((root + 1) * (root + 1) < high) ++root;
  for (const int p : prime_sieve(root, true)) {
    for (long long i = (low + p - 1) / p * p; i < high; i += p) {
      if ((i / p) % p == 0) {
        mu[i - low] = tmp[i - low] = 0;
      } else {
        mu[i - low] = -mu[i - low];
        tmp[i - low] /= p;
      }
    }
  }
  for (int i = 0; i < high - low; ++i) {
    if (tmp[i] > 1) mu[i] = -mu[i];
  }
  return mu;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_MOBIUS_MU_INIT2_HPP_
