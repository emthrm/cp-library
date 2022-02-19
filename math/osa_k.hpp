#pragma once
#include <utility>
#include <vector>

#include "./prime_sieve.hpp"

struct OsaK {
  const std::vector<int> smallest_prime_factor;

  explicit OsaK(const int n) : smallest_prime_factor(prime_sieve(n, false)) {}

  std::vector<std::pair<int, int>> query(int n) const {
    std::vector<std::pair<int, int>> res;
    while (n > 1) {
      const int prime = smallest_prime_factor[n];
      int exponent = 0;
      for (; smallest_prime_factor[n] == prime; n /= prime) {
        ++exponent;
      }
      res.emplace_back(prime, exponent);
    }
    return res;
  }
};
