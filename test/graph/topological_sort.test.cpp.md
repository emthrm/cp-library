---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/topological_sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 (topological sort)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    document_title: "\u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
      \u30FC\u30C8"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "#line 1 \"test/graph/topological_sort.test.cpp\"\n/*\n * @title \u30B0\
    \u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/topological_sort.hpp\"\
    \n\n\n\n#include <queue>\n#include <ranges>\n#include <utility>\n#line 8 \"include/emthrm/graph/topological_sort.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 10 \"include/emthrm/graph/topological_sort.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <typename CostType>\nstd::vector<int> topological_sort(\n    const\
    \ std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n = graph.size();\n\
    \  std::vector<int> deg(n, 0);\n  for (const int e : graph\n                 \
    \  | std::views::join\n                   | std::views::transform(&Edge<CostType>::dst))\
    \ {\n    ++deg[e];\n  }\n  std::queue<int> que;\n  for (int i = 0; i < n; ++i)\
    \ {\n    if (deg[i] == 0) que.emplace(i);\n  }\n  std::vector<int> res;\n  res.reserve(n);\n\
    \  while (!que.empty()) {\n    const int ver = que.front();\n    que.pop();\n\
    \    res.emplace_back(ver);\n    for (const int e : graph[ver]\n             \
    \        | std::views::transform(&Edge<CostType>::dst)) {\n      if (--deg[e]\
    \ == 0) que.emplace(e);\n    }\n  }\n  return std::cmp_equal(res.size(), n) ?\
    \ res : std::vector<int>{};\n}\n\n}  // namespace emthrm\n\n\n#line 13 \"test/graph/topological_sort.test.cpp\"\
    \n\nint main() {\n  int v, e;\n  std::cin >> v >> e;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(v);\n  while (e--) {\n    int s, t;\n    std::cin >> s >> t;\n    graph[s].emplace_back(s,\
    \ t);\n  }\n  for (const int ans : emthrm::topological_sort(graph)) {\n    std::cout\
    \ << ans << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8\n *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\n */\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n#include\
    \ \"emthrm/graph/topological_sort.hpp\"\n\nint main() {\n  int v, e;\n  std::cin\
    \ >> v >> e;\n  std::vector<std::vector<emthrm::Edge<bool>>> graph(v);\n  while\
    \ (e--) {\n    int s, t;\n    std::cin >> s >> t;\n    graph[s].emplace_back(s,\
    \ t);\n  }\n  for (const int ans : emthrm::topological_sort(graph)) {\n    std::cout\
    \ << ans << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/topological_sort.hpp
  isVerificationFile: true
  path: test/graph/topological_sort.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/graph/topological_sort.test.cpp
layout: document
redirect_from:
- /verify/test/graph/topological_sort.test.cpp
- /verify/test/graph/topological_sort.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---
