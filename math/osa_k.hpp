#pragma once
#include <utility>
#include <vector>

struct osa_k {
  osa_k(int val = 10000000) : least_prime_factor(val + 1, -1) {
    least_prime_factor[0] = 0;
    if (val >= 1) least_prime_factor[1] = 1;
    for (int i = 2; i <= val; ++i) {
      if (least_prime_factor[i] == -1) {
        least_prime_factor[i] = i;
        for (long long j = static_cast<long long>(i) * i; j <= val; j += i) {
          if (least_prime_factor[j] == -1) least_prime_factor[j] = i;
        }
      }
    }
  }

  std::vector<std::pair<int, int>> query(int val) const {
    std::vector<std::pair<int, int>> res;
    while (val > 1) {
      int prime = least_prime_factor[val], exponent = 0;
      while (least_prime_factor[val] == prime) {
        ++exponent;
        val /= prime;
      }
      res.emplace_back(prime, exponent);
    }
    return res;
  }

private:
  std::vector<int> least_prime_factor;
};
