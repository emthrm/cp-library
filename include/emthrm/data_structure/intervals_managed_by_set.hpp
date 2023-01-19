#ifndef EMTHRM_DATA_STRUCTURE_INTERVALS_MANAGED_BY_SET_HPP_
#define EMTHRM_DATA_STRUCTURE_INTERVALS_MANAGED_BY_SET_HPP_

#include <cassert>
#include <iostream>
#include <iterator>
#include <limits>
#include <set>
#if __cplusplus < 201703L
#include <tuple>
#endif
#include <utility>

namespace emthrm {

template <typename T>
struct IntervalsManagedBySet {
  using IntervalsType = std::set<std::pair<T, T>>;
  IntervalsType intervals{
      {std::numeric_limits<T>::lowest(), std::numeric_limits<T>::lowest()},
      {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()}};

  IntervalsManagedBySet() = default;

  bool contains(const T x) const { return contains(x, x); }

  bool contains(const T left, const T right) const {
    return find(left, right) != intervals.end();
  }

  std::pair<typename IntervalsType::const_iterator, bool> erase(const T x) {
    typename IntervalsType::const_iterator it = intervals.lower_bound({x, x});
    if (it->first == x) {
      const T right = it->second;
      it = intervals.erase(it);
      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;
    } else {
      it = std::prev(it);
#if __cplusplus >= 201703L
      const auto [left, right] = *it;
#else
      T left, right;
      std::tie(left, right) = *it;
#endif
      if (right < x) return {std::next(it), false};
      intervals.erase(it);
      it = std::next(intervals.emplace(left, x - 1).first);
      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;
    }
    return {it, true};
  }

  std::pair<typename IntervalsType::const_iterator, T> erase(
      const T left, const T right) {
    assert(left <= right);
    typename IntervalsType::const_iterator it =
        intervals.lower_bound({left, left});
    T res = 0;
    for (; it->second <= right; it = intervals.erase(it)) {
      res += it->second - it->first + 1;
    }
    if (it->first <= right) {
      res += right - it->first + 1;
      const T r = it->second;
      intervals.erase(it);
      it = intervals.emplace(right + 1, r).first;
    }
    if (left <= std::prev(it)->second) {
      it = std::prev(it);
#if __cplusplus >= 201703L
      const auto [l, r] = *it;
#else
      T l, r;
      std::tie(l, r) = *it;
#endif
      intervals.erase(it);
      if (right < r) {
        res += right - left + 1;
        intervals.emplace(right + 1, r);
      } else {
        res += r - left + 1;
      }
      it = std::next(intervals.emplace(l, left - 1).first);
    }
    return {it, res};
  }

  typename IntervalsType::const_iterator find(const T x) const {
    return find(x, x);
  }

  typename IntervalsType::const_iterator find(
      const T left, const T right) const {
    typename IntervalsType::const_iterator it =
        intervals.lower_bound({left, left});
    if (left < it->first) it = std::prev(it);
    return it->first <= left && right <= it->second ? it : intervals.end();
  }

  std::pair<typename IntervalsType::const_iterator, bool> insert(const T x) {
    typename IntervalsType::const_iterator it = intervals.lower_bound({x, x});
    if (it->first == x) return {it, false};
    if (x <= std::prev(it)->second) return {std::prev(it), false};
    T left = x, right = x;
    if (x + 1 == it->first) {
      right = it->second;
      it = intervals.erase(it);
    }
    if (std::prev(it)->second == x - 1) {
      it = std::prev(it);
      left = it->first;
      intervals.erase(it);
    }
    return {intervals.emplace(left, right).first, true};
  }

  std::pair<typename IntervalsType::const_iterator, T> insert(T left, T right) {
    assert(left <= right);
    typename IntervalsType::const_iterator it =
        intervals.lower_bound({left, left});
    if (left <= std::prev(it)->second) {
      it = std::prev(it);
      left = it->first;
    }
    T res = 0;
    if (left == it->first && right <= it->second) return {it, res};
    for (; it->second <= right; it = intervals.erase(it)) {
      res -= it->second - it->first + 1;
    }
    if (it->first <= right) {
      res -= it->second - it->first + 1;
      right = it->second;
      it = intervals.erase(it);
    }
    res += right - left + 1;
    if (right + 1 == it->first) {
      right = it->second;
      it = intervals.erase(it);
    }
    if (std::prev(it)->second == left - 1) {
      it = std::prev(it);
      left = it->first;
      intervals.erase(it);
    }
    return {intervals.emplace(left, right).first, res};
  }

  T mex(const T x = 0) const {
    auto it = intervals.lower_bound({x, x});
    if (x <= std::prev(it)->second) it = std::prev(it);
    return x < it->first ? x : it->second + 1;
  }

  friend std::ostream& operator<<(std::ostream& os,
                                  const IntervalsManagedBySet& x) {
    if (x.intervals.size() == 2) return os;
    auto it = next(x.intervals.begin());
    while (true) {
      os << '[' << it->first << ", " << it->second << ']';
      it = next(it);
      if (next(it) == x.intervals.end()) break;
      os << ' ';
    }
    return os;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_INTERVALS_MANAGED_BY_SET_HPP_
