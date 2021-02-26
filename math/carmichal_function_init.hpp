/**
 * @brief カーマイケル関数の数表
 * @docs docs/math/carmichal_function.md
 */

#pragma once
#include <cmath>
#include <numeric>
#include <vector>
#include "prime_sieve.hpp"
#include "lcm.hpp"

std::vector<long long> carmichal_function_init(long long low, long long high) {
  std::vector<long long> res(high - low, 1), tmp(high - low);
  std::iota(tmp.begin(), tmp.end(), low);
  if (low == 0 && high > 0) res[0] = 0;
  for (long long i = (low + 7) / 8 * 8; i < high; i += 8) tmp[i - low] >>= 1;
  for (int p : prime_sieve(std::ceil(std::sqrt(high)), true)) {
    for (long long i = (low + (p - 1)) / p * p; i < high; i += p) {
      if (i == 0) continue;
      tmp[i - low] /= p;
      long long phi = p - 1;
      while (tmp[i - low] % p == 0) {
        tmp[i - low] /= p;
        phi *= p;
      }
      res[i - low] = __lcm(res[i - low], phi);
    }
  }
  for (int i = 0; i < high - low; ++i) {
    if (tmp[i] > 1) res[i] = __lcm(res[i], tmp[i] - 1);
  }
  return res;
}
