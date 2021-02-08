---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/inverse_element/mod_inv_fermat.hpp
    title: "\u9006\u5143 Fermat \u306E\u5C0F\u5B9A\u7406\u7248"
  - icon: ':warning:'
    path: math/inverse_element/mod_inv_phi.hpp
    title: "\u9006\u5143 \u30AA\u30A4\u30E9\u30FC\u306E\u5B9A\u7406\u7248"
  - icon: ':x:'
    path: math/is_primitive_root.hpp
    title: "\u539F\u59CB\u6839\u5224\u5B9A"
  - icon: ':x:'
    path: math/linear_congruence.hpp
    title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (linear congruence)"
  - icon: ':x:'
    path: math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (discrete logarithm problem)"
  - icon: ':question:'
    path: math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/fps/fps.6.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570 (\u5E73\u65B9\u6839)"
  - icon: ':x:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  - icon: ':x:'
    path: test/math/linear_congruence.test.cpp
    title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
  - icon: ':x:'
    path: test/math/mod_log.test.cpp
    title: "\u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C"
  - icon: ':x:'
    path: test/math/mod_pow.test.cpp
    title: "\u6570\u5B66/\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
  - icon: ':x:'
    path: test/math/mod_sqrt.test.cpp
    title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod_pow.hpp\"\n\r\nlong long mod_pow(long long base,\
    \ long long exponent, int mod) {\r\n  base %= mod;\r\n  long long res = 1;\r\n\
    \  while (exponent > 0) {\r\n    if (exponent & 1) (res *= base) %= mod;\r\n \
    \   (base *= base) %= mod;\r\n    exponent >>= 1;\r\n  }\r\n  return res;\r\n\
    }\r\n"
  code: "#pragma once\r\n\r\nlong long mod_pow(long long base, long long exponent,\
    \ int mod) {\r\n  base %= mod;\r\n  long long res = 1;\r\n  while (exponent >\
    \ 0) {\r\n    if (exponent & 1) (res *= base) %= mod;\r\n    (base *= base) %=\
    \ mod;\r\n    exponent >>= 1;\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.hpp
  requiredBy:
  - math/mod_sqrt.hpp
  - math/linear_congruence.hpp
  - math/is_primitive_root.hpp
  - math/inverse_element/mod_inv_phi.hpp
  - math/inverse_element/mod_inv_fermat.hpp
  - math/mod_log.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/mod_log.test.cpp
  - test/math/mod_sqrt.test.cpp
  - test/math/linear_congruence.test.cpp
  - test/math/is_primitive_root.test.cpp
  - test/math/fps/fps.6.test.cpp
  - test/math/mod_pow.test.cpp
documentation_of: math/mod_pow.hpp
layout: document
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
  , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
---

冪乗を高速に求めるアルゴリズムである．


## 時間計算量

$O(\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`mod_pow(base, exponent, mod)`|$\mathrm{base}^{\mathrm{exponent}} \bmod \ \mathrm{mod}$|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.114-116


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_B/review/4088294/emthrm/C++14
