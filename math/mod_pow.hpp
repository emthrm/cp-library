#pragma once

long long mod_pow(long long base, long long exponent, int mod) {
  base %= mod;
  long long res = 1;
  while (exponent > 0) {
    if (exponent & 1) (res *= base) %= mod;
    (base *= base) %= mod;
    exponent >>= 1;
  }
  return res;
}
