#pragma once
#include <utility>
#include <vector>
#include "geometry.hpp"
#include "../util/xorshift.hpp"

geometry::Circle smallest_enclosing_circle(std::vector<geometry::Point> ps) {
  int n = ps.size();
  if (n == 1) return geometry::Circle(ps[0], 0);
  for (int i = 0; i < n; ++i) std::swap(ps[xor128.rand(n)], ps[xor128.rand(n)]);
  auto get_circle = [&](const geometry::Point &p1, const geometry::Point &p2) -> geometry::Circle {
    return geometry::Circle((p1 + p2) * 0.5, geometry::distance(p1, p2) * 0.5);
  };
  geometry::Circle res = get_circle(ps[0], ps[1]);
  auto is_in = [&](const geometry::Point &point) -> bool {
    return geometry::sgn(res.r - geometry::distance(res.p, point)) != -1;
  };
  for (int i = 2; i < n; ++i) {
    if (is_in(ps[i])) continue;
    res = get_circle(ps[0], ps[i]);
    for (int j = 1; j < i; ++j) {
      if (is_in(ps[j])) continue;
      res = get_circle(ps[j], ps[i]);
      for (int k = 0; k < j; ++k) {
        if (!is_in(ps[k])) {
          double a = (ps[i] - ps[j]).norm(), b = (ps[k] - ps[i]).norm(), c = (ps[j] - ps[k]).norm(), s = geometry::cross(ps[i] - ps[k], ps[j] - ps[k]);
          geometry::Point p = (ps[k] * a * (b + c - a) + ps[j] * b * (c + a - b) + ps[i] * c * (a + b - c)) / (4 * s * s);
          res = geometry::Circle(p, geometry::distance(ps[k], p));
        }
      }
    }
  }
  return res;
}
