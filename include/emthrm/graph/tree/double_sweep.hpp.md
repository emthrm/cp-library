---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/double_sweep.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/double sweep"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/tree/double_sweep.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <ranges>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\
    \n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include\
    \ <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge\
    \ {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src, const\
    \ int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\
    \n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 11 \"include/emthrm/graph/tree/double_sweep.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::pair<CostType, std::vector<int>>\
    \ double_sweep(\n    const std::vector<std::vector<Edge<CostType>>>& graph) {\n\
    \  const auto dfs1 = [&graph](auto dfs1, const int par, const int ver)\n     \
    \ -> std::pair<CostType, int> {\n    std::pair<CostType, int> res{0, ver};\n \
    \   for (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst != par) [[unlikely]]\
    \ {\n        std::pair<CostType, int> child = dfs1(dfs1, ver, e.dst);\n      \
    \  child.first += e.cost;\n        if (child.first > res.first) res = child;\n\
    \      }\n    }\n    return res;\n  };\n  const int s = dfs1(dfs1, -1, 0).second;\n\
    \  const auto [diameter, t] = dfs1(dfs1, -1, s);\n  std::vector<int> path{s};\n\
    \  const auto dfs2 = [&graph, t, &path](auto dfs2, const int par, const int ver)\n\
    \      -> bool {\n    if (ver == t) return true;\n    for (const int e : graph[ver]\n\
    \                     | std::views::transform(&Edge<CostType>::dst)) {\n     \
    \ if (e != par) [[likely]] {\n        path.emplace_back(e);\n        if (dfs2(dfs2,\
    \ ver, e)) return true;\n        path.pop_back();\n      }\n    }\n    return\
    \ false;\n  };\n  assert(dfs2(dfs2, -1, s));\n  return {diameter, path};\n}\n\n\
    }  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_\n#define EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_\n\
    \n#include <cassert>\n#include <ranges>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <typename CostType>\nstd::pair<CostType, std::vector<int>> double_sweep(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const auto dfs1\
    \ = [&graph](auto dfs1, const int par, const int ver)\n      -> std::pair<CostType,\
    \ int> {\n    std::pair<CostType, int> res{0, ver};\n    for (const Edge<CostType>&\
    \ e : graph[ver]) {\n      if (e.dst != par) [[unlikely]] {\n        std::pair<CostType,\
    \ int> child = dfs1(dfs1, ver, e.dst);\n        child.first += e.cost;\n     \
    \   if (child.first > res.first) res = child;\n      }\n    }\n    return res;\n\
    \  };\n  const int s = dfs1(dfs1, -1, 0).second;\n  const auto [diameter, t] =\
    \ dfs1(dfs1, -1, s);\n  std::vector<int> path{s};\n  const auto dfs2 = [&graph,\
    \ t, &path](auto dfs2, const int par, const int ver)\n      -> bool {\n    if\
    \ (ver == t) return true;\n    for (const int e : graph[ver]\n               \
    \      | std::views::transform(&Edge<CostType>::dst)) {\n      if (e != par) [[likely]]\
    \ {\n        path.emplace_back(e);\n        if (dfs2(dfs2, ver, e)) return true;\n\
    \        path.pop_back();\n      }\n    }\n    return false;\n  };\n  assert(dfs2(dfs2,\
    \ -1, s));\n  return {diameter, path};\n}\n\n}  // namespace emthrm\n\n#endif\
    \  // EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/tree/double_sweep.hpp
  requiredBy: []
  timestamp: '2023-02-24 21:17:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/double_sweep.test.cpp
documentation_of: include/emthrm/graph/tree/double_sweep.hpp
layout: document
title: double sweep
---

木の直径を求めるアルゴリズムである。


### 木の直径

木の最遠頂点間距離である。


## 時間計算量

$O(\lvert V \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::pair<CostType, std::vector<int>> double_sweep(const std::vector<std::vector<Edge<CostType>>>& graph);`|グラフ $\mathrm{graph}$ の直径とその経路|


## 参考文献

- http://www.prefield.com/algorithm/graph/tree_diameter.html


## TODO

- 頂点の重みを基にした直径
  - https://github.com/beet-aizu/library/blob/master/tree/diameterforvertex.cpp


## Submissons

https://judge.yosupo.jp/submission/40074
