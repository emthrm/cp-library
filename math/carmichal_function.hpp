/**
 * @brief カーマイケル関数
 * @docs docs/math/carmichal_function.md
 */

#pragma once
#include "lcm.hpp"

long long carmichal_function(long long val) {
  long long res = 1;
  if (val % 8 == 0) val >>= 1;
  for (long long i = 2; i * i <= val; ++i) {
    if (val % i == 0) {
      val /= i;
      long long phi = i - 1;
      while (val % i == 0) {
        val /= i;
        phi *= i;
      }
      res = __lcm(res, phi);
    }
  }
  if (val > 1) res = __lcm(res, val - 1);
  return res;
}
