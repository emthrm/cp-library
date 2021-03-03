/**
 * @brief 原始根判定
 * @docs docs/math/primitive_root.md
 */

#pragma once
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include "euler_phi/euler_phi.hpp"
#include "prime_factorization.hpp"
#include "mod_pow.hpp"

bool is_primitive_root(long long root, long long m) {
  if ((root %= m) < 0) root += m;
  if (std::__gcd(root, m) > 1) return false;
  static std::map<long long, long long> phi;
  if (phi.count(m) == 0) phi[m] = euler_phi(m);
  long long phi_m = phi[m];
  static std::map<long long, std::vector<std::pair<long long, int>>> pf;
  if (pf.count(phi_m) == 0) pf[phi_m] = prime_factorization(phi_m);
  for (const std::pair<long long, int> &pr : pf[phi_m]) {
    if (mod_pow(root, phi_m / pr.first, m) == 1) return false;
  }
  return true;
}
