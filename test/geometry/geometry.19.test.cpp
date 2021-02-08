/*
 * @brief 計算幾何学/計算幾何学 (凸性判定)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"

#include <iostream>
#include "../../geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  geometry::Polygon g(n);
  for (int i = 0; i < n; ++i) std::cin >> g[i];
  std::cout << geometry::is_convex(g) << '\n';
  return 0;
}
