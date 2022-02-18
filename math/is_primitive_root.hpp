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
#include "mod_pow.hpp"
#include "prime_factorization.hpp"

bool is_primitive_root(long long root, const long long m) {
  if ((root %= m) < 0) root += m;
  if (std::__gcd(root, m) > 1) return false;
  static std::map<long long, long long> phi;
  if (!phi.count(m)) phi[m] = euler_phi(m);
  const long long phi_m = phi[m];
  static std::map<long long, std::vector<long long>> primes;
  if (!primes.count(phi_m)) {
    const std::vector<std::pair<long long, int>> prime_factors =
        prime_factorization(phi_m);
    std::vector<long long> tmp;
    for (const std::pair<long long, int>& pr : prime_factors) {
      tmp.emplace_back(pr.first);
    }
    primes[phi_m] = tmp;
  }
  for (const long long p : primes[phi_m]) {
    if (mod_pow(root, phi_m / p, m) == 1) return false;
  }
  return true;
}
