/**
 * @brief メビウス関数
 * @docs docs/math/mobius_mu/mobius_mu.md
 */

#pragma once

int mobius_mu(long long n) {
  int cnt = 0;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      n /= i;
      if (n % i == 0) return 0;
      ++cnt;
    }
  }
  if (n > 1) ++cnt;
  return cnt & 1 ? -1 : 1;
}
