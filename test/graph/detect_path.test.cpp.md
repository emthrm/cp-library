---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/detect_path.hpp
    title: "\u9053 (path) \u306E\u691C\u51FA"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/past202112-open/tasks/past202112_g
    document_title: "\u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA"
    links:
    - https://atcoder.jp/contests/past202112-open/tasks/past202112_g
  bundledCode: "#line 1 \"test/graph/detect_path.test.cpp\"\n/*\n * @title \u30B0\u30E9\
    \u30D5/\u9053\u306E\u691C\u51FA\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/past202112-open/tasks/past202112_g\n */\n\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/detect_path.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/graph/detect_path.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 7 \"include/emthrm/graph/detect_path.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>>\
    \ detect_path(\n    const std::vector<std::vector<Edge<CostType>>>& graph,\n \
    \   const int s, const int t) {\n  std::vector<bool> is_visited(graph.size(),\
    \ false);\n  std::vector<Edge<CostType>> path;\n  const auto dfs = [&graph, t,\
    \ &is_visited, &path](auto dfs, const int ver)\n      -> bool {\n    if (ver ==\
    \ t) return true;\n    is_visited[ver] = true;\n    for (const Edge<CostType>&\
    \ e : graph[ver]) {\n      if (!is_visited[e.dst]) {\n        path.emplace_back(e);\n\
    \        if (dfs(dfs, e.dst)) return true;\n        path.pop_back();\n      }\n\
    \    }\n    return false;\n  };\n  dfs(dfs, s);\n  return path;\n}\n\n}  // namespace\
    \ emthrm\n\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\
    \n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include\
    \ <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge\
    \ {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src, const\
    \ int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\
    \n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 14 \"test/graph/detect_path.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (q--) {\n    int type, u, v;\n    std::cin >> type >> u >>\
    \ v;\n    --u; --v;\n    if (type == 1) {\n      const auto adj = std::ranges::find(graph[u],\
    \ v, &emthrm::Edge<bool>::dst);\n      if (adj != graph[u].end()) {\n        graph[u].erase(adj);\n\
    \        graph[v].erase(\n            std::ranges::find(graph[v], u, &emthrm::Edge<bool>::dst));\n\
    \      } else {\n        graph[u].emplace_back(u, v);\n        graph[v].emplace_back(v,\
    \ u);\n      }\n    } else if (type == 2) {\n      std::cout << (emthrm::detect_path(graph,\
    \ u, v).empty() ?\n                    \"No\\n\" : \"Yes\\n\");\n    }\n  }\n\
    \  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/past202112-open/tasks/past202112_g\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include\
    \ \"emthrm/graph/detect_path.hpp\"\n#include \"emthrm/graph/edge.hpp\"\n\nint\
    \ main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (q--) {\n    int type, u, v;\n    std::cin >> type >> u >>\
    \ v;\n    --u; --v;\n    if (type == 1) {\n      const auto adj = std::ranges::find(graph[u],\
    \ v, &emthrm::Edge<bool>::dst);\n      if (adj != graph[u].end()) {\n        graph[u].erase(adj);\n\
    \        graph[v].erase(\n            std::ranges::find(graph[v], u, &emthrm::Edge<bool>::dst));\n\
    \      } else {\n        graph[u].emplace_back(u, v);\n        graph[v].emplace_back(v,\
    \ u);\n      }\n    } else if (type == 2) {\n      std::cout << (emthrm::detect_path(graph,\
    \ u, v).empty() ?\n                    \"No\\n\" : \"Yes\\n\");\n    }\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/detect_path.hpp
  - include/emthrm/graph/edge.hpp
  isVerificationFile: true
  path: test/graph/detect_path.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/graph/detect_path.test.cpp
layout: document
redirect_from:
- /verify/test/graph/detect_path.test.cpp
- /verify/test/graph/detect_path.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA"
---
