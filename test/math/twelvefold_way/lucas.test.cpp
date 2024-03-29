/*
 * @title 数学/写像12相/Lucas の定理
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/arc117/tasks/arc117_c
 */

#include <iostream>
#include <map>
#include <string>

#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/lucas.hpp"

int main() {
  constexpr int C = 3;
  using ModInt = emthrm::MInt<C>;
  const std::string color = "BWR";
  std::map<char, int> mp;
  for (int i = 0; i < C; ++i) {
    mp[color[i]] = i;
  }
  int n;
  std::cin >> n;
  std::string c;
  std::cin >> c;
  ModInt ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += emthrm::lucas<C>(n - 1, i) * mp[c[i]];
  }
  if (n % 2 == 0) ans = -ans;
  std::cout << color[ans.v] << '\n';
  return 0;
}
