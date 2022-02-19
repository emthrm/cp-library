---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/subsequence_dp.hpp
    title: "\u90E8\u5206\u5217 DP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc081/tasks/arc081_e
    document_title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
    links:
    - https://atcoder.jp/contests/arc081/tasks/arc081_c
    - https://atcoder.jp/contests/arc081/tasks/arc081_e
  bundledCode: "#line 1 \"test/string/subsequence_dp.test.cpp\"\n/*\r\n * @brief \u6587\
    \u5B57\u5217/\u90E8\u5206\u5217 DP\r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/arc081/tasks/arc081_e\"\
    \r\n// #define PROBLEM \"https://atcoder.jp/contests/arc081/tasks/arc081_c\"\r\
    \n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n\r\n#line\
    \ 2 \"string/subsequence_dp.hpp\"\n#include <algorithm>\r\n#line 5 \"string/subsequence_dp.hpp\"\
    \n\r\nstd::vector<std::vector<int>> subsequence_dp(\r\n    const std::string&\
    \ s, const char basis = 'a', const int sigma = 26) {\r\n  const int n = s.length();\r\
    \n  std::vector<std::vector<int>> nx(n, std::vector<int>(sigma, n));\r\n  nx[n\
    \ - 1][s[n - 1] - basis] = n - 1;\r\n  for (int i = n - 2; i >= 0; --i) {\r\n\
    \    std::copy(nx[i + 1].begin(), nx[i + 1].end(), nx[i].begin());\r\n    nx[i][s[i]\
    \ - basis] = i;\r\n  }\r\n  return nx;\r\n}\r\n#line 12 \"test/string/subsequence_dp.test.cpp\"\
    \n\r\nint main() {\r\n  constexpr int SIGMA = 26;\r\n  std::string a;\r\n  std::cin\
    \ >> a;\r\n  const int n = a.length();\r\n  const std::vector<std::vector<int>>\
    \ nxt = subsequence_dp(a, 'a', SIGMA);\r\n  std::vector<int> dp(n + 1, n + 1),\
    \ next_char(n, -1);\r\n  dp[n] = 1;\r\n  for (int i = n - 1; i >= 0; --i) {\r\n\
    \    for (int c = 0; c < SIGMA; ++c) {\r\n      const int len = (nxt[i][c] ==\
    \ n ? 0 : dp[nxt[i][c] + 1]) + 1;\r\n      if (len < dp[i]) {\r\n        dp[i]\
    \ = len;\r\n        next_char[i] = c;\r\n      }\r\n    }\r\n  }\r\n  std::string\
    \ ans = \"\";\r\n  for (int i = 0; i < n;) {\r\n    ans += 'a' + next_char[i];\r\
    \n    i = nxt[i][next_char[i]] + 1;\r\n  }\r\n  std::cout << ans << '\\n';\r\n\
    \  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/\u90E8\u5206\u5217 DP\r\n */\r\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/arc081/tasks/arc081_e\"\r\n// #define\
    \ PROBLEM \"https://atcoder.jp/contests/arc081/tasks/arc081_c\"\r\n\r\n#include\
    \ <iostream>\r\n#include <string>\r\n#include <vector>\r\n\r\n#include \"../../string/subsequence_dp.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr int SIGMA = 26;\r\n  std::string a;\r\n  std::cin\
    \ >> a;\r\n  const int n = a.length();\r\n  const std::vector<std::vector<int>>\
    \ nxt = subsequence_dp(a, 'a', SIGMA);\r\n  std::vector<int> dp(n + 1, n + 1),\
    \ next_char(n, -1);\r\n  dp[n] = 1;\r\n  for (int i = n - 1; i >= 0; --i) {\r\n\
    \    for (int c = 0; c < SIGMA; ++c) {\r\n      const int len = (nxt[i][c] ==\
    \ n ? 0 : dp[nxt[i][c] + 1]) + 1;\r\n      if (len < dp[i]) {\r\n        dp[i]\
    \ = len;\r\n        next_char[i] = c;\r\n      }\r\n    }\r\n  }\r\n  std::string\
    \ ans = \"\";\r\n  for (int i = 0; i < n;) {\r\n    ans += 'a' + next_char[i];\r\
    \n    i = nxt[i][next_char[i]] + 1;\r\n  }\r\n  std::cout << ans << '\\n';\r\n\
    \  return 0;\r\n}\r\n"
  dependsOn:
  - string/subsequence_dp.hpp
  isVerificationFile: true
  path: test/string/subsequence_dp.test.cpp
  requiredBy: []
  timestamp: '2022-02-14 14:47:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/subsequence_dp.test.cpp
layout: document
redirect_from:
- /verify/test/string/subsequence_dp.test.cpp
- /verify/test/string/subsequence_dp.test.cpp.html
title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
---
