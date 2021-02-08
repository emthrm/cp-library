---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tsp.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\
      \u984C"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tsp.hpp\"\n#include <vector>\r\n\r\ntemplate <typename\
    \ T>\r\nT tsp(const std::vector<std::vector<T>> &graph, T TINF) {\r\n  int n =\
    \ graph.size();\r\n  if (n == 1) return 0;\r\n  std::vector<std::vector<T>> dp(1\
    \ << n, std::vector<T>(n, TINF));\r\n  dp[1][0] = 0;\r\n  for (int i = 1; i <\
    \ (1 << n); ++i) for (int j = 0; j < n; ++j) {\r\n    if (dp[i][j] == TINF) continue;\r\
    \n    for (int k = 0; k < n; ++k) {\r\n      if (!(i >> k & 1) && dp[i][j] + graph[j][k]\
    \ < dp[i | (1 << k)][k]) {\r\n        dp[i | (1 << k)][k] = dp[i][j] + graph[j][k];\r\
    \n      }\r\n    }\r\n  }\r\n  T res = TINF;\r\n  for (int j = 1; j < n; ++j)\
    \ {\r\n    if (dp[(1 << n) - 1][j] + graph[j][0] < res) res = dp[(1 << n) - 1][j]\
    \ + graph[j][0];\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nT tsp(const\
    \ std::vector<std::vector<T>> &graph, T TINF) {\r\n  int n = graph.size();\r\n\
    \  if (n == 1) return 0;\r\n  std::vector<std::vector<T>> dp(1 << n, std::vector<T>(n,\
    \ TINF));\r\n  dp[1][0] = 0;\r\n  for (int i = 1; i < (1 << n); ++i) for (int\
    \ j = 0; j < n; ++j) {\r\n    if (dp[i][j] == TINF) continue;\r\n    for (int\
    \ k = 0; k < n; ++k) {\r\n      if (!(i >> k & 1) && dp[i][j] + graph[j][k] <\
    \ dp[i | (1 << k)][k]) {\r\n        dp[i | (1 << k)][k] = dp[i][j] + graph[j][k];\r\
    \n      }\r\n    }\r\n  }\r\n  T res = TINF;\r\n  for (int j = 1; j < n; ++j)\
    \ {\r\n    if (dp[(1 << n) - 1][j] + graph[j][0] < res) res = dp[(1 << n) - 1][j]\
    \ + graph[j][0];\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tsp.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tsp.test.cpp
documentation_of: graph/tsp.hpp
layout: document
title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C (traveling salesman\
  \ problem)"
---

重み付き有向グラフについてすべての頂点を一度ずつ通る閉路の最小コストを求める問題である．


## 時間計算量

$O(2^{\lvert V \rvert} {\lvert V \rvert}^2)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`tsp(graph, ∞)`|グラフ $\mathrm{graph}$ の巡回セールスマン問題の解|存在しない場合は $\infty$ となる．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.173-175


## ToDo

- 最短のハミルトン路
  - https://ja.wikipedia.org/wiki/%E3%83%8F%E3%83%9F%E3%83%AB%E3%83%88%E3%83%B3%E8%B7%AF
  - https://ja.wikipedia.org/wiki/%E3%83%8F%E3%83%9F%E3%83%AB%E3%83%88%E3%83%B3%E9%96%89%E8%B7%AF%E5%95%8F%E9%A1%8C
  - http://www.prefield.com/algorithm/graph/shortest_hamilton_path.html
  - https://github.com/primenumber/ProconLib/blob/master/Graph/ShortestHamiltonPath.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/hamilton_cycle_ore.cc


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_2_A/review/4082476/emthrm/C++14
