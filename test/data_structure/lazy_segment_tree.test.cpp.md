---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728"
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/data_structure/lazy_segment_tree.test.cpp\"\n/*\n *\
    \ @title \u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_affine_range_sum\n\
    \ */\n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#line 1\
    \ \"include/emthrm/data_structure/lazy_segment_tree.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <bit>\n// #include <cassert>\n#include <limits>\n#line 9 \"include/emthrm/data_structure/lazy_segment_tree.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct LazySegmentTree {\n  using\
    \ Monoid = typename T::Monoid;\n  using OperatorMonoid = typename T::OperatorMonoid;\n\
    \n  explicit LazySegmentTree(const int n)\n      : LazySegmentTree(std::vector<Monoid>(n,\
    \ T::m_id())) {}\n\n  explicit LazySegmentTree(const std::vector<Monoid>& a)\n\
    \      : n(a.size()), height(std::countr_zero(std::bit_ceil(a.size()))),\n   \
    \     p2(1 << height) {\n    lazy.assign(p2, T::o_id());\n    data.assign(p2 <<\
    \ 1, T::m_id());\n    std::copy(a.begin(), a.end(), data.begin() + p2);\n    for\
    \ (int i = p2 - 1; i > 0; --i) {\n      data[i] = T::m_merge(data[i << 1], data[(i\
    \ << 1) + 1]);\n    }\n  }\n\n  void set(int idx, const Monoid val) {\n    idx\
    \ += p2;\n    for (int i = height; i > 0; --i) {\n      propagate(idx >> i);\n\
    \    }\n    data[idx] = val;\n    for (int i = 1; i <= height; ++i) {\n      const\
    \ int current_idx = idx >> i;\n      data[current_idx] =\n          T::m_merge(data[current_idx\
    \ << 1], data[(current_idx << 1) + 1]);\n    }\n  }\n\n  void apply(int idx, const\
    \ OperatorMonoid val) {\n    idx += p2;\n    for (int i = height; i > 0; --i)\
    \ {\n      propagate(idx >> i);\n    }\n    data[idx] = T::apply(data[idx], val);\n\
    \    for (int i = 1; i <= height; ++i) {\n      const int current_idx = idx >>\
    \ i;\n      data[current_idx] =\n          T::m_merge(data[current_idx << 1],\
    \ data[(current_idx << 1) + 1]);\n    }\n  }\n\n  void apply(int left, int right,\
    \ const OperatorMonoid val) {\n    if (right <= left) [[unlikely]] return;\n \
    \   left += p2;\n    right += p2;\n    const int ctz_left = std::countr_zero(static_cast<unsigned\
    \ int>(left));\n    for (int i = height; i > ctz_left; --i) {\n      propagate(left\
    \ >> i);\n    }\n    const int ctz_right = std::countr_zero(static_cast<unsigned\
    \ int>(right));\n    for (int i = height; i > ctz_right; --i) {\n      propagate(right\
    \ >> i);\n    }\n    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {\n\
    \      if (l & 1) apply_sub(l++, val);\n      if (r & 1) apply_sub(--r, val);\n\
    \    }\n    for (int i = left >> (ctz_left + 1); i > 0; i >>= 1) {\n      data[i]\
    \ = T::m_merge(data[i << 1], data[(i << 1) + 1]);\n    }\n    for (int i = right\
    \ >> (ctz_right + 1); i > 0; i >>= 1) {\n      data[i] = T::m_merge(data[i <<\
    \ 1], data[(i << 1) + 1]);\n    }\n  }\n\n  Monoid get(int left, int right) {\n\
    \    if (right <= left) [[unlikely]] return T::m_id();\n    left += p2;\n    right\
    \ += p2;\n    const int ctz_left = std::countr_zero(static_cast<unsigned int>(left));\n\
    \    for (int i = height; i > ctz_left; --i) {\n      propagate(left >> i);\n\
    \    }\n    const int ctz_right = std::countr_zero(static_cast<unsigned int>(right));\n\
    \    for (int i = height; i > ctz_right; --i) {\n      propagate(right >> i);\n\
    \    }\n    Monoid res_l = T::m_id(), res_r = T::m_id();\n    for (; left < right;\
    \ left >>= 1, right >>= 1) {\n      if (left & 1) res_l = T::m_merge(res_l, data[left++]);\n\
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
    \n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\n#ifndef ARBITRARY_MODINT\n\
    # include <cassert>\n#endif\n#include <compare>\n#line 9 \"include/emthrm/math/modint.hpp\"\
    \n// #include <numeric>\n#line 12 \"include/emthrm/math/modint.hpp\"\n\nnamespace\
    \ emthrm {\n\n#ifndef ARBITRARY_MODINT\ntemplate <int M>\nstruct MInt {\n  unsigned\
    \ int v;\n\n  MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0 ? x % M :\
    \ x % M + M) {}\n\n  static constexpr int get_mod() { return M; }\n  static void\
    \ set_mod(const int divisor) { assert(divisor == M); }\n\n  static void init(const\
    \ int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n  }\n\n  template\
    \ <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n    // assert(0 <=\
    \ n && n < M && std::gcd(n, M) == 1);\n    static std::vector<MInt> inverse{0,\
    \ 1};\n    const int prev = inverse.size();\n    if (n < prev) return inverse[n];\n\
    \    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be disjoint.\n\
    \      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i) {\n     \
    \   inverse[i] = -inverse[M % i] * (M / i);\n      }\n      return inverse[n];\n\
    \    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b = M; b;) {\n   \
    \   const unsigned int q = a / b;\n      std::swap(a -= q * b, b);\n      std::swap(u\
    \ -= q * v, v);\n    }\n    return u;\n  }\n\n  static MInt fact(const int n)\
    \ {\n    static std::vector<MInt> factorial{1};\n    const int prev = factorial.size();\n\
    \    if (n >= prev) {\n      factorial.resize(n + 1);\n      for (int i = prev;\
    \ i <= n; ++i) {\n        factorial[i] = factorial[i - 1] * i;\n      }\n    }\n\
    \    return factorial[n];\n  }\n\n  static MInt fact_inv(const int n) {\n    static\
    \ std::vector<MInt> f_inv{1};\n    const int prev = f_inv.size();\n    if (n >=\
    \ prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n    \
    \  for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n  \
    \    }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
    \ int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    return fact(n) * (n\
    \ - k < k ? fact_inv(k) * fact_inv(n - k) :\n                                \
    \  fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const int n, const\
    \ int k) {\n    return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k);\n\
    \  }\n  static MInt nHk(const int n, const int k) {\n    return n < 0 || k < 0\
    \ ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n  static MInt large_nCk(long\
    \ long n, const int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    inv<true>(k);\n\
    \    MInt res = 1;\n    for (int i = 1; i <= k; ++i) {\n      res *= inv(i) *\
    \ n--;\n    }\n    return res;\n  }\n\n  MInt pow(long long exponent) const {\n\
    \    MInt res = 1, tmp = *this;\n    for (; exponent > 0; exponent >>= 1) {\n\
    \      if (exponent & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n\
    \  }\n\n  MInt& operator+=(const MInt& x) {\n    if (std::cmp_greater_equal(v\
    \ += x.v, M)) v -= M;\n    return *this;\n  }\n  MInt& operator-=(const MInt&\
    \ x) {\n    if (std::cmp_greater_equal(v += M - x.v, M)) v -= M;\n    return *this;\n\
    \  }\n  MInt& operator*=(const MInt& x) {\n    v = static_cast<unsigned long long>(v)\
    \ * x.v % M;\n    return *this;\n  }\n  MInt& operator/=(const MInt& x) { return\
    \ *this *= inv(x.v); }\n\n  auto operator<=>(const MInt& x) const = default;\n\
    \n  MInt& operator++() {\n    if (std::cmp_equal(++v, M)) v = 0;\n    return *this;\n\
    \  }\n  MInt operator++(int) {\n    const MInt res = *this;\n    ++*this;\n  \
    \  return res;\n  }\n  MInt& operator--() {\n    v = (v == 0 ? M - 1 : v - 1);\n\
    \    return *this;\n  }\n  MInt operator--(int) {\n    const MInt res = *this;\n\
    \    --*this;\n    return res;\n  }\n\n  MInt operator+() const { return *this;\
    \ }\n  MInt operator-() const { return MInt(v ? M - v : 0); }\n\n  MInt operator+(const\
    \ MInt& x) const { return MInt(*this) += x; }\n  MInt operator-(const MInt& x)\
    \ const { return MInt(*this) -= x; }\n  MInt operator*(const MInt& x) const {\
    \ return MInt(*this) *= x; }\n  MInt operator/(const MInt& x) const { return MInt(*this)\
    \ /= x; }\n\n  friend std::ostream& operator<<(std::ostream& os, const MInt& x)\
    \ {\n    return os << x.v;\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return\
    \ is;\n  }\n};\n#else  // ARBITRARY_MODINT\ntemplate <int ID>\nstruct MInt {\n\
    \  unsigned int v;\n\n  MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0\
    \ ? x % mod() : x % mod() + mod()) {}\n\n  static int get_mod() { return mod();\
    \ }\n  static void set_mod(const int divisor) { mod() = divisor; }\n\n  static\
    \ void init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n\
    \  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n\
    \    // assert(0 <= n && n < mod() && std::gcd(x, mod()) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[mod() % i] * (mod() / i);\n      }\n      return\
    \ inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b =\
    \ mod(); b;) {\n      const unsigned int q = a / b;\n      std::swap(a -= q *\
    \ b, b);\n      std::swap(u -= q * v, v);\n    }\n    return u;\n  }\n\n  static\
    \ MInt fact(const int n) {\n    static std::vector<MInt> factorial{1};\n    const\
    \ int prev = factorial.size();\n    if (n >= prev) {\n      factorial.resize(n\
    \ + 1);\n      for (int i = prev; i <= n; ++i) {\n        factorial[i] = factorial[i\
    \ - 1] * i;\n      }\n    }\n    return factorial[n];\n  }\n\n  static MInt fact_inv(const\
    \ int n) {\n    static std::vector<MInt> f_inv{1};\n    const int prev = f_inv.size();\n\
    \    if (n >= prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n\
    \      for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n\
    \      }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
    \ int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    return fact(n) * (n\
    \ - k < k ? fact_inv(k) * fact_inv(n - k) :\n                                \
    \  fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const int n, const\
    \ int k) {\n    return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k);\n\
    \  }\n  static MInt nHk(const int n, const int k) {\n    return n < 0 || k < 0\
    \ ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n  static MInt large_nCk(long\
    \ long n, const int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    inv<true>(k);\n\
    \    MInt res = 1;\n    for (int i = 1; i <= k; ++i) {\n      res *= inv(i) *\
    \ n--;\n    }\n    return res;\n  }\n\n  MInt pow(long long exponent) const {\n\
    \    MInt res = 1, tmp = *this;\n    for (; exponent > 0; exponent >>= 1) {\n\
    \      if (exponent & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n\
    \  }\n\n  MInt& operator+=(const MInt& x) {\n    if (std::cmp_greater_equal(v\
    \ += x.v, mod())) v -= mod();\n    return *this;\n  }\n  MInt& operator-=(const\
    \ MInt& x) {\n    if (std::cmp_greater_equal(v += mod() - x.v, mod())) v -= mod();\n\
    \    return *this;\n  }\n  MInt& operator*=(const MInt& x) {\n    v = static_cast<unsigned\
    \ long long>(v) * x.v % mod();\n    return *this;\n    }\n  MInt& operator/=(const\
    \ MInt& x) { return *this *= inv(x.v); }\n\n  auto operator<=>(const MInt& x)\
    \ const = default;\n\n  MInt& operator++() {\n    if (std::cmp_equal(++v, mod()))\
    \ v = 0;\n    return *this;\n  }\n  MInt operator++(int) {\n    const MInt res\
    \ = *this;\n    ++*this;\n    return res;\n  }\n  MInt& operator--() {\n    v\
    \ = (v == 0 ? mod() - 1 : v - 1);\n    return *this;\n  }\n  MInt operator--(int)\
    \ {\n    const MInt res = *this;\n    --*this;\n    return res;\n  }\n\n  MInt\
    \ operator+() const { return *this; }\n  MInt operator-() const { return MInt(v\
    \ ? mod() - v : 0); }\n\n  MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  MInt operator-(const MInt& x) const { return MInt(*this) -= x; }\n\
    \  MInt operator*(const MInt& x) const { return MInt(*this) *= x; }\n  MInt operator/(const\
    \ MInt& x) const { return MInt(*this) /= x; }\n\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const MInt& x) {\n    return os << x.v;\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return\
    \ is;\n  }\n\n private:\n  static int& mod() {\n    static int divisor = 0;\n\
    \    return divisor;\n  }\n};\n#endif  // ARBITRARY_MODINT\n\n}  // namespace\
    \ emthrm\n\n\n#line 13 \"test/data_structure/lazy_segment_tree.test.cpp\"\n\n\
    int main() {\n  using ModInt = emthrm::MInt<998244353>;\n  int n, q;\n  std::cin\
    \ >> n >> q;\n  struct M {\n    using Monoid = std::pair<ModInt, int>;\n    using\
    \ OperatorMonoid = std::pair<ModInt, ModInt>;\n    static Monoid m_id() { return\
    \ {0, 0}; }\n    static OperatorMonoid o_id() { return {1, 0}; }\n    static Monoid\
    \ m_merge(const Monoid& a, const Monoid& b) {\n      return {a.first + b.first,\
    \ a.second + b.second};\n    }\n    static OperatorMonoid o_merge(const OperatorMonoid&\
    \ a,\n                                  const OperatorMonoid& b) {\n      return\
    \ {b.first * a.first, b.first * a.second + b.second};\n    }\n    static Monoid\
    \ apply(const Monoid& a, const OperatorMonoid& b) {\n      return {a.first * b.first\
    \ + b.second * a.second, a.second};\n    }\n  };\n  std::vector<M::Monoid> a(n,\
    \ {0, 1});\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i].first;\n  }\n\
    \  emthrm::LazySegmentTree<M> seg(a);\n  while (q--) {\n    int query, l, r;\n\
    \    std::cin >> query >> l >> r;\n    if (query == 0) {\n      int b, c;\n  \
    \    std::cin >> b >> c;\n      seg.apply(l, r, {b, c});\n    } else if (query\
    \ == 1) {\n      std::cout << seg.get(l, r).first << '\\n';\n    }\n  }\n  return\
    \ 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_affine_range_sum\n\
    \ */\n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include\
    \ \"emthrm/data_structure/lazy_segment_tree.hpp\"\n#include \"emthrm/math/modint.hpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<998244353>;\n  int n, q;\n  std::cin\
    \ >> n >> q;\n  struct M {\n    using Monoid = std::pair<ModInt, int>;\n    using\
    \ OperatorMonoid = std::pair<ModInt, ModInt>;\n    static Monoid m_id() { return\
    \ {0, 0}; }\n    static OperatorMonoid o_id() { return {1, 0}; }\n    static Monoid\
    \ m_merge(const Monoid& a, const Monoid& b) {\n      return {a.first + b.first,\
    \ a.second + b.second};\n    }\n    static OperatorMonoid o_merge(const OperatorMonoid&\
    \ a,\n                                  const OperatorMonoid& b) {\n      return\
    \ {b.first * a.first, b.first * a.second + b.second};\n    }\n    static Monoid\
    \ apply(const Monoid& a, const OperatorMonoid& b) {\n      return {a.first * b.first\
    \ + b.second * a.second, a.second};\n    }\n  };\n  std::vector<M::Monoid> a(n,\
    \ {0, 1});\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i].first;\n  }\n\
    \  emthrm::LazySegmentTree<M> seg(a);\n  while (q--) {\n    int query, l, r;\n\
    \    std::cin >> query >> l >> r;\n    if (query == 0) {\n      int b, c;\n  \
    \    std::cin >> b >> c;\n      seg.apply(l, r, {b, c});\n    } else if (query\
    \ == 1) {\n      std::cout << seg.get(l, r).first << '\\n';\n    }\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/lazy_segment_tree.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/data_structure/lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/lazy_segment_tree.test.cpp
- /verify/test/data_structure/lazy_segment_tree.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728"
---