---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp
    title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570 (Stirling number\
      \ of the second kind) \u306E\u6570\u8868"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/bell_number/bell_number_init.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\u30EB\u6570\
      \u306E\u6570\u8868"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp\"\
    \n\n\n\n#include <numeric>\n#include <vector>\n\n#line 1 \"include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp\"\
    \n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\n#ifndef ARBITRARY_MODINT\n\
    # include <cassert>\n#endif\n#include <compare>\n#include <iostream>\n// #include\
    \ <numeric>\n#include <utility>\n#line 12 \"include/emthrm/math/modint.hpp\"\n\
    \nnamespace emthrm {\n\n#ifndef ARBITRARY_MODINT\ntemplate <int M>\nstruct MInt\
    \ {\n  unsigned int v;\n\n  MInt() : v(0) {}\n  MInt(const long long x) : v(x\
    \ >= 0 ? x % M : x % M + M) {}\n\n  static constexpr int get_mod() { return M;\
    \ }\n  static void set_mod(const int divisor) { assert(divisor == M); }\n\n  static\
    \ void init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n\
    \  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n\
    \    // assert(0 <= n && n < M && std::gcd(n, M) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[M % i] * (M / i);\n      }\n      return inverse[n];\n\
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
    \ emthrm\n\n\n#line 7 \"include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<std::vector<T>> stirling_number_of_the_second_kind_init(\n\
    \    const int n, const int k) {\n  std::vector<std::vector<T>> s(n + 1, std::vector<T>(k\
    \ + 1, 0));\n  s[0][0] = 1;\n  for (int i = 1; i <= n; ++i) {\n    for (int j\
    \ = 1; j <= i && j <= k; ++j) {\n      s[i][j] = s[i - 1][j - 1] + s[i - 1][j]\
    \ * j;\n    }\n  }\n  return s;\n}\n\n}  // namespace emthrm\n\n\n#line 8 \"include/emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<std::vector<T>> bell_number_init(const\
    \ int n, const int k) {\n  std::vector<std::vector<T>> b =\n      stirling_number_of_the_second_kind_init<T>(n,\
    \ k);\n  for (int i = 0; i <= n; ++i) {\n    std::partial_sum(b[i].begin(), b[i].end(),\
    \ b[i].begin());\n  }\n  return b;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_\n#define\
    \ EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_\n\n#include <numeric>\n\
    #include <vector>\n\n#include \"emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<std::vector<T>> bell_number_init(const\
    \ int n, const int k) {\n  std::vector<std::vector<T>> b =\n      stirling_number_of_the_second_kind_init<T>(n,\
    \ k);\n  for (int i = 0; i <= n; ++i) {\n    std::partial_sum(b[i].begin(), b[i].end(),\
    \ b[i].begin());\n  }\n  return b;\n}\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_\n"
  dependsOn:
  - include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/bell_number/bell_number_init.test.cpp
documentation_of: include/emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp
layout: document
title: "\u30D9\u30EB\u6570 (Bell number) \u306E\u6570\u8868"
---

# ベル数 (Bell number)

区別された $n$ 個を $k$ グループ以下に分割する場合の数を $B(n, k)$ とおくと

$$
  B(n,k) = \sum_{j = 0}^k S(n, j) = \sum_{i = 0}^k \frac{i^n}{i!} \sum_{j = 0}^{k - i} \frac{(-1)^j}{j!}
$$

が成り立つ。ここで $S$ は[第2種スターリング数](../stirling_number/stirling_number.md)である。

$n = k$ を満たす $B(n, k)$ をベル数 $B_n$ と呼ぶ。

漸化式は

$$
  B_{n + 1} = \sum_{k = 0}^n \binom{n}{k} B_k
$$

であり、指数型母関数は

$$
  \sum_{n = 0}^\infty B_n \frac{x^n}{n!} = e^{e^x - 1}
$$

である。


## 時間計算量

||時間計算量|
|:--|:--|
||$O(\min \lbrace N, K \rbrace \log{N})$|
|数表|$O(NK)$|
|数表 $n = k$ 版|$O(N\log{N})$|


## 仕様

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`MInt<T> bell_number(const int n, int k);`|$B(n, k)$|


### 数表

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> bell_number_init(const int n, const int k);`|$B(i, j)$ ($0 \leq i \leq n,\ 0 \leq j \leq k$) の数表|


### 数表 $n = k$ 版

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> bell_number_init_by_fps(const int n);`|ベル数 $B_i$ ($0 \leq i \leq n$) の数表|


## 参考文献

- https://qiita.com/drken/items/f2ea4b58b0d21621bd51
- https://ja.wikipedia.org/wiki/ベル数


## Submissons

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_G/review/4088882/emthrm/C++14
- [数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_G/review/4088892/emthrm/C++14)
- 数表 $n = k$ 版