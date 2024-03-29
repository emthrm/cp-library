/*
 * @title 数学/形式的冪級数/多項式列の相乗
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/product_of_polynomial_sequence
 */

#include <cassert>
#include <iostream>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/formal_power_series/product_of_polynomial_sequence.hpp"
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
  int n;
  std::cin >> n;
  int degree = 0;
  std::vector<emthrm::FormalPowerSeries<ModInt>> f(n);
  for (int i = 0; i < n; ++i) {
    int d;
    std::cin >> d;
    degree += d;
    f[i].resize(d);
    for (int j = 0; j <= d; ++j) {
      std::cin >> f[i][j];
    }
  }
  emthrm::FormalPowerSeries<ModInt> a =
      emthrm::product_of_polynomial_sequence(f);
  assert(a.degree() <= degree);
  a.resize(degree);
  for (int i = 0; i <= degree; ++i) {
    std::cout << a[i] << " \n"[i == degree];
  }
  return 0;
}
