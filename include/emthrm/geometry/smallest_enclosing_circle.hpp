#ifndef EMTHRM_GEOMETRY_SMALLEST_ENCLOSING_CIRCLE_HPP_
#define EMTHRM_GEOMETRY_SMALLEST_ENCLOSING_CIRCLE_HPP_

#include <algorithm>
#include <random>
#include <utility>
#include <vector>

#include "emthrm/geometry/geometry.hpp"

namespace emthrm {

namespace geometry {

Circle smallest_enclosing_circle(std::vector<Point> ps) {
  const int n = ps.size();
  if (n == 1) [[unlikely]] return Circle(ps.front(), 0);
  std::shuffle(ps.begin(), ps.end(), std::mt19937_64(std::random_device {} ()));
  const auto get_circle = [](const Point& p1, const Point& p2) -> Circle {
    return Circle((p1 + p2) * 0.5, distance(p1, p2) * 0.5);
  };
  Circle res = get_circle(ps[0], ps[1]);
  const auto is_in = [&res](const Point& p) -> bool {
    return sgn(res.r - distance(res.p, p)) != -1;
  };
  for (int i = 2; i < n; ++i) {
    if (is_in(ps[i])) continue;
    res = get_circle(ps[0], ps[i]);
    for (int j = 1; j < i; ++j) {
      if (is_in(ps[j])) continue;
      res = get_circle(ps[j], ps[i]);
      for (int k = 0; k < j; ++k) {
        if (is_in(ps[k])) continue;
        const double a = (ps[i] - ps[j]).norm(), b = (ps[k] - ps[i]).norm();
        const double c = (ps[j] - ps[k]).norm();
        const double s = cross(ps[i] - ps[k], ps[j] - ps[k]);
        const Point p = (ps[k] * a * (b + c - a) + ps[j] * b * (c + a - b)
                         + ps[i] * c * (a + b - c)) / (4 * s * s);
        res = Circle(p, distance(ps[k], p));
      }
    }
  }
  return res;
}

}  // namespace geometry

}  // namespace emthrm

#endif  // EMTHRM_GEOMETRY_SMALLEST_ENCLOSING_CIRCLE_HPP_
