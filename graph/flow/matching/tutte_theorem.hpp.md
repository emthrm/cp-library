---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss-Jordan elimination)"
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  - icon: ':question:'
    path: util/xorshift.hpp
    title: xorshift
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/tutte_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u30BF\
      \u30C3\u30C8\u306E\u5B9A\u7406"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/flow/matching/matching.md
    document_title: "\u30BF\u30C3\u30C8\u306E\u5B9A\u7406"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/matching/tutte_theorem.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u30BF\u30C3\u30C8\u306E\u5B9A\u7406\r\n * @docs docs/graph/flow/matching/matching.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n#include \"../../../math/matrix/matrix.hpp\"\
    \r\n#include \"../../../math/matrix/gauss_jordan.hpp\"\r\n#include \"../../../util/xorshift.hpp\"\
    \r\n\r\nint tutte_theorem(const std::vector<std::vector<int>> &graph) {\r\n  constexpr\
    \ double EPS = 1e-8;\r\n  int n = graph.size();\r\n  Matrix<double> mat(n, n,\
    \ 0);\r\n  for (int i = 0; i < n; ++i) {\r\n    for (int e : graph[i]) {\r\n \
    \     if (e > i) {\r\n        double x = 0;\r\n        while (x < EPS) {\r\n \
    \         int den = xor128.rand();\r\n          if (den > EPS) x = 1.0 * xor128.rand()\
    \ / den;\r\n        }\r\n        mat[i][e] = x;\r\n        mat[e][i] = -x;\r\n\
    \      }\r\n    }\r\n  }\r\n  return gauss_jordan(mat, EPS) / 2;\r\n}\r\n"
  dependsOn:
  - math/matrix/matrix.hpp
  - math/matrix/gauss_jordan.hpp
  - util/xorshift.hpp
  isVerificationFile: false
  path: graph/flow/matching/tutte_theorem.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/matching/tutte_theorem.test.cpp
documentation_of: graph/flow/matching/tutte_theorem.hpp
layout: document
redirect_from:
- /library/graph/flow/matching/tutte_theorem.hpp
- /library/graph/flow/matching/tutte_theorem.hpp.html
title: "\u30BF\u30C3\u30C8\u306E\u5B9A\u7406"
---
### 最大マッチング

互いに端点を共有しない辺集合の内，最大サイズのものである．


### 最小辺被覆

任意の頂点がいずれかの端点となっている辺集合の内，最小サイズのものである．


### 最大独立集合 (最大安定集合)

互いに隣接していない点集合の内，最大サイズのものである．


### 最小頂点被覆

任意の辺に対して少なくとも一方の端点を含む頂点集合の内，最小サイズのものである．


### 最大クリーク

無向グラフにおいて完全グラフである部分グラフの内，最大のものである．


## 性質

1. 孤立点のないグラフにおいて $\lvert \text{最大マッチング} \rvert + \lvert \text{最小辺被覆} \rvert = \lvert \text{頂点数} \rvert$．

2. $\lvert \text{最大独立集合} \rvert + \lvert \text{最小頂点被覆} \rvert = \lvert \text{頂点数} \rvert$．

3. $\text{完全二部マッチングの組合せの個数} \equiv \lvert A \rvert \pmod{2}$．

   ただし二部グラフを $(U, V, E)$ とおくと $A$ は $A_{ij} = \begin{cases} 1 & (\text{辺 } (U_i, V_j) \text{ が存在}) \\\\ 0 & (\text{otherwise}) \end{cases}$ を満たす行列である．

以下は二部グラフにおいて成り立つ．

4. $\lvert \text{最大マッチング} \rvert = \lvert \text{最小頂点被覆} \rvert$．

5. ホールの定理

   頂点が $U$ と $V$ に分割されるとすると $U$ の要素をすべて被覆するマッチングが存在する．

   $\Leftrightarrow$ $U$ の任意の部分集合 $S$ について $\lvert S \rvert \leq \lvert S \text{ と隣接する頂点} \rvert$ が成り立つ．

6. $\text{増加道が存在しない} \Leftrightarrow \text{最大マッチング}$．

7. $\text{DAG の最小パス被覆} = \text{頂点数} - \text{最大マッチング}$．

   特に DAG の推移閉包において $\text{反鎖の最大サイズ} = \text{最小パス被覆}$． (Dilworth の定理)


## 時間計算量

||計算量|
|:--:|:--:|
|二部グラフの最大マッチング|$O(\lvert V \rvert \lvert E \rvert)$|
|Hopcroft-Karp algorithm|$O(\lvert E \rvert \sqrt{\lvert V \rvert})$|
|二部グラフの重み付き最大マッチング|$O(\lvert E \rvert \lvert V \rvert \log{\lvert V \rvert})$|
|タットの定理|$O({\lvert V \rvert}^3)$|


## 使用法

- 二部グラフの最大マッチング

||説明|備考|
|:--:|:--:|:--:|
|`BipartiteMatching(n)`|頂点数 $N$ の二部グラフの最大マッチングを考える．||
|`match`|マッチング相手|存在しない場合は $-1$ となる．|
|`add_edge(u, v)`|辺 $(u, v)$ を張る．||
|`solve()`|最大マッチングのサイズ||
|`push_back(ver)`|頂点 $\mathrm{ver}$ に関するフローを押し戻す．|返り値は頂点 $\mathrm{ver}$ とのマッチング相手|
|`fix(ver)`|頂点 $\mathrm{ver}$ に関するマッチングを固定する．||
|`enable(ver)`|頂点 $\mathrm{ver}$ を加える．||
|`disable(ver)`|頂点 $\mathrm{ver}$ を消す．||

- Hopcroft-Karp algorithm

||説明|備考|
|:--:|:--:|:--:|
|`HopcroftKarp(left, right)`|頂点数 $\mathrm{left}$ と $\mathrm{right}$ の Hopcroft-Karp algorithm を考える．|
|`match`|マッチング相手|存在しない場合は $-1$ となる．|
|`add_edge(u, v)`|辺 $(u, v)$ を張る．||
|`solve()`|最大マッチングのサイズ||

- 二部グラフの重み付き最大マッチング

||説明|備考|
|:--:|:--:|:--:|
|`WeightedBipartiteMatching<T>(left, right, ∞)`|頂点数 $\mathrm{left}$ と $\mathrm{right}$ の二部グラフの重み付き最大マッチング を考える．||
|`add_edge(src, dst, cost)`|コスト $\mathrm{cost}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を張る．||
|`solve()`|重み付き最大マッチング||
|`matching()`|マッチング相手|存在しない場合は $-1$ となる．|

- タットの定理

||説明|
|:--:|:--:|
|`tutte_theorem(graph)`|無向グラフ $\mathrm{graph}$ の最大マッチングのサイズ|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.195-199

性質3
- https://pekempey.hatenablog.com/entry/2016/11/29/200605

性質5
- https://mathtrain.jp/hall

性質6
- https://mathtrain.jp/bipartitematching

性質7
- https://lumakernel.github.io/ecasdqina/math/dilworth-theorem
- https://anta1.hatenadiary.org/entry/20120816/1345046832

二部グラフの最大マッチング
- https://ei1333.github.io/algorithm/bipartite-matching.html

Hopcroft-Karp algorithm
- https://ei1333.github.io/luzhiled/snippets/graph/hopcroft-karp.html

二部グラフの重み付き最大マッチング
- https://qiita.com/drken/items/e805e3f514acceb87602


## ToDo

- https://www.slideshare.net/wata_orz/ss-12131479
- https://drive.google.com/file/d/1RD66csuDTAYXPmuCsiPi3HWBwtLg95T5/view
- 一般グラフの最大マッチング
  - https://min-25.hatenablog.com/entry/2016/11/21/222625
  - https://judge.yosupo.jp/problem/general_matching
  - エドモンズ・カープのアルゴリズム
    - http://www.prefield.com/algorithm/graph/maximum_matching.html
    - https://github.com/spaghetti-source/algorithm/blob/master/graph/gabow_edmonds.cc
    - https://www.dropbox.com/sh/7uhazzp6wvx9mi7/AACpEgmn--Grp9nVD3NOD9Hia
    - https://www.slideshare.net/hcpc_hokudai/ss-120540096
    - https://qiita.com/Kutimoti_T/items/5b579773e0a24d650bdf
- 一般グラフの重み付き最大マッチング
  - https://min-25.hatenablog.com/entry/2016/11/21/222625
  - http://www.prefield.com/algorithm/graph/minimum_weight_matching.html
- 木の最小辺被覆
  - https://twitter.com/Ymgch_K/status/964058288747831296
- 最大独立集合
  - https://37zigen.com/maximum-independent-set-algorithm/
  - https://drive.google.com/drive/folders/1MlboOgOEnu_zx55pGhZK80IT3hN6H-Ji
  - https://ei1333.github.io/luzhiled/snippets/graph/maximum-independent-set.html
  - https://github.com/ei1333/library/blob/master/graph/others/maximum-independent-set.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Graph/MaximumIndependentSet.cpp
  - https://judge.yosupo.jp/problem/maximum_independent_set
- 二部グラフの最小頂点被覆
  - https://www.slideshare.net/drken1215/2-86838670
- 最大クリーク
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/maximal_cliques.cc
  - https://ei1333.github.io/luzhiled/snippets/graph/maximum-clique.html
  - https://github.com/ei1333/library/blob/master/graph/others/maximum-clique.cpp
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
  - https://github.com/eandbsoftware/libraryCPP/blob/master/!StableMatching.cpp


## Verified

- [二部グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0334/review/4092638/emthrm/C++14)
- [Hopcroft-Karp algorithm](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_7_A/review/4092671/emthrm/C++14)
- [二部グラフの重み付き最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2429/review/4092692/emthrm/C++14)
- [タットの定理](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3032/review/4092716/emthrm/C++14)
