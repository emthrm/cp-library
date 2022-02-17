/*
 * @brief 数学/形式的冪級数/ベルヌーイ数
 */
#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include <iostream>
#include <vector>

#include "../../../math/convolution/number_theoretic_transform.hpp"
#include "../../../math/formal_power_series/bernoulli_number.hpp"
#include "../../../math/formal_power_series/formal_power_series.hpp"
#include "../../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  FormalPowerSeries<ModInt>::set_mult(
      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)
          -> std::vector<ModInt> {
        static NumberTheoreticTransform<0> ntt;
        return ntt.convolution(a, b);
      });
  int n;
  std::cin >> n;
  const std::vector<ModInt> b = bernoulli_number<ModInt>(n);
  for (int i = 0; i <= n; ++i) {
    std::cout << b[i] << " \n"[i == n];
  }
  return 0;
}
