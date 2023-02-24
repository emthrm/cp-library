/*
 * @title 計算幾何学/計算幾何学 (最近点対)
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
 * verification-helper: ERROR 0.000001
 */

#include <iomanip>
#include <iostream>
#include <vector>

#include "emthrm/geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<emthrm::geometry::Point> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }
  std::cout << std::fixed << std::setprecision(7)
            << emthrm::geometry::closest_pair(p) << '\n';
  return 0;
}
