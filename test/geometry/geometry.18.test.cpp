/*
 * @title 計算幾何学/計算幾何学 (多角形に対する点の内外判定)
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
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
  int q;
  std::cin >> q;
  while (q--) {
    emthrm::geometry::Point p;
    std::cin >> p;
    std::cout << emthrm::geometry::contains(g, p) << '\n';
  }
  return 0;
}
