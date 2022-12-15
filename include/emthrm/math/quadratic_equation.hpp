#ifndef EMTHRM_MATH_QUADRATIC_EQUATION_HPP_
#define EMTHRM_MATH_QUADRATIC_EQUATION_HPP_

#include <cassert>
#include <cmath>
#include <vector>

namespace emthrm {

std::vector<double> quadratic_equation(double a, double b, double c,
                                       const double eps = 1e-8) {
  if (std::abs(a) < eps) {
    if (std::abs(b) < eps) {
      assert(std::abs(c) >= eps);
      return {};
    }
    return {-c / b};
  }
  double d = b * b - 4 * a * c;
  if (d <= -eps) return {};
  if (d < eps) return {-0.5 * b / a};
  d = std::sqrt(d);
  const double x1 = -0.5 * (b >= 0 ? b + d : b - d) / a, x2 = c / (x1 * a);
  return x1 > x2 ? std::vector<double>{x2, x1} : std::vector<double>{x1, x2};
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_QUADRATIC_EQUATION_HPP_
