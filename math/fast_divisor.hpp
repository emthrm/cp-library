/**
 * @brief 約数列挙
 */

#pragma once
// #include <algorithm>
#include <vector>
#include "prime_sieve.hpp"

struct Divisor {
  std::vector<int> smallest_prime_factor;

  Divisor(int n) : smallest_prime_factor(prime_sieve(n, false)) {}

  std::vector<int> query(int n) {
    std::vector<int> res{1};
    while (n > 1) {
      int prime_factor = smallest_prime_factor[n], tmp = 1, d = res.size();
      for (; n % prime_factor == 0; n /= prime_factor) {
        tmp *= prime_factor;
        for (int i = 0; i < d; ++i) res.emplace_back(res[i] * tmp);
      }
    }
    // std::sort(res.begin(), res.end());
    return res;
  }
};
