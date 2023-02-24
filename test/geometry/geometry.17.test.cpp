/*
 * @title 計算幾何学/計算幾何学 (多角形の面積)
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
 */

#include <iomanip>
#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  emthrm::geometry::Polygon g(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> g[i];
  }
  std::cout << std::fixed << std::setprecision(1)
            << emthrm::geometry::area(g) << '\n';
  return 0;
}
