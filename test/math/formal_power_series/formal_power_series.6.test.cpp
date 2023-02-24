/*
 * @title 数学/形式的冪級数/形式的冪級数 (平方根)
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
 */

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/mod_sqrt.hpp"
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
  emthrm::FormalPowerSeries<ModInt>::set_sqrt(
      [](const ModInt& a, ModInt* res) -> bool {
        const long long ans = emthrm::mod_sqrt(a.v, ModInt::get_mod());
        if (ans == -1) {
          return false;
        } else {
          *res = ans;
          return true;
        }
      });
  int n;
  std::cin >> n;
  emthrm::FormalPowerSeries<ModInt> a(n - 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  a = a.sqrt(n - 1);
  if (a.coef.empty()) {
    std::cout << "-1\n";
  } else {
    for (int i = 0; i < n; ++i) {
      std::cout << a[i] << " \n"[i + 1 == n];
    }
  }
  return 0;
}
