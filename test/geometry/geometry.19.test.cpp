/*
 * @title 計算幾何学/計算幾何学（凸性判定）
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
 */

#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  emthrm::geometry::Polygon g(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> g[i];
  }
  std::cout << emthrm::geometry::is_convex(g) << '\n';
  return 0;
}
