#pragma once

long long mod_pow(long long x, long long n, const int m) {
  if ((x %= m) < 0) x += m;
  long long res = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) res = (res * x) % m;
    x = (x * x) % m;
  }
  return res;
}
