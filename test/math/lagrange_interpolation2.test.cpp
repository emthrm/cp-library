/*
 * @title 数学/ラグランジュ補間 評価版2
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/arc033/tasks/arc033_4
 */

#include <iostream>
#include <vector>

#include "emthrm/math/lagrange_interpolation2.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000007>;
  int n;
  std::cin >> n;
  std::vector<ModInt> a(n + 1);
  for (int i = 0; i <= n; ++i) {
    std::cin >> a[i];
  }
  ModInt t;
  std::cin >> t;
  std::cout << lagrange_interpolation(a, t) << '\n';
  return 0;
}
