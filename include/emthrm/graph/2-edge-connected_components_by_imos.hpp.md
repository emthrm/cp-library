---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/enumerate_bridges.hpp
    title: "\u6A4B\u306E\u691C\u51FA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/2-edge-connected_components_by_imos.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ \u3044\u3082\u3059\u6CD5\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/2-edge-connected_components_by_imos.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <set>\n#include <queue>\n#include <ranges>\n\
    #include <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/enumerate_bridges.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/graph/enumerate_bridges.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 8 \"include/emthrm/graph/enumerate_bridges.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>>\
    \ enumerate_bridges(\n    const std::vector<std::vector<Edge<CostType>>>& graph)\
    \ {\n  const int n = graph.size();\n  std::vector<Edge<CostType>> res;\n  std::vector<int>\
    \ depth(n, -1), imos(n, 0);\n  const auto dfs = [&graph, &res, &depth, &imos](\n\
    \      auto dfs, const int par, const int ver) -> void {\n    bool has_multiple_edges\
    \ = false;\n    for (const Edge<CostType>& e : graph[ver]) {\n      if (depth[e.dst]\
    \ == -1) {\n        depth[e.dst] = depth[ver] + 1;\n        dfs(dfs, ver, e.dst);\n\
    \        if (imos[e.dst] == 0) {\n          res.emplace_back(std::min(ver, e.dst),\
    \ std::max(ver, e.dst), e.cost);\n        }\n        imos[ver] += imos[e.dst];\n\
    \      } else if (!has_multiple_edges && e.dst == par) {\n        has_multiple_edges\
    \ = true;\n      } else if (depth[e.dst] < depth[ver]) {\n        ++imos[ver];\n\
    \        --imos[e.dst];\n      }\n    }\n  };\n  for (int i = 0; i < n; ++i) {\n\
    \    if (depth[i] == -1) {\n      depth[i] = 0;\n      dfs(dfs, -1, i);\n    }\n\
    \  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 13 \"include/emthrm/graph/2-edge-connected_components_by_imos.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType, bool IS_FULL_VER = false>\n\
    struct TwoEdgeConnectedComponentsByImos {\n  std::vector<int> id;\n  std::vector<Edge<CostType>>\
    \ bridge;\n  std::vector<std::vector<int>> vertices;\n  std::vector<std::vector<Edge<CostType>>>\
    \ g;\n\n  explicit TwoEdgeConnectedComponentsByImos(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : bridge(enumerate_bridges(graph)) {\n    const int n = graph.size();\n\
    \    id.assign(n, -1);\n    std::set<std::pair<int, int>> st;\n    for (const\
    \ Edge<CostType>& e : bridge) st.emplace(e.src, e.dst);\n    int m = 0;\n    std::queue<int>\
    \ que;\n    for (int i = 0; i < n; ++i) {\n      if (id[i] != -1) continue;\n\
    \      que.emplace(i);\n      id[i] = m++;\n      if constexpr (IS_FULL_VER) vertices.emplace_back(std::vector<int>{i});\n\
    \      while (!que.empty()) {\n        const int ver = que.front();\n        que.pop();\n\
    \        for (const int e : graph[ver]\n                         | std::views::transform(&Edge<CostType>::dst))\
    \ {\n          if (id[e] == -1 && !st.contains(std::minmax(ver, e))) {\n     \
    \       id[e] = id[i];\n            if constexpr (IS_FULL_VER) vertices.back().emplace_back(e);\n\
    \            que.emplace(e);\n          }\n        }\n      }\n    }\n    g.resize(m);\n\
    \    for (const Edge<CostType>& e : bridge) {\n      const int u = id[e.src],\
    \ v = id[e.dst];\n      g[u].emplace_back(u, v, e.cost);\n      g[v].emplace_back(v,\
    \ u, e.cost);\n    }\n    if constexpr (IS_FULL_VER) {\n      for (int i = 0;\
    \ i < m; ++i) {\n        std::sort(vertices[i].begin(), vertices[i].end());\n\
    \      }\n    }\n  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_IMOS_HPP_\n#define EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_IMOS_HPP_\n\
    \n#include <algorithm>\n#include <set>\n#include <queue>\n#include <ranges>\n\
    #include <utility>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\
    #include \"emthrm/graph/enumerate_bridges.hpp\"\n\nnamespace emthrm {\n\ntemplate\
    \ <typename CostType, bool IS_FULL_VER = false>\nstruct TwoEdgeConnectedComponentsByImos\
    \ {\n  std::vector<int> id;\n  std::vector<Edge<CostType>> bridge;\n  std::vector<std::vector<int>>\
    \ vertices;\n  std::vector<std::vector<Edge<CostType>>> g;\n\n  explicit TwoEdgeConnectedComponentsByImos(\n\
    \      const std::vector<std::vector<Edge<CostType>>>& graph)\n      : bridge(enumerate_bridges(graph))\
    \ {\n    const int n = graph.size();\n    id.assign(n, -1);\n    std::set<std::pair<int,\
    \ int>> st;\n    for (const Edge<CostType>& e : bridge) st.emplace(e.src, e.dst);\n\
    \    int m = 0;\n    std::queue<int> que;\n    for (int i = 0; i < n; ++i) {\n\
    \      if (id[i] != -1) continue;\n      que.emplace(i);\n      id[i] = m++;\n\
    \      if constexpr (IS_FULL_VER) vertices.emplace_back(std::vector<int>{i});\n\
    \      while (!que.empty()) {\n        const int ver = que.front();\n        que.pop();\n\
    \        for (const int e : graph[ver]\n                         | std::views::transform(&Edge<CostType>::dst))\
    \ {\n          if (id[e] == -1 && !st.contains(std::minmax(ver, e))) {\n     \
    \       id[e] = id[i];\n            if constexpr (IS_FULL_VER) vertices.back().emplace_back(e);\n\
    \            que.emplace(e);\n          }\n        }\n      }\n    }\n    g.resize(m);\n\
    \    for (const Edge<CostType>& e : bridge) {\n      const int u = id[e.src],\
    \ v = id[e.dst];\n      g[u].emplace_back(u, v, e.cost);\n      g[v].emplace_back(v,\
    \ u, e.cost);\n    }\n    if constexpr (IS_FULL_VER) {\n      for (int i = 0;\
    \ i < m; ++i) {\n        std::sort(vertices[i].begin(), vertices[i].end());\n\
    \      }\n    }\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_IMOS_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/enumerate_bridges.hpp
  isVerificationFile: false
  path: include/emthrm/graph/2-edge-connected_components_by_imos.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/2-edge-connected_components_by_imos.test.cpp
documentation_of: include/emthrm/graph/2-edge-connected_components_by_imos.hpp
layout: document
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206 (2-edge-connected component) \u5206\
  \u89E3 \u3044\u3082\u3059\u6CD5\u7248"
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
