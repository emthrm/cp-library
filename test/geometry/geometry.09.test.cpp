/*
 * @brief 計算幾何学/計算幾何学 (直線と円の交点)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR "0.000001"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "../../geometry/geometry.hpp"

int main() {
  geometry::Point c;
  int r, q;
  std::cin >> c >> r >> q;
  geometry::Circle circle(c, r);
  while (q--) {
    geometry::Point p1, p2;
    std::cin >> p1 >> p2;
    std::vector<geometry::Point> ans =
        geometry::intersection(circle, geometry::Line(p1, p2));
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
