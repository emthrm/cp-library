/*
 * @brief 数学/形式的冪級数/形式的冪級数 (累乗)
 */
#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
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
  long long m;
  std::cin >> n >> m;
  emthrm::FormalPowerSeries<ModInt> a(n - 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  a = a.pow(m, n - 1);
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << " \n"[i + 1 == n];
  }
  return 0;
}
