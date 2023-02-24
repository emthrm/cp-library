/*
 * @title 計算幾何学/計算幾何学 (2線分の交差判定)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  int q;
  std::cin >> q;
  while (q--) {
    emthrm::geometry::Point p0, p1, p2, p3;
    std::cin >> p0 >> p1 >> p2 >> p3;
    std::cout << emthrm::geometry::has_intersected(
                     emthrm::geometry::Segment(p0, p1),
                     emthrm::geometry::Segment(p2, p3))
              << '\n';
  }
  return 0;
}
