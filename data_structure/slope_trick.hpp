#pragma once
#include <cassert>
#include <functional>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

template <typename T>
struct SlopeTrick {
  const T inf;

  SlopeTrick(T min_f = 0, const T inf = std::numeric_limits<T>::max()) : min_f(min_f), inf(inf) {}

  T min() const { return min_f; }

  std::pair<T, T> argmin() const { return {top_l(), top_r()}; }

  template <typename U>
  U f(U x) {
    U f_x = min_f;
    std::vector<T> tmp;
    while (top_l() > x) {
      T t = top_l();
      f_x += t - x;
      tmp.emplace_back(t);
      l.pop();
    }
    while (!tmp.empty()) {
      emplace_l(tmp.back());
      tmp.pop_back();
    }
    while (top_r() < x) {
      T t = top_r();
      f_x += x - t;
      tmp.emplace_back(t);
      r.pop();
    }
    while (!tmp.empty()) {
      emplace_r(tmp.back());
      tmp.pop_back();
    }
    return f_x;
  }

  void constant_function(T c) { min_f += c; }

  void x_minus_a(T a) {
    T t = top_l();
    if (t <= a) {
      emplace_r(a);
    } else {
      min_f += t - a;
      emplace_l(a);
      l.pop();
      emplace_r(t);
    }
  }

  void a_minus_x(T a) {
    T t = top_r();
    if (a <= t) {
      emplace_l(a);
    } else {
      min_f += a - t;
      emplace_r(a);
      r.pop();
      emplace_l(t);
    }
  }

  void abs_x_minus_a(T a) {
    x_minus_a(a);
    a_minus_x(a);
  }

  void cumulative_min() {
    while (!r.empty()) r.pop();
    add_r = 0;
  }

  void rcumulative_min() {
    while (!l.empty()) l.pop();
    add_l = 0;
  }

  void translate(T a) { sliding_window_minimum(a, a); }

  void sliding_window_minimum(T a, T b) {
    assert(a <= b);
    add_l += a;
    add_r += b;
  }

private:
  T add_l = 0, add_r = 0, min_f;
  std::priority_queue<T> l;
  std::priority_queue<T, std::vector<T>, std::greater<T>> r;

  void emplace_l(T a) { l.emplace(a - add_l); }

  void emplace_r(T a) { r.emplace(a - add_r); }

  T top_l() const { return l.empty() ? -inf : l.top() + add_l; }

  T top_r() const { return r.empty() ? inf : r.top() + add_r; }
};
