#ifndef EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_
#define EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_

#include <algorithm>
#include <map>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>

#include "emthrm/math/euler_phi.hpp"
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
    // GCC 12 adopted P2415.
    const std::vector<std::pair<int, int>> pf = prime_factorization(phi_m);
    const auto ev = pf | std::views::keys;
    // const auto ev = prime_factorization(phi_m) | std::views::keys;
    primes[phi_m] = std::vector<int>(ev.begin(), ev.end());
  }
  return std::none_of(primes[phi_m].begin(), primes[phi_m].end(),
                      [root, phi_m, m](const int p) -> bool {
                        return mod_pow(root, phi_m / p, m) == 1;
                      });
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_
