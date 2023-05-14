---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ lowlink \u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\
      \u30EA\u30F3\u30B0\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp\"\
    \n\n\n\n#include <bit>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef\
    \ EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 10 \"include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp\"\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct LowestCommonAncestorByDoubling\
    \ {\n  std::vector<int> depth;\n  std::vector<CostType> dist;\n\n  explicit LowestCommonAncestorByDoubling(\n\
    \      const std::vector<std::vector<Edge<CostType>>>& graph)\n      : is_built(false),\
    \ n(graph.size()),\n        table_h(std::countr_zero(std::bit_floor(graph.size()))\
    \ + 1),\n        graph(graph) {\n    assert(n > 0);\n    depth.resize(n);\n  \
    \  dist.resize(n);\n    parent.resize(table_h, std::vector<int>(n));\n  }\n\n\
    \  void build(const int root = 0) {\n    is_built = true;\n    dfs(-1, root, 0,\
    \ 0);\n    for (int i = 0; i + 1 < table_h; ++i) {\n      for (int ver = 0; ver\
    \ < n; ++ver) {\n        parent[i + 1][ver] =\n            (parent[i][ver] ==\
    \ -1 ? -1 : parent[i][parent[i][ver]]);\n      }\n    }\n  }\n\n  int query(int\
    \ u, int v) const {\n    assert(is_built);\n    if (depth[u] > depth[v]) std::swap(u,\
    \ v);\n    for (int i = 0; i < table_h; ++i) {\n      if ((depth[v] - depth[u])\
    \ >> i & 1) v = parent[i][v];\n    }\n    if (u == v) return u;\n    for (int\
    \ i = table_h - 1; i >= 0; --i) {\n      if (parent[i][u] != parent[i][v]) {\n\
    \        u = parent[i][u];\n        v = parent[i][v];\n      }\n    }\n    return\
    \ parent.front()[u];\n  }\n\n  CostType distance(const int u, const int v) const\
    \ {\n    assert(is_built);\n    return dist[u] + dist[v] - dist[query(u, v)] *\
    \ 2;\n  }\n\n  int level_ancestor(int v, const int d) const {\n    assert(is_built);\n\
    \    if (depth[v] < d) return -1;\n    for (int i = depth[v] - d, bit = 0; i >\
    \ 0; i >>= 1, ++bit) {\n      if (i & 1) v = parent[bit][v];\n    }\n    return\
    \ v;\n  }\n\n private:\n  bool is_built;\n  const int n, table_h;\n  std::vector<std::vector<int>>\
    \ parent;\n  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  void dfs(const\
    \ int par, const int ver, const int cur_depth,\n           const CostType cur_dist)\
    \ {\n    depth[ver] = cur_depth;\n    dist[ver] = cur_dist;\n    parent.front()[ver]\
    \ = par;\n    for (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst !=\
    \ par) dfs(ver, e.dst, cur_depth + 1, cur_dist + e.cost);\n    }\n  }\n};\n\n\
    }  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_DOUBLING_HPP_\n#define\
    \ EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_DOUBLING_HPP_\n\n#include <bit>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct LowestCommonAncestorByDoubling\
    \ {\n  std::vector<int> depth;\n  std::vector<CostType> dist;\n\n  explicit LowestCommonAncestorByDoubling(\n\
    \      const std::vector<std::vector<Edge<CostType>>>& graph)\n      : is_built(false),\
    \ n(graph.size()),\n        table_h(std::countr_zero(std::bit_floor(graph.size()))\
    \ + 1),\n        graph(graph) {\n    assert(n > 0);\n    depth.resize(n);\n  \
    \  dist.resize(n);\n    parent.resize(table_h, std::vector<int>(n));\n  }\n\n\
    \  void build(const int root = 0) {\n    is_built = true;\n    dfs(-1, root, 0,\
    \ 0);\n    for (int i = 0; i + 1 < table_h; ++i) {\n      for (int ver = 0; ver\
    \ < n; ++ver) {\n        parent[i + 1][ver] =\n            (parent[i][ver] ==\
    \ -1 ? -1 : parent[i][parent[i][ver]]);\n      }\n    }\n  }\n\n  int query(int\
    \ u, int v) const {\n    assert(is_built);\n    if (depth[u] > depth[v]) std::swap(u,\
    \ v);\n    for (int i = 0; i < table_h; ++i) {\n      if ((depth[v] - depth[u])\
    \ >> i & 1) v = parent[i][v];\n    }\n    if (u == v) return u;\n    for (int\
    \ i = table_h - 1; i >= 0; --i) {\n      if (parent[i][u] != parent[i][v]) {\n\
    \        u = parent[i][u];\n        v = parent[i][v];\n      }\n    }\n    return\
    \ parent.front()[u];\n  }\n\n  CostType distance(const int u, const int v) const\
    \ {\n    assert(is_built);\n    return dist[u] + dist[v] - dist[query(u, v)] *\
    \ 2;\n  }\n\n  int level_ancestor(int v, const int d) const {\n    assert(is_built);\n\
    \    if (depth[v] < d) return -1;\n    for (int i = depth[v] - d, bit = 0; i >\
    \ 0; i >>= 1, ++bit) {\n      if (i & 1) v = parent[bit][v];\n    }\n    return\
    \ v;\n  }\n\n private:\n  bool is_built;\n  const int n, table_h;\n  std::vector<std::vector<int>>\
    \ parent;\n  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  void dfs(const\
    \ int par, const int ver, const int cur_depth,\n           const CostType cur_dist)\
    \ {\n    depth[ver] = cur_depth;\n    dist[ver] = cur_dist;\n    parent.front()[ver]\
    \ = par;\n    for (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst !=\
    \ par) dfs(ver, e.dst, cur_depth + 1, cur_dist + e.cost);\n    }\n  }\n};\n\n\
    }  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_DOUBLING_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp
  requiredBy: []
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/2-edge-connected_components_by_lowlink.test.cpp
  - test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
documentation_of: include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp
layout: document
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (lowest common ancestor) \u30C0\u30D6\
  \u30EA\u30F3\u30B0\u7248"
---

# 最小共通祖先 (lowest common ancestor)

根付き木のある2頂点に対して最も深い共通祖先である。


## 時間計算量

||時間計算量|
|:--|:--|
|ダブリング版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(\log{\lvert V \rvert}) \rangle$|
|Euler tour technique 版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(1) \rangle$|


## 仕様

### ダブリング版

```cpp
template <typename CostType>
struct LowestCommonAncestorByDoubling;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|備考|
|:--|:--|:--|
|`std::vector<int> depth`|`depth[i]` は頂点 $i$ の深さを表す。||
|`std::vector<CostType> dist`|`dist[i]` は根と頂点 $i$ の間の距離を表す。|cost-free 版は `depth` に同じである。|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`explicit LowestCommonAncestorByDoubling(const std::vector<std::vector<Edge<CostType>>>& graph);`|木 $\mathrm{graph}$ に対してオブジェクトを構築する。||
|`void build(const int root = 0);`|根を $\mathrm{root}$ として構築する。||
|`int query(int u, int v) const;`|頂点 $u, v$ の最小共通祖先||
|`CostType distance(const int u, const int v) const;`|頂点 $u, v$ 間の距離||
|`int level_ancestor(int v, const int d) const;`|level ancestor problem $\mathrm{LA}(v, d)$。ただし $d \leq \mathrm{depth}(v)$ でなければ $-1$ を返す。||
|`int jump(const int u, const int v, const int d) const;`|頂点 $u$ から頂点 $v$ まで距離 $d$ だけ進んだときの頂点。ただし $d > \mathrm{dist}(u, v)$ を満たすときは $-1$ を返す。|cost-free 版|


### [Euler tour technique](euler_tour_technique.md)版

```cpp
template <typename CostType>
struct LowestCommonAncestor : EulerTourTechnique<CostType>;
```

- `CostType`：辺のコストを表す型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit LowestCommonAncestor(const std::vector<std::vector<Edge<CostType>>>& graph, const int root = 0);`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`int query(int u, int v) const;`|頂点 $u, v$ の最小共通祖先|


### [heavy-light decomposition 版](heavy-light_decomposition.md)


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.292-295，マイナビ出版（2012）
- https://yukicoder.me/wiki/lowest_common_ancestor

level ancestor problem
- https://en.wikipedia.org/wiki/Level_ancestor_problem

Euler tour technique 版
- Omer Berkman and Uzi Vishkin: Recursive Star-Tree Parallel Data Structure, *SIAM Journal on Computing*, Vol. 22, No. 2, pp. 221–242 (1993). https://doi.org/10.1137/0222017
- https://github.com/drken1215/algorithm/blob/efb8cf052b095e49e70135a6fb628308d06f49b2/DataStructureOnTree/euler_tour_on_nodes.cpp


## TODO

- Tarjan's off-line lowest common ancestors algorithm
  - ~~http://www.prefield.com/algorithm/graph/least_common_ancestor.html~~
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/least_common_ancestor_tarjan.cc
  - http://monyone.github.io/teihen_library/#OfflineLCA
- level ancestor problem $\langle O(\lvert V \rvert), O(1) \rangle$
  - https://www2.compute.dtu.dk/courses/02282/2018/levelancestor/levelancestor1x1.pdf
  - https://37zigen.com/level-ancestor-problem/
  - https://hdbn.hatenadiary.org/entry/20111125/1322194487
  - https://drive.google.com/drive/folders/1atQRO6Y9bHgLDH-YLq3obDwMxIuk7--h
  - https://noshi91.hatenablog.com/entry/2019/09/22/114149
  - https://suisen-kyopro.hatenablog.com/entry/2022/04/04/043452
  - https://twitter.com/GauravML/status/1415073033522319367
  - https://twitter.com/keijak/status/1510953079872663555
  - https://github.com/noshi91/n91lib_rs/blob/c9bd9cf36cbf4637884a049a4fe44f45b06ff71f/src/data_structure/level_ancestor.rs


## Submissons

- [ダブリング版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4084783/emthrm/C++14)
  - [level ancestor problem](https://judge.yosupo.jp/submission/122542)
- [Euler tour technique 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14)
- [heavy-light decomposition 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4093404/emthrm/C++14)
