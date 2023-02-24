/*
 * @title 計算幾何学/計算幾何学 (単位ベクトル)
 *
 * verification-helper: PROBLEM https://atcoder.jp/contests/abc246/tasks/abc246_b
 * verification-helper: ERROR 1e-6
 */

#include <iomanip>
#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  emthrm::geometry::Point p;
  std::cin >> p;
  const emthrm::geometry::Point ans = emthrm::geometry::unit_vector(p);
  std::cout << std::fixed << std::setprecision(7)
            << ans.x << ' ' << ans.y << '\n';
  return 0;
}
