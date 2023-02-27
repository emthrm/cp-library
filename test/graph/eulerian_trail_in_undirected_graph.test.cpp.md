---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u8DEF (Eulerian trail) \u7121\u5411\u30B0\u30E9\
      \u30D5\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/583
    document_title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\
      \u30B0\u30E9\u30D5\u7248"
    links:
    - https://yukicoder.me/problems/no/583
  bundledCode: "#line 1 \"test/graph/eulerian_trail_in_undirected_graph.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\
    \u30B0\u30E9\u30D5\u7248\n *\n * verification-helper: PROBLEM https://yukicoder.me/problems/no/583\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace emthrm {\n\nstruct EulerianTrailInUndirectedGraph\
    \ {\n  std::vector<int> trail;\n\n  explicit EulerianTrailInUndirectedGraph(const\
    \ int n)\n      : n(n), is_visited(n), graph(n) {}\n\n  void add_edge(const int\
    \ u, const int v) {\n    graph[u].emplace_back(v, graph[v].size());\n    graph[v].emplace_back(u,\
    \ graph[u].size() - 1);\n  }\n\n  bool build(int s = -1) {\n    trail.clear();\n\
    \    int odd_deg = 0, edge_num = 0;\n    for (int i = 0; i < n; ++i) {\n     \
    \ if (graph[i].size() & 1) {\n        ++odd_deg;\n        if (s == -1) s = i;\n\
    \      }\n      edge_num += graph[i].size();\n    }\n    edge_num >>= 1;\n   \
    \ if (edge_num == 0) {\n      trail = {s == -1 ? 0 : s};\n      return true;\n\
    \    }\n    if (odd_deg == 0) {\n      if (s == -1) {\n        s = std::distance(\n\
    \            graph.begin(),\n            std::find_if_not(graph.begin(), graph.end(),\n\
    \                             [](const std::vector<Edge>& edges) -> bool {\n \
    \                              return edges.empty();\n                       \
    \      }));\n      }\n    } else if (odd_deg != 2) {\n      return false;\n  \
    \  }\n    for (int i = 0; i < n; ++i) {\n      is_visited[i].assign(graph[i].size(),\
    \ false);\n    }\n    dfs(s);\n    if (std::cmp_equal(trail.size(), edge_num +\
    \ 1)) {\n      std::reverse(trail.begin(), trail.end());\n      return true;\n\
    \    }\n    trail.clear();\n    return false;\n  }\n\n private:\n  struct Edge\
    \ {\n    int dst, rev;\n    explicit Edge(const int dst, const int rev) : dst(dst),\
    \ rev(rev) {}\n  };\n\n  const int n;\n  std::vector<std::vector<bool>> is_visited;\n\
    \  std::vector<std::vector<Edge>> graph;\n\n  void dfs(const int ver) {\n    const\
    \ int deg = graph[ver].size();\n    for (int i = 0; i < deg; ++i) {\n      if\
    \ (!is_visited[ver][i]) {\n        const int dst = graph[ver][i].dst;\n      \
    \  is_visited[ver][i] = true;\n        is_visited[dst][graph[ver][i].rev] = true;\n\
    \        dfs(dst);\n      }\n    }\n    trail.emplace_back(ver);\n  }\n};\n\n\
    }  // namespace emthrm\n\n\n#line 10 \"test/graph/eulerian_trail_in_undirected_graph.test.cpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  emthrm::EulerianTrailInUndirectedGraph\
    \ eulerian_trail(n);\n  while (m--) {\n    int sa, sb;\n    std::cin >> sa >>\
    \ sb;\n    eulerian_trail.add_edge(sa, sb);\n  }\n  std::cout << (eulerian_trail.build()\
    \ ? \"YES\\n\" : \"NO\\n\");\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\
    \u30B0\u30E9\u30D5\u7248\n *\n * verification-helper: PROBLEM https://yukicoder.me/problems/no/583\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/graph/eulerian_trail_in_undirected_graph.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  emthrm::EulerianTrailInUndirectedGraph\
    \ eulerian_trail(n);\n  while (m--) {\n    int sa, sb;\n    std::cin >> sa >>\
    \ sb;\n    eulerian_trail.add_edge(sa, sb);\n  }\n  std::cout << (eulerian_trail.build()\
    \ ? \"YES\\n\" : \"NO\\n\");\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp
  isVerificationFile: true
  path: test/graph/eulerian_trail_in_undirected_graph.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/eulerian_trail_in_undirected_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/eulerian_trail_in_undirected_graph.test.cpp
- /verify/test/graph/eulerian_trail_in_undirected_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\
  \u30D5\u7248"
---
