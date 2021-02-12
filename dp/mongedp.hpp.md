---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dp/mongedp.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/MongeDP"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/mongedp.hpp\"\n#include <algorithm>\r\n#include <vector>\r\
    \n\r\ntemplate <typename Fn, typename T>\r\nT mongedp(int n, Fn cost, const T\
    \ inf) {\r\n  if (n == 0) return 0;\r\n  std::vector<std::vector<T>> dp(n, std::vector<T>(n,\
    \ inf));\r\n  std::vector<std::vector<int>> argmin(n, std::vector<int>(n, -1));\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    dp[i][i] = 0;\r\n    argmin[i][i] = i;\r\
    \n  }\r\n  for (int width = 1; width < n; ++width) {\r\n    for (int i = 0; i\
    \ + width < n; ++i) {\r\n      int j = i + width, right = std::min(j - 1, argmin[i\
    \ + 1][j]);\r\n      for (int k = argmin[i][j - 1]; k <= right; ++k) {\r\n   \
    \     T tmp = dp[i][k] + dp[k + 1][j] + cost(i, k, j);\r\n        if (dp[i][j]\
    \ > tmp) {\r\n          dp[i][j] = tmp;\r\n          argmin[i][j] = k;\r\n   \
    \     }\r\n      }\r\n    }\r\n  }\r\n  return dp[0][n - 1];\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename Fn, typename T>\r\nT mongedp(int n, Fn cost, const T inf) {\r\n  if\
    \ (n == 0) return 0;\r\n  std::vector<std::vector<T>> dp(n, std::vector<T>(n,\
    \ inf));\r\n  std::vector<std::vector<int>> argmin(n, std::vector<int>(n, -1));\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    dp[i][i] = 0;\r\n    argmin[i][i] = i;\r\
    \n  }\r\n  for (int width = 1; width < n; ++width) {\r\n    for (int i = 0; i\
    \ + width < n; ++i) {\r\n      int j = i + width, right = std::min(j - 1, argmin[i\
    \ + 1][j]);\r\n      for (int k = argmin[i][j - 1]; k <= right; ++k) {\r\n   \
    \     T tmp = dp[i][k] + dp[k + 1][j] + cost(i, k, j);\r\n        if (dp[i][j]\
    \ > tmp) {\r\n          dp[i][j] = tmp;\r\n          argmin[i][j] = k;\r\n   \
    \     }\r\n      }\r\n    }\r\n  }\r\n  return dp[0][n - 1];\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/mongedp.hpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dp/mongedp.test.cpp
documentation_of: dp/mongedp.hpp
layout: document
title: MongeDP (Knuth-Yao speedup)
---

Monge 性を満たす動的計画法である．


### Monge 性

重み関数 $f$ について

- QI (quandrangle inequality)

  $A \cap B \neq \phi$ を満たす任意の区間 $A, B$ について

  $$f(A \cup B) + f(A \cap B) \geq f(A) + f(B) \text{，}$$

- MLI (monotone on the lattice intervals)

  $A \subset B$ を満たす任意の区間 $A, B$ について

  $$f(a) \leq f(b)$$

  すなわち任意の $i \leq j,\ k \leq l$ について

  $$f(i, l) + f(j, k) \geq f(i, k) + f(j, l)$$

が成り立つとき, Monge 性を満たすと言う．


## 時間計算量

$O(N^2)$


## 使用法

||説明|
|:--:|:--:|
|`mongedp(n, cost, ∞)`|コストが $\mathrm{cost}(i, k, j)$ で計算できる $N$ 個の要素に MongeDP を行った解|


## 参考

- https://topcoder.g.hatena.ne.jp/spaghetti_source/comment?date=20120915


## ToDo

- 最適二分探索木
  - Hu-Tucker
    - https://atcoder.jp/contests/atc002/tasks/atc002_c
    - https://ei1333.github.io/luzhiled/snippets/dp/hu-tucker.html
    - https://github.com/beet-aizu/library/blob/master/algorithm/optimalbinarytree.cpp
    - https://lumakernel.github.io/ecasdqina/algorithm/Hu-Tucker
    -  https://atcoder.jp/contests/kupc2012/submissions/29656
- monotone minima
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html
  - https://ferin-tech.hatenablog.com/entry/2018/02/23/071343
  - https://ei1333.github.io/luzhiled/snippets/dp/monotone-minima.html
  - https://github.com/beet-aizu/library/blob/master/algorithm/monotoneminima.cpp
  - https://lumakernel.github.io/ecasdqina/math/Monge
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/speedup/Monotone-Minima
  - http://sigma425.hatenablog.com/entry/2015/12/01/162720
- SMAWK algorithm
  - https://en.wikipedia.org/wiki/SMAWK_algorithm
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html
  - https://drive.google.com/drive/folders/1FMOglXlDlyg6FJiP5QTJ0iSMq7XA2mqy
- オフライン・オンライン変換
  - https://qiita.com/tmaehara/items/0687af2cfb807cde7860
  - https://github.com/ei1333/library/blob/master/dp/online-offline-dp.cpp
  - https://docs.google.com/presentation/d/1cgPtVG4j4Ima6Exf_Kw1IdYVfmfDJSGwaEgOMgPkWHg
- divide and conquer
  - https://ferin-tech.hatenablog.com/entry/2018/02/23/071343
  - https://www.hamayanhamayan.com/entry/2017/03/20/234711
  - https://ei1333.github.io/algorithm/dynamic-programming.html
  - https://ei1333.github.io/luzhiled/snippets/dp/divide-and-conquer-optimization.html
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/speedup/Divide-and-Conquer-Optimization


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2415/review/4082345/emthrm/C++14
