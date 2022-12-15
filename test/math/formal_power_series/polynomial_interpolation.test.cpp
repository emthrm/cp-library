/*
 * @brief 数学/形式的冪級数/多項式補間
 */
#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/formal_power_series/polynomial_interpolation.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<0>;
  ModInt::set_mod(998244353);
  emthrm::FormalPowerSeries<ModInt>::set_mult(
      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)
          -> std::vector<ModInt> {
        static emthrm::NumberTheoreticTransform<0> ntt;
        return ntt.convolution(a, b);
      });
  int n;
  std::cin >> n;
  std::vector<ModInt> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> y[i];
  }
  const emthrm::FormalPowerSeries<ModInt> c =
      emthrm::polynomial_interpolation<emthrm::FormalPowerSeries>(x, y);
  for (int i = 0; i < n; ++i) {
    std::cout << c[i] << " \n"[i + 1 == n];
  }
  return 0;
}
