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
  bundledCode: "#line 1 \"test/string/subsequence_dp.test.cpp\"\n/*\n * @brief \u6587\
    \u5B57\u5217/\u90E8\u5206\u5217 DP\n */\n#define PROBLEM \"https://atcoder.jp/contests/arc081/tasks/arc081_e\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/arc081/tasks/arc081_c\"\n\n\
    #include <iostream>\n#include <string>\n#include <vector>\n\n#line 2 \"string/subsequence_dp.hpp\"\
    \n#include <algorithm>\n#line 5 \"string/subsequence_dp.hpp\"\n\nstd::vector<std::vector<int>>\
    \ subsequence_dp(\n    const std::string& s, const char basis = 'a', const int\
    \ sigma = 26) {\n  const int n = s.length();\n  std::vector<std::vector<int>>\
    \ nx(n, std::vector<int>(sigma, n));\n  nx[n - 1][s[n - 1] - basis] = n - 1;\n\
    \  for (int i = n - 2; i >= 0; --i) {\n    std::copy(nx[i + 1].begin(), nx[i +\
    \ 1].end(), nx[i].begin());\n    nx[i][s[i] - basis] = i;\n  }\n  return nx;\n\
    }\n#line 12 \"test/string/subsequence_dp.test.cpp\"\n\nint main() {\n  constexpr\
    \ int SIGMA = 26;\n  std::string a;\n  std::cin >> a;\n  const int n = a.length();\n\
    \  const std::vector<std::vector<int>> nxt = subsequence_dp(a, 'a', SIGMA);\n\
    \  std::vector<int> dp(n + 1, n + 1), next_char(n, -1);\n  dp[n] = 1;\n  for (int\
    \ i = n - 1; i >= 0; --i) {\n    for (int c = 0; c < SIGMA; ++c) {\n      const\
    \ int len = (nxt[i][c] == n ? 0 : dp[nxt[i][c] + 1]) + 1;\n      if (len < dp[i])\
    \ {\n        dp[i] = len;\n        next_char[i] = c;\n      }\n    }\n  }\n  std::string\
    \ ans = \"\";\n  for (int i = 0; i < n;) {\n    ans += 'a' + next_char[i];\n \
    \   i = nxt[i][next_char[i]] + 1;\n  }\n  std::cout << ans << '\\n';\n  return\
    \ 0;\n}\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/\u90E8\u5206\u5217 DP\n */\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc081/tasks/arc081_e\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/arc081/tasks/arc081_c\"\n\n#include <iostream>\n#include\
    \ <string>\n#include <vector>\n\n#include \"../../string/subsequence_dp.hpp\"\n\
    \nint main() {\n  constexpr int SIGMA = 26;\n  std::string a;\n  std::cin >> a;\n\
    \  const int n = a.length();\n  const std::vector<std::vector<int>> nxt = subsequence_dp(a,\
    \ 'a', SIGMA);\n  std::vector<int> dp(n + 1, n + 1), next_char(n, -1);\n  dp[n]\
    \ = 1;\n  for (int i = n - 1; i >= 0; --i) {\n    for (int c = 0; c < SIGMA; ++c)\
    \ {\n      const int len = (nxt[i][c] == n ? 0 : dp[nxt[i][c] + 1]) + 1;\n   \
    \   if (len < dp[i]) {\n        dp[i] = len;\n        next_char[i] = c;\n    \
    \  }\n    }\n  }\n  std::string ans = \"\";\n  for (int i = 0; i < n;) {\n   \
    \ ans += 'a' + next_char[i];\n    i = nxt[i][next_char[i]] + 1;\n  }\n  std::cout\
    \ << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - string/subsequence_dp.hpp
  isVerificationFile: true
  path: test/string/subsequence_dp.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/subsequence_dp.test.cpp
layout: document
redirect_from:
- /verify/test/string/subsequence_dp.test.cpp
- /verify/test/string/subsequence_dp.test.cpp.html
title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
---
