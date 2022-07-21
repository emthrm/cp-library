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
  bundledCode: "#line 1 \"test/string/split.test.cpp\"\n/*\n * @brief \u6587\u5B57\
    \u5217/\u6587\u5B57\u5217\u306E\u5206\u5272\n */\n#define IGNORE\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc033/tasks/abc033_c\"\n\n#include <iostream>\n\
    #include <string>\n#include <vector>\n\n#line 4 \"string/split.hpp\"\n\nstd::vector<std::string>\
    \ split(\n    const std::string& s, const std::string& delimiter) {\n  std::vector<std::string>\
    \ res;\n  int pos = 0;\n  while (true) {\n    const int pos_to_del = s.find(delimiter,\
    \ pos);\n    if (pos_to_del == s.npos) break;\n    res.emplace_back(s.substr(pos,\
    \ pos_to_del - pos));\n    pos = pos_to_del + delimiter.length();\n  }\n  res.emplace_back(s.substr(pos));\n\
    \  return res;\n}\n#line 12 \"test/string/split.test.cpp\"\n\nint main() {\n \
    \ std::string s;\n  std::cin >> s;\n  int ans = 0;\n  for (const std::string&\
    \ terms : split(s, \"+\")) {\n    bool is_0 = false;\n    for (int i = 0; i <\
    \ terms.length(); i += 2) {\n      is_0 |= terms[i] == '0';\n    }\n    ans +=\
    \ !is_0;\n  }\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/\u6587\u5B57\u5217\u306E\u5206\u5272\n */\n\
    #define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/abc033/tasks/abc033_c\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"../../string/split.hpp\"\
    \n\nint main() {\n  std::string s;\n  std::cin >> s;\n  int ans = 0;\n  for (const\
    \ std::string& terms : split(s, \"+\")) {\n    bool is_0 = false;\n    for (int\
    \ i = 0; i < terms.length(); i += 2) {\n      is_0 |= terms[i] == '0';\n    }\n\
    \    ans += !is_0;\n  }\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - string/split.hpp
  isVerificationFile: true
  path: test/string/split.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/split.test.cpp
layout: document
redirect_from:
- /verify/test/string/split.test.cpp
- /verify/test/string/split.test.cpp.html
title: "\u6587\u5B57\u5217/\u6587\u5B57\u5217\u306E\u5206\u5272"
---
