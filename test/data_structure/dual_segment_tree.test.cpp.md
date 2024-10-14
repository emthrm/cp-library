---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/dual_segment_tree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u53CC\u5BFE\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728"
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/data_structure/dual_segment_tree.test.cpp\"\n/*\n *\
    \ @title \u30C7\u30FC\u30BF\u69CB\u9020/\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_affine_point_get\n\
    \ */\n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#line 1\
    \ \"include/emthrm/data_structure/dual_segment_tree.hpp\"\n\n\n\n#include <bit>\n\
    #include <concepts>\n#include <cstdint>\n#include <optional>\n#line 10 \"include/emthrm/data_structure/dual_segment_tree.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nrequires requires {\n  typename\
    \ T::Elem;\n  typename T::OperatorMonoid;\n  {T::id()} -> std::same_as<typename\
    \ T::OperatorMonoid>;\n  {T::merge(std::declval<typename T::OperatorMonoid>(),\n\
    \            std::declval<typename T::OperatorMonoid>())}\n      -> std::same_as<typename\
    \ T::OperatorMonoid>;\n  {T::apply(std::declval<typename T::Elem>(),\n       \
    \     std::declval<typename T::OperatorMonoid>())}\n      -> std::same_as<typename\
    \ T::Elem>;\n}\nstruct DualSegmentTree {\n  using Elem = typename T::Elem;\n \
    \ using OperatorMonoid = typename T::OperatorMonoid;\n\n  explicit DualSegmentTree(const\
    \ std::vector<Elem>& data)\n      : n(data.size()), height(std::countr_zero(std::bit_ceil(data.size()))),\n\
    \        p2(1 << height), data(data), lazy(p2, T::id()) {}\n\n  void set(const\
    \ int idx, const Elem val) {\n    propagate_line(idx);\n    data[idx] = val;\n\
    \  }\n\n  void apply(const int idx, const OperatorMonoid val) {\n    propagate_line(idx);\n\
    \    data[idx] = T::apply(data[idx], val);\n  }\n\n  void apply(int left, int\
    \ right, const OperatorMonoid val) {\n    if (right <= left) [[unlikely]] return;\n\
    \    propagate_line(left, std::countr_zero(static_cast<unsigned int>(left)));\n\
    \    propagate_line(right, std::countr_zero(static_cast<unsigned int>(right)));\n\
    \    left += p2;\n    right += p2;\n    if (left & 1) {\n      data[left - p2]\
    \ = T::apply(data[left - p2], val);\n      ++left;\n    }\n    if (right & 1)\
    \ {\n      --right;\n      data[right - p2] = T::apply(data[right - p2], val);\n\
    \    }\n    for (left >>= 1, right >>= 1; left < right; left >>= 1, right >>=\
    \ 1) {\n      if (left & 1) {\n        lazy[left] = T::merge(lazy[left], val);\n\
    \        ++left;\n      }\n      if (right & 1) {\n        --right;\n        lazy[right]\
    \ = T::merge(lazy[right], val);\n      }\n    }\n  }\n\n  Elem operator[](const\
    \ int idx) {\n    propagate_line(idx);\n    return data[idx];\n  }\n\n private:\n\
    \  const int n, height, p2;\n  std::vector<Elem> data;\n  std::vector<OperatorMonoid>\
    \ lazy;\n\n  void propagate(const int idx) {\n    if (lazy[idx] == T::id()) return;\n\
    \    const int child = idx << 1;\n    if (child >= p2) {\n      if (child - p2\
    \ < n) {\n        data[child - p2] = T::apply(data[child - p2], lazy[idx]);\n\
    \        if (child - p2 + 1 < n) {\n          data[child - p2 + 1] = T::apply(data[child\
    \ - p2 + 1], lazy[idx]);\n        }\n      }\n    } else {\n      lazy[child]\
    \ = T::merge(lazy[child], lazy[idx]);\n      lazy[child + 1] = T::merge(lazy[child\
    \ + 1], lazy[idx]);\n    }\n    lazy[idx] = T::id();\n  }\n\n  void propagate_line(const\
    \ int idx, const int until = 0) {\n    const int node = idx + p2;\n    for (int\
    \ i = height; i > until; --i) {\n      propagate(node >> i);\n    }\n  }\n};\n\
    \nnamespace monoid {\n\ntemplate <typename T>\nstruct RangeUpdateQuery {\n  using\
    \ Elem = T;\n  using OperatorMonoid = std::optional<Elem>;\n  static constexpr\
    \ OperatorMonoid id() { return std::nullopt; }\n  static OperatorMonoid merge(const\
    \ OperatorMonoid& a,\n                              const OperatorMonoid& b) {\n\
    \    return b.has_value() ? b : a;\n  }\n  static Elem apply(const Elem& a, const\
    \ OperatorMonoid& b) {\n    return b.has_value() ? b.value() : a;\n  }\n};\n\n\
    template <typename T>\nstruct RangeAddQuery {\n  using Elem = T;\n  using OperatorMonoid\
    \ = T;\n  static constexpr OperatorMonoid id() { return 0; }\n  static OperatorMonoid\
    \ merge(const OperatorMonoid& a,\n                              const OperatorMonoid&\
    \ b) {\n    return a + b;\n  }\n  static Elem apply(const Elem& a, const OperatorMonoid&\
    \ b) { return a + b; }\n};\n\n}  // namespace monoid\n\n}  // namespace emthrm\n\
    \n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\n#ifndef ARBITRARY_MODINT\n\
    # include <cassert>\n#endif\n#include <compare>\n#line 9 \"include/emthrm/math/modint.hpp\"\
    \n// #include <numeric>\n#line 12 \"include/emthrm/math/modint.hpp\"\n\nnamespace\
    \ emthrm {\n\n#ifndef ARBITRARY_MODINT\ntemplate <unsigned int M>\nstruct MInt\
    \ {\n  unsigned int v;\n\n  constexpr MInt() : v(0) {}\n  constexpr MInt(const\
    \ long long x) : v(x >= 0 ? x % M : x % M + M) {}\n  static constexpr MInt raw(const\
    \ int x) {\n    MInt x_;\n    x_.v = x;\n    return x_;\n  }\n\n  static constexpr\
    \ int get_mod() { return M; }\n  static constexpr void set_mod(const int divisor)\
    \ {\n    assert(std::cmp_equal(divisor, M));\n  }\n\n  static void init(const\
    \ int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n  }\n\n  template\
    \ <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n    // assert(0 <=\
    \ n && n < M && std::gcd(n, M) == 1);\n    static std::vector<MInt> inverse{0,\
    \ 1};\n    const int prev = inverse.size();\n    if (n < prev) return inverse[n];\n\
    \    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be disjoint.\n\
    \      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i) {\n     \
    \   inverse[i] = -inverse[M % i] * raw(M / i);\n      }\n      return inverse[n];\n\
    \    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b = M; b;) {\n   \
    \   const unsigned int q = a / b;\n      std::swap(a -= q * b, b);\n      std::swap(u\
    \ -= q * v, v);\n    }\n    return u;\n  }\n\n  static MInt fact(const int n)\
    \ {\n    static std::vector<MInt> factorial{1};\n    if (const int prev = factorial.size();\
    \ n >= prev) {\n      factorial.resize(n + 1);\n      for (int i = prev; i <=\
    \ n; ++i) {\n        factorial[i] = factorial[i - 1] * i;\n      }\n    }\n  \
    \  return factorial[n];\n  }\n\n  static MInt fact_inv(const int n) {\n    static\
    \ std::vector<MInt> f_inv{1};\n    if (const int prev = f_inv.size(); n >= prev)\
    \ {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n      for (int\
    \ i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n      }\n   \
    \ }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const int k)\
    \ {\n    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();\n    return\
    \ fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :\n                   \
    \               fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const\
    \ int n, const int k) {\n    return n < 0 || n < k || k < 0 ? MInt() : fact(n)\
    \ * fact_inv(n - k);\n  }\n  static MInt nHk(const int n, const int k) {\n   \
    \ return n < 0 || k < 0 ? MInt() : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n\
    \  static MInt large_nCk(long long n, const int k) {\n    if (n < 0 || n < k ||\
    \ k < 0) [[unlikely]] return MInt();\n    inv<true>(k);\n    MInt res = 1;\n \
    \   for (int i = 1; i <= k; ++i) {\n      res *= inv(i) * n--;\n    }\n    return\
    \ res;\n  }\n\n  constexpr MInt pow(long long exponent) const {\n    MInt res\
    \ = 1, tmp = *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent\
    \ & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  constexpr\
    \ MInt& operator+=(const MInt& x) {\n    if ((v += x.v) >= M) v -= M;\n    return\
    \ *this;\n  }\n  constexpr MInt& operator-=(const MInt& x) {\n    if ((v += M\
    \ - x.v) >= M) v -= M;\n    return *this;\n  }\n  constexpr MInt& operator*=(const\
    \ MInt& x) {\n    v = (unsigned long long){v} * x.v % M;\n    return *this;\n\
    \  }\n  MInt& operator/=(const MInt& x) { return *this *= inv(x.v); }\n\n  constexpr\
    \ auto operator<=>(const MInt& x) const = default;\n\n  constexpr MInt& operator++()\
    \ {\n    if (++v == M) [[unlikely]] v = 0;\n    return *this;\n  }\n  constexpr\
    \ MInt operator++(int) {\n    const MInt res = *this;\n    ++*this;\n    return\
    \ res;\n  }\n  constexpr MInt& operator--() {\n    v = (v == 0 ? M - 1 : v - 1);\n\
    \    return *this;\n  }\n  constexpr MInt operator--(int) {\n    const MInt res\
    \ = *this;\n    --*this;\n    return res;\n  }\n\n  constexpr MInt operator+()\
    \ const { return *this; }\n  constexpr MInt operator-() const { return raw(v ?\
    \ M - v : 0); }\n\n  constexpr MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  constexpr MInt operator-(const MInt& x) const { return MInt(*this)\
    \ -= x; }\n  constexpr MInt operator*(const MInt& x) const { return MInt(*this)\
    \ *= x; }\n  MInt operator/(const MInt& x) const { return MInt(*this) /= x; }\n\
    \n  friend std::ostream& operator<<(std::ostream& os, const MInt& x) {\n    return\
    \ os << x.v;\n  }\n  friend std::istream& operator>>(std::istream& is, MInt& x)\
    \ {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return is;\n  }\n};\n\
    #else  // ARBITRARY_MODINT\ntemplate <int ID>\nstruct MInt {\n  unsigned int v;\n\
    \n  constexpr MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0 ? x % mod()\
    \ : x % mod() + mod()) {}\n  static constexpr MInt raw(const int x) {\n    MInt\
    \ x_;\n    x_.v = x;\n    return x_;\n  }\n\n  static int get_mod() { return mod();\
    \ }\n  static void set_mod(const unsigned int divisor) { mod() = divisor; }\n\n\
    \  static void init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n\
    \  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n\
    \    // assert(0 <= n && n < mod() && std::gcd(x, mod()) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[mod() % i] * raw(mod() / i);\n      }\n   \
    \   return inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned int a\
    \ = n, b = mod(); b;) {\n      const unsigned int q = a / b;\n      std::swap(a\
    \ -= q * b, b);\n      std::swap(u -= q * v, v);\n    }\n    return u;\n  }\n\n\
    \  static MInt fact(const int n) {\n    static std::vector<MInt> factorial{1};\n\
    \    if (const int prev = factorial.size(); n >= prev) {\n      factorial.resize(n\
    \ + 1);\n      for (int i = prev; i <= n; ++i) {\n        factorial[i] = factorial[i\
    \ - 1] * i;\n      }\n    }\n    return factorial[n];\n  }\n\n  static MInt fact_inv(const\
    \ int n) {\n    static std::vector<MInt> f_inv{1};\n    if (const int prev = f_inv.size();\
    \ n >= prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n\
    \      for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n\
    \      }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
    \ int k) {\n    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();\n   \
    \ return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :\n            \
    \                      fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const\
    \ int n, const int k) {\n    return n < 0 || n < k || k < 0 ? MInt() : fact(n)\
    \ * fact_inv(n - k);\n  }\n  static MInt nHk(const int n, const int k) {\n   \
    \ return n < 0 || k < 0 ? MInt() : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n\
    \  static MInt large_nCk(long long n, const int k) {\n    if (n < 0 || n < k ||\
    \ k < 0) [[unlikely]] return MInt();\n    inv<true>(k);\n    MInt res = 1;\n \
    \   for (int i = 1; i <= k; ++i) {\n      res *= inv(i) * n--;\n    }\n    return\
    \ res;\n  }\n\n  MInt pow(long long exponent) const {\n    MInt res = 1, tmp =\
    \ *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1)\
    \ res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  MInt& operator+=(const\
    \ MInt& x) {\n    if ((v += x.v) >= mod()) v -= mod();\n    return *this;\n  }\n\
    \  MInt& operator-=(const MInt& x) {\n    if ((v += mod() - x.v) >= mod()) v -=\
    \ mod();\n    return *this;\n  }\n  MInt& operator*=(const MInt& x) {\n    v =\
    \ (unsigned long long){v} * x.v % mod();\n    return *this;\n    }\n  MInt& operator/=(const\
    \ MInt& x) { return *this *= inv(x.v); }\n\n  auto operator<=>(const MInt& x)\
    \ const = default;\n\n  MInt& operator++() {\n    if (++v == mod()) [[unlikely]]\
    \ v = 0;\n    return *this;\n  }\n  MInt operator++(int) {\n    const MInt res\
    \ = *this;\n    ++*this;\n    return res;\n  }\n  MInt& operator--() {\n    v\
    \ = (v == 0 ? mod() - 1 : v - 1);\n    return *this;\n  }\n  MInt operator--(int)\
    \ {\n    const MInt res = *this;\n    --*this;\n    return res;\n  }\n\n  MInt\
    \ operator+() const { return *this; }\n  MInt operator-() const { return raw(v\
    \ ? mod() - v : 0); }\n\n  MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  MInt operator-(const MInt& x) const { return MInt(*this) -= x; }\n\
    \  MInt operator*(const MInt& x) const { return MInt(*this) *= x; }\n  MInt operator/(const\
    \ MInt& x) const { return MInt(*this) /= x; }\n\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const MInt& x) {\n    return os << x.v;\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return\
    \ is;\n  }\n\n private:\n  static unsigned int& mod() {\n    static unsigned int\
    \ divisor = 0;\n    return divisor;\n  }\n};\n#endif  // ARBITRARY_MODINT\n\n\
    }  // namespace emthrm\n\n\n#line 13 \"test/data_structure/dual_segment_tree.test.cpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<998244353>;\n  int n, q;\n  std::cin\
    \ >> n >> q;\n  std::vector<ModInt> a(n);\n  for (ModInt& a_i : a) std::cin >>\
    \ a_i;\n  struct M {\n    using Elem = ModInt;\n    using OperatorMonoid = std::pair<ModInt,\
    \ ModInt>;\n    static OperatorMonoid id() { return {ModInt::raw(1), ModInt::raw(0)};\
    \ }\n    static OperatorMonoid merge(const OperatorMonoid& a,\n              \
    \                  const OperatorMonoid& b) {\n      return {a.first * b.first,\
    \ a.second * b.first + b.second};\n    }\n    static Elem apply(const Elem& a,\
    \ const OperatorMonoid& b) {\n      return a * b.first + b.second;\n    }\n  };\n\
    \  emthrm::DualSegmentTree<M> dst(a);\n  while (q--) {\n    int type;\n    std::cin\
    \ >> type;\n    if (type == 0) {\n      int l, r;\n      ModInt b, c;\n      std::cin\
    \ >> l >> r >> b >> c;\n      dst.apply(l, r, {b, c});\n    } else if (type ==\
    \ 1) {\n      int i;\n      std::cin >> i;\n      std::cout << dst[i] << '\\n';\n\
    \    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u53CC\u5BFE\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_affine_point_get\n\
    \ */\n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include\
    \ \"emthrm/data_structure/dual_segment_tree.hpp\"\n#include \"emthrm/math/modint.hpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<998244353>;\n  int n, q;\n  std::cin\
    \ >> n >> q;\n  std::vector<ModInt> a(n);\n  for (ModInt& a_i : a) std::cin >>\
    \ a_i;\n  struct M {\n    using Elem = ModInt;\n    using OperatorMonoid = std::pair<ModInt,\
    \ ModInt>;\n    static OperatorMonoid id() { return {ModInt::raw(1), ModInt::raw(0)};\
    \ }\n    static OperatorMonoid merge(const OperatorMonoid& a,\n              \
    \                  const OperatorMonoid& b) {\n      return {a.first * b.first,\
    \ a.second * b.first + b.second};\n    }\n    static Elem apply(const Elem& a,\
    \ const OperatorMonoid& b) {\n      return a * b.first + b.second;\n    }\n  };\n\
    \  emthrm::DualSegmentTree<M> dst(a);\n  while (q--) {\n    int type;\n    std::cin\
    \ >> type;\n    if (type == 0) {\n      int l, r;\n      ModInt b, c;\n      std::cin\
    \ >> l >> r >> b >> c;\n      dst.apply(l, r, {b, c});\n    } else if (type ==\
    \ 1) {\n      int i;\n      std::cin >> i;\n      std::cout << dst[i] << '\\n';\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/dual_segment_tree.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/data_structure/dual_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2024-08-10 01:47:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/dual_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/dual_segment_tree.test.cpp
- /verify/test/data_structure/dual_segment_tree.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
