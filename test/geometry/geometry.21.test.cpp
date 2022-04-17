/*
 * @brief 計算幾何学/計算幾何学 (凸多角形の切断)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR "0.00001"

#include <iomanip>
#include <iostream>

#include "../../geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  geometry::Polygon g(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> g[i];
  }
  int q;
  std::cin >> q;
  while (q--) {
    geometry::Point p1, p2;
    std::cin >> p1 >> p2;
    std::cout << std::fixed << std::setprecision(6)
              << geometry::area(
                     geometry::cut_convex(g, geometry::Line(p1, p2)))
              << '\n';
  }
  return 0;
}
