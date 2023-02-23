#ifndef EMTHRM_MATH_CHINESE_REMAINDER_THEOREM_HPP_
#define EMTHRM_MATH_CHINESE_REMAINDER_THEOREM_HPP_

#include <numeric>
#include <utility>
#include <vector>

#include "emthrm/math/mod_inv.hpp"

namespace emthrm {

template <typename T>
std::pair<T, T> chinese_remainder_theorem(std::vector<T> b, std::vector<T> m) {
  const int n = b.size();
  T x = 0, md = 1;
  for (int i = 0; i < n; ++i) {
    if ((b[i] %= m[i]) < 0) b[i] += m[i];
    if (md < m[i]) {
      std::swap(x, b[i]);
      std::swap(md, m[i]);
    }
    if (md % m[i] == 0) {
      if (x % m[i] != b[i]) return {0, 0};
      continue;
    }
    const T g = std::gcd(md, m[i]);
    if ((b[i] - x) % g != 0) return {0, 0};
    const T u_i = m[i] / g;
    x += (b[i] - x) / g % u_i * mod_inv(md / g, u_i) % u_i * md;
    md *= u_i;
    if (x < 0) x += md;
  }
  return {x, md};
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CHINESE_REMAINDER_THEOREM_HPP_
