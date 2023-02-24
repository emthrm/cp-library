/*
 * @title 計算幾何学/計算幾何学 (凸多角形の直径)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR "0.000001"

#include <iomanip>
#include <iostream>
#include <tuple>

#include "emthrm/geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  emthrm::geometry::Polygon g(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> g[i];
  }
  const std::tuple<emthrm::geometry::Point, emthrm::geometry::Point> ans =
      rotating_calipers(g);
  std::cout << std::fixed << std::setprecision(7)
            << emthrm::geometry::distance(std::get<0>(ans), std::get<1>(ans))
            << '\n';
  return 0;
}
