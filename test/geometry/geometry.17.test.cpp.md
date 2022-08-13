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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (\u591A\u89D2\u5F62\u306E\u9762\u7A4D)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
  bundledCode: "#line 1 \"test/geometry/geometry.17.test.cpp\"\n/*\n * @brief \u8A08\
    \u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u591A\u89D2\u5F62\u306E\
    \u9762\u7A4D)\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
    \n\n#include <iomanip>\n#include <iostream>\n\n#line 2 \"geometry/geometry.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <functional>\n\
    #line 7 \"geometry/geometry.hpp\"\n#include <iterator>\n#include <limits>\n#include\
    \ <tuple>\n#include <utility>\n#include <vector>\n\nnamespace geometry {\n\nusing\
    \ Real = double;\nconstexpr long double PI = 3.14159265358979323846;\n\nint sgn(const\
    \ Real x) {\n  static constexpr Real EPS = 1e-8;\n  return x > EPS ? 1 : (x <\
    \ -EPS ? -1 : 0);\n}\n\nReal degree_to_radian(const Real d) { return d * PI /\
    \ 180; }\nReal radian_to_degree(const Real r) { return r * 180 / PI; }\n\nstruct\
    \ Point {\n  Real x, y;\n  explicit Point(const Real x = 0, const Real y = 0)\
    \ : x(x), y(y) {}\n  Real abs() const { return std::sqrt(norm()); }\n  Real arg()\
    \ const {\n    const Real res = std::atan2(y, x);\n    return res < 0 ? res +\
    \ PI * 2 : res;\n  }\n  Real norm() const { return x * x + y * y; }\n  Point rotate(const\
    \ Real angle) const {\n    const Real cs = std::cos(angle), sn = std::sin(angle);\n\
    \    return Point(x * cs - y * sn, x * sn + y * cs);\n  }\n  Point& operator+=(const\
    \ Point& p) {\n    x += p.x; y += p.y;\n    return *this;\n  }\n  Point& operator-=(const\
    \ Point& p) {\n    x -= p.x; y -= p.y;\n    return *this;\n  }\n  Point& operator*=(const\
    \ Real k) {\n    x *= k; y *= k;\n    return *this;\n  }\n  Point& operator/=(const\
    \ Real k) {\n    x /= k; y /= k;\n    return *this;\n  }\n  bool operator<(const\
    \ Point& p) const {\n    const int x_sgn = sgn(p.x - x);\n    return x_sgn !=\
    \ 0 ? x_sgn == 1 : sgn(p.y - y) == 1;\n  }\n  bool operator<=(const Point& p)\
    \ const { return !(p < *this); }\n  bool operator>(const Point& p) const { return\
    \ p < *this; }\n  bool operator>=(const Point& p) const { return !(*this < p);\
    \ }\n  Point operator+() const { return *this; }\n  Point operator-() const {\
    \ return Point(-x, -y); }\n  Point operator+(const Point& p) const { return Point(*this)\
    \ += p; }\n  Point operator-(const Point& p) const { return Point(*this) -= p;\
    \ }\n  Point operator*(const Real k) const { return Point(*this) *= k; }\n  Point\
    \ operator/(const Real k) const { return Point(*this) /= k; }\n  friend std::ostream&\
    \ operator<<(std::ostream& os, const Point& p) {\n    return os << '(' << p.x\
    \ << \", \" << p.y << ')';\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, Point& p) {\n    Real x, y; is >> x >> y;\n    p = Point(x, y);\n    return\
    \ is;\n  }\n};\n\nstruct Segment {\n  Point s, t;\n  explicit Segment(const Point&\
    \ s = Point(0, 0), const Point& t = Point(0, 0))\n      : s(s), t(t) {}\n};\n\
    struct Line : Segment {\n  using Segment::Segment;\n  explicit Line(const Real\
    \ a, const Real b, const Real c) {\n    if (sgn(a) == 0) {\n      s = Point(0,\
    \ -c / b); t = Point(1, s.y);\n    } else if (sgn(b) == 0) {\n      s = Point(-c\
    \ / a, 0); t = Point(s.x, 1);\n    } else if (sgn(c) == 0) {\n      s = Point(0,\
    \ 0); t = Point(1, -a / b);\n    } else {\n      s = Point(0, -c / b); t = Point(-c\
    \ / a, 0);\n    }\n  }\n};\n\nstruct Circle {\n  Point p; Real r;\n  explicit\
    \ Circle(const Point& p = Point(0, 0), const Real r = 0)\n      : p(p), r(r) {}\n\
    };\n\nPoint unit_vector(const Point& p) {\n  const Real a = p.abs();\n  return\
    \ Point(p.x / a, p.y / a);\n}\nstd::tuple<Point, Point> normal_unit_vector(const\
    \ Point& p) {\n  const Point u = unit_vector(p);\n  return {Point(-u.y, u.x),\
    \ Point(u.y, -u.x)};\n}\n\nReal cross(const Point& a, const Point& b) { return\
    \ a.x * b.y - a.y * b.x; }\nReal dot(const Point& a, const Point& b) { return\
    \ a.x * b.x + a.y * b.y; }\n\nint ccw(const Point& a, const Point& b, const Point&\
    \ c) {\n  const Point ab = b - a, ac = c - a;\n  const int sign = sgn(cross(ab,\
    \ ac));\n  if (sign == 0) {\n    if (sgn(dot(ab, ac)) == -1) return 2;\n    if\
    \ (sgn(ac.norm() - ab.norm()) == 1) return -2;\n  }\n  return sign;\n}\n\nReal\
    \ get_angle(const Point& a, const Point& b, const Point& c) {\n  Real ab = (a\
    \ - b).arg(), bc = (c - b).arg();\n  if (ab > bc) std::swap(ab, bc);\n  return\
    \ std::min(bc - ab, static_cast<Real>(PI * 2 - (bc - ab)));\n}\n\nReal closest_pair(std::vector<Point>\
    \ ps) {\n  const int n = ps.size();\n  assert(n >= 2);\n  std::sort(ps.begin(),\
    \ ps.end());\n  const std::function<Real(int, int)> f =\n      [&ps, &f](const\
    \ int left, const int right) -> Real {\n        const int mid = (left + right)\
    \ >> 1;\n        Real x_mid = ps[mid].x, d = std::numeric_limits<Real>::max();\n\
    \        if (left + 1 < mid) d = std::min(d, f(left, mid));\n        if (mid +\
    \ 1 < right) d = std::min(d, f(mid, right));\n        std::inplace_merge(std::next(ps.begin(),\
    \ left),\n                           std::next(ps.begin(), mid),\n           \
    \                std::next(ps.begin(), right),\n                           [](const\
    \ Point& a, const Point& b) -> bool {\n                             return sgn(b.y\
    \ - a.y) == 1;\n                           });\n        std::vector<Point> tmp;\n\
    \        for (int i = left; i < right; ++i) {\n          if (sgn(std::abs(ps[i].x\
    \ - x_mid) - d) == 1) continue;\n          for (int j = static_cast<int>(tmp.size())\
    \ - 1; j >= 0; --j) {\n            const Point v = ps[i] - tmp[j];\n         \
    \   if (sgn(v.y - d) == 1) break;\n            d = std::min(d, v.abs());\n   \
    \       }\n          tmp.emplace_back(ps[i]);\n        }\n        return d;\n\
    \      };\n  return f(0, n);\n}\n\nPoint projection(const Segment& a, const Point&\
    \ b) {\n  return a.s + (a.t - a.s) * dot(a.t - a.s, b - a.s) / (a.t - a.s).norm();\n\
    }\nPoint reflection(const Segment& a, const Point& b) {\n  return projection(a,\
    \ b) * 2 - b;\n}\n\nbool is_parallel(const Segment& a, const Segment& b) {\n \
    \ return sgn(cross(a.t - a.s, b.t - b.s)) == 0;\n}\nbool is_orthogonal(const Segment&\
    \ a, const Segment& b) {\n  return sgn(dot(a.t - a.s, b.t - b.s)) == 0;\n}\n\n\
    Real distance(const Point&, const Point&);\nReal distance(const Segment&, const\
    \ Point&);\nReal distance(const Line&, const Point&);\nint common_tangent_num(const\
    \ Circle&, const Circle&);\nbool has_intersected(const Segment& a, const Point&\
    \ b) {\n  return ccw(a.s, a.t, b) == 0;\n}\nbool has_intersected(const Segment&\
    \ a, const Segment& b) {\n  return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <=\
    \ 0 &&\n         ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;\n}\nbool has_intersected(const\
    \ Line& a, const Point& b) {\n  const int c = ccw(a.s, a.t, b);\n  return c !=\
    \ 1 && c != -1;\n}\nbool has_intersected(const Line& a, const Segment& b) {\n\
    \  return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) != 1;\n}\nbool has_intersected(const\
    \ Line& a, const Line& b) {\n  return sgn(cross(a.t - a.s, b.t - b.s)) != 0 ||\n\
    \         sgn(cross(a.t - a.s, b.s - a.s)) == 0;\n}\nbool has_intersected(const\
    \ Circle& a, const Point& b) {\n  return sgn(distance(a.p, b) - a.r) == 0;\n}\n\
    bool has_intersected(const Circle& a, const Segment& b) {\n  return sgn(a.r -\
    \ distance(b, a.p)) != -1 &&\n         sgn(std::max(distance(a.p, b.s), distance(a.p,\
    \ b.t)) - a.r) != -1;\n}\nbool has_intersected(const Circle& a, const Line& b)\
    \ {\n  return sgn(a.r - distance(b, a.p)) != -1;\n}\nbool has_intersected(const\
    \ Circle& a, const Circle& b) {\n  const int num = common_tangent_num(a, b);\n\
    \  return 1 <= num && num <= 3;\n}\n\nPoint intersection(const Line& a, const\
    \ Line& b) {\n  assert(has_intersected(a, b) && !is_parallel(a, b));\n  const\
    \ Point va = a.t - a.s, vb = b.t - b.s;\n  return a.s + va * cross(vb, b.s - a.s)\
    \ / cross(vb, va);\n}\nPoint intersection(const Segment& a, const Segment& b)\
    \ {\n  assert(has_intersected(a, b));\n  if (is_parallel(a, b)) {\n    if (sgn(distance(a.s,\
    \ b.s)) == 0) {\n      assert(sgn(dot(a.t - a.s, b.t - a.s)) == -1);\n      return\
    \ a.s;\n    } else if (sgn(distance(a.s, b.t)) == 0) {\n      assert(sgn(dot(a.t\
    \ - a.s, b.s - a.s)) == -1);\n      return a.s;\n    } else if (sgn(distance(a.t,\
    \ b.s)) == 0) {\n      assert(sgn(dot(a.s - a.t, b.t - a.t)) == -1);\n      return\
    \ a.t;\n    } else if (sgn(distance(a.t, b.t)) == 0) {\n      assert(sgn(dot(a.s\
    \ - a.t, b.s - a.t)) == -1);\n      return a.t;\n    } else {\n      assert(false);\n\
    \    }\n  } else {\n    return intersection(Line(a.s, a.t), Line(b.s, b.t));\n\
    \  }\n}\nPoint intersection(const Line& a, const Segment& b) {\n  assert(has_intersected(a,\
    \ b));\n  return intersection(a, Line(b.s, b.t));\n}\nstd::vector<Point> intersection(const\
    \ Circle& a, const Line& b) {\n  const Point pro = projection(b, a.p);\n  const\
    \ Real nor = (a.p - pro).norm();\n  const int sign = sgn(a.r - std::sqrt(nor));\n\
    \  if (sign == -1) return {};\n  if (sign == 0) return {pro};\n  const Point tmp\
    \ = unit_vector(b.t - b.s) * std::sqrt(a.r * a.r - nor);\n  return {pro + tmp,\
    \ pro - tmp};\n}\nstd::vector<Point> intersection(const Circle& a, const Segment&\
    \ b) {\n  if (!has_intersected(a, b)) return {};\n  const std::vector<Point> res\
    \ = intersection(a, Line(b.s, b.t));\n  if (sgn(distance(a.p, b.s) - a.r) != -1\
    \ &&\n      sgn(distance(a.p, b.t) - a.r) != -1) {\n    return res;\n  }\n  return\
    \ {res[sgn(dot(res[0] - b.s, res[0] - b.t)) == 1 ? 1 : 0]};\n}\nstd::vector<Point>\
    \ intersection(const Circle& a, const Circle& b) {\n  const int num = common_tangent_num(a,\
    \ b);\n  if (num == 0 || num == 4) return {};\n  const Real alpha = (b.p - a.p).arg();\n\
    \  if (num == 1 || num == 3) {\n    return {Point(a.p.x + a.r * std::cos(alpha),\n\
    \                  a.p.y + a.r * std::sin(alpha))};\n  }\n  const Real dist =\
    \ (b.p - a.p).norm();\n  const Real beta =\n      std::acos((dist + a.r * a.r\
    \ - b.r * b.r) / (2 * std::sqrt(dist) * a.r));\n  return {\n      a.p + Point(a.r\
    \ * std::cos(alpha + beta), a.r * std::sin(alpha + beta)),\n      a.p + Point(a.r\
    \ * std::cos(alpha - beta), a.r * std::sin(alpha - beta))};\n}\n\nReal distance(const\
    \ Point& a, const Point& b) { return (b - a).abs(); }\nReal distance(const Segment&\
    \ a, const Point& b) {\n  const Point foot = projection(a, b);\n  return has_intersected(a,\
    \ foot) ?\n         distance(foot, b) : std::min(distance(a.s, b), distance(a.t,\
    \ b));\n}\nReal distance(const Segment& a, const Segment& b) {\n  return has_intersected(a,\
    \ b) ? 0 :\n         std::min({distance(a, b.s), distance(a, b.t),\n         \
    \          distance(b, a.s), distance(b, a.t)});\n}\nReal distance(const Line&\
    \ a, const Point& b) {\n  return distance(projection(a, b), b);\n}\nReal distance(const\
    \ Line& a, const Segment& b) {\n  return has_intersected(a, b) ?\n         0 :\
    \ std::min(distance(a, b.s), distance(a, b.t));\n}\nReal distance(const Line&\
    \ a, const Line& b) {\n  return has_intersected(a, b) ? 0 : distance(a, b.s);\n\
    }\n\nstd::vector<Point> tangency(const Circle& a, const Point& b) {\n  const Real\
    \ dist = distance(a.p, b);\n  const int sign = sgn(dist - a.r);\n  if (sign ==\
    \ -1) return {};\n  if (sign == 0) return {b};\n  const Real alpha = (b - a.p).arg(),\
    \ beta = std::acos(a.r / dist);\n  return {\n      a.p + Point(a.r * std::cos(alpha\
    \ + beta), a.r * std::sin(alpha + beta)),\n      a.p + Point(a.r * std::cos(alpha\
    \ - beta), a.r * std::sin(alpha - beta))};\n}\nint common_tangent_num(const Circle&\
    \ a, const Circle& b) {\n  const Real dist = distance(a.p, b.p);\n  int sign =\
    \ sgn(a.r + b.r - dist);\n  if (sign == -1) return 4;\n  if (sign == 0) return\
    \ 3;\n  sign = sgn((sgn(a.r - b.r) == -1 ? b.r - a.r : a.r - b.r) - dist);\n \
    \ if (sign == -1) return 2;\n  if (sign == 0) return 1;\n  return 0;\n}\nstd::vector<Line>\
    \ common_tangent(const Circle& a, const Circle& b) {\n  std::vector<Line> tangents;\n\
    \  const Real dist = distance(a.p, b.p), argument = (b.p - a.p).arg();\n  int\
    \ sign = sgn(a.r + b.r - dist);\n  if (sign == -1) {\n    const Real ac = std::acos((a.r\
    \ + b.r) / dist);\n    Real alpha = argument + ac, cs = std::cos(alpha), sn =\
    \ std::sin(alpha);\n    tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn),\n\
    \                          b.p + Point(-b.r * cs, -b.r * sn));\n    alpha = argument\
    \ - ac; cs = std::cos(alpha); sn = std::sin(alpha);\n    tangents.emplace_back(a.p\
    \ + Point(a.r * cs, a.r * sn),\n                          b.p + Point(-b.r * cs,\
    \ -b.r * sn));\n  } else if (sign == 0) {\n    const Point s =\n        a.p +\
    \ Point(a.r * std::cos(argument), a.r * std::sin(argument));\n    tangents.emplace_back(s,\
    \ s + std::get<0>(normal_unit_vector(b.p - a.p)));\n  }\n  if (sgn(b.r - a.r)\
    \ == -1) {\n    sign = sgn(a.r - b.r - dist);\n    if (sign == -1) {\n      const\
    \ Real at = std::acos((a.r - b.r) / dist);\n      Real alpha = argument + at,\
    \ cs = std::cos(alpha), sn = std::sin(alpha);\n      tangents.emplace_back(a.p\
    \ + Point(a.r * cs, a.r * sn),\n                            b.p + Point(b.r *\
    \ cs, b.r * sn));\n      alpha = argument - at; cs = std::cos(alpha); sn = std::sin(alpha);\n\
    \      tangents.emplace_back(a.p + Point(a.r * cs, a.r * sn),\n              \
    \              b.p + Point(b.r * cs, b.r * sn));\n    } else if (sign == 0) {\n\
    \      const Point s =\n          a.p + Point(a.r * std::cos(argument), a.r *\
    \ std::sin(argument));\n      tangents.emplace_back(s, s + std::get<0>(normal_unit_vector(b.p\
    \ - a.p)));\n    }\n  } else {\n    sign = sgn(b.r - a.r - dist);\n    if (sign\
    \ == -1) {\n      const Real at = std::acos((b.r - a.r) / dist);\n      Real alpha\
    \ = argument - at, cs = std::cos(alpha), sn = std::sin(alpha);\n      tangents.emplace_back(a.p\
    \ + Point(-a.r * cs, -a.r * sn),\n                            b.p + Point(-b.r\
    \ * cs, -b.r * sn));\n      alpha = argument + at; cs = std::cos(alpha); sn =\
    \ std::sin(alpha);\n      tangents.emplace_back(a.p + Point(-a.r * cs, -a.r *\
    \ sn),\n                            b.p + Point(-b.r * cs, -b.r * sn));\n    }\
    \ else if (sign == 0) {\n      const Point s =\n          b.p + Point(-b.r * std::cos(argument),\
    \ -b.r * std::sin(argument));\n      tangents.emplace_back(s, s + std::get<0>(normal_unit_vector(a.p\
    \ - b.p)));\n    }\n  }\n  return tangents;\n}\n\nReal intersection_area(const\
    \ Circle& a, const Circle& b) {\n  const Real nor = (b.p - a.p).norm(), dist =\
    \ std::sqrt(nor);\n  if (sgn(a.r + b.r - dist) != 1) return 0;\n  if (sgn(std::abs(a.r\
    \ - b.r) - dist) != -1) {\n    return std::min(a.r, b.r) * std::min(a.r, b.r)\
    \ * PI;\n  }\n  const Real alpha =\n      std::acos((nor + a.r * a.r - b.r * b.r)\
    \ / (2 * dist * a.r));\n  const Real beta = std::acos((nor + b.r * b.r - a.r *\
    \ a.r) / (2 * dist * b.r));\n  return (alpha - std::sin(alpha + alpha) * 0.5)\
    \ * a.r * a.r +\n         (beta - std::sin(beta + beta) * 0.5) * b.r * b.r;\n\
    }\n\nusing Polygon = std::vector<Point>;\n\nReal area(Polygon a) {\n  const int\
    \ n = a.size();\n  a.resize(n + 1);\n  a.back() = a.front();\n  Real res = 0;\n\
    \  for (int i = 0; i < n; ++i) {\n    res += cross(a[i], a[i + 1]);\n  }\n  return\
    \ res * 0.5;\n}\n\nPoint centroid(Polygon a) {\n  const int n = a.size();\n  a.resize(n\
    \ + 1);\n  a.back() = a.front();\n  Point res(0, 0);\n  Real den = 0;\n  for (int\
    \ i = 0; i < n; ++i) {\n    const Real cro = cross(a[i], a[i + 1]);\n    res +=\
    \ (a[i] + a[i + 1]) / 3 * cro;\n    den += cro;\n  }\n  return res / den;\n}\n\
    \nint contains(Polygon a, const Point &b) {\n  const int n = a.size();\n  a.resize(n\
    \ + 1);\n  a.back() = a.front();\n  bool is_in = false;\n  for (int i = 0; i <\
    \ n; ++i) {\n    Point p = a[i] - b, q = a[i + 1] - b;\n    if (sgn(q.y - p.y)\
    \ == -1) std::swap(p, q);\n    const int sign = sgn(cross(p, q));\n    if (sign\
    \ == 1 && sgn(p.y) != 1 && sgn(q.y) == 1) is_in = !is_in;\n    if (sign == 0 &&\
    \ sgn(dot(p, q)) != 1) return 1;\n  }\n  return is_in ? 2 : 0;\n}\n\nbool is_convex(Polygon\
    \ a) {\n  const int n = a.size();\n  a.resize(n + 2);\n  a[n] = a[0];\n  a[n +\
    \ 1] = a[1];\n  for (int i = 1; i <= n; ++i) {\n    if (ccw(a[i - 1], a[i], a[i\
    \ + 1]) == -1) return false;\n  }\n  return true;\n}\n\nPolygon monotone_chain(std::vector<Point>\
    \ ps, const bool is_tight = true) {\n  const int n = ps.size();\n  std::sort(ps.begin(),\
    \ ps.end());\n  Polygon convex_hull(n << 1);\n  int idx = 0;\n  for (int i = 0;\
    \ i < n; convex_hull[idx++] = ps[i++]) {\n    while (idx >= 2 &&\n           sgn(cross(convex_hull[idx\
    \ - 1] - convex_hull[idx - 2],\n                     ps[i] - convex_hull[idx -\
    \ 1])) < is_tight) {\n      --idx;\n    }\n  }\n  for (int i = n - 2, border =\
    \ idx + 1; i >= 0; convex_hull[idx++] = ps[i--]) {\n    while (idx >= border &&\n\
    \           sgn(cross(convex_hull[idx - 1] - convex_hull[idx - 2],\n         \
    \            ps[i] - convex_hull[idx - 1])) < is_tight) {\n      --idx;\n    }\n\
    \  }\n  convex_hull.resize(idx - 1);\n  return convex_hull;\n}\n\nPolygon cut_convex(Polygon\
    \ a, const Line& b) {\n  const int n = a.size();\n  a.resize(n + 1);\n  a.back()\
    \ = a.front();\n  Polygon res;\n  for (int i = 0; i < n; ++i) {\n    const int\
    \ c = ccw(b.s, b.t, a[i]);\n    if (c != -1) res.emplace_back(a[i]);\n    if (c\
    \ * ccw(b.s, b.t, a[i + 1]) == -1) {\n      res.emplace_back(intersection(Line(a[i],\
    \ a[i + 1]), b));\n    }\n  }\n  return res.size() < 3 ? Polygon() : res;\n}\n\
    \nstd::tuple<Point, Point> rotating_calipers(Polygon a) {\n  const int n = a.size();\n\
    \  if (n <= 2) {\n    assert(n == 2);\n    return {a[0], a[1]};\n  }\n  a.resize(n\
    \ + 1);\n  a.back() = a.front();\n  int high = 0, low = 0;\n  for (int i = 1;\
    \ i < n; ++i) {\n    if (a[i].y > a[high].y) high = i;\n    if (a[i].y < a[low].y)\
    \ low = i;\n  }\n  Real max_norm = (a[high] - a[low]).norm();\n  int i = high,\
    \ j = low, argmax_i = i, argmax_j = j;\n  do {\n    int* i_or_j = &(sgn(cross(a[i\
    \ + 1] - a[i], a[j + 1] - a[j])) != -1 ? j : i);\n    if (++(*i_or_j) == n) *i_or_j\
    \ = 0;\n    const Real tmp = (a[j] - a[i]).norm();\n    if (sgn(tmp - max_norm)\
    \ == 1) {\n      max_norm = tmp;\n      argmax_i = i; argmax_j = j;\n    }\n \
    \ } while (i != high || j != low);\n  return {a[argmax_i], a[argmax_j]};\n}\n\n\
    }  // namespace geometry\n\n// namespace geometry {\n\n// using Integer = long\
    \ long;\n\n// int sgn(const Integer x) {\n//   return x > 0 ? 1 : (x < 0 ? -1\
    \ : 0);\n// }\n\n// struct Point {\n//   Integer x, y;\n//   explicit Point(const\
    \ Integer x = 0, const Integer y = 0) : x(x), y(y) {}\n//   Integer norm() const\
    \ { return x * x + y * y; }\n//   Point& operator+=(const Point& p) {\n//    \
    \ x += p.x; y += p.y;\n//     return *this;\n//   }\n//   Point& operator-=(const\
    \ Point& p) {\n//     x -= p.x; y -= p.y;\n//     return *this;\n//   }\n//  \
    \ Point& operator*=(const Integer k) {\n//     x *= k; y *= k;\n//     return\
    \ *this;\n//   }\n//   Point& operator/=(const Integer k) {\n//     x /= k; y\
    \ /= k;\n//     return *this;\n//   }\n//   bool operator<(const Point& p) const\
    \ {\n//     const int x_sgn = sgn(p.x - x);\n//     return x_sgn != 0 ? x_sgn\
    \ == 1 : sgn(p.y - y) == 1;\n//   }\n//   bool operator<=(const Point& p) const\
    \ { return !(p < *this); }\n//   bool operator>(const Point& p) const { return\
    \ p < *this; }\n//   bool operator>=(const Point& p) const { return !(*this <\
    \ p); }\n//   Point operator+() const { return *this; }\n//   Point operator-()\
    \ const { return Point(-x, -y); }\n//   Point operator+(const Point& p) const\
    \ { return Point(*this) += p; }\n//   Point operator-(const Point& p) const {\
    \ return Point(*this) -= p; }\n//   Point operator*(const Integer k) const { return\
    \ Point(*this) *= k; }\n//   Point operator/(const Integer k) const { return Point(*this)\
    \ /= k; }\n//   friend std::ostream& operator<<(std::ostream& os, const Point&\
    \ p) {\n//     return os << '(' << p.x << \", \" << p.y << ')';\n//   }\n//  \
    \ friend std::istream& operator>>(std::istream& is, Point& p) {\n//     Integer\
    \ x, y; is >> x >> y;\n//     p = Point(x, y);\n//     return is;\n//   }\n//\
    \ };\n\n// struct Segment {\n//   Point s, t;\n//   explicit Segment(const Point&\
    \ s = Point(0, 0), const Point& t = Point(0, 0))\n//       : s(s), t(t) {}\n//\
    \ };\n// struct Line : Segment {\n//   using Segment::Segment;\n// };\n\n// struct\
    \ Circle {\n//   Point p; Integer r;\n//   explicit Circle(const Point& p = Point(0,\
    \ 0), const Integer r = 0)\n//       : p(p), r(r) {}\n// };\n\n// Integer cross(const\
    \ Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }\n// Integer dot(const\
    \ Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }\n\n// int ccw(const\
    \ Point& a, const Point& b, const Point& c) {\n//   const Point ab = b - a, ac\
    \ = c - a;\n//   const int sign = sgn(cross(ab, ac));\n//   if (sign == 0) {\n\
    //     if (sgn(dot(ab, ac)) == -1) return 2;\n//     if (sgn(ac.norm() - ab.norm())\
    \ == 1) return -2;\n//   }\n//   return sign;\n// }\n\n// Integer closest_pair(std::vector<Point>\
    \ ps) {\n//   const int n = ps.size();\n//   assert(n >= 2);\n//   std::sort(ps.begin(),\
    \ ps.end());\n//   const std::function<Integer(int, int)> f =\n//       [&ps,\
    \ &f](const int left, const int right) -> Integer {\n//         const int mid\
    \ = (left + right) >> 1;\n//         Integer x_mid = ps[mid].x, d = std::numeric_limits<Integer>::max();\n\
    //         if (left + 1 < mid) d = std::min(d, f(left, mid));\n//         if (mid\
    \ + 1 < right) d = std::min(d, f(mid, right));\n//         std::inplace_merge(std::next(ps.begin(),\
    \ left),\n//                            std::next(ps.begin(), mid),\n//      \
    \                      std::next(ps.begin(), right),\n//                     \
    \       [](const Point& a, const Point& b) -> bool {\n//                     \
    \         return sgn(b.y - a.y) == 1;\n//                            });\n// \
    \        std::vector<Point> tmp;\n//         for (int i = left; i < right; ++i)\
    \ {\n//           if (sgn((ps[i].x - x_mid) * (ps[i].x - x_mid) - d) == 1) continue;\n\
    //           for (int j = static_cast<int>(tmp.size()) - 1; j >= 0; --j) {\n//\
    \             const Point v = ps[i] - tmp[j];\n//             if (sgn(v.y * v.y\
    \ - d) == 1) break;\n//             d = std::min(d, v.norm());\n//           }\n\
    //           tmp.emplace_back(ps[i]);\n//         }\n//         return d;\n//\
    \       };\n//   return f(0, n);\n// }\n\n// bool is_parallel(const Segment& a,\
    \ const Segment& b) {\n//   return sgn(cross(a.t - a.s, b.t - b.s)) == 0;\n//\
    \ }\n// bool is_orthogonal(const Segment& a, const Segment& b) {\n//   return\
    \ sgn(dot(a.t - a.s, b.t - b.s)) == 0;\n// }\n\n// int common_tangent_num(const\
    \ Circle&, const Circle&);\n// bool has_intersected(const Segment& a, const Point&\
    \ b) {\n//   return ccw(a.s, a.t, b) == 0;\n// }\n// bool has_intersected(const\
    \ Segment& a, const Segment& b) {\n//   return ccw(a.s, a.t, b.s) * ccw(a.s, a.t,\
    \ b.t) <= 0 &&\n//          ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;\n//\
    \ }\n// bool has_intersected(const Line& a, const Point& b) {\n//   const int\
    \ c = ccw(a.s, a.t, b);\n//   return c != 1 && c != -1;\n// }\n// bool has_intersected(const\
    \ Line& a, const Segment& b) {\n//   return ccw(a.s, a.t, b.s) * ccw(a.s, a.t,\
    \ b.t) != 1;\n// }\n// bool has_intersected(const Line& a, const Line& b) {\n\
    //   return sgn(cross(a.t - a.s, b.t - b.s)) != 0 ||\n//          sgn(cross(a.t\
    \ - a.s, b.s - a.s)) == 0;\n// }\n// bool has_intersected(const Circle& a, const\
    \ Point& b) {\n//   return (a.p - b).norm() == a.r * a.r;\n// }\n// bool has_intersected(const\
    \ Circle& a, const Circle& b) {\n//   const int num = common_tangent_num(a, b);\n\
    //   return 1 <= num && num <= 3;\n// }\n\n// int common_tangent_num(const Circle&\
    \ a, const Circle& b) {\n//   const Integer dist = (a.p - b.p).norm();\n//   int\
    \ sign = sgn((a.r + b.r) * (a.r + b.r) - dist);\n//   if (sign == -1) return 4;\n\
    //   if (sign == 0) return 3;\n//   sign = sgn((b.r - a.r) * (b.r - a.r) - dist);\n\
    //   if (sign == -1) return 2;\n//   if (sign == 0) return 1;\n//   return 0;\n\
    // }\n\n// using Polygon = std::vector<Point>;\n\n// Integer area(Polygon a) {\n\
    //   const int n = a.size();\n//   a.resize(n + 1);\n//   a.back() = a.front();\n\
    //   Integer res = 0;\n//   for (int i = 0; i < n; ++i) {\n//     res += cross(a[i],\
    \ a[i + 1]);\n//   }\n//   // return res / 2;\n//   return res;\n// }\n\n// int\
    \ contains(Polygon a, const Point &b) {\n//   const int n = a.size();\n//   a.resize(n\
    \ + 1);\n//   a.back() = a.front();\n//   bool is_in = false;\n//   for (int i\
    \ = 0; i < n; ++i) {\n//     Point p = a[i] - b, q = a[i + 1] - b;\n//     if\
    \ (sgn(q.y - p.y) == -1) std::swap(p, q);\n//     const int sign = sgn(cross(p,\
    \ q));\n//     if (sign == 1 && sgn(p.y) != 1 && sgn(q.y) == 1) is_in = !is_in;\n\
    //     if (sign == 0 && sgn(dot(p, q)) != 1) return 1;\n//   }\n//   return is_in\
    \ ? 2 : 0;\n// }\n\n// bool is_convex(Polygon a) {\n//   const int n = a.size();\n\
    //   a.resize(n + 2);\n//   a[n] = a[0];\n//   a[n + 1] = a[1];\n//   for (int\
    \ i = 1; i <= n; ++i) {\n//     if (ccw(a[i - 1], a[i], a[i + 1]) == -1) return\
    \ false;\n//   }\n//   return true;\n// }\n\n// Polygon monotone_chain(std::vector<Point>\
    \ ps, const bool is_tight = true) {\n//   const int n = ps.size();\n//   std::sort(ps.begin(),\
    \ ps.end());\n//   Polygon convex_hull(n << 1);\n//   int idx = 0;\n//   for (int\
    \ i = 0; i < n; convex_hull[idx++] = ps[i++]) {\n//     while (idx >= 2 &&\n//\
    \            sgn(cross(convex_hull[idx - 1] - convex_hull[idx - 2],\n//      \
    \                ps[i] - convex_hull[idx - 1])) < is_tight) {\n//       --idx;\n\
    //     }\n//   }\n//   for (int i = n - 2, border = idx + 1; i >= 0; convex_hull[idx++]\
    \ = ps[i--]) {\n//     while (idx >= border &&\n//            sgn(cross(convex_hull[idx\
    \ - 1] - convex_hull[idx - 2],\n//                      ps[i] - convex_hull[idx\
    \ - 1])) < is_tight) {\n//       --idx;\n//     }\n//   }\n//   convex_hull.resize(idx\
    \ - 1);\n//   return convex_hull;\n// }\n\n// std::pair<Point, Point> rotating_calipers(Polygon\
    \ a) {\n//   const int n = a.size();\n//   if (n <= 2) {\n//     assert(n == 2);\n\
    //     return {a[0], a[1]};\n//   }\n//   a.resize(n + 1);\n//   a.back() = a.front();\n\
    //   int high = 0, low = 0;\n//   for (int i = 1; i < n; ++i) {\n//     if (a[i].y\
    \ > a[high].y) high = i;\n//     if (a[i].y < a[low].y) low = i;\n//   }\n// \
    \  Integer max_norm = (a[high] - a[low]).norm();\n//   int i = high, j = low,\
    \ argmax_i = i, argmax_j = j;\n//   do {\n//     int* i_or_j = &(sgn(cross(a[i\
    \ + 1] - a[i], a[j + 1] - a[j])) != -1 ? j : i);\n//     if (++(*i_or_j) == n)\
    \ *i_or_j = 0;\n//     const Integer tmp = (a[j] - a[i]).norm();\n//     if (sgn(tmp\
    \ - max_norm) == 1) {\n//       max_norm = tmp;\n//       argmax_i = i; argmax_j\
    \ = j;\n//     }\n//   } while (i != high || j != low);\n//   return {a[argmax_i],\
    \ a[argmax_j]};\n// }\n\n// }  // namespace geometry\n#line 10 \"test/geometry/geometry.17.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  geometry::Polygon g(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> g[i];\n  }\n  std::cout << std::fixed\
    \ << std::setprecision(1) << geometry::area(g) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @brief \u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
    \ (\u591A\u89D2\u5F62\u306E\u9762\u7A4D)\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
    \n\n#include <iomanip>\n#include <iostream>\n\n#include \"../../geometry/geometry.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  geometry::Polygon g(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> g[i];\n  }\n  std::cout << std::fixed\
    \ << std::setprecision(1) << geometry::area(g) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.17.test.cpp
  requiredBy: []
  timestamp: '2022-08-13 17:25:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.17.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.17.test.cpp
- /verify/test/geometry/geometry.17.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u591A\u89D2\
  \u5F62\u306E\u9762\u7A4D)"
---
