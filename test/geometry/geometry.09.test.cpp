/*
 * @title 計算幾何学/計算幾何学 (直線と円の交点)
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
 * verification-helper: ERROR 0.000001
 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "emthrm/geometry/geometry.hpp"

int main() {
  emthrm::geometry::Point c;
  int r, q;
  std::cin >> c >> r >> q;
  emthrm::geometry::Circle circle(c, r);
  while (q--) {
    emthrm::geometry::Point p1, p2;
    std::cin >> p1 >> p2;
    std::vector<emthrm::geometry::Point> ans =
        emthrm::geometry::intersection(circle, emthrm::geometry::Line(p1, p2));
    std::sort(ans.begin(), ans.end());
    if (ans.size() == 1) {
      std::cout << std::fixed << std::setprecision(7)
                << ans[0].x << ' ' << ans[0].y << ' '
                << ans[0].x << ' ' << ans[0].y << '\n';
    } else if (ans.size() == 2) {
      for (int i = 0; i < 2; ++i) {
        std::cout << std::fixed << std::setprecision(7)
                  << ans[i].x << ' ' << ans[i].y << " \n"[i + 1 == 2];
      }
    }
  }
  return 0;
}
