/*
 * @brief 動的計画法/スライド最小値
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <iostream>
#include <vector>

#include "emthrm/dynamic_programming/slide_min.hpp"

int main() {
  int n, l;
  std::cin >> n >> l;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  const std::vector<int> ans = emthrm::slide_min(a, l);
  for (int i = 0; i + l <= n; ++i) {
    std::cout << ans[i] << " \n"[i + l == n];
  }
  return 0;
}
