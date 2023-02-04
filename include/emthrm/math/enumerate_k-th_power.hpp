#ifndef EMTHRM_MATH_ENUMERATE_K_TH_POWER_HPP_
#define EMTHRM_MATH_ENUMERATE_K_TH_POWER_HPP_

#include <vector>

#include "emthrm/math/mod_pow.hpp"
#include "emthrm/math/prime_sieve.hpp"

namespace emthrm {

std::vector<int> enumerate_kth_power(const int n, const int k, const int m) {
  const std::vector<int> smallest_prime_factor = prime_sieve<false>(n);
  std::vector<int> res(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    if (smallest_prime_factor[i] == i) [[unlikely]] {
      res[i] = mod_pow(i, k, m);
    } else {
      res[i] = static_cast<long long>(res[smallest_prime_factor[i]])
               * res[i / smallest_prime_factor[i]] % m;
    }
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_ENUMERATE_K_TH_POWER_HPP_
