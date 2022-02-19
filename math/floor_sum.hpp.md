---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/floor_sum.test.cpp
    title: "\u6570\u5B66/sum of floor of linear"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/floor_sum.hpp\"\n#include <utility>\r\n\r\nlong long\
    \ floor_sum(long long a, long long b, long long m, long long n) {\r\n  long long\
    \ res = 0;\r\n  if (a < 0) {\r\n    long long nxt_a = a % m;\r\n    if (nxt_a\
    \ < 0) nxt_a += m;\r\n    res -= n * (n - 1) / 2 * ((nxt_a - a) / m);\r\n    a\
    \ = nxt_a;\r\n  }\r\n  if (b < 0) {\r\n    long long nxt_b = b % m;\r\n    if\
    \ (nxt_b < 0) nxt_b += m;\r\n    res -= n * ((nxt_b - b) / m);\r\n    b = nxt_b;\r\
    \n  }\r\n  while (true) {\r\n    if (a >= m) {\r\n      res += n * (n - 1) / 2\
    \ * (a / m);\r\n      a %= m;\r\n    }\r\n    if (b >= m) {\r\n      res += n\
    \ * (b / m);\r\n      b %= m;\r\n    }\r\n    const long long y_max = a * n +\
    \ b;\r\n    if (y_max < m) break;\r\n    b = y_max % m;\r\n    n = y_max / m;\r\
    \n    std::swap(a, m);\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <utility>\r\n\r\nlong long floor_sum(long long a,\
    \ long long b, long long m, long long n) {\r\n  long long res = 0;\r\n  if (a\
    \ < 0) {\r\n    long long nxt_a = a % m;\r\n    if (nxt_a < 0) nxt_a += m;\r\n\
    \    res -= n * (n - 1) / 2 * ((nxt_a - a) / m);\r\n    a = nxt_a;\r\n  }\r\n\
    \  if (b < 0) {\r\n    long long nxt_b = b % m;\r\n    if (nxt_b < 0) nxt_b +=\
    \ m;\r\n    res -= n * ((nxt_b - b) / m);\r\n    b = nxt_b;\r\n  }\r\n  while\
    \ (true) {\r\n    if (a >= m) {\r\n      res += n * (n - 1) / 2 * (a / m);\r\n\
    \      a %= m;\r\n    }\r\n    if (b >= m) {\r\n      res += n * (b / m);\r\n\
    \      b %= m;\r\n    }\r\n    const long long y_max = a * n + b;\r\n    if (y_max\
    \ < m) break;\r\n    b = y_max % m;\r\n    n = y_max / m;\r\n    std::swap(a,\
    \ m);\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_sum.hpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/floor_sum.test.cpp
documentation_of: math/floor_sum.hpp
layout: document
title: sum of floor of linear
---

$$\sum_{i = 0}^{N - 1} \left\lfloor \frac{Ai + B}{M} \right\rfloor$$


## 時間計算量

$O(\log{M})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`floor_sum(a, b, m, n)`|$\sum_{i = 0}^{N - 1} \left\lfloor \frac{Ai + B}{M} \right\rfloor$|$M \in \mathbb{N}^+$|


## 参考

- https://rsk0315.hatenablog.com/entry/2020/12/13/231307
- https://qiita.com/R_olldIce/items/3e2c80baa6d5e6f3abe9#4-floor_sum
- https://github.com/atcoder/ac-library/blob/c8e527063415e2f9aaf87cf80f2c59730a46ed98/atcoder/math.hpp#L82-L97
- https://github.com/atcoder/ac-library/blob/6c88a70c8f95fef575af354900d107fbd0db1a12/atcoder/internal_math.hpp#L180-L207


## Verified

https://judge.yosupo.jp/submission/39036
