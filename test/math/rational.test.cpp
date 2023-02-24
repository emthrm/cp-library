/*
 * @title 数学/有理数
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589"

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "emthrm/math/rational.hpp"

int main() {
  using rational = emthrm::Rational<>;
  constexpr int OCCURRENCE = 20;
  int p[OCCURRENCE + 1]{};
  std::fill(p, p + (OCCURRENCE + 1), 1);
  for (int i = 1; i <= OCCURRENCE; ++i) {
    p[i] = p[i - 1] * 2;
  }
  while (true) {
    std::string s;
    std::cin >> s;
    if (s == "#") break;
    const int n = s.length();
    std::vector<int> dir;
    for (int i = 0; i < n;) {
      if (s[i] == 'n') {
        dir.emplace_back(0);
        i += 5;
      } else {
        dir.emplace_back(90);
        i += 4;
      }
    }
    std::reverse(dir.begin(), dir.end());
    rational ans = dir.front();
    for (int i = 1; std::cmp_less(i, dir.size()); ++i) {
      ans += rational(90, p[i]) * (dir[i] == 0 ? -1 : 1);
    }
    std::cout << ans << '\n';
  }
  return 0;
}
