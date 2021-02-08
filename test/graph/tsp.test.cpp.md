---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tsp.hpp
    title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C (traveling\
      \ salesman problem)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
    document_title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
      \u30F3\u554F\u984C"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
  bundledCode: "#line 1 \"test/graph/tsp.test.cpp\"\n/*\r\n * @brief \u30B0\u30E9\u30D5\
    /\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 3 \"graph/tsp.hpp\"\n\
    \r\ntemplate <typename T>\r\nT tsp(const std::vector<std::vector<T>> &graph, T\
    \ TINF) {\r\n  int n = graph.size();\r\n  if (n == 1) return 0;\r\n  std::vector<std::vector<T>>\
    \ dp(1 << n, std::vector<T>(n, TINF));\r\n  dp[1][0] = 0;\r\n  for (int i = 1;\
    \ i < (1 << n); ++i) for (int j = 0; j < n; ++j) {\r\n    if (dp[i][j] == TINF)\
    \ continue;\r\n    for (int k = 0; k < n; ++k) {\r\n      if (!(i >> k & 1) &&\
    \ dp[i][j] + graph[j][k] < dp[i | (1 << k)][k]) {\r\n        dp[i | (1 << k)][k]\
    \ = dp[i][j] + graph[j][k];\r\n      }\r\n    }\r\n  }\r\n  T res = TINF;\r\n\
    \  for (int j = 1; j < n; ++j) {\r\n    if (dp[(1 << n) - 1][j] + graph[j][0]\
    \ < res) res = dp[(1 << n) - 1][j] + graph[j][0];\r\n  }\r\n  return res;\r\n\
    }\r\n#line 9 \"test/graph/tsp.test.cpp\"\n\r\nint main() {\r\n  constexpr long\
    \ long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n  int v, e;\r\n  std::cin >> v >> e;\r\n\
    \  std::vector<std::vector<long long>> g(v, std::vector<long long>(v, LINF));\r\
    \n  while (e--) {\r\n    int s, t, d;\r\n    std::cin >> s >> t >> d;\r\n    g[s][t]\
    \ = d;\r\n  }\r\n  long long ans = tsp(g, LINF);\r\n  std::cout << (ans == LINF\
    \ ? -1 : ans) << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
    \u30F3\u554F\u984C\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../graph/tsp.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n\
    \  int v, e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<long long>>\
    \ g(v, std::vector<long long>(v, LINF));\r\n  while (e--) {\r\n    int s, t, d;\r\
    \n    std::cin >> s >> t >> d;\r\n    g[s][t] = d;\r\n  }\r\n  long long ans =\
    \ tsp(g, LINF);\r\n  std::cout << (ans == LINF ? -1 : ans) << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - graph/tsp.hpp
  isVerificationFile: true
  path: test/graph/tsp.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tsp.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tsp.test.cpp
- /verify/test/graph/tsp.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C"
---
