---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/longest_common_subsequence.hpp
    title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (longest common subsequence)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\
      \u5206\u5217"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
  bundledCode: "#line 1 \"test/dynamic_programming/longest_common_subsequence.test.cpp\"\
    \n/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\
    \u5206\u5217\r\n */\r\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n\r\n#line 2 \"dynamic_programming/longest_common_subsequence.hpp\"\
    \n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nT\
    \ longest_common_subsequence(const T& a, const T& b) {\r\n  int a_size = a.size(),\
    \ b_size = b.size();\r\n  std::vector<std::vector<int>> dp(a_size + 1, std::vector<int>(b_size\
    \ + 1, 0));\r\n  for (int i = 0; i < a_size; ++i) {\r\n    for (int j = 0; j <\
    \ b_size; ++j) {\r\n      dp[i + 1][j + 1] =\r\n          (a[i] == b[j] ? dp[i][j]\
    \ + 1 : std::max(dp[i][j + 1], dp[i + 1][j]));\r\n    }\r\n  }\r\n  T res;\r\n\
    \  while (a_size > 0 && b_size > 0) {\r\n    if (dp[a_size][b_size] == dp[a_size\
    \ - 1][b_size]) {\r\n      --a_size;\r\n    } else if (dp[a_size][b_size] == dp[a_size][b_size\
    \ - 1]) {\r\n      --b_size;\r\n    } else {\r\n      res.push_back(a[--a_size]);\r\
    \n      --b_size;\r\n    }\r\n  }\r\n  std::reverse(res.begin(), res.end());\r\
    \n  return res;\r\n}\r\n#line 10 \"test/dynamic_programming/longest_common_subsequence.test.cpp\"\
    \n\r\nint main() {\r\n  int q;\r\n  std::cin >> q;\r\n  while (q--) {\r\n    std::string\
    \ s, t;\r\n    std::cin >> s >> t;\r\n    std::cout << longest_common_subsequence(s,\
    \ t).length() << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\
    \u5206\u5217\r\n */\r\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n\r\n#include \"../../dynamic_programming/longest_common_subsequence.hpp\"\
    \r\n\r\nint main() {\r\n  int q;\r\n  std::cin >> q;\r\n  while (q--) {\r\n  \
    \  std::string s, t;\r\n    std::cin >> s >> t;\r\n    std::cout << longest_common_subsequence(s,\
    \ t).length() << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dynamic_programming/longest_common_subsequence.hpp
  isVerificationFile: true
  path: test/dynamic_programming/longest_common_subsequence.test.cpp
  requiredBy: []
  timestamp: '2022-02-14 14:47:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/longest_common_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/longest_common_subsequence.test.cpp
- /verify/test/dynamic_programming/longest_common_subsequence.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\u5206\u5217"
---
