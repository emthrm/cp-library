/*
 * @brief 計算幾何学/計算幾何学 (凸包)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include "../../geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<geometry::Point> p(n);
  for (int i = 0; i < n; ++i) std::cin >> p[i];
  geometry::Polygon convex_hull = monotone_chain(p, false);
  int sz = convex_hull.size();
  std::vector<std::pair<geometry::Point, int>> ps;
  for (int i = 0; i < sz; ++i) ps.emplace_back(convex_hull[i], i);
  std::sort(ps.begin(), ps.end(), [](const std::pair<geometry::Point, int> &a, const std::pair<geometry::Point, int> &b) -> bool {
    const geometry::Point &a_p = a.first, &b_p = b.first;
    int sign = geometry::sgn(b_p.y - a_p.y);
    return sign == 0 ? geometry::sgn(b_p.x - a_p.x) == 1 : sign == 1;
  });
  std::rotate(convex_hull.begin(), convex_hull.begin() + ps.front().second, convex_hull.end());
  std::cout << sz << '\n';
  for (const geometry::Point &e : convex_hull) {
    std::cout << static_cast<int>(std::round(e.x)) << ' ' << static_cast<int>(std::round(e.y)) << '\n';
  }
  return 0;
}
