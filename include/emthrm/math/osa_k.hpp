#ifndef EMTHRM_MATH_OSA_K_HPP_
#define EMTHRM_MATH_OSA_K_HPP_

#include <utility>
#include <vector>

#include "emthrm/math/prime_sieve.hpp"

namespace emthrm {

struct OsaK {
  const std::vector<int> smallest_prime_factor;

  explicit OsaK(const int n) : smallest_prime_factor(prime_sieve<false>(n)) {}

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

}  // namespace emthrm

#endif  // EMTHRM_MATH_OSA_K_HPP_
