---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/kita_masa.test.cpp
    title: "\u6570\u5B66/\u304D\u305F\u307E\u3055\u6CD5"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/kita_masa.hpp\"\n#include <algorithm>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nT kita_masa(const std::vector<T> &c, const std::vector<T>\
    \ &a, long long n) {\r\n  int k = c.size();\r\n  std::vector<T> coefficient((k\
    \ << 1) - 1, 0);\r\n  coefficient[0] = 1;\r\n  int now = 0;\r\n  std::vector<std::vector<T>>\
    \ base(2, std::vector<T>((k << 1) - 1, 0));\r\n  base[now][1] = 1;\r\n  for (;\
    \ n > 0; n >>= 1) {\r\n    if (n & 1) {\r\n      fill(base[now ^ 1].begin(), base[now\
    \ ^ 1].end(), 0);\r\n      for (int i = 0; i < k; ++i) for (int j = 0; j < k;\
    \ ++j) base[now ^ 1][i + j] += coefficient[i] * base[now][j];\r\n      fill(coefficient.begin(),\
    \ coefficient.end(), 0);\r\n      for (int i = (k << 1) - 2; i >= k; --i) {\r\n\
    \        coefficient[i] += base[now ^ 1][i];\r\n        for (int j = 0; j < k;\
    \ ++j) coefficient[i - k + j] += coefficient[i] * c[j];\r\n      }\r\n      for\
    \ (int i = 0; i < k; ++i) coefficient[i] += base[now ^ 1][i];\r\n    }\r\n   \
    \ fill(base[now ^ 1].begin(), base[now ^ 1].end(), 0);\r\n    for (int i = 0;\
    \ i < k; ++i) for (int j = 0; j < k; ++j) base[now ^ 1][i + j] += base[now][i]\
    \ * base[now][j];\r\n    now ^= 1;\r\n    for (int i = (k << 1) - 2; i >= k; --i)\
    \ for (int j = 0; j < k; ++j) base[now][i - k + j] += base[now][i] * c[j];\r\n\
    \  }\r\n  T res = 0;\r\n  for (int i = 0; i < k; ++i) res += coefficient[i] *\
    \ a[i];\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nT kita_masa(const std::vector<T> &c, const std::vector<T> &a,\
    \ long long n) {\r\n  int k = c.size();\r\n  std::vector<T> coefficient((k <<\
    \ 1) - 1, 0);\r\n  coefficient[0] = 1;\r\n  int now = 0;\r\n  std::vector<std::vector<T>>\
    \ base(2, std::vector<T>((k << 1) - 1, 0));\r\n  base[now][1] = 1;\r\n  for (;\
    \ n > 0; n >>= 1) {\r\n    if (n & 1) {\r\n      fill(base[now ^ 1].begin(), base[now\
    \ ^ 1].end(), 0);\r\n      for (int i = 0; i < k; ++i) for (int j = 0; j < k;\
    \ ++j) base[now ^ 1][i + j] += coefficient[i] * base[now][j];\r\n      fill(coefficient.begin(),\
    \ coefficient.end(), 0);\r\n      for (int i = (k << 1) - 2; i >= k; --i) {\r\n\
    \        coefficient[i] += base[now ^ 1][i];\r\n        for (int j = 0; j < k;\
    \ ++j) coefficient[i - k + j] += coefficient[i] * c[j];\r\n      }\r\n      for\
    \ (int i = 0; i < k; ++i) coefficient[i] += base[now ^ 1][i];\r\n    }\r\n   \
    \ fill(base[now ^ 1].begin(), base[now ^ 1].end(), 0);\r\n    for (int i = 0;\
    \ i < k; ++i) for (int j = 0; j < k; ++j) base[now ^ 1][i + j] += base[now][i]\
    \ * base[now][j];\r\n    now ^= 1;\r\n    for (int i = (k << 1) - 2; i >= k; --i)\
    \ for (int j = 0; j < k; ++j) base[now][i - k + j] += base[now][i] * c[j];\r\n\
    \  }\r\n  T res = 0;\r\n  for (int i = 0; i < k; ++i) res += coefficient[i] *\
    \ a[i];\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/kita_masa.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/kita_masa.test.cpp
documentation_of: math/kita_masa.hpp
layout: document
title: "\u304D\u305F\u307E\u3055\u6CD5"
---

$k$-階定数係数斉次線形漸化式の第 $n$ 項を高速に求めるアルゴリズムである．


## 時間計算量

$O(K^2 \log{N})$


## 使用法

||説明|
|:--:|:--:|
|`kita_masa(c, a, n)`|係数 $C$, 初項 $A$ で表される $k$-階定数係数斉次線形漸化式の第 $n$ 項|


## 参考

- https://lumakernel.github.io/ecasdqina/algorithm/Kitamasa
- http://sugarknri.hatenablog.com/entry/2017/11/18/233936
- http://yosupo.hatenablog.com/entry/2015/03/27/025132


## ToDo

- https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
- 高速きたまさ法
  - http://misawa.github.io/others/fast_kitamasa_method.html
  - https://yukicoder.me/problems/no/215/editorial
  - http://kmjp.hatenablog.jp/entry/2015/06/03/1000
  - http://sugarknri.hatenablog.com/entry/2017/11/18/233936
  - http://q.c.titech.ac.jp/docs/progs/polynomial_division.html
- Bostan-Mori のアルゴリズム
  - https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a


## Verified

https://atcoder.jp/contests/tdpc/submissions/9303052
