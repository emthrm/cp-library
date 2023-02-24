/*
 * @title 計算幾何学/計算幾何学 (平行 / 垂直)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  int q;
  std::cin >> q;
  while (q--) {
    emthrm::geometry::Point p0, p1, p2, p3;
    std::cin >> p0 >> p1 >> p2 >> p3;
    const emthrm::geometry::Line s1(p0, p1), s2(p2, p3);
    if (emthrm::geometry::is_parallel(s1, s2)) {
      std::cout << "2\n";
    } else if (emthrm::geometry::is_orthogonal(s1, s2)) {
      std::cout << "1\n";
    } else {
      std::cout << "0\n";
    }
  }
  return 0;
}
