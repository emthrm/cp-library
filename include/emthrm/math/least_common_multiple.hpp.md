---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/emthrm/math/carmichael_function.hpp
    title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570"
  - icon: ':warning:'
    path: include/emthrm/math/carmichael_function_init.hpp
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
  bundledCode: "#line 1 \"include/emthrm/math/least_common_multiple.hpp\"\n\n\n\n\
    #if __cplusplus < 201703L\n\n#include <algorithm>\n\nnamespace emthrm {\n\nlong\
    \ long __lcm(const long long a, const long long b) {\n  return a / std::__gcd(a,\
    \ b) * b;\n}\n\n}  // namespace emthrm\n\n#endif\n\n\n"
  code: "#ifndef EMTHRM_MATH_LEAST_COMMON_MULTIPLE_HPP_\n#define EMTHRM_MATH_LEAST_COMMON_MULTIPLE_HPP_\n\
    \n#if __cplusplus < 201703L\n\n#include <algorithm>\n\nnamespace emthrm {\n\n\
    long long __lcm(const long long a, const long long b) {\n  return a / std::__gcd(a,\
    \ b) * b;\n}\n\n}  // namespace emthrm\n\n#endif\n\n#endif  // EMTHRM_MATH_LEAST_COMMON_MULTIPLE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/least_common_multiple.hpp
  requiredBy:
  - include/emthrm/math/carmichael_function.hpp
  - include/emthrm/math/carmichael_function_init.hpp
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/least_common_multiple.test.cpp
documentation_of: include/emthrm/math/least_common_multiple.hpp
layout: document
title: "\u6700\u5C0F\u516C\u500D\u6570 (least common multiple)"
---


## 時間計算量

$O(\log{\max \lbrace A, B \rbrace})$


## 仕様

|名前|戻り値|対応バージョン|
|:--|:--|:--|
|`long long __lcm(const long long a, const long long b);`|$a$ と $b$ の最小公倍数|C++14以前|


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_C/review/4967150/emthrm/C++14
