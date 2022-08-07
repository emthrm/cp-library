---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/run_length_encoding.test.cpp
    title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/run_length_encoding.hpp\"\n#include <utility>\n#include\
    \ <vector>\n\ntemplate <typename T = char, typename U>\nstd::vector<std::pair<T,\
    \ int>> run_length_encoding(const U& s) {\n  const int n = s.size();\n  std::vector<std::pair<T,\
    \ int>> res;\n  if (n == 0) return res;\n  T ch = s.front();\n  int num = 1;\n\
    \  for (int i = 1; i < n; ++i) {\n    if (s[i] != ch) {\n      res.emplace_back(ch,\
    \ num);\n      num = 0;\n    }\n    ch = s[i];\n    ++num;\n  }\n  res.emplace_back(ch,\
    \ num);\n  return res;\n}\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ T = char, typename U>\nstd::vector<std::pair<T, int>> run_length_encoding(const\
    \ U& s) {\n  const int n = s.size();\n  std::vector<std::pair<T, int>> res;\n\
    \  if (n == 0) return res;\n  T ch = s.front();\n  int num = 1;\n  for (int i\
    \ = 1; i < n; ++i) {\n    if (s[i] != ch) {\n      res.emplace_back(ch, num);\n\
    \      num = 0;\n    }\n    ch = s[i];\n    ++num;\n  }\n  res.emplace_back(ch,\
    \ num);\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
