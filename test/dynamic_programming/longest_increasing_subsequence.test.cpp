/*
 * @brief 動的計画法/最長増加部分列
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <iostream>
#include <vector>

#include "../../dynamic_programming/longest_increasing_subsequence.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::cout << longest_increasing_subsequence(a).size() << '\n';
  return 0;
}
