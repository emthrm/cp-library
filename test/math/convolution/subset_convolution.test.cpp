/*
 * @title 数学/畳み込み/subset convolution
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/subset_convolution
 */

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/subset_convolution.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  constexpr int kMaxN = 20;
  int n;
  std::cin >> n;
  std::vector<ModInt> a(1 << n), b(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < (1 << n); ++i) {
    std::cin >> b[i];
  }
  const std::vector<ModInt> c = emthrm::subset_convolution<kMaxN>(a, b);
  for (int i = 0; i < (1 << n); ++i) {
    std::cout << c[i] << " \n"[i + 1 == (1 << n)];
  }
  return 0;
}
