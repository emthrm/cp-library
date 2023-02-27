---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/prim.hpp
    title: "Prim \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    document_title: "\u30B0\u30E9\u30D5/Prim \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/graph/prim.test.cpp\"\n/*\n * @title \u30B0\u30E9\u30D5\
    /Prim \u6CD5\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/prim.hpp\"\
    \n\n\n\n#include <functional>\n#include <queue>\n#line 7 \"include/emthrm/graph/prim.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 9 \"include/emthrm/graph/prim.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename\
    \ CostType>\nCostType prim(const std::vector<std::vector<Edge<CostType>>>& graph,\n\
    \              const int root = 0) {\n  const int n = graph.size();\n  CostType\
    \ res = 0;\n  std::vector<bool> is_visited(n, false);\n  is_visited[root] = true;\n\
    \  std::priority_queue<Edge<CostType>,\n                      std::vector<Edge<CostType>>,\n\
    \                      std::greater<Edge<CostType>>> que;\n  for (const Edge<CostType>&\
    \ e : graph[root]) {\n    if (e.dst != root) que.emplace(e);\n  }\n  while (!que.empty())\
    \ {\n    const Edge<CostType> e1 = que.top();\n    que.pop();\n    if (is_visited[e1.dst])\
    \ continue;\n    is_visited[e1.dst] = true;\n    res += e1.cost;\n    for (const\
    \ Edge<CostType>& e2 : graph[e1.dst]) {\n      if (!is_visited[e2.dst]) que.emplace(e2);\n\
    \    }\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 12 \"test/graph/prim.test.cpp\"\
    \n\nint main() {\n  int v, e;\n  std::cin >> v >> e;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> edge(v);\n  while (e--) {\n    int s, t, w;\n    std::cin >> s >> t\
    \ >> w;\n    edge[s].emplace_back(s, t, w);\n    edge[t].emplace_back(t, s, w);\n\
    \  }\n  std::cout << emthrm::prim(edge) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/Prim \u6CD5\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\n */\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/prim.hpp\"\n\nint main() {\n  int v, e;\n  std::cin\
    \ >> v >> e;\n  std::vector<std::vector<emthrm::Edge<long long>>> edge(v);\n \
    \ while (e--) {\n    int s, t, w;\n    std::cin >> s >> t >> w;\n    edge[s].emplace_back(s,\
    \ t, w);\n    edge[t].emplace_back(t, s, w);\n  }\n  std::cout << emthrm::prim(edge)\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/prim.hpp
  isVerificationFile: true
  path: test/graph/prim.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/prim.test.cpp
layout: document
redirect_from:
- /verify/test/graph/prim.test.cpp
- /verify/test/graph/prim.test.cpp.html
title: "\u30B0\u30E9\u30D5/Prim \u6CD5"
---
