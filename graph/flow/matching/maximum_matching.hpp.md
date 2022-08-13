---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss\u2013Jordan elimination)"
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: util/xorshift.hpp
    title: xorshift
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/maximum_matching.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E00\
      \u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/flow/matching/matching.md
    document_title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
      \u30F3\u30B0"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/matching/maximum_matching.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief \u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\
    \u30C1\u30F3\u30B0\n * @docs docs/graph/flow/matching/matching.md\n */\n\n#pragma\
    \ once\n#include <vector>\n\n#include \"../../../math/modint.hpp\"\n#include \"\
    ../../../math/matrix/gauss_jordan.hpp\"\n#include \"../../../math/matrix/matrix.hpp\"\
    \n#include \"../../../util/xorshift.hpp\"\n\nint maximum_matching(const std::vector<std::vector<int>>&\
    \ graph) {\n  constexpr int P = 1000000007;\n  using ModInt = MInt<P>;\n  ModInt::set_mod(P);\n\
    \  const int n = graph.size();\n  Matrix<ModInt> tutte_matrix(n, n, 0);\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (const int j : graph[i]) {\n      if (j >\
    \ i) {\n        const ModInt x = xor128.rand(1, P);\n        tutte_matrix[i][j]\
    \ = x;\n        tutte_matrix[j][i] = -x;\n      }\n    }\n  }\n  return gauss_jordan(&tutte_matrix,\
    \ ModInt(0)) / 2;\n}\n"
  dependsOn:
  - math/modint.hpp
  - math/matrix/gauss_jordan.hpp
  - math/matrix/matrix.hpp
  - util/xorshift.hpp
  isVerificationFile: false
  path: graph/flow/matching/maximum_matching.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/matching/maximum_matching.test.cpp
documentation_of: graph/flow/matching/maximum_matching.hpp
layout: document
redirect_from:
- /library/graph/flow/matching/maximum_matching.hpp
- /library/graph/flow/matching/maximum_matching.hpp.html
title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
### マッチング (matching)

互いに端点を共有しない辺集合である．


### 辺被覆 (edge cover)

任意の頂点がいずれかの端点となっている辺集合である．


### 独立集合 (independent set) / 安定集合 (stable set)

互いに隣接していない頂点集合である．


### 頂点被覆 (vertex cover)

任意の辺に対して少なくとも一方の端点を含む頂点集合である．


### クリーク (clique)

無向グラフに対して完全グラフな部分グラフである．


## 性質

1. 孤立点のないグラフに対して (最大マッチングのサイズ) + (最小辺被覆のサイズ) = (頂点数) が成り立つ．

2. (最大独立集合のサイズ) + (最小頂点被覆のサイズ) = (頂点数)

3. 二部グラフ $(U, V, E)$ に対して $\lvert U \rvert = \lvert V \rvert \implies (\text{完全二部マッチングの個数}) \equiv \lvert A \rvert \pmod{2}$ が成り立つ．ただし $A$ は $a_{ij} = \begin{cases} 1 & ((U_i, V_j) \in E), \\\\ 0 & (\text{otherwise}) \end{cases}$ を満たす $\lvert U \rvert \times \lvert V \rvert$ 型行列である．

4. 二部グラフに対して，最大マッチングのサイズは最小頂点被覆のサイズに等しい．

5. 有向非巡回グラフの最小パス被覆は二部グラフの最大マッチングに帰着できる．


### Hall's theorem

二部グラフ $(U, V, E)$ に対して，以下は同値である．

- $U$ の元をすべて被覆するマッチングが存在する．
- $\forall S \subseteq U,\ \lvert S \rvert \leq \lvert \Gamma(S) \rvert$.


### Dilworth's theorem

任意の有限な半順序集合に対して，反鎖 (antichain) の最大サイズは共通部分のない鎖 (chain) に分解したときの最小サイズに等しい．

特に有向非巡回グラフ $G$ では，$\forall u, v \in V(G)$ に対して

$$
  u \leq v \iff u \text{ から } v \text{ に到達可能である．}
$$

と定義すると，$(V(G), \leq)$ は半順序集合である．$(V(G), \leq)$ に対して，共通部分のない鎖に分解したときの最小サイズは最小パス被覆のサイズを意味する．


## 時間計算量

||計算量|
|:--:|:--:|
|二部グラフの最大マッチング|$O(\lvert V \rvert \lvert E \rvert)$|
|Hopcroft–Karp algorithm|$O(\lvert E \rvert \sqrt{\lvert V \rvert})$|
|二部グラフの重み付き最大マッチング|$O(\lvert E \rvert \lvert V \rvert \log{\lvert V \rvert})$|
|一般グラフの最大マッチング|$O({\lvert V \rvert}^3 + \lvert E \rvert)$|


## 使用法

- 二部グラフの最大マッチング

||説明|備考|
|:--:|:--:|:--:|
|`BipartiteMatching(n)`|頂点数 $N$ の二部グラフの最大マッチングを考える．||
|`match`|マッチした相手|存在しないときは $-1$ となる．|
|`add_edge(u, v)`|辺 $(u, v)$ を加える．||
|`solve()`|最大マッチングのサイズ||
|`fix(ver)`|頂点 $\mathrm{ver}$ に対するマッチングを固定する．||
|`activate(ver)`|頂点 $\mathrm{ver}$ を有効にする．|返り値は最大マッチングのサイズの変化量である．|
|`deactivate(ver)`|頂点 $\mathrm{ver}$ を無効にする．|返り値は最大マッチングのサイズの変化量である．|

- Hopcroft–Karp algorithm

||説明|備考|
|:--:|:--:|:--:|
|`HopcroftKarp(left, right)`|頂点数 $\mathrm{left}$ と $\mathrm{right}$ の二部グラフで Hopcroft–Karp algorithm を考える．|
|`match`|マッチした相手|存在しないときは $-1$ となる．|
|`add_edge(u, v)`|辺 $(u, v)$ を加える．||
|`solve()`|最大マッチングのサイズ||

- 二部グラフの重み付き最大マッチング

||説明|備考|
|:--:|:--:|:--:|
|`WeightedBipartiteMatching<T>(left, right)`|頂点数 $\mathrm{left}$ と $\mathrm{right}$ の二部グラフの重み付き最大マッチングを考える．||
|`add_edge(src, dst, cost)`|重み $\mathrm{cost}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を加える．||
|`solve()`|重み付き最大マッチングの重み||
|`matching()`|マッチした相手|存在しないときは $-1$ となる．|

- 一般グラフの最大マッチング

||説明|
|:--:|:--:|
|`maximum_matching(graph)`|無向グラフ $\mathrm{graph}$ の最大マッチングのサイズ|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.195-199，マイナビ出版（2012）

性質3
- https://pekempey.hatenablog.com/entry/2016/11/29/200605

性質5・Dilworth's theorem
- https://en.wikipedia.org/wiki/Dilworth%27s_theorem
- ~~https://lumakernel.github.io/ecasdqina/math/dilworth-theorem~~
- https://anta1.hatenadiary.org/entry/20120816/1345046832

Hall's theorem
- https://mathtrain.jp/hall

二部グラフの最大マッチング
- https://ei1333.github.io/algorithm/bipartite-matching.html

Hopcroft–Karp algorithm
- https://misteer.hatenablog.com/entry/hopcroft-karp
- https://ei1333.github.io/luzhiled/snippets/graph/hopcroft-karp.html

二部グラフの重み付き最大マッチング
- https://qiita.com/drken/items/e805e3f514acceb87602

一般グラフの最大マッチング
- https://kopricky.github.io/code/Academic/maximum_matching_memo.html


## ToDo

- https://www.slideshare.net/wata_orz/ss-12131479
- https://drive.google.com/file/d/1RD66csuDTAYXPmuCsiPi3HWBwtLg95T5/view
- 一般グラフの最大マッチング
  - ~~https://min-25.hatenablog.com/entry/2016/11/21/222625~~
  - https://judge.yosupo.jp/problem/general_matching
  - Edmonds' Algorithm
    - http://www.prefield.com/algorithm/graph/maximum_matching.html
    - https://github.com/spaghetti-source/algorithm/blob/master/graph/gabow_edmonds.cc
    - https://www.dropbox.com/sh/7uhazzp6wvx9mi7/AACpEgmn--Grp9nVD3NOD9Hia
    - https://www.slideshare.net/hcpc_hokudai/ss-120540096
    - https://qiita.com/Kutimoti_T/items/5b579773e0a24d650bdf
- 一般グラフの重み付き最大マッチング
  - ~~https://min-25.hatenablog.com/entry/2016/11/21/222625~~
  - http://www.prefield.com/algorithm/graph/minimum_weight_matching.html
  - https://judge.yosupo.jp/problem/general_weighted_matching
- 木の最小辺被覆
  - https://twitter.com/Ymgch_K/status/964058288747831296
- 最大独立集合
  - https://37zigen.com/maximum-independent-set-algorithm/
  - https://drive.google.com/drive/folders/1MlboOgOEnu_zx55pGhZK80IT3hN6H-Ji
  - https://ei1333.github.io/luzhiled/snippets/graph/maximum-independent-set.html
  - https://github.com/ei1333/library/blob/master/graph/others/maximum-independent-set.hpp
  - https://github.com/primenumber/ProconLib/blob/master/Graph/MaximumIndependentSet.cpp
  - https://mugen1337.github.io/procon/Graph2/WeightedMaximumIndependentSet.cpp
  - https://sotanishy.github.io/cp-library-cpp/graph/maximum_independent_set.cpp
  - https://sotanishy.github.io/cp-library-cpp/graph/maximum_weight_independent_set.hpp
  - https://judge.yosupo.jp/problem/maximum_independent_set
- 木上の独立集合
  - https://github.com/noshi91/blog/tree/master/codes/typical90/
  - https://atcoder.jp/contests/typical90/tasks/typical90_z
  - https://twitter.com/noshi91/status/1387447778167513088
  - https://twitter.com/noshi91/status/1387448827838353411
  - https://twitter.com/noshi91/status/1387456359587729411
- 二部グラフの最小頂点被覆
  - https://www.slideshare.net/drken1215/2-86838670
- 最大クリーク
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/maximal_cliques.cc
  - https://ei1333.github.io/luzhiled/snippets/graph/maximum-clique.html
  - https://github.com/ei1333/library/blob/master/graph/others/maximum-clique.hpp
  - https://www.t3nro.net/2017/04/maximum-clique-problem/
- ハンガリアン法 (Hungarian method)
  - https://ei1333.github.io/algorithm/hungarian.html
  - https://ei1333.github.io/luzhiled/snippets/graph/hungarian.html
  - http://www.prefield.com/algorithm/math/hungarian.html
  - https://github.com/primenumber/ProconLib/blob/master/Graph/Hungarian.cpp
  - https://judge.yosupo.jp/problem/assignment
- 安定マッチング (stable matching)
  - https://ja.wikipedia.org/wiki/%E5%AE%89%E5%AE%9A%E7%B5%90%E5%A9%9A%E5%95%8F%E9%A1%8C
  - https://mathtrain.jp/galeshapley
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!StableMatching.cpp~~
  - https://sotanishy.github.io/cp-library-cpp/misc/stable_matching.hpp
- FKT algorithm
  - https://en.wikipedia.org/wiki/FKT_algorithm
  - https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf
- クリークの列挙
  - https://sotanishy.github.io/cp-library-cpp/graph/enumerate_cliques.cpp


## Verified

- [二部グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_7_A/review/5876417/emthrm/C++17)
- [Hopcroft–Karp algorithm](https://judge.yosupo.jp/submission/2723)
- [二部グラフの重み付き最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2429/review/4092692/emthrm/C++14)
- [一般グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3032/review/5853683/emthrm/C++17)
