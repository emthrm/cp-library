/*
 * @brief 数学/形式的冪級数/形式的冪級数 (逆元)
 */
#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <iostream>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/formal_power_series/formal_power_series.hpp"
#include "../../../math/convolution/number_theoretic_transform.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  FormalPowerSeries<ModInt>::set_mul(
      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b) -> std::vector<ModInt> {
        static NumberTheoreticTransform<0> ntt;
        return ntt.convolution(a, b);
      });
  int n;
  std::cin >> n;
  FormalPowerSeries<ModInt> b(n - 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> b[i];
  }
  b = b.inv(n - 1);
  for (int i = 0; i < n; ++i) {
    std::cout << b[i] << " \n"[i + 1 == n];
  }
  return 0;
}
