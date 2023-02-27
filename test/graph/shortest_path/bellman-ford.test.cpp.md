---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/shortest_path/bellman-ford.hpp
    title: "Bellman\u2013Ford \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    document_title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman\u2013\
      Ford \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/graph/shortest_path/bellman-ford.test.cpp\"\n/*\n *\
    \ @title \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman\u2013Ford \u6CD5\
    \n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/shortest_path/bellman-ford.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#line 8 \"\
    include/emthrm/graph/shortest_path/bellman-ford.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 10 \"include/emthrm/graph/shortest_path/bellman-ford.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct BellmanFord {\n\
    \  const CostType inf;\n  std::vector<CostType> dist;\n\n  BellmanFord(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n              const CostType inf = std::numeric_limits<CostType>::max())\n\
    \      : inf(inf), is_built(false), graph(graph) {}\n\n  bool has_negative_cycle(const\
    \ int s) {\n    is_built = true;\n    const int n = graph.size();\n    dist.assign(n,\
    \ inf);\n    dist[s] = 0;\n    prev.assign(n, -1);\n    for (int step = 0; step\
    \ < n; ++step) {\n      bool is_updated = false;\n      for (int i = 0; i < n;\
    \ ++i) {\n        if (dist[i] == inf) continue;\n        for (const Edge<CostType>&\
    \ e : graph[i]) {\n          if (dist[e.dst] > dist[i] + e.cost) {\n         \
    \   dist[e.dst] = dist[i] + e.cost;\n            prev[e.dst] = i;\n          \
    \  is_updated = true;\n          }\n        }\n      }\n      if (!is_updated)\
    \ return false;\n    }\n    return true;\n  }\n\n  std::vector<int> build_path(int\
    \ t) const {\n    assert(is_built);\n    std::vector<int> res;\n    for (; t !=\
    \ -1; t = prev[t]) {\n      res.emplace_back(t);\n    }\n    std::reverse(res.begin(),\
    \ res.end());\n    return res;\n  }\n\n private:\n  bool is_built;\n  std::vector<int>\
    \ prev;\n  std::vector<std::vector<Edge<CostType>>> graph;\n};\n\n}  // namespace\
    \ emthrm\n\n\n#line 12 \"test/graph/shortest_path/bellman-ford.test.cpp\"\n\n\
    int main() {\n  int v, e, r;\n  std::cin >> v >> e >> r;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(v);\n  while (e--) {\n    int s, t, d;\n    std::cin >> s >> t\
    \ >> d;\n    graph[s].emplace_back(s, t, d);\n  }\n  emthrm::BellmanFord<long\
    \ long> bellman_ford(graph);\n  if (bellman_ford.has_negative_cycle(r)) {\n  \
    \  std::cout << \"NEGATIVE CYCLE\\n\";\n    return 0;\n  }\n  for (int i = 0;\
    \ i < v; ++i) {\n    if (bellman_ford.dist[i] == bellman_ford.inf) {\n      std::cout\
    \ << \"INF\\n\";\n    } else {\n      std::cout << bellman_ford.dist[i] << '\\\
    n';\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman\u2013\
    Ford \u6CD5\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/shortest_path/bellman-ford.hpp\"\n\nint main() {\n \
    \ int v, e, r;\n  std::cin >> v >> e >> r;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(v);\n  while (e--) {\n    int s, t, d;\n    std::cin >> s >> t\
    \ >> d;\n    graph[s].emplace_back(s, t, d);\n  }\n  emthrm::BellmanFord<long\
    \ long> bellman_ford(graph);\n  if (bellman_ford.has_negative_cycle(r)) {\n  \
    \  std::cout << \"NEGATIVE CYCLE\\n\";\n    return 0;\n  }\n  for (int i = 0;\
    \ i < v; ++i) {\n    if (bellman_ford.dist[i] == bellman_ford.inf) {\n      std::cout\
    \ << \"INF\\n\";\n    } else {\n      std::cout << bellman_ford.dist[i] << '\\\
    n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/shortest_path/bellman-ford.hpp
  isVerificationFile: true
  path: test/graph/shortest_path/bellman-ford.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/shortest_path/bellman-ford.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path/bellman-ford.test.cpp
- /verify/test/graph/shortest_path/bellman-ford.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman\u2013Ford \u6CD5"
---
