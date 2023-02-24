/*
 * @title 計算幾何学/計算幾何学 (ccw(a, b, c))
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
 */

#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  emthrm::geometry::Point p0, p1;
  int q;
  std::cin >> p0 >> p1 >> q;
  while (q--) {
    emthrm::geometry::Point p2;
    std::cin >> p2;
    const int ans = ccw(p0, p1, p2);
    if (ans == -2) {
      std::cout << "ONLINE_FRONT\n";
    } else if (ans == -1) {
      std::cout << "CLOCKWISE\n";
    } else if (ans == 0) {
      std::cout << "ON_SEGMENT\n";
    } else if (ans == 1) {
      std::cout << "COUNTER_CLOCKWISE\n";
    } else if (ans == 2) {
      std::cout << "ONLINE_BACK\n";
    }
  }
  return 0;
}
