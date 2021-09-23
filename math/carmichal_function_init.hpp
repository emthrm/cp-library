/**
 * @brief カーマイケル関数の数表
 * @docs docs/math/carmichal_function.md
 */

#pragma once
#include <cmath>
#include <numeric>
#include <vector>
#include "prime_sieve.hpp"
#include "least_common_multiple.hpp"

std::vector<long long> carmichal_function_init(const long long low, const long long high) {
  std::vector<long long> lambda(high - low, 1), tmp(high - low);
  std::iota(tmp.begin(), tmp.end(), low);
  if (low == 0 && high > 0) {
    lambda[0] = 0;
  }
  for (long long i = (low + 7) / 8 * 8; i < high; i += 8) {
    tmp[i - low] >>= 1;
  }
  for (const int p : prime_sieve(std::ceil(std::sqrt(high)), true)) {
    for (long long i = (low + p - 1) / p * p; i < high; i += p) {
      if (i == 0) continue;
      tmp[i - low] /= p;
      long long phi = p - 1;
      while (tmp[i - low] % p == 0) {
        tmp[i - low] /= p;
        phi *= p;
      }
      lambda[i - low] = __lcm(lambda[i - low], phi);
    }
  }
  for (int i = 0; i < high - low; ++i) {
    if (tmp[i] > 1) {
      lambda[i] = __lcm(lambda[i], tmp[i] - 1);
    }
  }
  return lambda;
}
