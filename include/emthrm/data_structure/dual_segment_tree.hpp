#ifndef EMTHRM_DATA_STRUCTURE_DUAL_SEGMENT_TREE_HPP_
#define EMTHRM_DATA_STRUCTURE_DUAL_SEGMENT_TREE_HPP_

#include <bit>
#include <concepts>
#include <cstdint>
#include <optional>
#include <utility>
#include <vector>

namespace emthrm {

template <typename T>
requires requires {
  typename T::Elem;
  typename T::OperatorMonoid;
  {T::id()} -> std::same_as<typename T::OperatorMonoid>;
  {T::merge(std::declval<typename T::OperatorMonoid>(),
            std::declval<typename T::OperatorMonoid>())}
      -> std::same_as<typename T::OperatorMonoid>;
  {T::apply(std::declval<typename T::Elem>(),
            std::declval<typename T::OperatorMonoid>())}
      -> std::same_as<typename T::Elem>;
}
struct DualSegmentTree {
  using Elem = typename T::Elem;
  using OperatorMonoid = typename T::OperatorMonoid;

  explicit DualSegmentTree(const std::vector<Elem>& data)
      : n(data.size()), height(std::countr_zero(std::bit_ceil(data.size()))),
        p2(1 << height), data(data), lazy(p2, T::id()) {}

  void set(const int idx, const Elem val) {
    propagate_line(idx);
    data[idx] = val;
  }

  void apply(const int idx, const OperatorMonoid val) {
    propagate_line(idx);
    data[idx] = T::apply(data[idx], val);
  }

  void apply(int left, int right, const OperatorMonoid val) {
    if (right <= left) [[unlikely]] return;
    propagate_line(left, std::countr_zero(static_cast<unsigned int>(left)));
    propagate_line(right, std::countr_zero(static_cast<unsigned int>(right)));
    left += p2;
    right += p2;
    if (left & 1) {
      data[left - p2] = T::apply(data[left - p2], val);
      ++left;
    }
    if (right & 1) {
      --right;
      data[right - p2] = T::apply(data[right - p2], val);
    }
    for (left >>= 1, right >>= 1; left < right; left >>= 1, right >>= 1) {
      if (left & 1) {
        lazy[left] = T::merge(lazy[left], val);
        ++left;
      }
      if (right & 1) {
        --right;
        lazy[right] = T::merge(lazy[right], val);
      }
    }
  }

  Elem operator[](const int idx) {
    propagate_line(idx);
    return data[idx];
  }

 private:
  const int n, height, p2;
  std::vector<Elem> data;
  std::vector<OperatorMonoid> lazy;

  void propagate(const int idx) {
    if (lazy[idx] == T::id()) return;
    const int child = idx << 1;
    if (child >= p2) {
      if (child - p2 < n) {
        data[child - p2] = T::apply(data[child - p2], lazy[idx]);
        if (child - p2 + 1 < n) {
          data[child - p2 + 1] = T::apply(data[child - p2 + 1], lazy[idx]);
        }
      }
    } else {
      lazy[child] = T::merge(lazy[child], lazy[idx]);
      lazy[child + 1] = T::merge(lazy[child + 1], lazy[idx]);
    }
    lazy[idx] = T::id();
  }

  void propagate_line(const int idx, const int until = 0) {
    const int node = idx + p2;
    for (int i = height; i > until; --i) {
      propagate(node >> i);
    }
  }
};

namespace monoid {

template <typename T>
struct RangeUpdateQuery {
  using Elem = T;
  using OperatorMonoid = std::optional<Elem>;
  static constexpr OperatorMonoid id() { return std::nullopt; }
  static OperatorMonoid merge(const OperatorMonoid& a,
                              const OperatorMonoid& b) {
    return b.has_value() ? b : a;
  }
  static Elem apply(const Elem& a, const OperatorMonoid& b) {
    return b.has_value() ? b.value() : a;
  }
};

template <typename T>
struct RangeAddQuery {
  using Elem = T;
  using OperatorMonoid = T;
  static constexpr OperatorMonoid id() { return 0; }
  static OperatorMonoid merge(const OperatorMonoid& a,
                              const OperatorMonoid& b) {
    return a + b;
  }
  static Elem apply(const Elem& a, const OperatorMonoid& b) { return a + b; }
};

}  // namespace monoid

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_DUAL_SEGMENT_TREE_HPP_
