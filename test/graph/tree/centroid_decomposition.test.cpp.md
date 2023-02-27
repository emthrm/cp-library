---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/tree/centroid_decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3 (centroid decompositon)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/abc291/tasks/abc291_h
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
    links:
    - https://atcoder.jp/contests/abc291/tasks/abc291_h
  bundledCode: "#line 1 \"test/graph/tree/centroid_decomposition.test.cpp\"\n/*\n\
    \ * @title \u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_h\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/tree/centroid_decomposition.hpp\"\
    \n\n\n\n#include <ranges>\n#line 6 \"include/emthrm/graph/tree/centroid_decomposition.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 8 \"include/emthrm/graph/tree/centroid_decomposition.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename CostType>\nstruct CentroidDecomposition {\n \
    \ int root;\n  std::vector<int> parent;\n  std::vector<std::vector<int>> g;\n\n\
    \  explicit CentroidDecomposition(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : graph(graph) {\n    const int n = graph.size();\n    parent.assign(n,\
    \ -1);\n    g.resize(n);\n    is_alive.assign(n, true);\n    subtree.resize(n);\n\
    \    root = build(0);\n  }\n\n private:\n  std::vector<bool> is_alive;\n  std::vector<int>\
    \ subtree;\n  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  int build(const\
    \ int s) {\n    const int centroid = search_centroid(-1, s, calc_subtree(-1, s)\
    \ / 2);\n    is_alive[centroid] = false;\n    for (const int e : graph[centroid]\n\
    \                     | std::views::transform(&Edge<CostType>::dst)) {\n     \
    \ if (is_alive[e]) {\n        const int child = build(e);\n        g[centroid].emplace_back(child);\n\
    \        parent[child] = centroid;\n      }\n    }\n    is_alive[centroid] = true;\n\
    \    return centroid;\n  }\n\n  int calc_subtree(const int par, const int ver)\
    \ {\n    subtree[ver] = 1;\n    for (const int e : graph[ver]\n              \
    \       | std::views::transform(&Edge<CostType>::dst)) {\n      if (e != par &&\
    \ is_alive[e]) {\n        subtree[ver] += calc_subtree(ver, e);\n      }\n   \
    \ }\n    return subtree[ver];\n  }\n\n  int search_centroid(const int par, const\
    \ int ver, const int half) const {\n    for (const int e : graph[ver]\n      \
    \               | std::views::transform(&Edge<CostType>::dst)) {\n      if (e\
    \ != par && is_alive[e] && subtree[e] > half) {\n        return search_centroid(ver,\
    \ e, half);\n      }\n    }\n    return ver;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 13 \"test/graph/tree/centroid_decomposition.test.cpp\"\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    --a; --b;\n    graph[a].emplace_back(a, b);\n    graph[b].emplace_back(b,\
    \ a);\n  }\n  const std::vector<int> p = emthrm::CentroidDecomposition(graph).parent;\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cout << (p[i] == -1 ? -1 : p[i] + 1)\
    \ << \" \\n\"[i + 1 == n];\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3\n *\n *\
    \ verification-helper: IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_h\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/tree/centroid_decomposition.hpp\"\n\nint main() {\n\
    \  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);\n\
    \  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin >> a >> b;\n\
    \    --a; --b;\n    graph[a].emplace_back(a, b);\n    graph[b].emplace_back(b,\
    \ a);\n  }\n  const std::vector<int> p = emthrm::CentroidDecomposition(graph).parent;\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cout << (p[i] == -1 ? -1 : p[i] + 1)\
    \ << \" \\n\"[i + 1 == n];\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/centroid_decomposition.hpp
  isVerificationFile: true
  path: test/graph/tree/centroid_decomposition.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 17:26:42+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/graph/tree/centroid_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/centroid_decomposition.test.cpp
- /verify/test/graph/tree/centroid_decomposition.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
---
