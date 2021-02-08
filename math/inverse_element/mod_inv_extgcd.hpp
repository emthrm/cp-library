/**
 * @brief 逆元 拡張 Euclid の互除法版
 * @docs docs/math/inverse_element/inverse_element.md
 */

#pragma once
#include <algorithm>
#include <utility>

long long mod_inv_extgcd(long long a, int mod) {
  a %= mod;
  if (std::__gcd(a, static_cast<long long>(mod)) != 1) return -1;
  long long b = mod, x = 1, y = 0;
  while (b > 0) {
    long long tmp = a / b;
    std::swap(a -= tmp * b, b);
    std::swap(x -= tmp * y, y);
  }
  x %= mod;
  return x < 0 ? x + mod : x;
}
