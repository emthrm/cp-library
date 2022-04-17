/*
 * @brief 数学/写像12相/スターリング数/第2種スターリング数の数表 形式的冪級数版
 */
#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include <iostream>
#include <vector>

#include "../../../../math/convolution/number_theoretic_transform.hpp"
#include "../../../../math/formal_power_series/formal_power_series.hpp"
#include "../../../../math/modint.hpp"
#include "../../../../math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp"

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
  const std::vector<ModInt> s =
      stirling_number_of_the_second_kind_init_by_fps<0>(n);
  for (int i = 0; i <= n; ++i) {
    std::cout << s[i] << " \n"[i == n];
  }
  return 0;
}
