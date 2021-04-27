#pragma once
#include <algorithm>
#include <cassert>
#include <iterator>
#include <utility>
#include <vector>

template <typename T>
struct LiChaoTree {
  struct Line {
    T a, b;
    Line(T a, T b) : a(a), b(b) {}
    T f(T x) const { return a * x + b; }
  };

  LiChaoTree(const std::vector<T> &xs_, const T inf, bool is_minimized = true) : xs(xs_), is_minimized(is_minimized) {
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    int sz = xs.size();
    assert(sz > 0);
    while (n < sz) n <<= 1;
    xs.resize(n, xs.back());
    dat.assign(n << 1, Line(0, inf));
  }

  void add(T a, T b) {
    if (!is_minimized) {
      a = -a;
      b = -b;
    }
    Line line(a, b);
    add(line, 1, 0, n);
  }

  void add(T a, T b, T left, T right) {
    if (!is_minimized) {
      a = -a;
      b = -b;
    }
    int l = std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), left));
    int r = std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), right));
    int len, node_l = l, node_r = r;
    for (l += n, r += n, len = 1; l < r; l >>= 1, r >>= 1, len <<= 1) {
      if (l & 1) {
        Line line(a, b);
        add(line, l++, node_l, node_l + len);
        node_l += len;
      }
      if (r & 1) {
        Line line(a, b);
        node_r -= len;
        add(line, --r, node_r, node_r + len);
      }
    }
  }

  T query(T x) const {
    int node = std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), x));
    node += n;
    T res = dat[node].f(x);
    while (node >>= 1) {
      if (dat[node].f(x) < res) res = dat[node].f(x);
    }
    return is_minimized ? res : -res;
  }

private:
  bool is_minimized;
  int n = 1;
  std::vector<T> xs;
  std::vector<Line> dat;

  void add(Line &line, int node, int left, int right) {
    bool l = dat[node].f(xs[left]) <= line.f(xs[left]), r = dat[node].f(xs[right - 1]) <= line.f(xs[right - 1]);
    if (l && r) return;
    if (!l && !r) {
      std::swap(dat[node], line);
      return;
    }
    int mid = (left + right) >> 1;
    if (line.f(xs[mid]) < dat[node].f(xs[mid])) std::swap(dat[node], line);
    if (line.f(xs[left]) <= dat[node].f(xs[left])) {
      add(line, node << 1, left, mid);
    } else {
      add(line, (node << 1) + 1, mid, right);
    }
  }
};
