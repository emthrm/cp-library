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
    \n/*\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\u5206\
    \u5217\n */\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 2 \"dynamic_programming/longest_common_subsequence.hpp\"\
    \n#include <algorithm>\n#include <vector>\n\ntemplate <typename T>\nT longest_common_subsequence(const\
    \ T& a, const T& b) {\n  int a_size = a.size(), b_size = b.size();\n  std::vector<std::vector<int>>\
    \ dp(a_size + 1, std::vector<int>(b_size + 1, 0));\n  for (int i = 0; i < a_size;\
    \ ++i) {\n    for (int j = 0; j < b_size; ++j) {\n      dp[i + 1][j + 1] =\n \
    \         (a[i] == b[j] ? dp[i][j] + 1 : std::max(dp[i][j + 1], dp[i + 1][j]));\n\
    \    }\n  }\n  T res;\n  while (a_size > 0 && b_size > 0) {\n    if (dp[a_size][b_size]\
    \ == dp[a_size - 1][b_size]) {\n      --a_size;\n    } else if (dp[a_size][b_size]\
    \ == dp[a_size][b_size - 1]) {\n      --b_size;\n    } else {\n      res.push_back(a[--a_size]);\n\
    \      --b_size;\n    }\n  }\n  std::reverse(res.begin(), res.end());\n  return\
    \ res;\n}\n#line 10 \"test/dynamic_programming/longest_common_subsequence.test.cpp\"\
    \n\nint main() {\n  int q;\n  std::cin >> q;\n  while (q--) {\n    std::string\
    \ s, t;\n    std::cin >> s >> t;\n    std::cout << longest_common_subsequence(s,\
    \ t).length() << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\
    \u5206\u5217\n */\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../../dynamic_programming/longest_common_subsequence.hpp\"\
    \n\nint main() {\n  int q;\n  std::cin >> q;\n  while (q--) {\n    std::string\
    \ s, t;\n    std::cin >> s >> t;\n    std::cout << longest_common_subsequence(s,\
    \ t).length() << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - dynamic_programming/longest_common_subsequence.hpp
  isVerificationFile: true
  path: test/dynamic_programming/longest_common_subsequence.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/longest_common_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/longest_common_subsequence.test.cpp
- /verify/test/dynamic_programming/longest_common_subsequence.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\u5206\u5217"
---
