---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/catalan_number.test.cpp
    title: "\u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/catalan_number.hpp\"\n#include <vector>\r\n#line 2\
    \ \"math/modint.hpp\"\n// #include <algorithm>\r\n// #include <cassert>\r\n#include\
    \ <iostream>\r\n#include <utility>\r\n#line 7 \"math/modint.hpp\"\n\r\n// template\
    \ <int MOD>\r\n// struct MInt {\r\n//   unsigned int val;\r\n//   MInt(): val(0)\
    \ {}\r\n//   MInt(long long x) : val(x >= 0 ? x % MOD : x % MOD + MOD) {}\r\n\
    //   static constexpr int get_mod() { return MOD; }\r\n//   static void set_mod(int\
    \ divisor) { assert(divisor == MOD); }\r\n//   static void init(int x = 10000000)\
    \ { inv(x, true); fact(x); fact_inv(x); }\r\n//   static MInt inv(int x, bool\
    \ init = false) {\r\n//     // assert(0 <= x && x < MOD && std::__gcd(x, MOD)\
    \ == 1);\r\n//     static std::vector<MInt> inverse{0, 1};\r\n//     int prev\
    \ = inverse.size();\r\n//     if (init && x >= prev) {\r\n//       // \"x!\" and\
    \ \"MOD\" must be disjoint.\r\n//       inverse.resize(x + 1);\r\n//       for\
    \ (int i = prev; i <= x; ++i) inverse[i] = -inverse[MOD % i] * (MOD / i);\r\n\
    //     }\r\n//     if (x < inverse.size()) return inverse[x];\r\n//     unsigned\
    \ int a = x, b = MOD; int u = 1, v = 0;\r\n//     while (b) {\r\n//       unsigned\
    \ int tmp = a / b;\r\n//       std::swap(a -= tmp * b, b);\r\n//       std::swap(u\
    \ -= tmp * v, v);\r\n//     }\r\n//     return u;\r\n//   }\r\n//   static MInt\
    \ fact(int x) {\r\n//     static std::vector<MInt> f{1};\r\n//     int prev =\
    \ f.size();\r\n//     if (x >= prev) {\r\n//       f.resize(x + 1);\r\n//    \
    \   for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;\r\n//     }\r\n//   \
    \  return f[x];\r\n//   }\r\n//   static MInt fact_inv(int x) {\r\n//     static\
    \ std::vector<MInt> finv{1};\r\n//     int prev = finv.size();\r\n//     if (x\
    \ >= prev) {\r\n//       finv.resize(x + 1);\r\n//       finv[x] = inv(fact(x).val);\r\
    \n//       for (int i = x; i > prev; --i) finv[i - 1] = finv[i] * i;\r\n//   \
    \  }\r\n//     return finv[x];\r\n//   }\r\n//   static MInt nCk(int n, int k)\
    \ {\r\n//     if (n < 0 || n < k || k < 0) return 0;\r\n//     if (n - k > k)\
    \ k = n - k;\r\n//     return fact(n) * fact_inv(k) * fact_inv(n - k);\r\n// \
    \  }\r\n//   static MInt nPk(int n, int k) { return n < 0 || n < k || k < 0 ?\
    \ 0 : fact(n) * fact_inv(n - k); }\r\n//   static MInt nHk(int n, int k) { return\
    \ n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }\r\n//   MInt pow(long\
    \ long exponent) const {\r\n//     MInt tmp = *this, res = 1;\r\n//     while\
    \ (exponent > 0) {\r\n//       if (exponent & 1) res *= tmp;\r\n//       tmp *=\
    \ tmp;\r\n//       exponent >>= 1;\r\n//     }\r\n//     return res;\r\n//   }\r\
    \n//   MInt &operator+=(const MInt &x) { if((val += x.val) >= MOD) val -= MOD;\
    \ return *this; }\r\n//   MInt &operator-=(const MInt &x) { if((val += MOD - x.val)\
    \ >= MOD) val -= MOD; return *this; }\r\n//   MInt &operator*=(const MInt &x)\
    \ { val = static_cast<unsigned long long>(val) * x.val % MOD; return *this; }\r\
    \n//   MInt &operator/=(const MInt &x) { return *this *= inv(x.val); }\r\n// \
    \  bool operator==(const MInt &x) const { return val == x.val; }\r\n//   bool\
    \ operator!=(const MInt &x) const { return val != x.val; }\r\n//   bool operator<(const\
    \ MInt &x) const { return val < x.val; }\r\n//   bool operator<=(const MInt &x)\
    \ const { return val <= x.val; }\r\n//   bool operator>(const MInt &x) const {\
    \ return val > x.val; }\r\n//   bool operator>=(const MInt &x) const { return\
    \ val >= x.val; }\r\n//   MInt &operator++() { if (++val == MOD) val = 0; return\
    \ *this; }\r\n//   MInt operator++(int) { MInt res = *this; ++*this; return res;\
    \ }\r\n//   MInt &operator--() { val = (val == 0 ? MOD : val) - 1; return *this;\
    \ }\r\n//   MInt operator--(int) { MInt res = *this; --*this; return res; }\r\n\
    //   MInt operator+() const { return *this; }\r\n//   MInt operator-() const {\
    \ return MInt(val ? MOD - val : 0); }\r\n//   MInt operator+(const MInt &x) const\
    \ { return MInt(*this) += x; }\r\n//   MInt operator-(const MInt &x) const { return\
    \ MInt(*this) -= x; }\r\n//   MInt operator*(const MInt &x) const { return MInt(*this)\
    \ *= x; }\r\n//   MInt operator/(const MInt &x) const { return MInt(*this) /=\
    \ x; }\r\n//   friend std::ostream &operator<<(std::ostream &os, const MInt &x)\
    \ { return os << x.val; }\r\n//   friend std::istream &operator>>(std::istream\
    \ &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }\r\n//\
    \ };\r\n// namespace std { template <int MOD> MInt<MOD> abs(const MInt<MOD> &x)\
    \ { return x; } }\r\n\r\ntemplate <int ID>\r\nstruct MInt {\r\n  unsigned int\
    \ val;\r\n  MInt(): val(0) {}\r\n  MInt(long long x) : val(x >= 0 ? x % mod()\
    \ : x % mod() + mod()) {}\r\n  static int get_mod() { return mod(); }\r\n  static\
    \ void set_mod(int divisor) { mod() = divisor; }\r\n  static void init(int x =\
    \ 10000000) { inv(x, true); fact(x); fact_inv(x); }\r\n  static MInt inv(int x,\
    \ bool init = false) {\r\n    // assert(0 <= x && x < mod() && std::__gcd(x, mod())\
    \ == 1);\r\n    static std::vector<MInt> inverse{0, 1};\r\n    int prev = inverse.size();\r\
    \n    if (init && x >= prev) {\r\n      // \"x!\" and \"mod()\" must be disjoint.\r\
    \n      inverse.resize(x + 1);\r\n      for (int i = prev; i <= x; ++i) inverse[i]\
    \ = -inverse[mod() % i] * (mod() / i);\r\n    }\r\n    if (x < inverse.size())\
    \ return inverse[x];\r\n    unsigned int a = x, b = mod(); int u = 1, v = 0;\r\
    \n    while (b) {\r\n      unsigned int tmp = a / b;\r\n      std::swap(a -= tmp\
    \ * b, b);\r\n      std::swap(u -= tmp * v, v);\r\n    }\r\n    return u;\r\n\
    \  }\r\n  static MInt fact(int x) {\r\n    static std::vector<MInt> f{1};\r\n\
    \    int prev = f.size();\r\n    if (x >= prev) {\r\n      f.resize(x + 1);\r\n\
    \      for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;\r\n    }\r\n    return\
    \ f[x];\r\n  }\r\n  static MInt fact_inv(int x) {\r\n    static std::vector<MInt>\
    \ finv{1};\r\n    int prev = finv.size();\r\n    if (x >= prev) {\r\n      finv.resize(x\
    \ + 1);\r\n      finv[x] = inv(fact(x).val);\r\n      for (int i = x; i > prev;\
    \ --i) finv[i - 1] = finv[i] * i;\r\n    }\r\n    return finv[x];\r\n  }\r\n \
    \ static MInt nCk(int n, int k) {\r\n    if (n < 0 || n < k || k < 0) return 0;\r\
    \n    if (n - k > k) k = n - k;\r\n    return fact(n) * fact_inv(k) * fact_inv(n\
    \ - k);\r\n  }\r\n  static MInt nPk(int n, int k) { return n < 0 || n < k || k\
    \ < 0 ? 0 : fact(n) * fact_inv(n - k); }\r\n  static MInt nHk(int n, int k) {\
    \ return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }\r\n  MInt pow(long\
    \ long exponent) const {\r\n    MInt tmp = *this, res = 1;\r\n    while (exponent\
    \ > 0) {\r\n      if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n     \
    \ exponent >>= 1;\r\n    }\r\n    return res;\r\n  }\r\n  MInt &operator+=(const\
    \ MInt &x) { if((val += x.val) >= mod()) val -= mod(); return *this; }\r\n  MInt\
    \ &operator-=(const MInt &x) { if((val += mod() - x.val) >= mod()) val -= mod();\
    \ return *this; }\r\n  MInt &operator*=(const MInt &x) { val = static_cast<unsigned\
    \ long long>(val) * x.val % mod(); return *this; }\r\n  MInt &operator/=(const\
    \ MInt &x) { return *this *= inv(x.val); }\r\n  bool operator==(const MInt &x)\
    \ const { return val == x.val; }\r\n  bool operator!=(const MInt &x) const { return\
    \ val != x.val; }\r\n  bool operator<(const MInt &x) const { return val < x.val;\
    \ }\r\n  bool operator<=(const MInt &x) const { return val <= x.val; }\r\n  bool\
    \ operator>(const MInt &x) const { return val > x.val; }\r\n  bool operator>=(const\
    \ MInt &x) const { return val >= x.val; }\r\n  MInt &operator++() { if (++val\
    \ == mod()) val = 0; return *this; }\r\n  MInt operator++(int) { MInt res = *this;\
    \ ++*this; return res; }\r\n  MInt &operator--() { val = (val == 0 ? mod() : val)\
    \ - 1; return *this; }\r\n  MInt operator--(int) { MInt res = *this; --*this;\
    \ return res; }\r\n  MInt operator+() const { return *this; }\r\n  MInt operator-()\
    \ const { return MInt(val ? mod() - val : 0); }\r\n  MInt operator+(const MInt\
    \ &x) const { return MInt(*this) += x; }\r\n  MInt operator-(const MInt &x) const\
    \ { return MInt(*this) -= x; }\r\n  MInt operator*(const MInt &x) const { return\
    \ MInt(*this) *= x; }\r\n  MInt operator/(const MInt &x) const { return MInt(*this)\
    \ /= x; }\r\n  friend std::ostream &operator<<(std::ostream &os, const MInt &x)\
    \ { return os << x.val; }\r\n  friend std::istream &operator>>(std::istream &is,\
    \ MInt &x) { long long val; is >> val; x = MInt(val); return is; }\r\nprivate:\r\
    \n  static int &mod() { static int divisor = 0; return divisor; }\r\n};\r\nnamespace\
    \ std { template <int ID> MInt<ID> abs(const MInt<ID> &x) { return x; } }\r\n\
    #line 4 \"math/catalan_number.hpp\"\n\r\ntemplate <int T>\r\nstd::vector<MInt<T>>\
    \ catalan_number(int n) {\r\n  using ModInt = MInt<T>;\r\n  ModInt::inv(n + 1,\
    \ true);\r\n  std::vector<ModInt> catalan(n + 1);\r\n  catalan[0] = 1;\r\n  for\
    \ (int i = 0; i < n; ++i) catalan[i + 1] = catalan[i] * ModInt::inv(i + 2) * 2\
    \ * (2 * i + 1);\r\n  return catalan;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"modint.hpp\"\r\n\r\ntemplate\
    \ <int T>\r\nstd::vector<MInt<T>> catalan_number(int n) {\r\n  using ModInt =\
    \ MInt<T>;\r\n  ModInt::inv(n + 1, true);\r\n  std::vector<ModInt> catalan(n +\
    \ 1);\r\n  catalan[0] = 1;\r\n  for (int i = 0; i < n; ++i) catalan[i + 1] = catalan[i]\
    \ * ModInt::inv(i + 2) * 2 * (2 * i + 1);\r\n  return catalan;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/catalan_number.hpp
  requiredBy: []
  timestamp: '2021-02-15 03:05:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/catalan_number.test.cpp
documentation_of: math/catalan_number.hpp
layout: document
title: "\u30AB\u30BF\u30E9\u30F3\u6570 (Catalan number)"
---

$$c_n = \dfrac{\binom{2n}{n}}{n + 1} = \dbinom{2n}{n} - \dbinom{2n}{n - 1}$$

で定義された $c$ である．

$$\begin{cases} c_0 = 1 \\ c_{n + 1} = \sum_{i = 0}^n c_i c_{n - i} \end{cases}$$

の特殊解である．

カタラン数 $c_n$ の適用可能な例
- 長さ $2n$ の correct bracket sequence の場合の数
- $n \times n$ マスの格子において左下から右上まで対角線をまたがない最短経路の個数
- $n + 1$ 個の葉を持つ二分木の個数
- $n + 1$ 人によるトーナメントの総数
- 凸 $n + 2$ 角形の三角形分割の個数


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`catalan_number<T>(n)`|カタラン数 $c_i \ (0 \leq i \leq n)$ の数表|


## 参考

- https://mathtrain.jp/catalan
- https://drive.google.com/file/d/1WC7Y2Ni-8elttUgorfbix9tO1fvYN3g3/view
- https://tubo28.me/compprog/algorithm/catalan-number/


## Verified

https://yukicoder.me/submissions/414045
