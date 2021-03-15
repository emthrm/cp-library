---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/dp/knuth_yao_speedup.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth-Yao speedup"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/knuth_yao_speedup.hpp\"\n#include <algorithm>\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename T>\r\nT knuth_yao_speedup(const std::vector<std::vector<T>>\
    \ &f, const T inf) {\r\n  int n = f.size();\r\n  if (n == 0) return 0;\r\n  std::vector<std::vector<T>>\
    \ dp(n, std::vector<T>(n, inf));\r\n  std::vector<std::vector<int>> argmin(n,\
    \ std::vector<int>(n, -1));\r\n  for (int i = 0; i < n; ++i) {\r\n    dp[i][i]\
    \ = 0;\r\n    argmin[i][i] = i;\r\n  }\r\n  for (int width = 2; width <= n; ++width)\
    \ {\r\n    for (int i = 0; i + width - 1 < n; ++i) {\r\n      int j = i + width\
    \ - 1, right = std::min(j - 1, argmin[i + 1][j]);\r\n      for (int k = argmin[i][j\
    \ - 1]; k <= right; ++k) {\r\n        T tmp = dp[i][k] + dp[k + 1][j] + f[i][j];\r\
    \n        if (dp[i][j] > tmp) {\r\n          dp[i][j] = tmp;\r\n          argmin[i][j]\
    \ = k;\r\n        }\r\n      }\r\n    }\r\n  }\r\n  return dp[0][n - 1];\r\n}\r\
    \n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nT knuth_yao_speedup(const std::vector<std::vector<T>> &f, const\
    \ T inf) {\r\n  int n = f.size();\r\n  if (n == 0) return 0;\r\n  std::vector<std::vector<T>>\
    \ dp(n, std::vector<T>(n, inf));\r\n  std::vector<std::vector<int>> argmin(n,\
    \ std::vector<int>(n, -1));\r\n  for (int i = 0; i < n; ++i) {\r\n    dp[i][i]\
    \ = 0;\r\n    argmin[i][i] = i;\r\n  }\r\n  for (int width = 2; width <= n; ++width)\
    \ {\r\n    for (int i = 0; i + width - 1 < n; ++i) {\r\n      int j = i + width\
    \ - 1, right = std::min(j - 1, argmin[i + 1][j]);\r\n      for (int k = argmin[i][j\
    \ - 1]; k <= right; ++k) {\r\n        T tmp = dp[i][k] + dp[k + 1][j] + f[i][j];\r\
    \n        if (dp[i][j] > tmp) {\r\n          dp[i][j] = tmp;\r\n          argmin[i][j]\
    \ = k;\r\n        }\r\n      }\r\n    }\r\n  }\r\n  return dp[0][n - 1];\r\n}\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: dp/knuth_yao_speedup.hpp
  requiredBy: []
  timestamp: '2021-02-25 03:52:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/dp/knuth_yao_speedup.test.cpp
documentation_of: dp/knuth_yao_speedup.hpp
layout: document
title: Knuth-Yao speedup
---


### Monge 性

重み関数 $f$ を考える．

- QI (quandrangle inequality)

  $A \cap B \neq \phi$ を満たす任意の区間 $A, B$ について

  $$f(A \cup B) + f(A \cap B) \geq f(A) + f(B) \text{，}$$

- MLI (monotone on the lattice intervals)

  $A \subset B$ を満たす任意の区間 $A, B$ について

  $$f(a) \leq f(b) \text{，}$$

  すなわち任意の $i \leq j,\ k \leq l$ について

  $$f(i, l) + f(j, k) \geq f(i, k) + f(j, l)$$

の両方が成り立つとき, $f$ は Monge 性を満たす．


## 時間計算量

$O(N^2)$


## 使用法

||説明|
|:--:|:--:|
|`knuth_yao_speedup(f, ∞)`|Knuth-Yao speedup を用いた重み行列 $f$ に対する動的計画法の解|


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
  - https://dic.kimiyuki.net/monotone-minima
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html
  - https://ferin-tech.hatenablog.com/entry/2018/02/23/071343
  - https://ei1333.github.io/luzhiled/snippets/dp/monotone-minima.html
  - https://github.com/beet-aizu/library/blob/master/algorithm/monotoneminima.cpp
  - https://lumakernel.github.io/ecasdqina/math/Monge
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/speedup/Monotone-Minima
  - http://sigma425.hatenablog.com/entry/2015/12/01/162720
- SMAWK algorithm
  - https://en.wikipedia.org/wiki/SMAWK_algorithm
  - https://dic.kimiyuki.net/smawk-algorithm
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

https://atcoder.jp/contests/kupc2012/submissions/20470375
