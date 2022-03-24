---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-6
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2276
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (\u7DDA\u5206\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2276
  bundledCode: "#line 1 \"test/geometry/geometry.07.test.cpp\"\n/*\r\n * @brief \u8A08\
    \u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u7DDA\u5206\u3068\u5186\
    \u306E\u4EA4\u5DEE\u5224\u5B9A)\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2276\"\
    \r\n#define ERROR \"1e-6\"\r\n\r\n#include <algorithm>\r\n#include <iomanip>\r\
    \n#include <iostream>\r\n#include <limits>\r\n#include <tuple>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\n#line 3 \"geometry/geometry.hpp\"\n#include <cassert>\r\
    \n#include <cmath>\r\n#include <functional>\r\n#line 7 \"geometry/geometry.hpp\"\
    \n#include <iterator>\r\n#line 11 \"geometry/geometry.hpp\"\n\r\nnamespace geometry\
    \ {\r\n\r\nusing Real = double;\r\nconstexpr long double PI = 3.14159265358979323846;\r\
    \n\r\nint sgn(const Real x) {\r\n  static constexpr Real EPS = 1e-8;\r\n  return\
    \ x > EPS ? 1 : (x < -EPS ? -1 : 0);\r\n}\r\n\r\nReal degree_to_radian(const Real\
    \ d) { return d * PI / 180; }\r\nReal radian_to_degree(const Real r) { return\
    \ r * 180 / PI; }\r\n\r\nstruct Point {\r\n  Real x, y;\r\n  explicit Point(const\
    \ Real x = 0, const Real y = 0) : x(x), y(y) {}\r\n  Real abs() const { return\
    \ std::sqrt(norm()); }\r\n  Real arg() const {\r\n    const Real res = std::atan2(y,\
    \ x);\r\n    return res < 0 ? res + PI * 2 : res;\r\n  }\r\n  Real norm() const\
    \ { return x * x + y * y; }\r\n  Point rotate(const Real angle) const {\r\n  \
    \  const Real cs = std::cos(angle), sn = std::sin(angle);\r\n    return Point(x\
    \ * cs - y * sn, x * sn + y * cs);\r\n  }\r\n  Point unit_vector() const {\r\n\
    \    const Real a = abs();\r\n    return Point(x / a, y / a);\r\n  }\r\n  std::pair<Point,\
    \ Point> normal_unit_vector() const {\r\n    const Point u = unit_vector();\r\n\
    \    return {Point(-u.y, u.x), Point(u.y, -u.x)};\r\n  }\r\n  Point& operator+=(const\
    \ Point& p) {\r\n    x += p.x; y += p.y;\r\n    return *this;\r\n  }\r\n  Point&\
    \ operator-=(const Point& p) {\r\n    x -= p.x; y -= p.y;\r\n    return *this;\r\
    \n  }\r\n  Point& operator*=(const Real k) {\r\n    x *= k; y *= k;\r\n    return\
    \ *this;\r\n  }\r\n  Point& operator/=(const Real k) {\r\n    x /= k; y /= k;\r\
    \n    return *this;\r\n  }\r\n  bool operator<(const Point& p) const {\r\n   \
    \ const int x_sgn = sgn(p.x - x);\r\n    return x_sgn != 0 ? x_sgn == 1 : sgn(p.y\
    \ - y) == 1;\r\n  }\r\n  bool operator<=(const Point& p) const { return !(p <\
    \ *this); }\r\n  bool operator>(const Point& p) const { return p < *this; }\r\n\
    \  bool operator>=(const Point& p) const { return !(*this < p); }\r\n  Point operator+()\
    \ const { return *this; }\r\n  Point operator-() const { return Point(-x, -y);\
    \ }\r\n  Point operator+(const Point& p) const { return Point(*this) += p; }\r\
    \n  Point operator-(const Point& p) const { return Point(*this) -= p; }\r\n  Point\
    \ operator*(const Real k) const { return Point(*this) *= k; }\r\n  Point operator/(const\
    \ Real k) const { return Point(*this) /= k; }\r\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const Point& p) {\r\n    return os << '(' << p.x << \", \" << p.y << ')';\r\
    \n  }\r\n  friend std::istream& operator>>(std::istream& is, Point& p) {\r\n \
    \   Real x, y; is >> x >> y;\r\n    p = Point(x, y);\r\n    return is;\r\n  }\r\
    \n};\r\n\r\nstruct Segment {\r\n  Point s, t;\r\n  explicit Segment(const Point&\
    \ s = Point(0, 0), const Point& t = Point(0, 0))\r\n      : s(s), t(t) {}\r\n\
    };\r\nstruct Line : Segment {\r\n  using Segment::Segment;\r\n  explicit Line(const\
    \ Real a, const Real b, const Real c) {\r\n    if (sgn(a) == 0) {\r\n      s =\
    \ Point(0, -c / b); t = Point(1, s.y);\r\n    } else if (sgn(b) == 0) {\r\n  \
    \    s = Point(-c / a, 0); t = Point(s.x, 1);\r\n    } else if (sgn(c) == 0) {\r\
    \n      s = Point(0, 0); t = Point(1, -a / b);\r\n    } else {\r\n      s = Point(0,\
    \ -c / b); t = Point(-c / a, 0);\r\n    }\r\n  }\r\n};\r\n\r\nstruct Circle {\r\
    \n  Point p; Real r;\r\n  explicit Circle(const Point& p = Point(0, 0), const\
    \ Real r = 0)\r\n      : p(p), r(r) {}\r\n};\r\n\r\nReal cross(const Point& a,\
    \ const Point& b) { return a.x * b.y - a.y * b.x; }\r\nReal dot(const Point& a,\
    \ const Point& b) { return a.x * b.x + a.y * b.y; }\r\n\r\nint ccw(const Point&\
    \ a, const Point& b, const Point& c) {\r\n  const Point ab = b - a, ac = c - a;\r\
    \n  const int sign = sgn(cross(ab, ac));\r\n  if (sign == 0) {\r\n    if (sgn(dot(ab,\
    \ ac)) == -1) return 2;\r\n    if (sgn(ac.norm() - ab.norm()) == 1) return -2;\r\
    \n  }\r\n  return sign;\r\n}\r\n\r\nReal get_angle(const Point& a, const Point&\
    \ b, const Point& c) {\r\n  Real ab = (a - b).arg(), bc = (c - b).arg();\r\n \
    \ if (ab > bc) std::swap(ab, bc);\r\n  return std::min(bc - ab, static_cast<Real>(PI\
    \ * 2 - (bc - ab)));\r\n}\r\n\r\nReal closest_pair(std::vector<Point> ps) {\r\n\
    \  const int n = ps.size();\r\n  assert(n >= 2);\r\n  std::sort(ps.begin(), ps.end());\r\
    \n  const std::function<Real(int, int)> f =\r\n      [&ps, &f](const int left,\
    \ const int right) -> Real {\r\n        const int mid = (left + right) >> 1;\r\
    \n        Real x_mid = ps[mid].x, d = std::numeric_limits<Real>::max();\r\n  \
    \      if (left + 1 < mid) d = std::min(d, f(left, mid));\r\n        if (mid +\
    \ 1 < right) d = std::min(d, f(mid, right));\r\n        std::inplace_merge(std::next(ps.begin(),\
    \ left),\r\n                           std::next(ps.begin(), mid),\r\n       \
    \                    std::next(ps.begin(), right),\r\n                       \
    \    [](const Point& a, const Point& b) -> bool {\r\n                        \
    \     return sgn(b.y - a.y) == 1;\r\n                           });\r\n      \
    \  std::vector<Point> tmp;\r\n        for (int i = left; i < right; ++i) {\r\n\
    \          if (sgn(std::abs(ps[i].x - x_mid) - d) == 1) continue;\r\n        \
    \  for (int j = static_cast<int>(tmp.size()) - 1; j >= 0; --j) {\r\n         \
    \   const Point v = ps[i] - tmp[j];\r\n            if (sgn(v.y - d) == 1) break;\r\
    \n            d = std::min(d, v.abs());\r\n          }\r\n          tmp.emplace_back(ps[i]);\r\
    \n        }\r\n        return d;\r\n      };\r\n  return f(0, n);\r\n}\r\n\r\n\
    Point projection(const Segment& a, const Point& b) {\r\n  return a.s + (a.t -\
    \ a.s) * dot(a.t - a.s, b - a.s) / (a.t - a.s).norm();\r\n}\r\nPoint reflection(const\
    \ Segment& a, const Point& b) {\r\n  return projection(a, b) * 2 - b;\r\n}\r\n\
    \r\nbool is_parallel(const Segment& a, const Segment& b) {\r\n  return sgn(cross(a.t\
    \ - a.s, b.t - b.s)) == 0;\r\n}\r\nbool is_orthogonal(const Segment& a, const\
    \ Segment& b) {\r\n  return sgn(dot(a.t - a.s, b.t - b.s)) == 0;\r\n}\r\n\r\n\
    Real distance(const Point&, const Point&);\r\nReal distance(const Segment&, const\
    \ Point&);\r\nReal distance(const Line&, const Point&);\r\nint common_tangent_num(const\
    \ Circle&, const Circle&);\r\nbool has_intersected(const Segment& a, const Point&\
    \ b) {\r\n  return ccw(a.s, a.t, b) == 0;\r\n}\r\nbool has_intersected(const Segment&\
    \ a, const Segment& b) {\r\n  return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <=\
    \ 0 &&\r\n         ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;\r\n}\r\nbool\
    \ has_intersected(const Line& a, const Point& b) {\r\n  const int c = ccw(a.s,\
    \ a.t, b);\r\n  return c != 1 && c != -1;\r\n}\r\nbool has_intersected(const Line&\
    \ a, const Segment& b) {\r\n  return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) !=\
    \ 1;\r\n}\r\nbool has_intersected(const Line& a, const Line& b) {\r\n  return\
    \ sgn(cross(a.t - a.s, b.t - b.s)) != 0 ||\r\n         sgn(cross(a.t - a.s, b.s\
    \ - a.s)) == 0;\r\n}\r\nbool has_intersected(const Circle& a, const Point& b)\
    \ {\r\n  return sgn(distance(a.p, b) - a.r) == 0;\r\n}\r\nbool has_intersected(const\
    \ Circle& a, const Segment& b) {\r\n  return sgn(a.r - distance(b, a.p)) != -1\
    \ &&\r\n         sgn(std::max(distance(a.p, b.s), distance(a.p, b.t)) - a.r) !=\
    \ -1;\r\n}\r\nbool has_intersected(const Circle& a, const Line& b) {\r\n  return\
    \ sgn(a.r - distance(b, a.p)) != -1;\r\n}\r\nbool has_intersected(const Circle&\
    \ a, const Circle& b) {\r\n  const int num = common_tangent_num(a, b);\r\n  return\
    \ 1 <= num && num <= 3;\r\n}\r\n\r\nPoint intersection(const Line& a, const Line&\
    \ b) {\r\n  assert(has_intersected(a, b) && !is_parallel(a, b));\r\n  const Point\
    \ va = a.t - a.s, vb = b.t - b.s;\r\n  return a.s + va * cross(vb, b.s - a.s)\
    \ / cross(vb, va);\r\n}\r\nPoint intersection(const Segment& a, const Segment&\
    \ b) {\r\n  assert(has_intersected(a, b));\r\n  if (is_parallel(a, b)) {\r\n \
    \   if (sgn(distance(a.s, b.s)) == 0) {\r\n      assert(sgn(dot(a.t - a.s, b.t\
    \ - a.s)) == -1);\r\n      return a.s;\r\n    } else if (sgn(distance(a.s, b.t))\
    \ == 0) {\r\n      assert(sgn(dot(a.t - a.s, b.s - a.s)) == -1);\r\n      return\
    \ a.s;\r\n    } else if (sgn(distance(a.t, b.s)) == 0) {\r\n      assert(sgn(dot(a.s\
    \ - a.t, b.t - a.t)) == -1);\r\n      return a.t;\r\n    } else if (sgn(distance(a.t,\
    \ b.t)) == 0) {\r\n      assert(sgn(dot(a.s - a.t, b.s - a.t)) == -1);\r\n   \
    \   return a.t;\r\n    } else {\r\n      assert(false);\r\n    }\r\n  } else {\r\
    \n    return intersection(Line(a.s, a.t), Line(b.s, b.t));\r\n  }\r\n}\r\nPoint\
    \ intersection(const Line& a, const Segment& b) {\r\n  assert(has_intersected(a,\
    \ b));\r\n  return intersection(a, Line(b.s, b.t));\r\n}\r\nstd::vector<Point>\
    \ intersection(const Circle& a, const Line& b) {\r\n  const Point pro = projection(b,\
    \ a.p);\r\n  const Real nor = (a.p - pro).norm();\r\n  const int sign = sgn(a.r\
    \ - std::sqrt(nor));\r\n  if (sign == -1) return {};\r\n  if (sign == 0) return\
    \ {pro};\r\n  const Point tmp = (b.t - b.s).unit_vector() * std::sqrt(a.r * a.r\
    \ - nor);\r\n  return {pro + tmp, pro - tmp};\r\n}\r\nstd::vector<Point> intersection(const\
    \ Circle& a, const Segment& b) {\r\n  if (!has_intersected(a, b)) return {};\r\
    \n  const std::vector<Point> res = intersection(a, Line(b.s, b.t));\r\n  if (sgn(distance(a.p,\
    \ b.s) - a.r) != -1 &&\r\n      sgn(distance(a.p, b.t) - a.r) != -1) {\r\n   \
    \ return res;\r\n  }\r\n  return {res[sgn(dot(res[0] - b.s, res[0] - b.t)) ==\
    \ 1 ? 1 : 0]};\r\n}\r\nstd::vector<Point> intersection(const Circle& a, const\
    \ Circle& b) {\r\n  const int num = common_tangent_num(a, b);\r\n  if (num ==\
    \ 0 || num == 4) return {};\r\n  const Real alpha = (b.p - a.p).arg();\r\n  if\
    \ (num == 1 || num == 3) {\r\n    return {Point(a.p.x + a.r * std::cos(alpha),\r\
    \n                  a.p.y + a.r * std::sin(alpha))};\r\n  }\r\n  const Real dist\
    \ = (b.p - a.p).norm();\r\n  const Real beta =\r\n      std::acos((dist + a.r\
    \ * a.r - b.r * b.r) / (2 * std::sqrt(dist) * a.r));\r\n  return {\r\n      a.p\
    \ + Point(a.r * std::cos(alpha + beta), a.r * std::sin(alpha + beta)),\r\n   \
    \   a.p + Point(a.r * std::cos(alpha - beta), a.r * std::sin(alpha - beta))};\r\
    \n}\r\n\r\nReal distance(const Point& a, const Point& b) { return (b - a).abs();\
    \ }\r\nReal distance(const Segment& a, const Point& b) {\r\n  const Point foot\
    \ = projection(a, b);\r\n  return has_intersected(a, foot) ?\r\n         distance(foot,\
    \ b) : std::min(distance(a.s, b), distance(a.t, b));\r\n}\r\nReal distance(const\
    \ Segment& a, const Segment& b) {\r\n  return has_intersected(a, b) ? 0 :\r\n\
    \         std::min({distance(a, b.s), distance(a, b.t),\r\n                  \
    \ distance(b, a.s), distance(b, a.t)});\r\n}\r\nReal distance(const Line& a, const\
    \ Point& b) {\r\n  return distance(projection(a, b), b);\r\n}\r\nReal distance(const\
    \ Line& a, const Segment& b) {\r\n  return has_intersected(a, b) ?\r\n       \
    \  0 : std::min(distance(a, b.s), distance(a, b.t));\r\n}\r\nReal distance(const\
    \ Line& a, const Line& b) {\r\n  return has_intersected(a, b) ? 0 : distance(a,\
    \ b.s);\r\n}\r\n\r\nstd::vector<Point> tangency(const Circle& a, const Point&\
    \ b) {\r\n  const Real dist = distance(a.p, b);\r\n  const int sign = sgn(dist\
    \ - a.r);\r\n  if (sign == -1) return {};\r\n  if (sign == 0) return {b};\r\n\
    \  const Real alpha = (b - a.p).arg(), beta = std::acos(a.r / dist);\r\n  return\
    \ {\r\n      a.p + Point(a.r * std::cos(alpha + beta), a.r * std::sin(alpha +\
    \ beta)),\r\n      a.p + Point(a.r * std::cos(alpha - beta), a.r * std::sin(alpha\
    \ - beta))};\r\n}\r\nint common_tangent_num(const Circle& a, const Circle& b)\
    \ {\r\n  const Real dist = distance(a.p, b.p);\r\n  int sign = sgn(a.r + b.r -\
    \ dist);\r\n  if (sign == -1) return 4;\r\n  if (sign == 0) return 3;\r\n  sign\
    \ = sgn((sgn(a.r - b.r) == -1 ? b.r - a.r : a.r - b.r) - dist);\r\n  if (sign\
    \ == -1) return 2;\r\n  if (sign == 0) return 1;\r\n  return 0;\r\n}\r\nstd::vector<Line>\
    \ common_tangent(const Circle& a, const Circle& b) {\r\n  std::vector<Line> tangents;\r\
    \n  const Real dist = distance(a.p, b.p), argument = (b.p - a.p).arg();\r\n  int\
    \ sign = sgn(a.r + b.r - dist);\r\n  if (sign == -1) {\r\n    const Real ac =\
    \ std::acos((a.r + b.r) / dist);\r\n    Real alpha = argument + ac, cs = std::cos(alpha),\
    \ sn = std::sin(alpha);\r\n    tangents.emplace_back(a.p + Point(a.r * cs, a.r\
    \ * sn),\r\n                          b.p + Point(-b.r * cs, -b.r * sn));\r\n\
    \    alpha = argument - ac; cs = std::cos(alpha); sn = std::sin(alpha);\r\n  \
    \  tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn),\r\n                \
    \          b.p + Point(-b.r * cs, -b.r * sn));\r\n  } else if (sign == 0) {\r\n\
    \    const Point s =\r\n        a.p + Point(a.r * std::cos(argument), a.r * std::sin(argument));\r\
    \n    tangents.emplace_back(s, s + (b.p - a.p).normal_unit_vector().first);\r\n\
    \  }\r\n  if (sgn(b.r - a.r) == -1) {\r\n    sign = sgn(a.r - b.r - dist);\r\n\
    \    if (sign == -1) {\r\n      const Real at = std::acos((a.r - b.r) / dist);\r\
    \n      Real alpha = argument + at, cs = std::cos(alpha), sn = std::sin(alpha);\r\
    \n      tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn),\r\n           \
    \                 b.p + Point(b.r * cs, b.r * sn));\r\n      alpha = argument\
    \ - at; cs = std::cos(alpha); sn = std::sin(alpha);\r\n      tangents.emplace_back(a.p\
    \ + Point(a.r * cs, a.r * sn),\r\n                            b.p + Point(b.r\
    \ * cs, b.r * sn));\r\n    } else if (sign == 0) {\r\n      const Point s =\r\n\
    \          a.p + Point(a.r * std::cos(argument), a.r * std::sin(argument));\r\n\
    \      tangents.emplace_back(s, s + (b.p - a.p).normal_unit_vector().first);\r\
    \n    }\r\n  } else {\r\n    sign = sgn(b.r - a.r - dist);\r\n    if (sign ==\
    \ -1) {\r\n      const Real at = std::acos((b.r - a.r) / dist);\r\n      Real\
    \ alpha = argument - at, cs = std::cos(alpha), sn = std::sin(alpha);\r\n     \
    \ tangents.emplace_back(a.p + Point(-a.r * cs, -a.r * sn),\r\n               \
    \             b.p + Point(-b.r * cs, -b.r * sn));\r\n      alpha = argument +\
    \ at; cs = std::cos(alpha); sn = std::sin(alpha);\r\n      tangents.emplace_back(a.p\
    \ + Point(-a.r * cs, -a.r * sn),\r\n                            b.p + Point(-b.r\
    \ * cs, -b.r * sn));\r\n    } else if (sign == 0) {\r\n      const Point s =\r\
    \n          b.p + Point(-b.r * std::cos(argument), -b.r * std::sin(argument));\r\
    \n      tangents.emplace_back(s, s + (a.p - b.p).normal_unit_vector().first);\r\
    \n    }\r\n  }\r\n  return tangents;\r\n}\r\n\r\nReal intersection_area(const\
    \ Circle& a, const Circle& b) {\r\n  const Real nor = (b.p - a.p).norm(), dist\
    \ = std::sqrt(nor);\r\n  if (sgn(a.r + b.r - dist) != 1) return 0;\r\n  if (sgn(std::abs(a.r\
    \ - b.r) - dist) != -1) {\r\n    return std::min(a.r, b.r) * std::min(a.r, b.r)\
    \ * PI;\r\n  }\r\n  const Real alpha =\r\n      std::acos((nor + a.r * a.r - b.r\
    \ * b.r) / (2 * dist * a.r));\r\n  const Real beta = std::acos((nor + b.r * b.r\
    \ - a.r * a.r) / (2 * dist * b.r));\r\n  return (alpha - std::sin(alpha + alpha)\
    \ * 0.5) * a.r * a.r +\r\n         (beta - std::sin(beta + beta) * 0.5) * b.r\
    \ * b.r;\r\n}\r\n\r\nusing Polygon = std::vector<Point>;\r\n\r\nReal area(Polygon\
    \ a) {\r\n  const int n = a.size();\r\n  a.resize(n + 1);\r\n  a.back() = a.front();\r\
    \n  Real res = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n    res += cross(a[i],\
    \ a[i + 1]);\r\n  }\r\n  return res * 0.5;\r\n}\r\n\r\nPoint centroid(Polygon\
    \ a) {\r\n  const int n = a.size();\r\n  a.resize(n + 1);\r\n  a.back() = a.front();\r\
    \n  Point res(0, 0);\r\n  Real den = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n\
    \    const Real cro = cross(a[i], a[i + 1]);\r\n    res += (a[i] + a[i + 1]) /\
    \ 3 * cro;\r\n    den += cro;\r\n  }\r\n  return res / den;\r\n}\r\n\r\nint contains(Polygon\
    \ a, const Point &b) {\r\n  const int n = a.size();\r\n  a.resize(n + 1);\r\n\
    \  a.back() = a.front();\r\n  bool is_in = false;\r\n  for (int i = 0; i < n;\
    \ ++i) {\r\n    Point p = a[i] - b, q = a[i + 1] - b;\r\n    if (sgn(q.y - p.y)\
    \ == -1) std::swap(p, q);\r\n    const int sign = sgn(cross(p, q));\r\n    if\
    \ (sign == 1 && sgn(p.y) != 1 && sgn(q.y) == 1) is_in = !is_in;\r\n    if (sign\
    \ == 0 && sgn(dot(p, q)) != 1) return 1;\r\n  }\r\n  return is_in ? 2 : 0;\r\n\
    }\r\n\r\nbool is_convex(Polygon a) {\r\n  const int n = a.size();\r\n  a.resize(n\
    \ + 2);\r\n  a[n] = a[0];\r\n  a[n + 1] = a[1];\r\n  for (int i = 1; i <= n; ++i)\
    \ {\r\n    if (ccw(a[i - 1], a[i], a[i + 1]) == -1) return false;\r\n  }\r\n \
    \ return true;\r\n}\r\n\r\nPolygon monotone_chain(std::vector<Point> ps, const\
    \ bool is_tight = true) {\r\n  const int n = ps.size();\r\n  std::sort(ps.begin(),\
    \ ps.end());\r\n  Polygon convex_hull(n << 1);\r\n  int idx = 0;\r\n  for (int\
    \ i = 0; i < n; convex_hull[idx++] = ps[i++]) {\r\n    while (idx >= 2 &&\r\n\
    \           sgn(cross(convex_hull[idx - 1] - convex_hull[idx - 2],\r\n       \
    \              ps[i] - convex_hull[idx - 1])) < is_tight) {\r\n      --idx;\r\n\
    \    }\r\n  }\r\n  for (int i = n - 2, border = idx + 1; i >= 0; convex_hull[idx++]\
    \ = ps[i--]) {\r\n    while (idx >= border &&\r\n           sgn(cross(convex_hull[idx\
    \ - 1] - convex_hull[idx - 2],\r\n                     ps[i] - convex_hull[idx\
    \ - 1])) < is_tight) {\r\n      --idx;\r\n    }\r\n  }\r\n  convex_hull.resize(idx\
    \ - 1);\r\n  return convex_hull;\r\n}\r\n\r\nPolygon cut_convex(Polygon a, const\
    \ Line& b) {\r\n  const int n = a.size();\r\n  a.resize(n + 1);\r\n  a.back()\
    \ = a.front();\r\n  Polygon res;\r\n  for (int i = 0; i < n; ++i) {\r\n    const\
    \ int c = ccw(b.s, b.t, a[i]);\r\n    if (c != -1) res.emplace_back(a[i]);\r\n\
    \    if (c * ccw(b.s, b.t, a[i + 1]) == -1) {\r\n      res.emplace_back(intersection(Line(a[i],\
    \ a[i + 1]), b));\r\n    }\r\n  }\r\n  return res.size() < 3 ? Polygon() : res;\r\
    \n}\r\n\r\nstd::pair<Point, Point> rotating_calipers(Polygon a) {\r\n  const int\
    \ n = a.size();\r\n  if (n <= 2) {\r\n    assert(n == 2);\r\n    return {a[0],\
    \ a[1]};\r\n  }\r\n  a.resize(n + 1);\r\n  a.back() = a.front();\r\n  int high\
    \ = 0, low = 0;\r\n  for (int i = 1; i < n; ++i) {\r\n    if (a[i].y > a[high].y)\
    \ high = i;\r\n    if (a[i].y < a[low].y) low = i;\r\n  }\r\n  Real max_norm =\
    \ (a[high] - a[low]).norm();\r\n  int i = high, j = low, argmax_i = i, argmax_j\
    \ = j;\r\n  do {\r\n    int* i_or_j = &(sgn(cross(a[i + 1] - a[i], a[j + 1] -\
    \ a[j])) != -1 ? j : i);\r\n    if (++(*i_or_j) == n) *i_or_j = 0;\r\n    const\
    \ Real tmp = (a[j] - a[i]).norm();\r\n    if (sgn(tmp - max_norm) == 1) {\r\n\
    \      max_norm = tmp;\r\n      argmax_i = i; argmax_j = j;\r\n    }\r\n  } while\
    \ (i != high || j != low);\r\n  return {a[argmax_i], a[argmax_j]};\r\n}\r\n\r\n\
    }  // namespace geometry\r\n\r\n// namespace geometry {\r\n\r\n// using Integer\
    \ = long long;\r\n\r\n// int sgn(const Integer x) {\r\n//   return x > 0 ? 1 :\
    \ (x < 0 ? -1 : 0);\r\n// }\r\n\r\n// struct Point {\r\n//   Integer x, y;\r\n\
    //   explicit Point(const Integer x = 0, const Integer y = 0) : x(x), y(y) {}\r\
    \n//   Integer norm() const { return x * x + y * y; }\r\n//   Point& operator+=(const\
    \ Point& p) {\r\n//     x += p.x; y += p.y;\r\n//     return *this;\r\n//   }\r\
    \n//   Point& operator-=(const Point& p) {\r\n//     x -= p.x; y -= p.y;\r\n//\
    \     return *this;\r\n//   }\r\n//   Point& operator*=(const Integer k) {\r\n\
    //     x *= k; y *= k;\r\n//     return *this;\r\n//   }\r\n//   Point& operator/=(const\
    \ Integer k) {\r\n//     x /= k; y /= k;\r\n//     return *this;\r\n//   }\r\n\
    //   bool operator<(const Point& p) const {\r\n//     const int x_sgn = sgn(p.x\
    \ - x);\r\n//     return x_sgn != 0 ? x_sgn == 1 : sgn(p.y - y) == 1;\r\n//  \
    \ }\r\n//   bool operator<=(const Point& p) const { return !(p < *this); }\r\n\
    //   bool operator>(const Point& p) const { return p < *this; }\r\n//   bool operator>=(const\
    \ Point& p) const { return !(*this < p); }\r\n//   Point operator+() const { return\
    \ *this; }\r\n//   Point operator-() const { return Point(-x, -y); }\r\n//   Point\
    \ operator+(const Point& p) const { return Point(*this) += p; }\r\n//   Point\
    \ operator-(const Point& p) const { return Point(*this) -= p; }\r\n//   Point\
    \ operator*(const Integer k) const { return Point(*this) *= k; }\r\n//   Point\
    \ operator/(const Integer k) const { return Point(*this) /= k; }\r\n//   friend\
    \ std::ostream& operator<<(std::ostream& os, const Point& p) {\r\n//     return\
    \ os << '(' << p.x << \", \" << p.y << ')';\r\n//   }\r\n//   friend std::istream&\
    \ operator>>(std::istream& is, Point& p) {\r\n//     Integer x, y; is >> x >>\
    \ y;\r\n//     p = Point(x, y);\r\n//     return is;\r\n//   }\r\n// };\r\n\r\n\
    // struct Segment {\r\n//   Point s, t;\r\n//   explicit Segment(const Point&\
    \ s = Point(0, 0), const Point& t = Point(0, 0))\r\n//       : s(s), t(t) {}\r\
    \n// };\r\n// struct Line : Segment {\r\n//   using Segment::Segment;\r\n// };\r\
    \n\r\n// struct Circle {\r\n//   Point p; Integer r;\r\n//   explicit Circle(const\
    \ Point& p = Point(0, 0), const Integer r = 0)\r\n//       : p(p), r(r) {}\r\n\
    // };\r\n\r\n// Integer cross(const Point& a, const Point& b) { return a.x * b.y\
    \ - a.y * b.x; }\r\n// Integer dot(const Point& a, const Point& b) { return a.x\
    \ * b.x + a.y * b.y; }\r\n\r\n// int ccw(const Point& a, const Point& b, const\
    \ Point& c) {\r\n//   const Point ab = b - a, ac = c - a;\r\n//   const int sign\
    \ = sgn(cross(ab, ac));\r\n//   if (sign == 0) {\r\n//     if (sgn(dot(ab, ac))\
    \ == -1) return 2;\r\n//     if (sgn(ac.norm() - ab.norm()) == 1) return -2;\r\
    \n//   }\r\n//   return sign;\r\n// }\r\n\r\n// Integer closest_pair(std::vector<Point>\
    \ ps) {\r\n//   const int n = ps.size();\r\n//   assert(n >= 2);\r\n//   std::sort(ps.begin(),\
    \ ps.end());\r\n//   const std::function<Integer(int, int)> f =\r\n//       [&ps,\
    \ &f](const int left, const int right) -> Integer {\r\n//         const int mid\
    \ = (left + right) >> 1;\r\n//         Integer x_mid = ps[mid].x, d = std::numeric_limits<Integer>::max();\r\
    \n//         if (left + 1 < mid) d = std::min(d, f(left, mid));\r\n//        \
    \ if (mid + 1 < right) d = std::min(d, f(mid, right));\r\n//         std::inplace_merge(std::next(ps.begin(),\
    \ left),\r\n//                            std::next(ps.begin(), mid),\r\n//  \
    \                          std::next(ps.begin(), right),\r\n//               \
    \             [](const Point& a, const Point& b) -> bool {\r\n//             \
    \                 return sgn(b.y - a.y) == 1;\r\n//                          \
    \  });\r\n//         std::vector<Point> tmp;\r\n//         for (int i = left;\
    \ i < right; ++i) {\r\n//           if (sgn((ps[i].x - x_mid) * (ps[i].x - x_mid)\
    \ - d) == 1) continue;\r\n//           for (int j = static_cast<int>(tmp.size())\
    \ - 1; j >= 0; --j) {\r\n//             const Point v = ps[i] - tmp[j];\r\n//\
    \             if (sgn(v.y * v.y - d) == 1) break;\r\n//             d = std::min(d,\
    \ v.norm());\r\n//           }\r\n//           tmp.emplace_back(ps[i]);\r\n//\
    \         }\r\n//         return d;\r\n//       };\r\n//   return f(0, n);\r\n\
    // }\r\n\r\n// bool is_parallel(const Segment& a, const Segment& b) {\r\n//  \
    \ return sgn(cross(a.t - a.s, b.t - b.s)) == 0;\r\n// }\r\n// bool is_orthogonal(const\
    \ Segment& a, const Segment& b) {\r\n//   return sgn(dot(a.t - a.s, b.t - b.s))\
    \ == 0;\r\n// }\r\n\r\n// int common_tangent_num(const Circle&, const Circle&);\r\
    \n// bool has_intersected(const Segment& a, const Point& b) {\r\n//   return ccw(a.s,\
    \ a.t, b) == 0;\r\n// }\r\n// bool has_intersected(const Segment& a, const Segment&\
    \ b) {\r\n//   return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 &&\r\n//  \
    \        ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;\r\n// }\r\n// bool has_intersected(const\
    \ Line& a, const Point& b) {\r\n//   const int c = ccw(a.s, a.t, b);\r\n//   return\
    \ c != 1 && c != -1;\r\n// }\r\n// bool has_intersected(const Line& a, const Segment&\
    \ b) {\r\n//   return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) != 1;\r\n// }\r\n\
    // bool has_intersected(const Line& a, const Line& b) {\r\n//   return sgn(cross(a.t\
    \ - a.s, b.t - b.s)) != 0 ||\r\n//          sgn(cross(a.t - a.s, b.s - a.s)) ==\
    \ 0;\r\n// }\r\n// bool has_intersected(const Circle& a, const Point& b) {\r\n\
    //   return (a.p - b).norm() == a.r * a.r;\r\n// }\r\n// bool has_intersected(const\
    \ Circle& a, const Circle& b) {\r\n//   const int num = common_tangent_num(a,\
    \ b);\r\n//   return 1 <= num && num <= 3;\r\n// }\r\n\r\n// int common_tangent_num(const\
    \ Circle& a, const Circle& b) {\r\n//   const Integer dist = (a.p - b.p).norm();\r\
    \n//   int sign = sgn((a.r + b.r) * (a.r + b.r) - dist);\r\n//   if (sign == -1)\
    \ return 4;\r\n//   if (sign == 0) return 3;\r\n//   sign = sgn((b.r - a.r) *\
    \ (b.r - a.r) - dist);\r\n//   if (sign == -1) return 2;\r\n//   if (sign == 0)\
    \ return 1;\r\n//   return 0;\r\n// }\r\n\r\n// using Polygon = std::vector<Point>;\r\
    \n\r\n// Integer area(Polygon a) {\r\n//   const int n = a.size();\r\n//   a.resize(n\
    \ + 1);\r\n//   a.back() = a.front();\r\n//   Integer res = 0;\r\n//   for (int\
    \ i = 0; i < n; ++i) {\r\n//     res += cross(a[i], a[i + 1]);\r\n//   }\r\n//\
    \   // return res / 2;\r\n//   return res;\r\n// }\r\n\r\n// int contains(Polygon\
    \ a, const Point &b) {\r\n//   const int n = a.size();\r\n//   a.resize(n + 1);\r\
    \n//   a.back() = a.front();\r\n//   bool is_in = false;\r\n//   for (int i =\
    \ 0; i < n; ++i) {\r\n//     Point p = a[i] - b, q = a[i + 1] - b;\r\n//     if\
    \ (sgn(q.y - p.y) == -1) std::swap(p, q);\r\n//     const int sign = sgn(cross(p,\
    \ q));\r\n//     if (sign == 1 && sgn(p.y) != 1 && sgn(q.y) == 1) is_in = !is_in;\r\
    \n//     if (sign == 0 && sgn(dot(p, q)) != 1) return 1;\r\n//   }\r\n//   return\
    \ is_in ? 2 : 0;\r\n// }\r\n\r\n// bool is_convex(Polygon a) {\r\n//   const int\
    \ n = a.size();\r\n//   a.resize(n + 2);\r\n//   a[n] = a[0];\r\n//   a[n + 1]\
    \ = a[1];\r\n//   for (int i = 1; i <= n; ++i) {\r\n//     if (ccw(a[i - 1], a[i],\
    \ a[i + 1]) == -1) return false;\r\n//   }\r\n//   return true;\r\n// }\r\n\r\n\
    // Polygon monotone_chain(std::vector<Point> ps, const bool is_tight = true) {\r\
    \n//   const int n = ps.size();\r\n//   std::sort(ps.begin(), ps.end());\r\n//\
    \   Polygon convex_hull(n << 1);\r\n//   int idx = 0;\r\n//   for (int i = 0;\
    \ i < n; convex_hull[idx++] = ps[i++]) {\r\n//     while (idx >= 2 &&\r\n//  \
    \          sgn(cross(convex_hull[idx - 1] - convex_hull[idx - 2],\r\n//      \
    \                ps[i] - convex_hull[idx - 1])) < is_tight) {\r\n//       --idx;\r\
    \n//     }\r\n//   }\r\n//   for (int i = n - 2, border = idx + 1; i >= 0; convex_hull[idx++]\
    \ = ps[i--]) {\r\n//     while (idx >= border &&\r\n//            sgn(cross(convex_hull[idx\
    \ - 1] - convex_hull[idx - 2],\r\n//                      ps[i] - convex_hull[idx\
    \ - 1])) < is_tight) {\r\n//       --idx;\r\n//     }\r\n//   }\r\n//   convex_hull.resize(idx\
    \ - 1);\r\n//   return convex_hull;\r\n// }\r\n\r\n// std::pair<Point, Point>\
    \ rotating_calipers(Polygon a) {\r\n//   const int n = a.size();\r\n//   if (n\
    \ <= 2) {\r\n//     assert(n == 2);\r\n//     return {a[0], a[1]};\r\n//   }\r\
    \n//   a.resize(n + 1);\r\n//   a.back() = a.front();\r\n//   int high = 0, low\
    \ = 0;\r\n//   for (int i = 1; i < n; ++i) {\r\n//     if (a[i].y > a[high].y)\
    \ high = i;\r\n//     if (a[i].y < a[low].y) low = i;\r\n//   }\r\n//   Integer\
    \ max_norm = (a[high] - a[low]).norm();\r\n//   int i = high, j = low, argmax_i\
    \ = i, argmax_j = j;\r\n//   do {\r\n//     int* i_or_j = &(sgn(cross(a[i + 1]\
    \ - a[i], a[j + 1] - a[j])) != -1 ? j : i);\r\n//     if (++(*i_or_j) == n) *i_or_j\
    \ = 0;\r\n//     const Integer tmp = (a[j] - a[i]).norm();\r\n//     if (sgn(tmp\
    \ - max_norm) == 1) {\r\n//       max_norm = tmp;\r\n//       argmax_i = i; argmax_j\
    \ = j;\r\n//     }\r\n//   } while (i != high || j != low);\r\n//   return {a[argmax_i],\
    \ a[argmax_j]};\r\n// }\r\n\r\n// }  // namespace geometry\r\n#line 16 \"test/geometry/geometry.07.test.cpp\"\
    \n\r\nint main() {\r\n  int n, k;\r\n  std::cin >> n >> k;\r\n  std::vector<geometry::Circle>\
    \ people(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    geometry::Point p;\r\n\
    \    double r;\r\n    std::cin >> p >> r;\r\n    people[i] = geometry::Circle(p,\
    \ r);\r\n  }\r\n  std::vector<double> l(n), r(n), comp;\r\n  for (int i = 0; i\
    \ < n; ++i) {\r\n    const std::vector<geometry::Point> t =\r\n        geometry::tangency(people[i],\
    \ geometry::Point(0, 0));\r\n    l[i] = t[0].arg();\r\n    r[i] = t[1].arg();\r\
    \n    if (l[i] > r[i]) std::swap(l[i], r[i]);\r\n    if (r[i] > geometry::PI &&\r\
    \n        geometry::has_intersected(\r\n            people[i],\r\n           \
    \ geometry::Segment(geometry::Point(0, 0),\r\n                              geometry::Point(2415,\
    \ 0)))) {\r\n      std::swap(l[i], r[i]);\r\n      l[i] = 0;\r\n    } else {\r\
    \n      if (l[i] < 0) l[i] = 0;\r\n      if (r[i] > geometry::PI) r[i] = geometry::PI;\r\
    \n    }\r\n    if (l[i] < geometry::PI) {\r\n      comp.emplace_back(l[i]);\r\n\
    \      comp.emplace_back(r[i]);\r\n    }\r\n  }\r\n  std::vector<bool> is_used(n,\
    \ true);\r\n  for (int i = 0; i < n; ++i) {\r\n    if (l[i] >= geometry::PI) is_used[i]\
    \ = false;\r\n    if (!is_used[i]) continue;\r\n    for (int j = 0; j < n; ++j)\
    \ {\r\n      if (j != i && l[i] <= l[j] && r[j] <= r[i]) is_used[j] = false;\r\
    \n    }\r\n  }\r\n  std::vector<std::pair<double, double>> balls;\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    if (is_used[i]) balls.emplace_back(l[i], r[i]);\r\
    \n  }\r\n  n = balls.size();\r\n  if (n == 0) {\r\n    std::cout << 0 << '\\n';\r\
    \n    return 0;\r\n  }\r\n  std::sort(balls.begin(), balls.end());\r\n  std::vector<std::vector<std::vector<double>>>\
    \ dp(n,\r\n      std::vector<std::vector<double>>(k + 1,\r\n          std::vector<double>(2,\
    \ std::numeric_limits<double>::lowest())));\r\n  dp[0][0][false] = 0;\r\n  dp[0][1][true]\
    \ = balls[0].second - balls[0].first;\r\n  for (int i = 1; i < n; ++i) {\r\n \
    \   double left, right;\r\n    std::tie(left, right) = balls[i];\r\n    int x\
    \ = i - 1;\r\n    while (x >= 0 && balls[i].first <= balls[x].second) --x;\r\n\
    \    ++x;\r\n    if (x > i - 1) x = i - 1;\r\n    for (int j = 0; j <= k; ++j)\
    \ {\r\n      if (j + 1 <= k) {\r\n        dp[i][j + 1][true] =\r\n           \
    \ std::max(dp[i][j + 1][true],\r\n                     dp[x][j][true] + right\
    \ - std::max(balls[x].second, left));\r\n        dp[i][j + 1][true] =\r\n    \
    \        std::max(dp[i][j + 1][true], dp[x][j][false] + right - left);\r\n   \
    \   }\r\n      dp[i][j][false] =\r\n          std::max(dp[i][j][false],\r\n  \
    \                 std::max(dp[i - 1][j][false], dp[i - 1][j][true]));\r\n    }\r\
    \n  }\r\n  double ans = 0;\r\n  for (int y = 0; y <= k; ++y) {\r\n    for (int\
    \ z = 0; z < 2; ++z) {\r\n      if (dp[n - 1][y][z] > ans) ans = dp[n - 1][y][z];\r\
    \n    }\r\n  }\r\n  std::cout << std::fixed << std::setprecision(7) << ans / geometry::PI\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
    \ (\u7DDA\u5206\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A)\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2276\"\r\n#define\
    \ ERROR \"1e-6\"\r\n\r\n#include <algorithm>\r\n#include <iomanip>\r\n#include\
    \ <iostream>\r\n#include <limits>\r\n#include <tuple>\r\n#include <utility>\r\n\
    #include <vector>\r\n\r\n#include \"../../geometry/geometry.hpp\"\r\n\r\nint main()\
    \ {\r\n  int n, k;\r\n  std::cin >> n >> k;\r\n  std::vector<geometry::Circle>\
    \ people(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    geometry::Point p;\r\n\
    \    double r;\r\n    std::cin >> p >> r;\r\n    people[i] = geometry::Circle(p,\
    \ r);\r\n  }\r\n  std::vector<double> l(n), r(n), comp;\r\n  for (int i = 0; i\
    \ < n; ++i) {\r\n    const std::vector<geometry::Point> t =\r\n        geometry::tangency(people[i],\
    \ geometry::Point(0, 0));\r\n    l[i] = t[0].arg();\r\n    r[i] = t[1].arg();\r\
    \n    if (l[i] > r[i]) std::swap(l[i], r[i]);\r\n    if (r[i] > geometry::PI &&\r\
    \n        geometry::has_intersected(\r\n            people[i],\r\n           \
    \ geometry::Segment(geometry::Point(0, 0),\r\n                              geometry::Point(2415,\
    \ 0)))) {\r\n      std::swap(l[i], r[i]);\r\n      l[i] = 0;\r\n    } else {\r\
    \n      if (l[i] < 0) l[i] = 0;\r\n      if (r[i] > geometry::PI) r[i] = geometry::PI;\r\
    \n    }\r\n    if (l[i] < geometry::PI) {\r\n      comp.emplace_back(l[i]);\r\n\
    \      comp.emplace_back(r[i]);\r\n    }\r\n  }\r\n  std::vector<bool> is_used(n,\
    \ true);\r\n  for (int i = 0; i < n; ++i) {\r\n    if (l[i] >= geometry::PI) is_used[i]\
    \ = false;\r\n    if (!is_used[i]) continue;\r\n    for (int j = 0; j < n; ++j)\
    \ {\r\n      if (j != i && l[i] <= l[j] && r[j] <= r[i]) is_used[j] = false;\r\
    \n    }\r\n  }\r\n  std::vector<std::pair<double, double>> balls;\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    if (is_used[i]) balls.emplace_back(l[i], r[i]);\r\
    \n  }\r\n  n = balls.size();\r\n  if (n == 0) {\r\n    std::cout << 0 << '\\n';\r\
    \n    return 0;\r\n  }\r\n  std::sort(balls.begin(), balls.end());\r\n  std::vector<std::vector<std::vector<double>>>\
    \ dp(n,\r\n      std::vector<std::vector<double>>(k + 1,\r\n          std::vector<double>(2,\
    \ std::numeric_limits<double>::lowest())));\r\n  dp[0][0][false] = 0;\r\n  dp[0][1][true]\
    \ = balls[0].second - balls[0].first;\r\n  for (int i = 1; i < n; ++i) {\r\n \
    \   double left, right;\r\n    std::tie(left, right) = balls[i];\r\n    int x\
    \ = i - 1;\r\n    while (x >= 0 && balls[i].first <= balls[x].second) --x;\r\n\
    \    ++x;\r\n    if (x > i - 1) x = i - 1;\r\n    for (int j = 0; j <= k; ++j)\
    \ {\r\n      if (j + 1 <= k) {\r\n        dp[i][j + 1][true] =\r\n           \
    \ std::max(dp[i][j + 1][true],\r\n                     dp[x][j][true] + right\
    \ - std::max(balls[x].second, left));\r\n        dp[i][j + 1][true] =\r\n    \
    \        std::max(dp[i][j + 1][true], dp[x][j][false] + right - left);\r\n   \
    \   }\r\n      dp[i][j][false] =\r\n          std::max(dp[i][j][false],\r\n  \
    \                 std::max(dp[i - 1][j][false], dp[i - 1][j][true]));\r\n    }\r\
    \n  }\r\n  double ans = 0;\r\n  for (int y = 0; y <= k; ++y) {\r\n    for (int\
    \ z = 0; z < 2; ++z) {\r\n      if (dp[n - 1][y][z] > ans) ans = dp[n - 1][y][z];\r\
    \n    }\r\n  }\r\n  std::cout << std::fixed << std::setprecision(7) << ans / geometry::PI\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.07.test.cpp
  requiredBy: []
  timestamp: '2022-03-25 02:44:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.07.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.07.test.cpp
- /verify/test/geometry/geometry.07.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u7DDA\u5206\
  \u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A)"
---
