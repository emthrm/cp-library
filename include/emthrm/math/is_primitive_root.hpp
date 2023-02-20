/**
 * @brief 原始根判定
 * @docs docs/math/primitive_root.md
 */

#ifndef EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_
#define EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_

#include <algorithm>
#if __cplusplus >= 201703L
# include <numeric>
#else
# include <utility>
#endif  // __cplusplus >= 201703L
#include <map>
#include <vector>

#include "emthrm/math/euler_phi/euler_phi.hpp"
#include "emthrm/math/mod_pow.hpp"
#include "emthrm/math/prime_factorization.hpp"

namespace emthrm {

bool is_primitive_root(long long root, const int m) {
  if ((root %= m) < 0) root += m;
#if __cplusplus >= 201703L
  if (std::gcd(root, m) > 1) return false;
#else
  if (std::__gcd(static_cast<int>(root), m) > 1) return false;
#endif  // __cplusplus >= 201703L
  static std::map<int, int> phi;
  if (!phi.count(m)) phi[m] = euler_phi(m);
  const int phi_m = phi[m];
  static std::map<int, std::vector<int>> primes;
  if (!primes.count(phi_m)) {
    std::vector<int> tmp;
#if __cplusplus >= 201703L
    for (const auto& [prime, _] : prime_factorization(phi_m)) {
      tmp.emplace_back(prime);
    }
#else
    for (const std::pair<int, int>& pr : prime_factorization(phi_m)) {
      tmp.emplace_back(pr.first);
    }
#endif  // __cplusplus >= 201703L
    primes[phi_m] = tmp;
  }
  return std::none_of(primes[phi_m].begin(), primes[phi_m].end(),
                      [root, phi_m, m](const int p) -> bool {
                        return mod_pow(root, phi_m / p, m) == 1;
                      });
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_
