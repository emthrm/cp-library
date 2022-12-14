/*
 * @brief 計算幾何学/計算幾何学 (2線分の距離)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR "0.00000001"

#include <iomanip>
#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  int q;
  std::cin >> q;
  while (q--) {
    geometry::Point p0, p1, p2, p3;
    std::cin >> p0 >> p1 >> p2 >> p3;
    std::cout << std::fixed << std::setprecision(9)
              << geometry::distance(geometry::Segment(p0, p1),
                                    geometry::Segment(p2, p3))
              << '\n';
  }
  return 0;
}
