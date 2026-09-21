#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_MULTIPOINT_BINOMIAL_PREFIX_SUM_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_MULTIPOINT_BINOMIAL_PREFIX_SUM_HPP_

#include <algorithm>
#include <cassert>
#include <vector>

#include "emthrm/math/modint.hpp"
#include "emthrm/misc/mo.hpp"

namespace emthrm {

template <unsigned int T>
std::vector<MInt<T>> multipoint_binomial_prefix_sum(
    const std::vector<int>& ns, const std::vector<int>& ms) {
  using ModInt = MInt<T>;
  assert(ns.size() == ms.size());
  if (ns.empty()) [[unlikely]] return {};
  assert(T % 2 == 1);
  const int q = ns.size();
  for (int i = 0; i < q; ++i) {
    assert(0 <= ms[i] && ms[i] <= ns[i]);
  }
  ModInt::init(std::ranges::max(ns));
  ModInt sum = 1;
  Mo mo(ms, ns,
        // S(n, m) -> S(n, m - 1)
        [&sum](const int, const int m, const int n) {
          sum -= ModInt::nCk(n, m + 1);
        },
        // S(n, m) -> S(n + 1, m)
        [&sum](const int, const int m, const int n) {
          sum += sum - ModInt::nCk(n - 1, m);
        },
        // S(n, m) -> S(n, m + 1)
        [&sum](const int, const int m, const int n) {
          sum += ModInt::nCk(n, m);
        },
        // S(n, m) -> S(n - 1, m)
        [&sum](const int, const int m, const int n) {
          static const ModInt inv2 = ModInt::inv(2);
          sum = (sum + ModInt::nCk(n, m)) * inv2;
        });
  std::vector<ModInt> ans(q);
  for (int i = 0; i < q; ++i) {
    const int idx = mo.process();
    ans[idx] = sum;
  }
  return ans;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_MULTIPOINT_BINOMIAL_PREFIX_SUM_HPP_
