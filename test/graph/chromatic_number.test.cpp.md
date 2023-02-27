---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/chromatic_number.hpp
    title: "\u5F69\u8272\u6570 (chromatic number)"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    document_title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/graph/chromatic_number.test.cpp\"\n/*\n * @title \u30B0\
    \u30E9\u30D5/\u5F69\u8272\u6570\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/chromatic_number\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/chromatic_number.hpp\"\
    \n\n\n\n#include <bit>\n#include <numeric>\n#include <ranges>\n#line 8 \"include/emthrm/graph/chromatic_number.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 10 \"include/emthrm/graph/chromatic_number.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <typename CostType>\nint chromatic_number(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\n  const int n = graph.size();\n  std::vector<int> adj(n, 0);\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (const int e : graph[i] | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      adj[i] |= 1 << e;\n    }\n  }\n  std::vector<int> indep(1 << n);\n\
    \  indep[0] = 1;\n  for (unsigned int i = 1; i < (1 << n); ++i) {\n    const int\
    \ v = std::countr_zero(i);\n    indep[i] = indep[i ^ (1 << v)] + indep[(i ^ (1\
    \ << v)) & ~adj[v]];\n  }\n  int res = n;\n  for (const int mod : std::vector<int>{1000000007,\
    \ 1000000011}) {\n    std::vector<long long> f(1 << n);\n    for (unsigned int\
    \ i = 0; i < (1 << n); ++i) {\n      f[i] = ((n - std::popcount(i)) & 1 ? mod\
    \ - 1 : 1);\n    }\n    for (int c = 1; c < res; ++c) {\n      for (int i = 0;\
    \ i < (1 << n); ++i) {\n        f[i] = (f[i] * indep[i]) % mod;\n      }\n   \
    \   if (std::reduce(f.begin(), f.end(), 0LL) % mod > 0) {\n        res = c;\n\
    \        break;\n      }\n    }\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 12 \"test/graph/chromatic_number.test.cpp\"\n\nint main() {\n  int n, m;\n\
    \  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);\n\
    \  while (m--) {\n    int u, v;\n    std::cin >> u >> v;\n    graph[u].emplace_back(u,\
    \ v);\n    graph[v].emplace_back(v, u);\n  }\n  std::cout << emthrm::chromatic_number(graph)\
    \ << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u5F69\u8272\u6570\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/chromatic_number\n */\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"emthrm/graph/chromatic_number.hpp\"\n#include\
    \ \"emthrm/graph/edge.hpp\"\n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n\
    \  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);\n  while (m--) {\n \
    \   int u, v;\n    std::cin >> u >> v;\n    graph[u].emplace_back(u, v);\n   \
    \ graph[v].emplace_back(v, u);\n  }\n  std::cout << emthrm::chromatic_number(graph)\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/chromatic_number.hpp
  - include/emthrm/graph/edge.hpp
  isVerificationFile: true
  path: test/graph/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/graph/chromatic_number.test.cpp
- /verify/test/graph/chromatic_number.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
---
