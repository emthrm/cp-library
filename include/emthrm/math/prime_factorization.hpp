#ifndef EMTHRM_MATH_PRIME_FACTORIZATION_HPP_
#define EMTHRM_MATH_PRIME_FACTORIZATION_HPP_

#include <utility>
#include <vector>

namespace emthrm {

template <typename T>
std::vector<std::pair<T, int>> prime_factorization(T n) {
  std::vector<std::pair<T, int>> res;
  for (T i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      int exponent = 0;
      for (; n % i == 0; n /= i) {
        ++exponent;
      }
      res.emplace_back(i, exponent);
    }
  }
  if (n > 1) res.emplace_back(n, 1);
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_PRIME_FACTORIZATION_HPP_
