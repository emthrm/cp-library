---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/lagrange_interpolation2.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 (Lagrange interpolation)\
      \ \u8A55\u4FA1\u72482"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/faulhaber_by_lagrange_interpolation.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\
      \u88DC\u9593\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp\"\
    \n\n\n\n#include <vector>\n\n#line 1 \"include/emthrm/math/lagrange_interpolation2.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"include/emthrm/math/lagrange_interpolation2.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nT lagrange_interpolation(const\
    \ std::vector<T>& y, const T t) {\n  const int n = y.size();\n  assert(t < 0 ||\
    \ t >= n);\n  std::vector<T> fact(n, 1);\n  for (int i = 1; i < n; ++i) {\n  \
    \  fact[i] = fact[i - 1] * i;\n  }\n  T res = 0;\n  for (int i = 0; i < n; ++i)\
    \ {\n    res += ((n - 1 - i) & 1 ? -y[i] : y[i])\n           / ((t - i) * fact[i]\
    \ * fact[n - 1 - i]);\n  }\n  for (int i = 0; i < n; ++i) {\n    res *= t - i;\n\
    \  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/modint.hpp\"\
    \n\n\n\n#ifndef ARBITRARY_MODINT\n#line 6 \"include/emthrm/math/modint.hpp\"\n\
    #endif\n#include <compare>\n#include <iostream>\n// #include <numeric>\n#include\
    \ <utility>\n#line 12 \"include/emthrm/math/modint.hpp\"\n\nnamespace emthrm {\n\
    \n#ifndef ARBITRARY_MODINT\ntemplate <int M>\nstruct MInt {\n  unsigned int v;\n\
    \n  MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0 ? x % M : x % M + M)\
    \ {}\n\n  static constexpr int get_mod() { return M; }\n  static void set_mod(const\
    \ int divisor) { assert(divisor == M); }\n\n  static void init(const int x) {\n\
    \    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n  }\n\n  template <bool MEMOIZES\
    \ = false>\n  static MInt inv(const int n) {\n    // assert(0 <= n && n < M &&\
    \ std::gcd(n, M) == 1);\n    static std::vector<MInt> inverse{0, 1};\n    const\
    \ int prev = inverse.size();\n    if (n < prev) return inverse[n];\n    if constexpr\
    \ (MEMOIZES) {\n      // \"n!\" and \"M\" must be disjoint.\n      inverse.resize(n\
    \ + 1);\n      for (int i = prev; i <= n; ++i) {\n        inverse[i] = -inverse[M\
    \ % i] * (M / i);\n      }\n      return inverse[n];\n    }\n    int u = 1, v\
    \ = 0;\n    for (unsigned int a = n, b = M; b;) {\n      const unsigned int q\
    \ = a / b;\n      std::swap(a -= q * b, b);\n      std::swap(u -= q * v, v);\n\
    \    }\n    return u;\n  }\n\n  static MInt fact(const int n) {\n    static std::vector<MInt>\
    \ factorial{1};\n    const int prev = factorial.size();\n    if (n >= prev) {\n\
    \      factorial.resize(n + 1);\n      for (int i = prev; i <= n; ++i) {\n   \
    \     factorial[i] = factorial[i - 1] * i;\n      }\n    }\n    return factorial[n];\n\
    \  }\n\n  static MInt fact_inv(const int n) {\n    static std::vector<MInt> f_inv{1};\n\
    \    const int prev = f_inv.size();\n    if (n >= prev) {\n      f_inv.resize(n\
    \ + 1);\n      f_inv[n] = inv(fact(n).v);\n      for (int i = n; i > prev; --i)\
    \ {\n        f_inv[i - 1] = f_inv[i] * i;\n      }\n    }\n    return f_inv[n];\n\
    \  }\n\n  static MInt nCk(const int n, const int k) {\n    if (n < 0 || n < k\
    \ || k < 0) return 0;\n    return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n\
    \ - k) :\n                                  fact_inv(n - k) * fact_inv(k));\n\
    \  }\n  static MInt nPk(const int n, const int k) {\n    return n < 0 || n < k\
    \ || k < 0 ? 0 : fact(n) * fact_inv(n - k);\n  }\n  static MInt nHk(const int\
    \ n, const int k) {\n    return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k -\
    \ 1, k));\n  }\n\n  static MInt large_nCk(long long n, const int k) {\n    if\
    \ (n < 0 || n < k || k < 0) return 0;\n    inv<true>(k);\n    MInt res = 1;\n\
    \    for (int i = 1; i <= k; ++i) {\n      res *= inv(i) * n--;\n    }\n    return\
    \ res;\n  }\n\n  MInt pow(long long exponent) const {\n    MInt res = 1, tmp =\
    \ *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1)\
    \ res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  MInt& operator+=(const\
    \ MInt& x) {\n    if (std::cmp_greater_equal(v += x.v, M)) v -= M;\n    return\
    \ *this;\n  }\n  MInt& operator-=(const MInt& x) {\n    if (std::cmp_greater_equal(v\
    \ += M - x.v, M)) v -= M;\n    return *this;\n  }\n  MInt& operator*=(const MInt&\
    \ x) {\n    v = static_cast<unsigned long long>(v) * x.v % M;\n    return *this;\n\
    \  }\n  MInt& operator/=(const MInt& x) { return *this *= inv(x.v); }\n\n  auto\
    \ operator<=>(const MInt& x) const = default;\n\n  MInt& operator++() {\n    if\
    \ (std::cmp_equal(++v, M)) v = 0;\n    return *this;\n  }\n  MInt operator++(int)\
    \ {\n    const MInt res = *this;\n    ++*this;\n    return res;\n  }\n  MInt&\
    \ operator--() {\n    v = (v == 0 ? M - 1 : v - 1);\n    return *this;\n  }\n\
    \  MInt operator--(int) {\n    const MInt res = *this;\n    --*this;\n    return\
    \ res;\n  }\n\n  MInt operator+() const { return *this; }\n  MInt operator-()\
    \ const { return MInt(v ? M - v : 0); }\n\n  MInt operator+(const MInt& x) const\
    \ { return MInt(*this) += x; }\n  MInt operator-(const MInt& x) const { return\
    \ MInt(*this) -= x; }\n  MInt operator*(const MInt& x) const { return MInt(*this)\
    \ *= x; }\n  MInt operator/(const MInt& x) const { return MInt(*this) /= x; }\n\
    \n  friend std::ostream& operator<<(std::ostream& os, const MInt& x) {\n    return\
    \ os << x.v;\n  }\n  friend std::istream& operator>>(std::istream& is, MInt& x)\
    \ {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return is;\n  }\n};\n\
    #else  // ARBITRARY_MODINT\ntemplate <int ID>\nstruct MInt {\n  unsigned int v;\n\
    \n  MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0 ? x % mod() : x % mod()\
    \ + mod()) {}\n\n  static int get_mod() { return mod(); }\n  static void set_mod(const\
    \ int divisor) { mod() = divisor; }\n\n  static void init(const int x) {\n   \
    \ inv<true>(x);\n    fact(x);\n    fact_inv(x);\n  }\n\n  template <bool MEMOIZES\
    \ = false>\n  static MInt inv(const int n) {\n    // assert(0 <= n && n < mod()\
    \ && std::gcd(x, mod()) == 1);\n    static std::vector<MInt> inverse{0, 1};\n\
    \    const int prev = inverse.size();\n    if (n < prev) return inverse[n];\n\
    \    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be disjoint.\n\
    \      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i) {\n     \
    \   inverse[i] = -inverse[mod() % i] * (mod() / i);\n      }\n      return inverse[n];\n\
    \    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b = mod(); b;) {\n\
    \      const unsigned int q = a / b;\n      std::swap(a -= q * b, b);\n      std::swap(u\
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
    \ emthrm\n\n\n#line 8 \"include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int T>\nMInt<T> faulhaber_by_lagrange_interpolation(const\
    \ long long n, const int k) {\n  using ModInt = MInt<T>;\n  if (n < 1) [[unlikely]]\
    \ return 0;\n  std::vector<ModInt> y(k + 2, 0);\n  for (int i = 1; i < k + 2;\
    \ ++i) {\n    y[i] = y[i - 1] + ModInt(i).pow(k);\n  }\n  return n - 1 < k + 2\
    \ ? y[n - 1] : lagrange_interpolation(y, ModInt(n - 1));\n}\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_LAGRANGE_INTERPOLATION_HPP_\n\
    #define EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_LAGRANGE_INTERPOLATION_HPP_\n\
    \n#include <vector>\n\n#include \"emthrm/math/lagrange_interpolation2.hpp\"\n\
    #include \"emthrm/math/modint.hpp\"\n\nnamespace emthrm {\n\ntemplate <int T>\n\
    MInt<T> faulhaber_by_lagrange_interpolation(const long long n, const int k) {\n\
    \  using ModInt = MInt<T>;\n  if (n < 1) [[unlikely]] return 0;\n  std::vector<ModInt>\
    \ y(k + 2, 0);\n  for (int i = 1; i < k + 2; ++i) {\n    y[i] = y[i - 1] + ModInt(i).pow(k);\n\
    \  }\n  return n - 1 < k + 2 ? y[n - 1] : lagrange_interpolation(y, ModInt(n -\
    \ 1));\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_LAGRANGE_INTERPOLATION_HPP_\n"
  dependsOn:
  - include/emthrm/math/lagrange_interpolation2.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/faulhaber_by_lagrange_interpolation.test.cpp
documentation_of: include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp
layout: document
title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F (Faulhaber's\
  \ formula) \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u7248"
---

# ファウルハーバーの公式 (Faulhaber's formula)

$$
  S_k(n) \mathrel{:=} \sum_{i = 1}^{n - 1} i^k
$$

と定義すると

$$
  S_k(n + 1) = \dfrac{1}{k + 1} \sum_{i = 0}^k \binom{k + 1}{i} B_i n^{k + 1 - i}
$$

が成り立つ。ここで $B$ は[ベルヌーイ数](bernoulli_number)である。


## 時間計算量

||時間計算量|
|:--|:--|
|形式的冪級数版|$O(K\log{K})$|
|ラグランジュ補間版|$O(K \log{\max{\lbrace K, M \rbrace}})$|


## 仕様

### 形式的冪級数版

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`MInt<T> faulhaber_by_fps(const long long n, const int k);`|$S_k(n)$|


### ラグランジュ補間版

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`MInt<T> faulhaber_by_lagrange_interpolation(const long long n, const int k);`|$S_k(n)$|


## 参考文献

- https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%82%A6%E3%83%AB%E3%83%8F%E3%83%BC%E3%83%90%E3%83%BC%E3%81%AE%E5%85%AC%E5%BC%8F


## Submissons

- [形式的冪級数版](https://yukicoder.me/submissions/431468)
- [ラグランジュ補間版](https://yukicoder.me/submissions/437458)
