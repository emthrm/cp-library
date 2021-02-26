/**
 * @brief メビウス関数の数表2
 * @docs docs/math/mobius_mu/mobius_mu.md
 */

#pragma once
#include <cmath>
#include <numeric>
#include <vector>
#include "../prime_sieve.hpp"

std::vector<int> mobius_mu_init2(long long low, long long high) {
  std::vector<int> mu(high - low, 1);
  std::vector<long long> tmp(high - low);
  std::iota(tmp.begin(), tmp.end(), low);
  if (low == 0 && high > 0) mu[0] = 0;
  for (int p : prime_sieve(std::ceil(std::sqrt(high)), true)) {
    for (long long i = (low + (p - 1)) / p * p; i < high; i += p) {
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
