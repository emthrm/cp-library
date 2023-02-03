#ifndef EMTHRM_MATH_PRIME_SIEVE_HPP_
#define EMTHRM_MATH_PRIME_SIEVE_HPP_

#include <numeric>
#include <vector>

namespace emthrm {

std::vector<int> prime_sieve(const int n, const bool get_only_prime) {
  std::vector<int> smallest_prime_factor(n + 1), prime;
  std::iota(smallest_prime_factor.begin(), smallest_prime_factor.end(), 0);
  for (int i = 2; i <= n; ++i) {
    if (smallest_prime_factor[i] == i) [[unlikely]] prime.emplace_back(i);
    for (const int p : prime) {
      if (i * p > n || p > smallest_prime_factor[i]) break;
      smallest_prime_factor[i * p] = p;
    }
  }
  return get_only_prime ? prime : smallest_prime_factor;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_PRIME_SIEVE_HPP_
