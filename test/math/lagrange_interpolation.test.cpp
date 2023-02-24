/*
 * @title 数学/ラグランジュ補間 評価版
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/arc033/tasks/arc033_4
 */

#include <iostream>
#include <numeric>
#include <vector>

#include "emthrm/math/lagrange_interpolation.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000007>;
  int n;
  std::cin >> n;
  std::vector<ModInt> x(n + 1);
  std::iota(x.begin(), x.end(), 0);
  std::vector<ModInt> a(n + 1);
  for (int i = 0; i <= n; ++i) {
    std::cin >> a[i];
  }
  ModInt t;
  std::cin >> t;
  std::cout << emthrm::lagrange_interpolation(x, a, t) << '\n';
  return 0;
}
