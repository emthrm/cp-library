---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/levenshtein_distance.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\
      \u30A4\u30F3\u8DDD\u96E2"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/levenshtein_distance.hpp\"\n#include\
    \ <algorithm>\n#include <numeric>\n#include <vector>\n\ntemplate <typename T>\n\
    int levenshtein_distance(const T& a, const T& b) {\n  const int n = a.size(),\
    \ m = b.size();\n  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m\
    \ + 1));\n  for (int i = n; i >= 1; --i) {\n    dp[i][0] = i;\n  }\n  std::iota(dp[0].begin(),\
    \ dp[0].end(), 0);\n  for (int i = 1; i <= n; ++i) {\n    for (int j = 1; j <=\
    \ m; ++j) {\n      dp[i][j] = std::min({dp[i - 1][j] + 1,\n                  \
    \         dp[i][j - 1] + 1,\n                           dp[i - 1][j - 1] + (a[i\
    \ - 1] != b[j - 1])});\n    }\n  }\n  return dp[n][m];\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    \ntemplate <typename T>\nint levenshtein_distance(const T& a, const T& b) {\n\
    \  const int n = a.size(), m = b.size();\n  std::vector<std::vector<int>> dp(n\
    \ + 1, std::vector<int>(m + 1));\n  for (int i = n; i >= 1; --i) {\n    dp[i][0]\
    \ = i;\n  }\n  std::iota(dp[0].begin(), dp[0].end(), 0);\n  for (int i = 1; i\
    \ <= n; ++i) {\n    for (int j = 1; j <= m; ++j) {\n      dp[i][j] = std::min({dp[i\
    \ - 1][j] + 1,\n                           dp[i][j - 1] + 1,\n               \
    \            dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});\n    }\n  }\n  return\
    \ dp[n][m];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/levenshtein_distance.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/levenshtein_distance.test.cpp
documentation_of: dynamic_programming/levenshtein_distance.hpp
layout: document
title: "\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2 (Levenshtein\
  \ distance) / \u7DE8\u96C6\u8DDD\u96E2 (edit distance)"
---

任意の文字を削除・挿入・置換することによって，二つの文字列を一致させるために必要な操作回数の最小値である．


## 時間計算量

$O(NM)$


## 使用法

||説明|
|:--:|:--:|
|`levenshtein_distance(a, b)`|$A$ と $B$ のレーベンシュタイン距離|


## 参考

- https://ja.wikipedia.org/wiki/%E3%83%AC%E3%83%BC%E3%83%99%E3%83%B3%E3%82%B7%E3%83%A5%E3%82%BF%E3%82%A4%E3%83%B3%E8%B7%9D%E9%9B%A2


## ToDo

- Method of Four Russians
  - https://en.wikipedia.org/wiki/Method_of_Four_Russians#:~:text=In%20computer%20science%2C%20the%20Method,bounded%20number%20of%20possible%20values.
  - https://qiita.com/okateim/items/a1b0523c1c862009e81f
  - https://echizen-tm.hatenadiary.org/entry/20120520/1337516536


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_E/review/4112291/emthrm/C++14
