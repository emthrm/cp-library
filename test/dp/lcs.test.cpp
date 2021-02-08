/*
 * @brief 動的計画法/最長共通部分列
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_f"

#include <iostream>
#include <string>
#include "../../dp/lcs.hpp"

int main() {
  std::string s, t;
  std::cin >> s >> t;
  std::cout << lcs(s, t) << '\n';
  return 0;
}
