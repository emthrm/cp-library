/*
 * @brief 数学/畳み込み/数論変換
 */
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/convolution/ntt.hpp"

int main() {
  ModInt::set_mod(998244353);
  NTT ntt;
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < m; ++i) std::cin >> b[i];
  std::vector<ModInt> ans = ntt.convolution(a, b);
  for (int i = 0; i <= (n - 1) + (m - 1); ++i) std::cout << ans[i] << " \n"[i + 1 == (n - 1) + (m - 1)];
  return 0;
}
