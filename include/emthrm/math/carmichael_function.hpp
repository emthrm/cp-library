/**
 * @brief カーマイケル関数
 * @docs docs/math/carmichael_function.md
 */

#ifndef EMTHRM_MATH_CARMICHAEL_FUNCTION_HPP_
#define EMTHRM_MATH_CARMICHAEL_FUNCTION_HPP_

#include "emthrm/math/least_common_multiple.hpp"

namespace emthrm {

long long carmichael_function(long long n) {
  long long lambda = 1;
  if (n % 8 == 0) n >>= 1;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      n /= i;
      long long phi = i - 1;
      for (; n % i == 0; n /= i) {
        phi *= i;
      }
      lambda = __lcm(lambda, phi);
    }
  }
  return n > 1 ? __lcm(lambda, n - 1) : lambda;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CARMICHAEL_FUNCTION_HPP_