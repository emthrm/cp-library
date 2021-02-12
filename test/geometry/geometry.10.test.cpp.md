---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/geometry.hpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2316
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (\u7DDA\u5206\u3068\u5186\u306E\u4EA4\u70B9)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2316
  bundledCode: "#line 1 \"test/geometry/geometry.10.test.cpp\"\n/*\r\n * @brief \u8A08\
    \u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u7DDA\u5206\u3068\u5186\
    \u306E\u4EA4\u70B9)\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2316\"\
    \r\n\r\n#include <algorithm>\r\n#include <cmath>\r\n#include <iostream>\r\n#include\
    \ <string>\r\n#include <vector>\r\n#line 3 \"geometry/geometry.hpp\"\n#include\
    \ <cassert>\r\n#line 5 \"geometry/geometry.hpp\"\n#include <functional>\r\n#line\
    \ 7 \"geometry/geometry.hpp\"\n#include <limits>\r\n#include <utility>\r\n#line\
    \ 10 \"geometry/geometry.hpp\"\n\r\nnamespace geometry {\r\nusing Real = double;\r\
    \nconstexpr long double PI = 3.14159265358979323846;\r\n\r\nint sgn(Real x) {\r\
    \n  static constexpr Real EPS = 1e-8;\r\n  return x > EPS ? 1 : x < -EPS ? -1\
    \ : 0;\r\n}\r\n\r\nReal degree_to_radian(Real d) { return d * PI / 180; }\r\n\
    Real radian_to_degree(Real r) { return r * 180 / PI; }\r\n\r\nstruct Point {\r\
    \n  Real x, y;\r\n  Point(Real x = 0, Real y = 0) : x(x), y(y) {}\r\n  Real abs()\
    \ const { return std::sqrt(norm()); }\r\n  Real arg() const { Real res = std::atan2(y,\
    \ x); return res < 0 ? res + PI * 2 : res; }\r\n  Real norm() const { return x\
    \ * x + y * y; }\r\n  Point rotate(Real angle) const { Real cs = std::cos(angle),\
    \ sn = std::sin(angle); return Point(x * cs - y * sn, x * sn + y * cs); }\r\n\
    \  Point unit_vector() const { Real a = abs(); return Point(x / a, y / a); }\r\
    \n  std::pair<Point, Point> normal_unit_vector() const { Point p = unit_vector();\
    \ return {Point(-p.y, p.x), Point(p.y, -p.x)}; }\r\n  Point &operator+=(const\
    \ Point &p) { x += p.x; y += p.y; return *this; }\r\n  Point &operator-=(const\
    \ Point &p) { x -= p.x; y -= p.y; return *this; }\r\n  Point &operator*=(Real\
    \ k) { x *= k; y *= k; return *this; }\r\n  Point &operator/=(Real k) { x /= k;\
    \ y /= k; return *this; }\r\n  bool operator<(const Point &p) const { int x_sgn\
    \ = sgn(p.x - x); return x_sgn != 0 ? x_sgn == 1 : sgn(p.y - y) == 1; }\r\n  bool\
    \ operator<=(const Point &p) const { return !(p < *this); }\r\n  bool operator>(const\
    \ Point &p) const { return p < *this; }\r\n  bool operator>=(const Point &p) const\
    \ { return !(*this < p); }\r\n  Point operator+() const { return *this; }\r\n\
    \  Point operator-() const { return Point(-x, -y); }\r\n  Point operator+(const\
    \ Point &p) const { return Point(*this) += p; }\r\n  Point operator-(const Point\
    \ &p) const { return Point(*this) -= p; }\r\n  Point operator*(Real k) const {\
    \ return Point(*this) *= k; }\r\n  Point operator/(Real k) const { return Point(*this)\
    \ /= k; }\r\n  friend std::ostream &operator<<(std::ostream &os, const Point &p)\
    \ { return os << '(' << p.x << \", \" << p.y << ')'; }\r\n  friend std::istream\
    \ &operator>>(std::istream &is, Point &p) { Real x, y; is >> x >> y; p = Point(x,\
    \ y); return is; }\r\n};\r\n\r\nstruct Segment {\r\n  Point s, t;\r\n  Segment(const\
    \ Point &s = {0, 0}, const Point &t = {0, 0}) : s(s), t(t) {}\r\n};\r\nstruct\
    \ Line : Segment {\r\n  using Segment::Segment;\r\n  Line(Real a, Real b, Real\
    \ c) {\r\n    if (sgn(a) == 0) {\r\n      s = Point(0, -c / b); t = Point(1, s.y);\r\
    \n    } else if (sgn(b) == 0) {\r\n      s = Point(-c / a, 0); t = Point(s.x,\
    \ 1);\r\n    } else if (sgn(c) == 0) {\r\n      s = Point(0, 0); t = Point(1,\
    \ -a / b);\r\n    } else {\r\n      s = Point(0, -c / b); t = Point(-c / a, 0);\r\
    \n    }\r\n  }\r\n};\r\n\r\nstruct Circle {\r\n  Point p; Real r;\r\n  Circle(const\
    \ Point &p = {0, 0}, Real r = 0) : p(p), r(r) {}\r\n};\r\n\r\nReal cross(const\
    \ Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }\r\nReal dot(const\
    \ Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }\r\n\r\nint ccw(const\
    \ Point &a, const Point &b, const Point &c) {\r\n  Point ab = b - a, ac = c -\
    \ a;\r\n  int sign = sgn(cross(ab, ac));\r\n  if (sign == 0) {\r\n    if (sgn(dot(ab,\
    \ ac)) == -1) return 2;\r\n    if (sgn(ac.norm() - ab.norm()) == 1) return -2;\r\
    \n  }\r\n  return sign;\r\n}\r\n\r\nReal get_angle(const Point &a, const Point\
    \ &b, const Point &c) {\r\n  Real ba_arg = (a - b).arg(), bc_arg = (c - b).arg();\r\
    \n  if (ba_arg > bc_arg) std::swap(ba_arg, bc_arg);\r\n  return std::min(bc_arg\
    \ - ba_arg, static_cast<Real>(PI * 2 - (bc_arg - ba_arg)));\r\n}\r\n\r\nReal closest_pair(std::vector<Point>\
    \ ps) {\r\n  int n = ps.size();\r\n  assert(n > 1);\r\n  std::sort(ps.begin(),\
    \ ps.end());\r\n  std::function<Real(int, int)> rec = [&ps, &rec](int left, int\
    \ right) -> Real {\r\n    int mid = (left + right) >> 1;\r\n    Real x_mid = ps[mid].x,\
    \ d = std::numeric_limits<Real>::max();\r\n    if (left + 1 < mid) {\r\n     \
    \ Real tmp = rec(left, mid);\r\n      if (tmp < d) d = tmp;\r\n    }\r\n    if\
    \ (mid + 1 < right) {\r\n      Real tmp = rec(mid, right);\r\n      if (tmp <\
    \ d) d = tmp;\r\n    }\r\n    std::inplace_merge(ps.begin() + left, ps.begin()\
    \ + mid, ps.begin() + right, [&](const Point &a, const Point &b) -> bool { return\
    \ sgn(b.y - a.y) == 1; });\r\n    std::vector<Point> tmp;\r\n    for (int i =\
    \ left; i < right; ++i) {\r\n      if (sgn(std::abs(ps[i].x - x_mid) - d) == 1)\
    \ continue;\r\n      for (int j = static_cast<int>(tmp.size()) - 1; j >= 0; --j)\
    \ {\r\n        Point now = ps[i] - tmp[j];\r\n        if (sgn(now.y - d) == 1)\
    \ break;\r\n        Real tmp = now.abs();\r\n        if (tmp < d) d = tmp;\r\n\
    \      }\r\n      tmp.emplace_back(ps[i]);\r\n    }\r\n    return d;\r\n  };\r\
    \n  return rec(0, n);\r\n}\r\n\r\nPoint projection(const Segment &a, const Point\
    \ &b) { return a.s + (a.t - a.s) * dot(a.t - a.s, b - a.s) / (a.t - a.s).norm();\
    \ }\r\nPoint reflection(const Segment &a, const Point &b) { return projection(a,\
    \ b) * 2 - b; }\r\n\r\nbool is_parallel(const Segment &a, const Segment &b) {\
    \ return sgn(cross(a.t - a.s, b.t - b.s)) == 0; }\r\nbool is_orthogonal(const\
    \ Segment &a, const Segment &b) { return sgn(dot(a.t - a.s, b.t - b.s)) == 0;\
    \ }\r\n\r\nReal distance(const Point&, const Point&);\r\nReal distance(const Segment&,\
    \ const Point&);\r\nReal distance(const Line&, const Point&);\r\nint sizeof_common_tangent(const\
    \ Circle&, const Circle&);\r\nbool has_intersected(const Segment &a, const Point\
    \ &b) { return ccw(a.s, a.t, b) == 0; }\r\nbool has_intersected(const Segment\
    \ &a, const Segment &b) { return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0\
    \ && ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0; }\r\nbool has_intersected(const\
    \ Line &a, const Point &b) { int c = ccw(a.s, a.t, b); return c != 1 && c != -1;\
    \ }\r\nbool has_intersected(const Line &a, const Segment &b) { return ccw(a.s,\
    \ a.t, b.s) * ccw(a.s, a.t, b.t) != 1; }\r\nbool has_intersected(const Line &a,\
    \ const Line &b) { return sgn(cross(a.t - a.s, b.t - b.s)) != 0 || sgn(cross(a.t\
    \ - a.s, b.s - a.s)) == 0; }\r\nbool has_intersected(const Circle &a, const Point\
    \ &b) { return sgn(distance(a.p, b) - a.r) == 0; }\r\nbool has_intersected(const\
    \ Circle &a, const Segment &b) { return sgn(a.r - distance(b, a.p)) != -1 && sgn(std::max(distance(a.p,\
    \ b.s), distance(a.p, b.t)) - a.r) != -1; }\r\nbool has_intersected(const Circle\
    \ &a, const Line &b) { return sgn(a.r - distance(b, a.p)) != -1; }\r\nbool has_intersected(const\
    \ Circle &a, const Circle &b) { return sizeof_common_tangent(a, b) > 0; }\r\n\r\
    \nPoint intersection(const Line &a, const Line &b) {\r\n  assert(has_intersected(a,\
    \ b) && !is_parallel(a, b));\r\n  return a.s + (a.t - a.s) * cross(b.t - b.s,\
    \ b.s - a.s) / cross(b.t - b.s, a.t - a.s);\r\n}\r\nPoint intersection(const Segment\
    \ &a, const Segment &b) {\r\n  assert(has_intersected(a, b));\r\n  if (is_parallel(a,\
    \ b)) {\r\n    if (sgn(distance(a.s, b.s)) == 0) {\r\n      assert(sgn(dot(a.t\
    \ - a.s, b.t - a.s)) == -1);\r\n      return a.s;\r\n    } else if (sgn(distance(a.s,\
    \ b.t)) == 0) {\r\n      assert(sgn(dot(a.t - a.s, b.s - a.s)) == -1);\r\n   \
    \   return a.s;\r\n    } else if (sgn(distance(a.t, b.s)) == 0) {\r\n      assert(sgn(dot(a.s\
    \ - a.t, b.t - a.t)) == -1);\r\n      return a.t;\r\n    } else if (sgn(distance(a.t,\
    \ b.t)) == 0) {\r\n      assert(sgn(dot(a.s - a.t, b.s - a.t)) == -1);\r\n   \
    \   return a.t;\r\n    } else {\r\n      assert(false);\r\n    }\r\n  } else {\r\
    \n    return intersection(Line(a.s, a.t), Line(b.s, b.t));\r\n  }\r\n}\r\nPoint\
    \ intersection(const Line &a, const Segment &b) {\r\n  assert(has_intersected(a,\
    \ b));\r\n  return intersection(a, Line(b.s, b.t));\r\n}\r\nstd::vector<Point>\
    \ intersection(const Circle &a, const Line &b) {\r\n  Point pro = projection(b,\
    \ a.p);\r\n  Real nor = (a.p - pro).norm();\r\n  int sign = sgn(a.r - std::sqrt(nor));\r\
    \n  if (sign == -1) return {};\r\n  if (sign == 0) return {pro};\r\n  Point v\
    \ = (b.t - b.s).unit_vector() * std::sqrt(a.r * a.r - nor);\r\n  return {pro +\
    \ v, pro - v};\r\n}\r\nstd::vector<Point> intersection(const Circle &a, const\
    \ Segment &b) {\r\n  if (!has_intersected(a, b)) return {};\r\n  std::vector<Point>\
    \ res = intersection(a, Line(b.s, b.t));\r\n  if (sgn(distance(a.p, b.s) - a.r)\
    \ != -1 && sgn(distance(a.p, b.t) - a.r) != -1) return res;\r\n  return {sgn(dot(res[0]\
    \ - b.s, res[0] - b.t)) == 1 ? res[1] : res[0]};\r\n}\r\nstd::vector<Point> intersection(const\
    \ Circle &a, const Circle &b) {\r\n  int sz = sizeof_common_tangent(a, b);\r\n\
    \  if (sz == 0 || sz == 4) return {};\r\n  Real alpha = (b.p - a.p).arg();\r\n\
    \  if (sz == 1 || sz == 3) return {Point(a.p.x + a.r * std::cos(alpha), a.p.y\
    \ + a.r * std::sin(alpha))};\r\n  Real dist = (b.p - a.p).norm(), beta = std::acos((dist\
    \ + a.r * a.r - b.r * b.r) / (2 * std::sqrt(dist) * a.r));\r\n  return {a.p +\
    \ Point(a.r * std::cos(alpha + beta), a.r * std::sin(alpha + beta)), a.p + Point(a.r\
    \ * std::cos(alpha - beta), a.r * std::sin(alpha - beta))};\r\n}\r\n\r\nReal distance(const\
    \ Point &a, const Point &b) { return (b - a).abs(); }\r\nReal distance(const Segment\
    \ &a, const Point &b) {\r\n  Point foot = projection(a, b);\r\n  return has_intersected(a,\
    \ foot) ? distance(foot, b) : std::min(distance(a.s, b), distance(a.t, b));\r\n\
    }\r\nReal distance(const Segment &a, const Segment &b) { return has_intersected(a,\
    \ b) ? 0 : std::min({distance(a, b.s), distance(a, b.t), distance(b, a.s), distance(b,\
    \ a.t)}); }\r\nReal distance(const Line &a, const Point &b) { return distance(projection(a,\
    \ b), b); }\r\nReal distance(const Line &a, const Segment &b) { return has_intersected(a,\
    \ b) ? 0 : std::min(distance(a, b.s), distance(a, b.t)); }\r\nReal distance(const\
    \ Line &a, const Line &b) { return has_intersected(a, b) ? 0 : distance(a, b.s);\
    \ }\r\n\r\nstd::vector<Point> tangency(const Circle &a, const Point &b) {\r\n\
    \  Real dist = distance(a.p, b);\r\n  int sign = sgn(dist - a.r);\r\n  if (sign\
    \ == -1) return {};\r\n  if (sign == 0) return {b};\r\n  Real alpha = (b - a.p).arg(),\
    \ beta = std::acos(a.r / dist);\r\n  return {a.p + Point(a.r * std::cos(alpha\
    \ + beta), a.r * std::sin(alpha + beta)), a.p + Point(a.r * std::cos(alpha - beta),\
    \ a.r * std::sin(alpha - beta))};\r\n}\r\nint sizeof_common_tangent(const Circle\
    \ &a, const Circle &b) {\r\n  Real dist = distance(a.p, b.p);\r\n  int sign =\
    \ sgn(a.r + b.r - dist);\r\n  if (sign == -1) return 4;\r\n  if (sign == 0) return\
    \ 3;\r\n  sign = sgn((sgn(a.r - b.r) == -1 ? b.r - a.r : a.r - b.r) - dist);\r\
    \n  if (sign == -1) return 2;\r\n  if (sign == 0) return 1;\r\n  return 0;\r\n\
    }\r\nstd::vector<Line> common_tangent(const Circle &a, const Circle &b) {\r\n\
    \  std::vector<Line> tangents;\r\n  Real dist = distance(a.p, b.p), argument =\
    \ (b.p - a.p).arg();\r\n  int sign = sgn(a.r + b.r - dist);\r\n  if (sign == -1)\
    \ {\r\n    Real ac = std::acos((a.r + b.r) / dist), alpha = argument + ac, cs\
    \ = std::cos(alpha), sn = std::sin(alpha);\r\n    tangents.emplace_back(a.p +\
    \ Point(a.r * cs, a.r * sn), b.p + Point(-b.r * cs, -b.r * sn));\r\n    alpha\
    \ = argument - ac; cs = std::cos(alpha); sn = std::sin(alpha);\r\n    tangents.emplace_back(a.p\
    \ + Point(a.r * cs, a.r * sn), b.p + Point(-b.r * cs, -b.r * sn));\r\n  } else\
    \ if (sign == 0) {\r\n    Point s = a.p + Point(a.r * std::cos(argument), a.r\
    \ * std::sin(argument));\r\n    tangents.emplace_back(s, s + (b.p - a.p).normal_unit_vector().first);\r\
    \n  }\r\n  if (sgn(b.r - a.r) == -1) {\r\n    sign = sgn(a.r - b.r - dist);\r\n\
    \    if (sign == -1) {\r\n      Real at = std::acos((a.r - b.r) / dist), alpha\
    \ = argument + at, cs = std::cos(alpha), sn = std::sin(alpha);\r\n      tangents.emplace_back(a.p\
    \ + Point(a.r * cs, a.r * sn), b.p + Point(b.r * cs, b.r * sn));\r\n      alpha\
    \ = argument - at; cs = std::cos(alpha); sn = std::sin(alpha);\r\n      tangents.emplace_back(a.p\
    \ + Point(a.r * cs, a.r * sn), b.p + Point(b.r * cs, b.r * sn));\r\n    } else\
    \ if (sign == 0) {\r\n      Point s = a.p + Point(a.r * std::cos(argument), a.r\
    \ * std::sin(argument));\r\n      tangents.emplace_back(s, s + (b.p - a.p).normal_unit_vector().first);\r\
    \n    }\r\n  } else {\r\n    sign = sgn(b.r - a.r - dist);\r\n    if (sign ==\
    \ -1) {\r\n      Real at = std::acos((b.r - a.r) / dist), alpha = argument - at,\
    \ cs = std::cos(alpha), sn = std::sin(alpha);\r\n      tangents.emplace_back(a.p\
    \ + Point(-a.r * cs, -a.r * sn), b.p + Point(-b.r * cs, -b.r * sn));\r\n     \
    \ alpha = argument + at; cs = std::cos(alpha); sn = std::sin(alpha);\r\n     \
    \ tangents.emplace_back(a.p + Point(-a.r * cs, -a.r * sn), b.p + Point(-b.r *\
    \ cs, -b.r * sn));\r\n    } else if (sign == 0) {\r\n      Point s = b.p + Point(-b.r\
    \ * std::cos(argument), -b.r * std::sin(argument));\r\n      tangents.emplace_back(s,\
    \ s + (a.p - b.p).normal_unit_vector().first);\r\n    }\r\n  }\r\n  return tangents;\r\
    \n}\r\n\r\nReal intersection_area(const Circle &a, const Circle &b) {\r\n  Real\
    \ nor = (b.p - a.p).norm(), dist = std::sqrt(nor);\r\n  if (sgn(a.r + b.r - dist)\
    \ != 1) return 0;\r\n  if (sgn(std::abs(a.r - b.r) - dist) != -1) return std::min(a.r,\
    \ b.r) * std::min(a.r, b.r) * PI;\r\n  Real alpha = std::acos((nor + a.r * a.r\
    \ - b.r * b.r) / (2 * dist * a.r)), beta = std::acos((nor + b.r * b.r - a.r *\
    \ a.r) / (2 * dist * b.r));\r\n  return (alpha - std::sin(alpha + alpha) * 0.5)\
    \ * a.r * a.r + (beta - std::sin(beta + beta) * 0.5) * b.r * b.r;\r\n}\r\n\r\n\
    using Polygon = std::vector<Point>;\r\n\r\nReal area(const Polygon &a) {\r\n \
    \ int n = a.size();\r\n  Real res = 0;\r\n  for (int i = 0; i < n; ++i) res +=\
    \ cross(a[i], a[(i + 1) % n]);\r\n  return res * 0.5;\r\n}\r\n\r\nPoint centroid(const\
    \ Polygon &a) {\r\n  Point res(0, 0);\r\n  int n = a.size();\r\n  Real den = 0;\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    Real cro = cross(a[i], a[(i + 1) % n]);\r\
    \n    res += (a[i] + a[(i + 1) % n]) / 3 * cro;\r\n    den += cro;\r\n  }\r\n\
    \  return res / den;\r\n}\r\n\r\nint is_contained(const Polygon &a, const Point\
    \ &b) {\r\n  int n = a.size();\r\n  bool is_in = false;\r\n  for (int i = 0; i\
    \ < n; ++i) {\r\n    Point p = a[i] - b, q = a[(i + 1) % n] - b;\r\n    if (sgn(q.y\
    \ - p.y) == -1) std::swap(p, q);\r\n    int sign = sgn(cross(p, q));\r\n    if\
    \ (sign == 1 && sgn(p.y) != 1 && sgn(q.y) == 1) is_in = !is_in;\r\n    if (sign\
    \ == 0 && sgn(dot(p, q)) != 1) return 1;\r\n  }\r\n  return is_in ? 2 : 0;\r\n\
    }\r\n\r\nbool is_convex(const Polygon &a) {\r\n  int n = a.size();\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    if (ccw(a[(i - 1 + n) % n], a[i], a[(i + 1) % n])\
    \ == -1) return false;\r\n  }\r\n  return true;\r\n}\r\n\r\nPolygon monotone_chain(std::vector<Point>\
    \ ps, bool tight = true) {\r\n  std::sort(ps.begin(), ps.end());\r\n  int n =\
    \ ps.size(), idx = 0;\r\n  Polygon convex_hull(n << 1);\r\n  for (int i = 0; i\
    \ < n; convex_hull[idx++] = ps[i++]) {\r\n    while (idx >= 2 && sgn(cross(convex_hull[idx\
    \ - 1] - convex_hull[idx - 2], ps[i] - convex_hull[idx - 1])) < tight) --idx;\r\
    \n  }\r\n  for (int i = n - 2, border = idx + 1; i >= 0; convex_hull[idx++] =\
    \ ps[i--]) {\r\n    while (idx >= border && sgn(cross(convex_hull[idx - 1] - convex_hull[idx\
    \ - 2], ps[i] - convex_hull[idx - 1])) < tight) --idx;\r\n  }\r\n  convex_hull.resize(idx\
    \ - 1);\r\n  return convex_hull;\r\n}\r\n\r\nPolygon cut_convex(const Polygon\
    \ &a, const Line &b) {\r\n  int n = a.size();\r\n  Polygon res;\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    int c = ccw(b.s, b.t, a[i]);\r\n    if (c != -1)\
    \ res.emplace_back(a[i]);\r\n    if (c * ccw(b.s, b.t, a[(i + 1) % n]) == -1)\
    \ res.emplace_back(intersection(Line(a[i], a[(i + 1) % n]), b));\r\n  }\r\n  if\
    \ (res.size() < 3) res.clear();\r\n  return res;\r\n}\r\n\r\nstd::pair<Point,\
    \ Point> rotating_calipers(const Polygon &a) {\r\n  int n = a.size(), high = 0,\
    \ low = 0;\r\n  if (n <= 2) {\r\n    assert(n == 2);\r\n    return {a[0], a[1]};\r\
    \n  }\r\n  for (int i = 1; i < n; ++i) {\r\n    if (a[i].y > a[high].y) high =\
    \ i;\r\n    if (a[i].y < a[low].y) low = i;\r\n  }\r\n  Real max_norm = (a[high]\
    \ - a[low]).norm();\r\n  int i = high, j = low, max_i = i, max_j = j;\r\n  do\
    \ {\r\n    ((sgn(cross(a[(i + 1) % n] - a[i], a[(j + 1) % n] - a[j])) != -1 ?\
    \ j : i) += 1) %= n;\r\n    Real tmp = (a[j] - a[i]).norm();\r\n    if (sgn(tmp\
    \ - max_norm) == 1) {\r\n      max_norm = tmp;\r\n      max_i = i; max_j = j;\r\
    \n    }\r\n  } while (i != high || j != low);\r\n  return {a[max_i], a[max_j]};\r\
    \n}\r\n}  // geometry\r\n#line 12 \"test/geometry/geometry.10.test.cpp\"\n\r\n\
    int main() {\r\n  constexpr double EPS = 1e-8;\r\n  int n, a, b;\r\n  std::cin\
    \ >> n >> a >> b;\r\n  std::vector<geometry::Point> flo(n);\r\n  for (int i =\
    \ 0; i < n; ++i) std::cin >> flo[i];\r\n  geometry::Point now = geometry::intersection(geometry::Segment(geometry::Point(a,\
    \ 0), geometry::Point(a, 200)), geometry::Segment(flo[0], flo[1])) + (flo[1] -\
    \ flo[0]).unit_vector();\r\n  int ans = 0;\r\n  for (int i = 0; i + 2 < n; ++i)\
    \ {\r\n    double sta = std::atan2((flo[i + 1] - flo[i]).y, (flo[i + 1] - flo[i]).x);\r\
    \n    while (true) {\r\n      int type = 0;\r\n      geometry::Point p;\r\n  \
    \    bool skip;\r\n      for (int j = i + 1; j <= i + 2 && j + 1 < n; ++j) {\r\
    \n        for (const geometry::Point &inter : geometry::intersection(geometry::Circle(now,\
    \ 1), geometry::Segment(flo[j], flo[j + 1]))) {\r\n          double ar = std::atan2((inter\
    \ - now).y, (inter - now).x) - sta;\r\n          if (-EPS < ar && ar < geometry::PI\
    \ / 2 + EPS) {\r\n            if (type == 0) {\r\n              type = 1;\r\n\
    \              p = inter;\r\n              skip = j > i + 1;\r\n            }\
    \ else if (type == 1) {\r\n              if (ar > std::atan2((p - now).y, (p -\
    \ now).x) - sta) {\r\n                p = inter;\r\n                skip = j >\
    \ i + 1;\r\n              }\r\n            }\r\n          }\r\n        }\r\n \
    \     }\r\n      for (int j = i + 1; j <= i + 2 && j + 1 < n; ++j) {\r\n     \
    \   for (const geometry::Point &inter : geometry::intersection(geometry::Circle(now,\
    \ std::sqrt(2)), geometry::Segment(flo[j], flo[j + 1]))) {\r\n          double\
    \ ar = std::atan2((inter - now).y, (inter - now).x) - sta;\r\n          if (geometry::PI\
    \ / 4 - EPS < ar && ar < geometry::PI / 4 * 3 + EPS) {\r\n            if (type\
    \ == 0) {\r\n              type = 2;\r\n              p = inter;\r\n         \
    \     skip = j > i + 1;\r\n            } else if (type == 1) {\r\n           \
    \   if (ar - geometry::PI / 4 > std::atan2((p - now).y, (p - now).x) - sta) {\r\
    \n                type = 2;\r\n                p = inter;\r\n                skip\
    \ = j > i + 1;\r\n              }\r\n            } else if (type == 2) {\r\n \
    \             if (ar > std::atan2((p - now).y, (p - now).x) - sta) {\r\n     \
    \           p = inter;\r\n                skip = j > i + 1;\r\n              }\r\
    \n            }\r\n          }\r\n        }\r\n      }\r\n      (ans += std::max(type,\
    \ 1)) %= 4;\r\n      if (type == 0) {\r\n        now += (flo[i + 1] - flo[i]).unit_vector();\r\
    \n      } else {\r\n        now = p;\r\n        i += skip;\r\n        break;\r\
    \n      }\r\n    }\r\n  }\r\n  while (now.x <= b) {\r\n    now += (flo[n - 1]\
    \ - flo[n - 2]).unit_vector();\r\n    (ans += 1) %= 4;\r\n  }\r\n  std::cout <<\
    \ std::vector<std::string>({\"Red\", \"Green\", \"Blue\", \"White\"})[ans] <<\
    \ '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
    \ (\u7DDA\u5206\u3068\u5186\u306E\u4EA4\u70B9)\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2316\"\
    \r\n\r\n#include <algorithm>\r\n#include <cmath>\r\n#include <iostream>\r\n#include\
    \ <string>\r\n#include <vector>\r\n#include \"../../geometry/geometry.hpp\"\r\n\
    \r\nint main() {\r\n  constexpr double EPS = 1e-8;\r\n  int n, a, b;\r\n  std::cin\
    \ >> n >> a >> b;\r\n  std::vector<geometry::Point> flo(n);\r\n  for (int i =\
    \ 0; i < n; ++i) std::cin >> flo[i];\r\n  geometry::Point now = geometry::intersection(geometry::Segment(geometry::Point(a,\
    \ 0), geometry::Point(a, 200)), geometry::Segment(flo[0], flo[1])) + (flo[1] -\
    \ flo[0]).unit_vector();\r\n  int ans = 0;\r\n  for (int i = 0; i + 2 < n; ++i)\
    \ {\r\n    double sta = std::atan2((flo[i + 1] - flo[i]).y, (flo[i + 1] - flo[i]).x);\r\
    \n    while (true) {\r\n      int type = 0;\r\n      geometry::Point p;\r\n  \
    \    bool skip;\r\n      for (int j = i + 1; j <= i + 2 && j + 1 < n; ++j) {\r\
    \n        for (const geometry::Point &inter : geometry::intersection(geometry::Circle(now,\
    \ 1), geometry::Segment(flo[j], flo[j + 1]))) {\r\n          double ar = std::atan2((inter\
    \ - now).y, (inter - now).x) - sta;\r\n          if (-EPS < ar && ar < geometry::PI\
    \ / 2 + EPS) {\r\n            if (type == 0) {\r\n              type = 1;\r\n\
    \              p = inter;\r\n              skip = j > i + 1;\r\n            }\
    \ else if (type == 1) {\r\n              if (ar > std::atan2((p - now).y, (p -\
    \ now).x) - sta) {\r\n                p = inter;\r\n                skip = j >\
    \ i + 1;\r\n              }\r\n            }\r\n          }\r\n        }\r\n \
    \     }\r\n      for (int j = i + 1; j <= i + 2 && j + 1 < n; ++j) {\r\n     \
    \   for (const geometry::Point &inter : geometry::intersection(geometry::Circle(now,\
    \ std::sqrt(2)), geometry::Segment(flo[j], flo[j + 1]))) {\r\n          double\
    \ ar = std::atan2((inter - now).y, (inter - now).x) - sta;\r\n          if (geometry::PI\
    \ / 4 - EPS < ar && ar < geometry::PI / 4 * 3 + EPS) {\r\n            if (type\
    \ == 0) {\r\n              type = 2;\r\n              p = inter;\r\n         \
    \     skip = j > i + 1;\r\n            } else if (type == 1) {\r\n           \
    \   if (ar - geometry::PI / 4 > std::atan2((p - now).y, (p - now).x) - sta) {\r\
    \n                type = 2;\r\n                p = inter;\r\n                skip\
    \ = j > i + 1;\r\n              }\r\n            } else if (type == 2) {\r\n \
    \             if (ar > std::atan2((p - now).y, (p - now).x) - sta) {\r\n     \
    \           p = inter;\r\n                skip = j > i + 1;\r\n              }\r\
    \n            }\r\n          }\r\n        }\r\n      }\r\n      (ans += std::max(type,\
    \ 1)) %= 4;\r\n      if (type == 0) {\r\n        now += (flo[i + 1] - flo[i]).unit_vector();\r\
    \n      } else {\r\n        now = p;\r\n        i += skip;\r\n        break;\r\
    \n      }\r\n    }\r\n  }\r\n  while (now.x <= b) {\r\n    now += (flo[n - 1]\
    \ - flo[n - 2]).unit_vector();\r\n    (ans += 1) %= 4;\r\n  }\r\n  std::cout <<\
    \ std::vector<std::string>({\"Red\", \"Green\", \"Blue\", \"White\"})[ans] <<\
    \ '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.10.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.10.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.10.test.cpp
- /verify/test/geometry/geometry.10.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u7DDA\u5206\
  \u3068\u5186\u306E\u4EA4\u70B9)"
---
