---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/girth_in_directed_graph.hpp
    title: "\u5185\u5468 (girth) \u6709\u5411\u30B0\u30E9\u30D5\u7248"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/girth_in_undirected_graph.hpp
    title: "\u5185\u5468 (girth) \u7121\u5411\u30B0\u30E9\u30D5\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/1320
    document_title: "\u30B0\u30E9\u30D5/\u5185\u5468"
    links:
    - https://yukicoder.me/problems/no/1320
  bundledCode: "#line 1 \"test/graph/girth.test.cpp\"\n/*\n * @title \u30B0\u30E9\u30D5\
    /\u5185\u5468\n *\n * verification-helper: PROBLEM https://yukicoder.me/problems/no/1320\n\
    \ */\n\n#include <iostream>\n#include <limits>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/girth_in_directed_graph.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <functional>\n#line 7 \"include/emthrm/graph/girth_in_directed_graph.hpp\"\
    \n#include <queue>\n#include <utility>\n#line 10 \"include/emthrm/graph/girth_in_directed_graph.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 12 \"include/emthrm/graph/girth_in_directed_graph.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename CostType>\nCostType girth_in_directed_graph(\n    const\
    \ std::vector<std::vector<Edge<CostType>>>& graph,\n    const CostType inf = std::numeric_limits<CostType>::max())\
    \ {\n  const int n = graph.size();\n  CostType res = inf;\n  std::vector<CostType>\
    \ dist(n);\n  std::priority_queue<std::pair<CostType, int>,\n                \
    \      std::vector<std::pair<CostType, int>>,\n                      std::greater<std::pair<CostType,\
    \ int>>> que;\n  for (int root = 0; root < n; ++root) {\n    std::fill(dist.begin(),\
    \ dist.end(), inf);\n    dist[root] = 0;\n    que.emplace(dist[root], root);\n\
    \    while (!que.empty()) {\n      const auto [d, ver] = que.top();\n      que.pop();\n\
    \      if (d > dist[ver]) continue;\n      for (const Edge<CostType>& e : graph[ver])\
    \ {\n        const CostType nxt = dist[ver] + e.cost;\n        if (nxt < dist[e.dst])\
    \ {\n          dist[e.dst] = nxt;\n          que.emplace(nxt, e.dst);\n      \
    \  } else if (e.dst == root) {\n          res = std::min(res, nxt);\n        }\n\
    \      }\n    }\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 1\
    \ \"include/emthrm/graph/girth_in_undirected_graph.hpp\"\n\n\n\n#line 10 \"include/emthrm/graph/girth_in_undirected_graph.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 12 \"include/emthrm/graph/girth_in_undirected_graph.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename CostType>\nCostType girth_in_undirected_graph(\n   \
    \ const int n, const std::vector<Edge<CostType>>& edges,\n    const CostType inf\
    \ = std::numeric_limits<CostType>::max()) {\n  const int m = edges.size();\n \
    \ std::vector<std::vector<int>> graph(n);\n  for (int i = 0; i < m; ++i) {\n \
    \   graph[edges[i].src].emplace_back(i);\n    graph[edges[i].dst].emplace_back(i);\n\
    \  }\n  std::vector<bool> is_used(m, false);\n  std::vector<int> label(n), prev(n);\n\
    \  std::vector<CostType> dist(n);\n  std::priority_queue<std::pair<CostType, int>,\n\
    \                      std::vector<std::pair<CostType, int>>,\n              \
    \        std::greater<std::pair<CostType, int>>> que;\n  CostType res = inf;\n\
    \  for (int root = 0; root < n; ++root) {\n    std::fill(is_used.begin(), is_used.end(),\
    \ false);\n    std::fill(label.begin(), label.end(), -2);\n    label[root] = -1;\n\
    \    std::fill(prev.begin(), prev.end(), -1);\n    std::fill(dist.begin(), dist.end(),\
    \ inf);\n    dist[root] = 0;\n    que.emplace(0, root);\n    while (!que.empty())\
    \ {\n      const auto [d, ver] = que.top();\n      que.pop();\n      if (d > dist[ver])\
    \ continue;\n      for (const int id : graph[ver]) {\n        const int dst =\
    \ (edges[id].src == ver ? edges[id].dst : edges[id].src);\n        const CostType\
    \ nxt = dist[ver] + edges[id].cost;\n        if (nxt < dist[dst]) {\n        \
    \  dist[dst] = nxt;\n          label[dst] = (label[ver] == -1 ? dst : label[ver]);\n\
    \          if (prev[dst] != -1) is_used[dst] = true;\n          is_used[id] =\
    \ true;\n          que.emplace(nxt, dst);\n        }\n      }\n    }\n    for\
    \ (int i = 0; i < m; ++i) {\n      const int src = edges[i].src, dst = edges[i].dst;\n\
    \      if (!is_used[i] && label[src] != -2 && label[dst] != -2) {\n        if\
    \ (label[src] != label[dst]) {\n          res = std::min(res, dist[src] + dist[dst]\
    \ + edges[i].cost);\n        } else if (label[src] == -1) {\n          res = std::min(res,\
    \ edges[i].cost);\n        }\n      }\n    }\n  }\n  return res;\n}\n\n}  // namespace\
    \ emthrm\n\n\n#line 14 \"test/graph/girth.test.cpp\"\n\nint main() {\n  constexpr\
    \ long long LINF = std::numeric_limits<long long>::max();\n  int t, n, m;\n  std::cin\
    \ >> t >> n >> m;\n  if (t == 0) {\n    std::vector<emthrm::Edge<long long>> edges;\n\
    \    while (m--) {\n      int u, v, w;\n      std::cin >> u >> v >> w;\n     \
    \ --u; --v;\n      edges.emplace_back(u, v, w);\n    }\n    const long long ans\
    \ = emthrm::girth_in_undirected_graph(n, edges, LINF);\n    std::cout << (ans\
    \ == LINF ? -1 : ans) << '\\n';\n  } else if (t == 1) {\n    std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n    while (m--) {\n      int u, v, w;\n      std::cin >>\
    \ u >> v >> w;\n      --u; --v;\n      graph[u].emplace_back(u, v, w);\n    }\n\
    \    const long long ans = emthrm::girth_in_directed_graph(graph, LINF);\n   \
    \ std::cout << (ans == LINF ? -1 : ans) << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u5185\u5468\n *\n * verification-helper:\
    \ PROBLEM https://yukicoder.me/problems/no/1320\n */\n\n#include <iostream>\n\
    #include <limits>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n#include\
    \ \"emthrm/graph/girth_in_directed_graph.hpp\"\n#include \"emthrm/graph/girth_in_undirected_graph.hpp\"\
    \n\nint main() {\n  constexpr long long LINF = std::numeric_limits<long long>::max();\n\
    \  int t, n, m;\n  std::cin >> t >> n >> m;\n  if (t == 0) {\n    std::vector<emthrm::Edge<long\
    \ long>> edges;\n    while (m--) {\n      int u, v, w;\n      std::cin >> u >>\
    \ v >> w;\n      --u; --v;\n      edges.emplace_back(u, v, w);\n    }\n    const\
    \ long long ans = emthrm::girth_in_undirected_graph(n, edges, LINF);\n    std::cout\
    \ << (ans == LINF ? -1 : ans) << '\\n';\n  } else if (t == 1) {\n    std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n    while (m--) {\n      int u, v, w;\n      std::cin >>\
    \ u >> v >> w;\n      --u; --v;\n      graph[u].emplace_back(u, v, w);\n    }\n\
    \    const long long ans = emthrm::girth_in_directed_graph(graph, LINF);\n   \
    \ std::cout << (ans == LINF ? -1 : ans) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/girth_in_directed_graph.hpp
  - include/emthrm/graph/girth_in_undirected_graph.hpp
  isVerificationFile: true
  path: test/graph/girth.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/girth.test.cpp
layout: document
redirect_from:
- /verify/test/graph/girth.test.cpp
- /verify/test/graph/girth.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5185\u5468"
---
