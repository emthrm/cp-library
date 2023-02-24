/*
 * @title 計算幾何学/計算幾何学 (2線分の距離)
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
 * verification-helper: ERROR 0.00000001
 */

#include <iomanip>
#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  int q;
  std::cin >> q;
  while (q--) {
    emthrm::geometry::Point p0, p1, p2, p3;
    std::cin >> p0 >> p1 >> p2 >> p3;
    std::cout << std::fixed << std::setprecision(9)
              << emthrm::geometry::distance(emthrm::geometry::Segment(p0, p1),
                                    emthrm::geometry::Segment(p2, p3))
              << '\n';
  }
  return 0;
}
