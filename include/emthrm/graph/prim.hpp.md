---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/prim.test.cpp
    title: "\u30B0\u30E9\u30D5/Prim \u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/prim.hpp\"\n\n\n\n#include <functional>\n\
    #include <queue>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 9 \"include/emthrm/graph/prim.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nCostType prim(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n              const int root = 0) {\n  const int n = graph.size();\n\
    \  CostType res = 0;\n  std::vector<bool> is_visited(n, false);\n  is_visited[root]\
    \ = true;\n  std::priority_queue<Edge<CostType>,\n                      std::vector<Edge<CostType>>,\n\
    \                      std::greater<Edge<CostType>>> que;\n  for (const Edge<CostType>&\
    \ e : graph[root]) {\n    if (e.dst != root) que.emplace(e);\n  }\n  while (!que.empty())\
    \ {\n    const Edge<CostType> e1 = que.top();\n    que.pop();\n    if (is_visited[e1.dst])\
    \ continue;\n    is_visited[e1.dst] = true;\n    res += e1.cost;\n    for (const\
    \ Edge<CostType>& e2 : graph[e1.dst]) {\n      if (!is_visited[e2.dst]) que.emplace(e2);\n\
    \    }\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_PRIM_HPP_\n#define EMTHRM_GRAPH_PRIM_HPP_\n\n#include\
    \ <functional>\n#include <queue>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nCostType prim(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n              const int root = 0) {\n  const int n = graph.size();\n\
    \  CostType res = 0;\n  std::vector<bool> is_visited(n, false);\n  is_visited[root]\
    \ = true;\n  std::priority_queue<Edge<CostType>,\n                      std::vector<Edge<CostType>>,\n\
    \                      std::greater<Edge<CostType>>> que;\n  for (const Edge<CostType>&\
    \ e : graph[root]) {\n    if (e.dst != root) que.emplace(e);\n  }\n  while (!que.empty())\
    \ {\n    const Edge<CostType> e1 = que.top();\n    que.pop();\n    if (is_visited[e1.dst])\
    \ continue;\n    is_visited[e1.dst] = true;\n    res += e1.cost;\n    for (const\
    \ Edge<CostType>& e2 : graph[e1.dst]) {\n      if (!is_visited[e2.dst]) que.emplace(e2);\n\
    \    }\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_PRIM_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/prim.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/prim.test.cpp
documentation_of: include/emthrm/graph/prim.hpp
layout: document
title: "Prim \u6CD5"
---

# 最小全域木 (minimum spanning tree)


## 時間計算量

$O(\lvert E \rvert \log{\lvert V \rvert})$


## 仕様

### Prim 法

|名前|戻り値|要件|
|:--|:--|:--|
|`template <typename CostType>`<br>`CostType prim(const std::vector<std::vector<Edge<CostType>>>& graph, const int root = 0);`|根を $\mathrm{root}$ とするグラフ $\mathrm{graph}$ の最小全域木のコスト|$\mathrm{graph}$ は双方向の辺の情報をもつ。|


### Kruskal 法

|名前|戻り値|備考|
|:--|:--|:--|
|`template <typename CostType>`<br>`CostType kruskal(const std::vector<std::vector<Edge<CostType>>>& graph);`|グラフ $\mathrm{graph}$ の最小全域木のコスト|$\mathrm{graph}$ には単方向の辺の情報のみでよい。|


## 参考文献

Prim 法
- Robert C. Prim: Shortest connection networks and some generalizations, *The Bell System Technical Journal*, Vol. 36, No. 6, pp. 1389–1401 (1957). https://doi.org/10.1002/j.1538-7305.1957.tb01515.x
- ~~http://www.prefield.com/algorithm/graph/prim.html~~

Kruskal 法
- Joseph B. Kruskal: On the shortest spanning subtree of a graph and the traveling salesman problem, *Proceedings of the American Mathematical Society*, Vol. 7, pp. 48–50 (1956). https://doi.org/10.1090/S0002-9939-1956-0078686-7
- https://github.com/spaghetti-source/algorithm/blob/64d34fb9b940a3e933cf36c4dd26b7457b42f50b/graph/kruskal.cc


## TODO

- https://www.slideshare.net/tmaehara/ss-17402143
- https://twitter.com/noshi91/status/1482583425421029376
- ブルーフカ法 (Borůvka's algorithm)
  - https://ja.wikipedia.org/wiki/%E3%83%96%E3%83%AB%E3%83%BC%E3%83%95%E3%82%AB%E6%B3%95
  - http://spinda2.blog48.fc2.com/blog-entry-560.html
  - https://inzkyk.github.io/algorithms/minimum_spanning_trees/boruvka_algorithms/
  - https://twitter.com/yamerarenaku/status/1166349080022462465
  - https://ei1333.github.io/luzhiled/snippets/graph/boruvka.html
  - ~~https://lumakernel.github.io/ecasdqina/graph/boruvka~~
- Fibonacchi heap を用いた Prim 法の高速化
  - https://github.com/ei1333/library/blob/master/graph/prim-fibonacchi-heap.cpp
- Euclidean minimum spanning tree
  - https://en.wikipedia.org/wiki/Euclidean_minimum_spanning_tree
  - https://www.slideshare.net/maroonrk/ss-65378126
  - http://tokoharuland.hateblo.jp/entry/2018/04/01/155743
  - https://github.com/beet-aizu/library/blob/master/graph/voronoiminimumspanningtree.cpp
  - https://judge.yosupo.jp/problem/euclidean_mst
- 最小シュタイナー木
  - https://ja.wikipedia.org/wiki/%E3%82%B7%E3%83%A5%E3%82%BF%E3%82%A4%E3%83%8A%E3%83%BC%E6%9C%A8
  - https://www.slideshare.net/wata_orz/ss-12131479
  - ~~http://www.prefield.com/algorithm/dp/steiner_tree.html~~
  - http://monyone.github.io/teihen_library/#MinimumSteinerTree
  - https://sotanishy.github.io/cp-library-cpp/graph/minimum_steiner_tree.hpp
- 最小全域有向木
  - https://37zigen.com/gabow-galil-spencer-tarjan/
  - https://noshi91.github.io/algorithm-encyclopedia/chu-liu-edmonds
  - http://joisino.hatenablog.com/entry/2017/01/11/230141
  - https://ark4rk.hatenablog.com/entry/2017/09/15/011937
  - https://twitter.com/nuo_chocorusk/status/1187055311422574593
  - https://twitter.com/yamerarenaku/status/1187065174529691648
  - https://ei1333.github.io/algorithm/chu-liu-edmond.html
  - https://ei1333.github.io/luzhiled/snippets/graph/chu-liu-edmond.html
  - https://github.com/beet-aizu/library/blob/master/graph/arborescence_edmond.cpp
  - https://github.com/beet-aizu/library/blob/master/graph/arborescence_tarjan.cpp
  - ~~https://lumakernel.github.io/ecasdqina/graph/MinimumSpanningArborescence~~
  - ~~http://www.prefield.com/algorithm/graph/chu_liu_edmonds.html~~
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/arborescence.cc
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/arborescence2.cc
  - https://github.com/primenumber/ProconLib/blob/master/Graph/MinimumArborescence.cpp
  - https://gist.github.com/tjkendev/231897301fde67d4a81f51c3f0873936
  - https://sotanishy.github.io/cp-library-cpp/graph/minimum_spanning_arborescence.cpp
  - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_B
  - https://judge.yosupo.jp/problem/directedmst
- minimum diameter spanning tree
  - ~~http://www.prefield.com/algorithm/graph/minimum_diameter_spanning_tree.html~~
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/kariv_hakimi.cc


## Submissons

- [Prim 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_2_A/review/4083632/emthrm/C++14)
- [Kruskal 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_2_A/review/4083639/emthrm/C++14)