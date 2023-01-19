#ifndef EMTHRM_MATH_LEAST_COMMON_MULTIPLE_HPP_
#define EMTHRM_MATH_LEAST_COMMON_MULTIPLE_HPP_

#if __cplusplus < 201703L

#include <algorithm>

namespace emthrm {

long long __lcm(const long long a, const long long b) {
  return a / std::__gcd(a, b) * b;
}

}  // namespace emthrm

#endif

#endif  // EMTHRM_MATH_LEAST_COMMON_MULTIPLE_HPP_
