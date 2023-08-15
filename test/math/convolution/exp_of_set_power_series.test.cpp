/*
 * @title 数学/畳み込み/集合冪級数の指数
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/exp_of_set_power_series
 */

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/exp_of_set_power_series.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  constexpr int kMaxN = 20;
  int n;
  std::cin >> n;
  std::vector<ModInt> b(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    std::cin >> b[i];
  }
  const std::vector<ModInt> c = emthrm::exp_of_set_power_series<kMaxN>(b);
  for (int i = 0; i < (1 << n); ++i) {
    std::cout << c[i] << " \n"[i + 1 == (1 << n)];
  }
  return 0;
}
