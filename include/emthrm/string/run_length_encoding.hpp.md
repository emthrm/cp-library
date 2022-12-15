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
  bundledCode: "#line 1 \"include/emthrm/string/run_length_encoding.hpp\"\n\n\n\n\
    #include <utility>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ T = char, typename U>\nstd::vector<std::pair<T, int>> run_length_encoding(const\
    \ U& s) {\n  const int n = s.size();\n  std::vector<std::pair<T, int>> res;\n\
    \  if (n == 0) return res;\n  T ch = s.front();\n  int num = 1;\n  for (int i\
    \ = 1; i < n; ++i) {\n    if (s[i] != ch) {\n      res.emplace_back(ch, num);\n\
    \      num = 0;\n    }\n    ch = s[i];\n    ++num;\n  }\n  res.emplace_back(ch,\
    \ num);\n  return res;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_STRING_RUN_LENGTH_ENCODING_HPP_\n#define EMTHRM_STRING_RUN_LENGTH_ENCODING_HPP_\n\
    \n#include <utility>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ T = char, typename U>\nstd::vector<std::pair<T, int>> run_length_encoding(const\
    \ U& s) {\n  const int n = s.size();\n  std::vector<std::pair<T, int>> res;\n\
    \  if (n == 0) return res;\n  T ch = s.front();\n  int num = 1;\n  for (int i\
    \ = 1; i < n; ++i) {\n    if (s[i] != ch) {\n      res.emplace_back(ch, num);\n\
    \      num = 0;\n    }\n    ch = s[i];\n    ++num;\n  }\n  res.emplace_back(ch,\
    \ num);\n  return res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_STRING_RUN_LENGTH_ENCODING_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/run_length_encoding.test.cpp
documentation_of: include/emthrm/string/run_length_encoding.hpp
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
