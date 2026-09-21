---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/twelvefold_way/multipoint_binomial_prefix_sum.hpp
    title: "\u4E8C\u9805\u4FC2\u6570\u306E prefix sum \u306E\u591A\u70B9\u8A55\u4FA1"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/misc/mo.hpp
    title: Mo's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/2206
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E\
      \ prefix sum \u306E\u591A\u70B9\u8A55\u4FA1"
    links:
    - https://yukicoder.me/problems/no/2206
  bundledCode: "#line 1 \"test/math/twelvefold_way/multipoint_binomial_prefix_sum.test.cpp\"\
    \n/*\n * @title \u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E\
    \ prefix sum \u306E\u591A\u70B9\u8A55\u4FA1\n *\n * verification-helper: PROBLEM\
    \ https://yukicoder.me/problems/no/2206\n */\n\n#include <iostream>\n#include\
    \ <vector>\n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\n#ifndef ARBITRARY_MODINT\n\
    # include <cassert>\n#endif\n#include <compare>\n#line 9 \"include/emthrm/math/modint.hpp\"\
    \n// #include <numeric>\n#include <utility>\n#line 12 \"include/emthrm/math/modint.hpp\"\
    \n\nnamespace emthrm {\n\n#ifndef ARBITRARY_MODINT\ntemplate <unsigned int M>\n\
    struct MInt {\n  unsigned int v;\n\n  constexpr MInt() : v(0) {}\n  constexpr\
    \ MInt(const long long x) : v(x >= 0 ? x % M : x % M + M) {}\n  static constexpr\
    \ MInt raw(const int x) {\n    MInt x_;\n    x_.v = x;\n    return x_;\n  }\n\n\
    \  static constexpr int get_mod() { return M; }\n  static constexpr void set_mod(const\
    \ int divisor) {\n    assert(std::cmp_equal(divisor, M));\n  }\n\n  static void\
    \ init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n  }\n\
    \n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n    //\
    \ assert(0 <= n && n < M && std::gcd(n, M) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[M % i] * raw(M / i);\n      }\n      return\
    \ inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b =\
    \ M; b;) {\n      const unsigned int q = a / b;\n      std::swap(a -= q * b, b);\n\
    \      std::swap(u -= q * v, v);\n    }\n    return u;\n  }\n\n  static MInt fact(const\
    \ int n) {\n    static std::vector<MInt> factorial{1};\n    if (const int prev\
    \ = factorial.size(); n >= prev) {\n      factorial.resize(n + 1);\n      for\
    \ (int i = prev; i <= n; ++i) {\n        factorial[i] = factorial[i - 1] * i;\n\
    \      }\n    }\n    return factorial[n];\n  }\n\n  static MInt fact_inv(const\
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
    }  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/twelvefold_way/multipoint_binomial_prefix_sum.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#line 7 \"include/emthrm/math/twelvefold_way/multipoint_binomial_prefix_sum.hpp\"\
    \n\n#line 1 \"include/emthrm/misc/mo.hpp\"\n\n\n\n#line 5 \"include/emthrm/misc/mo.hpp\"\
    \n#include <cmath>\n#include <numeric>\n#line 8 \"include/emthrm/misc/mo.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename AddLeft, typename AddRight,\n   \
    \       typename DelLeft, typename DelRight>\nstruct Mo {\n  explicit Mo(const\
    \ std::vector<int>& ls, const std::vector<int>& rs,\n              const AddLeft&\
    \ add_left, const AddRight& add_right,\n              const DelLeft& del_left,\
    \ const DelRight& del_right)\n      : n(ls.size()), ptr(0), nl(0), nr(0), ls(ls),\
    \ rs(rs),\n        add_left(add_left), add_right(add_right),\n        del_left(del_left),\
    \ del_right(del_right) {\n    const int width = (\n        n == 0 ? 1\n      \
    \         : std::max(std::llround(std::ranges::max(rs) / std::sqrt(n)),\n    \
    \                      1LL));\n    order.resize(n);\n    std::iota(order.begin(),\
    \ order.end(), 0);\n    std::sort(order.begin(), order.end(),\n              [&ls,\
    \ &rs, width](const int a, const int b) -> bool {\n                  if (ls[a]\
    \ / width != ls[b] / width) return ls[a] < ls[b];\n                  return (ls[a]\
    \ / width) & 1 ? rs[a] < rs[b] : rs[a] > rs[b];\n              });\n  }\n\n  int\
    \ process() {\n    if (ptr == n) [[unlikely]] return -1;\n    const int id = order[ptr++];\n\
    \    while (ls[id] < nl) {\n      const int idx = --nl;\n      add_left(idx, nl,\
    \ nr);\n    }\n    while (nr < rs[id]) {\n      const int idx = nr++;\n      add_right(idx,\
    \ nl, nr);\n    }\n    while (nl < ls[id]) {\n      const int idx = nl++;\n  \
    \    del_left(idx, nl, nr);\n    }\n    while (rs[id] < nr) {\n      const int\
    \ idx = --nr;\n      del_right(idx, nl, nr);\n    }\n    return id;\n  }\n\n private:\n\
    \  const int n;\n  int ptr, nl, nr;\n  std::vector<int> ls, rs, order;\n  AddLeft\
    \ add_left;\n  AddRight add_right;\n  DelLeft del_left;\n  DelRight del_right;\n\
    };\n\n}  // namespace emthrm\n\n\n#line 10 \"include/emthrm/math/twelvefold_way/multipoint_binomial_prefix_sum.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <unsigned int T>\nstd::vector<MInt<T>> multipoint_binomial_prefix_sum(\n\
    \    const std::vector<int>& ns, const std::vector<int>& ms) {\n  using ModInt\
    \ = MInt<T>;\n  assert(ns.size() == ms.size());\n  if (ns.empty()) [[unlikely]]\
    \ return {};\n  assert(T % 2 == 1);\n  const int q = ns.size();\n  for (int i\
    \ = 0; i < q; ++i) {\n    assert(0 <= ms[i] && ms[i] <= ns[i]);\n  }\n  ModInt::init(std::ranges::max(ns));\n\
    \  ModInt sum = 1;\n  Mo mo(ms, ns,\n        // S(n, m) -> S(n, m - 1)\n     \
    \   [&sum](const int, const int m, const int n) {\n          sum -= ModInt::nCk(n,\
    \ m + 1);\n        },\n        // S(n, m) -> S(n + 1, m)\n        [&sum](const\
    \ int, const int m, const int n) {\n          sum += sum - ModInt::nCk(n - 1,\
    \ m);\n        },\n        // S(n, m) -> S(n, m + 1)\n        [&sum](const int,\
    \ const int m, const int n) {\n          sum += ModInt::nCk(n, m);\n        },\n\
    \        // S(n, m) -> S(n - 1, m)\n        [&sum](const int, const int m, const\
    \ int n) {\n          static const ModInt inv2 = ModInt::inv(2);\n          sum\
    \ = (sum + ModInt::nCk(n, m)) * inv2;\n        });\n  std::vector<ModInt> ans(q);\n\
    \  for (int i = 0; i < q; ++i) {\n    const int idx = mo.process();\n    ans[idx]\
    \ = sum;\n  }\n  return ans;\n}\n\n}  // namespace emthrm\n\n\n#line 12 \"test/math/twelvefold_way/multipoint_binomial_prefix_sum.test.cpp\"\
    \n\nint main() {\n  constexpr int MOD = 998244353;\n  using ModInt = emthrm::MInt<MOD>;\n\
    \  int t;\n  std::cin >> t;\n  std::vector<int> n(t), m(t);\n  for (int i = 0;\
    \ i < t; ++i) {\n    std::cin >> n[i] >> m[i];\n    --n[i];\n    --m[i];\n  }\n\
    \  const std::vector<ModInt> sums =\n      emthrm::multipoint_binomial_prefix_sum<MOD>(n,\
    \ m);\n  for (int i = 0; i < t; ++i) {\n    std::cout << (ModInt::raw(2).pow(n[i]\
    \ + 1) - 1) * sums[i] << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E\
    \ prefix sum \u306E\u591A\u70B9\u8A55\u4FA1\n *\n * verification-helper: PROBLEM\
    \ https://yukicoder.me/problems/no/2206\n */\n\n#include <iostream>\n#include\
    \ <vector>\n\n#include \"emthrm/math/modint.hpp\"\n#include \"emthrm/math/twelvefold_way/multipoint_binomial_prefix_sum.hpp\"\
    \n\nint main() {\n  constexpr int MOD = 998244353;\n  using ModInt = emthrm::MInt<MOD>;\n\
    \  int t;\n  std::cin >> t;\n  std::vector<int> n(t), m(t);\n  for (int i = 0;\
    \ i < t; ++i) {\n    std::cin >> n[i] >> m[i];\n    --n[i];\n    --m[i];\n  }\n\
    \  const std::vector<ModInt> sums =\n      emthrm::multipoint_binomial_prefix_sum<MOD>(n,\
    \ m);\n  for (int i = 0; i < t; ++i) {\n    std::cout << (ModInt::raw(2).pow(n[i]\
    \ + 1) - 1) * sums[i] << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/twelvefold_way/multipoint_binomial_prefix_sum.hpp
  - include/emthrm/misc/mo.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/multipoint_binomial_prefix_sum.test.cpp
  requiredBy: []
  timestamp: '2026-09-21 19:26:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/twelvefold_way/multipoint_binomial_prefix_sum.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/multipoint_binomial_prefix_sum.test.cpp
- /verify/test/math/twelvefold_way/multipoint_binomial_prefix_sum.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E prefix sum\
  \ \u306E\u591A\u70B9\u8A55\u4FA1"
---
