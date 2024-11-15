/*
 * @title 文字列/ワイルドカード ? を用いたパターンマッチング
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/wildcard_pattern_matching
 */

#include <iostream>
#include <string>

#include "emthrm/string/wildcard_pattern_matching.hpp"

int main() {
  std::string s, t;
  std::cin >> s >> t;
  std::string w(s.length() - t.length() + 1, '0');
  for (const int i : emthrm::wildcard_pattern_matching(s, t, '*')) w[i] = '1';
  std::cout << w << '\n';
  return 0;
}
