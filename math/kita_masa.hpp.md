---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/kita_masa.test.cpp
    title: "\u6570\u5B66/\u304D\u305F\u307E\u3055\u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/kita_masa.hpp\"\n#include <algorithm>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nT kita_masa(const std::vector<T> &c, const std::vector<T>\
    \ &a, long long n) {\r\n  if (n == 0) return a[0];\r\n  int k = c.size();\r\n\
    \  std::vector<T> coefficient[3];\r\n  for (int i = 0; i < 3; ++i) coefficient[i].assign(k,\
    \ 0);\r\n  if (k == 1) {\r\n    coefficient[0][0] = c[0] * a[0];\r\n  } else {\r\
    \n    coefficient[0][1] = 1;\r\n  }\r\n  auto succ = [&c, k, &coefficient]() ->\
    \ void {\r\n    for (int i = 0; i < k - 1; ++i) coefficient[0][i] += coefficient[0].back()\
    \ * c[i + 1];\r\n    coefficient[0].back() *= c[0];\r\n    std::rotate(coefficient[0].begin(),\
    \ coefficient[0].begin() + k - 1, coefficient[0].end());\r\n  };\r\n  for (int\
    \ bit = 62 - __builtin_clzll(n); bit >= 0; --bit) {\r\n    for (int i = 1; i <\
    \ 3; ++i) std::copy(coefficient[0].begin(), coefficient[0].end(), coefficient[i].begin());\r\
    \n    for (T &e : coefficient[1]) e *= coefficient[2][0];\r\n    for (int i =\
    \ 1; i < k; ++i) {\r\n      succ();\r\n      for (int j = 0; j < k; ++j) coefficient[1][j]\
    \ += coefficient[2][i] * coefficient[0][j];\r\n    }\r\n    coefficient[0].swap(coefficient[1]);\r\
    \n    if (n >> bit & 1) succ();\r\n  }\r\n  T res = 0;\r\n  for (int i = 0; i\
    \ < k; ++i) res += coefficient[0][i] * a[i];\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nT kita_masa(const std::vector<T> &c, const std::vector<T> &a,\
    \ long long n) {\r\n  if (n == 0) return a[0];\r\n  int k = c.size();\r\n  std::vector<T>\
    \ coefficient[3];\r\n  for (int i = 0; i < 3; ++i) coefficient[i].assign(k, 0);\r\
    \n  if (k == 1) {\r\n    coefficient[0][0] = c[0] * a[0];\r\n  } else {\r\n  \
    \  coefficient[0][1] = 1;\r\n  }\r\n  auto succ = [&c, k, &coefficient]() -> void\
    \ {\r\n    for (int i = 0; i < k - 1; ++i) coefficient[0][i] += coefficient[0].back()\
    \ * c[i + 1];\r\n    coefficient[0].back() *= c[0];\r\n    std::rotate(coefficient[0].begin(),\
    \ coefficient[0].begin() + k - 1, coefficient[0].end());\r\n  };\r\n  for (int\
    \ bit = 62 - __builtin_clzll(n); bit >= 0; --bit) {\r\n    for (int i = 1; i <\
    \ 3; ++i) std::copy(coefficient[0].begin(), coefficient[0].end(), coefficient[i].begin());\r\
    \n    for (T &e : coefficient[1]) e *= coefficient[2][0];\r\n    for (int i =\
    \ 1; i < k; ++i) {\r\n      succ();\r\n      for (int j = 0; j < k; ++j) coefficient[1][j]\
    \ += coefficient[2][i] * coefficient[0][j];\r\n    }\r\n    coefficient[0].swap(coefficient[1]);\r\
    \n    if (n >> bit & 1) succ();\r\n  }\r\n  T res = 0;\r\n  for (int i = 0; i\
    \ < k; ++i) res += coefficient[0][i] * a[i];\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/kita_masa.hpp
  requiredBy: []
  timestamp: '2021-04-14 13:53:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
- ~~http://sugarknri.hatenablog.com/entry/2017/11/18/233936~~
- http://yosupo.hatenablog.com/entry/2015/03/27/025132
- https://tjkendev.github.io/procon-library/cpp/series/kitamasa.html


## ToDo

- https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
- 高速きたまさ法
  - http://misawa.github.io/others/fast_kitamasa_method.html
  - https://yukicoder.me/problems/no/215/editorial
  - http://kmjp.hatenablog.jp/entry/2015/06/03/1000
  - http://sugarknri.hatenablog.com/entry/2017/11/18/233936
- Bostan-Mori のアルゴリズム
  - http://q.c.titech.ac.jp/docs/progs/polynomial_division.html
  - https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a
  - https://atcoder.jp/contests/abc198/submissions/21708598


## Verified

https://yukicoder.me/submissions/647774
