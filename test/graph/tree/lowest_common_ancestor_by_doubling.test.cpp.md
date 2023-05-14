---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (lowest common ancestor) \u30C0\u30D6\
      \u30EA\u30F3\u30B0\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148\
      \ \u30C0\u30D6\u30EA\u30F3\u30B0\u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u7248\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp\"\
    \n\n\n\n#include <bit>\n#include <cassert>\n#include <utility>\n#line 8 \"include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 10 \"include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp\"\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct LowestCommonAncestorByDoubling\
    \ {\n  std::vector<int> depth;\n  std::vector<CostType> dist;\n\n  explicit LowestCommonAncestorByDoubling(\n\
    \      const std::vector<std::vector<Edge<CostType>>>& graph)\n      : is_built(false),\
    \ n(graph.size()),\n        table_h(std::countr_zero(std::bit_floor(graph.size()))\
    \ + 1),\n        graph(graph) {\n    assert(n > 0);\n    depth.resize(n);\n  \
    \  dist.resize(n);\n    parent.resize(table_h, std::vector<int>(n));\n  }\n\n\
    \  void build(const int root = 0) {\n    is_built = true;\n    dfs(-1, root, 0,\
    \ 0);\n    for (int i = 0; i + 1 < table_h; ++i) {\n      for (int ver = 0; ver\
    \ < n; ++ver) {\n        parent[i + 1][ver] =\n            (parent[i][ver] ==\
    \ -1 ? -1 : parent[i][parent[i][ver]]);\n      }\n    }\n  }\n\n  int query(int\
    \ u, int v) const {\n    assert(is_built);\n    if (depth[u] > depth[v]) std::swap(u,\
    \ v);\n    for (int i = 0; i < table_h; ++i) {\n      if ((depth[v] - depth[u])\
    \ >> i & 1) v = parent[i][v];\n    }\n    if (u == v) return u;\n    for (int\
    \ i = table_h - 1; i >= 0; --i) {\n      if (parent[i][u] != parent[i][v]) {\n\
    \        u = parent[i][u];\n        v = parent[i][v];\n      }\n    }\n    return\
    \ parent.front()[u];\n  }\n\n  CostType distance(const int u, const int v) const\
    \ {\n    assert(is_built);\n    return dist[u] + dist[v] - dist[query(u, v)] *\
    \ 2;\n  }\n\n  int level_ancestor(int v, const int d) const {\n    assert(is_built);\n\
    \    if (depth[v] < d) return -1;\n    for (int i = depth[v] - d, bit = 0; i >\
    \ 0; i >>= 1, ++bit) {\n      if (i & 1) v = parent[bit][v];\n    }\n    return\
    \ v;\n  }\n\n private:\n  bool is_built;\n  const int n, table_h;\n  std::vector<std::vector<int>>\
    \ parent;\n  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  void dfs(const\
    \ int par, const int ver, const int cur_depth,\n           const CostType cur_dist)\
    \ {\n    depth[ver] = cur_depth;\n    dist[ver] = cur_dist;\n    parent.front()[ver]\
    \ = par;\n    for (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst !=\
    \ par) dfs(ver, e.dst, cur_depth + 1, cur_dist + e.cost);\n    }\n  }\n};\n\n\
    }  // namespace emthrm\n\n\n#line 12 \"test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ graph(n);\n  for (int i = 0; i < n; ++i) {\n    int k;\n    std::cin >> k;\n\
    \    while (k--) {\n      int c;\n      std::cin >> c;\n      graph[i].emplace_back(i,\
    \ c, 1);\n      graph[c].emplace_back(c, i, 1);\n    }\n  }\n  emthrm::LowestCommonAncestorByDoubling<int>\
    \ lowest_common_ancestor(graph);\n  lowest_common_ancestor.build(0);\n  int q;\n\
    \  std::cin >> q;\n  while (q--) {\n    int u, v;\n    std::cin >> u >> v;\n \
    \   std::cout << lowest_common_ancestor.query(u, v) << '\\n';\n  }\n  return 0;\n\
    }\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u7248\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp\"\n\nint\
    \ main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ graph(n);\n  for (int i = 0; i < n; ++i) {\n    int k;\n    std::cin >> k;\n\
    \    while (k--) {\n      int c;\n      std::cin >> c;\n      graph[i].emplace_back(i,\
    \ c, 1);\n      graph[c].emplace_back(c, i, 1);\n    }\n  }\n  emthrm::LowestCommonAncestorByDoubling<int>\
    \ lowest_common_ancestor(graph);\n  lowest_common_ancestor.build(0);\n  int q;\n\
    \  std::cin >> q;\n  while (q--) {\n    int u, v;\n    std::cin >> u >> v;\n \
    \   std::cout << lowest_common_ancestor.query(u, v) << '\\n';\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp
  isVerificationFile: true
  path: test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
- /verify/test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\
  \u30EA\u30F3\u30B0\u7248"
---
