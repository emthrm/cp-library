/*
 * @brief 計算幾何学/計算幾何学 (最近点対)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"
#define ERROR "0.000001"

#include <iomanip>
#include <iostream>
#include <vector>
#include "../../geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<geometry::Point> p(n);
  for (int i = 0; i < n; ++i) std::cin >> p[i];
  std::cout << std::fixed << std::setprecision(7) << closest_pair(p) << '\n';
  return 0;
}
