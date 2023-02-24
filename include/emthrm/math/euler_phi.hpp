/**
 * @title オイラーの $\varphi$ 関数
 * @docs docs/math/euler_phi.md
 */

#ifndef EMTHRM_MATH_EULER_PHI_HPP_
#define EMTHRM_MATH_EULER_PHI_HPP_

#include <cassert>

namespace emthrm {

long long euler_phi(long long n) {
  assert(n >= 1);
  long long res = n;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) [[unlikely]] {
      res -= res / i;
      while (n % i == 0) n /= i;
    }
  }
  return n > 1 ? res - res / n : res;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_EULER_PHI_HPP_
