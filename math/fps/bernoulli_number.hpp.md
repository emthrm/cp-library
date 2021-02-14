---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/fps/fps.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/fps/faulhaber_with_fps.hpp
    title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\
      \u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/fps/bernoulli_number.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D9\u30EB\u30CC\u30FC\
      \u30A4\u6570"
  - icon: ':heavy_check_mark:'
    path: test/math/fps/faulhaber_with_fps.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/fps/bernoulli_number.hpp\"\n#include <vector>\r\n#line\
    \ 2 \"math/fps/fps.hpp\"\n#include <algorithm>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n#include <initializer_list>\r\n#line 7 \"math/fps/fps.hpp\"\n\
    \r\ntemplate <typename T>\r\nstruct FPS {\r\n  using MUL = std::function<std::vector<T>(const\
    \ std::vector<T>&, const std::vector<T>&)>;\r\n  using SQR = std::function<bool(const\
    \ T&, T&)>;\r\n  std::vector<T> co;\r\n  FPS(int deg = 0) : co(deg + 1, 0) {}\r\
    \n  FPS(const std::vector<T> &co) : co(co) {}\r\n  FPS(std::initializer_list<T>\
    \ init) : co(init.begin(), init.end()) {}\r\n  template <typename InputIter> FPS(InputIter\
    \ first, InputIter last) : co(first, last) {}\r\n  inline const T &operator[](int\
    \ term) const { return co[term]; }\r\n  inline T &operator[](int term) { return\
    \ co[term]; }\r\n  static void set_mul(MUL mul) { get_mul() = mul; }\r\n  static\
    \ void set_sqr(SQR sqr) { get_sqr() = sqr; }\r\n  void resize(int deg) { co.resize(deg\
    \ + 1, 0); }\r\n  void shrink() { while (co.size() > 1 && co.back() == 0) co.pop_back();\
    \ }\r\n  int degree() const { return static_cast<int>(co.size()) - 1; }\r\n  FPS\
    \ &operator=(const std::vector<T> &new_co) {\r\n    co.resize(new_co.size());\r\
    \n    std::copy(new_co.begin(), new_co.end(), co.begin());\r\n    return *this;\r\
    \n  }\r\n  FPS &operator=(const FPS &x) {\r\n    co.resize(x.co.size());\r\n \
    \   std::copy(x.co.begin(), x.co.end(), co.begin());\r\n    return *this;\r\n\
    \  }\r\n  FPS &operator+=(const FPS &x) {\r\n    int n = x.co.size();\r\n    if\
    \ (n > co.size()) resize(n - 1);\r\n    for (int i = 0; i < n; ++i) co[i] += x.co[i];\r\
    \n    return *this;\r\n  }\r\n  FPS &operator-=(const FPS &x) {\r\n    int n =\
    \ x.co.size();\r\n    if (n > co.size()) resize(n - 1);\r\n    for (int i = 0;\
    \ i < n; ++i) co[i] -= x.co[i];\r\n    return *this;\r\n  }\r\n  FPS &operator*=(T\
    \ x) {\r\n    for (T &e : co) e *= x;\r\n    return *this;\r\n  }\r\n  FPS &operator*=(const\
    \ FPS &x) { return *this = get_mul()(co, x.co); }\r\n  FPS &operator/=(T x) {\r\
    \n    assert(x != 0);\r\n    T inv_x = static_cast<T>(1) / x;\r\n    for (T &e\
    \ : co) e *= inv_x;\r\n    return *this;\r\n  }\r\n  FPS &operator/=(const FPS\
    \ &x) {\r\n    int sz = x.co.size();\r\n    if (sz > co.size()) return *this =\
    \ FPS();\r\n    int n = co.size() - sz + 1;\r\n    FPS a(co.rbegin(), co.rbegin()\
    \ + n), b(x.co.rbegin(), x.co.rbegin() + std::min(sz, n));\r\n    b = b.inv(n\
    \ - 1);\r\n    a *= b;\r\n    return *this = FPS(a.co.rend() - n, a.co.rend());\r\
    \n  }\r\n  FPS &operator%=(const FPS &x) {\r\n    *this -= *this / x * x;\r\n\
    \    co.resize(static_cast<int>(x.co.size()) - 1);\r\n    if (co.empty()) co =\
    \ {0};\r\n    return *this;\r\n  }\r\n  FPS &operator<<=(int n) {\r\n    co.insert(co.begin(),\
    \ n, 0);\r\n    return *this;\r\n  }\r\n  FPS &operator>>=(int n) {\r\n    if\
    \ (co.size() < n) return *this = FPS();\r\n    co.erase(co.begin(), co.begin()\
    \ + n);\r\n    return *this;\r\n  }\r\n  bool operator==(const FPS &x) const {\r\
    \n    FPS a(*this), b(x);\r\n    a.shrink(); b.shrink();\r\n    int n = a.co.size();\r\
    \n    if (n != b.co.size()) return false;\r\n    for (int i = 0; i < n; ++i) if\
    \ (a.co[i] != b.co[i]) return false;\r\n    return true;\r\n  }\r\n  bool operator!=(const\
    \ FPS &x) const { return !(*this == x); }\r\n  FPS operator+() const { return\
    \ *this; }\r\n  FPS operator-() const {\r\n    FPS res(*this);\r\n    for (T &e\
    \ : res.co) e = -e;\r\n    return res;\r\n  }\r\n  FPS operator+(const FPS &x)\
    \ const { return FPS(*this) += x; }\r\n  FPS operator-(const FPS &x) const { return\
    \ FPS(*this) -= x; }\r\n  FPS operator*(T x) const { return FPS(*this) *= x; }\r\
    \n  FPS operator*(const FPS &x) const { return FPS(*this) *= x; }\r\n  FPS operator/(T\
    \ x) const { return FPS(*this) /= x; }\r\n  FPS operator/(const FPS &x) const\
    \ { return FPS(*this) /= x; }\r\n  FPS operator%(const FPS &x) const { return\
    \ FPS(*this) %= x; }\r\n  FPS operator<<(int n) const { return FPS(*this) <<=\
    \ n; }\r\n  FPS operator>>(int n) const { return FPS(*this) >>= n; }\r\n  T horner(T\
    \ x) const {\r\n    T res = 0;\r\n    for (int i = static_cast<int>(co.size())\
    \ - 1; i >= 0; --i) (res *= x) += co[i];\r\n    return res;\r\n  }\r\n  FPS differential()\
    \ const {\r\n    int n = co.size();\r\n    assert(n >= 1);\r\n    FPS res(n -\
    \ 1);\r\n    for (int i = 1; i < n; ++i) res.co[i - 1] = co[i] * i;\r\n    return\
    \ res;\r\n  }\r\n  FPS integral() const {\r\n    int n = co.size();\r\n    FPS\
    \ res(n + 1);\r\n    for (int i = 0; i < n; ++i) res[i + 1] = co[i] / (i + 1);\r\
    \n    return res;\r\n  }\r\n  FPS exp(int deg = -1) const {\r\n    assert(co[0]\
    \ == 0);\r\n    int n = co.size();\r\n    if (deg == -1) deg = n - 1;\r\n    FPS\
    \ one{1}, res = one;\r\n    for (int i = 1; i <= deg; i <<= 1) {\r\n      res\
    \ *= FPS(co.begin(), co.begin() + std::min(n, i << 1)) - res.log((i << 1) - 1)\
    \ + one;\r\n      res.co.resize(i << 1);\r\n    }\r\n    res.co.resize(deg + 1);\r\
    \n    return res;\r\n  }\r\n  FPS inv(int deg = -1) const {\r\n    assert(co[0]\
    \ != 0);\r\n    int n = co.size();\r\n    if (deg == -1) deg = n - 1;\r\n    FPS\
    \ res{static_cast<T>(1) / co[0]};\r\n    for (int i = 1; i <= deg; i <<= 1) {\r\
    \n      res = res + res - res * res * FPS(co.begin(), co.begin() + std::min(n,\
    \ i << 1));\r\n      res.co.resize(i << 1);\r\n    }\r\n    res.co.resize(deg\
    \ + 1);\r\n    return res;\r\n  }\r\n  FPS log(int deg = -1) const {\r\n    assert(co[0]\
    \ == 1);\r\n    if (deg == -1) deg = static_cast<int>(co.size()) - 1;\r\n    FPS\
    \ integrand = differential() * inv(deg - 1);\r\n    integrand.co.resize(deg);\r\
    \n    return integrand.integral();\r\n  }\r\n  FPS pow(long long exponent, int\
    \ deg = -1) const {\r\n    int n = co.size();\r\n    if (deg == -1) deg = n -\
    \ 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      if (co[i] != 0) {\r\n     \
    \   long long shift = exponent * i;\r\n        if (shift > deg) break;\r\n   \
    \     T tmp = 1, base = co[i];\r\n        long long e = exponent;\r\n        while\
    \ (e > 0) {\r\n          if (e & 1) tmp *= base;\r\n          base *= base;\r\n\
    \          e >>= 1;\r\n        }\r\n        return ((((*this >> i) * (static_cast<T>(1)\
    \ / co[i])).log(deg - shift) * static_cast<T>(exponent)).exp(deg - shift) * tmp)\
    \ << shift;\r\n      }\r\n    }\r\n    return FPS(deg);\r\n  }\r\n  FPS mod_pow(long\
    \ long exponent, const FPS &md) const {\r\n    FPS inv_rev_md = FPS(md.co.rbegin(),\
    \ md.co.rend()).inv();\r\n    int deg_of_md = md.co.size();\r\n    auto mod_mul\
    \ = [&](FPS &multiplicand, const FPS &multiplier) -> void {\r\n      multiplicand\
    \ *= multiplier;\r\n      if (deg_of_md <= multiplicand.co.size()) {\r\n     \
    \   int n = multiplicand.co.size() - deg_of_md + 1;\r\n        FPS quotient =\
    \ FPS(multiplicand.co.rbegin(), multiplicand.co.rbegin() + n) * FPS(inv_rev_md.co.begin(),\
    \ inv_rev_md.co.begin() + std::min(static_cast<int>(inv_rev_md.co.size()), n));\r\
    \n        multiplicand -= FPS(quotient.co.rend() - n, quotient.co.rend()) * md;\r\
    \n      }\r\n      multiplicand.co.resize(deg_of_md - 1);\r\n      if (multiplicand.co.empty())\
    \ multiplicand.co = {0};\r\n    };\r\n    FPS res{1}, base = *this;\r\n    mod_mul(base,\
    \ res);\r\n    while (exponent > 0) {\r\n      if (exponent & 1) mod_mul(res,\
    \ base);\r\n      mod_mul(base, base);\r\n      exponent >>= 1;\r\n    }\r\n \
    \   return res;\r\n  }\r\n  FPS sqrt(int deg = -1) const {\r\n    int n = co.size();\r\
    \n    if (deg == -1) deg = n - 1;\r\n    if (co[0] == 0) {\r\n      for (int i\
    \ = 1; i < n; ++i) {\r\n        if (co[i] == 0) continue;\r\n        if (i & 1)\
    \ return FPS(-1);\r\n        int shift = i >> 1;\r\n        if (deg < shift) break;\r\
    \n        FPS res = (*this >> i).sqrt(deg - shift);\r\n        if (res.co.empty())\
    \ return FPS(-1);\r\n        res <<= shift;\r\n        res.resize(deg);\r\n  \
    \      return res;\r\n      }\r\n      return FPS(deg);\r\n    }\r\n    T s;\r\
    \n    if (!get_sqr()(co[0], s)) return FPS(-1);\r\n    FPS res{s};\r\n    T half\
    \ = static_cast<T>(1) / 2;\r\n    for (int i = 1; i <= deg; i <<= 1) {\r\n   \
    \   (res += FPS(co.begin(), co.begin() + std::min(n, i << 1)) * res.inv((i <<\
    \ 1) - 1)) *= half;\r\n    }\r\n    res.resize(deg);\r\n    return res;\r\n  }\r\
    \n  FPS translate(T c) const {\r\n    int n = co.size();\r\n    std::vector<T>\
    \ fact(n, 1), inv_fact(n, 1);\r\n    for (int i = 1; i < n; ++i) fact[i] = fact[i\
    \ - 1] * i;\r\n    inv_fact[n - 1] = static_cast<T>(1) / fact[n - 1];\r\n    for\
    \ (int i = n - 1; i > 0; --i) inv_fact[i - 1] = inv_fact[i] * i;\r\n    std::vector<T>\
    \ g(n), ex(n);\r\n    for (int i = 0; i < n; ++i) g[n - 1 - i] = co[i] * fact[i];\r\
    \n    T pow_c = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      ex[i] = pow_c\
    \ * inv_fact[i];\r\n      pow_c *= c;\r\n    }\r\n    std::vector<T> conv = get_mul()(g,\
    \ ex);\r\n    FPS res(n - 1);\r\n    for (int i = 0; i < n; ++i) res[i] = conv[n\
    \ - 1 - i] * inv_fact[i];\r\n    return res;\r\n  }\r\nprivate:\r\n  static MUL\
    \ &get_mul() {\r\n    static MUL mul = [](const std::vector<T> &a, const std::vector<T>\
    \ &b) -> std::vector<T> {\r\n      int n = a.size(), m = b.size();\r\n      std::vector<T>\
    \ res(n + m - 1, 0);\r\n      for (int i = 0; i < n; ++i) for (int j = 0; j <\
    \ m; ++j) res[i + j] += a[i] * b[j];\r\n      return res;\r\n    };\r\n    return\
    \ mul;\r\n  }\r\n  static SQR &get_sqr() {\r\n    static SQR sqr = [](const T\
    \ &a, T &res) -> bool { return false; };\r\n    return sqr;\r\n  }\r\n};\r\n#line\
    \ 4 \"math/fps/bernoulli_number.hpp\"\n\r\ntemplate <typename T>\r\nstd::vector<T>\
    \ bernoulli_number(int n) {\r\n  FPS<T> bernoulli(n);\r\n  bernoulli[0] = 1;\r\
    \n  for (int i = 1; i <= n; ++i) bernoulli[i] = bernoulli[i - 1] / (i + 1);\r\n\
    \  bernoulli = bernoulli.inv(n);\r\n  T fact = 1;\r\n  for (int i = 0; i <= n;\
    \ ++i) {\r\n    bernoulli[i] *= fact;\r\n    fact *= i + 1;\r\n  }\r\n  return\
    \ bernoulli.co;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"fps.hpp\"\r\n\r\ntemplate\
    \ <typename T>\r\nstd::vector<T> bernoulli_number(int n) {\r\n  FPS<T> bernoulli(n);\r\
    \n  bernoulli[0] = 1;\r\n  for (int i = 1; i <= n; ++i) bernoulli[i] = bernoulli[i\
    \ - 1] / (i + 1);\r\n  bernoulli = bernoulli.inv(n);\r\n  T fact = 1;\r\n  for\
    \ (int i = 0; i <= n; ++i) {\r\n    bernoulli[i] *= fact;\r\n    fact *= i + 1;\r\
    \n  }\r\n  return bernoulli.co;\r\n}\r\n"
  dependsOn:
  - math/fps/fps.hpp
  isVerificationFile: false
  path: math/fps/bernoulli_number.hpp
  requiredBy:
  - math/fps/faulhaber_with_fps.hpp
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/fps/faulhaber_with_fps.test.cpp
  - test/math/fps/bernoulli_number.test.cpp
documentation_of: math/fps/bernoulli_number.hpp
layout: document
title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570 (Bernoulli number)"
---

$$\dfrac{x}{e^x - 1} = \sum_{n = 0}^{\infty} B_n \frac{x^n}{n!}$$

で定義される $B_n$ である．

$$\begin{cases} B_0 = 1 \\ B_n = -\dfrac{1}{n + 1} \sum_{k = 0}^{n - 1} \binom{n + 1}{k} B_k \end{cases}$$

なる漸化式より計算ができる．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`bernoulli_number<T>(n)`|ベルヌーイ数 $B_i \ (0 \leq i \leq n)$ の数表|


## 参考

- https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0


## Verified

https://judge.yosupo.jp/submission/3792