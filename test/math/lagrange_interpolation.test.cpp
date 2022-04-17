/*
 * @brief 数学/ラグランジュ補間 評価版
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc033/tasks/arc033_4"

#include <iostream>
#include <numeric>
#include <vector>

#include "../../math/lagrange_interpolation.hpp"
#include "../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
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
  std::cout << lagrange_interpolation(x, a, t) << '\n';
  return 0;
}
