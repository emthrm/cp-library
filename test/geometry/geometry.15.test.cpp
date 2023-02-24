/*
 * @title 計算幾何学/計算幾何学 (2円の共通接線)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G"
#define ERROR "0.00001"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <vector>

#include "emthrm/geometry/geometry.hpp"

int main() {
  emthrm::geometry::Point c1_o, c2_o;
  double c1r, c2r;
  std::cin >> c1_o >> c1r >> c2_o >> c2r;
  // GCC 12 adopted P2415.
  const std::vector<emthrm::geometry::Line> tangents =
      emthrm::geometry::common_tangent(emthrm::geometry::Circle(c1_o, c1r),
                                       emthrm::geometry::Circle(c2_o, c2r));
  const auto ev = tangents | std::views::transform(&emthrm::geometry::Line::s);
  // const auto ev =
  //     emthrm::geometry::common_tangent(emthrm::geometry::Circle(c1_o, c1r),
  //                                      emthrm::geometry::Circle(c2_o, c2r))
  //     | std::views::transform(&emthrm::geometry::Line::s);
  std::vector<emthrm::geometry::Point> ans(ev.begin(), ev.end());
  std::sort(ans.begin(), ans.end());
  for (const emthrm::geometry::Point& p : ans) {
    std::cout << std::fixed << std::setprecision(6)
              << p.x << ' ' << p.y << '\n';
  }
  return 0;
}
