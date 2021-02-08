/*
 * @brief 計算幾何学/計算幾何学 (多角形の面積)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"

#include <iomanip>
#include <iostream>
#include "../../geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  geometry::Polygon g(n);
  for (int i = 0; i < n; ++i) std::cin >> g[i];
  std::cout << std::fixed << std::setprecision(1) << geometry::area(g) << '\n';
  return 0;
}
