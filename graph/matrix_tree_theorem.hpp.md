---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: math/matrix/determinant.hpp
    title: "\u884C\u5217\u5F0F (determinant)"
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/matrix_tree_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/spectral_graph_theory.md
    document_title: "\u884C\u5217\u6728\u5B9A\u7406"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/matrix_tree_theorem.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u884C\u5217\u6728\u5B9A\u7406\r\n * @docs docs/graph/spectral_graph_theory.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n#include \"edge.hpp\"\r\n#include\
    \ \"../math/matrix/matrix.hpp\"\r\n#include \"../math/matrix/determinant.hpp\"\
    \r\n\r\ntemplate <typename T, typename CostType>\r\nT matrix_tree_theorem(const\
    \ std::vector<std::vector<Edge<CostType>>> &graph, const T EPS) {\r\n  int n =\
    \ graph.size();\r\n  Matrix<int> laplacian(n, n, 0);\r\n  for (int i = 0; i <\
    \ n; ++i) for (const Edge<CostType> &e : graph[i]) {\r\n    ++laplacian[e.src][e.src];\r\
    \n    --laplacian[e.src][e.dst];\r\n  }\r\n  Matrix<int> cofactor(n - 1, n - 1);\r\
    \n  for (int i = 0; i < n - 1; ++i) for (int j = 0; j < n - 1; ++j) cofactor[i][j]\
    \ = laplacian[i + 1][j + 1];\r\n  return det(cofactor, EPS);\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - math/matrix/matrix.hpp
  - math/matrix/determinant.hpp
  isVerificationFile: false
  path: graph/matrix_tree_theorem.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/matrix_tree_theorem.test.cpp
documentation_of: graph/matrix_tree_theorem.hpp
layout: document
redirect_from:
- /library/graph/matrix_tree_theorem.hpp
- /library/graph/matrix_tree_theorem.hpp.html
title: "\u884C\u5217\u6728\u5B9A\u7406"
---
# スペクトルグラフ理論 (spectral graph theory)

隣接行列やラプラシアン行列等を用いてグラフを解析する手法である．

1. 行列木定理 (Kirchhoff's theorem, Kirchhoff's matrix tree theorem)

   ラプラシアン行列の任意の余因子は全域木の個数と等しい．

2. ラプラシアン行列における固有値$0$の個数は連結成分の個数に等しい．

3. 隣接行列の行列式の偶奇と完全マッチングの個数の偶奇は一致する．

4. ケイリーの公式 (Cayley's formula)

   $n$ 頂点のラベル付きの木の総数は $N^{N - 2}$ 個である．


### ラプラシアン行列 (laplacian Matrix)

$N$ 頂点の無向グラフにおいて

$$A_{ij} = \begin{cases} \text{頂点 } i \text{ の次数} & (i = j) \\ -(\text{頂点 } i \text{ と } j \text{ を結ぶ辺の本数}) & (\text{otherwise}) \end{cases}$$

となる $N \times N$ 行列である．


## 時間計算量

- 行列木定理 $O(N^3)$


## 使用法

- 行列木定理

||説明|備考|
|:--:|:--:|:--:|
|`matrix_tree_theorem(graph, ε)`|グラフ $\mathrm{graph}$ の全域木の個数|双方向の辺の情報が必要である．|


## 参考

1. https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf
2. https://www.slideshare.net/irrrrr/ss-25911553
3. https://pekempey.hatenablog.com/entry/2016/11/29/200605
4. http://joisino.hatenablog.com/entry/2017/08/20/200000


## ToDo

- LGV 公式
  - https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf


## Verified

- [行列木定理](https://atcoder.jp/contests/jsc2021/submissions/21877707)
