/*
 * @title 数学/畳み込み/添え字 and での畳み込み
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/bitwise_and_convolution
 */

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/and_convolution.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  int n;
  std::cin >> n;
  std::vector<ModInt> a(1 << n), b(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < (1 << n); ++i) {
    std::cin >> b[i];
  }
  const std::vector<ModInt> c = emthrm::and_convolution(a, b);
  for (int i = 0; i < (1 << n); ++i) {
    std::cout << c[i] << " \n"[i + 1 == 1 << n];
  }
  return 0;
}
