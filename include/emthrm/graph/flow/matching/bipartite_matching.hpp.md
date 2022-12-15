---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/bipartite_matching.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E8C\
      \u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/flow/matching/matching.md
    document_title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
      \u30F3\u30B0"
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/flow/matching/bipartite_matching.hpp\"\
    \n/**\n * @brief \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
    \u30F3\u30B0\n * @docs docs/graph/flow/matching/matching.md\n */\n\n#ifndef EMTHRM_GRAPH_FLOW_MATCHING_BIPARTITE_MATCHING_HPP_\n\
    #define EMTHRM_GRAPH_FLOW_MATCHING_BIPARTITE_MATCHING_HPP_\n\n#include <vector>\n\
    \nnamespace emthrm {\n\nstruct BipartiteMatching {\n  std::vector<int> match;\n\
    \n  explicit BipartiteMatching(const int n)\n      : match(n, -1), n(n), t(0),\
    \ is_alive(n, true), is_used(n, 0), graph(n) {}\n\n  void add_edge(const int u,\
    \ const int v) {\n    graph[u].emplace_back(v);\n    graph[v].emplace_back(u);\n\
    \  }\n\n  int solve() {\n    int res = 0;\n    for (int i = 0; i < n; ++i) {\n\
    \      if (is_alive[i] && match[i] == -1) {\n        ++t;\n        res += dfs(i);\n\
    \      }\n    }\n    return res;\n  }\n\n  void fix(const int ver) {\n    is_alive[ver]\
    \ = false;\n    if (match[ver] != -1) is_alive[match[ver]] = false;\n  }\n\n \
    \ int activate(const int ver) {\n    if (is_alive[ver]) return 0;\n    is_alive[ver]\
    \ = true;\n    ++t;\n    return dfs(ver) ? 1 : 0;\n  }\n\n  int deactivate(const\
    \ int ver) {\n    if (!is_alive[ver]) return 0;\n    is_alive[ver] = false;\n\
    \    const int m = match[ver];\n    if (m == -1) return 0;\n    match[ver] = match[m]\
    \ = -1;\n    ++t;\n    return dfs(m) ? 0 : -1;\n  }\n\n private:\n  const int\
    \ n;\n  int t;\n  std::vector<bool> is_alive;\n  std::vector<int> is_used;\n \
    \ std::vector<std::vector<int>> graph;\n\n  bool dfs(const int ver) {\n    is_used[ver]\
    \ = t;\n    for (const int dst : graph[ver]) {\n      if (!is_alive[dst]) continue;\n\
    \      const int m = match[dst];\n      if (m == -1 || (is_used[m] < t && dfs(m)))\
    \ {\n        match[ver] = dst;\n        match[dst] = ver;\n        return true;\n\
    \      }\n    }\n    return false;\n  }\n};\n\n}  // namespace emthrm\n\n#endif\
    \  // EMTHRM_GRAPH_FLOW_MATCHING_BIPARTITE_MATCHING_HPP_\n"
  code: "/**\n * @brief \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\
    \u30C1\u30F3\u30B0\n * @docs docs/graph/flow/matching/matching.md\n */\n\n#ifndef\
    \ EMTHRM_GRAPH_FLOW_MATCHING_BIPARTITE_MATCHING_HPP_\n#define EMTHRM_GRAPH_FLOW_MATCHING_BIPARTITE_MATCHING_HPP_\n\
    \n#include <vector>\n\nnamespace emthrm {\n\nstruct BipartiteMatching {\n  std::vector<int>\
    \ match;\n\n  explicit BipartiteMatching(const int n)\n      : match(n, -1), n(n),\
    \ t(0), is_alive(n, true), is_used(n, 0), graph(n) {}\n\n  void add_edge(const\
    \ int u, const int v) {\n    graph[u].emplace_back(v);\n    graph[v].emplace_back(u);\n\
    \  }\n\n  int solve() {\n    int res = 0;\n    for (int i = 0; i < n; ++i) {\n\
    \      if (is_alive[i] && match[i] == -1) {\n        ++t;\n        res += dfs(i);\n\
    \      }\n    }\n    return res;\n  }\n\n  void fix(const int ver) {\n    is_alive[ver]\
    \ = false;\n    if (match[ver] != -1) is_alive[match[ver]] = false;\n  }\n\n \
    \ int activate(const int ver) {\n    if (is_alive[ver]) return 0;\n    is_alive[ver]\
    \ = true;\n    ++t;\n    return dfs(ver) ? 1 : 0;\n  }\n\n  int deactivate(const\
    \ int ver) {\n    if (!is_alive[ver]) return 0;\n    is_alive[ver] = false;\n\
    \    const int m = match[ver];\n    if (m == -1) return 0;\n    match[ver] = match[m]\
    \ = -1;\n    ++t;\n    return dfs(m) ? 0 : -1;\n  }\n\n private:\n  const int\
    \ n;\n  int t;\n  std::vector<bool> is_alive;\n  std::vector<int> is_used;\n \
    \ std::vector<std::vector<int>> graph;\n\n  bool dfs(const int ver) {\n    is_used[ver]\
    \ = t;\n    for (const int dst : graph[ver]) {\n      if (!is_alive[dst]) continue;\n\
    \      const int m = match[dst];\n      if (m == -1 || (is_used[m] < t && dfs(m)))\
    \ {\n        match[ver] = dst;\n        match[dst] = ver;\n        return true;\n\
    \      }\n    }\n    return false;\n  }\n};\n\n}  // namespace emthrm\n\n#endif\
    \  // EMTHRM_GRAPH_FLOW_MATCHING_BIPARTITE_MATCHING_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/graph/flow/matching/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/matching/bipartite_matching.test.cpp
documentation_of: include/emthrm/graph/flow/matching/bipartite_matching.hpp
layout: document
redirect_from:
- /library/include/emthrm/graph/flow/matching/bipartite_matching.hpp
- /library/include/emthrm/graph/flow/matching/bipartite_matching.hpp.html
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
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


## TODO

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
  - https://judge.yosupo.jp/problem/enumerate_cliques


## Verified

- [二部グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_7_A/review/5876417/emthrm/C++17)
- [Hopcroft–Karp algorithm](https://judge.yosupo.jp/submission/2723)
- [二部グラフの重み付き最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2429/review/4092692/emthrm/C++14)
- [一般グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3032/review/5853683/emthrm/C++17)
