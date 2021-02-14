/*
 * @brief 数学/メビウス関数/メビウス関数
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/problemset/problem/1139/D"

#include <iostream>
#include "../../../math/modint.hpp"
#include "../../../math/mobius_mu/mobius_mu.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int m;
  std::cin >> m;
  ModInt ans = 1;
  for (int i = 2; i <= m; ++i) ans -= (ModInt(m) / (m - m / i) - 1) * mobius_mu(i);
  std::cout << ans << '\n';
  return 0;
}
