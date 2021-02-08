#pragma once
#include <cassert>
#include <cmath>
#include <utility>
#include <vector>

std::vector<double> quadratic_equation(double a, double b, double c, const double EPS = 1e-8) {
  if (std::abs(a) < EPS) {
    if (std::abs(b) < EPS) {
      assert(std::abs(c) >= EPS);
      return {};
    }
    return {-c / b};
  }
  double d = b * b - 4 * a * c;
  if (std::abs(d) < EPS) return {-0.5 * b / a};
  if (d <= -EPS) return {};
  d = std::sqrt(d);
  double x1 = -0.5 * (b >= 0 ? b + d : b - d) / a, x2 = c / (x1 * a);
  if (x1 > x2) std::swap(x1, x2);
  return {x1, x2};
}
