/*
 * @brief 数学/畳み込み/高速フーリエ変換
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/atc001/tasks/fft_c"

#include <iostream>
#include <vector>
#include "../../../math/convolution/fast_fourier_transform.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1, 0), b(n + 1, 0);
  for (int i = 1; i <= n; ++i) std::cin >> a[i] >> b[i];
  std::vector<fast_fourier_transform::Real> ans = fast_fourier_transform::convolution(a, b);
  for (int i = 1; i <= n * 2; ++i) std::cout << static_cast<long long>(ans[i] + 0.5) << '\n';
  return 0;
}
