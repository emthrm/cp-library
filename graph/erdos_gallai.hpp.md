---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/erdos_gallai.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30A8\u30EB\u30C7\u30B7\u30E5\u30FB\u30AC\u30E9\u30A4\
      \u306E\u5B9A\u7406"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/erdos_gallai.hpp\"\n#include <algorithm>\r\n#include\
    \ <functional>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nbool erdos_gallai(const\
    \ std::vector<T> &degree) {\r\n  int n = degree.size();\r\n  std::vector<T> deg(degree);\r\
    \n  std::sort(deg.begin(), deg.end(), std::greater<T>());\r\n  deg.insert(deg.begin(),\
    \ 0);\r\n  std::vector<long long> sum(n + 1, 0);\r\n  for (int i = 1; i <= n;\
    \ ++i) sum[i] = sum[i - 1] + deg[i];\r\n  if (sum[n] & 1) return false;\r\n  int\
    \ right = n;\r\n  for (int i = 1; i <= n; ++i) {\r\n    if (right < i) right =\
    \ i;\r\n    while (right > i && deg[right] < i) --right;\r\n    if (sum[i] > static_cast<long\
    \ long>(i) * (i - 1) + static_cast<long long>(i) * (right - i) + sum[n] - sum[right])\
    \ return false;\r\n  }\r\n  return true;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <functional>\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename T>\r\nbool erdos_gallai(const std::vector<T>\
    \ &degree) {\r\n  int n = degree.size();\r\n  std::vector<T> deg(degree);\r\n\
    \  std::sort(deg.begin(), deg.end(), std::greater<T>());\r\n  deg.insert(deg.begin(),\
    \ 0);\r\n  std::vector<long long> sum(n + 1, 0);\r\n  for (int i = 1; i <= n;\
    \ ++i) sum[i] = sum[i - 1] + deg[i];\r\n  if (sum[n] & 1) return false;\r\n  int\
    \ right = n;\r\n  for (int i = 1; i <= n; ++i) {\r\n    if (right < i) right =\
    \ i;\r\n    while (right > i && deg[right] < i) --right;\r\n    if (sum[i] > static_cast<long\
    \ long>(i) * (i - 1) + static_cast<long long>(i) * (right - i) + sum[n] - sum[right])\
    \ return false;\r\n  }\r\n  return true;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/erdos_gallai.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/erdos_gallai.test.cpp
documentation_of: graph/erdos_gallai.hpp
layout: document
title: "\u30A8\u30EB\u30C7\u30B7\u30E5\u30FB\u30AC\u30E9\u30A4\u306E\u5B9A\u7406 (Erd\u0151\
  s\u2013Gallai theorem)"
---

$$\text{降順の次数列 } d_1, d_2,\ldots, d_n \text{ を実現する単純無向グラフが存在する} \\ \Leftrightarrow \begin{cases} \sum_{i = 1}^n d_i \equiv 0 \pmod{2} \\ \sum_{i = 1}^k d_i \leq k(k-1) + \sum_{i = k+1}^n \min(d_i, k) \ (k = 1, 2,\ldots, n) \text{．} \end{cases}$$


## 時間計算量

$O(\lvert V \rvert \log{\lvert V \rvert})$


## 使用法

||説明|
|:--:|:--:|
|`erdos_gallai(degree)`|次数列を $\mathrm{degree}$ とする無向単純グラフが存在するか|


## 参考

- https://mathtrain.jp/shakehands


## Verified

https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/9252185
