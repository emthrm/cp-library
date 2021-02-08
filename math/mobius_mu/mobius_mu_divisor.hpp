/**
 * @brief メビウス関数 約数版
 * @docs docs/math/mobius_mu/mobius_mu.md
 */

#pragma once
#include <map>
#include <vector>

template <typename T>
std::map<T, int> mobius_mu_divisor(T val) {
  std::vector<T> primes;
  for (T i = 2; i * i <= val; ++i) {
    if (val % i == 0) {
      primes.emplace_back(i);
      while (val % i == 0) val /= i;
    }
  }
  if (val != 1) primes.emplace_back(val);
  int n = primes.size();
  std::map<T, int> mu;
  for (int i = 0; i < (1 << n); ++i) {
    int cnt = 0;
    T di = 1;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        ++cnt;
        di *= primes[j];
      }
    }
    mu[di] = (cnt & 1 ? -1 : 1);
  }
  return mu;
}
