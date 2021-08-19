---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: geometry/smallest_enclosing_circle.hpp
    title: "\u6700\u5C0F\u5305\u542B\u5186 (smallest enclosing circle)"
  - icon: ':heavy_check_mark:'
    path: graph/flow/matching/tutte_theorem.hpp
    title: "\u30BF\u30C3\u30C8\u306E\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/geometry/smallest_enclosing_circle.test.cpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u6700\u5C0F\u5305\u542B\u5186"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/tutte_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u30BF\
      \u30C3\u30C8\u306E\u5B9A\u7406"
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"util/xorshift.hpp\"\n#include <ctime>\r\n\r\nstruct Xor128\
    \ {\r\n  int rand() {\r\n    unsigned int t = x ^ (x << 11);\r\n    x = y; y =\
    \ z; z = w; w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\r\n    return static_cast<int>(w);\r\
    \n  }\r\n  int rand(int ub) {\r\n    int res = rand() % ub;\r\n    return res\
    \ < 0 ? res + ub : res;\r\n  }\r\n  int rand(int lb, int ub) { return lb + rand(ub\
    \ - lb); }\r\n  long long randll() {\r\n    unsigned long long res = static_cast<unsigned\
    \ long long>(rand()) << 32;\r\n    return static_cast<long long>(res | rand());\r\
    \n  }\r\n  long long randll(long long ub) {\r\n    long long res = randll() %\
    \ ub;\r\n    return res < 0 ? res + ub : res;\r\n  }\r\n  long long randll(long\
    \ long lb, long long ub) { return lb + randll(ub - lb); }\r\nprivate:\r\n  unsigned\
    \ int x = 123456789, y = 362436069, z = 521288629, w = static_cast<unsigned int>(std::time(nullptr));\r\
    \n} xor128;\r\n"
  code: "#pragma once\r\n#include <ctime>\r\n\r\nstruct Xor128 {\r\n  int rand() {\r\
    \n    unsigned int t = x ^ (x << 11);\r\n    x = y; y = z; z = w; w = (w ^ (w\
    \ >> 19)) ^ (t ^ (t >> 8));\r\n    return static_cast<int>(w);\r\n  }\r\n  int\
    \ rand(int ub) {\r\n    int res = rand() % ub;\r\n    return res < 0 ? res + ub\
    \ : res;\r\n  }\r\n  int rand(int lb, int ub) { return lb + rand(ub - lb); }\r\
    \n  long long randll() {\r\n    unsigned long long res = static_cast<unsigned\
    \ long long>(rand()) << 32;\r\n    return static_cast<long long>(res | rand());\r\
    \n  }\r\n  long long randll(long long ub) {\r\n    long long res = randll() %\
    \ ub;\r\n    return res < 0 ? res + ub : res;\r\n  }\r\n  long long randll(long\
    \ long lb, long long ub) { return lb + randll(ub - lb); }\r\nprivate:\r\n  unsigned\
    \ int x = 123456789, y = 362436069, z = 521288629, w = static_cast<unsigned int>(std::time(nullptr));\r\
    \n} xor128;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: util/xorshift.hpp
  requiredBy:
  - math/mod_sqrt.hpp
  - graph/flow/matching/tutte_theorem.hpp
  - geometry/smallest_enclosing_circle.hpp
  timestamp: '2021-02-15 03:05:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/mod_sqrt.test.cpp
  - test/math/formal_power_series/formal_power_series.6.test.cpp
  - test/math/is_primitive_root.test.cpp
  - test/graph/flow/matching/tutte_theorem.test.cpp
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
