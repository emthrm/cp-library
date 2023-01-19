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
  bundledCode: "#line 1 \"include/emthrm/string/replace.hpp\"\n\n\n\n#include <cstddef>\n\
    #include <string>\n\nnamespace emthrm {\n\nstd::string replace(const std::string&\
    \ s, const std::string& before,\n                    const std::string& after)\
    \ {\n  std::string res = \"\";\n  int pos = 0;\n  while (true) {\n    const std::size_t\
    \ pos_b = s.find(before, pos);\n    if (pos_b == s.npos) break;\n    res += s.substr(pos,\
    \ pos_b - pos) + after;\n    pos = pos_b + before.length();\n  }\n  return res\
    \ + s.substr(pos);\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_STRING_REPLACE_HPP_\n#define EMTHRM_STRING_REPLACE_HPP_\n\n\
    #include <cstddef>\n#include <string>\n\nnamespace emthrm {\n\nstd::string replace(const\
    \ std::string& s, const std::string& before,\n                    const std::string&\
    \ after) {\n  std::string res = \"\";\n  int pos = 0;\n  while (true) {\n    const\
    \ std::size_t pos_b = s.find(before, pos);\n    if (pos_b == s.npos) break;\n\
    \    res += s.substr(pos, pos_b - pos) + after;\n    pos = pos_b + before.length();\n\
    \  }\n  return res + s.substr(pos);\n}\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_STRING_REPLACE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/replace.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/string/replace.hpp
layout: document
title: "\u6587\u5B57\u5217\u306E\u7F6E\u63DB"
---


## 仕様

|名前|戻り値|
|:--|:--|
|`std::string replace(const std::string& s, const std::string& before, const std::string& after);`|$\mathrm{before}$ を $\mathrm{after}$ に置換した文字列 $S$|
