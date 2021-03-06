#pragma once
#include <algorithm>
#include <utility>

long long mod_inv(long long a, int m) {
  if ((a %= m) < 0) a += m;
  if (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;
  long long b = m, x = 1, u = 0;
  while (b > 0) {
    long long q = a / b;
    std::swap(a -= q * b, b);
    std::swap(x -= q * u, u);
  }
  x %= m;
  return x < 0 ? x + m : x;
}
