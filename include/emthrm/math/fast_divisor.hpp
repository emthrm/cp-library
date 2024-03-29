/**
 * @title 約数列挙
 */

#ifndef EMTHRM_MATH_FAST_DIVISOR_HPP_
#define EMTHRM_MATH_FAST_DIVISOR_HPP_

// #include <algorithm>
#include <vector>

#include "emthrm/math/prime_sieve.hpp"

namespace emthrm {

struct Divisor {
  const std::vector<int> smallest_prime_factor;

  explicit Divisor(const int n)
      : smallest_prime_factor(prime_sieve<false>(n)) {}

  std::vector<int> query(int n) const {
    std::vector<int> res{1};
    while (n > 1) {
      const int prime_factor = smallest_prime_factor[n], d = res.size();
      int tmp = 1;
      for (; n % prime_factor == 0; n /= prime_factor) {
        tmp *= prime_factor;
        for (int i = 0; i < d; ++i) {
          res.emplace_back(res[i] * tmp);
        }
      }
    }
    // std::sort(res.begin(), res.end());
    return res;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_MATH_FAST_DIVISOR_HPP_
