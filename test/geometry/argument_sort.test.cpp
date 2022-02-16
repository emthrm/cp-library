/*
 * @brief 計算幾何学/偏角ソート
 */
#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include <iostream>
#include <utility>
#include <vector>

#include "../../geometry/argument_sort.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> ps(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> ps[i].first >> ps[i].second;
  }
  argument_sort(&ps);
  for (int i = 0; i < n; ++i) {
    std::cout << ps[i].first << ' ' << ps[i].second << '\n';
  }
  return 0;
}
