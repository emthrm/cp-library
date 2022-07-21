---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/matrix_tree_theorem.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u884C\u5217\u6728\u5B9A\u7406\n * @docs docs/graph/spectral_graph_theory.md\n\
    \ */\n\n#pragma once\n#include <algorithm>\n#include <iterator>\n#include <vector>\n\
    \n#include \"../math/matrix/determinant.hpp\"\n#include \"../math/matrix/matrix.hpp\"\
    \n#include \"./edge.hpp\"\n\ntemplate <typename T, typename CostType>\nT matrix_tree_theorem(const\
    \ std::vector<std::vector<Edge<CostType>>>& graph,\n                      const\
    \ T eps = 1e-8) {\n  const int n = graph.size();\n  if (n == 1) return 1;\n  Matrix<int>\
    \ laplacian(n, n, 0);\n  for (int i = 0; i < n; ++i) {\n    for (const Edge<CostType>&\
    \ e : graph[i]) {\n      ++laplacian[e.src][e.src];\n      --laplacian[e.src][e.dst];\n\
    \    }\n  }\n  Matrix<int> cofactor(n - 1, n - 1);\n  for (int i = 0; i < n -\
    \ 1; ++i) {\n    std::copy(std::next(laplacian[i + 1].begin()), laplacian[i +\
    \ 1].end(),\n              cofactor[i].begin());\n  }\n  return det(cofactor,\
    \ eps);\n}\n"
  dependsOn:
  - math/matrix/determinant.hpp
  - math/matrix/matrix.hpp
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/matrix_tree_theorem.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
# spectral graph theory


### 行列木定理 (Kirchhoff's matrix tree theorem)

無向グラフ $G$ の全域木の個数は $G$ のラプラシアン行列の任意の余因子に等しい．


### ケイリーの公式 (Cayley's formula)

$N$ 頂点のラベル付きの木の個数は $N^{N - 2}$ である．

行列木定理の特殊なときとして示せる．


### Lindström–Gessel–Viennot lemma

有向非巡回グラフ $G$，頂点集合 $A = \lbrace a_1, a_2, \ldots, a_n \rbrace,\ B = \lbrace b_1, b_2, \ldots, b_n \rbrace$，[可換環](../../.verify-helper/docs/static/algebraic_structure.md) $R$ 上の重み $w \colon E(G) \to R$ が与えられる．ただし有向パス $P$ に対して $\omega(P) \mathrel{:=} \prod_{e \in P} w(e)$ とおき，任意の $s, t \in V(G)$ に対して $e(s, t) \mathrel{:=} \sum_{\text{始点 } s \text{・終点 } t \text{ の有向パス } P} \omega(P)$ が well-defined であるとする．

以下を満たす $n$ 本のパスの組を $(P_1, P_2, \ldots, P_n)$ と記す．

- ある $\lbrace 1, 2, \ldots, n \rbrace$ の置換 $\sigma$ が存在し，任意の $i \in \lbrace 1, 2, \ldots, n \rbrace$ に対して $P_i$ は始点 $a_i$・終点 $b_{\sigma(i)}$ の有向パスである．
- $i \neq j$ を満たす任意の $i, j \in \lbrace 1, 2, \ldots, n \rbrace$ に対して $P_i$ と $P_j$ は点素である．

このとき

$$
  \det(M) = \sum_{(P_1, P_2, \ldots, P_n)} \mathrm{sgn}(\sigma) \prod_{i = 1}^n \omega(P_i)
$$

が成り立つ．ただし $M$ は $m_{ij} \mathrel{:=} e(a_i, b_j)$ で定義される $n$ 次正方行列である．

特殊な場合として，任意の $e \in E(G)$ に対して $w(e) = 1$ が成り立つときを考える．このとき $e(s, t)$ は始点 $s$・終点 $t$ の有向パスの本数に等しい．

さらに $i < j,\ k < l$ を満たす任意の $i, j, k, l \in \lbrace 1, 2, \ldots, n \rbrace$ に対して，始点 $a_i$・終点 $b_l$ の有向パスと始点 $a_j$・終点 $b_k$ の有向パスが必ず交差するとき，任意の $(P_1, P_2, \ldots, P_n)$ に対応する置換 $\sigma$ は恒等置換のみとなる．すなわち始点 $a_i$ に対応する終点は必ず $b_i$ となる．


## 時間計算量

- 行列木定理 $O(N^3)$


## 使用法

- 行列木定理

||説明|
|:--:|:--:|
|`matrix_tree_theorem(graph, ε = 1e-8)`|無向グラフ $\mathrm{graph}$ の全域木の個数|


## 参考

- https://www.slideshare.net/irrrrr/ss-25911553

行列木定理
- https://mizuwater0.hatenablog.com/entry/2018/11/25/233547
- https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf

ケイリーの公式
- http://joisino.hatenablog.com/entry/2017/08/20/200000

Lindström–Gessel–Viennot lemma
- https://en.wikipedia.org/wiki/Lindstr%C3%B6m%E2%80%93Gessel%E2%80%93Viennot_lemma
- https://suikaba.hatenablog.com/entry/2018/12/19/025636
- https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf
- https://twitter.com/kotatsugame_t/status/1411648290546851840
- https://twitter.com/noshi91/status/1432074841675362304
- https://atcoder.jp/contests/abc216/editorial/2561


## Verified

- [行列木定理](https://atcoder.jp/contests/jsc2021/submissions/21877707)
