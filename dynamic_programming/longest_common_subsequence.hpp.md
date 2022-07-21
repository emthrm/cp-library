---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/longest_common_subsequence.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\u5206\u5217"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/longest_common_subsequence.hpp\"\n#include\
    \ <algorithm>\n#include <vector>\n\ntemplate <typename T>\nT longest_common_subsequence(const\
    \ T& a, const T& b) {\n  int a_size = a.size(), b_size = b.size();\n  std::vector<std::vector<int>>\
    \ dp(a_size + 1, std::vector<int>(b_size + 1, 0));\n  for (int i = 0; i < a_size;\
    \ ++i) {\n    for (int j = 0; j < b_size; ++j) {\n      dp[i + 1][j + 1] =\n \
    \         (a[i] == b[j] ? dp[i][j] + 1 : std::max(dp[i][j + 1], dp[i + 1][j]));\n\
    \    }\n  }\n  T res;\n  while (a_size > 0 && b_size > 0) {\n    if (dp[a_size][b_size]\
    \ == dp[a_size - 1][b_size]) {\n      --a_size;\n    } else if (dp[a_size][b_size]\
    \ == dp[a_size][b_size - 1]) {\n      --b_size;\n    } else {\n      res.push_back(a[--a_size]);\n\
    \      --b_size;\n    }\n  }\n  std::reverse(res.begin(), res.end());\n  return\
    \ res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ T>\nT longest_common_subsequence(const T& a, const T& b) {\n  int a_size = a.size(),\
    \ b_size = b.size();\n  std::vector<std::vector<int>> dp(a_size + 1, std::vector<int>(b_size\
    \ + 1, 0));\n  for (int i = 0; i < a_size; ++i) {\n    for (int j = 0; j < b_size;\
    \ ++j) {\n      dp[i + 1][j + 1] =\n          (a[i] == b[j] ? dp[i][j] + 1 : std::max(dp[i][j\
    \ + 1], dp[i + 1][j]));\n    }\n  }\n  T res;\n  while (a_size > 0 && b_size >\
    \ 0) {\n    if (dp[a_size][b_size] == dp[a_size - 1][b_size]) {\n      --a_size;\n\
    \    } else if (dp[a_size][b_size] == dp[a_size][b_size - 1]) {\n      --b_size;\n\
    \    } else {\n      res.push_back(a[--a_size]);\n      --b_size;\n    }\n  }\n\
    \  std::reverse(res.begin(), res.end());\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/longest_common_subsequence.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/longest_common_subsequence.test.cpp
documentation_of: dynamic_programming/longest_common_subsequence.hpp
layout: document
title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (longest common subsequence)"
---

2列に対して双方に現れる部分列の内，最長のものである．


## 時間計算量

$O(NM)$


## 使用法

||説明|
|:--:|:--:|
|`longest_common_subsequence(a, b)`|$A$ と $B$ の最長共通部分列|


## 参考

- https://qiita.com/drken/items/03c7db44ccd27820ea0d


## ToDo

- https://judge.yosupo.jp/problem/prefix_substring_lcs
- https://github.com/yosupo06/library-checker-problems/issues/732
- 高速化
  - http://www.prefield.com/algorithm/dp/lcs_hs.html


## Verified

https://atcoder.jp/contests/dp/submissions/9236673
