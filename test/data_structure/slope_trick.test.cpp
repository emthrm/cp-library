/*
 * @brief データ構造/slope trick
 */
#define PROBLEM "https://atcoder.jp/contests/arc123/tasks/arc123_d"

#include <algorithm>
#include <iostream>
#include <vector>

#include "emthrm/data_structure/slope_trick.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  SlopeTrick<long long> slope_trick(0);
  slope_trick.abs_x_minus_a(0);
  slope_trick.abs_x_minus_a(a.front());
  for (int i = 1; i < n; ++i) {
    slope_trick.translate(std::max(a[i] - a[i - 1], 0));
    slope_trick.cumulative_min();
    slope_trick.abs_x_minus_a(0);
    slope_trick.abs_x_minus_a(a[i]);
  }
  std::cout << slope_trick.min() << '\n';
  return 0;
}
