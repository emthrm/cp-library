---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/minimum_steiner_tree.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <functional>\n#include <limits>\n#include <queue>\n\
    #include <ranges>\n#include <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 13 \"include/emthrm/graph/minimum_steiner_tree.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nCostType minimum_steiner_tree(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph,\n    std::vector<int>\
    \ terminals) {\n  if (terminals.empty()) [[unlikely]] return 0;\n  const CostType\
    \ inf = std::numeric_limits<CostType>::max();\n  const int n = graph.size();\n\
    \  std::ranges::sort(terminals);\n  terminals.erase(\n      std::unique(terminals.begin(),\
    \ terminals.end()), terminals.end());\n  const int m = terminals.size();\n  if\
    \ (m == 1) [[unlikely]] return 0;\n  std::vector dp(1 << (m - 1), std::vector(n,\
    \ inf));\n  for (const int i : std::views::iota(0, m - 1)) {\n    dp[1 << i][terminals[i]]\
    \ = 0;\n  }\n  std::priority_queue<std::pair<CostType, int>,\n               \
    \       std::vector<std::pair<CostType, int>>,\n                      std::greater<std::pair<CostType,\
    \ int>>> que;\n  for (const int bit : std::views::iota(1, 1 << (m - 1))) {\n \
    \   for (const int i : std::views::iota(0, n)) {\n      for (int sub = bit; sub\
    \ > 0; sub = (sub - 1) & bit) {\n        if (dp[sub][i] == inf || dp[bit ^ sub][i]\
    \ == inf) continue;\n        dp[bit][i] = std::min(dp[bit][i], dp[sub][i] + dp[bit\
    \ ^ sub][i]);\n      }\n    }\n    for (const int i : std::views::iota(0, n))\
    \ {\n      if (dp[bit][i] != inf) que.emplace(dp[bit][i], i);\n    }\n    while\
    \ (!que.empty()) {\n      const auto [cur_cost, vertex] = que.top();\n      que.pop();\n\
    \      if (cur_cost > dp[bit][vertex]) continue;\n      for (const Edge<CostType>&\
    \ e : graph[vertex]) {\n        if (const CostType tmp = dp[bit][vertex] + e.cost;\n\
    \            tmp < dp[bit][e.dst]) {\n          dp[bit][e.dst] = tmp;\n      \
    \    que.emplace(dp[bit][e.dst], e.dst);\n        }\n      }\n    }\n  }\n  return\
    \ dp.back()[terminals.back()];\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_MINIMUM_STEINER_TREE_HPP_\n#define EMTHRM_GRAPH_MINIMUM_STEINER_TREE_HPP_\n\
    \n#include <algorithm>\n#include <functional>\n#include <limits>\n#include <queue>\n\
    #include <ranges>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nCostType minimum_steiner_tree(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph,\n    std::vector<int>\
    \ terminals) {\n  if (terminals.empty()) [[unlikely]] return 0;\n  const CostType\
    \ inf = std::numeric_limits<CostType>::max();\n  const int n = graph.size();\n\
    \  std::ranges::sort(terminals);\n  terminals.erase(\n      std::unique(terminals.begin(),\
    \ terminals.end()), terminals.end());\n  const int m = terminals.size();\n  if\
    \ (m == 1) [[unlikely]] return 0;\n  std::vector dp(1 << (m - 1), std::vector(n,\
    \ inf));\n  for (const int i : std::views::iota(0, m - 1)) {\n    dp[1 << i][terminals[i]]\
    \ = 0;\n  }\n  std::priority_queue<std::pair<CostType, int>,\n               \
    \       std::vector<std::pair<CostType, int>>,\n                      std::greater<std::pair<CostType,\
    \ int>>> que;\n  for (const int bit : std::views::iota(1, 1 << (m - 1))) {\n \
    \   for (const int i : std::views::iota(0, n)) {\n      for (int sub = bit; sub\
    \ > 0; sub = (sub - 1) & bit) {\n        if (dp[sub][i] == inf || dp[bit ^ sub][i]\
    \ == inf) continue;\n        dp[bit][i] = std::min(dp[bit][i], dp[sub][i] + dp[bit\
    \ ^ sub][i]);\n      }\n    }\n    for (const int i : std::views::iota(0, n))\
    \ {\n      if (dp[bit][i] != inf) que.emplace(dp[bit][i], i);\n    }\n    while\
    \ (!que.empty()) {\n      const auto [cur_cost, vertex] = que.top();\n      que.pop();\n\
    \      if (cur_cost > dp[bit][vertex]) continue;\n      for (const Edge<CostType>&\
    \ e : graph[vertex]) {\n        if (const CostType tmp = dp[bit][vertex] + e.cost;\n\
    \            tmp < dp[bit][e.dst]) {\n          dp[bit][e.dst] = tmp;\n      \
    \    que.emplace(dp[bit][e.dst], e.dst);\n        }\n      }\n    }\n  }\n  return\
    \ dp.back()[terminals.back()];\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_MINIMUM_STEINER_TREE_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/minimum_steiner_tree.hpp
  requiredBy: []
  timestamp: '2024-07-28 17:15:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/graph/minimum_steiner_tree.hpp
layout: document
title: "\u6700\u5C0F\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\u6728 (minimum Steiner tree)"
---


## 時間計算量

ターミナルの数を $T$ とおくと $O(3^T \lvert V \rvert + 2^T \lvert E \rvert \log{\lvert E \rvert})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`CostType minimum_steiner_tree(const std::vector<std::vector<Edge<CostType>>>& graph, std::vector<int> terminals);`|無向グラフ $\mathrm{graph}$ の最小シュタイナー木におけるコスト|


## 参考文献

- https://www.slideshare.net/wata_orz/ss-12131479


## Submissons

https://atcoder.jp/contests/abc364/submissions/56083584
