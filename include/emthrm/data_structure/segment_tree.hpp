/**
 * @brief セグメント木
 * @docs docs/data_structure/segment_tree.md
 */

#ifndef EMTHRM_DATA_STRUCTURE_SEGMENT_TREE_HPP_
#define EMTHRM_DATA_STRUCTURE_SEGMENT_TREE_HPP_

#include <algorithm>
#include <limits>
#include <vector>

namespace emthrm {

template <typename T>
struct SegmentTree {
  using Monoid = typename T::Monoid;

  explicit SegmentTree(int n) : SegmentTree(std::vector<Monoid>(n, T::id())) {}

  explicit SegmentTree(const std::vector<Monoid>& a) : n(a.size()), p2(1) {
    while (p2 < n) p2 <<= 1;
    dat.assign(p2 << 1, T::id());
    std::copy(a.begin(), a.end(), dat.begin() + p2);
    for (int i = p2 - 1; i > 0; --i) {
      dat[i] = T::merge(dat[i << 1], dat[(i << 1) + 1]);
    }
  }

  void set(int idx, const Monoid val) {
    idx += p2;
    dat[idx] = val;
    while (idx >>= 1) dat[idx] = T::merge(dat[idx << 1], dat[(idx << 1) + 1]);
  }

  Monoid get(int left, int right) const {
    Monoid res_l = T::id(), res_r = T::id();
    for (left += p2, right += p2; left < right; left >>= 1, right >>= 1) {
      if (left & 1) res_l = T::merge(res_l, dat[left++]);
      if (right & 1) res_r = T::merge(dat[--right], res_r);
    }
    return T::merge(res_l, res_r);
  }

  Monoid operator[](const int idx) const { return dat[idx + p2]; }

  template <typename G>
  int find_right(int left, const G g) {
    if (left >= n) return n;
    Monoid val = T::id();
    left += p2;
    do {
      while (!(left & 1)) left >>= 1;
      Monoid nxt = T::merge(val, dat[left]);
      if (!g(nxt)) {
        while (left < p2) {
          left <<= 1;
          nxt = T::merge(val, dat[left]);
          if (g(nxt)) {
            val = nxt;
            ++left;
          }
        }
        return left - p2;
      }
      val = nxt;
      ++left;
    } while (__builtin_popcount(left) > 1);
    return n;
  }

  template <typename G>
  int find_left(int right, const G g) {
    if (right <= 0) return -1;
    Monoid val = T::id();
    right += p2;
    do {
      --right;
      while (right > 1 && (right & 1)) right >>= 1;
      Monoid nxt = T::merge(dat[right], val);
      if (!g(nxt)) {
        while (right < p2) {
          right = (right << 1) + 1;
          nxt = T::merge(dat[right], val);
          if (g(nxt)) {
            val = nxt;
            --right;
          }
        }
        return right - p2;
      }
      val = nxt;
    } while (__builtin_popcount(right) > 1);
    return -1;
  }

 private:
  const int n;
  int p2;
  std::vector<Monoid> dat;
};

namespace monoid {

template <typename T>
struct RangeMinimumQuery {
  using Monoid = T;
  static constexpr Monoid id() { return std::numeric_limits<Monoid>::max(); }
  static Monoid merge(const Monoid& a, const Monoid& b) {
    return std::min(a, b);
  }
};

template <typename T>
struct RangeMaximumQuery {
  using Monoid = T;
  static constexpr Monoid id() { return std::numeric_limits<Monoid>::lowest(); }
  static Monoid merge(const Monoid& a, const Monoid& b) {
    return std::max(a, b);
  }
};

template <typename T>
struct RangeSumQuery {
  using Monoid = T;
  static constexpr Monoid id() { return 0; }
  static Monoid merge(const Monoid& a, const Monoid& b) { return a + b; }
};

}  // namespace monoid

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_SEGMENT_TREE_HPP_
