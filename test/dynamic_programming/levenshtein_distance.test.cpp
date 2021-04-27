/*
 * @brief 動的計画法/レーベンシュタイン距離
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E"

#include <iostream>
#include <string>
#include "../../dynamic_programming/levenshtein_distance.hpp"

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;
  std::cout << levenshtein_distance(s1, s2) << '\n';
  return 0;
}
