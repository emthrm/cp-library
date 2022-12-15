#ifndef EMTHRM_MATH_IS_PRIME_HPP_
#define EMTHRM_MATH_IS_PRIME_HPP_

namespace emthrm {

bool is_prime(const long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_IS_PRIME_HPP_
