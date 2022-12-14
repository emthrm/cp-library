#pragma once
#include <vector>

#include "./mod_pow.hpp"
#include "./prime_sieve.hpp"

std::vector<int> enumerate_kth_power(const int n, const int k, const int m) {
  const std::vector<int> smallest_prime_factor = prime_sieve(n, false);
  std::vector<int> res(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    if (smallest_prime_factor[i] == i) {
      res[i] = mod_pow(i, k, m);
    } else {
      res[i] = static_cast<long long>(res[smallest_prime_factor[i]])
               * res[i / smallest_prime_factor[i]] % m;
    }
  }
  return res;
}
