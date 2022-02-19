---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/split.hpp
    title: "\u6587\u5B57\u5217\u306E\u5206\u5272"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6587\u5B57\u5217/\u6587\u5B57\u5217\u306E\u5206\u5272"
    links:
    - https://atcoder.jp/contests/abc033/tasks/abc033_c
  bundledCode: "#line 1 \"test/string/split.test.cpp\"\n/*\r\n * @brief \u6587\u5B57\
    \u5217/\u6587\u5B57\u5217\u306E\u5206\u5272\r\n */\r\n#define IGNORE\r\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc033/tasks/abc033_c\"\r\n\r\n#include\
    \ <iostream>\r\n#include <string>\r\n#include <vector>\r\n\r\n#line 4 \"string/split.hpp\"\
    \n\r\nstd::vector<std::string> split(\r\n    const std::string& s, const std::string&\
    \ delimiter) {\r\n  std::vector<std::string> res;\r\n  int pos = 0;\r\n  while\
    \ (true) {\r\n    const int pos_to_del = s.find(delimiter, pos);\r\n    if (pos_to_del\
    \ == s.npos) break;\r\n    res.emplace_back(s.substr(pos, pos_to_del - pos));\r\
    \n    pos = pos_to_del + delimiter.length();\r\n  }\r\n  res.emplace_back(s.substr(pos));\r\
    \n  return res;\r\n}\r\n#line 12 \"test/string/split.test.cpp\"\n\r\nint main()\
    \ {\r\n  std::string s;\r\n  std::cin >> s;\r\n  int ans = 0;\r\n  for (const\
    \ std::string& terms : split(s, \"+\")) {\r\n    bool is_0 = false;\r\n    for\
    \ (int i = 0; i < terms.length(); i += 2) {\r\n      is_0 |= terms[i] == '0';\r\
    \n    }\r\n    ans += !is_0;\r\n  }\r\n  std::cout << ans << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/\u6587\u5B57\u5217\u306E\u5206\u5272\r\
    \n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/abc033/tasks/abc033_c\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n\r\n\
    #include \"../../string/split.hpp\"\r\n\r\nint main() {\r\n  std::string s;\r\n\
    \  std::cin >> s;\r\n  int ans = 0;\r\n  for (const std::string& terms : split(s,\
    \ \"+\")) {\r\n    bool is_0 = false;\r\n    for (int i = 0; i < terms.length();\
    \ i += 2) {\r\n      is_0 |= terms[i] == '0';\r\n    }\r\n    ans += !is_0;\r\n\
    \  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - string/split.hpp
  isVerificationFile: true
  path: test/string/split.test.cpp
  requiredBy: []
  timestamp: '2022-02-14 14:47:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/split.test.cpp
layout: document
redirect_from:
- /verify/test/string/split.test.cpp
- /verify/test/string/split.test.cpp.html
title: "\u6587\u5B57\u5217/\u6587\u5B57\u5217\u306E\u5206\u5272"
---
