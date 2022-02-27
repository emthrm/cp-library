/*
 * @brief 文字列/Knuth–Morris–Pratt algorithm
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>

#include "../../string/knuth-morris-pratt.hpp"

int main() {
  std::string t, p;
  std::cin >> t >> p;
  for (const int ans : KnuthMorrisPratt<>(p).match(t)) std::cout << ans << '\n';
  return 0;
}
