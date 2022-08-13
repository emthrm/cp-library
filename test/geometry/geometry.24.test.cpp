/*
 * @brief 計算幾何学/計算幾何学 (点の回転)
 */
#define PROBLEM "https://atcoder.jp/contests/abc259/tasks/abc259_b"
#define ERROR "1e-6"

#include <iomanip>
#include <iostream>

#include "../../geometry/geometry.hpp"

int main() {
  geometry::Point p;
  int d;
  std::cin >> p >> d;
  p = p.rotate(geometry::degree_to_radian(d));
  std::cout << std::fixed << std::setprecision(7) << p.x << ' ' << p.y << '\n';
  return 0;
}
