---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/split.test.cpp
    title: "\u6587\u5B57\u5217/\u6587\u5B57\u5217\u306E\u5206\u5272"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/string/split.hpp\"\n\n\n\n#include <cstddef>\n\
    #include <string>\n#include <vector>\n\nnamespace emthrm {\n\nstd::vector<std::string>\
    \ split(\n    const std::string& s, const std::string& delimiter) {\n  std::vector<std::string>\
    \ res;\n  int pos = 0;\n  while (true) {\n    const std::size_t pos_to_del = s.find(delimiter,\
    \ pos);\n    if (pos_to_del == s.npos) break;\n    res.emplace_back(s.substr(pos,\
    \ pos_to_del - pos));\n    pos = pos_to_del + delimiter.length();\n  }\n  res.emplace_back(s.substr(pos));\n\
    \  return res;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_STRING_SPLIT_HPP_\n#define EMTHRM_STRING_SPLIT_HPP_\n\n#include\
    \ <cstddef>\n#include <string>\n#include <vector>\n\nnamespace emthrm {\n\nstd::vector<std::string>\
    \ split(\n    const std::string& s, const std::string& delimiter) {\n  std::vector<std::string>\
    \ res;\n  int pos = 0;\n  while (true) {\n    const std::size_t pos_to_del = s.find(delimiter,\
    \ pos);\n    if (pos_to_del == s.npos) break;\n    res.emplace_back(s.substr(pos,\
    \ pos_to_del - pos));\n    pos = pos_to_del + delimiter.length();\n  }\n  res.emplace_back(s.substr(pos));\n\
    \  return res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_STRING_SPLIT_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/split.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/split.test.cpp
documentation_of: include/emthrm/string/split.hpp
layout: document
title: "\u6587\u5B57\u5217\u306E\u5206\u5272"
---


## 使用法

||説明|
|:--:|:--:|
|`split(s, delimiter)`|$\mathrm{delimiter}$ で分割した文字列 $S$|


## Verified

https://atcoder.jp/contests/abc033/submissions/9292173
