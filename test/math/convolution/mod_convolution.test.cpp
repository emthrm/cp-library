/*
 * @title 数学/畳み込み/任意の法の下での畳み込み
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/atc001/tasks/fft_c
 */

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/mod_convolution.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000001>;
  int n;
  std::cin >> n;
  std::vector<ModInt> a(n + 1, 0), b(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i] >> b[i];
  }
  const std::vector<ModInt> ans = emthrm::mod_convolution(a, b);
  for (int i = 1; i <= n * 2; ++i) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}
