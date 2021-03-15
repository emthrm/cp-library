---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/divisor.test.cpp
    title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/divisor.hpp\"\n#include <algorithm>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nstd::vector<T> divisor(T n) {\r\n  std::vector<T>\
    \ res;\r\n  for (T i = 1; i * i <= n; ++i) {\r\n    if (n % i == 0) {\r\n    \
    \  res.emplace_back(i);\r\n      if (i * i != n) res.emplace_back(n / i);\r\n\
    \    }\r\n  }\r\n  std::sort(res.begin(), res.end());\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nstd::vector<T> divisor(T n) {\r\n  std::vector<T> res;\r\n \
    \ for (T i = 1; i * i <= n; ++i) {\r\n    if (n % i == 0) {\r\n      res.emplace_back(i);\r\
    \n      if (i * i != n) res.emplace_back(n / i);\r\n    }\r\n  }\r\n  std::sort(res.begin(),\
    \ res.end());\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
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

- プログラミングコンテストチャレンジブック \[第2版\] p.111


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2932/review/4088339/emthrm/C++14
