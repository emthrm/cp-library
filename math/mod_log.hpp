#pragma once
#include <cmath>
#include <map>
#include "mod_pow.hpp"

int mod_log(long long g, long long y, int mod) {
  if ((g %= mod) < 0) g += mod;
  if ((y %= mod) < 0) y += mod;
  if (mod == 1) return 0;
  if (g == 0) {
    if (y == 1) {
      return 0;
    } else if (y == 0) {
      return 1;
    } else {
      return -1;
    }
  }
  int root = std::ceil(std::sqrt(mod));
  std::map<long long, int> baby;
  long long p = 1;
  for (int i = 0; i < root; ++i) {
    if (p == y) return i;
    baby[p * y % mod] = i;
    (p *= g) %= mod;
  }
  long long brute_force = p;
  for (int i = root; i < 100; ++i) {
    if (i == mod) return -1;
    if (brute_force == y) return i;
    (brute_force *= g) %= mod;
  }
  long long giant = p;
  for (int i = 1; i <= root; ++i) {
    if (baby.count(giant) == 1) {
      int ans = static_cast<int>(static_cast<long long>(i) * root - baby[giant]);
      if (mod_pow(g, ans, mod) == y) return ans;
    }
    (giant *= p) %= mod;
  }
  return -1;
}
