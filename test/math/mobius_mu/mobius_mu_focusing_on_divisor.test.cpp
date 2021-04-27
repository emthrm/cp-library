/*
 * @brief 数学/メビウス関数/メビウス関数 約数版
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/problemset/problem/1139/D"

#include <iostream>
#include <map>
#include <utility>
#include "../../../math/modint.hpp"
#include "../../../math/mobius_mu/mobius_mu_focusing_on_divisor.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int m;
  std::cin >> m;
  std::map<int, int> mp;
  ModInt ans = 1;
  for (int i = m; i >= 2; --i) {
    if (mp.count(i) == 0) {
      for (const std::pair<int, int> &pr : mobius_mu_focusing_on_divisor(i)) mp[pr.first] = pr.second;
    }
    ans -= (ModInt(m) / (m - m / i) - 1) * mp[i];
  }
  std::cout << ans << '\n';
  return 0;
}
