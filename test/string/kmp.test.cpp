/*
 * @brief 文字列/KMP 法
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "../../string/kmp.hpp"

int main() {
  std::string t, p;
  std::cin >> t >> p;
  for (int e : KMP<>(p).match(t)) std::cout << e << '\n';
  return 0;
}
