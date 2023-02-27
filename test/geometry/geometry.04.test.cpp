/*
 * @title 計算幾何学/計算幾何学（鏡映）
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
 * verification-helper: ERROR 0.00000001
 */

#include <iomanip>
#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  emthrm::geometry::Point p1, p2;
  int q;
  std::cin >> p1 >> p2 >> q;
  const emthrm::geometry::Segment p1p2(p1, p2);
  while (q--) {
    emthrm::geometry::Point p0;
    std::cin >> p0;
    const emthrm::geometry::Point ans = reflection(p1p2, p0);
    std::cout << std::fixed << std::setprecision(9)
              << ans.x << ' ' << ans.y << '\n';
  }
  return 0;
}
