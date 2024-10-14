---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/union-find/union-find.hpp
    title: union-find
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/connencted_component_of_complement_graph.hpp
    title: "\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/connected_components_of_complement_graph
    document_title: "\u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\
      \u6210\u5206\u5206\u89E3"
    links:
    - https://judge.yosupo.jp/problem/connected_components_of_complement_graph
  bundledCode: "#line 1 \"test/graph/connencted_component_of_complement_graph.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/connected_components_of_complement_graph\n\
    \ */\n\n#include <iostream>\n#include <ranges>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/data_structure/union-find/union-find.hpp\"\n\n\n\n#include <utility>\n\
    #line 6 \"include/emthrm/data_structure/union-find/union-find.hpp\"\n\nnamespace\
    \ emthrm {\n\nstruct UnionFind {\n  explicit UnionFind(const int n) : data(n,\
    \ -1) {}\n\n  int root(const int ver) {\n    return data[ver] < 0 ? ver : data[ver]\
    \ = root(data[ver]);\n  }\n\n  bool unite(int u, int v) {\n    u = root(u);\n\
    \    v = root(v);\n    if (u == v) return false;\n    if (data[u] > data[v]) std::swap(u,\
    \ v);\n    data[u] += data[v];\n    data[v] = u;\n    return true;\n  }\n\n  bool\
    \ is_same(const int u, const int v) { return root(u) == root(v); }\n\n  int size(const\
    \ int ver) { return -data[root(ver)]; }\n\n private:\n  std::vector<int> data;\n\
    };\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n\
    /**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/connencted_component_of_complement_graph.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/graph/connencted_component_of_complement_graph.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 9 \"include/emthrm/graph/connencted_component_of_complement_graph.hpp\"\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nUnionFind connencted_component_of_complement_graph(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n =\
    \ graph.size();\n  UnionFind union_find(n);\n  const auto check = [&graph, n,\
    \ &union_find](const int ver) -> void {\n    std::vector<bool> is_adjacent(n,\
    \ false);\n    for (const int e : graph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      is_adjacent[e] = true;\n    }\n    for (int i = 0; i < n; ++i) {\n\
    \      if (!is_adjacent[i]) union_find.unite(ver, i);\n    }\n  };\n  int argmin_deg\
    \ = 0;\n  for (int i = 1; i < n; ++i) {\n    if (graph[i].size() < graph[argmin_deg].size())\
    \ argmin_deg = i;\n  }\n  check(argmin_deg);\n  for (const int e : graph[argmin_deg]\n\
    \                   | std::views::transform(&Edge<CostType>::dst)) {\n    check(e);\n\
    \  }\n  return union_find;\n}\n\n}  // namespace emthrm\n\n\n#line 14 \"test/graph/connencted_component_of_complement_graph.test.cpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n    graph[a].emplace_back(a,\
    \ b);\n    graph[b].emplace_back(b, a);\n  }\n  emthrm::UnionFind union_find =\n\
    \      emthrm::connencted_component_of_complement_graph(graph);\n  int k = 0;\n\
    \  std::vector<std::vector<int>> v(n);\n  for (const int i : std::views::iota(0,\
    \ n)) {\n    v[union_find.root(i)].emplace_back(i);\n    if (union_find.root(i)\
    \ == i) ++k;\n  }\n  std::cout << k << '\\n';\n  for (const std::vector<int>&\
    \ v_i : v) {\n    if (v_i.empty()) continue;\n    std::cout << v_i.size();\n \
    \   for (const int v_ij : v_i) std::cout << ' ' << v_ij;\n    std::cout << '\\\
    n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\
    \u6210\u5206\u5206\u89E3\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/connected_components_of_complement_graph\n\
    \ */\n\n#include <iostream>\n#include <ranges>\n#include <vector>\n\n#include\
    \ \"emthrm/data_structure/union-find/union-find.hpp\"\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/connencted_component_of_complement_graph.hpp\"\n\nint\
    \ main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n    graph[a].emplace_back(a,\
    \ b);\n    graph[b].emplace_back(b, a);\n  }\n  emthrm::UnionFind union_find =\n\
    \      emthrm::connencted_component_of_complement_graph(graph);\n  int k = 0;\n\
    \  std::vector<std::vector<int>> v(n);\n  for (const int i : std::views::iota(0,\
    \ n)) {\n    v[union_find.root(i)].emplace_back(i);\n    if (union_find.root(i)\
    \ == i) ++k;\n  }\n  std::cout << k << '\\n';\n  for (const std::vector<int>&\
    \ v_i : v) {\n    if (v_i.empty()) continue;\n    std::cout << v_i.size();\n \
    \   for (const int v_ij : v_i) std::cout << ' ' << v_ij;\n    std::cout << '\\\
    n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/union-find/union-find.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/connencted_component_of_complement_graph.hpp
  isVerificationFile: true
  path: test/graph/connencted_component_of_complement_graph.test.cpp
  requiredBy: []
  timestamp: '2024-05-23 20:00:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/connencted_component_of_complement_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/connencted_component_of_complement_graph.test.cpp
- /verify/test/graph/connencted_component_of_complement_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\
  \u89E3"
---
