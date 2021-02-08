/*
 * @brief 計算幾何学/計算幾何学 (2円の交点)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"
#define ERROR "0.000001"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "../../geometry/geometry.hpp"

int main() {
  geometry::Point c1_o, c2_o;
  double c1r, c2r;
  std::cin >> c1_o >> c1r >> c2_o >> c2r;
  std::vector<geometry::Point> ans = geometry::intersection(geometry::Circle(c1_o, c1r), geometry::Circle(c2_o, c2r));
  std::sort(ans.begin(), ans.end());
  if (ans.size() == 1) {
    std::cout << std::fixed << std::setprecision(7) << ans[0].x << ' ' << ans[0].y << ' ' << ans[0].x << ' ' << ans[0].y << '\n';
  } else if (ans.size() == 2) {
    for (int i = 0; i < 2; ++i) {
      std::cout << std::fixed << std::setprecision(7) << ans[i].x << ' ' << ans[i].y << " \n"[i + 1 == 2];
    }
  }
  return 0;
}
