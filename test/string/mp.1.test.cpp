/*
 * @brief 文字列/MP 法 (`match(t)`)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "../../string/mp.hpp"

int main() {
  std::string t, p;
  std::cin >> t >> p;
  for (int e : MP(p).match(t)) std::cout << e << '\n';
  return 0;
}
