/*
 * @brief 計算幾何学/計算幾何学 (接点)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
#define ERROR "0.00001"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "../../geometry/geometry.hpp"

int main() {
  geometry::Point p, c_o;
  double r;
  std::cin >> p >> c_o >> r;
  std::vector<geometry::Point> ans =
      geometry::tangency(geometry::Circle(c_o, r), p);
  std::sort(ans.begin(), ans.end());
  for (int i = 0; i < 2; ++i) {
    std::cout << std::fixed << std::setprecision(6)
              << ans[i].x << ' ' << ans[i].y << '\n';
  }
  return 0;
}
