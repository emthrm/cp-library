/*
 * @brief 計算幾何学/計算幾何学 (凸包)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

#include "emthrm/geometry/geometry.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<emthrm::geometry::Point> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }
  emthrm::geometry::Polygon convex_hull = monotone_chain(p, false);
  const int m = convex_hull.size();
  std::vector<std::pair<emthrm::geometry::Point, int>> ps;
  ps.reserve(m);
  for (int i = 0; i < m; ++i) {
    ps.emplace_back(convex_hull[i], i);
  }
  std::sort(
      ps.begin(), ps.end(),
      [](const std::pair<emthrm::geometry::Point, int>& a,
         const std::pair<emthrm::geometry::Point, int>& b) -> bool {
        const emthrm::geometry::Point& a_p = a.first;
        const emthrm::geometry::Point& b_p = b.first;
        const int sign = emthrm::geometry::sgn(b_p.y - a_p.y);
        return sign == 0 ?
               emthrm::geometry::sgn(b_p.x - a_p.x) == 1 : sign == 1;
      });
  std::rotate(convex_hull.begin(),
              std::next(convex_hull.begin(), ps.front().second),
              convex_hull.end());
  std::cout << m << '\n';
  for (const emthrm::geometry::Point& p : convex_hull) {
    std::cout << static_cast<int>(std::round(p.x)) << ' '
              << static_cast<int>(std::round(p.y)) << '\n';
  }
  return 0;
}
