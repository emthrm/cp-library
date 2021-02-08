#pragma once
#include <deque>
#include <utility>

template <typename T>
struct CHT {
  CHT(bool is_minimized = true) : is_minimized(is_minimized) {}

  void add(T a, T b) {
    Line now(a, b);
    if (deq.empty()) {
      deq.emplace_back(now);
    } else if (deq.back().first <= a) {
      if (deq.back().first == a) {
        if (is_minimized) {
          if (b >= deq.back().second) return;
          deq.pop_back();
        } else {
          if (b <= deq.back().second) return;
          deq.pop_back();
        }
      }
      while (deq.size() >= 2 && !is_necessary(deq[deq.size() - 2], deq.back(), now)) deq.pop_back();
      deq.emplace_back(now);
    } else {
      if (deq.front().first == a) {
        if (is_minimized) {
          if (b >= deq.front().second) return;
          deq.pop_front();
        } else {
          if (b <= deq.front().second) return;
          deq.pop_front();
        }
      }
      while (deq.size() >= 2 && !is_necessary(now, deq[0], deq[1])) deq.pop_front();
      deq.emplace_front(now);
    }
  }

  T query(T x) const {
    int lb = -1, ub = deq.size() - 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      if (is_minimized) {
        (f(deq[mid], x) < f(deq[mid + 1], x) ? ub : lb) = mid;
      } else {
        (f(deq[mid], x) > f(deq[mid + 1], x) ? ub : lb) = mid;
      }
    }
    return f(deq[ub], x);
  }

  T monotone_inc_query(T x) {
    if (is_minimized) {
      while (deq.size() >= 2 && f(deq[deq.size() - 2], x) <= f(deq.back(), x)) deq.pop_back();
      return f(deq.back(), x);
    } else {
      while (deq.size() >= 2 && f(deq[0], x) <= f(deq[1], x)) deq.pop_front();
      return f(deq.front(), x);
    }
  }

  T monotone_dec_query(T x) {
    if (is_minimized) {
      while (deq.size() >= 2 && f(deq[0], x) >= f(deq[1], x)) deq.pop_front();
      return f(deq.front(), x);
    } else {
      while (deq.size() >= 2 && f(deq[deq.size() - 2], x) >= f(deq.back(), x)) deq.pop_back();
      return f(deq.back(), x);
    }
  }

private:
  using Line = std::pair<T, T>;

  bool is_minimized;
  std::deque<Line> deq;

  using Real = long double;
  bool is_necessary(const Line &l1, const Line &l2, const Line &l3) const {
    Real lhs = static_cast<Real>(l3.second - l2.second) / (l2.first - l3.first);
    Real rhs = static_cast<Real>(l2.second - l1.second) / (l1.first - l2.first);
    return is_minimized ? lhs < rhs : lhs > rhs;
    // T lhs_num = l3.second - l2.second, lhs_den = l2.first - l3.first;
    // if (lhs_den < 0) {
    //   lhs_num = -lhs_num;
    //   lhs_den = -lhs_den;
    // }
    // T rhs_num = l2.second - l1.second, rhs_den = l1.first - l2.first;
    // if (rhs_den < 0) {
    //   rhs_num = -rhs_num;
    //   rhs_den = -rhs_den;
    // }
    // return is_minimized ? lhs_num * rhs_den < rhs_num * lhs_den : lhs_num * rhs_den > rhs_num * lhs_den;
  }

  T f(const Line &l, T x) const { return l.first * x + l.second; }
};
