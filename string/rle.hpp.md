---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/rle.test.cpp
    title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rle.hpp\"\n#include <string>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\ntemplate <typename T = char, typename U = std::string>\r\
    \nstd::vector<std::pair<T, int>> rle(const U &s) {\r\n  int n = s.size();\r\n\
    \  std::vector<std::pair<T, int>> res;\r\n  T now = s[0];\r\n  int cnt = 1;\r\n\
    \  for (int i = 1; i < n; ++i) {\r\n    if (s[i] != now) {\r\n      res.emplace_back(now,\
    \ cnt);\r\n      cnt = 0;\r\n    }\r\n    now = s[i];\r\n    ++cnt;\r\n  }\r\n\
    \  res.emplace_back(now, cnt);\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <string>\r\n#include <utility>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T = char, typename U = std::string>\r\nstd::vector<std::pair<T,\
    \ int>> rle(const U &s) {\r\n  int n = s.size();\r\n  std::vector<std::pair<T,\
    \ int>> res;\r\n  T now = s[0];\r\n  int cnt = 1;\r\n  for (int i = 1; i < n;\
    \ ++i) {\r\n    if (s[i] != now) {\r\n      res.emplace_back(now, cnt);\r\n  \
    \    cnt = 0;\r\n    }\r\n    now = s[i];\r\n    ++cnt;\r\n  }\r\n  res.emplace_back(now,\
    \ cnt);\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rle.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/rle.test.cpp
documentation_of: string/rle.hpp
layout: document
title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (run length encoding)"
---


## 時間計算量

$O(\lvert S \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`rle<T = char, U = string>(s)`|ランレングス圧縮した $S$|


## Verified

https://atcoder.jp/contests/abc143/submissions/9291464