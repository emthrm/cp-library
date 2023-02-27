---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/detect_directed_cycle.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/detect_directed_cycle.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 8 \"include/emthrm/graph/detect_directed_cycle.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>>\
    \ detect_directed_cycle(\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\n  const int n = graph.size();\n  std::vector<int> is_visited(n, 0);\n\
    \  std::vector<Edge<CostType>> edges, cycle;\n  const auto dfs = [&graph, &is_visited,\
    \ &edges, &cycle](\n      auto dfs, const int ver) -> bool {\n    is_visited[ver]\
    \ = 1;\n    for (const Edge<CostType>& e : graph[ver]) {\n      if (is_visited[e.dst]\
    \ == 1) {\n        cycle.emplace_back(e);\n        while (cycle.back().src !=\
    \ e.dst) {\n          cycle.emplace_back(edges.back());\n          edges.pop_back();\n\
    \        }\n        std::reverse(cycle.begin(), cycle.end());\n        return\
    \ true;\n      } else if (is_visited[e.dst] == 0) {\n        edges.emplace_back(e);\n\
    \        if (dfs(dfs, e.dst)) return true;\n        edges.pop_back();\n      }\n\
    \    }\n    is_visited[ver] = 2;\n    return false;\n  };\n  for (int i = 0; i\
    \ < n; ++i) {\n    if (is_visited[i] == 0 && dfs(dfs, i)) break;\n  }\n  return\
    \ cycle;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_DETECT_DIRECTED_CYCLE_HPP_\n#define EMTHRM_GRAPH_DETECT_DIRECTED_CYCLE_HPP_\n\
    \n#include <algorithm>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>>\
    \ detect_directed_cycle(\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\n  const int n = graph.size();\n  std::vector<int> is_visited(n, 0);\n\
    \  std::vector<Edge<CostType>> edges, cycle;\n  const auto dfs = [&graph, &is_visited,\
    \ &edges, &cycle](\n      auto dfs, const int ver) -> bool {\n    is_visited[ver]\
    \ = 1;\n    for (const Edge<CostType>& e : graph[ver]) {\n      if (is_visited[e.dst]\
    \ == 1) {\n        cycle.emplace_back(e);\n        while (cycle.back().src !=\
    \ e.dst) {\n          cycle.emplace_back(edges.back());\n          edges.pop_back();\n\
    \        }\n        std::reverse(cycle.begin(), cycle.end());\n        return\
    \ true;\n      } else if (is_visited[e.dst] == 0) {\n        edges.emplace_back(e);\n\
    \        if (dfs(dfs, e.dst)) return true;\n        edges.pop_back();\n      }\n\
    \    }\n    is_visited[ver] = 2;\n    return false;\n  };\n  for (int i = 0; i\
    \ < n; ++i) {\n    if (is_visited[i] == 0 && dfs(dfs, i)) break;\n  }\n  return\
    \ cycle;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_DETECT_DIRECTED_CYCLE_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/detect_directed_cycle.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/detect_directed_cycle.test.cpp
documentation_of: include/emthrm/graph/detect_directed_cycle.hpp
layout: document
title: "\u6709\u5411\u9589\u8DEF (directed cycle) \u306E\u691C\u51FA"
---

# 歩道 (walk) の検出


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

### 道の検出

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<Edge<CostType>> detect_path(const std::vector<std::vector<Edge<CostType>>>& graph, const int s, const int t);`|有向グラフ $\mathrm{graph}$ における始点 $s$、終点 $t$ の道。ただし存在しないときは空配列を返す。|


### 有向閉路の検出

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<Edge<CostType>> detect_directed_cycle(const std::vector<std::vector<Edge<CostType>>>& graph);`|有向グラフ $\mathrm{graph}$ における閉路。ただし存在しないときは空配列を返す。|


## 参考文献

有向閉路の検出
- https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-6-%E3%82%B5%E3%82%A4%E3%82%AF%E3%83%AB%E6%A4%9C%E5%87%BA


## TODO

- 無向閉路の検出
  - https://judge.yosupo.jp/problem/cycle_detection_undirected
- 閉路の列挙
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/cycle_enumeration.cc


## Submissons

- [道の検出](https://atcoder.jp/contests/past202112-open/submissions/29621513)
- [有向閉路の検出](https://judge.yosupo.jp/submission/15525)
