/*
 * @brief 動的計画法/最長共通部分列
 */
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <iostream>
#include <string>

#include "../../dynamic_programming/longest_common_subsequence.hpp"

int main() {
  int q;
  std::cin >> q;
  while (q--) {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << longest_common_subsequence(s, t).length() << '\n';
  }
  return 0;
}
