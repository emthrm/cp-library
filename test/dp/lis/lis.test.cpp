/*
 * @brief 動的計画法/LIS/最長増加部分列
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <iostream>
#include <vector>
#include "../../../dp/lis/lis.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::cout << lis(a, std::numeric_limits<int>::max()).size() << '\n';
  return 0;
}
