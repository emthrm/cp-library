---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/centroid.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/tree/centroid.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <ranges>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 9 \"include/emthrm/graph/tree/centroid.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<int> centroid(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n =\
    \ graph.size();\n  std::vector<int> subtree(n, 1), res;\n  const auto dfs = [&graph,\
    \ n, &subtree, &res](\n      auto dfs, const int par, const int ver) -> void {\n\
    \    bool is_centroid = true;\n    for (const int e : graph[ver]\n           \
    \          | std::views::transform(&Edge<CostType>::dst)) {\n      if (e != par)\
    \ {\n        dfs(dfs, ver, e);\n        subtree[ver] += subtree[e];\n        is_centroid\
    \ &= subtree[e] <= n / 2;\n      }\n    }\n    if (is_centroid && n - subtree[ver]\
    \ <= n / 2) res.emplace_back(ver);\n  };\n  dfs(dfs, -1, 0);\n  std::sort(res.begin(),\
    \ res.end());\n  return res;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_TREE_CENTROID_HPP_\n#define EMTHRM_GRAPH_TREE_CENTROID_HPP_\n\
    \n#include <algorithm>\n#include <ranges>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<int> centroid(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n =\
    \ graph.size();\n  std::vector<int> subtree(n, 1), res;\n  const auto dfs = [&graph,\
    \ n, &subtree, &res](\n      auto dfs, const int par, const int ver) -> void {\n\
    \    bool is_centroid = true;\n    for (const int e : graph[ver]\n           \
    \          | std::views::transform(&Edge<CostType>::dst)) {\n      if (e != par)\
    \ {\n        dfs(dfs, ver, e);\n        subtree[ver] += subtree[e];\n        is_centroid\
    \ &= subtree[e] <= n / 2;\n      }\n    }\n    if (is_centroid && n - subtree[ver]\
    \ <= n / 2) res.emplace_back(ver);\n  };\n  dfs(dfs, -1, 0);\n  std::sort(res.begin(),\
    \ res.end());\n  return res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_TREE_CENTROID_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/tree/centroid.hpp
  requiredBy: []
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/centroid.test.cpp
documentation_of: include/emthrm/graph/tree/centroid.hpp
layout: document
title: "\u91CD\u5FC3 (centroid)"
---

根としたときに任意の子の部分木の大きさが木の大きさの半分以下となる頂点である。

任意の木に必ず存在し、高々二つである。二つ存在するとき、木の頂点数は偶数である。


## 時間計算量

$O(\lvert V \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<int> centroid(const std::vector<std::vector<Edge<CostType>>>& graph);`|木 $\mathrm{graph}$ の重心|


## 参考文献

- Camille Jordan: Sur les assemblages de lignes, *Journal für die reine und angewandte Mathematik*, Vol. 70, pp. 185–190 (1869). https://doi.org/10.1515/crll.1869.70.185
- https://qiita.com/drken/items/4b4c3f1824339b090202
- ~~https://lumakernel.github.io/ecasdqina/graph/Centroid~~
- https://img.atcoder.jp/arc087/editorial.pdf


## Submissons

https://atcoder.jp/contests/arc087/submissions/9306188
