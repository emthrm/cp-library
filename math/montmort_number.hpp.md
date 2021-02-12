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
    \ <typename T>\r\nstd::vector<T> montmort_number(int n) {\r\n  std::vector<T>\
    \ montmort(n + 1, 0);\r\n  if (n >= 0) montmort[0] = 1;\r\n  for (int i = 2; i\
    \ <= n; ++i) montmort[i] = (montmort[i - 1] + montmort[i - 2]) * (i - 1);\r\n\
    \  return montmort;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<T>\
    \ montmort_number(int n) {\r\n  std::vector<T> montmort(n + 1, 0);\r\n  if (n\
    \ >= 0) montmort[0] = 1;\r\n  for (int i = 2; i <= n; ++i) montmort[i] = (montmort[i\
    \ - 1] + montmort[i - 2]) * (i - 1);\r\n  return montmort;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/montmort_number.hpp
  requiredBy: []
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/montmort_number.test.cpp
documentation_of: math/montmort_number.hpp
layout: document
title: "\u30E2\u30F3\u30E2\u30FC\u30EB\u6570 (Montmort number)"
---

$$a_n = \begin{cases} 0 & (n = 1) \\ 1 & (n = 2) \\ (n - 1)(a_{n - 1} + a_{n - 2}) & (n \geq 3) \end{cases}$$

となる完全順列の個数 $a_n$ のこと．これを解くと

$$a_n = n! \sum_{k = 2}^n \dfrac{(-1)^k}{k!} \ (n \geq 2)$$

が成り立つ．

母関数

$$M(x) = \dfrac{e^{-x}}{1 - x} \text{．}$$


### 完全順列 (攪乱順列, derangement)

大きさ $N$ の順列 $P$ の内，$P_i \neq i \ (1 \leq \forall i \leq N)$ を満たすものである．


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`montmort<T>(n)`|モンモール数 $a_i \ (1 \leq i \leq n)$ の数表|


## 参考

- https://mathtrain.jp/montmort
- http://kyuridenamida.hatenablog.com/entry/2016/04/27/015414


## Verified

https://judge.yosupo.jp/submission/2731
