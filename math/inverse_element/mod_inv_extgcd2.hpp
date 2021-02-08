/**
 * @brief 逆元 拡張 Euclid の互除法版2
 * @docs docs/math/inverse_element/inverse_element.md
 */

#pragma once
#include <algorithm>
#include "../ext_gcd.hpp"

long long mod_inv_extgcd2(long long a, int mod) {
  a %= mod;
  if (std::__gcd(a, static_cast<long long>(mod)) != 1) return -1;
  return (ext_gcd(a, static_cast<long long>(mod)).first + mod) % mod;
}
