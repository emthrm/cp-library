---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/enumerate_quotients.test.cpp
    title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  verificationStatus: LIBRARY_ALL_WA
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


## 参考

- https://twitter.com/noshi91/status/1278227768333852672


## Verified

https://atcoder.jp/contests/abc230/submissions/28839379
