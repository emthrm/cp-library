---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC (minimum cost $s$-$t$-flow)\
      \ \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5 (successive shortest path algorithm)\
      \ \u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/flow/matching/weighted_bipartite_matching.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E8C\
      \u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\u30DE\u30C3\
      \u30C1\u30F3\u30B0"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.01.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n\n\n\n#include <cassert>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n#include <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n\
    #line 11 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T, typename U>\nstruct MinimumCostSTFlow\
    \ {\n  struct Edge {\n    int dst, rev;\n    T cap;\n    U cost;\n    explicit\
    \ Edge(const int dst, const T cap, const U cost, const int rev)\n        : dst(dst),\
    \ rev(rev), cap(cap), cost(cost) {}\n  };\n\n  const U uinf;\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  explicit MinimumCostSTFlow(const int n,\n                      \
    \       const U uinf = std::numeric_limits<U>::max())\n      : uinf(uinf), graph(n),\
    \ tinf(std::numeric_limits<T>::max()), n(n),\n        has_negative_edge(false),\
    \ prev_v(n, -1), prev_e(n, -1), dist(n),\n        potential(n, 0) {}\n\n  void\
    \ add_edge(const int src, const int dst, const T cap, const U cost) {\n    has_negative_edge\
    \ |= cost < 0;\n    graph[src].emplace_back(dst, cap, cost, graph[dst].size());\n\
    \    graph[dst].emplace_back(src, 0, -cost, graph[src].size() - 1);\n  }\n\n \
    \ U solve(const int s, const int t, T flow) {\n    if (flow == 0) [[unlikely]]\
    \ return 0;\n    U res = 0;\n    has_negative_edge ? bellman_ford(s) : dijkstra(s);\n\
    \    while (true) {\n      if (dist[t] == uinf) return uinf;\n      res += calc(s,\
    \ t, &flow);\n      if (flow == 0) break;\n      dijkstra(s);\n    }\n    return\
    \ res;\n  }\n\n  U solve(const int s, const int t) {\n    U res = 0;\n    T flow\
    \ = tinf;\n    bellman_ford(s);\n    while (potential[t] < 0 && dist[t] != uinf)\
    \ {\n      res += calc(s, t, &flow);\n      dijkstra(s);\n    }\n    return res;\n\
    \  }\n\n  std::pair<T, U> minimum_cost_maximum_flow(const int s, const int t,\n\
    \                                            const T flow) {\n    if (flow ==\
    \ 0) [[unlikely]] return {0, 0};\n    T f = flow;\n    U cost = 0;\n    has_negative_edge\
    \ ? bellman_ford(s) : dijkstra(s);\n    while (dist[t] != uinf) {\n      cost\
    \ += calc(s, t, &f);\n      if (f == 0) break;\n      dijkstra(s);\n    }\n  \
    \  return {flow - f, cost};\n  }\n\n private:\n  const T tinf;\n  const int n;\n\
    \  bool has_negative_edge;\n  std::vector<int> prev_v, prev_e;\n  std::vector<U>\
    \ dist, potential;\n  std::priority_queue<std::pair<U, int>, std::vector<std::pair<U,\
    \ int>>,\n                      std::greater<std::pair<U, int>>> que;\n\n  void\
    \ bellman_ford(const int s) {\n    std::fill(dist.begin(), dist.end(), uinf);\n\
    \    dist[s] = 0;\n    bool is_updated = true;\n    for (int step = 0; step <\
    \ n && is_updated; ++step) {\n      is_updated = false;\n      for (int i = 0;\
    \ i < n; ++i) {\n        if (dist[i] == uinf) continue;\n        for (int j =\
    \ 0; std::cmp_less(j, graph[i].size()); ++j) {\n          const Edge& e = graph[i][j];\n\
    \          if (e.cap > 0 && dist[e.dst] > dist[i] + e.cost) {\n            dist[e.dst]\
    \ = dist[i] + e.cost;\n            prev_v[e.dst] = i;\n            prev_e[e.dst]\
    \ = j;\n            is_updated = true;\n          }\n        }\n      }\n    }\n\
    \    assert(!is_updated);\n    for (int i = 0; i < n; ++i) {\n      if (dist[i]\
    \ != uinf) potential[i] += dist[i];\n    }\n  }\n\n  void dijkstra(const int s)\
    \ {\n    std::fill(dist.begin(), dist.end(), uinf);\n    dist[s] = 0;\n    que.emplace(0,\
    \ s);\n    while (!que.empty()) {\n      const auto [d, ver] = que.top();\n  \
    \    que.pop();\n      if (dist[ver] < d) continue;\n      for (int i = 0; std::cmp_less(i,\
    \ graph[ver].size()); ++i) {\n        const Edge& e = graph[ver][i];\n       \
    \ const U nxt = dist[ver] + e.cost + potential[ver] - potential[e.dst];\n    \
    \    if (e.cap > 0 && dist[e.dst] > nxt) {\n          dist[e.dst] = nxt;\n   \
    \       prev_v[e.dst] = ver;\n          prev_e[e.dst] = i;\n          que.emplace(dist[e.dst],\
    \ e.dst);\n        }\n      }\n    }\n    for (int i = 0; i < n; ++i) {\n    \
    \  if (dist[i] != uinf) potential[i] += dist[i];\n    }\n  }\n\n  U calc(const\
    \ int s, const int t, T* flow) {\n    T f = *flow;\n    for (int v = t; v != s;\
    \ v = prev_v[v]) {\n      f = std::min(f, graph[prev_v[v]][prev_e[v]].cap);\n\
    \    }\n    *flow -= f;\n    for (int v = t; v != s; v = prev_v[v]) {\n      Edge&\
    \ e = graph[prev_v[v]][prev_e[v]];\n      e.cap -= f;\n      graph[v][e.rev].cap\
    \ += f;\n    }\n    return potential[t] * f;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 8 \"include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct WeightedBipartiteMatching\
    \ {\n  explicit WeightedBipartiteMatching(const int left, const int right)\n \
    \     : is_built(false), left(left), right(right), mcf(left + right + 2) {}\n\n\
    \  void add_edge(const int src, const int dst, const T cost) {\n    mcf.add_edge(src,\
    \ left + dst, 1, -cost);\n  }\n\n  T solve() {\n    assert(!is_built);\n    is_built\
    \ = true;\n    const int s = left + right, t = left + right + 1;\n    for (int\
    \ i = 0; i < left; ++i) {\n      mcf.add_edge(s, i, 1, 0);\n    }\n    for (int\
    \ i = 0; i < right; ++i) {\n      mcf.add_edge(left + i, t, 1, 0);\n    }\n  \
    \  return -mcf.minimum_cost_maximum_flow(s, t, left).second;\n  }\n\n  std::vector<int>\
    \ matching() const {\n    assert(is_built);\n    std::vector<int> res(left, -1);\n\
    \    for (int i = 0; i < left; ++i) {\n      for (const auto& e : mcf.graph[i])\
    \ {\n        if (e.cap == 0 && left <= e.dst && e.dst < left + right) {\n    \
    \      res[i] = e.dst - left;\n          break;\n        }\n      }\n    }\n \
    \   return res;\n  }\n\n private:\n  bool is_built;\n  const int left, right;\n\
    \  MinimumCostSTFlow<int, T> mcf;\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_FLOW_MATCHING_WEIGHTED_BIPARTITE_MATCHING_HPP_\n#define\
    \ EMTHRM_GRAPH_FLOW_MATCHING_WEIGHTED_BIPARTITE_MATCHING_HPP_\n\n#include <cassert>\n\
    #include <vector>\n\n#include \"emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct WeightedBipartiteMatching\
    \ {\n  explicit WeightedBipartiteMatching(const int left, const int right)\n \
    \     : is_built(false), left(left), right(right), mcf(left + right + 2) {}\n\n\
    \  void add_edge(const int src, const int dst, const T cost) {\n    mcf.add_edge(src,\
    \ left + dst, 1, -cost);\n  }\n\n  T solve() {\n    assert(!is_built);\n    is_built\
    \ = true;\n    const int s = left + right, t = left + right + 1;\n    for (int\
    \ i = 0; i < left; ++i) {\n      mcf.add_edge(s, i, 1, 0);\n    }\n    for (int\
    \ i = 0; i < right; ++i) {\n      mcf.add_edge(left + i, t, 1, 0);\n    }\n  \
    \  return -mcf.minimum_cost_maximum_flow(s, t, left).second;\n  }\n\n  std::vector<int>\
    \ matching() const {\n    assert(is_built);\n    std::vector<int> res(left, -1);\n\
    \    for (int i = 0; i < left; ++i) {\n      for (const auto& e : mcf.graph[i])\
    \ {\n        if (e.cap == 0 && left <= e.dst && e.dst < left + right) {\n    \
    \      res[i] = e.dst - left;\n          break;\n        }\n      }\n    }\n \
    \   return res;\n  }\n\n private:\n  bool is_built;\n  const int left, right;\n\
    \  MinimumCostSTFlow<int, T> mcf;\n};\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_GRAPH_FLOW_MATCHING_WEIGHTED_BIPARTITE_MATCHING_HPP_\n"
  dependsOn:
  - include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: false
  path: include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/flow/matching/weighted_bipartite_matching.test.cpp
  - test/math/bigint.01.test.cpp
documentation_of: include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp
layout: document
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\u30DE\
  \u30C3\u30C1\u30F3\u30B0"
---

### マッチング (matching)

互いに端点を共有しない辺集合である。


### 辺被覆 (edge cover)

任意の頂点がいずれかの端点となっている辺集合である。


### 独立集合 (independent set) / 安定集合 (stable set)

互いに隣接していない頂点集合である。


### 頂点被覆 (vertex cover)

任意の辺に対して少なくとも一方の端点を含む頂点集合である。


### クリーク (clique)

無向グラフに対して完全グラフな部分グラフである。


## 性質

1. 孤立点のないグラフに対して (最大マッチングのサイズ) + (最小辺被覆のサイズ) = (頂点数) が成り立つ。

2. (最大独立集合のサイズ) + (最小頂点被覆のサイズ) = (頂点数)

3. 二部グラフ $(U, V, E)$ に対して $\lvert U \rvert = \lvert V \rvert \implies (\text{完全二部マッチングの個数}) \equiv \lvert A \rvert \pmod{2}$ が成り立つ。ただし $A$ は $a_{ij} = \begin{cases} 1 & ((U_i, V_j) \in E), \\\\ 0 & (\text{otherwise}) \end{cases}$ を満たす $\lvert U \rvert \times \lvert V \rvert$ 型行列である。

4. 二部グラフに対して、最大マッチングのサイズは最小頂点被覆のサイズに等しい。

5. 有向非巡回グラフの最小パス被覆は二部グラフの最大マッチングに帰着できる。


### Hall's theorem

二部グラフ $(U, V, E)$ に対して、以下は同値である。

- $U$ の元をすべて被覆するマッチングが存在する。
- $\forall S \subseteq U,\ \lvert S \rvert \leq \lvert \Gamma(S) \rvert$.


### Dilworth's theorem

任意の有限な半順序集合に対して、反鎖 (antichain) の最大サイズは共通部分のない鎖 (chain) に分解したときの最小サイズに等しい。

特に有向非巡回グラフ $G$ では、$\forall u, v \in V(G)$ に対して

$$
  u \leq v \iff u \text{ から } v \text{ に到達可能である。}
$$

と定義すると、$(V(G), \leq)$ は半順序集合である。$(V(G), \leq)$ に対して、共通部分のない鎖に分解したときの最小サイズは最小パス被覆のサイズを意味する。


## 時間計算量

||時間計算量|
|:--|:--|
|二部グラフの最大マッチング|$O(\lvert V \rvert \lvert E \rvert)$|
|Hopcroft–Karp algorithm|$O(\lvert E \rvert \sqrt{\lvert V \rvert})$|
|二部グラフの重み付き最大マッチング|$O(\lvert E \rvert \lvert V \rvert \log{\lvert V \rvert})$|
|一般グラフの最大マッチング|$O({\lvert V \rvert}^3 + \lvert E \rvert)$|


## 仕様

### 二部グラフの最大マッチング

```cpp
struct BipartiteMatching;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> match`|マッチした相手。ただし存在しないときは $-1$ となる。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit BipartiteMatching(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`void add_edge(const int u, const int v);`|辺 $(u, v)$ を加える。|
|`int solve();`|最大マッチングのサイズ|
|`void fix(const int ver);`|頂点 $\mathrm{ver}$ に対するマッチングを固定する。|
|`int activate(const int ver);`|頂点 $\mathrm{ver}$ を有効にしたのち、最大マッチングのサイズの変化量を返す。|
|`int deactivate(const int ver);`|頂点 $\mathrm{ver}$ を無効にしたのち、最大マッチングのサイズの変化量を返す。|


### Hopcroft–Karp algorithm

```cpp
struct HopcroftKarp;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> match`|マッチした相手。ただし存在しないときは $-1$ となる。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit HopcroftKarp(const int left, const int right);`|頂点数 $\mathrm{left}$ と $\mathrm{right}$ の二部グラフに対してオブジェクトを構築する。|
|`void add_edge(const int u, const int v);`|辺 $(u, v)$ を加える。|
|`int solve();`|最大マッチングのサイズ|


### 二部グラフの重み付き最大マッチング

```cpp
template <typename T>
struct WeightedBipartiteMatching;
```

- `T`：重みを表す型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit WeightedBipartiteMatching(const int left, const int right);`|頂点数 $\mathrm{left}$ と $\mathrm{right}$ の二部グラフに対してオブジェクトを構築する。|
|`void add_edge(const int src, const int dst, const T cost);`|重み $\mathrm{cost}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を加える。||
|`T solve();`|重み付き最大マッチングの重み||
|`std::vector<int> matching() const;`|マッチした相手。ただし存在しないときは $-1$ が格納される。|


### 一般グラフの最大マッチング

|名前|戻り値|
|:--|:--|
|`int maximum_matching(const std::vector<std::vector<int>>& graph);`|無向グラフ $\mathrm{graph}$ の最大マッチングのサイズ|


## 参考文献

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


## Submissons

- [二部グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_7_A/review/5876417/emthrm/C++17)
- [Hopcroft–Karp algorithm](https://judge.yosupo.jp/submission/2723)
- [二部グラフの重み付き最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2429/review/4092692/emthrm/C++14)
- [一般グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3032/review/5853683/emthrm/C++17)
