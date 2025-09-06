/*
 * @title 計算幾何学/最小包含円
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/minimum_enclosing_circle
 */

#include <iostream>
#include <vector>

#include "emthrm/geometry/geometry.hpp"
#include "emthrm/geometry/smallest_enclosing_circle.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<emthrm::geometry::Point> p(n);
  for (auto& p_i : p) {
    std::cin >> p_i;
  }
  const auto c = emthrm::geometry::smallest_enclosing_circle(p);
  for (const auto& p_i : p) {
    std::cout << (emthrm::geometry::has_intersected(c, p_i) ? '1' : '0');
  }
  std::cout << '\n';
  return 0;
}
