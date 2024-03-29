#ifndef EMTHRM_DYNAMIC_PROGRAMMING_CONVEX_HULL_TRICK_HPP_
#define EMTHRM_DYNAMIC_PROGRAMMING_CONVEX_HULL_TRICK_HPP_

#include <cassert>
#include <deque>
#include <iterator>
#include <numeric>
#include <utility>

namespace emthrm {

template <typename T, bool IS_MINIMIZED = true>
struct ConvexHullTrick {
  ConvexHullTrick() = default;

  void add(T a, T b) {
    if constexpr (!IS_MINIMIZED) {
      a = -a;
      b = -b;
    }
    const Line line(a, b);
    if (deq.empty()) [[unlikely]] {
      deq.emplace_back(line);
    } else if (deq.back().first >= a) {
      if (deq.back().first == a) {
        if (b >= deq.back().second) return;
        deq.pop_back();
      }
      for (int i = std::ssize(deq) - 2; i >= 0; --i) {
        if (!must_pop(deq[i], deq[i + 1], line)) break;
        deq.pop_back();
      }
      deq.emplace_back(line);
    } else {
      if (deq.front().first == a) {
        if (b >= deq.front().second) return;
        deq.pop_front();
      }
      while (deq.size() >= 2 && must_pop(line, deq.front(), deq[1])) {
        deq.pop_front();
      }
      deq.emplace_front(line);
    }
  }

  T query(const T x) const {
    assert(!deq.empty());
    int lb = -1, ub = deq.size() - 1;
    while (ub - lb > 1) {
      const int mid = std::midpoint(lb, ub);
      (f(deq[mid], x) < f(deq[mid + 1], x) ? ub : lb) = mid;
    }
    return IS_MINIMIZED ? f(deq[ub], x) : -f(deq[ub], x);
  }

  T monotonically_increasing_query(const T x) {
    while (deq.size() >= 2 && f(deq.front(), x) >= f(deq[1], x)) {
      deq.pop_front();
    }
    return IS_MINIMIZED ? f(deq.front(), x) : -f(deq.front(), x);
  }

  T monotonically_decreasing_query(const T x) {
    for (int i = std::ssize(deq) - 2; i >= 0; --i) {
      if (f(deq[i], x) > f(deq[i + 1], x)) break;
      deq.pop_back();
    }
    return IS_MINIMIZED ? f(deq.back(), x) : -f(deq.back(), x);
  }

 private:
  using Line = std::pair<T, T>;

  std::deque<Line> deq;

  bool must_pop(const Line& l1, const Line& l2, const Line& l3) const {
#ifdef __SIZEOF_INT128__
    const T lhs_num = l3.second - l2.second, lhs_den = l2.first - l3.first;
    const T rhs_num = l2.second - l1.second, rhs_den = l1.first - l2.first;
    return __int128{lhs_num} * rhs_den <= __int128{rhs_num} * lhs_den;
#else
    const long double lhs =
        static_cast<long double>(l3.second - l2.second) / (l2.first - l3.first);
    const long double rhs =
        static_cast<long double>(l2.second - l1.second) / (l1.first - l2.first);
    return lhs <= rhs;
#endif  // __SIZEOF_INT128__
  }

  T f(const Line& l, const T x) const { return l.first * x + l.second; }
};

}  // namespace emthrm

#endif  // EMTHRM_DYNAMIC_PROGRAMMING_CONVEX_HULL_TRICK_HPP_
