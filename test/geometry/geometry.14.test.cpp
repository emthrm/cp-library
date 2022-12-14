/*
 * @brief 計算幾何学/計算幾何学 (2円の共通接線の本数)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"

#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  geometry::Point c1_o, c2_o;
  double c1r, c2r;
  std::cin >> c1_o >> c1r >> c2_o >> c2r;
  std::cout << geometry::common_tangent_num(geometry::Circle(c1_o, c1r),
                                            geometry::Circle(c2_o, c2r))
            << '\n';
  return 0;
}
