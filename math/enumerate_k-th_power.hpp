#pragma once
#include <vector>
#include "prime_sieve.hpp"
#include "mod_pow.hpp"

std::vector<int> enumerate_kth_power(int n, int k, int m) {
  std::vector<int> res(n + 1, 0);
  std::vector<int> smallest_prime_factor = prime_sieve(n, false);
  for (int i = 1; i <= n; ++i) {
    if (smallest_prime_factor[i] == i) {
      res[i] = mod_pow(i, k, m);
    } else {
      res[i] = static_cast<long long>(res[smallest_prime_factor[i]]) * res[i / smallest_prime_factor[i]] % m;
    }
  }
  return res;
}
