---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/knuth_yao_speedup.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/knuth_yao_speedup.hpp\"\n#include <algorithm>\r\
    \n#include <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<std::vector<T>>\
    \ knuth_yao_speedup(\r\n    const std::vector<std::vector<T>>& w, const T inf)\
    \ {\r\n  const int n = w.size();\r\n  std::vector<std::vector<T>> dp(n, std::vector<T>(n,\
    \ inf));\r\n  if (n == 0) return dp;\r\n  std::vector<std::vector<int>> argmin(n,\
    \ std::vector<int>(n, -1));\r\n  for (int i = 0; i < n; ++i) {\r\n    dp[i][i]\
    \ = 0;\r\n    argmin[i][i] = i;\r\n  }\r\n  for (int width = 2; width <= n; ++width)\
    \ {\r\n    for (int i = 0; ; ++i) {\r\n      const int j = i + width - 1;\r\n\
    \      if (j >= n) break;\r\n      const int right = std::min(j - 1, argmin[i\
    \ + 1][j]);\r\n      for (int k = argmin[i][j - 1]; k <= right; ++k) {\r\n   \
    \     const T tmp = dp[i][k] + dp[k + 1][j] + w[i][j];\r\n        if (tmp < dp[i][j])\
    \ {\r\n          dp[i][j] = tmp;\r\n          argmin[i][j] = k;\r\n        }\r\
    \n      }\r\n    }\r\n  }\r\n  return dp;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nstd::vector<std::vector<T>> knuth_yao_speedup(\r\n    const\
    \ std::vector<std::vector<T>>& w, const T inf) {\r\n  const int n = w.size();\r\
    \n  std::vector<std::vector<T>> dp(n, std::vector<T>(n, inf));\r\n  if (n == 0)\
    \ return dp;\r\n  std::vector<std::vector<int>> argmin(n, std::vector<int>(n,\
    \ -1));\r\n  for (int i = 0; i < n; ++i) {\r\n    dp[i][i] = 0;\r\n    argmin[i][i]\
    \ = i;\r\n  }\r\n  for (int width = 2; width <= n; ++width) {\r\n    for (int\
    \ i = 0; ; ++i) {\r\n      const int j = i + width - 1;\r\n      if (j >= n) break;\r\
    \n      const int right = std::min(j - 1, argmin[i + 1][j]);\r\n      for (int\
    \ k = argmin[i][j - 1]; k <= right; ++k) {\r\n        const T tmp = dp[i][k] +\
    \ dp[k + 1][j] + w[i][j];\r\n        if (tmp < dp[i][j]) {\r\n          dp[i][j]\
    \ = tmp;\r\n          argmin[i][j] = k;\r\n        }\r\n      }\r\n    }\r\n \
    \ }\r\n  return dp;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/knuth_yao_speedup.hpp
  requiredBy: []
  timestamp: '2022-02-12 20:37:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/knuth_yao_speedup.test.cpp
documentation_of: dynamic_programming/knuth_yao_speedup.hpp
layout: document
title: "Knuth\u2013Yao speedup"
---

$N \times N$ 型重み行列 $W$ を考える．ただし $i > j$ を満たす $i, j \in \lbrace 1, 2, \ldots, n \rbrace$ に対して $w_{ij} = \infty$ が成り立つ．

- $W$ は Monge property を満たし，
- $W$ は単調，すなわち任意の $1 \leq i \leq k \leq l \leq j \leq N$ に対して $w_{kl} \leq w_{ij}$ を満たす

とき，

$$f(i, j) \mathrel{:=} \begin{cases} 0 & (i = j), \\ \min_{i \leq k < j} \lbrace f(i, k) + f(k + 1, j) \rbrace + w_{ij} & (i < j) \end{cases}$$

で定義される $f$ に対して $f(i, j)$ ($1 \leq i \leq j \leq N$) を $O(N^2)$ で計算できる．


### Monge property

二変数関数 $f$ を考える．$\forall i \leq j,\ k \leq l$ に対して $f(i, l) + f(j, k) \geq f(i, k) + f(j, l)$ が成り立つとき，$f$ は Monge property を満たす．


## 時間計算量

$O(N^2)$


## 使用法

||説明|
|:--:|:--:|
|`knuth_yao_speedup(w, ∞)`|重み行列 $W$ に対して上で定義した $f$|


## 参考

- https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html


## ToDo

- 最適二分探索木問題
  - https://atcoder.jp/contests/atc002/tasks/atc002_c
  - Hu–Tucker algorithm
    - https://ei1333.github.io/luzhiled/snippets/dp/hu-tucker.html
    - https://github.com/beet-aizu/library/blob/master/algorithm/optimalbinarytree.cpp
    - ~~https://lumakernel.github.io/ecasdqina/algorithm/Hu-Tucker~~
    - https://atcoder.jp/contests/kupc2012/submissions/29656
- monotone minima
  - https://dic.kimiyuki.net/monotone-minima
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html
  - https://ferin-tech.hatenablog.com/entry/2018/02/23/071343
  - https://lorent-kyopro.hatenablog.com/entry/2021/04/04/133958
  - https://ei1333.github.io/luzhiled/snippets/dp/monotone-minima.html
  - https://github.com/beet-aizu/library/blob/master/algorithm/monotoneminima.cpp
  - https://lumakernel.github.io/ecasdqina/math/Monge
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/speedup/Monotone-Minima
  - http://sigma425.hatenablog.com/entry/2015/12/01/162720
  - https://docs.google.com/presentation/d/1cgPtVG4j4Ima6Exf_Kw1IdYVfmfDJSGwaEgOMgPkWHg/
- SMAWK algorithm
  - https://en.wikipedia.org/wiki/SMAWK_algorithm
  - https://dic.kimiyuki.net/smawk-algorithm
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html
  - https://drive.google.com/drive/folders/1FMOglXlDlyg6FJiP5QTJ0iSMq7XA2mqy
  - https://noshi91.github.io/Library/algorithm/smawk.cpp
- divide and conquer
  - https://ferin-tech.hatenablog.com/entry/2018/02/23/071343
  - https://www.hamayanhamayan.com/entry/2017/03/20/234711
  - https://ei1333.github.io/algorithm/dynamic-programming.html
  - https://ei1333.github.io/luzhiled/snippets/dp/divide-and-conquer-optimization.html
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/speedup/Divide-and-Conquer-Optimization


## Verified

https://atcoder.jp/contests/kupc2012/submissions/25148833
