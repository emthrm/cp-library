#ifndef EMTHRM_MATH_MOD_LOG_HPP_
#define EMTHRM_MATH_MOD_LOG_HPP_

#include <map>

#include "emthrm/math/mod_pow.hpp"

namespace emthrm {

int mod_log(long long g, long long y, const int m) {
  if (m == 1) return 0;
  if ((g %= m) < 0) g += m;
  if ((y %= m) < 0) y += m;
  if (g == 0) {
    if (y == 1) return 0;
    if (y == 0) return 1;
    return -1;
  }
  int root = 1;
  while (root * root < m) ++root;
  std::map<long long, int> baby;
  long long p = 1;
  for (int i = 0; i < root; ++i) {
    if (p == y) return i;
    baby[p * y % m] = i;
    p = (p * g) % m;
  }
  long long brute_force = p;
  for (int i = root; i < 100; ++i) {
    if (i == m) return -1;
    if (brute_force == y) return i;
    brute_force = (brute_force * g) % m;
  }
  long long giant = p;
  for (int i = 1; i <= root; ++i) {
    if (const auto it = baby.find(giant); it != baby.end()) {
      const int ans = static_cast<long long>(i) * root - it->second;
      if (mod_pow(g, ans, m) == y) return ans;
    }
    giant = (giant * p) % m;
  }
  return -1;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_MOD_LOG_HPP_
