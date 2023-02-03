#ifndef EMTHRM_GEOMETRY_INTEGRAL_GEOMETRY_HPP_
#define EMTHRM_GEOMETRY_INTEGRAL_GEOMETRY_HPP_

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <vector>

namespace emthrm {

namespace geometry {

using Integer = long long;

int sgn(const Integer x) {
  return x > 0 ? 1 : (x < 0 ? -1 : 0);
}

struct Point {
  Integer x, y;
  explicit Point(const Integer x = 0, const Integer y = 0) : x(x), y(y) {}
  Integer norm() const { return x * x + y * y; }
  Point& operator+=(const Point& p) {
    x += p.x; y += p.y;
    return *this;
  }
  Point& operator-=(const Point& p) {
    x -= p.x; y -= p.y;
    return *this;
  }
  Point& operator*=(const Integer k) {
    x *= k; y *= k;
    return *this;
  }
  Point& operator/=(const Integer k) {
    x /= k; y /= k;
    return *this;
  }
  bool operator<(const Point& p) const {
    const int x_sgn = sgn(p.x - x);
    return x_sgn != 0 ? x_sgn == 1 : sgn(p.y - y) == 1;
  }
  bool operator<=(const Point& p) const { return !(p < *this); }
  bool operator>(const Point& p) const { return p < *this; }
  bool operator>=(const Point& p) const { return !(*this < p); }
  Point operator+() const { return *this; }
  Point operator-() const { return Point(-x, -y); }
  Point operator+(const Point& p) const { return Point(*this) += p; }
  Point operator-(const Point& p) const { return Point(*this) -= p; }
  Point operator*(const Integer k) const { return Point(*this) *= k; }
  Point operator/(const Integer k) const { return Point(*this) /= k; }
  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << '(' << p.x << ", " << p.y << ')';
  }
  friend std::istream& operator>>(std::istream& is, Point& p) {
    Integer x, y; is >> x >> y;
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
};

struct Circle {
  Point p; Integer r;
  explicit Circle(const Point& p = Point(0, 0), const Integer r = 0)
      : p(p), r(r) {}
};

Integer cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
Integer dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }

int ccw(const Point& a, const Point& b, const Point& c) {
  const Point ab = b - a, ac = c - a;
  const int sign = sgn(cross(ab, ac));
  if (sign == 0) {
    if (sgn(dot(ab, ac)) == -1) return 2;
    if (sgn(ac.norm() - ab.norm()) == 1) return -2;
  }
  return sign;
}

Integer closest_pair(std::vector<Point> ps) {
  const int n = ps.size();
  assert(n >= 2);
  std::sort(ps.begin(), ps.end());
  const std::function<Integer(int, int)> f =
      [&ps, &f](const int left, const int right) -> Integer {
        const int mid = std::midpoint(left, right);
        Integer x_mid = ps[mid].x, d = std::numeric_limits<Integer>::max();
        if (left + 1 < mid) d = std::min(d, f(left, mid));
        if (mid + 1 < right) d = std::min(d, f(mid, right));
        std::inplace_merge(std::next(ps.begin(), left),
                           std::next(ps.begin(), mid),
                           std::next(ps.begin(), right),
                           [](const Point& a, const Point& b) -> bool {
                             return sgn(b.y - a.y) == 1;
                           });
        std::vector<Point> tmp;
        for (int i = left; i < right; ++i) {
          if (sgn((ps[i].x - x_mid) * (ps[i].x - x_mid) - d) == 1) continue;
          for (int j = std::ssize(tmp) - 1; j >= 0; --j) {
            const Point v = ps[i] - tmp[j];
            if (sgn(v.y * v.y - d) == 1) break;
            d = std::min(d, v.norm());
          }
          tmp.emplace_back(ps[i]);
        }
        return d;
      };
  return f(0, n);
}

bool is_parallel(const Segment& a, const Segment& b) {
  return sgn(cross(a.t - a.s, b.t - b.s)) == 0;
}
bool is_orthogonal(const Segment& a, const Segment& b) {
  return sgn(dot(a.t - a.s, b.t - b.s)) == 0;
}

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
  return (a.p - b).norm() == a.r * a.r;
}
bool has_intersected(const Circle& a, const Circle& b) {
  const int num = common_tangent_num(a, b);
  return 1 <= num && num <= 3;
}

int common_tangent_num(const Circle& a, const Circle& b) {
  const Integer dist = (a.p - b.p).norm();
  int sign = sgn((a.r + b.r) * (a.r + b.r) - dist);
  if (sign == -1) return 4;
  if (sign == 0) return 3;
  sign = sgn((b.r - a.r) * (b.r - a.r) - dist);
  if (sign == -1) return 2;
  if (sign == 0) return 1;
  return 0;
}

using Polygon = std::vector<Point>;

Integer area(Polygon a) {
  const int n = a.size();
  a.resize(n + 1);
  a.back() = a.front();
  Integer res = 0;
  for (int i = 0; i < n; ++i) {
    res += cross(a[i], a[i + 1]);
  }
  // return res / 2;
  return res;
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

std::pair<Point, Point> rotating_calipers(Polygon a) {
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
  Integer max_norm = (a[high] - a[low]).norm();
  int i = high, j = low, argmax_i = i, argmax_j = j;
  do {
    int* i_or_j = &(sgn(cross(a[i + 1] - a[i], a[j + 1] - a[j])) != -1 ? j : i);
    if (++(*i_or_j) == n) *i_or_j = 0;
    const Integer tmp = (a[j] - a[i]).norm();
    if (sgn(tmp - max_norm) == 1) {
      max_norm = tmp;
      argmax_i = i; argmax_j = j;
    }
  } while (i != high || j != low);
  return {a[argmax_i], a[argmax_j]};
}

}  // namespace geometry

}  // namespace emthrm

#endif  // EMTHRM_GEOMETRY_INTEGRAL_GEOMETRY_HPP_
