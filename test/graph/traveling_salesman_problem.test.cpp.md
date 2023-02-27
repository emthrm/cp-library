---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/traveling_salesman_problem.hpp
    title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C (traveling\
      \ salesman problem)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
    document_title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
      \u30F3\u554F\u984C"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
  bundledCode: "#line 1 \"test/graph/traveling_salesman_problem.test.cpp\"\n/*\n *\
    \ @title \u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\
    \u984C\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\n\
    \ */\n\n#include <iostream>\n#include <limits>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/traveling_salesman_problem.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#line 6 \"include/emthrm/graph/traveling_salesman_problem.hpp\"\
    \n#include <numeric>\n#line 8 \"include/emthrm/graph/traveling_salesman_problem.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 10 \"include/emthrm/graph/traveling_salesman_problem.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename CostType>\nCostType traveling_salesman_problem(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph,\n    const CostType\
    \ inf = std::numeric_limits<CostType>::max()) {\n  const int n = graph.size();\n\
    \  if (n == 1) [[unlikely]] return 0;\n  std::vector<std::vector<CostType>> dp(1\
    \ << n, std::vector<CostType>(n, inf));\n  dp[1][0] = 0;\n  for (int i = 1; i\
    \ < (1 << n); ++i) {\n    for (int j = 0; j < n; ++j) {\n      if (dp[i][j] ==\
    \ inf) continue;\n      for (const Edge<CostType>& e : graph[j]) {\n        if\
    \ (i >> e.dst & 1) continue;\n        dp[i | (1 << e.dst)][e.dst] =\n        \
    \    std::min(dp[i | (1 << e.dst)][e.dst], dp[i][j] + e.cost);\n      }\n    }\n\
    \  }\n  CostType res = inf;\n  for (int j = 1; j < n; ++j) {\n    if (dp.back()[j]\
    \ == inf) continue;\n    for (const Edge<CostType>& e : graph[j]) {\n      if\
    \ (e.dst == 0) res = std::min(res, dp.back()[j] + e.cost);\n    }\n  }\n  return\
    \ res;\n}\n\n}  // namespace emthrm\n\n\n#line 13 \"test/graph/traveling_salesman_problem.test.cpp\"\
    \n\nint main() {\n  constexpr int INF = std::numeric_limits<int>::max();\n  int\
    \ v, e;\n  std::cin >> v >> e;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ g(v);\n  while (e--) {\n    int s, t, d;\n    std::cin >> s >> t >> d;\n   \
    \ g[s].emplace_back(s, t, d);\n  }\n  const int ans = emthrm::traveling_salesman_problem(g,\
    \ INF);\n  std::cout << (ans == INF ? -1 : ans) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
    \u30F3\u554F\u984C\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\n\
    \ */\n\n#include <iostream>\n#include <limits>\n#include <vector>\n\n#include\
    \ \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/traveling_salesman_problem.hpp\"\
    \n\nint main() {\n  constexpr int INF = std::numeric_limits<int>::max();\n  int\
    \ v, e;\n  std::cin >> v >> e;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ g(v);\n  while (e--) {\n    int s, t, d;\n    std::cin >> s >> t >> d;\n   \
    \ g[s].emplace_back(s, t, d);\n  }\n  const int ans = emthrm::traveling_salesman_problem(g,\
    \ INF);\n  std::cout << (ans == INF ? -1 : ans) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/traveling_salesman_problem.hpp
  isVerificationFile: true
  path: test/graph/traveling_salesman_problem.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/traveling_salesman_problem.test.cpp
layout: document
redirect_from:
- /verify/test/graph/traveling_salesman_problem.test.cpp
- /verify/test/graph/traveling_salesman_problem.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C"
---
