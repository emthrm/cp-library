---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/lowlink.hpp
    title: lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ lowlink \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp\"\
    \n\n\n\n// #include <algorithm>\n#include <ranges>\n#include <vector>\n\n#line\
    \ 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/lowlink.hpp\"\n\n\n\n#include <algorithm>\n#line\
    \ 6 \"include/emthrm/graph/lowlink.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 8 \"include/emthrm/graph/lowlink.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Lowlink {\n  std::vector<int>\
    \ order, lowlink, articulation_points;\n  std::vector<Edge<CostType>> bridges;\n\
    \  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  explicit Lowlink(const\
    \ std::vector<std::vector<Edge<CostType>>>& graph)\n      : graph(graph) {\n \
    \   const int n = graph.size();\n    order.assign(n, -1);\n    lowlink.resize(n);\n\
    \    int t = 0;\n    for (int i = 0; i < n; ++i) {\n      if (order[i] == -1)\
    \ dfs(-1, i, &t);\n    }\n  }\n\n private:\n  void dfs(const int par, const int\
    \ ver, int* t) {\n    order[ver] = lowlink[ver] = (*t)++;\n    int num = 0;\n\
    \    bool is_articulation_point = false;\n    for (const Edge<CostType>& e : graph[ver])\
    \ {\n      if (order[e.dst] == -1) {\n        ++num;\n        dfs(ver, e.dst,\
    \ t);\n        lowlink[ver] = std::min(lowlink[ver], lowlink[e.dst]);\n      \
    \  if (order[ver] <= lowlink[e.dst]) {\n          is_articulation_point = true;\n\
    \          if (order[ver] < lowlink[e.dst]) {\n            bridges.emplace_back(std::min(ver,\
    \ e.dst), std::max(ver, e.dst),\n                                 e.cost);\n \
    \         }\n        }\n      } else if (e.dst != par) {\n        lowlink[ver]\
    \ = std::min(lowlink[ver], order[e.dst]);\n      }\n    }\n    if ((par == -1\
    \ && num >= 2) || (par != -1 && is_articulation_point)) {\n      articulation_points.emplace_back(ver);\n\
    \    }\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 10 \"include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType, bool IS_FULL_VER = false>\n\
    struct TwoEdgeConnectedComponents : Lowlink<CostType> {\n  std::vector<int> id;\n\
    \  std::vector<std::vector<int>> vertices;\n  std::vector<std::vector<Edge<CostType>>>\
    \ g;\n\n  explicit TwoEdgeConnectedComponents(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : Lowlink<CostType>(graph) {\n    const int n = graph.size();\n\
    \    id.assign(n, -1);\n    int m = 0;\n    for (int i = 0; i < n; ++i) {\n  \
    \    if (id[i] == -1) dfs(-1, i, &m);\n    }\n    g.resize(m);\n    for (const\
    \ Edge<CostType>& e : this->bridges) {\n      const int u = id[e.src], v = id[e.dst];\n\
    \      g[u].emplace_back(u, v, e.cost);\n      g[v].emplace_back(v, u, e.cost);\n\
    \    }\n    // if constexpr (IS_FULL_VER) {\n    //   for (int i = 0; i < m; ++i)\
    \ {\n    //     std::sort(vertices[i].begin(), vertices[i].end());\n    //   }\n\
    \    // }\n  }\n\n private:\n  void dfs(const int par, const int ver, int* m)\
    \ {\n    if (par != -1 && this->order[par] >= this->lowlink[ver]) {\n      id[ver]\
    \ = id[par];\n    } else {\n      id[ver] = (*m)++;\n      if constexpr (IS_FULL_VER)\
    \ vertices.emplace_back();\n    }\n    if constexpr (IS_FULL_VER) vertices[id[ver]].emplace_back(ver);\n\
    \    for (const int e : this->graph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (id[e] == -1) dfs(ver, e, m);\n    }\n  }\n};\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_\n#define\
    \ EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_\n\n// #include <algorithm>\n\
    #include <ranges>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n#include\
    \ \"emthrm/graph/lowlink.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename CostType,\
    \ bool IS_FULL_VER = false>\nstruct TwoEdgeConnectedComponents : Lowlink<CostType>\
    \ {\n  std::vector<int> id;\n  std::vector<std::vector<int>> vertices;\n  std::vector<std::vector<Edge<CostType>>>\
    \ g;\n\n  explicit TwoEdgeConnectedComponents(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : Lowlink<CostType>(graph) {\n    const int n = graph.size();\n\
    \    id.assign(n, -1);\n    int m = 0;\n    for (int i = 0; i < n; ++i) {\n  \
    \    if (id[i] == -1) dfs(-1, i, &m);\n    }\n    g.resize(m);\n    for (const\
    \ Edge<CostType>& e : this->bridges) {\n      const int u = id[e.src], v = id[e.dst];\n\
    \      g[u].emplace_back(u, v, e.cost);\n      g[v].emplace_back(v, u, e.cost);\n\
    \    }\n    // if constexpr (IS_FULL_VER) {\n    //   for (int i = 0; i < m; ++i)\
    \ {\n    //     std::sort(vertices[i].begin(), vertices[i].end());\n    //   }\n\
    \    // }\n  }\n\n private:\n  void dfs(const int par, const int ver, int* m)\
    \ {\n    if (par != -1 && this->order[par] >= this->lowlink[ver]) {\n      id[ver]\
    \ = id[par];\n    } else {\n      id[ver] = (*m)++;\n      if constexpr (IS_FULL_VER)\
    \ vertices.emplace_back();\n    }\n    if constexpr (IS_FULL_VER) vertices[id[ver]].emplace_back(ver);\n\
    \    for (const int e : this->graph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (id[e] == -1) dfs(ver, e, m);\n    }\n  }\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/lowlink.hpp
  isVerificationFile: false
  path: include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/2-edge-connected_components_by_lowlink.test.cpp
documentation_of: include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp
layout: document
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206 (2-edge-connected component) \u5206\
  \u89E3 lowlink \u7248"
---

# 二重辺連結成分 (2-edge-connected component) 分解

無向グラフを橋の存在しない部分グラフに分解することである。

それぞれの成分には、任意の3点を始点・経由点・終点とする辺素パスが存在し、さらに任意の2点を結ぶ2本以上の辺素パスが存在する。


### bridge-block tree

二重辺連結成分を一つの頂点に縮約することで得られる木である。


## 時間計算量

||時間計算量|
|:--|:--|
|[lowlink](lowlink.md) 版|$O(\lvert V \rvert + \lvert E \rvert)$|
|いもす法版|$O(\lvert V \rvert + \lvert E \rvert \log{\lvert E \rvert})$|


## 仕様

### lowlink 版

```cpp
template <typename CostType, bool IS_FULL_VER = false>
struct TwoEdgeConnectedComponents : Lowlink<CostType>;
```

- `CostType`：辺のコストを表す型
- `IS_FULL_VER`：完全版かを表す変数

#### メンバ変数

|名前|説明|要件|
|:--|:--|:--|
|`std::vector<int> id`|`id[i]` は元のグラフの頂点 $i$ を含む頂点を表す。||
|`std::vector<std::vector<int>> vertices`|`vertices[i]` は縮約後のグラフの頂点 $i$ に含まれる頂点を表す。|完全版|
|`std::vector<std::vector<Edge<CostType>>> g`|二重辺連結成分を一つの頂点に縮約したグラフ||

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit TwoEdgeConnectedComponents(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|


### いもす法版

```cpp
template <typename CostType, bool IS_FULL_VER = false>
struct TwoEdgeConnectedComponentsByImos;
```

- `CostType`：辺のコストを表す型
- `IS_FULL_VER`：完全版かを表す変数

#### メンバ変数

|名前|説明|要件|
|:--|:--|:--|
|`std::vector<int> id`|`id[i]` は元のグラフの頂点 $i$ を含む頂点を表す。||
|`std::vector<Edge<CostType>> bridge`|橋||
|`std::vector<std::vector<int>> vertices`|`vertices[i]` は縮約後のグラフの頂点 $i$ に含まれる頂点を表す。|完全版|
|`std::vector<std::vector<Edge<CostType>>> g`|二重辺連結成分を一つの頂点に縮約したグラフ||

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit TwoEdgeConnectedComponentsByImos(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 参考文献

- https://en.wikipedia.org/wiki/Bridge_(graph_theory)
- https://www.slideshare.net/chokudai/arc039

lowlink 版
- https://ei1333.github.io/luzhiled/snippets/graph/two-edge-connected-components.html


## TODO

- 三重辺連結成分分解
  - https://ja.wikipedia.org/wiki/%E9%80%A3%E7%B5%90%E3%82%B0%E3%83%A9%E3%83%95
  - https://judge.yosupo.jp/problem/three_edge_connected_components


## Submissons

- [lowlink 版](https://atcoder.jp/contests/arc039/submissions/9288123)
- [いもす法版](https://judge.yosupo.jp/submission/5729)
