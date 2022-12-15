/*
 * @brief 数学/形式的冪級数/形式的冪級数 (translate(c))
 */
#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
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
  int n, c;
  std::cin >> n >> c;
  emthrm::FormalPowerSeries<ModInt> a(n - 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  a = a.translate(c);
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << " \n"[i + 1 == n];
  }
  return 0;
}
