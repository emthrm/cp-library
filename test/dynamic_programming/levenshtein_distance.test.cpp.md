---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/levenshtein_distance.hpp
    title: "\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2 (Levenshtein\
      \ distance) / \u7DE8\u96C6\u8DDD\u96E2 (edit distance)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30EC\u30FC\u30D9\u30F3\u30B7\
      \u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
  bundledCode: "#line 1 \"test/dynamic_programming/levenshtein_distance.test.cpp\"\
    \n/*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\
    \u30BF\u30A4\u30F3\u8DDD\u96E2\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#line 1 \"include/emthrm/dynamic_programming/levenshtein_distance.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T>\nint levenshtein_distance(const T& a, const\
    \ T& b) {\n  const int n = a.size(), m = b.size();\n  std::vector<std::vector<int>>\
    \ dp(n + 1, std::vector<int>(m + 1));\n  for (int i = n; i >= 1; --i) {\n    dp[i][0]\
    \ = i;\n  }\n  std::iota(dp[0].begin(), dp[0].end(), 0);\n  for (int i = 1; i\
    \ <= n; ++i) {\n    for (int j = 1; j <= m; ++j) {\n      dp[i][j] = std::min({dp[i\
    \ - 1][j] + 1,\n                           dp[i][j - 1] + 1,\n               \
    \            dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});\n    }\n  }\n  return\
    \ dp[n][m];\n}\n\n}  // namespace emthrm\n\n\n#line 11 \"test/dynamic_programming/levenshtein_distance.test.cpp\"\
    \n\nint main() {\n  std::string s1, s2;\n  std::cin >> s1 >> s2;\n  std::cout\
    \ << emthrm::levenshtein_distance(s1, s2) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/\u30EC\u30FC\u30D9\u30F3\u30B7\
    \u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#include \"emthrm/dynamic_programming/levenshtein_distance.hpp\"\
    \n\nint main() {\n  std::string s1, s2;\n  std::cin >> s1 >> s2;\n  std::cout\
    \ << emthrm::levenshtein_distance(s1, s2) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/levenshtein_distance.hpp
  isVerificationFile: true
  path: test/dynamic_programming/levenshtein_distance.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
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
