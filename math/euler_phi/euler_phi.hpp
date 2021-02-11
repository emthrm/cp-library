/**
 * @brief オイラーの $\varphi$ 関数
 * @docs docs/math/euler_phi/euler_phi.md
 */

#pragma once
#include <cassert>

long long euler_phi(long long n) {
  assert(n >= 1);
  long long res = n;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      res -= res / i;
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) res -= res / n;
  return res;
}
