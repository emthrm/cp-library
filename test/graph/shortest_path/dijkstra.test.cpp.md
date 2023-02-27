---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/shortest_path/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    document_title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra \u6CD5"
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/graph/shortest_path/dijkstra.test.cpp\"\n/*\n * @title\
    \ \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra \u6CD5\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/shortest_path\n */\n\n#include <iostream>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title\
    \ \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <limits>\n#include <queue>\n#include <utility>\n#line 11 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 13 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename CostType>\nstruct Dijkstra {\n  const CostType inf;\n\
    \n  Dijkstra(const std::vector<std::vector<Edge<CostType>>>& graph,\n        \
    \   const CostType inf = std::numeric_limits<CostType>::max())\n      : inf(inf),\
    \ is_built(false), graph(graph) {}\n\n  std::vector<CostType> build(const int\
    \ s) {\n    is_built = true;\n    const int n = graph.size();\n    std::vector<CostType>\
    \ dist(n, inf);\n    dist[s] = 0;\n    prev.assign(n, -1);\n    std::priority_queue<std::pair<CostType,\
    \ int>,\n                        std::vector<std::pair<CostType, int>>,\n    \
    \                    std::greater<std::pair<CostType, int>>> que;\n    que.emplace(0,\
    \ s);\n    while (!que.empty()) {\n      const auto [d, ver] = que.top();\n  \
    \    que.pop();\n      if (d > dist[ver]) continue;\n      for (const Edge<CostType>&\
    \ e : graph[ver]) {\n        if (dist[ver] + e.cost < dist[e.dst]) {\n       \
    \   dist[e.dst] = dist[ver] + e.cost;\n          prev[e.dst] = ver;\n        \
    \  que.emplace(dist[e.dst], e.dst);\n        }\n      }\n    }\n    return dist;\n\
    \  }\n\n  std::vector<int> build_path(int t) const {\n    assert(is_built);\n\
    \    std::vector<int> res;\n    for (; t != -1; t = prev[t]) {\n      res.emplace_back(t);\n\
    \    }\n    std::reverse(res.begin(), res.end());\n    return res;\n  }\n\n private:\n\
    \  bool is_built;\n  std::vector<int> prev;\n  std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n};\n\n}  // namespace emthrm\n\n\n#line 12 \"test/graph/shortest_path/dijkstra.test.cpp\"\
    \n\nint main() {\n  int n, m, s, t;\n  std::cin >> n >> m >> s >> t;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  while (m--) {\n    int a, b, c;\n    std::cin >> a >> b\
    \ >> c;\n    graph[a].emplace_back(a, b, c);\n  }\n  emthrm::Dijkstra<long long>\
    \ dijkstra(graph);\n  const long long x = dijkstra.build(s)[t];\n  if (x == dijkstra.inf)\
    \ {\n    std::cout << \"-1\\n\";\n    return 0;\n  }\n  const std::vector<int>\
    \ path = dijkstra.build_path(t);\n  const int y = path.size() - 1;\n  std::cout\
    \ << x << ' ' << y << '\\n';\n  for (int i = 0; i < y; ++i) {\n    std::cout <<\
    \ path[i] << ' ' << path[i + 1] << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra\
    \ \u6CD5\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/shortest_path\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/shortest_path/dijkstra.hpp\"\n\nint main() {\n  int\
    \ n, m, s, t;\n  std::cin >> n >> m >> s >> t;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  while (m--) {\n    int a, b, c;\n    std::cin >> a >> b\
    \ >> c;\n    graph[a].emplace_back(a, b, c);\n  }\n  emthrm::Dijkstra<long long>\
    \ dijkstra(graph);\n  const long long x = dijkstra.build(s)[t];\n  if (x == dijkstra.inf)\
    \ {\n    std::cout << \"-1\\n\";\n    return 0;\n  }\n  const std::vector<int>\
    \ path = dijkstra.build_path(t);\n  const int y = path.size() - 1;\n  std::cout\
    \ << x << ' ' << y << '\\n';\n  for (int i = 0; i < y; ++i) {\n    std::cout <<\
    \ path[i] << ' ' << path[i + 1] << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/shortest_path/dijkstra.hpp
  isVerificationFile: true
  path: test/graph/shortest_path/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/shortest_path/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path/dijkstra.test.cpp
- /verify/test/graph/shortest_path/dijkstra.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra \u6CD5"
---
