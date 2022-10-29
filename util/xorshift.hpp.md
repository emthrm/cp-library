---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/smallest_enclosing_circle.hpp
    title: "\u6700\u5C0F\u5305\u542B\u5186 (smallest enclosing circle)"
  - icon: ':heavy_check_mark:'
    path: graph/flow/matching/maximum_matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/smallest_enclosing_circle.test.cpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u6700\u5C0F\u5305\u542B\u5186"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/maximum_matching.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E00\
      \u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/formal_power_series.6.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570 (\u5E73\u65B9\u6839)"
  - icon: ':heavy_check_mark:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: test/math/mod_sqrt.test.cpp
    title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"util/xorshift.hpp\"\n#include <ctime>\n\nstruct Xor128 {\n\
    \  Xor128() : x(123456789), y(362436069), z(521288629), w(std::time(nullptr))\
    \ {}\n  int rand() {\n    unsigned int t = x ^ (x << 11);\n    x = y; y = z; z\
    \ = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n  int rand(const\
    \ int ub) {\n    const int res = rand() % ub;\n    return res < 0 ? res + ub :\
    \ res;\n  }\n  int rand(const int lb, const int ub) { return lb + rand(ub - lb);\
    \ }\n  long long randll() {\n    return (static_cast<unsigned long long>(rand())\
    \ << 32) | rand();\n  }\n  long long randll(const long long ub) {\n    const long\
    \ long res = randll() % ub;\n    return res < 0 ? res + ub : res;\n  }\n  long\
    \ long randll(const long long lb, const long long ub) {\n    return lb + randll(ub\
    \ - lb);\n  }\n private:\n  unsigned int x, y, z, w;\n} xor128;\n"
  code: "#pragma once\n#include <ctime>\n\nstruct Xor128 {\n  Xor128() : x(123456789),\
    \ y(362436069), z(521288629), w(std::time(nullptr)) {}\n  int rand() {\n    unsigned\
    \ int t = x ^ (x << 11);\n    x = y; y = z; z = w;\n    return w = (w ^ (w >>\
    \ 19)) ^ (t ^ (t >> 8));\n  }\n  int rand(const int ub) {\n    const int res =\
    \ rand() % ub;\n    return res < 0 ? res + ub : res;\n  }\n  int rand(const int\
    \ lb, const int ub) { return lb + rand(ub - lb); }\n  long long randll() {\n \
    \   return (static_cast<unsigned long long>(rand()) << 32) | rand();\n  }\n  long\
    \ long randll(const long long ub) {\n    const long long res = randll() % ub;\n\
    \    return res < 0 ? res + ub : res;\n  }\n  long long randll(const long long\
    \ lb, const long long ub) {\n    return lb + randll(ub - lb);\n  }\n private:\n\
    \  unsigned int x, y, z, w;\n} xor128;\n"
  dependsOn: []
  isVerificationFile: false
  path: util/xorshift.hpp
  requiredBy:
  - math/mod_sqrt.hpp
  - graph/flow/matching/maximum_matching.hpp
  - geometry/smallest_enclosing_circle.hpp
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/formal_power_series.6.test.cpp
  - test/math/mod_sqrt.test.cpp
  - test/math/is_primitive_root.test.cpp
  - test/graph/flow/matching/maximum_matching.test.cpp
  - test/geometry/smallest_enclosing_circle.test.cpp
documentation_of: util/xorshift.hpp
layout: document
title: xorshift
---

疑似乱数列生成法の一種である．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`xor128.rand()`|`int` 型の乱数||
|`xor128.rand(ub)`|`int` 型の乱数|$[0, \mathrm{ub})$|
|`xor128.rand(lb, ub)`|`int` 型の乱数|$[\mathrm{lb}, \mathrm{ub})$|
|`xor128.randll()`|`long long` 型の乱数||
|`xor128.randll(ub)`|`long long` 型の乱数|$[0, \mathrm{ub})$|
|`xor128.randll(lb, ub)`|`long long` 型の乱数|$[\mathrm{lb}, \mathrm{ub})$|

周期は $2^{128} - 1$ である．


## 参考

- https://ja.wikipedia.org/wiki/Xorshift
- ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!XorShift128.cpp~~
- https://nodchip.hatenadiary.org/entry/20090111/1231667839
