#ifndef EMTHRM_DYNAMIC_PROGRAMMING_LI_CHAO_TREE_HPP_
#define EMTHRM_DYNAMIC_PROGRAMMING_LI_CHAO_TREE_HPP_

#include <algorithm>
#include <cassert>
#include <iterator>
#include <utility>
#include <vector>

namespace emthrm {

template <typename T, bool IS_MINIMIZED = true>
struct LiChaoTree {
  struct Line {
    T a, b;
    explicit Line(const T a, const T b) : a(a), b(b) {}
    T f(const T x) const { return a * x + b; }
  };

  explicit LiChaoTree(const std::vector<T>& xs_, const T inf) : n(1), xs(xs_) {
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    const int xs_size = xs.size();
    assert(xs_size > 0);
    while (n < xs_size) n <<= 1;
    const T xs_back = xs.back();
    xs.resize(n, xs_back);
    dat.assign(n << 1, Line(0, inf));
  }

  void add(T a, T b) {
#if __cplusplus >= 201703L
    if constexpr (!IS_MINIMIZED) {
#else
    if (!IS_MINIMIZED) {
#endif
      a = -a;
      b = -b;
    }
    Line line(a, b);
    add(&line, 1, 0, n);
  }

  void add(T a, T b, T left, T right) {
#if __cplusplus >= 201703L
    if constexpr (!IS_MINIMIZED) {
#else
    if (!IS_MINIMIZED) {
#endif
      a = -a;
      b = -b;
    }
    for (int len = 1,
             node_l = std::distance(
                 xs.begin(), std::lower_bound(xs.begin(), xs.end(), left)),
             node_r = std::distance(
                 xs.begin(), std::lower_bound(xs.begin(), xs.end(), right)),
             l = node_l + n, r = node_r + n;
         l < r;
         l >>= 1, r >>= 1, len <<= 1) {
      if (l & 1) {
        Line line(a, b);
        add(&line, l++, node_l, node_l + len);
        node_l += len;
      }
      if (r & 1) {
        Line line(a, b);
        node_r -= len;
        add(&line, --r, node_r, node_r + len);
      }
    }
  }

  T query(const T x) const {
    int node = n + std::distance(xs.begin(),
                                 std::lower_bound(xs.begin(), xs.end(), x));
    T res = dat[node].f(x);
    while (node >>= 1) {
      if (dat[node].f(x) < res) res = dat[node].f(x);
    }
    return IS_MINIMIZED ? res : -res;
  }

 private:
  int n;
  std::vector<T> xs;
  std::vector<Line> dat;

  void add(Line* line, int node, int left, int right) {
    const bool flag_l = dat[node].f(xs[left]) <= line->f(xs[left]);
    const bool flag_r = dat[node].f(xs[right - 1]) <= line->f(xs[right - 1]);
    if (flag_l && flag_r) return;
    if (!flag_l && !flag_r) {
      std::swap(dat[node], *line);
      return;
    }
    const int mid = (left + right) >> 1;
    if (line->f(xs[mid]) < dat[node].f(xs[mid])) std::swap(dat[node], *line);
    if (line->f(xs[left]) <= dat[node].f(xs[left])) {
      add(line, node << 1, left, mid);
    } else {
      add(line, (node << 1) + 1, mid, right);
    }
  }
};

}  // namespace emthrm

#endif  // EMTHRM_DYNAMIC_PROGRAMMING_LI_CHAO_TREE_HPP_
