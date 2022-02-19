---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/run_length_encoding.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (run length encoding)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc143/tasks/abc143_c
    document_title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
      \u7E2E"
    links:
    - https://atcoder.jp/contests/abc143/tasks/abc143_c
  bundledCode: "#line 1 \"test/string/run_length_encoding.test.cpp\"\n/*\r\n * @brief\
    \ \u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\r\n */\r\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc143/tasks/abc143_c\"\r\n\r\n\
    #include <iostream>\r\n#include <string>\r\n\r\n#line 2 \"string/run_length_encoding.hpp\"\
    \n#include <utility>\r\n#include <vector>\r\n\r\ntemplate <typename T = char,\
    \ typename U>\r\nstd::vector<std::pair<T, int>> run_length_encoding(const U& s)\
    \ {\r\n  const int n = s.size();\r\n  std::vector<std::pair<T, int>> res;\r\n\
    \  if (n == 0) return res;\r\n  T ch = s.front();\r\n  int num = 1;\r\n  for (int\
    \ i = 1; i < n; ++i) {\r\n    if (s[i] != ch) {\r\n      res.emplace_back(ch,\
    \ num);\r\n      num = 0;\r\n    }\r\n    ch = s[i];\r\n    ++num;\r\n  }\r\n\
    \  res.emplace_back(ch, num);\r\n  return res;\r\n}\r\n#line 10 \"test/string/run_length_encoding.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::string s;\r\n  std::cin\
    \ >> s;\r\n  std::cout << run_length_encoding(s).size() << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
    \u7E2E\r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/abc143/tasks/abc143_c\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n\r\n#include \"../../string/run_length_encoding.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::string s;\r\n \
    \ std::cin >> s;\r\n  std::cout << run_length_encoding(s).size() << '\\n';\r\n\
    \  return 0;\r\n}\r\n"
  dependsOn:
  - string/run_length_encoding.hpp
  isVerificationFile: true
  path: test/string/run_length_encoding.test.cpp
  requiredBy: []
  timestamp: '2022-02-14 14:47:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/run_length_encoding.test.cpp
layout: document
redirect_from:
- /verify/test/string/run_length_encoding.test.cpp
- /verify/test/string/run_length_encoding.test.cpp.html
title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
---
