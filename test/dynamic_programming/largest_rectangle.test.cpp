/*
 * @title 動的計画法/ヒストグラム中の最大長方形
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
 */

#include <iostream>
#include <vector>

#include "emthrm/dynamic_programming/largest_rectangle.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> h[i];
  }
  std::cout << emthrm::largest_rectangle(h) << '\n';
  return 0;
}
