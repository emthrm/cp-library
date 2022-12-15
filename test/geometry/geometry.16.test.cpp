/*
 * @brief 計算幾何学/計算幾何学 (2円の共通部分の面積)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_I"
#define ERROR "0.000001"

#include <iomanip>
#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  emthrm::geometry::Point c1_o, c2_o;
  double c1r, c2r;
  std::cin >> c1_o >> c1r >> c2_o >> c2r;
  std::cout << std::fixed << std::setprecision(7)
            << emthrm::geometry::intersection_area(
                   emthrm::geometry::Circle(c1_o, c1r),
                   emthrm::geometry::Circle(c2_o, c2r))
            << '\n';
  return 0;
}
