/*
 * @title 数学/畳み込み/数論変換
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/convolution_mod
 */

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  constexpr int MOD = 998244353;
  using ModInt = emthrm::MInt<MOD>;
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  const std::vector<ModInt> ans =
      emthrm::NumberTheoreticTransform<MOD>().convolution(a, b);
  for (int i = 0; i <= (n - 1) + (m - 1); ++i) {
    std::cout << ans[i] << " \n"[i == (n - 1) + (m - 1)];
  }
  return 0;
}
