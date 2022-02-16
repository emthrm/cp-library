/**
 * @brief メビウス関数 約数版
 * @docs docs/math/mobius_mu/mobius_mu.md
 */

#pragma once
#include <map>
#include <vector>

template <typename T>
std::map<T, int> mobius_mu_focusing_on_divisor(T n) {
  std::vector<T> primes;
  for (T i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      primes.emplace_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) primes.emplace_back(n);
  const int p = primes.size();
  std::map<T, int> mu;
  for (int i = 0; i < (1 << p); ++i) {
    T d = 1;
    for (int j = 0; j < p; ++j) {
      if (i >> j & 1) d *= primes[j];
    }
    mu[d] = (__builtin_popcount(i) & 1 ? -1 : 1);
  }
  return mu;
}
