---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/replace.hpp\"\n#include <string>\r\n\r\nstd::string\
    \ replace(const std::string &s, const std::string &before, const std::string &after)\
    \ {\r\n  std::string res = \"\";\r\n  int pos = 0;\r\n  while (true) {\r\n   \
    \ int b_pos = s.find(before, pos);\r\n    if (b_pos == s.npos) break;\r\n    res\
    \ += s.substr(pos, b_pos - pos) + after;\r\n    pos = b_pos + before.length();\r\
    \n  }\r\n  return res + s.substr(pos);\r\n}\r\n"
  code: "#pragma once\r\n#include <string>\r\n\r\nstd::string replace(const std::string\
    \ &s, const std::string &before, const std::string &after) {\r\n  std::string\
    \ res = \"\";\r\n  int pos = 0;\r\n  while (true) {\r\n    int b_pos = s.find(before,\
    \ pos);\r\n    if (b_pos == s.npos) break;\r\n    res += s.substr(pos, b_pos -\
    \ pos) + after;\r\n    pos = b_pos + before.length();\r\n  }\r\n  return res +\
    \ s.substr(pos);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/replace.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/replace.hpp
layout: document
title: "\u6587\u5B57\u5217\u306E\u7F6E\u63DB"
---


## 使用法

||説明|
|:--:|:--:|
|`split(s, before, after)`|$\mathrm{before}$ を $\mathrm{after}$ に置換した文字列 $S$|
