---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/ext_gcd.test.cpp
    title: "\u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ext_gcd.hpp\"\n#include <tuple>\n#include <utility>\n\
    \ntemplate <typename T>\nstd::pair<T, T> ext_gcd(T a, T b) {\n  T x = 1, y = 0;\n\
    \  for (T u = 0, v = 1; b;) {\n    const T q = a / b;\n    std::swap(a -= q *\
    \ b, b);\n    std::swap(x -= q * u, u);\n    std::swap(y -= q * v, v);\n  }\n\
    \  return a < 0 ? std::make_pair(-x, -y) : std::make_pair(x, y);\n}\n"
  code: "#pragma once\n#include <tuple>\n#include <utility>\n\ntemplate <typename\
    \ T>\nstd::pair<T, T> ext_gcd(T a, T b) {\n  T x = 1, y = 0;\n  for (T u = 0,\
    \ v = 1; b;) {\n    const T q = a / b;\n    std::swap(a -= q * b, b);\n    std::swap(x\
    \ -= q * u, u);\n    std::swap(y -= q * v, v);\n  }\n  return a < 0 ? std::make_pair(-x,\
    \ -y) : std::make_pair(x, y);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/ext_gcd.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/ext_gcd.test.cpp
documentation_of: math/ext_gcd.hpp
layout: document
title: "\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5 (extended Euclidean algorithm)"
---

$ax + by = \gcd(a, b)$ を満たす整数解 $(x, y)$ を求めるアルゴリズムである．

$ax + by = c \cdot \mathrm{gcd}(a, b)$ の特殊解を $(x, y) = (x^{\prime}, y^{\prime})$ とすると，一般解は $k \in \mathrm{Z}$ を用いて $(x, y) = \left(x^{\prime} + k \frac{b}{\mathrm{gcd}(a, b)}, y^{\prime} - k \frac{a}{\mathrm{gcd}(a, b)}\right)$ と表せる．


## 時間計算量

$O(\log{\max \lbrace A, B \rbrace})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`ext_gcd(a, b)`|$ax + by = \gcd(a, b)$ を満たす整数解 $(x, y)$|$a \neq 0,\ b \neq 0$ のとき $\lvert x \rvert \leq \left\lvert \frac{b}{\mathrm{gcd}(a, b)} \right\rvert,\ \lvert y \rvert \leq \left\lvert \frac{a}{\mathrm{gcd}(a, b)} \right\rvert$ が成り立つ．|


## 参考

- https://qiita.com/drken/items/b97ff231e43bce50199a
- https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
- https://ja.wikipedia.org/wiki/%E3%83%99%E3%82%BA%E3%83%BC%E3%81%AE%E7%AD%89%E5%BC%8F
- https://scol.hatenablog.com/entry/2019/10/19/180000
- https://divinejk.hatenablog.com/entry/2021/02/28/233332


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_E/review/5272349/emthrm/C++17
