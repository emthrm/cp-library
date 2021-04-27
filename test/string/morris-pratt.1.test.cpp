/*
 * @brief 文字列/Morris-Pratt algorithm (match(t))
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "../../string/morris-pratt.hpp"

int main() {
  std::string t, p;
  std::cin >> t >> p;
  for (int e : MorrisPratt(p).match(t)) std::cout << e << '\n';
  return 0;
}
