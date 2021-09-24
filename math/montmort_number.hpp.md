---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/montmort_number.test.cpp
    title: "\u6570\u5B66/\u30E2\u30F3\u30E2\u30FC\u30EB\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/montmort_number.hpp\"\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nstd::vector<T> montmort_number(const int n) {\r\n  std::vector<T>\
    \ montmort(n + 1, 0);\r\n  if (n >= 0) {\r\n    montmort[0] = 1;\r\n  }\r\n  for\
    \ (int i = 2; i <= n; ++i) {\r\n    montmort[i] = (montmort[i - 1] + montmort[i\
    \ - 2]) * (i - 1);\r\n  }\r\n  return montmort;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<T>\
    \ montmort_number(const int n) {\r\n  std::vector<T> montmort(n + 1, 0);\r\n \
    \ if (n >= 0) {\r\n    montmort[0] = 1;\r\n  }\r\n  for (int i = 2; i <= n; ++i)\
    \ {\r\n    montmort[i] = (montmort[i - 1] + montmort[i - 2]) * (i - 1);\r\n  }\r\
    \n  return montmort;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/montmort_number.hpp
  requiredBy: []
  timestamp: '2021-09-24 03:41:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/montmort_number.test.cpp
documentation_of: math/montmort_number.hpp
layout: document
title: "\u30E2\u30F3\u30E2\u30FC\u30EB\u6570 (Montmort number)"
---

$$!n = \begin{cases} 1 & (n = 0) \\ 0 & (n = 1) \\ (n - 1)(!(n - 1) + !(n - 2)) & (n \geq 2) \end{cases}$$

という漸化式をもつ，完全順列の個数 $!n$ である．これを解くと

$$!n = n! \sum_{k = 0}^n \dfrac{(-1)^k}{k!}$$

という一般項が得られる．

指数型母関数は

$$\sum_{n = 0}^\infty !n \frac{x^n}{n!} = \dfrac{e^{-x}}{1 - x} \text{．}$$

である．


### 完全順列 (complete permutation) / 攪乱順列 (derangement)

大きさ $N$ の順列 $P$ の内，$P_i \neq i \ (i = 1, 2, \ldots, N)$ を満たすものである．


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`montmort_number<T>(n)`|モンモール数 $!i \ (1 \leq i \leq n)$ の数表|


## 参考

- https://mathtrain.jp/montmort
- http://kyuridenamida.hatenablog.com/entry/2016/04/27/015414
- https://en.wikipedia.org/wiki/Derangement


## Verified

https://judge.yosupo.jp/submission/2731
