#pragma once
#include <utility>
#include <vector>

struct osa_k {
  osa_k(int n = 10000000) : least_prime_factor(n + 1, -1) {
    least_prime_factor[0] = 0;
    if (n >= 1) least_prime_factor[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (least_prime_factor[i] == -1) {
        least_prime_factor[i] = i;
        for (long long j = static_cast<long long>(i) * i; j <= n; j += i) {
          if (least_prime_factor[j] == -1) least_prime_factor[j] = i;
        }
      }
    }
  }

  std::vector<std::pair<int, int>> query(int n) const {
    std::vector<std::pair<int, int>> res;
    while (n > 1) {
      int prime = least_prime_factor[n], exponent = 0;
      while (least_prime_factor[n] == prime) {
        ++exponent;
        n /= prime;
      }
      res.emplace_back(prime, exponent);
    }
    return res;
  }

private:
  std::vector<int> least_prime_factor;
};
