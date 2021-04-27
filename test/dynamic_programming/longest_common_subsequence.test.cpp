/*
 * @brief 動的計画法/最長共通部分列
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_f"

#include <iostream>
#include <string>
#include "../../dynamic_programming/longest_common_subsequence.hpp"

int main() {
  std::string s, t;
  std::cin >> s >> t;
  std::cout << longest_common_subsequence(s, t) << '\n';
  return 0;
}
