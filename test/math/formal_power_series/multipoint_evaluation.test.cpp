/*
 * @title 数学/形式的冪級数/multipoint evaluation
 */
#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/formal_power_series/multipoint_evaluation.hpp"
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
  int n, m;
  std::cin >> n >> m;
  emthrm::FormalPowerSeries<ModInt> c(n - 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
  }
  std::vector<ModInt> p(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> p[i];
  }
  emthrm::MultipointEvaluation<emthrm::FormalPowerSeries, ModInt>
      multipoint_evaluation(p);
  multipoint_evaluation.build(c);
  for (int i = 0; i < m; ++i) {
    std::cout << multipoint_evaluation.f_x[i] << " \n"[i + 1 == m];
  }
  return 0;
}
