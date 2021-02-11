/**
 * @brief カーマイケル関数
 * @docs docs/math/carmichal_function.md
 */

#pragma once
#include "lcm.hpp"

long long carmichal_function(long long n) {
  long long res = 1;
  if (n % 8 == 0) n >>= 1;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      n /= i;
      long long phi = i - 1;
      while (n % i == 0) {
        n /= i;
        phi *= i;
      }
      res = __lcm(res, phi);
    }
  }
  if (n > 1) res = __lcm(res, n - 1);
  return res;
}
