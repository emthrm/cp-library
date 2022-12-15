/*
 * @brief 数学/写像12相/分割数 $n = m$ 版
 */
#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/partition_function_by_fps.hpp"

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
  const std::vector<ModInt> p = emthrm::partition_function_by_fps<ModInt>(n);
  for (int i = 0; i <= n; ++i) {
    std::cout << p[i] << " \n"[i == n];
  }
  return 0;
}
