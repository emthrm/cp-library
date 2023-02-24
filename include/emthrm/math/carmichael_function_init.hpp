/**
 * @title カーマイケル関数の数表
 * @docs docs/math/carmichael_function.md
 */

#ifndef EMTHRM_MATH_CARMICHAEL_FUNCTION_INIT_HPP_
#define EMTHRM_MATH_CARMICHAEL_FUNCTION_INIT_HPP_

#include <numeric>
#include <vector>

#include "emthrm/math/prime_sieve.hpp"

namespace emthrm {

std::vector<long long> carmichael_function_init(const long long low,
                                                const long long high) {
  std::vector<long long> lambda(high - low, 1), tmp(high - low);
  std::iota(tmp.begin(), tmp.end(), low);
  if (low == 0 && high > 0) lambda[0] = 0;
  for (long long i = (low + 7) / 8 * 8; i < high; i += 8) {
    tmp[i - low] >>= 1;
  }
  long long root = 1;
  while ((root + 1) * (root + 1) < high) ++root;
  for (const int p : prime_sieve<true>(root)) {
    for (long long i = (low + p - 1) / p * p; i < high; i += p) {
      if (i == 0) continue;
      tmp[i - low] /= p;
      long long phi = p - 1;
      for (; tmp[i - low] % p == 0; tmp[i - low] /= p) {
        phi *= p;
      }
      lambda[i - low] = std::lcm(lambda[i - low], phi);
    }
  }
  for (int i = 0; i < high - low; ++i) {
    if (tmp[i] > 1) lambda[i] = std::lcm(lambda[i], tmp[i] - 1);
  }
  return lambda;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CARMICHAEL_FUNCTION_INIT_HPP_
