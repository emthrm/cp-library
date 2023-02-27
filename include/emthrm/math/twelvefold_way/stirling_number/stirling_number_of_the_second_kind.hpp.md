---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
      \u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp\"\
    \n\n\n\n#include <cassert>\n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\
    \n#ifndef ARBITRARY_MODINT\n#line 6 \"include/emthrm/math/modint.hpp\"\n#endif\n\
    #include <compare>\n#include <iostream>\n// #include <numeric>\n#include <utility>\n\
    #include <vector>\n\nnamespace emthrm {\n\n#ifndef ARBITRARY_MODINT\ntemplate\
    \ <int M>\nstruct MInt {\n  unsigned int v;\n\n  MInt() : v(0) {}\n  MInt(const\
    \ long long x) : v(x >= 0 ? x % M : x % M + M) {}\n\n  static constexpr int get_mod()\
    \ { return M; }\n  static void set_mod(const int divisor) { assert(divisor ==\
    \ M); }\n\n  static void init(const int x) {\n    inv<true>(x);\n    fact(x);\n\
    \    fact_inv(x);\n  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const\
    \ int n) {\n    // assert(0 <= n && n < M && std::gcd(n, M) == 1);\n    static\
    \ std::vector<MInt> inverse{0, 1};\n    const int prev = inverse.size();\n   \
    \ if (n < prev) return inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"\
    n!\" and \"M\" must be disjoint.\n      inverse.resize(n + 1);\n      for (int\
    \ i = prev; i <= n; ++i) {\n        inverse[i] = -inverse[M % i] * (M / i);\n\
    \      }\n      return inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned\
    \ int a = n, b = M; b;) {\n      const unsigned int q = a / b;\n      std::swap(a\
    \ -= q * b, b);\n      std::swap(u -= q * v, v);\n    }\n    return u;\n  }\n\n\
    \  static MInt fact(const int n) {\n    static std::vector<MInt> factorial{1};\n\
    \    const int prev = factorial.size();\n    if (n >= prev) {\n      factorial.resize(n\
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
    \ emthrm\n\n\n#line 7 \"include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int T>\nMInt<T> stirling_number_of_the_second_kind(const\
    \ int n, const int k) {\n  using ModInt = MInt<T>;\n  if (n < k) return 0;\n \
    \ ModInt::init(k);\n  ModInt s = 0;\n  for (int i = 1; i <= k; ++i) {\n    s +=\
    \ ModInt::nCk(k, i)\n         * ((k - i) & 1 ? -ModInt(i).pow(n) : ModInt(i).pow(n));\n\
    \  }\n  return s * ModInt::fact_inv(k);\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_SECOND_KIND_HPP_\n\
    #define EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_SECOND_KIND_HPP_\n\
    \n#include <cassert>\n\n#include \"emthrm/math/modint.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <int T>\nMInt<T> stirling_number_of_the_second_kind(const int\
    \ n, const int k) {\n  using ModInt = MInt<T>;\n  if (n < k) return 0;\n  ModInt::init(k);\n\
    \  ModInt s = 0;\n  for (int i = 1; i <= k; ++i) {\n    s += ModInt::nCk(k, i)\n\
    \         * ((k - i) & 1 ? -ModInt(i).pow(n) : ModInt(i).pow(n));\n  }\n  return\
    \ s * ModInt::fact_inv(k);\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_SECOND_KIND_HPP_\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.test.cpp
documentation_of: include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp
layout: document
title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570 (Stirling number of\
  \ the second kind)"
---

# スターリング数 (Stirling number)


## 第1種スターリング数 (Stirling number of the first kind)

$$
  x^{\overline{n}} = \sum_{k = 0}^n s(n, k) x^k
$$

で定義される $s$ である。

$$
  \begin{aligned}
    s(n, k) =
    \begin{cases}
      1 & (n = k), \\
      0 & (n \geq 1,\ k = 0), \\
      s(n - 1, k - 1) + (n - 1)s(n - 1, k) & (1 \leq k < n)
    \end{cases}
  \end{aligned}
$$

という漸化式をもつ。

組合せ数学では区別された $n$ 個を $k$ 個の巡回列に分割する個数を意味する。


## 第2種スターリング数 (Stirling number of the second kind)

$$
  x^n = \sum_{k = 0}^n S(n, k) x^{\underline{k}}
$$

で定義される $S$ である。

$$
  \begin{aligned}
    S(n, k) =
    \begin{cases}
      1 & (n = k), \\
      0 & (n \geq 1,\ k = 0), \\
      S(n-1, k-1) + k S(n - 1, k) & (1 \leq k < n)
    \end{cases}
  \end{aligned}
$$

という漸化式をもつ。

一般項は

$$
  S(n,k) = \dfrac{\sum_{i = 1}^k (-1)^{k - i} \binom{k}{i} i^n}{k!}
$$

である。

組合せ数学では区別された $n$ 個を $k$ グループに分割する個数を意味する。


## 時間計算量

||時間計算量|
|:--|:--|
|第1種スターリング数の数表|$O(NK)$|
|第1種スターリング数の数表 形式的冪級数版|$O(N\log{N})$|
|第2種スターリング数|$O(K\log{N})$|
|第2種スターリング数の数表|$O(NK)$|
|第2種スターリング数の数表 形式的冪級数版|$O(N\log{N})$|


## 仕様

### 第1種スターリング数の数表

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> stirling_number_of_the_first_kind_init(const int n, const int k);`|第1種スターリング数 $s(i, j)$ ($0 \leq i \leq n,\ 0 \leq j \leq k$) の数表|


### 第1種スターリング数の数表 形式的冪級数版

|名前|戻り値|備考|
|:--|:--|:--|
|`template <typename T>`<br>`std::vector<T> stirling_number_of_the_first_kind_init_by_fps(const int n);`|第1種スターリング数 $s(n, k)$ ($0 \leq k \leq n$) の数表|$x^{\underline{n}} = \sum_{k = 0}^n (-1)^{n + k} s(n, k) x^k$|


### 第2種スターリング数

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`MInt<T> stirling_number_of_the_second_kind(const int n, const int k);`|第2種スターリング数 $S(n,k)$|


### 第2種スターリング数の数表

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> stirling_number_of_the_second_kind_init(const int n, const int k);`|第2種スターリング数 $S(i, j)$ ($0 \leq i \leq n,\ 0 \leq j \leq k$) の数表|


### 第2種スターリング数の数表 形式的冪級数版

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`std::vector<MInt<T>> stirling_number_of_the_second_kind_init_by_fps(const int n);`|第2種スターリング数 $S(n, k)$ ($0 \leq k \leq n$) の数表|


## 参考文献

- https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0

第2種スターリング数
- https://mathtrain.jp/stnum
- https://mathtrain.jp/zensya

形式的冪級数版
- https://min-25.hatenablog.com/entry/2015/04/07/160154


## TODO

- 小さな素数 $p \in \mathbb{P}$ で割ったあまり
  - https://maspypy.com/stirling-%e6%95%b0%e3%82%92-p-%e3%81%a7%e5%89%b2%e3%81%a3%e3%81%9f%e4%bd%99%e3%82%8a%e3%81%ae%e8%a8%88%e7%ae%97
  - https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n
  - https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_small_p_large_n


## Submissons

- 第1種スターリング数の数表
- [第1種スターリング数の数表 形式的冪級数版](https://judge.yosupo.jp/submission/4637)
- [第2種スターリング数](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_I/review/4088846/emthrm/C++14)
- [第2種スターリング数の数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_I/review/4088857/emthrm/C++14)
- [第2種スターリング数の数表 形式的冪級数版](https://judge.yosupo.jp/submission/4636)
