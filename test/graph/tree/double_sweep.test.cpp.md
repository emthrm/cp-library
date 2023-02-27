---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/double_sweep.hpp
    title: double sweep
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    document_title: "\u30B0\u30E9\u30D5/\u6728/double sweep"
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/graph/tree/double_sweep.test.cpp\"\n/*\n * @title \u30B0\
    \u30E9\u30D5/\u6728/double sweep\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/tree_diameter\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/tree/double_sweep.hpp\"\
    \n\n\n\n#include <cassert>\n#include <ranges>\n#include <tuple>\n#include <utility>\n\
    #line 9 \"include/emthrm/graph/tree/double_sweep.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 11 \"include/emthrm/graph/tree/double_sweep.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::pair<CostType, std::vector<int>>\
    \ double_sweep(\n    const std::vector<std::vector<Edge<CostType>>>& graph) {\n\
    \  const auto dfs1 = [&graph](auto dfs1, const int par, const int ver)\n     \
    \ -> std::pair<CostType, int> {\n    std::pair<CostType, int> res{0, ver};\n \
    \   for (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst != par) [[unlikely]]\
    \ {\n        std::pair<CostType, int> child = dfs1(dfs1, ver, e.dst);\n      \
    \  child.first += e.cost;\n        if (child.first > res.first) res = child;\n\
    \      }\n    }\n    return res;\n  };\n  const int s = dfs1(dfs1, -1, 0).second;\n\
    \  const auto [diameter, t] = dfs1(dfs1, -1, s);\n  std::vector<int> path{s};\n\
    \  const auto dfs2 = [&graph, t, &path](auto dfs2, const int par, const int ver)\n\
    \      -> bool {\n    if (ver == t) return true;\n    for (const int e : graph[ver]\n\
    \                     | std::views::transform(&Edge<CostType>::dst)) {\n     \
    \ if (e != par) [[likely]] {\n        path.emplace_back(e);\n        if (dfs2(dfs2,\
    \ ver, e)) return true;\n        path.pop_back();\n      }\n    }\n    return\
    \ false;\n  };\n  assert(dfs2(dfs2, -1, s));\n  return {diameter, path};\n}\n\n\
    }  // namespace emthrm\n\n\n#line 12 \"test/graph/tree/double_sweep.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b, c;\n \
    \   std::cin >> a >> b >> c;\n    graph[a].emplace_back(a, b, c);\n    graph[b].emplace_back(b,\
    \ a, c);\n  }\n  const auto [x, u] = emthrm::double_sweep(graph);\n  const int\
    \ y = u.size();\n  std::cout << x << ' ' << y << '\\n';\n  for (int i = 0; i <\
    \ y; ++i) {\n    std::cout << u[i] << \" \\n\"[i + 1 == y];\n  }\n  return 0;\n\
    }\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6728/double sweep\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/tree_diameter\n */\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/double_sweep.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b, c;\n \
    \   std::cin >> a >> b >> c;\n    graph[a].emplace_back(a, b, c);\n    graph[b].emplace_back(b,\
    \ a, c);\n  }\n  const auto [x, u] = emthrm::double_sweep(graph);\n  const int\
    \ y = u.size();\n  std::cout << x << ' ' << y << '\\n';\n  for (int i = 0; i <\
    \ y; ++i) {\n    std::cout << u[i] << \" \\n\"[i + 1 == y];\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/double_sweep.hpp
  isVerificationFile: true
  path: test/graph/tree/double_sweep.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/double_sweep.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/double_sweep.test.cpp
- /verify/test/graph/tree/double_sweep.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/double sweep"
---
