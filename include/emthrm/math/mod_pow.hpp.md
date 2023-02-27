---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/enumerate_k-th_power.hpp
    title: $i^k \bmod m$ ($0 \leq i \leq n$)
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/is_primitive_root.hpp
    title: "\u539F\u59CB\u6839 (primitive root) \u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (discrete logarithm problem)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59 (quadratic residue)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_k-th_power.test.cpp
    title: "\u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)"
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/formal_power_series.6.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570\uFF08\u5E73\u65B9\u6839\uFF09"
  - icon: ':heavy_check_mark:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: test/math/mod_log.test.cpp
    title: "\u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C"
  - icon: ':heavy_check_mark:'
    path: test/math/mod_pow.test.cpp
    title: "\u6570\u5B66/\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
  - icon: ':heavy_check_mark:'
    path: test/math/mod_sqrt.test.cpp
    title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/mod_pow.hpp\"\n\n\n\nnamespace emthrm\
    \ {\n\nlong long mod_pow(long long x, long long n, const int m) {\n  if ((x %=\
    \ m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0; n >>= 1) {\n    if (n\
    \ & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n  return res;\n}\n\n}\
    \  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_MOD_POW_HPP_\n#define EMTHRM_MATH_MOD_POW_HPP_\n\nnamespace\
    \ emthrm {\n\nlong long mod_pow(long long x, long long n, const int m) {\n  if\
    \ ((x %= m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0; n >>= 1) {\n \
    \   if (n & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n  return res;\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOD_POW_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/mod_pow.hpp
  requiredBy:
  - include/emthrm/math/mod_log.hpp
  - include/emthrm/math/enumerate_k-th_power.hpp
  - include/emthrm/math/is_primitive_root.hpp
  - include/emthrm/math/mod_sqrt.hpp
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/mod_pow.test.cpp
  - test/math/mod_sqrt.test.cpp
  - test/math/is_primitive_root.test.cpp
  - test/math/mod_log.test.cpp
  - test/math/formal_power_series/formal_power_series.6.test.cpp
  - test/math/enumerate_k-th_power.test.cpp
documentation_of: include/emthrm/math/mod_pow.hpp
layout: document
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
  \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
---

累乗を高速に求めるアルゴリズムである。


## 時間計算量

$O(\log{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`long long mod_pow(long long x, long long n, const int m);`|$x^n \bmod{m}$|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.114-116，マイナビ出版（2012）


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_B/review/4088294/emthrm/C++14
