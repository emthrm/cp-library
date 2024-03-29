/*
 * @title 文字列/Morris–Pratt algorithm（パターンマッチング）
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
 */

#include <iostream>
#include <string>

#include "emthrm/string/morris-pratt.hpp"

int main() {
  std::string t, p;
  std::cin >> t >> p;
  for (const int ans : emthrm::MorrisPratt(p).match(t)) {
    std::cout << ans << '\n';
  }
  return 0;
}
