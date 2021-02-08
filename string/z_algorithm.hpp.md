---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/z_algorithm.test.cpp
    title: "\u6587\u5B57\u5217/Z algorithm"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.hpp\"\n#include <algorithm>\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<int> z_algorithm(const\
    \ T &s) {\r\n  int n = s.size();\r\n  std::vector<int> res(n, 0);\r\n  for (int\
    \ i = 1, j = 0; i < n; ++i) {\r\n    if (i + res[i - j] < j + res[j]) {\r\n  \
    \    res[i] = res[i - j];\r\n    } else {\r\n      res[i] = std::max(j + res[j]\
    \ - i, 0);\r\n      while (i + res[i] < n && s[i + res[i]] == s[res[i]]) ++res[i];\r\
    \n      j = i;\r\n    }\r\n  }\r\n  res[0] = n;\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nstd::vector<int> z_algorithm(const T &s) {\r\n  int n = s.size();\r\
    \n  std::vector<int> res(n, 0);\r\n  for (int i = 1, j = 0; i < n; ++i) {\r\n\
    \    if (i + res[i - j] < j + res[j]) {\r\n      res[i] = res[i - j];\r\n    }\
    \ else {\r\n      res[i] = std::max(j + res[j] - i, 0);\r\n      while (i + res[i]\
    \ < n && s[i + res[i]] == s[res[i]]) ++res[i];\r\n      j = i;\r\n    }\r\n  }\r\
    \n  res[0] = n;\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/z_algorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
title: Z algorithm
---

ある文字列 $S$ において $S$ と `S[i:|S|]` の最長共通接頭辞の長さを求めるアルゴリズムである．


## 時間計算量

$O(\lvert S \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`z_algorithm(s)`|$S$ と `S[i:|S|]` の最長共通接頭辞の長さ|


## 参考

- https://snuke.hatenablog.com/entry/2014/12/03/214243
- https://sen-comp.hatenablog.com/entry/2020/01/16/174230


## ToDo

- 動的 Z algorithm
  - https://heno239.hatenablog.com/entry/2020/07/07/140651


## Verified

https://judge.yosupo.jp/submission/27816
