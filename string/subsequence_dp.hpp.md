---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/subsequence_dp.test.cpp
    title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/subsequence_dp.hpp\"\n#include <string>\r\n#include\
    \ <vector>\r\n\r\nstd::vector<std::vector<int>> nx_init(const std::string &s,\
    \ const char basis = 'a', const int char_sz = 26) {\r\n  int n = s.size();\r\n\
    \  std::vector<std::vector<int>> nx(n, std::vector<int>(char_sz, n));\r\n  nx[n\
    \ - 1][s[n - 1] - basis] = n - 1;\r\n  for (int i = n - 2; i >= 0; --i) {\r\n\
    \    for (int j = 0; j < char_sz; ++j) nx[i][j] = nx[i + 1][j];\r\n    nx[i][s[i]\
    \ - basis] = i;\r\n  }\r\n  return nx;\r\n}\r\n"
  code: "#pragma once\r\n#include <string>\r\n#include <vector>\r\n\r\nstd::vector<std::vector<int>>\
    \ nx_init(const std::string &s, const char basis = 'a', const int char_sz = 26)\
    \ {\r\n  int n = s.size();\r\n  std::vector<std::vector<int>> nx(n, std::vector<int>(char_sz,\
    \ n));\r\n  nx[n - 1][s[n - 1] - basis] = n - 1;\r\n  for (int i = n - 2; i >=\
    \ 0; --i) {\r\n    for (int j = 0; j < char_sz; ++j) nx[i][j] = nx[i + 1][j];\r\
    \n    nx[i][s[i] - basis] = i;\r\n  }\r\n  return nx;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/subsequence_dp.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/subsequence_dp.test.cpp
documentation_of: string/subsequence_dp.hpp
layout: document
title: "\u90E8\u5206\u5217 DP"
---


## 時間計算量

文字の種類数を $K$ とおくと $O(K \lvert S \rvert)$．


## 使用法

||説明|
|:--:|:--:|
|`nx_init(s, 基準 = 'a', 種類数 = 26)`|$S$ の $i$ 文字目以降 (inclusive) で最初に文字 $c$ が現れるインデックス|


## 参考

- https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd


## Verified

https://codeforces.com/contest/1149/submission/68086082
