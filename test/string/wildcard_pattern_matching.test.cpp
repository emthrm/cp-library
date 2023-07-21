/*
 * @title 文字列/ワイルドカード ? を用いたパターンマッチング
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_h
 */

#include <iostream>
#include <string>

#include "emthrm/string/wildcard_pattern_matching.hpp"

int main() {
  int l, w;
  std::string s, p;
  std::cin >> l >> w >> s >> p;
  s = s + std::string(w - 1, '.') + s;
  if (l == w) {
    s.pop_back();
  } else {
    s += std::string(w - (l + 1), '.');
  }
  std::cout << emthrm::wildcard_pattern_matching(s, p, '_').size() << '\n';
  return 0;
}
