#ifndef EMTHRM_GEOMETRY_GEOMETRY_HPP_
#define EMTHRM_GEOMETRY_GEOMETRY_HPP_

#include <algorithm>
#include <cassert>
#include <cmath>
#include <compare>
#include <iostream>
#include <iterator>
#include <limits>
#include <numbers>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>

namespace emthrm {

namespace geometry {

using Real = double;

int sgn(const Real x) {
  static constexpr Real EPS = 1e-8;
  return x > EPS ? 1 : (x < -EPS ? -1 : 0);
}

Real degree_to_radian(const Real d) { return d * std::numbers::pi / 180; }
Real radian_to_degree(const Real r) { return r * 180 / std::numbers::pi; }

struct Point {
  Real x, y;

  explicit Point(const Real x = 0, const Real y = 0) : x(x), y(y) {}

  Real abs() const { return std::sqrt(norm()); }

  Real arg() const {
    const Real res = std::atan2(y, x);
    return res < 0 ? res + std::numbers::pi * 2 : res;
  }

  Real norm() const { return x * x + y * y; }

  Point rotate(const Real angle) const {
    const Real cs = std::cos(angle), sn = std::sin(angle);
    return Point(x * cs - y * sn, x * sn + y * cs);
  }

  Point& operator+=(const Point& p) {
    x += p.x; y += p.y;
    return *this;
  }
  Point& operator-=(const Point& p) {
    x -= p.x; y -= p.y;
    return *this;
  }
  Point& operator*=(const Real k) {
    x *= k; y *= k;
    return *this;
  }
  Point& operator/=(const Real k) {
    x /= k; y /= k;
    return *this;
  }

  std::partial_ordering operator<=>(const Point& p) const {
    const int x_sgn = sgn(p.x - x);
    if (x_sgn == 0) return 0 <=> sgn(p.y - y);
    return x_sgn == 1 ? std::partial_ordering::less :
                        std::partial_ordering::greater;
  }

  Point operator+() const { return *this; }
  Point operator-() const { return Point(-x, -y); }

  Point operator+(const Point& p) const { return Point(*this) += p; }
  Point operator-(const Point& p) const { return Point(*this) -= p; }
  Point operator*(const Real k) const { return Point(*this) *= k; }
  Point operator/(const Real k) const { return Point(*this) /= k; }

  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << '(' << p.x << ", " << p.y << ')';
  }
  friend std::istream& operator>>(std::istream& is, Point& p) {
    Real x, y; is >> x >> y;
    p = Point(x, y);
    return is;
  }
};

struct Segment {
  Point s, t;
  explicit Segment(const Point& s = Point(0, 0), const Point& t = Point(0, 0))
      : s(s), t(t) {}
};
struct Line : Segment {
  using Segment::Segment;
  explicit Line(const Real a, const Real b, const Real c) {
    if (sgn(a) == 0) {
      s = Point(0, -c / b); t = Point(1, s.y);
    } else if (sgn(b) == 0) {
      s = Point(-c / a, 0); t = Point(s.x, 1);
    } else if (sgn(c) == 0) {
      s = Point(0, 0); t = Point(1, -a / b);
    } else {
      s = Point(0, -c / b); t = Point(-c / a, 0);
    }
  }
};

struct Circle {
  Point p; Real r;
  explicit Circle(const Point& p = Point(0, 0), const Real r = 0)
      : p(p), r(r) {}
};

Point unit_vector(const Point& p) {
  const Real a = p.abs();
  return Point(p.x / a, p.y / a);
}
std::tuple<Point, Point> normal_unit_vector(const Point& p) {
  const Point u = unit_vector(p);
  return {Point(-u.y, u.x), Point(u.y, -u.x)};
}

Real cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
Real dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }

int ccw(const Point& a, const Point& b, const Point& c) {
  const Point ab = b - a, ac = c - a;
  const int sign = sgn(cross(ab, ac));
  if (sign == 0) {
    if (sgn(dot(ab, ac)) == -1) return 2;
    if (sgn(ac.norm() - ab.norm()) == 1) return -2;
  }
  return sign;
}

Real get_angle(const Point& a, const Point& b, const Point& c) {
  Real ab = (a - b).arg(), bc = (c - b).arg();
  if (ab > bc) std::swap(ab, bc);
  return std::min(bc - ab, static_cast<Real>(std::numbers::pi * 2 - (bc - ab)));
}

Real closest_pair(std::vector<Point> ps) {
  const int n = ps.size();
  assert(n >= 2);
  std::sort(ps.begin(), ps.end());
  const auto f = [&ps](auto f, const int left, const int right) -> Real {
    const int mid = std::midpoint(left, right);
    Real x_mid = ps[mid].x, d = std::numeric_limits<Real>::max();
    if (left + 1 < mid) d = std::min(d, f(f, left, mid));
    if (mid + 1 < right) d = std::min(d, f(f, mid, right));
    std::inplace_merge(std::next(ps.begin(), left), std::next(ps.begin(), mid),
                       std::next(ps.begin(), right),
                       [](const Point& a, const Point& b) -> bool {
                         return sgn(b.y - a.y) == 1;
                       });
    std::vector<Point> tmp;
    for (int i = left; i < right; ++i) {
      if (sgn(std::abs(ps[i].x - x_mid) - d) == 1) continue;
      for (int j = std::ssize(tmp) - 1; j >= 0; --j) {
        const Point v = ps[i] - tmp[j];
        if (sgn(v.y - d) == 1) break;
        d = std::min(d, v.abs());
      }
      tmp.emplace_back(ps[i]);
    }
    return d;
  };
  return f(f, 0, n);
}

Point projection(const Segment& a, const Point& b) {
  return a.s + (a.t - a.s) * dot(a.t - a.s, b - a.s) / (a.t - a.s).norm();
}
Point reflection(const Segment& a, const Point& b) {
  return projection(a, b) * 2 - b;
}

bool is_parallel(const Segment& a, const Segment& b) {
  return sgn(cross(a.t - a.s, b.t - b.s)) == 0;
}
bool is_orthogonal(const Segment& a, const Segment& b) {
  return sgn(dot(a.t - a.s, b.t - b.s)) == 0;
}

Real distance(const Point&, const Point&);
Real distance(const Segment&, const Point&);
Real distance(const Line&, const Point&);
int common_tangent_num(const Circle&, const Circle&);
bool has_intersected(const Segment& a, const Point& b) {
  return ccw(a.s, a.t, b) == 0;
}
bool has_intersected(const Segment& a, const Segment& b) {
  return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 &&
         ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;
}
bool has_intersected(const Line& a, const Point& b) {
  const int c = ccw(a.s, a.t, b);
  return c != 1 && c != -1;
}
bool has_intersected(const Line& a, const Segment& b) {
  return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) != 1;
}
bool has_intersected(const Line& a, const Line& b) {
  return sgn(cross(a.t - a.s, b.t - b.s)) != 0 ||
         sgn(cross(a.t - a.s, b.s - a.s)) == 0;
}
bool has_intersected(const Circle& a, const Point& b) {
  return sgn(distance(a.p, b) - a.r) == 0;
}
bool has_intersected(const Circle& a, const Segment& b) {
  return sgn(a.r - distance(b, a.p)) != -1 &&
         sgn(std::max(distance(a.p, b.s), distance(a.p, b.t)) - a.r) != -1;
}
bool has_intersected(const Circle& a, const Line& b) {
  return sgn(a.r - distance(b, a.p)) != -1;
}
bool has_intersected(const Circle& a, const Circle& b) {
  const int num = common_tangent_num(a, b);
  return 1 <= num && num <= 3;
}

Point intersection(const Line& a, const Line& b) {
  assert(has_intersected(a, b) && !is_parallel(a, b));
  const Point va = a.t - a.s, vb = b.t - b.s;
  return a.s + va * cross(vb, b.s - a.s) / cross(vb, va);
}
Point intersection(const Segment& a, const Segment& b) {
  assert(has_intersected(a, b));
  if (is_parallel(a, b)) {
    if (sgn(distance(a.s, b.s)) == 0) {
      assert(sgn(dot(a.t - a.s, b.t - a.s)) == -1);
      return a.s;
    } else if (sgn(distance(a.s, b.t)) == 0) {
      assert(sgn(dot(a.t - a.s, b.s - a.s)) == -1);
      return a.s;
    } else if (sgn(distance(a.t, b.s)) == 0) {
      assert(sgn(dot(a.s - a.t, b.t - a.t)) == -1);
      return a.t;
    } else if (sgn(distance(a.t, b.t)) == 0) {
      assert(sgn(dot(a.s - a.t, b.s - a.t)) == -1);
      return a.t;
    } else {
      assert(false);
    }
  } else {
    return intersection(Line(a.s, a.t), Line(b.s, b.t));
  }
}
Point intersection(const Line& a, const Segment& b) {
  assert(has_intersected(a, b));
  return intersection(a, Line(b.s, b.t));
}
std::vector<Point> intersection(const Circle& a, const Line& b) {
  const Point pro = projection(b, a.p);
  const Real nor = (a.p - pro).norm();
  const int sign = sgn(a.r - std::sqrt(nor));
  if (sign == -1) return {};
  if (sign == 0) return {pro};
  const Point tmp = unit_vector(b.t - b.s) * std::sqrt(a.r * a.r - nor);
  return {pro + tmp, pro - tmp};
}
std::vector<Point> intersection(const Circle& a, const Segment& b) {
  if (!has_intersected(a, b)) return {};
  const std::vector<Point> res = intersection(a, Line(b.s, b.t));
  if (sgn(distance(a.p, b.s) - a.r) != -1 &&
      sgn(distance(a.p, b.t) - a.r) != -1) {
    return res;
  }
  return {res[sgn(dot(res[0] - b.s, res[0] - b.t)) == 1 ? 1 : 0]};
}
std::vector<Point> intersection(const Circle& a, const Circle& b) {
  const int num = common_tangent_num(a, b);
  if (num == 0 || num == 4) return {};
  const Real alpha = (b.p - a.p).arg();
  if (num == 1 || num == 3) {
    return {Point(a.p.x + a.r * std::cos(alpha),
                  a.p.y + a.r * std::sin(alpha))};
  }
  const Real dist = (b.p - a.p).norm();
  const Real beta =
      std::acos((dist + a.r * a.r - b.r * b.r) / (2 * std::sqrt(dist) * a.r));
  return {
      a.p + Point(a.r * std::cos(alpha + beta), a.r * std::sin(alpha + beta)),
      a.p + Point(a.r * std::cos(alpha - beta), a.r * std::sin(alpha - beta))};
}

Real distance(const Point& a, const Point& b) { return (b - a).abs(); }
Real distance(const Segment& a, const Point& b) {
  const Point foot = projection(a, b);
  return has_intersected(a, foot) ?
         distance(foot, b) : std::min(distance(a.s, b), distance(a.t, b));
}
Real distance(const Segment& a, const Segment& b) {
  return has_intersected(a, b) ? 0 :
         std::min({distance(a, b.s), distance(a, b.t),
                   distance(b, a.s), distance(b, a.t)});
}
Real distance(const Line& a, const Point& b) {
  return distance(projection(a, b), b);
}
Real distance(const Line& a, const Segment& b) {
  return has_intersected(a, b) ?
         0 : std::min(distance(a, b.s), distance(a, b.t));
}
Real distance(const Line& a, const Line& b) {
  return has_intersected(a, b) ? 0 : distance(a, b.s);
}

std::vector<Point> tangency(const Circle& a, const Point& b) {
  const Real dist = distance(a.p, b);
  const int sign = sgn(dist - a.r);
  if (sign == -1) return {};
  if (sign == 0) return {b};
  const Real alpha = (b - a.p).arg(), beta = std::acos(a.r / dist);
  return {
      a.p + Point(a.r * std::cos(alpha + beta), a.r * std::sin(alpha + beta)),
      a.p + Point(a.r * std::cos(alpha - beta), a.r * std::sin(alpha - beta))};
}
int common_tangent_num(const Circle& a, const Circle& b) {
  const Real dist = distance(a.p, b.p);
  int sign = sgn(a.r + b.r - dist);
  if (sign == -1) return 4;
  if (sign == 0) return 3;
  sign = sgn((sgn(a.r - b.r) == -1 ? b.r - a.r : a.r - b.r) - dist);
  if (sign == -1) return 2;
  if (sign == 0) return 1;
  return 0;
}
std::vector<Line> common_tangent(const Circle& a, const Circle& b) {
  std::vector<Line> tangents;
  const Real dist = distance(a.p, b.p), argument = (b.p - a.p).arg();
  int sign = sgn(a.r + b.r - dist);
  if (sign == -1) {
    const Real ac = std::acos((a.r + b.r) / dist);
    Real alpha = argument + ac, cs = std::cos(alpha), sn = std::sin(alpha);
    tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn),
                          b.p + Point(-b.r * cs, -b.r * sn));
    alpha = argument - ac; cs = std::cos(alpha); sn = std::sin(alpha);
    tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn),
                          b.p + Point(-b.r * cs, -b.r * sn));
  } else if (sign == 0) {
    const Point s =
        a.p + Point(a.r * std::cos(argument), a.r * std::sin(argument));
    tangents.emplace_back(s, s + std::get<0>(normal_unit_vector(b.p - a.p)));
  }
  if (sgn(b.r - a.r) == -1) {
    sign = sgn(a.r - b.r - dist);
    if (sign == -1) {
      const Real at = std::acos((a.r - b.r) / dist);
      Real alpha = argument + at, cs = std::cos(alpha), sn = std::sin(alpha);
      tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn),
                            b.p + Point(b.r * cs, b.r * sn));
      alpha = argument - at; cs = std::cos(alpha); sn = std::sin(alpha);
      tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn),
                            b.p + Point(b.r * cs, b.r * sn));
    } else if (sign == 0) {
      const Point s =
          a.p + Point(a.r * std::cos(argument), a.r * std::sin(argument));
      tangents.emplace_back(s, s + std::get<0>(normal_unit_vector(b.p - a.p)));
    }
  } else {
    sign = sgn(b.r - a.r - dist);
    if (sign == -1) {
      const Real at = std::acos((b.r - a.r) / dist);
      Real alpha = argument - at, cs = std::cos(alpha), sn = std::sin(alpha);
      tangents.emplace_back(a.p + Point(-a.r * cs, -a.r * sn),
                            b.p + Point(-b.r * cs, -b.r * sn));
      alpha = argument + at; cs = std::cos(alpha); sn = std::sin(alpha);
      tangents.emplace_back(a.p + Point(-a.r * cs, -a.r * sn),
                            b.p + Point(-b.r * cs, -b.r * sn));
    } else if (sign == 0) {
      const Point s =
          b.p + Point(-b.r * std::cos(argument), -b.r * std::sin(argument));
      tangents.emplace_back(s, s + std::get<0>(normal_unit_vector(a.p - b.p)));
    }
  }
  return tangents;
}

Real intersection_area(const Circle& a, const Circle& b) {
  const Real nor = (b.p - a.p).norm(), dist = std::sqrt(nor);
  if (sgn(a.r + b.r - dist) != 1) return 0;
  if (sgn(std::abs(a.r - b.r) - dist) != -1) {
    return std::min(a.r, b.r) * std::min(a.r, b.r) * std::numbers::pi;
  }
  const Real alpha =
      std::acos((nor + a.r * a.r - b.r * b.r) / (2 * dist * a.r));
  const Real beta = std::acos((nor + b.r * b.r - a.r * a.r) / (2 * dist * b.r));
  return (alpha - std::sin(alpha + alpha) * 0.5) * a.r * a.r +
         (beta - std::sin(beta + beta) * 0.5) * b.r * b.r;
}

using Polygon = std::vector<Point>;

Real area(Polygon a) {
  const int n = a.size();
  a.resize(n + 1);
  a.back() = a.front();
  Real res = 0;
  for (int i = 0; i < n; ++i) {
    res += cross(a[i], a[i + 1]);
  }
  return res * 0.5;
}

Point centroid(Polygon a) {
  const int n = a.size();
  a.resize(n + 1);
  a.back() = a.front();
  Point res(0, 0);
  Real den = 0;
  for (int i = 0; i < n; ++i) {
    const Real cro = cross(a[i], a[i + 1]);
    res += (a[i] + a[i + 1]) / 3 * cro;
    den += cro;
  }
  return res / den;
}

int contains(Polygon a, const Point &b) {
  const int n = a.size();
  a.resize(n + 1);
  a.back() = a.front();
  bool is_in = false;
  for (int i = 0; i < n; ++i) {
    Point p = a[i] - b, q = a[i + 1] - b;
    if (sgn(q.y - p.y) == -1) std::swap(p, q);
    const int sign = sgn(cross(p, q));
    if (sign == 1 && sgn(p.y) != 1 && sgn(q.y) == 1) is_in = !is_in;
    if (sign == 0 && sgn(dot(p, q)) != 1) return 1;
  }
  return is_in ? 2 : 0;
}

bool is_convex(Polygon a) {
  const int n = a.size();
  a.resize(n + 2);
  a[n] = a[0];
  a[n + 1] = a[1];
  for (int i = 1; i <= n; ++i) {
    if (ccw(a[i - 1], a[i], a[i + 1]) == -1) return false;
  }
  return true;
}

Polygon monotone_chain(std::vector<Point> ps, const bool is_tight = true) {
  const int n = ps.size();
  std::sort(ps.begin(), ps.end());
  Polygon convex_hull(n << 1);
  int idx = 0;
  for (int i = 0; i < n; convex_hull[idx++] = ps[i++]) {
    while (idx >= 2 &&
           sgn(cross(convex_hull[idx - 1] - convex_hull[idx - 2],
                     ps[i] - convex_hull[idx - 1])) < is_tight) {
      --idx;
    }
  }
  for (int i = n - 2, border = idx + 1; i >= 0; convex_hull[idx++] = ps[i--]) {
    while (idx >= border &&
           sgn(cross(convex_hull[idx - 1] - convex_hull[idx - 2],
                     ps[i] - convex_hull[idx - 1])) < is_tight) {
      --idx;
    }
  }
  convex_hull.resize(idx - 1);
  return convex_hull;
}

Polygon cut_convex(Polygon a, const Line& b) {
  const int n = a.size();
  a.resize(n + 1);
  a.back() = a.front();
  Polygon res;
  for (int i = 0; i < n; ++i) {
    const int c = ccw(b.s, b.t, a[i]);
    if (c != -1) res.emplace_back(a[i]);
    if (c * ccw(b.s, b.t, a[i + 1]) == -1) {
      res.emplace_back(intersection(Line(a[i], a[i + 1]), b));
    }
  }
  return res.size() < 3 ? Polygon() : res;
}

std::tuple<Point, Point> rotating_calipers(Polygon a) {
  const int n = a.size();
  if (n <= 2) {
    assert(n == 2);
    return {a[0], a[1]};
  }
  a.resize(n + 1);
  a.back() = a.front();
  int high = 0, low = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i].y > a[high].y) high = i;
    if (a[i].y < a[low].y) low = i;
  }
  Real max_norm = (a[high] - a[low]).norm();
  int i = high, j = low, argmax_i = i, argmax_j = j;
  do {
    int* i_or_j = &(sgn(cross(a[i + 1] - a[i], a[j + 1] - a[j])) != -1 ? j : i);
    if (++(*i_or_j) == n) *i_or_j = 0;
    const Real tmp = (a[j] - a[i]).norm();
    if (sgn(tmp - max_norm) == 1) {
      max_norm = tmp;
      argmax_i = i; argmax_j = j;
    }
  } while (i != high || j != low);
  return {a[argmax_i], a[argmax_j]};
}

}  // namespace geometry

}  // namespace emthrm

#endif  // EMTHRM_GEOMETRY_GEOMETRY_HPP_
