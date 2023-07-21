---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/string/subsequence_dp.hpp
    title: "\u90E8\u5206\u5217 DP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/arc081/tasks/arc081_c
    document_title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
    links:
    - https://atcoder.jp/contests/arc081/tasks/arc081_c
  bundledCode: "#line 1 \"test/string/subsequence_dp.test.cpp\"\n/*\n * @title \u6587\
    \u5B57\u5217/\u90E8\u5206\u5217 DP\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/arc081/tasks/arc081_c\n */\n\n#include <iostream>\n\
    #include <string>\n#include <vector>\n\n#line 1 \"include/emthrm/string/subsequence_dp.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 7 \"include/emthrm/string/subsequence_dp.hpp\"\
    \n\nnamespace emthrm {\n\nstd::vector<std::vector<int>> subsequence_dp(\n    const\
    \ std::string& s, const char basis = 'a', const int sigma = 26) {\n  const int\
    \ n = s.length();\n  std::vector<std::vector<int>> nx(n, std::vector<int>(sigma,\
    \ n));\n  nx[n - 1][s[n - 1] - basis] = n - 1;\n  for (int i = n - 2; i >= 0;\
    \ --i) {\n    std::copy(nx[i + 1].begin(), nx[i + 1].end(), nx[i].begin());\n\
    \    nx[i][s[i] - basis] = i;\n  }\n  return nx;\n}\n\n}  // namespace emthrm\n\
    \n\n#line 13 \"test/string/subsequence_dp.test.cpp\"\n\nint main() {\n  constexpr\
    \ int SIGMA = 26;\n  std::string a;\n  std::cin >> a;\n  const int n = a.length();\n\
    \  const std::vector<std::vector<int>> nxt =\n      emthrm::subsequence_dp(a,\
    \ 'a', SIGMA);\n  std::vector<int> dp(n + 1, n + 1), next_char(n, -1);\n  dp[n]\
    \ = 1;\n  for (int i = n - 1; i >= 0; --i) {\n    for (int c = 0; c < SIGMA; ++c)\
    \ {\n      const int len = (nxt[i][c] == n ? 0 : dp[nxt[i][c] + 1]) + 1;\n   \
    \   if (len < dp[i]) {\n        dp[i] = len;\n        next_char[i] = c;\n    \
    \  }\n    }\n  }\n  std::string ans = \"\";\n  for (int i = 0; i < n;) {\n   \
    \ ans += 'a' + next_char[i];\n    i = nxt[i][next_char[i]] + 1;\n  }\n  std::cout\
    \ << ans << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6587\u5B57\u5217/\u90E8\u5206\u5217 DP\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/arc081/tasks/arc081_c\n\
    \ */\n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include\
    \ \"emthrm/string/subsequence_dp.hpp\"\n\nint main() {\n  constexpr int SIGMA\
    \ = 26;\n  std::string a;\n  std::cin >> a;\n  const int n = a.length();\n  const\
    \ std::vector<std::vector<int>> nxt =\n      emthrm::subsequence_dp(a, 'a', SIGMA);\n\
    \  std::vector<int> dp(n + 1, n + 1), next_char(n, -1);\n  dp[n] = 1;\n  for (int\
    \ i = n - 1; i >= 0; --i) {\n    for (int c = 0; c < SIGMA; ++c) {\n      const\
    \ int len = (nxt[i][c] == n ? 0 : dp[nxt[i][c] + 1]) + 1;\n      if (len < dp[i])\
    \ {\n        dp[i] = len;\n        next_char[i] = c;\n      }\n    }\n  }\n  std::string\
    \ ans = \"\";\n  for (int i = 0; i < n;) {\n    ans += 'a' + next_char[i];\n \
    \   i = nxt[i][next_char[i]] + 1;\n  }\n  std::cout << ans << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/string/subsequence_dp.hpp
  isVerificationFile: true
  path: test/string/subsequence_dp.test.cpp
  requiredBy: []
  timestamp: '2023-07-21 12:14:05+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/string/subsequence_dp.test.cpp
layout: document
redirect_from:
- /verify/test/string/subsequence_dp.test.cpp
- /verify/test/string/subsequence_dp.test.cpp.html
title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
---
