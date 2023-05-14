---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/2-edge-connected_components_by_imos.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206 (2-edge-connected component)\
      \ \u5206\u89E3 \u3044\u3082\u3059\u6CD5\u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/2-edge-connected_components_by_imos.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ \u3044\u3082\u3059\u6CD5\u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/enumerate_bridges.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6A4B\u306E\u5217\u6319"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/enumerate_bridges.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n\
    /**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
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
    \  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_ENUMERATE_BRIDGES_HPP_\n#define EMTHRM_GRAPH_ENUMERATE_BRIDGES_HPP_\n\
    \n#include <algorithm>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
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
    \  }\n  return res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_ENUMERATE_BRIDGES_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/enumerate_bridges.hpp
  requiredBy:
  - include/emthrm/graph/2-edge-connected_components_by_imos.hpp
  timestamp: '2023-02-24 21:17:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/2-edge-connected_components_by_imos.test.cpp
  - test/graph/enumerate_bridges.test.cpp
documentation_of: include/emthrm/graph/enumerate_bridges.hpp
layout: document
title: "\u6A4B\u306E\u691C\u51FA"
---


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<Edge<CostType>> enumerate_bridges(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ の橋|


## 参考文献

- https://www.slideshare.net/chokudai/arc039


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_B/review/4082847/emthrm/C++14
