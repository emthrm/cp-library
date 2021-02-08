/**
 * @brief オイラーの $\varphi$ 関数
 * @docs docs/math/euler_phi/euler_phi.md
 */

#pragma once
#include <cassert>

long long euler_phi(long long val) {
  assert(val >= 1);
  long long res = val;
  for (long long i = 2; i * i <= val; ++i) {
    if (val % i == 0) {
      res -= res / i;
      while (val % i == 0) val /= i;
    }
  }
  if (val > 1) res -= res / val;
  return res;
}
