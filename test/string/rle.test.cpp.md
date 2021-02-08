---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/rle.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (run length encoding)"
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
    document_title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
      \u7E2E"
    links:
    - https://atcoder.jp/contests/abc143/tasks/abc143_c
  bundledCode: "#line 1 \"test/string/rle.test.cpp\"\n/*\r\n * @brief \u6587\u5B57\
    \u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\r\n */\r\n#define IGNORE\r\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc143/tasks/abc143_c\"\r\n\r\n\
    #include <iostream>\r\n#include <string>\r\n#line 3 \"string/rle.hpp\"\n#include\
    \ <utility>\r\n#include <vector>\r\n\r\ntemplate <typename T = char, typename\
    \ U = std::string>\r\nstd::vector<std::pair<T, int>> rle(const U &s) {\r\n  int\
    \ n = s.size();\r\n  std::vector<std::pair<T, int>> res;\r\n  T now = s[0];\r\n\
    \  int cnt = 1;\r\n  for (int i = 1; i < n; ++i) {\r\n    if (s[i] != now) {\r\
    \n      res.emplace_back(now, cnt);\r\n      cnt = 0;\r\n    }\r\n    now = s[i];\r\
    \n    ++cnt;\r\n  }\r\n  res.emplace_back(now, cnt);\r\n  return res;\r\n}\r\n\
    #line 10 \"test/string/rle.test.cpp\"\n\r\nint main() {\r\n  int n;\r\n  std::cin\
    \ >> n;\r\n  std::string s;\r\n  std::cin >> s;\r\n  std::cout << rle<>(s).size()\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
    \u7E2E\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/abc143/tasks/abc143_c\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include \"../../string/rle.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::string s;\r\n \
    \ std::cin >> s;\r\n  std::cout << rle<>(s).size() << '\\n';\r\n  return 0;\r\n\
    }\r\n"
  dependsOn:
  - string/rle.hpp
  isVerificationFile: true
  path: test/string/rle.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/rle.test.cpp
layout: document
redirect_from:
- /verify/test/string/rle.test.cpp
- /verify/test/string/rle.test.cpp.html
title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
---
