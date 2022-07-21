---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/enumerate_k-th_power.hpp
    title: $i^k \bmod m$ ($0 \leq i \leq n$)
  - icon: ':x:'
    path: math/is_primitive_root.hpp
    title: "\u539F\u59CB\u6839\u5224\u5B9A"
  - icon: ':x:'
    path: math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (discrete logarithm problem)"
  - icon: ':x:'
    path: math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/enumerate_k-th_power.test.cpp
    title: "\u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)"
  - icon: ':x:'
    path: test/math/formal_power_series/formal_power_series.6.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570 (\u5E73\u65B9\u6839)"
  - icon: ':x:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
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
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod_pow.hpp\"\n\nlong long mod_pow(long long x, long\
    \ long n, const int m) {\n  if ((x %= m) < 0) x += m;\n  long long res = 1;\n\
    \  for (; n > 0; n >>= 1) {\n    if (n & 1) res = (res * x) % m;\n    x = (x *\
    \ x) % m;\n  }\n  return res;\n}\n"
  code: "#pragma once\n\nlong long mod_pow(long long x, long long n, const int m)\
    \ {\n  if ((x %= m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0; n >>=\
    \ 1) {\n    if (n & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.hpp
  requiredBy:
  - math/mod_sqrt.hpp
  - math/enumerate_k-th_power.hpp
  - math/mod_log.hpp
  - math/is_primitive_root.hpp
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/mod_sqrt.test.cpp
  - test/math/enumerate_k-th_power.test.cpp
  - test/math/mod_pow.test.cpp
  - test/math/mod_log.test.cpp
  - test/math/is_primitive_root.test.cpp
  - test/math/formal_power_series/formal_power_series.6.test.cpp
documentation_of: math/mod_pow.hpp
layout: document
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
  \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
---

累乗を高速に求めるアルゴリズムである．


## 時間計算量

$O(\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`mod_pow(x, n, m)`|$x^n \bmod{m}$|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.114-116，マイナビ出版（2012）


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_B/review/4088294/emthrm/C++14
