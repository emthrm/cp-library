/*
 * @title 数学/畳み込み/高速フーリエ変換
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/atc001/tasks/fft_c
 */

#include <cmath>
#include <iostream>
#include <vector>

#include "emthrm/math/convolution/fast_fourier_transform.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1, 0), b(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i] >> b[i];
  }
  const std::vector<emthrm::fast_fourier_transform::Real> ans =
      emthrm::fast_fourier_transform::convolution(a, b);
  for (int i = 1; i <= n * 2; ++i) {
    std::cout << std::llround(ans[i]) << '\n';
  }
  return 0;
}
