/**
 * @brief 原始根判定
 * @docs docs/math/primitive_root.md
 */

#ifndef EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_
#define EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_

#include <algorithm>
#include <map>
#include <utility>
#include <vector>

#include "emthrm/math/euler_phi/euler_phi.hpp"
#include "emthrm/math/mod_pow.hpp"
#include "emthrm/math/prime_factorization.hpp"

namespace emthrm {

bool is_primitive_root(long long root, const int m) {
  if ((root %= m) < 0) root += m;
  if (std::__gcd(static_cast<int>(root), m) > 1) return false;
  static std::map<int, int> phi;
  if (!phi.count(m)) phi[m] = euler_phi(m);
  const int phi_m = phi[m];
  static std::map<int, std::vector<int>> primes;
  if (!primes.count(phi_m)) {
    std::vector<int> tmp;
    for (const std::pair<int, int>& pr : prime_factorization(phi_m)) {
      tmp.emplace_back(pr.first);
    }
    primes[phi_m] = tmp;
  }
  for (const int p : primes[phi_m]) {
    if (mod_pow(root, phi_m / p, m) == 1) return false;
  }
  return true;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_
