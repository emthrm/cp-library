/*
 * @brief 数学/畳み込み/任意の法の下での畳み込み
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/atc001/tasks/fft_c"

#include <iostream>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/convolution/mod_convolution.hpp"

int main() {
  ModInt::set_mod(1000000001);
  int n;
  std::cin >> n;
  std::vector<ModInt> a(n + 1, 0), b(n + 1, 0);
  for (int i = 1; i <= n; ++i) std::cin >> a[i] >> b[i];
  std::vector<ModInt> ans = mod_convolution(a, b);
  for (int i = 1; i <= n * 2; ++i) std::cout << ans[i] << '\n';
  return 0;
}
