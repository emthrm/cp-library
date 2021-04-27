/*
 * @brief 数学/形式的冪級数/multipoint evaluation
 */
#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include <iostream>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/formal_power_series/formal_power_series.hpp"
#include "../../../math/convolution/number_theoretic_transform.hpp"
#include "../../../math/formal_power_series/multipoint_evaluation.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  NumberTheoreticTransform<0> ntt;
  FormalPowerSeries<ModInt>::set_mul([&](const std::vector<ModInt> &a, const std::vector<ModInt> &b) -> std::vector<ModInt> {
    return ntt.convolution(a, b);
  });
  int n, m;
  std::cin >> n >> m;
  FormalPowerSeries<ModInt> c(n - 1);
  for (int i = 0; i < n; ++i) std::cin >> c[i];
  std::vector<ModInt> p(m);
  for (int i = 0; i < m; ++i) std::cin >> p[i];
  MultipointEvaluation<FormalPowerSeries, ModInt> multieval(p);
  multieval.calc(c);
  for (int i = 0; i < m; ++i) std::cout << multieval.val[i] << " \n"[i + 1 == m];
  return 0;
}
