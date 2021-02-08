/*
 * @brief 文字列/ローリングハッシュ
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "../../string/rolling_hash.hpp"

int main() {
  std::string t, p;
  std::cin >> t >> p;
  RollingHash<> rh_t(t), rh_p(p);
  for (int i = 0; i < t.length(); ++i) {
    if (i + p.length() <= t.length() && rh_t.get(i, i + p.length()) == rh_p.get(0, p.length())) {
      std::cout << i << '\n';
    }
  }
  return 0;
}
