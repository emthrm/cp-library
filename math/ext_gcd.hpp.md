---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/crt.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
  - icon: ':warning:'
    path: math/inverse_element/mod_inv_extgcd2.hpp
    title: "\u9006\u5143 \u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5\u72482"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/crt.test.cpp
    title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: test/math/ext_gcd.test.cpp
    title: "\u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ext_gcd.hpp\"\n#include <tuple>\r\n#include <utility>\r\
    \n\r\ntemplate <typename T>\r\nstd::pair<T, T> ext_gcd(T a, T b) {\r\n  if (b\
    \ == 0) return {1, 0};\r\n  T fst, snd; std::tie(fst, snd) = ext_gcd(b, a % b);\r\
    \n  return {snd, fst - a / b * snd};\r\n}\r\n"
  code: "#pragma once\r\n#include <tuple>\r\n#include <utility>\r\n\r\ntemplate <typename\
    \ T>\r\nstd::pair<T, T> ext_gcd(T a, T b) {\r\n  if (b == 0) return {1, 0};\r\n\
    \  T fst, snd; std::tie(fst, snd) = ext_gcd(b, a % b);\r\n  return {snd, fst -\
    \ a / b * snd};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/ext_gcd.hpp
  requiredBy:
  - math/crt.hpp
  - math/inverse_element/mod_inv_extgcd2.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/ext_gcd.test.cpp
  - test/math/crt.test.cpp
documentation_of: math/ext_gcd.hpp
layout: document
title: "\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5 (extended Euclidean algorithm)"
---

$ax + by = \gcd(a, b)$ を満たす整数解 $(x, y)$ を求めるアルゴリズムである．


## 時間計算量

$O(\log{\max \lbrace A, B \rbrace})$


## 使用法

||説明|
|:--:|:--:|
|`ext_gcd(a, b)`|$ax + by = \gcd(a, b)$ を満たす整数解 $(x, y)$|


## 参考

- https://qiita.com/drken/items/b97ff231e43bce50199a


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_E/review/4088355/emthrm/C++14
