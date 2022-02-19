---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/carmichael_function.hpp
    title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570"
  - icon: ':warning:'
    path: math/carmichael_function_init.hpp
    title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\u8868"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/least_common_multiple.test.cpp
    title: "\u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/least_common_multiple.hpp\"\n#include <algorithm>\r\
    \n\r\nlong long __lcm(const long long a, const long long b) {\r\n  return a /\
    \ std::__gcd(a, b) * b;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n\r\nlong long __lcm(const long long\
    \ a, const long long b) {\r\n  return a / std::__gcd(a, b) * b;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/least_common_multiple.hpp
  requiredBy:
  - math/carmichael_function.hpp
  - math/carmichael_function_init.hpp
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/least_common_multiple.test.cpp
documentation_of: math/least_common_multiple.hpp
layout: document
title: "\u6700\u5C0F\u516C\u500D\u6570 (least common multiple)"
---


## 時間計算量

$O(\log{\max \lbrace A, B \rbrace})$


## 使用法

||説明|
|:--:|:--:|
|`__lcm(a, b)`|$a$ と $b$ の最小公倍数|


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_C/review/4967150/emthrm/C++14
