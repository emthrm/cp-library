---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_quotients.test.cpp
    title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/enumerate_quotients.hpp\"\n#include <tuple>\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<std::tuple<T, T, T>> enumerate_quotients(const\
    \ T n) {\r\n  std::vector<std::tuple<T, T, T>> quotients;\r\n  for (T l = 1; l\
    \ <= n;) {\r\n    const T quotient = n / l, r = n / quotient + 1;\r\n    quotients.emplace_back(l,\
    \ r, quotient);\r\n    l = r;\r\n  }\r\n  return quotients;\r\n}\r\n"
  code: "#pragma once\r\n#include <tuple>\r\n#include <vector>\r\n\r\ntemplate <typename\
    \ T>\r\nstd::vector<std::tuple<T, T, T>> enumerate_quotients(const T n) {\r\n\
    \  std::vector<std::tuple<T, T, T>> quotients;\r\n  for (T l = 1; l <= n;) {\r\
    \n    const T quotient = n / l, r = n / quotient + 1;\r\n    quotients.emplace_back(l,\
    \ r, quotient);\r\n    l = r;\r\n  }\r\n  return quotients;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/enumerate_quotients.hpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/enumerate_quotients.test.cpp
documentation_of: math/enumerate_quotients.hpp
layout: document
title: "\u5546\u306E\u5217\u6319"
---


## 時間計算量

$O(\sqrt{N})$


## 使用法

||説明|
|:--:|:--:|
|`enumerate_quotients(n)`|$\lbrace (l, r, q) \mid \forall x \in \lbrace l, l + 1, \ldots, r - 1 \rbrace,\ \lfloor \frac{n}{x} \rfloor = q \rbrace$|


## 備考

1. $\left\lfloor \frac{N}{i} \right\rfloor = q$ を満たす $i$ の範囲は $\left(\left\lfloor \frac{N}{q + 1} \right\rfloor, \left\lfloor \frac{N}{q} \right\rfloor \right\rbrack$ を満たす．
2. $N \in \mathbb{N}^+$ に対して商を昇順に並べたものを $Q \mathrel{:=} (q_1, q_2, \ldots, q_k)$ ($k \in \mathbb{N}^+,\ q_1 < q_2 < \cdots < q_k$) とおく．$x \in Q$ に対して
   - $x^2 \leq N$ ならば $x = q_x$ が成り立ち，
   - $x^2 \geq N$ ならば $x = q_{k + 1 - N / x}$ が成り立つ．


## 参考

- https://twitter.com/noshi91/status/1278227768333852672

備考1
- https://twitter.com/heno_code/status/1495040694527741954

備考2
- https://twitter.com/maspy_stars/status/1495039893172412421


## Verified

https://atcoder.jp/contests/abc230/submissions/28839379
