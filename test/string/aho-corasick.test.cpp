/*
 * @title 文字列/Aho–Corasick algorithm
 *
 * verification-helper: PROBLEM https://yukicoder.me/problems/no/430
 */

#include <iostream>
#include <string>

#include "emthrm/string/aho-corasick.hpp"

int main() {
  std::string s;
  std::cin >> s;
  emthrm::AhoCorasick<> aho([](const char c) -> int { return c - 'A'; });
  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    std::string p;
    std::cin >> p;
    aho.add(p, i);
  }
  aho.build();
  std::cout << aho.match(s) << '\n';
  return 0;
}
