/**
 * @brief 原始根判定
 * @docs docs/math/primitive_root.md
 */

#ifndef EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_
#define EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_

#include <numeric>
#include <map>
#include <ranges>
#include <vector>

#include "emthrm/math/euler_phi/euler_phi.hpp"
#include "emthrm/math/mod_pow.hpp"
#include "emthrm/math/prime_factorization.hpp"

namespace emthrm {

bool is_primitive_root(long long root, const int m) {
  if ((root %= m) < 0) root += m;
  if (std::gcd(root, m) > 1) return false;
  static std::map<int, int> phi;
  if (!phi.contains(m)) phi[m] = euler_phi(m);
  const int phi_m = phi[m];
  static std::map<int, std::vector<int>> primes;
  if (!primes.contains(phi_m)) {
    const auto ev = prime_factorization(phi_m) | std::views::keys;
    primes[phi_m] = std::vector<int>(ev.begin(), ev.end());
  }
  for (const int p : primes[phi_m]) {
    if (mod_pow(root, phi_m / p, m) == 1) return false;
  }
  return true;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_
