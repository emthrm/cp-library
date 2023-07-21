---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/is_bipartite.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/is_bipartite.hpp\"\n\n\n\n#include\
    \ <ranges>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n\
    \ * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 8 \"include/emthrm/graph/is_bipartite.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<int> is_bipartite(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n =\
    \ graph.size();\n  std::vector<int> color(n, -1);\n  const auto dfs = [&graph,\
    \ &color](auto dfs, const int ver, const int c)\n      -> bool {\n    color[ver]\
    \ = c;\n    for (const int e : graph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (color[e] == c || (color[e] == -1 && !dfs(dfs, e, c ^ 1))) {\n \
    \       return false;\n      }\n    }\n    return true;\n  };\n  for (int i =\
    \ 0; i < n; ++i) {\n    if (color[i] == -1 && !dfs(dfs, i, 0)) return std::vector<int>{};\n\
    \  }\n  return color;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_IS_BIPARTITE_HPP_\n#define EMTHRM_GRAPH_IS_BIPARTITE_HPP_\n\
    \n#include <ranges>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<int> is_bipartite(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n =\
    \ graph.size();\n  std::vector<int> color(n, -1);\n  const auto dfs = [&graph,\
    \ &color](auto dfs, const int ver, const int c)\n      -> bool {\n    color[ver]\
    \ = c;\n    for (const int e : graph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (color[e] == c || (color[e] == -1 && !dfs(dfs, e, c ^ 1))) {\n \
    \       return false;\n      }\n    }\n    return true;\n  };\n  for (int i =\
    \ 0; i < n; ++i) {\n    if (color[i] == -1 && !dfs(dfs, i, 0)) return std::vector<int>{};\n\
    \  }\n  return color;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_IS_BIPARTITE_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/is_bipartite.hpp
  requiredBy: []
  timestamp: '2023-02-24 21:17:22+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/is_bipartite.test.cpp
documentation_of: include/emthrm/graph/is_bipartite.hpp
layout: document
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5 (bipartite graph) \u5224\u5B9A"
---


### 二部グラフ (bipartite graph)

- 各部分集合内の頂点間で辺が存在しないように、頂点集合を二つの部分集合に分割できるグラフである。
- [彩色数](chromatic_number.md) $2$ のグラフである。
- 奇数長の閉路を含まないグラフである。

これらはすべて同値である。


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

|名前|戻り値|備考|
|:--|:--|:--|
|`template <typename CostType>`<br>`std::vector<int> is_bipartite(const std::vector<std::vector<Edge<CostType>>>& graph);`|隣接する頂点の色が同じにならないよう、無向グラフ $\mathrm{graph}$ を $2$ 色に塗り分けたときの各頂点の色。ただし二部グラフでなければ空配列を返す。|色は $0$ または $1$ で表す。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.93-94，マイナビ出版（2012）


## Submissons

https://atcoder.jp/contests/arc099/submissions/26050245
