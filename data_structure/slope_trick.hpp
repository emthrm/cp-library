#pragma once
#include <cassert>
#include <functional>
#include <limits>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

template <typename T>
struct SlopeTrick {
  const T inf;

  explicit SlopeTrick(
      const T min_f = 0, const T inf = std::numeric_limits<T>::max())
      : added_l(0), added_r(0), min_f(min_f), inf(inf) {}

  T min() const { return min_f; }
  std::pair<T, T> argmin() const { return {top_l(), top_r()}; }

  template <typename U>
  U f(const U x) {
    U f_x = min_f;
    std::vector<T> tmp;
    for (; top_l() > x; l.pop()) {
      const T t = top_l();
      f_x += t - x;
      tmp.emplace_back(t);
    }
    for (; !tmp.empty(); tmp.pop_back()) {
      emplace_l(tmp.back());
    }
    for (; top_r() < x; r.pop()) {
      const T t = top_r();
      f_x += x - t;
      tmp.emplace_back(t);
    }
    for (; !tmp.empty(); tmp.pop_back()) {
      emplace_r(tmp.back());
    }
    return f_x;
  }

  void constant_function(const T c) { min_f += c; }

  void x_minus_a(const T a) {
    const T t = top_l();
    if (t <= a) {
      emplace_r(a);
    } else {
      min_f += t - a;
      emplace_l(a);
      l.pop();
      emplace_r(t);
    }
  }

  void a_minus_x(const T a) {
    const T t = top_r();
    if (a <= t) {
      emplace_l(a);
    } else {
      min_f += a - t;
      emplace_r(a);
      r.pop();
      emplace_l(t);
    }
  }

  void abs_x_minus_a(const T a) {
    x_minus_a(a);
    a_minus_x(a);
  }

  void cumulative_min() {
    while (!r.empty()) r.pop();
    added_r = 0;
  }

  void rcumulative_min() {
    while (!l.empty()) l.pop();
    added_l = 0;
  }

  void translate(const T a) { sliding_window_minimum(a, a); }

  void sliding_window_minimum(const T a, const T b) {
    assert(a <= b);
    added_l += a;
    added_r += b;
  }

private:
  T added_l, added_r, min_f;
  std::priority_queue<T> l;
  std::priority_queue<T, std::vector<T>, std::greater<T>> r;

  void emplace_l(const T a) { l.emplace(a - added_l); }
  void emplace_r(const T a) { r.emplace(a - added_r); }

  T top_l() const { return l.empty() ? -inf : l.top() + added_l; }
  T top_r() const { return r.empty() ? inf : r.top() + added_r; }
};
