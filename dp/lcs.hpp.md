---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/dp/lcs.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\u5206\u5217"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/lcs.hpp\"\n#include <algorithm>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nT lcs(const T &a, const T &b) {\r\n  int a_sz =\
    \ a.size(), b_sz = b.size();\r\n  std::vector<std::vector<int>> dp(a_sz + 1, std::vector<int>(b_sz\
    \ + 1, 0));\r\n  for (int i = 0; i < a_sz; ++i) for (int j = 0; j < b_sz; ++j)\
    \ {\r\n    dp[i + 1][j + 1] = a[i] == b[j] ? dp[i][j] + 1 : std::max(dp[i][j +\
    \ 1], dp[i + 1][j]);\r\n  }\r\n  T res;\r\n  while (a_sz > 0 && b_sz > 0) {\r\n\
    \    if (dp[a_sz][b_sz] == dp[a_sz - 1][b_sz]) {\r\n      --a_sz;\r\n    } else\
    \ if (dp[a_sz][b_sz] == dp[a_sz][b_sz - 1]) {\r\n      --b_sz;\r\n    } else {\r\
    \n      res.push_back(a[a_sz - 1]);\r\n      --a_sz; --b_sz;\r\n    }\r\n  }\r\
    \n  std::reverse(res.begin(), res.end());\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nT lcs(const T &a, const T &b) {\r\n  int a_sz = a.size(), b_sz\
    \ = b.size();\r\n  std::vector<std::vector<int>> dp(a_sz + 1, std::vector<int>(b_sz\
    \ + 1, 0));\r\n  for (int i = 0; i < a_sz; ++i) for (int j = 0; j < b_sz; ++j)\
    \ {\r\n    dp[i + 1][j + 1] = a[i] == b[j] ? dp[i][j] + 1 : std::max(dp[i][j +\
    \ 1], dp[i + 1][j]);\r\n  }\r\n  T res;\r\n  while (a_sz > 0 && b_sz > 0) {\r\n\
    \    if (dp[a_sz][b_sz] == dp[a_sz - 1][b_sz]) {\r\n      --a_sz;\r\n    } else\
    \ if (dp[a_sz][b_sz] == dp[a_sz][b_sz - 1]) {\r\n      --b_sz;\r\n    } else {\r\
    \n      res.push_back(a[a_sz - 1]);\r\n      --a_sz; --b_sz;\r\n    }\r\n  }\r\
    \n  std::reverse(res.begin(), res.end());\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/lcs.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/dp/lcs.test.cpp
documentation_of: dp/lcs.hpp
layout: document
title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (longest common subsequence)"
---

ある2列において双方に現れる部分列の内, 最長のものである．


## 時間計算量

$O(NM)$


## 使用法

||説明|
|:--:|:--:|
|`lcs(a, b)`|$A$ と $B$ の最長共通部分列|


## 参考

- https://qiita.com/drken/items/03c7db44ccd27820ea0d


## ToDo

- 高速化
  - http://www.prefield.com/algorithm/dp/lcs_hs.html


## Verified

https://atcoder.jp/contests/dp/submissions/9236673
