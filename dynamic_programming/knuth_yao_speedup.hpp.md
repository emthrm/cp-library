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
    \ std::vector<int>(n, -1));\r\n  for (int j = 0; j < n; ++j) {\r\n    dp[j][j]\
    \ = 0;\r\n    argmin[j][j] = j;\r\n    for (int i = j - 1; i >= 0; --i) {\r\n\
    \      const int right = std::min(j - 1, argmin[i + 1][j]);\r\n      for (int\
    \ k = argmin[i][j - 1]; k <= right; ++k) {\r\n        const T tmp = dp[i][k] +\
    \ dp[k + 1][j];\r\n        if (tmp < dp[i][j]) {\r\n          dp[i][j] = tmp;\r\
    \n          argmin[i][j] = k;\r\n        }\r\n      }\r\n      dp[i][j] += w[i][j];\r\
    \n    }\r\n  }\r\n  return dp;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nstd::vector<std::vector<T>> knuth_yao_speedup(\r\n    const\
    \ std::vector<std::vector<T>>& w, const T inf) {\r\n  const int n = w.size();\r\
    \n  std::vector<std::vector<T>> dp(n, std::vector<T>(n, inf));\r\n  if (n == 0)\
    \ return dp;\r\n  std::vector<std::vector<int>> argmin(n, std::vector<int>(n,\
    \ -1));\r\n  for (int j = 0; j < n; ++j) {\r\n    dp[j][j] = 0;\r\n    argmin[j][j]\
    \ = j;\r\n    for (int i = j - 1; i >= 0; --i) {\r\n      const int right = std::min(j\
    \ - 1, argmin[i + 1][j]);\r\n      for (int k = argmin[i][j - 1]; k <= right;\
    \ ++k) {\r\n        const T tmp = dp[i][k] + dp[k + 1][j];\r\n        if (tmp\
    \ < dp[i][j]) {\r\n          dp[i][j] = tmp;\r\n          argmin[i][j] = k;\r\n\
    \        }\r\n      }\r\n      dp[i][j] += w[i][j];\r\n    }\r\n  }\r\n  return\
    \ dp;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/knuth_yao_speedup.hpp
  requiredBy: []
  timestamp: '2022-03-23 02:29:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/knuth_yao_speedup.test.cpp
documentation_of: dynamic_programming/knuth_yao_speedup.hpp
layout: document
title: "Knuth\u2013Yao speedup"
---

$i \leq j$ を満たす $i, j \in \lbrace 1, 2, \ldots, n \rbrace$ で定義される二変数関数 $w(i, j)$ を考える．

- $w$ が concave quadrangle inequality を満たし，
- $\lbrack i, j \rbrack \subseteq \lbrack i^\prime, j^\prime \rbrack$ ならば $w(i, j) \leq w(i^\prime, j^\prime)$ が成り立つ

とき，

$$c(i, j) \mathrel{:=} \begin{cases} 0 & (i = j), \\ \min_{i < k \leq j} \lbrace c(i, k - 1) + c(k, j) \rbrace + w(i, j) & (i < j) \end{cases}$$

で定義される $c$ に対して $c(i, j)$ ($1 \leq i \leq j \leq n$) を $O(n^2)$ 時間・領域で計算できる．


### convex quadrangle inequality

$i \leq j$ を満たす $i, j$ で定義される二変数関数 $f(i, j)$ を考える．$i \leq i^\prime \leq j \leq j^\prime$ を満たす任意の $i, i^\prime, j, j^\prime$ に対して $f(i, j) + f(i^\prime, j^\prime) \geq f(i^\prime, j) + f(i, j^\prime)$ が成り立つならば，$f$ は convex quadrangle inequality を満たすと呼ぶ．


### concave quadrangle inequality

$i \leq j$ を満たす $i, j$ で定義される二変数関数 $f(i, j)$ を考える．$i \leq i^\prime \leq j \leq j^\prime$ を満たす任意の $i, i^\prime, j, j^\prime$ に対して $f(i, j) + f(i^\prime, j^\prime) \leq f(i^\prime, j) + f(i, j^\prime)$ が成り立つならば，$f$ は concave quadrangle inequality を満たすと呼ぶ．


### Monge property

$m \times n$ 型行列 $A$ を考える．$1 \leq i < i^\prime \leq m,\ 1 \leq j < j^\prime \leq n$ を満たす任意の $i, i^\prime \in \lbrace 1, 2, \ldots, m \rbrace,\ j, j^\prime \in \lbrace 1, 2, \ldots, n \rbrace$ に対して $A{\lbrack i, j^\prime \rbrack} + A{\lbrack i^\prime, j \rbrack} \geq A{\lbrack i, j \rbrack} + A{\lbrack i^\prime, j^\prime \rbrack}$ が成り立つという性質を Monge property と呼ぶ．Monge property を満たす $A$ は Monge matrix である．

ここで $m \times n$ 型行列 $A$ に対して，以下の二つは同値である．

- $A$ は Monge matrix である．
- 任意の $i \in \lbrace 1, 2, \ldots, m - 1 \rbrace,\ j \in \lbrace 1, 2, \ldots, n - 1 \rbrace$ に対して $A{\lbrack i, j + 1 \rbrack} + A{\lbrack i + 1, j \rbrack} \geq A{\lbrack i, j \rbrack} + A{\lbrack i + 1, j + 1 \rbrack}$ が成り立つ．

Monge matrix は totally monotone である．逆は必ずしも成り立つとは限らない．


### monotone

$m \times n$ 型行列 $A$ を考える．任意の $i \in \lbrace 1, 2, \ldots, m \rbrace$ に対して $j_i \in \mathrm{argmin}_{j \in \lbrace 1, 2, \ldots, n \rbrace} A{\lbrack i, j \rbrack}$ のとり方を一つ定める．$i < i^\prime$ を満たす任意の $i, i^\prime \in \lbrace 1, 2, \ldots, m \rbrace$ に対して $j_i \leq j_{i^\prime}$ が成り立つならば，$A$ は monotone であると呼ぶ．


### totally monotone

$m \times n$ 型行列 $A$ に対して，以下の三つは同値である．

- $A$ は totally monotone である．
- $A$ の任意の部分行列は monotone である．
- $A$ の任意の $2 \times 2$ 型部分行列は monotone である．


## 時間計算量

$O(N^2)$


## 使用法

||説明|
|:--:|:--:|
|`knuth_yao_speedup(w, ∞)`|二変数関数 $w$ に対して上で定義した $f$|


## 参考

- Yao, F. F.: Speed-Up in Dynamic Programming, SIAM Journal on Algebraic Discrete Methods, Vol. 3, No. 4, pp. 532–540 (1982).
- Bein, W., Golin, M. J., Larmore, L. L. and Zhang, Y.: The Knuth-Yao Quadrangle-Inequality Speedup is a Consequence of Total Monotonicity, ACM Trans. Algorithms, Vol. 6, No. 1 (2010).
- https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html
- https://github.com/LumaKernel/lib-cpp/blob/eb360cde5ad3e86a380de5745c7c741cfa165c37/src/math/Monge.md

Monge property
- https://noshi91.hatenablog.com/entry/2021/04/06/004409


## ToDo

- https://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#d1c516d3
- 最適二分探索木問題
  - https://atcoder.jp/contests/atc002/tasks/atc002_c
  - Hu–Tucker algorithm
    - https://ei1333.github.io/luzhiled/snippets/dp/hu-tucker.html
    - https://github.com/beet-aizu/library/blob/master/algorithm/optimalbinarytree.cpp
    - ~~https://lumakernel.github.io/ecasdqina/algorithm/Hu-Tucker~~
    - https://atcoder.jp/contests/kupc2012/submissions/29656
- Monge property の確認
  - https://twitter.com/catupper/status/1379083352725024769
  - https://twitter.com/kobae964/status/1400788795268603905
  - https://atcoder.jp/contests/abc218/tasks/abc218_h
  - https://atcoder.jp/contests/abc218/editorial/2638
  - https://twitter.com/noshi91/status/1436688971778519046
  - https://atcoder.jp/contests/arc129/tasks/arc129_e
  - https://twitter.com/noshi91/status/1462421876802977792
- monotone minima: monotone な $m \times n$ 型行列 $A$ に対して $j^\prime \in \mathrm{argmin}_{j \in \lbrace 1, 2, \ldots, n \rbrace} A{\lbrack i, j \rbrack}$ ($i = 1, 2, \ldots, m$) を $O(m + n \log{m})$ 時間で求めるアルゴリズム
  - https://dic.kimiyuki.net/monotone-minima
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html
  - https://ferin-tech.hatenablog.com/entry/2018/02/23/071343
  - https://lorent-kyopro.hatenablog.com/entry/2021/04/04/133958
  - https://future-architect.github.io/articles/20210707a/
  - https://ei1333.github.io/luzhiled/snippets/dp/monotone-minima.html
  - https://github.com/beet-aizu/library/blob/master/algorithm/monotoneminima.cpp
  - ~~https://lumakernel.github.io/ecasdqina/math/Monge~~
  - ~~https://lumakernel.github.io/ecasdqina/dynamic-programming/speedup/Monotone-Minima~~
  - http://sigma425.hatenablog.com/entry/2015/12/01/162720
  - https://docs.google.com/presentation/d/1cgPtVG4j4Ima6Exf_Kw1IdYVfmfDJSGwaEgOMgPkWHg/
- SMAWK algorithm: totally monotone な $m \times n$ 型行列 $A$ に対して $j^\prime \in \mathrm{argmin}_{j \in \lbrace 1, 2, \ldots, n \rbrace} A{\lbrack i, j \rbrack}$ ($i = 1, 2, \ldots, m$) を $O(m + n)$ 時間で求めるアルゴリズム
  - https://en.wikipedia.org/wiki/SMAWK_algorithm
  - https://dic.kimiyuki.net/smawk-algorithm
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html
  - https://drive.google.com/drive/folders/1FMOglXlDlyg6FJiP5QTJ0iSMq7XA2mqy
  - https://noshi91.github.io/Library/algorithm/smawk.cpp
  - https://yukicoder.me/problems/no/912
  - https://twitter.com/noshi91/status/1185199846061305861
  - 凸性のある $(\max, +)$-convolution
    - https://noshi91.github.io/Library/algorithm/concave_max_plus_convolution.cpp
    - https://twitter.com/noshi91/status/1425502725026942983
    - https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j
    - https://maspypy.com/%E9%A3%B4-%EF%BC%88joi%E6%98%A5%E5%90%88%E5%AE%BF-2018-j%EF%BC%89
    - https://atcoder.jp/contests/abc218/tasks/abc218_h
    - ナップサック問題
      - https://noshi91.github.io/Library/algorithm/axiotis_tzamos_knapsack.cpp.html
      - https://atcoder.jp/contests/kupc2021/tasks/kupc2021_f
      - https://atcoder.jp/contests/kupc2021/submissions/26987105
  - トロピカル半環上の Monge matrix multiplication
    - https://twitter.com/noshi91/status/1379752954060677123
    - https://twitter.com/hotmanww/status/1379755525655515140
    - https://twitter.com/noshi91/status/1374354051576467459
- LARSCH algorithm
  - https://noshi91.github.io/algorithm-encyclopedia/larsch-algorithm
  - https://noshi91.github.io/Library/algorithm/larsch.cpp.html
  - https://atcoder.jp/contests/dp/tasks/dp_z
  - https://twitter.com/lorent_kyopro/status/1379104326958772226
  - https://atcoder.jp/contests/abc228/tasks/abc228_h
  - https://twitter.com/noshi91/status/1462064752759230471
  - https://twitter.com/hotmanww/status/1462077828422246406
- divide and conquer optimization: $\mathrm{dp}(i, j) \mathrel{:=} \min_{k \in \lbrace 1, 2, \ldots, j - 1 \rbrace} \lbrace \mathrm{dp}(i - 1, k) + w(k, j) \rbrace$ ($i = 2, 3, \ldots, m,\ j = 2, 3, \ldots, n$) を考える．任意の $i \in \lbrace 2, 3, \ldots, m \rbrace,\ j \in \lbrace 2, 3, \ldots, n - 1 \rbrace$ に対して $\mathrm{argmin}_{k \in \lbrace 1, 2, \ldots, j - 1 \rbrace} \lbrace \mathrm{dp}(i - 1, k) + w(k, j) \rbrace \leq \mathrm{argmin}_{k \in \lbrace 1, 2, \ldots, j \rbrace} \lbrace \mathrm{dp}(i - 1, k) + w(k, j + 1) \rbrace$ が成り立つならば $\mathrm{dp}(i, j)$ ($i = 1, 2, \ldots, m,\ j = 1, 2, \ldots, n$) を $O(nm \log{m})$ 時間で求められる．
  - https://ferin-tech.hatenablog.com/entry/2018/02/23/071343
  - https://www.hamayanhamayan.com/entry/2017/03/20/234711
  - https://ei1333.github.io/algorithm/dynamic-programming.html
  - https://ei1333.github.io/luzhiled/snippets/dp/divide-and-conquer-optimization.html
  - ~~https://lumakernel.github.io/ecasdqina/dynamic-programming/speedup/Divide-and-Conquer-Optimization~~


## Verified

https://atcoder.jp/contests/kupc2012/submissions/30174381
