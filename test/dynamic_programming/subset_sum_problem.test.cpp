/*
 * @title 動的計画法/部分和問題
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/sharp_p_subset_sum
 */

#include <iostream>
#include <vector>

#include "emthrm/dynamic_programming/subset_sum_problem.hpp"
#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  constexpr int MOD = 998244353;
  using ModInt = emthrm::MInt<MOD>;
  emthrm::FormalPowerSeries<ModInt>::set_mult(
      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)
          -> std::vector<ModInt> {
        static emthrm::NumberTheoreticTransform<MOD> ntt;
        return ntt.convolution(a, b);
      });
  int n, t;
  std::cin >> n >> t;
  std::vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
  }
  const std::vector<ModInt> p = emthrm::subset_sum_problem<ModInt>(s, t);
  for (int i = 1; i <= t; ++i) {
    std::cout << p[i] << " \n"[i == t];
  }
  return 0;
}
