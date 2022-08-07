/*
 * @brief 動的計画法/最長増加部分列
 */
#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

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
  std::vector<int> ans;
  int i = 0;
  for (const int lis_i : longest_increasing_subsequence(a)) {
    while (a[i] != lis_i) ++i;
    ans.emplace_back(i++);
  }
  const int k = ans.size();
  std::cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    std::cout << ans[i] << " \n"[i + 1 == k];
  }
  return 0;
}
