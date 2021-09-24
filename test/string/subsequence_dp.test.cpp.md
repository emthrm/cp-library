---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/subsequence_dp.hpp
    title: "\u90E8\u5206\u5217 DP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc081/tasks/arc081_c
    document_title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
    links:
    - https://atcoder.jp/contests/arc081/tasks/arc081_c
  bundledCode: "#line 1 \"test/string/subsequence_dp.test.cpp\"\n/*\r\n * @brief \u6587\
    \u5B57\u5217/\u90E8\u5206\u5217 DP\r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/arc081/tasks/arc081_c\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n#line\
    \ 2 \"string/subsequence_dp.hpp\"\n#include <algorithm>\r\n#line 5 \"string/subsequence_dp.hpp\"\
    \n\r\nstd::vector<std::vector<int>> subsequence_dp(const std::string &s, const\
    \ char basis = 'a', const int sigma = 26) {\r\n  const int n = s.size();\r\n \
    \ std::vector<std::vector<int>> nx(n, std::vector<int>(sigma, n));\r\n  nx[n -\
    \ 1][s[n - 1] - basis] = n - 1;\r\n  for (int i = n - 2; i >= 0; --i) {\r\n  \
    \  std::copy(nx[i + 1].begin(), nx[i + 1].end(), nx[i].begin());\r\n    nx[i][s[i]\
    \ - basis] = i;\r\n  }\r\n  return nx;\r\n}\r\n#line 10 \"test/string/subsequence_dp.test.cpp\"\
    \n\r\nint main() {\r\n  constexpr int C = 26;\r\n  std::string a;\r\n  std::cin\
    \ >> a;\r\n  const int n = a.length();\r\n  std::vector<std::vector<int>> nx =\
    \ subsequence_dp(a, 'a', C);\r\n  std::vector<int> dp(n + 1, n + 1);\r\n  dp[n]\
    \ = 1;\r\n  std::vector<int> next_char(n, -1);\r\n  for (int i = n - 1; i >= 0;\
    \ --i) {\r\n    for (int c = 0; c < C; ++c) {\r\n      const int len = (nx[i][c]\
    \ == n ? 0 : dp[nx[i][c] + 1]) + 1;\r\n      if (len < dp[i]) {\r\n        dp[i]\
    \ = len;\r\n        next_char[i] = c;\r\n      }\r\n    }\r\n  }\r\n  std::string\
    \ ans = \"\";\r\n  for (int i = 0; i < n;) {\r\n    ans += 'a' + next_char[i];\r\
    \n    i = nx[i][next_char[i]] + 1;\r\n  }\r\n  std::cout << ans << '\\n';\r\n\
    \  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/\u90E8\u5206\u5217 DP\r\n */\r\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/arc081/tasks/arc081_c\"\r\n\r\n#include\
    \ <iostream>\r\n#include <string>\r\n#include <vector>\r\n#include \"../../string/subsequence_dp.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr int C = 26;\r\n  std::string a;\r\n  std::cin\
    \ >> a;\r\n  const int n = a.length();\r\n  std::vector<std::vector<int>> nx =\
    \ subsequence_dp(a, 'a', C);\r\n  std::vector<int> dp(n + 1, n + 1);\r\n  dp[n]\
    \ = 1;\r\n  std::vector<int> next_char(n, -1);\r\n  for (int i = n - 1; i >= 0;\
    \ --i) {\r\n    for (int c = 0; c < C; ++c) {\r\n      const int len = (nx[i][c]\
    \ == n ? 0 : dp[nx[i][c] + 1]) + 1;\r\n      if (len < dp[i]) {\r\n        dp[i]\
    \ = len;\r\n        next_char[i] = c;\r\n      }\r\n    }\r\n  }\r\n  std::string\
    \ ans = \"\";\r\n  for (int i = 0; i < n;) {\r\n    ans += 'a' + next_char[i];\r\
    \n    i = nx[i][next_char[i]] + 1;\r\n  }\r\n  std::cout << ans << '\\n';\r\n\
    \  return 0;\r\n}\r\n"
  dependsOn:
  - string/subsequence_dp.hpp
  isVerificationFile: true
  path: test/string/subsequence_dp.test.cpp
  requiredBy: []
  timestamp: '2021-09-23 22:47:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/subsequence_dp.test.cpp
layout: document
redirect_from:
- /verify/test/string/subsequence_dp.test.cpp
- /verify/test/string/subsequence_dp.test.cpp.html
title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
---
