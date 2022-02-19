---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/run_length_encoding.test.cpp
    title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/run_length_encoding.hpp\"\n#include <utility>\r\n\
    #include <vector>\r\n\r\ntemplate <typename T = char, typename U>\r\nstd::vector<std::pair<T,\
    \ int>> run_length_encoding(const U& s) {\r\n  const int n = s.size();\r\n  std::vector<std::pair<T,\
    \ int>> res;\r\n  if (n == 0) return res;\r\n  T ch = s.front();\r\n  int num\
    \ = 1;\r\n  for (int i = 1; i < n; ++i) {\r\n    if (s[i] != ch) {\r\n      res.emplace_back(ch,\
    \ num);\r\n      num = 0;\r\n    }\r\n    ch = s[i];\r\n    ++num;\r\n  }\r\n\
    \  res.emplace_back(ch, num);\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <utility>\r\n#include <vector>\r\n\r\ntemplate <typename\
    \ T = char, typename U>\r\nstd::vector<std::pair<T, int>> run_length_encoding(const\
    \ U& s) {\r\n  const int n = s.size();\r\n  std::vector<std::pair<T, int>> res;\r\
    \n  if (n == 0) return res;\r\n  T ch = s.front();\r\n  int num = 1;\r\n  for\
    \ (int i = 1; i < n; ++i) {\r\n    if (s[i] != ch) {\r\n      res.emplace_back(ch,\
    \ num);\r\n      num = 0;\r\n    }\r\n    ch = s[i];\r\n    ++num;\r\n  }\r\n\
    \  res.emplace_back(ch, num);\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2022-02-08 18:47:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/run_length_encoding.test.cpp
documentation_of: string/run_length_encoding.hpp
layout: document
title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (run length encoding)"
---


## 時間計算量

$O(\lvert S \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`run_length_encoding<T = char>(s)`|$S$ のランレングス圧縮|


## Verified

https://atcoder.jp/contests/abc143/submissions/9291464
