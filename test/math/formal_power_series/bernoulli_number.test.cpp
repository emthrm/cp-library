/*
 * @title 数学/形式的冪級数/ベルヌーイ数
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/bernoulli_number
 */

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/formal_power_series/bernoulli_number.hpp"
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
  int n;
  std::cin >> n;
  const std::vector<ModInt> b = emthrm::bernoulli_number<ModInt>(n);
  for (int i = 0; i <= n; ++i) {
    std::cout << b[i] << " \n"[i == n];
  }
  return 0;
}
