/*
 * @brief 計算幾何学/計算幾何学 (単位ベクトル)
 */
#define PROBLEM "https://atcoder.jp/contests/abc246/tasks/abc246_b"
#define ERROR "1e-6"

#include <iomanip>
#include <iostream>

#include "../../geometry/geometry.hpp"

int main() {
  geometry::Point p;
  std::cin >> p;
  const geometry::Point ans = p.unit_vector();
  std::cout << std::fixed << std::setprecision(7)
            << ans.x << ' ' << ans.y << '\n';
  return 0;
}
