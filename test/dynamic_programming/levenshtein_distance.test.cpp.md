---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/levenshtein_distance.hpp
    title: "\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2 (Levenshtein\
      \ distance) / \u7DE8\u96C6\u8DDD\u96E2 (edit distance)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30EC\u30FC\u30D9\u30F3\u30B7\
      \u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
  bundledCode: "#line 1 \"test/dynamic_programming/levenshtein_distance.test.cpp\"\
    \n/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u30EC\u30FC\u30D9\u30F3\u30B7\
    \u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n\r\n#line 2 \"dynamic_programming/levenshtein_distance.hpp\"\
    \n#include <algorithm>\r\n#include <numeric>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nint levenshtein_distance(const T& a, const T& b) {\r\n  const\
    \ int n = a.size(), m = b.size();\r\n  std::vector<std::vector<int>> dp(n + 1,\
    \ std::vector<int>(m + 1));\r\n  for (int i = n; i >= 1; --i) {\r\n    dp[i][0]\
    \ = i;\r\n  }\r\n  std::iota(dp[0].begin(), dp[0].end(), 0);\r\n  for (int i =\
    \ 1; i <= n; ++i) {\r\n    for (int j = 1; j <= m; ++j) {\r\n      dp[i][j] =\
    \ std::min({dp[i - 1][j] + 1,\r\n                           dp[i][j - 1] + 1,\r\
    \n                           dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});\r\n\
    \    }\r\n  }\r\n  return dp[n][m];\r\n}\r\n#line 10 \"test/dynamic_programming/levenshtein_distance.test.cpp\"\
    \n\r\nint main() {\r\n  std::string s1, s2;\r\n  std::cin >> s1 >> s2;\r\n  std::cout\
    \ << levenshtein_distance(s1, s2) << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u30EC\u30FC\u30D9\u30F3\u30B7\
    \u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n\r\n#include \"../../dynamic_programming/levenshtein_distance.hpp\"\
    \r\n\r\nint main() {\r\n  std::string s1, s2;\r\n  std::cin >> s1 >> s2;\r\n \
    \ std::cout << levenshtein_distance(s1, s2) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dynamic_programming/levenshtein_distance.hpp
  isVerificationFile: true
  path: test/dynamic_programming/levenshtein_distance.test.cpp
  requiredBy: []
  timestamp: '2022-02-14 14:47:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/levenshtein_distance.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/levenshtein_distance.test.cpp
- /verify/test/dynamic_programming/levenshtein_distance.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\
  \u30F3\u8DDD\u96E2"
---
