/*
 * @brief 数学/形式的冪級数/形式的冪級数 (平方根)
 */
#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include <iostream>
#include <vector>

#include "../../../math/convolution/number_theoretic_transform.hpp"
#include "../../../math/formal_power_series/formal_power_series.hpp"
#include "../../../math/mod_sqrt.hpp"
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
  FormalPowerSeries<ModInt>::set_sqrt(
      [](const ModInt& a, ModInt* res) -> bool {
        const long long ans = mod_sqrt(a.v, ModInt::get_mod());
        if (ans == -1) {
          return false;
        } else {
          *res = ans;
          return true;
        }
      });
  int n;
  std::cin >> n;
  FormalPowerSeries<ModInt> a(n - 1);
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
