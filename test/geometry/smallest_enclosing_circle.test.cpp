/*
 * @brief 計算幾何学/最小包含円
 */
#define PROBLEM "https://atcoder.jp/contests/abc151/tasks/abc151_f"
#define ERROR "1e-6"

#include <iomanip>
#include <iostream>
#include <vector>

#include "../../geometry/geometry.hpp"
#include "../../geometry/smallest_enclosing_circle.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<geometry::Point> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }
  std::cout << std::fixed << std::setprecision(6)
            << geometry::smallest_enclosing_circle(p).r << '\n';
  return 0;
}
