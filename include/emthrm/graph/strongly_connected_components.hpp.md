---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/strongly_connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/strongly_connected_components.hpp\"\
    \n\n\n\n// #include <algorithm>\n#include <ranges>\n#include <vector>\n\n#line\
    \ 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 9 \"include/emthrm/graph/strongly_connected_components.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename CostType, bool IS_FULL_VER = false>\nstruct StronglyConnectedComponents\
    \ {\n  std::vector<int> id;\n  std::vector<std::vector<int>> vertices;\n  std::vector<std::vector<Edge<CostType>>>\
    \ g;\n\n  explicit StronglyConnectedComponents(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : n(graph.size()), is_used(n, false), graph(graph), rgraph(n)\
    \ {\n    for (int i = 0; i < n; ++i) {\n      if (!is_used[i]) dfs(i);\n    }\n\
    \    id.assign(n, -1);\n    order.reserve(n);\n    for (int i = 0; i < n; ++i)\
    \ {\n      for (const Edge<CostType>& e : graph[i]) {\n        rgraph[e.dst].emplace_back(e.dst,\
    \ e.src, e.cost);\n      }\n    }\n    int m = 0;\n    for (int i = n - 1; i >=\
    \ 0; --i) {\n      if (id[order[i]] == -1) {\n        if constexpr (IS_FULL_VER)\
    \ vertices.emplace_back();\n        rdfs(order[i], m++);\n      }\n    }\n   \
    \ g.resize(m);\n    for (int i = 0; i < n; ++i) {\n      for (const Edge<CostType>&\
    \ e : graph[i]) {\n        if (id[i] != id[e.dst]) g[id[i]].emplace_back(id[i],\
    \ id[e.dst], e.cost);\n      }\n    }\n    // if constexpr (IS_FULL_VER) {\n \
    \   //   for (int i = 0; i < m; ++i) {\n    //     std::sort(vertices[i].begin(),\
    \ vertices[i].end());\n    //   }\n    // }\n  }\n\n private:\n  const int n;\n\
    \  std::vector<bool> is_used;\n  std::vector<int> order;\n  const std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n  std::vector<std::vector<Edge<CostType>>> rgraph;\n\n  void dfs(const\
    \ int ver) {\n    is_used[ver] = true;\n    for (const int e : graph[ver]\n  \
    \                   | std::views::transform(&Edge<CostType>::dst)) {\n      if\
    \ (!is_used[e]) dfs(e);\n    }\n    order.emplace_back(ver);\n  }\n\n  void rdfs(const\
    \ int ver, const int m) {\n    id[ver] = m;\n    if constexpr (IS_FULL_VER) vertices.back().emplace_back(ver);\n\
    \    for (const int e : rgraph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (id[e] == -1) rdfs(e, m);\n    }\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_GRAPH_STRONGLY_CONNECTED_COMPONENTS_HPP_\n#define EMTHRM_GRAPH_STRONGLY_CONNECTED_COMPONENTS_HPP_\n\
    \n// #include <algorithm>\n#include <ranges>\n#include <vector>\n\n#include \"\
    emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename CostType,\
    \ bool IS_FULL_VER = false>\nstruct StronglyConnectedComponents {\n  std::vector<int>\
    \ id;\n  std::vector<std::vector<int>> vertices;\n  std::vector<std::vector<Edge<CostType>>>\
    \ g;\n\n  explicit StronglyConnectedComponents(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : n(graph.size()), is_used(n, false), graph(graph), rgraph(n)\
    \ {\n    for (int i = 0; i < n; ++i) {\n      if (!is_used[i]) dfs(i);\n    }\n\
    \    id.assign(n, -1);\n    order.reserve(n);\n    for (int i = 0; i < n; ++i)\
    \ {\n      for (const Edge<CostType>& e : graph[i]) {\n        rgraph[e.dst].emplace_back(e.dst,\
    \ e.src, e.cost);\n      }\n    }\n    int m = 0;\n    for (int i = n - 1; i >=\
    \ 0; --i) {\n      if (id[order[i]] == -1) {\n        if constexpr (IS_FULL_VER)\
    \ vertices.emplace_back();\n        rdfs(order[i], m++);\n      }\n    }\n   \
    \ g.resize(m);\n    for (int i = 0; i < n; ++i) {\n      for (const Edge<CostType>&\
    \ e : graph[i]) {\n        if (id[i] != id[e.dst]) g[id[i]].emplace_back(id[i],\
    \ id[e.dst], e.cost);\n      }\n    }\n    // if constexpr (IS_FULL_VER) {\n \
    \   //   for (int i = 0; i < m; ++i) {\n    //     std::sort(vertices[i].begin(),\
    \ vertices[i].end());\n    //   }\n    // }\n  }\n\n private:\n  const int n;\n\
    \  std::vector<bool> is_used;\n  std::vector<int> order;\n  const std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n  std::vector<std::vector<Edge<CostType>>> rgraph;\n\n  void dfs(const\
    \ int ver) {\n    is_used[ver] = true;\n    for (const int e : graph[ver]\n  \
    \                   | std::views::transform(&Edge<CostType>::dst)) {\n      if\
    \ (!is_used[e]) dfs(e);\n    }\n    order.emplace_back(ver);\n  }\n\n  void rdfs(const\
    \ int ver, const int m) {\n    id[ver] = m;\n    if constexpr (IS_FULL_VER) vertices.back().emplace_back(ver);\n\
    \    for (const int e : rgraph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (id[e] == -1) rdfs(e, m);\n    }\n  }\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_STRONGLY_CONNECTED_COMPONENTS_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/strongly_connected_components.hpp
  requiredBy: []
  timestamp: '2023-02-24 21:17:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/strongly_connected_components.test.cpp
documentation_of: include/emthrm/graph/strongly_connected_components.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206 (strongly connected components) \u5206\u89E3"
---

有向グラフを共通部分の存在しない強連結成分に分解することである。


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

### Kosaraju's algorithm

```cpp
template <typename CostType, bool IS_FULL_VER = false>
struct StronglyConnectedComponents;
```

- `CostType`：辺のコストを表す型
- `IS_FULL_VER`：完全版かを表す型

#### メンバ変数

|名前|説明|要件|
|:--|:--|:--|
|`std::vector<int> id`|`id[i]` は元のグラフの頂点 $i$ を含む頂点を表す。||
|`std::vector<std::vector<int>> vertices`|`vertices[i]` は縮約後のグラフの頂点 $i$ に含まれる頂点を表す。|完全版|
|`std::vector<std::vector<Edge<CostType>>> g`|強連結成分を一つの頂点に縮約したグラフ||

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit StronglyConnectedComponents(const std::vector<std::vector<Edge<CostType>>>& graph);`|有向グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 備考

無向グラフの辺に向きをつけることで強連結成分分解できる $\Leftrightarrow$ グラフが2辺連結である

構築方法としては深さ優先探索木で後退辺を逆辺とすればよい。


## 参考文献

Kosaraju's algorithm
- Micha Sharir: A strong-connectivity algorithm and its applications in data flow analysis, *Computers & Mathematics with Applications*, Vol. 7, No. 1, pp. 67–72 (1981). https://doi.org/10.1016/0898-1221(81)90008-0
- https://github.com/beet-aizu/library/blob/346558ee0881bd18b10c0d32d7678b033d6b0326/graph/stronglyconnectedcomponent.cpp

備考
- https://twitter.com/noshi91/status/1172798654450520064


## TODO

- Tarjan's algorithm
  - ~~http://www.prefield.com/algorithm/graph/strongly_connected_components.html~~
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/strongly_connected_component_tarjan.cc
  - https://tubo28.me/compprog/algorithm/tarjan-scc/
- Gabow's algorithm
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/strongly_connected_component_gabow.cc


## Submissons

- [Kosaraju's algorithm](https://judge.yosupo.jp/submission/4441)
