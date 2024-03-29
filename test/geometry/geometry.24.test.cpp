/*
 * @title 計算幾何学/計算幾何学 (点の回転)
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/abc259/tasks/abc259_b
 * verification-helper: ERROR 1e-6
 */

#include <iomanip>
#include <iostream>

#include "emthrm/geometry/geometry.hpp"

int main() {
  emthrm::geometry::Point p;
  int d;
  std::cin >> p >> d;
  p = p.rotate(emthrm::geometry::degree_to_radian(d));
  std::cout << std::fixed << std::setprecision(7) << p.x << ' ' << p.y << '\n';
  return 0;
}
