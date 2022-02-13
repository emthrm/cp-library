/*
 * @brief 計算幾何学/計算幾何学 (凸多角形の直径)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR "0.000001"

#include <iomanip>
#include <iostream>
#include <utility>
#include "../../geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  geometry::Polygon g(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> g[i];
  }
  const std::pair<geometry::Point, geometry::Point> ans = rotating_calipers(g);
  std::cout << std::fixed << std::setprecision(7)
            << geometry::distance(ans.first, ans.second) << '\n';
  return 0;
}
