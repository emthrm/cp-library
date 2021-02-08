/*
 * @brief 計算幾何学/計算幾何学 (鏡映)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR "0.00000001"

#include <iomanip>
#include <iostream>
#include "../../geometry/geometry.hpp"

int main() {
  geometry::Point p1, p2;
  int q;
  std::cin >> p1 >> p2 >> q;
  geometry::Segment p1p2(p1, p2);
  while (q--) {
    geometry::Point p0;
    std::cin >> p0;
    geometry::Point ans = reflection(p1p2, p0);
    std::cout << std::fixed << std::setprecision(9) << ans.x << ' ' << ans.y << '\n';
  }
  return 0;
}
