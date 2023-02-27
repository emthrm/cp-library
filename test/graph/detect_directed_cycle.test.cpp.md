---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/detect_directed_cycle.hpp
    title: "\u6709\u5411\u9589\u8DEF (directed cycle) \u306E\u691C\u51FA"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    document_title: "\u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/graph/detect_directed_cycle.test.cpp\"\n/*\n * @title\
    \ \u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/cycle_detection\n */\n\n#include <iostream>\n\
    #include <ranges>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/detect_directed_cycle.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"include/emthrm/graph/detect_directed_cycle.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 8 \"include/emthrm/graph/detect_directed_cycle.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>> detect_directed_cycle(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n =\
    \ graph.size();\n  std::vector<int> is_visited(n, 0);\n  std::vector<Edge<CostType>>\
    \ edges, cycle;\n  const auto dfs = [&graph, &is_visited, &edges, &cycle](\n \
    \     auto dfs, const int ver) -> bool {\n    is_visited[ver] = 1;\n    for (const\
    \ Edge<CostType>& e : graph[ver]) {\n      if (is_visited[e.dst] == 1) {\n   \
    \     cycle.emplace_back(e);\n        while (cycle.back().src != e.dst) {\n  \
    \        cycle.emplace_back(edges.back());\n          edges.pop_back();\n    \
    \    }\n        std::reverse(cycle.begin(), cycle.end());\n        return true;\n\
    \      } else if (is_visited[e.dst] == 0) {\n        edges.emplace_back(e);\n\
    \        if (dfs(dfs, e.dst)) return true;\n        edges.pop_back();\n      }\n\
    \    }\n    is_visited[ver] = 2;\n    return false;\n  };\n  for (int i = 0; i\
    \ < n; ++i) {\n    if (is_visited[i] == 0 && dfs(dfs, i)) break;\n  }\n  return\
    \ cycle;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 13 \"test/graph/detect_directed_cycle.test.cpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ graph(n);\n  for (int i = 0; i < m; ++i) {\n    int u, v;\n    std::cin >> u\
    \ >> v;\n    graph[u].emplace_back(u, v, i);\n  }\n  // GCC 12 adopted P2415.\n\
    \  const std::vector<emthrm::Edge<int>> cycle =\n      emthrm::detect_directed_cycle(graph);\n\
    \  const auto ev = cycle | std::views::transform(&emthrm::Edge<int>::cost);\n\
    \  // const auto ev = emthrm::detect_directed_cycle(graph)\n  //             \
    \  | std::views::transform(&emthrm::Edge<int>::cost);\n  const int l = ev.size();\n\
    \  if (l == 0) {\n    std::cout << \"-1\\n\";\n  } else {\n    std::cout << l\
    \ << '\\n';\n    for (const int e : ev) std::cout << e << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA\
    \n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/cycle_detection\n\
    \ */\n\n#include <iostream>\n#include <ranges>\n#include <vector>\n\n#include\
    \ \"emthrm/graph/detect_directed_cycle.hpp\"\n#include \"emthrm/graph/edge.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ graph(n);\n  for (int i = 0; i < m; ++i) {\n    int u, v;\n    std::cin >> u\
    \ >> v;\n    graph[u].emplace_back(u, v, i);\n  }\n  // GCC 12 adopted P2415.\n\
    \  const std::vector<emthrm::Edge<int>> cycle =\n      emthrm::detect_directed_cycle(graph);\n\
    \  const auto ev = cycle | std::views::transform(&emthrm::Edge<int>::cost);\n\
    \  // const auto ev = emthrm::detect_directed_cycle(graph)\n  //             \
    \  | std::views::transform(&emthrm::Edge<int>::cost);\n  const int l = ev.size();\n\
    \  if (l == 0) {\n    std::cout << \"-1\\n\";\n  } else {\n    std::cout << l\
    \ << '\\n';\n    for (const int e : ev) std::cout << e << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/detect_directed_cycle.hpp
  - include/emthrm/graph/edge.hpp
  isVerificationFile: true
  path: test/graph/detect_directed_cycle.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/detect_directed_cycle.test.cpp
layout: document
redirect_from:
- /verify/test/graph/detect_directed_cycle.test.cpp
- /verify/test/graph/detect_directed_cycle.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
---
