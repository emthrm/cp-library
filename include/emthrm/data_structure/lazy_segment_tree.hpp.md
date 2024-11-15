---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/lazy_segment_tree.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_minimum_query_and_range_add_query.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (range minimum query and range add query)"
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_minimum_query_and_range_update_query.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (range minimum query and range update query)"
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_sum_query_and_range_add_query.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (range sum query and range add query)"
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_sum_query_and_range_update_query.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (range sum query and range update query)"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 Euler tour\
      \ technique \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/data_structure/lazy_segment_tree.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <bit>\n// #include <cassert>\n#include <limits>\n\
    #include <type_traits>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ T>\nrequires requires {\n  typename T::Monoid;\n  typename T::OperatorMonoid;\n\
    \  {T::m_id()} -> std::same_as<typename T::Monoid>;\n  {T::o_id()} -> std::same_as<typename\
    \ T::OperatorMonoid>;\n  {T::m_merge(std::declval<typename T::Monoid>(),\n   \
    \           std::declval<typename T::Monoid>())}\n      -> std::same_as<typename\
    \ T::Monoid>;\n  {T::o_merge(std::declval<typename T::OperatorMonoid>(),\n   \
    \           std::declval<typename T::OperatorMonoid>())}\n      -> std::same_as<typename\
    \ T::OperatorMonoid>;\n  {T::apply(std::declval<typename T::Monoid>(),\n     \
    \       std::declval<typename T::OperatorMonoid>())}\n      -> std::same_as<typename\
    \ T::Monoid>;\n}\nstruct LazySegmentTree {\n  using Monoid = typename T::Monoid;\n\
    \  using OperatorMonoid = typename T::OperatorMonoid;\n\n  explicit LazySegmentTree(const\
    \ int n)\n      : LazySegmentTree(std::vector<Monoid>(n, T::m_id())) {}\n\n  explicit\
    \ LazySegmentTree(const std::vector<Monoid>& a)\n      : n(a.size()), height(std::countr_zero(std::bit_ceil(a.size()))),\n\
    \        p2(1 << height) {\n    lazy.assign(p2, T::o_id());\n    data.assign(p2\
    \ << 1, T::m_id());\n    std::copy(a.begin(), a.end(), data.begin() + p2);\n \
    \   for (int i = p2 - 1; i > 0; --i) {\n      data[i] = T::m_merge(data[i << 1],\
    \ data[(i << 1) + 1]);\n    }\n  }\n\n  void set(int idx, const Monoid val) {\n\
    \    idx += p2;\n    for (int i = height; i > 0; --i) {\n      propagate(idx >>\
    \ i);\n    }\n    data[idx] = val;\n    for (int i = 1; i <= height; ++i) {\n\
    \      const int current_idx = idx >> i;\n      data[current_idx] =\n        \
    \  T::m_merge(data[current_idx << 1], data[(current_idx << 1) + 1]);\n    }\n\
    \  }\n\n  void apply(int idx, const OperatorMonoid val) {\n    idx += p2;\n  \
    \  for (int i = height; i > 0; --i) {\n      propagate(idx >> i);\n    }\n   \
    \ data[idx] = T::apply(data[idx], val);\n    for (int i = 1; i <= height; ++i)\
    \ {\n      const int current_idx = idx >> i;\n      data[current_idx] =\n    \
    \      T::m_merge(data[current_idx << 1], data[(current_idx << 1) + 1]);\n   \
    \ }\n  }\n\n  void apply(int left, int right, const OperatorMonoid val) {\n  \
    \  if (right <= left) [[unlikely]] return;\n    left += p2;\n    right += p2;\n\
    \    const int ctz_left = std::countr_zero(static_cast<unsigned int>(left));\n\
    \    for (int i = height; i > ctz_left; --i) {\n      propagate(left >> i);\n\
    \    }\n    const int ctz_right = std::countr_zero(static_cast<unsigned int>(right));\n\
    \    for (int i = height; i > ctz_right; --i) {\n      propagate(right >> i);\n\
    \    }\n    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) apply_sub(l++, val);\n      if (r & 1) apply_sub(--r, val);\n    }\n\
    \    for (int i = left >> (ctz_left + 1); i > 0; i >>= 1) {\n      data[i] = T::m_merge(data[i\
    \ << 1], data[(i << 1) + 1]);\n    }\n    for (int i = right >> (ctz_right + 1);\
    \ i > 0; i >>= 1) {\n      data[i] = T::m_merge(data[i << 1], data[(i << 1) +\
    \ 1]);\n    }\n  }\n\n  Monoid get(int left, int right) {\n    if (right <= left)\
    \ [[unlikely]] return T::m_id();\n    left += p2;\n    right += p2;\n    const\
    \ int ctz_left = std::countr_zero(static_cast<unsigned int>(left));\n    for (int\
    \ i = height; i > ctz_left; --i) {\n      propagate(left >> i);\n    }\n    const\
    \ int ctz_right = std::countr_zero(static_cast<unsigned int>(right));\n    for\
    \ (int i = height; i > ctz_right; --i) {\n      propagate(right >> i);\n    }\n\
    \    Monoid res_l = T::m_id(), res_r = T::m_id();\n    for (; left < right; left\
    \ >>= 1, right >>= 1) {\n      if (left & 1) res_l = T::m_merge(res_l, data[left++]);\n\
    \      if (right & 1) res_r = T::m_merge(data[--right], res_r);\n    }\n    return\
    \ T::m_merge(res_l, res_r);\n  }\n\n  Monoid operator[](const int idx) {\n   \
    \ const int node = idx + p2;\n    for (int i = height; i > 0; --i) {\n      propagate(node\
    \ >> i);\n    }\n    return data[node];\n  }\n\n  template <typename G>\n  int\
    \ find_right(int left, const G g) {\n    if (left >= n) [[unlikely]] return n;\n\
    \    left += p2;\n    for (int i = height; i > 0; --i) {\n      propagate(left\
    \ >> i);\n    }\n    Monoid val = T::m_id();\n    do {\n      while (!(left &\
    \ 1)) left >>= 1;\n      Monoid nxt = T::m_merge(val, data[left]);\n      if (!g(nxt))\
    \ {\n        while (left < p2) {\n          propagate(left);\n          left <<=\
    \ 1;\n          nxt = T::m_merge(val, data[left]);\n          if (g(nxt)) {\n\
    \            val = nxt;\n            ++left;\n          }\n        }\n       \
    \ return left - p2;\n      }\n      val = nxt;\n      ++left;\n    } while (!std::has_single_bit(static_cast<unsigned\
    \ int>(left)));\n    return n;\n  }\n\n  template <typename G>\n  int find_left(int\
    \ right, const G g) {\n    if (right <= 0) [[unlikely]] return -1;\n    right\
    \ += p2;\n    for (int i = height; i > 0; --i) {\n      propagate((right - 1)\
    \ >> i);\n    }\n    Monoid val = T::m_id();\n    do {\n      --right;\n     \
    \ while (right > 1 && (right & 1)) right >>= 1;\n      Monoid nxt = T::m_merge(data[right],\
    \ val);\n      if (!g(nxt)) {\n        while (right < p2) {\n          propagate(right);\n\
    \          right = (right << 1) + 1;\n          nxt = T::m_merge(data[right],\
    \ val);\n          if (g(nxt)) {\n            val = nxt;\n            --right;\n\
    \          }\n        }\n        return right - p2;\n      }\n      val = nxt;\n\
    \    } while (!std::has_single_bit(static_cast<unsigned int>(right)));\n    return\
    \ -1;\n  }\n\n private:\n  const int n, height, p2;\n  std::vector<Monoid> data;\n\
    \  std::vector<OperatorMonoid> lazy;\n\n  void apply_sub(const int idx, const\
    \ OperatorMonoid& val) {\n    data[idx] = T::apply(data[idx], val);\n    if (idx\
    \ < p2) lazy[idx] = T::o_merge(lazy[idx], val);\n  }\n\n  void propagate(const\
    \ int idx) {\n    // assert(1 <= idx && idx < p2);\n    apply_sub(idx << 1, lazy[idx]);\n\
    \    apply_sub((idx << 1) + 1, lazy[idx]);\n    lazy[idx] = T::o_id();\n  }\n\
    };\n\nnamespace monoid {\n\ntemplate <typename T>\nstruct RangeMinimumAndUpdateQuery\
    \ {\n  using Monoid = T;\n  using OperatorMonoid = T;\n  static constexpr Monoid\
    \ m_id() { return std::numeric_limits<Monoid>::max(); }\n  static constexpr OperatorMonoid\
    \ o_id() {\n    return std::numeric_limits<OperatorMonoid>::max();\n  }\n  static\
    \ Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return std::min(a, b);\n\
    \  }\n  static OperatorMonoid o_merge(const OperatorMonoid& a,\n             \
    \                   const OperatorMonoid& b) {\n    return b == o_id() ? a : b;\n\
    \  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {\n    return\
    \ b == o_id() ? a : b;\n  }\n};\n\ntemplate <typename T>\nstruct RangeMaximumAndUpdateQuery\
    \ {\n  using Monoid = T;\n  using OperatorMonoid = T;\n  static constexpr Monoid\
    \ m_id() {\n    return std::numeric_limits<Monoid>::lowest();\n  }\n  static constexpr\
    \ OperatorMonoid o_id() {\n    return std::numeric_limits<OperatorMonoid>::lowest();\n\
    \  }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return\
    \ std::max(a, b);\n  }\n  static OperatorMonoid o_merge(const OperatorMonoid&\
    \ a,\n                                const OperatorMonoid& b) {\n    return b\
    \ == o_id() ? a : b;\n  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid&\
    \ b) {\n    return b == o_id()? a : b;\n  }\n};\n\ntemplate <typename T, T Inf>\n\
    struct RangeMinimumAndAddQuery {\n  using Monoid = T;\n  using OperatorMonoid\
    \ = T;\n  static constexpr Monoid m_id() { return Inf; }\n  static constexpr OperatorMonoid\
    \ o_id() { return 0; }\n  static Monoid m_merge(const Monoid& a, const Monoid&\
    \ b) {\n    return std::min(a, b);\n  }\n  static OperatorMonoid o_merge(const\
    \ OperatorMonoid& a,\n                                const OperatorMonoid& b)\
    \ {\n    return a + b;\n  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid&\
    \ b) {\n    return a + b;\n  }\n};\n\ntemplate <typename T, T Inf>\nstruct RangeMaximumAndAddQuery\
    \ {\n  using Monoid = T;\n  using OperatorMonoid = T;\n  static constexpr Monoid\
    \ m_id() { return -Inf; }\n  static constexpr OperatorMonoid o_id() { return 0;\
    \ }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return std::max(a,\
    \ b);\n  }\n  static OperatorMonoid o_merge(const OperatorMonoid& a,\n       \
    \                         const OperatorMonoid& b) {\n    return a + b;\n  }\n\
    \  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {\n    return\
    \ a + b;\n  }\n};\n\ntemplate <typename T>\nstruct RangeSumAndUpdateQuery {\n\
    \  using Monoid = struct { T sum; int len; };\n  using OperatorMonoid = T;\n \
    \ static std::vector<Monoid> init(const int n) {\n    return std::vector<Monoid>(n,\
    \ Monoid{0, 1});\n  }\n  static constexpr Monoid m_id() { return {0, 0}; }\n \
    \ static constexpr OperatorMonoid o_id() {\n    return std::numeric_limits<OperatorMonoid>::max();\n\
    \  }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return\
    \ Monoid{a.sum + b.sum, a.len + b.len};\n  }\n  static OperatorMonoid o_merge(const\
    \ OperatorMonoid& a,\n                                const OperatorMonoid& b)\
    \ {\n    return b == o_id() ? a : b;\n  }\n  static Monoid apply(const Monoid&\
    \ a, const OperatorMonoid& b) {\n    return Monoid{b == o_id() ? a.sum : b * a.len,\
    \ a.len};\n  }\n};\n\ntemplate <typename T>\nstruct RangeSumAndAddQuery {\n  using\
    \ Monoid = struct { T sum; int len; };\n  using OperatorMonoid = T;\n  static\
    \ std::vector<Monoid> init(const int n) {\n    return std::vector<Monoid>(n, Monoid{0,\
    \ 1});\n  }\n  static constexpr Monoid m_id() { return {0, 0}; }\n  static constexpr\
    \ OperatorMonoid o_id() { return 0; }\n  static Monoid m_merge(const Monoid& a,\
    \ const Monoid& b) {\n    return Monoid{a.sum + b.sum, a.len + b.len};\n  }\n\
    \  static OperatorMonoid o_merge(const OperatorMonoid& a,\n                  \
    \              const OperatorMonoid& b) {\n    return a + b;\n  }\n  static Monoid\
    \ apply(const Monoid& a, const OperatorMonoid& b) {\n    return Monoid{a.sum +\
    \ b * a.len, a.len};\n  }\n};\n\n}  // namespace monoid\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_DATA_STRUCTURE_LAZY_SEGMENT_TREE_HPP_\n#define EMTHRM_DATA_STRUCTURE_LAZY_SEGMENT_TREE_HPP_\n\
    \n#include <algorithm>\n#include <bit>\n// #include <cassert>\n#include <limits>\n\
    #include <type_traits>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ T>\nrequires requires {\n  typename T::Monoid;\n  typename T::OperatorMonoid;\n\
    \  {T::m_id()} -> std::same_as<typename T::Monoid>;\n  {T::o_id()} -> std::same_as<typename\
    \ T::OperatorMonoid>;\n  {T::m_merge(std::declval<typename T::Monoid>(),\n   \
    \           std::declval<typename T::Monoid>())}\n      -> std::same_as<typename\
    \ T::Monoid>;\n  {T::o_merge(std::declval<typename T::OperatorMonoid>(),\n   \
    \           std::declval<typename T::OperatorMonoid>())}\n      -> std::same_as<typename\
    \ T::OperatorMonoid>;\n  {T::apply(std::declval<typename T::Monoid>(),\n     \
    \       std::declval<typename T::OperatorMonoid>())}\n      -> std::same_as<typename\
    \ T::Monoid>;\n}\nstruct LazySegmentTree {\n  using Monoid = typename T::Monoid;\n\
    \  using OperatorMonoid = typename T::OperatorMonoid;\n\n  explicit LazySegmentTree(const\
    \ int n)\n      : LazySegmentTree(std::vector<Monoid>(n, T::m_id())) {}\n\n  explicit\
    \ LazySegmentTree(const std::vector<Monoid>& a)\n      : n(a.size()), height(std::countr_zero(std::bit_ceil(a.size()))),\n\
    \        p2(1 << height) {\n    lazy.assign(p2, T::o_id());\n    data.assign(p2\
    \ << 1, T::m_id());\n    std::copy(a.begin(), a.end(), data.begin() + p2);\n \
    \   for (int i = p2 - 1; i > 0; --i) {\n      data[i] = T::m_merge(data[i << 1],\
    \ data[(i << 1) + 1]);\n    }\n  }\n\n  void set(int idx, const Monoid val) {\n\
    \    idx += p2;\n    for (int i = height; i > 0; --i) {\n      propagate(idx >>\
    \ i);\n    }\n    data[idx] = val;\n    for (int i = 1; i <= height; ++i) {\n\
    \      const int current_idx = idx >> i;\n      data[current_idx] =\n        \
    \  T::m_merge(data[current_idx << 1], data[(current_idx << 1) + 1]);\n    }\n\
    \  }\n\n  void apply(int idx, const OperatorMonoid val) {\n    idx += p2;\n  \
    \  for (int i = height; i > 0; --i) {\n      propagate(idx >> i);\n    }\n   \
    \ data[idx] = T::apply(data[idx], val);\n    for (int i = 1; i <= height; ++i)\
    \ {\n      const int current_idx = idx >> i;\n      data[current_idx] =\n    \
    \      T::m_merge(data[current_idx << 1], data[(current_idx << 1) + 1]);\n   \
    \ }\n  }\n\n  void apply(int left, int right, const OperatorMonoid val) {\n  \
    \  if (right <= left) [[unlikely]] return;\n    left += p2;\n    right += p2;\n\
    \    const int ctz_left = std::countr_zero(static_cast<unsigned int>(left));\n\
    \    for (int i = height; i > ctz_left; --i) {\n      propagate(left >> i);\n\
    \    }\n    const int ctz_right = std::countr_zero(static_cast<unsigned int>(right));\n\
    \    for (int i = height; i > ctz_right; --i) {\n      propagate(right >> i);\n\
    \    }\n    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) apply_sub(l++, val);\n      if (r & 1) apply_sub(--r, val);\n    }\n\
    \    for (int i = left >> (ctz_left + 1); i > 0; i >>= 1) {\n      data[i] = T::m_merge(data[i\
    \ << 1], data[(i << 1) + 1]);\n    }\n    for (int i = right >> (ctz_right + 1);\
    \ i > 0; i >>= 1) {\n      data[i] = T::m_merge(data[i << 1], data[(i << 1) +\
    \ 1]);\n    }\n  }\n\n  Monoid get(int left, int right) {\n    if (right <= left)\
    \ [[unlikely]] return T::m_id();\n    left += p2;\n    right += p2;\n    const\
    \ int ctz_left = std::countr_zero(static_cast<unsigned int>(left));\n    for (int\
    \ i = height; i > ctz_left; --i) {\n      propagate(left >> i);\n    }\n    const\
    \ int ctz_right = std::countr_zero(static_cast<unsigned int>(right));\n    for\
    \ (int i = height; i > ctz_right; --i) {\n      propagate(right >> i);\n    }\n\
    \    Monoid res_l = T::m_id(), res_r = T::m_id();\n    for (; left < right; left\
    \ >>= 1, right >>= 1) {\n      if (left & 1) res_l = T::m_merge(res_l, data[left++]);\n\
    \      if (right & 1) res_r = T::m_merge(data[--right], res_r);\n    }\n    return\
    \ T::m_merge(res_l, res_r);\n  }\n\n  Monoid operator[](const int idx) {\n   \
    \ const int node = idx + p2;\n    for (int i = height; i > 0; --i) {\n      propagate(node\
    \ >> i);\n    }\n    return data[node];\n  }\n\n  template <typename G>\n  int\
    \ find_right(int left, const G g) {\n    if (left >= n) [[unlikely]] return n;\n\
    \    left += p2;\n    for (int i = height; i > 0; --i) {\n      propagate(left\
    \ >> i);\n    }\n    Monoid val = T::m_id();\n    do {\n      while (!(left &\
    \ 1)) left >>= 1;\n      Monoid nxt = T::m_merge(val, data[left]);\n      if (!g(nxt))\
    \ {\n        while (left < p2) {\n          propagate(left);\n          left <<=\
    \ 1;\n          nxt = T::m_merge(val, data[left]);\n          if (g(nxt)) {\n\
    \            val = nxt;\n            ++left;\n          }\n        }\n       \
    \ return left - p2;\n      }\n      val = nxt;\n      ++left;\n    } while (!std::has_single_bit(static_cast<unsigned\
    \ int>(left)));\n    return n;\n  }\n\n  template <typename G>\n  int find_left(int\
    \ right, const G g) {\n    if (right <= 0) [[unlikely]] return -1;\n    right\
    \ += p2;\n    for (int i = height; i > 0; --i) {\n      propagate((right - 1)\
    \ >> i);\n    }\n    Monoid val = T::m_id();\n    do {\n      --right;\n     \
    \ while (right > 1 && (right & 1)) right >>= 1;\n      Monoid nxt = T::m_merge(data[right],\
    \ val);\n      if (!g(nxt)) {\n        while (right < p2) {\n          propagate(right);\n\
    \          right = (right << 1) + 1;\n          nxt = T::m_merge(data[right],\
    \ val);\n          if (g(nxt)) {\n            val = nxt;\n            --right;\n\
    \          }\n        }\n        return right - p2;\n      }\n      val = nxt;\n\
    \    } while (!std::has_single_bit(static_cast<unsigned int>(right)));\n    return\
    \ -1;\n  }\n\n private:\n  const int n, height, p2;\n  std::vector<Monoid> data;\n\
    \  std::vector<OperatorMonoid> lazy;\n\n  void apply_sub(const int idx, const\
    \ OperatorMonoid& val) {\n    data[idx] = T::apply(data[idx], val);\n    if (idx\
    \ < p2) lazy[idx] = T::o_merge(lazy[idx], val);\n  }\n\n  void propagate(const\
    \ int idx) {\n    // assert(1 <= idx && idx < p2);\n    apply_sub(idx << 1, lazy[idx]);\n\
    \    apply_sub((idx << 1) + 1, lazy[idx]);\n    lazy[idx] = T::o_id();\n  }\n\
    };\n\nnamespace monoid {\n\ntemplate <typename T>\nstruct RangeMinimumAndUpdateQuery\
    \ {\n  using Monoid = T;\n  using OperatorMonoid = T;\n  static constexpr Monoid\
    \ m_id() { return std::numeric_limits<Monoid>::max(); }\n  static constexpr OperatorMonoid\
    \ o_id() {\n    return std::numeric_limits<OperatorMonoid>::max();\n  }\n  static\
    \ Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return std::min(a, b);\n\
    \  }\n  static OperatorMonoid o_merge(const OperatorMonoid& a,\n             \
    \                   const OperatorMonoid& b) {\n    return b == o_id() ? a : b;\n\
    \  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {\n    return\
    \ b == o_id() ? a : b;\n  }\n};\n\ntemplate <typename T>\nstruct RangeMaximumAndUpdateQuery\
    \ {\n  using Monoid = T;\n  using OperatorMonoid = T;\n  static constexpr Monoid\
    \ m_id() {\n    return std::numeric_limits<Monoid>::lowest();\n  }\n  static constexpr\
    \ OperatorMonoid o_id() {\n    return std::numeric_limits<OperatorMonoid>::lowest();\n\
    \  }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return\
    \ std::max(a, b);\n  }\n  static OperatorMonoid o_merge(const OperatorMonoid&\
    \ a,\n                                const OperatorMonoid& b) {\n    return b\
    \ == o_id() ? a : b;\n  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid&\
    \ b) {\n    return b == o_id()? a : b;\n  }\n};\n\ntemplate <typename T, T Inf>\n\
    struct RangeMinimumAndAddQuery {\n  using Monoid = T;\n  using OperatorMonoid\
    \ = T;\n  static constexpr Monoid m_id() { return Inf; }\n  static constexpr OperatorMonoid\
    \ o_id() { return 0; }\n  static Monoid m_merge(const Monoid& a, const Monoid&\
    \ b) {\n    return std::min(a, b);\n  }\n  static OperatorMonoid o_merge(const\
    \ OperatorMonoid& a,\n                                const OperatorMonoid& b)\
    \ {\n    return a + b;\n  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid&\
    \ b) {\n    return a + b;\n  }\n};\n\ntemplate <typename T, T Inf>\nstruct RangeMaximumAndAddQuery\
    \ {\n  using Monoid = T;\n  using OperatorMonoid = T;\n  static constexpr Monoid\
    \ m_id() { return -Inf; }\n  static constexpr OperatorMonoid o_id() { return 0;\
    \ }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return std::max(a,\
    \ b);\n  }\n  static OperatorMonoid o_merge(const OperatorMonoid& a,\n       \
    \                         const OperatorMonoid& b) {\n    return a + b;\n  }\n\
    \  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {\n    return\
    \ a + b;\n  }\n};\n\ntemplate <typename T>\nstruct RangeSumAndUpdateQuery {\n\
    \  using Monoid = struct { T sum; int len; };\n  using OperatorMonoid = T;\n \
    \ static std::vector<Monoid> init(const int n) {\n    return std::vector<Monoid>(n,\
    \ Monoid{0, 1});\n  }\n  static constexpr Monoid m_id() { return {0, 0}; }\n \
    \ static constexpr OperatorMonoid o_id() {\n    return std::numeric_limits<OperatorMonoid>::max();\n\
    \  }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return\
    \ Monoid{a.sum + b.sum, a.len + b.len};\n  }\n  static OperatorMonoid o_merge(const\
    \ OperatorMonoid& a,\n                                const OperatorMonoid& b)\
    \ {\n    return b == o_id() ? a : b;\n  }\n  static Monoid apply(const Monoid&\
    \ a, const OperatorMonoid& b) {\n    return Monoid{b == o_id() ? a.sum : b * a.len,\
    \ a.len};\n  }\n};\n\ntemplate <typename T>\nstruct RangeSumAndAddQuery {\n  using\
    \ Monoid = struct { T sum; int len; };\n  using OperatorMonoid = T;\n  static\
    \ std::vector<Monoid> init(const int n) {\n    return std::vector<Monoid>(n, Monoid{0,\
    \ 1});\n  }\n  static constexpr Monoid m_id() { return {0, 0}; }\n  static constexpr\
    \ OperatorMonoid o_id() { return 0; }\n  static Monoid m_merge(const Monoid& a,\
    \ const Monoid& b) {\n    return Monoid{a.sum + b.sum, a.len + b.len};\n  }\n\
    \  static OperatorMonoid o_merge(const OperatorMonoid& a,\n                  \
    \              const OperatorMonoid& b) {\n    return a + b;\n  }\n  static Monoid\
    \ apply(const Monoid& a, const OperatorMonoid& b) {\n    return Monoid{a.sum +\
    \ b * a.len, a.len};\n  }\n};\n\n}  // namespace monoid\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_DATA_STRUCTURE_LAZY_SEGMENT_TREE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/data_structure/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2023-05-12 19:52:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/lazy_segment_tree.test.cpp
  - test/data_structure/range_sum_query_and_range_add_query.test.cpp
  - test/data_structure/range_sum_query_and_range_update_query.test.cpp
  - test/data_structure/range_minimum_query_and_range_update_query.test.cpp
  - test/data_structure/range_minimum_query_and_range_add_query.test.cpp
  - test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
documentation_of: include/emthrm/data_structure/lazy_segment_tree.hpp
layout: document
title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

# セグメント木 (segment tree)

[モノイド](../../.verify-helper/docs/static/algebraic_structure.md)であるデータに対して高速に区間クエリを処理する（完全）二分木である。


## 時間計算量

$\langle O(N), O(\log{N}) \rangle$


## 仕様

### セグメント木

```cpp
template <typename T>
requires requires {
  typename T::Monoid;
  {T::id()} -> std::same_as<typename T::Monoid>;
  {T::merge(std::declval<typename T::Monoid>(),
            std::declval<typename T::Monoid>())}
      -> std::same_as<typename T::Monoid>;
}
struct SegmentTree;
```

- `T`：モノイドを表す構造体であり、以下の型エイリアスと静的メンバ関数を必要とする。
  - `Monoid`：要素型
  - `static constexpr Monoid id();`：単位元
  - `static Monoid merge(const Monoid&, const Monoid&);`：二項演算 $\circ$

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit SegmentTree(const int n);`|要素数 $N$ のオブジェクトを構築する。|
|`explicit SegmentTree(const std::vector<Monoid>& a);`|$A$ に対してオブジェクトを構築する。|
|`void set(int idx, const Monoid val);`|$A_{\mathrm{idx}} \gets \mathrm{val}$|
|`Monoid get(int left, int right) const;`|$A_{\mathrm{left}} \circ \cdots \circ A_{\mathrm{right}}$|
|`Monoid operator[](const int idx) const;`|$A_{\mathrm{idx}}$|
|`template <typename G>`<br>`int find_right(int left, const G g);`|`g(get(left, right + 1)) = false` を満たす最小の $\mathrm{right}$。ただし存在しないときは $N$ を返す。|
|`template <typename G>`<br>`int find_left(int right, const G g);`|`g(get(left, right)) = false` を満たす最大の $\mathrm{left}$。ただし存在しないときは $-1$ を返す。|

#### メンバ型

|名前|説明|
|:--|:--|
|`Monoid`|`T::Monoid`|


### 遅延伝播セグメント木

```cpp
template <typename T>
requires requires {
  typename T::Monoid;
  typename T::OperatorMonoid;
  {T::m_id()} -> std::same_as<typename T::Monoid>;
  {T::o_id()} -> std::same_as<typename T::OperatorMonoid>;
  {T::m_merge(std::declval<typename T::Monoid>(),
              std::declval<typename T::Monoid>())}
      -> std::same_as<typename T::Monoid>;
  {T::o_merge(std::declval<typename T::OperatorMonoid>(),
              std::declval<typename T::OperatorMonoid>())}
      -> std::same_as<typename T::OperatorMonoid>;
  {T::apply(std::declval<typename T::Monoid>(),
            std::declval<typename T::OperatorMonoid>())}
      -> std::same_as<typename T::Monoid>;
}
struct LazySegmentTree;
```

- `T`：モノイドを表す構造体であり、以下の型エイリアスと静的メンバ関数を必要とする。
  - `Monoid`：要素型
  - `OperatorMonoid`：作用素モノイドの要素型
  - `static constexpr Monoid m_id();`：単位元
  - `static constexpr OperatorMonoid o_id();`：作用素モノイドの単位元
  - `static Monoid m_merge(const Monoid&, const Monoid&);`：二項演算 $\circ$
  - `static OperatorMonoid o_merge(const OperatorMonoid&, const OperatorMonoid&);`
  - `static Monoid apply(const Monoid&, const OperatorMonoid&);`

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit LazySegmentTree(const int n);`|要素数 $N$ のオブジェクトを構築する。|
|`explicit LazySegmentTree(const std::vector<Monoid>& a);`|$A$ に対してオブジェクトを構築する。|
|`void set(int idx, const Monoid val);`|$A_{\mathrm{idx}} \gets \mathrm{val}$|
|`void apply(int idx, const OperatorMonoid val);`|$\mathrm{idx}$ における変更クエリ|
|`void apply(int left, int right, const OperatorMonoid val);`|$[\mathrm{left}, \mathrm{right})$ における変更クエリ|
|`Monoid get(int left, int right);`|$[\mathrm{left}, \mathrm{right})$ における解答クエリ|
|`Monoid operator[](const int idx);`|$A_{\mathrm{idx}}$|
|`template <typename G>`<br>`int find_right(int left, const G g);`|`g(get(left, right + 1)) = false` を満たす最小の $\mathrm{right}$。ただし存在しない場合は $N$ を返す。|
|`template <typename G>`<br>`int find_left(int right, const G g);`|`g(get(left, right)) = false` を満たす最大の $\mathrm{left}$。ただし存在しない場合は $-1$ を返す。|

#### メンバ型

|名前|説明|
|:--|:--|
|`Monoid`|`T::Monoid`|
|`OperatorMonoid`|`T::OperatorMonoid`|


### 双対セグメント木

```cpp
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
struct DualSegmentTree;
```

- `T`：以下の型エイリアスと静的メンバ関数を必要とする。
  - `Eval`：要素型
  - `OperatorMonoid`：作用素モノイドの要素型
  - `static constexpr OperatorMonoid id();`：作用素モノイドの単位元
  - `static OperatorMonoid merge(const OperatorMonoid&, const OperatorMonoid&);`
  - `static Elem apply(const Elem&, const OperatorMonoid&);`

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit DualSegmentTree(const std::vector<Elem>& a);`|$A$ に対してオブジェクトを構築する。|
|`void set(const int idx, const Elem val);`|$A_{\mathrm{idx}} \gets \mathrm{val}$|
|`void apply(const int idx, const OperatorMonoid val);`|$\mathrm{idx}$ における変更クエリ|
|`void apply(int left, int right, const OperatorMonoid val);`|$[\mathrm{left}, \mathrm{right})$ における変更クエリ|
|`Elem operator[](const int idx);`|$A_{\mathrm{idx}}$|

#### メンバ型

|名前|説明|
|:--|:--|
|`Elem`|`T::Elem`|
|`OperatorMonoid`|`T::OperatorMonoid`|


## 参考文献

- https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
- https://beet-aizu.hatenablog.com/entry/2019/11/27/125906
- http://kagamiz.hatenablog.com/entry/2012/12/18/220849
- https://kmyk.github.io/blog/blog/2020/03/04/segment-tree-is-not-complete-binary-tree/

セグメント木
- https://tsutaj.hatenablog.com/entry/2017/03/29/204841
- https://github.com/atcoder/ac-library/blob/8de49c6f150d2e5af851cbbd074aee552bf2bec9/atcoder/segtree.hpp

遅延伝播セグメント木
- https://tsutaj.hatenablog.com/entry/2017/03/30/224339
- https://kazuma8128.hatenablog.com/entry/2017/12/29/081929
- https://smijake3.hatenablog.com/entry/2018/11/03/100133
- https://github.com/atcoder/ac-library/blob/0dd2c18e8bfc41f5f7a4a985b78c47aae945e9aa/atcoder/lazysegtree.hpp

双対セグメント木
- ~~https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/~~
- https://hackmd.io/@tatyam-prime/DualSegmentTree


## TODO

- https://www.hamayanhamayan.com/entry/2017/07/08/173120
- https://ei1333.hateblo.jp/entry/2017/12/14/000000
- https://elliptic-shiho.github.io/segtree/segtree.pdf
- https://elliptic-shiho.hatenablog.com/entry/2024/02/14/033532
- 動的構築セグメント木
  - https://scrapbox.io/data-structures/Dynamic_Segment_Tree
  - http://kazuma8128.hatenablog.com/entry/2018/11/29/093827
  - https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
  - http://degwer.hatenablog.com/entry/20131211/1386757368
  - ~~https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/DynamicSegmentTree~~
  - https://mugen1337.github.io/procon/DataStructure/BinaryTrieMonoid.cpp
  - https://sotanishy.github.io/cp-library-cpp/data-structure/segtree/dynamic_segment_tree.cpp
  - https://sotanishy.github.io/cp-library-cpp/data-structure/segtree/dynamic_lazy_segment_tree.cpp
  - https://www.hamayanhamayan.com/entry/2019/02/09/103140
  - https://twitter.com/noshi91/status/1338881669525172224
  - https://judge.yosupo.jp/problem/point_set_range_composite_large_array
- 2次元セグメント木
  - https://www.hamayanhamayan.com/entry/2017/12/09/015937
  - https://ei1333.github.io/algorithm/segment-tree.html
  - https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
  - https://codeforces.com/blog/entry/74181?#comment-583268
  - https://drive.google.com/file/d/1bSjYiA-nSsHzBbCnLq1GeTpRzs2Ucm0q
  - https://noshi91.hatenablog.com/entry/2024/04/07/055028
  - https://github.com/ei1333/library/blob/master/structure/segment-tree-2d-2.cpp
  - ~~https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/SegmentTree2D~~
  - https://github.com/primenumber/ProconLib/blob/master/Structure/SegmentTree2D.cpp
  - https://algoogle.hadrori.jp/algorithm/2d-segment-tree.html
  - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  - https://judge.yosupo.jp/problem/rectangle_add_point_get
  - 問題例 "[RangeMinimumQuery](https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2021Day2/problems/H)"
  - 問題例 "[Longest Array Deconstruction](https://codeforces.com/contest/1575/problem/L)"
    - https://twitter.com/PCTprobability/status/1444372565435170816
  - 問題例 "[School of Killifish](https://onlinejudge.u-aizu.ac.jp/problems/1068)"
  - 問題例 "[Snuke Panic (2D)](https://atcoder.jp/contests/abc266/tasks/abc266_h)"
  - フラクショナルカスケーディング (fractional cascading)
    - https://en.wikipedia.org/wiki/Fractional_cascading
    - http://sntea.hatenablog.com/entry/2017/09/28/003418
    - https://www.slideshare.net/okuraofvegetable/ss-65377588
    - https://www.slideshare.net/satashun/2013-25814388
    - https://qiita.com/nariaki3551/items/3c5e59b3ece31a4dfce8
    - ~~https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/FractionalCascadingSegmentTree~~
  - range tree
    - https://en.wikipedia.org/wiki/Range_tree
    - https://kopricky.github.io/code/SegmentTrees/rangetree_pointupdate.html
    - https://mugen1337.github.io/procon/DataStructure/RangeTree.cpp
    - https://sotanishy.github.io/cp-library-cpp/data-structure/range_tree.cpp
    - 問題例「[三角形の質問](https://yukicoder.me/problems/no/1625)」
  - 四分木 (quadtree)
    - https://ja.wikipedia.org/wiki/%E5%9B%9B%E5%88%86%E6%9C%A8
    - https://sotanishy.github.io/cp-library-cpp/data-structure/quadtree.cpp
- 永続セグメント木
  - https://scrapbox.io/data-structures/Persistent_Segment_Tree
  - https://scrapbox.io/data-structures/Persistent_Lazy_Segment_Tree
  - http://sigma425.hatenablog.com/entry/2014/12/30/164148
  - https://ei1333.github.io/algorithm/segment-tree.html
  - https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
  - https://github.com/beet-aizu/library/blob/master/segtree/persistent/ushi.cpp
  - ~~https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/PersistentSegmentTree~~
  - ~~https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/PersistentLazySegmentTree~~
  - https://github.com/primenumber/ProconLib/blob/master/Structure/SegmentTreePersistent.cpp
  - http://monyone.github.io/teihen_library/#PersistentDynamicSumSegmentTree
  - https://sotanishy.github.io/cp-library-cpp/data-structure/segtree/persistent_segment_tree.cpp
- segment tree Beats
  - https://rsm9.hatenablog.com/entry/2021/02/01/220408
  - https://twitter.com/fuppy_kyopro/status/1356599033439997952
  - https://codeforces.com/blog/entry/57319
  - https://hackmd.io/@a4YdmMWJSTa0aHKUX3wNcA/S1MJhbSLV
  - https://smijake3.hatenablog.com/entry/2019/04/28/021457
  - https://smijake3.hatenablog.com/entry/2019/05/18/145531
  - https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
  - https://kmyk.github.io/competitive-programming-library/library/data_structure/segment_tree_beats.hpp.html
  - https://github.com/tjkendev/segment-tree-beats
  - https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_1.html
  - https://mugen1337.github.io/procon/SegmentTree/SegmentTreeBeats.cpp
  - https://sotanishy.github.io/cp-library-cpp/data-structure/segtree/segment_tree_beats.cpp
  - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  - 問題例「[惑星ヤナイヅの資源](https://onlinejudge.u-aizu.ac.jp/problems/0427)」
  - 問題例 "[I like Query Problem](https://atcoder.jp/contests/abc256/tasks/abc256_h)"
- 区間等差数列加算クエリ / 区間等差数列更新クエリ
  - https://null-mn.hatenablog.com/entry/2021/08/22/064325
  - https://twitter.com/yosupot/status/1104175527923986432
  - https://twitter.com/kuma_program/status/1358762477589155840
  - https://judge.yosupo.jp/problem/range_linear_add_range_min
- $A_{l \oplus x} A_{(l + 1) \oplus x} \cdots A_{(r - 1) \oplus x}$
  - 問題例 "[Reverse and Swap](https://codeforces.com/contest/1401/problem/F)"
  - 問題例 "[Minimal String Xoration](https://codeforces.com/contest/1654/problem/F)"
    - https://twitter.com/SSRS_cp/status/1505543549601054720
  - 問題例 "[Static Xor Range Composite Query](https://yukicoder.me/problems/no/1891)"
  - 問題例 "[Xor Range Substring Sum Query](https://yukicoder.me/problems/no/2265)"
  - 問題例 "[Swap and Maximum Block](https://codeforces.com/contest/1716/problem/E)"
    - https://twitter.com/SSRS_cp/status/1555231633741332480
    - https://twitter.com/kude_coder/status/1555244124282159104
    - https://hotman78.hatenablog.com/entry/2020/06/17/102519
    - https://kmjp.hatenablog.jp/entry/2023/08/29/0900
- 定数時間アルゴリズム
  - https://docs.google.com/presentation/d/1AvECxRv7hLbCNdXjERzhuJuYcV5fYFPpLA_S4QppbRI
- 円環版 `get`
  - https://twitter.com/risujiroh/status/1654163763971358723


## Submissons

- [セグメント木](https://judge.yosupo.jp/submission/25800)
  - [range minimum query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_A/review/4890699/emthrm/C++17)
  - range maximum query
  - [range sum query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_B/review/4890707/emthrm/C++14)
- [遅延伝播セグメント木](https://judge.yosupo.jp/submission/26157)
  - [range minimum query and range update query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_F/review/4899784/emthrm/C++17)
  - range maximum query and range update query
  - [range minimum query and range add query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_H/review/4899786/emthrm/C++17)
  - range maximum query and range add query
  - [range sum query and range update query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_I/review/4899787/emthrm/C++17)
  - [range sum query and range add query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4899788/emthrm/C++17)
- [双対セグメント木](https://judge.yosupo.jp/submission/227174)
