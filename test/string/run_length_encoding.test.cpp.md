---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/run_length_encoding.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (run length encoding)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc143/tasks/abc143_c
    document_title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
      \u7E2E"
    links:
    - https://atcoder.jp/contests/abc143/tasks/abc143_c
  bundledCode: "#line 1 \"test/string/run_length_encoding.test.cpp\"\n/*\n * @brief\
    \ \u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\n */\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc143/tasks/abc143_c\"\n\n#include <iostream>\n\
    #include <string>\n\n#line 2 \"string/run_length_encoding.hpp\"\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T = char, typename U>\nstd::vector<std::pair<T,\
    \ int>> run_length_encoding(const U& s) {\n  const int n = s.size();\n  std::vector<std::pair<T,\
    \ int>> res;\n  if (n == 0) return res;\n  T ch = s.front();\n  int num = 1;\n\
    \  for (int i = 1; i < n; ++i) {\n    if (s[i] != ch) {\n      res.emplace_back(ch,\
    \ num);\n      num = 0;\n    }\n    ch = s[i];\n    ++num;\n  }\n  res.emplace_back(ch,\
    \ num);\n  return res;\n}\n#line 10 \"test/string/run_length_encoding.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::string s;\n  std::cin >>\
    \ s;\n  std::cout << run_length_encoding(s).size() << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
    \u7E2E\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc143/tasks/abc143_c\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../../string/run_length_encoding.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::string s;\n  std::cin >>\
    \ s;\n  std::cout << run_length_encoding(s).size() << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - string/run_length_encoding.hpp
  isVerificationFile: true
  path: test/string/run_length_encoding.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/run_length_encoding.test.cpp
layout: document
redirect_from:
- /verify/test/string/run_length_encoding.test.cpp
- /verify/test/string/run_length_encoding.test.cpp.html
title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
---
