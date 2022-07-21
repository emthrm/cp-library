---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/divisor.test.cpp
    title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/divisor.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <typename T>\nstd::vector<T> divisor(const T n) {\n  std::vector<T>\
    \ res;\n  T i = 1;\n  for (; i * i < n; ++i) {\n    if (n % i == 0) {\n      res.emplace_back(i);\n\
    \      res.emplace_back(n / i);\n    }\n  }\n  if (i * i == n && n % i == 0) res.emplace_back(i);\n\
    \  std::sort(res.begin(), res.end());\n  return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ T>\nstd::vector<T> divisor(const T n) {\n  std::vector<T> res;\n  T i = 1;\n\
    \  for (; i * i < n; ++i) {\n    if (n % i == 0) {\n      res.emplace_back(i);\n\
    \      res.emplace_back(n / i);\n    }\n  }\n  if (i * i == n && n % i == 0) res.emplace_back(i);\n\
    \  std::sort(res.begin(), res.end());\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/divisor.test.cpp
documentation_of: math/divisor.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---


## 時間計算量

$O(\sqrt{N})$


## 使用法

||説明|
|:--:|:--:|
|`divisor(n)`|$n$ の約数|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，p.111，マイナビ出版（2012）


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2932/review/4088339/emthrm/C++14
