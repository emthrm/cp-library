/*
 * @title 数学/写像12相/スターリング数/第1種スターリング数の数表 形式的冪級数版
 */
#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_by_fps.hpp"

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
  const std::vector<ModInt> s =
      emthrm::stirling_number_of_the_first_kind_init_by_fps<ModInt>(n);
  for (int i = 0; i <= n; ++i) {
    std::cout << s[i] << " \n"[i == n];
  }
  return 0;
}
