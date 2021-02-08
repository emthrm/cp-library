---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/is_primitive_root.hpp
    title: "\u539F\u59CB\u6839\u5224\u5B9A"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/divisor.test.cpp
    title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
  - icon: ':x:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/divisor.hpp\"\n#include <algorithm>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nstd::vector<T> divisor(T val) {\r\n  std::vector<T>\
    \ res;\r\n  for (T i = 1; i * i <= val; ++i) {\r\n    if (val % i == 0) {\r\n\
    \      res.emplace_back(i);\r\n      if (i * i != val) res.emplace_back(val /\
    \ i);\r\n    }\r\n  }\r\n  std::sort(res.begin(), res.end());\r\n  return res;\r\
    \n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nstd::vector<T> divisor(T val) {\r\n  std::vector<T> res;\r\n\
    \  for (T i = 1; i * i <= val; ++i) {\r\n    if (val % i == 0) {\r\n      res.emplace_back(i);\r\
    \n      if (i * i != val) res.emplace_back(val / i);\r\n    }\r\n  }\r\n  std::sort(res.begin(),\
    \ res.end());\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy:
  - math/is_primitive_root.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/divisor.test.cpp
  - test/math/is_primitive_root.test.cpp
documentation_of: math/divisor.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---


## 時間計算量

$O(\sqrt{N})$


## 使用法

||説明|
|:--:|:--:|
|`divisor(val)`|$\mathrm{val}$ の約数|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] p.111


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2932/review/4088339/emthrm/C++14
