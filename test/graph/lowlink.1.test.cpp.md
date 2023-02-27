---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/lowlink.hpp
    title: lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    document_title: "\u30B0\u30E9\u30D5/lowlink\uFF08\u6A4B\uFF09"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"test/graph/lowlink.1.test.cpp\"\n/*\n * @title \u30B0\u30E9\
    \u30D5/lowlink\uFF08\u6A4B\uFF09\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <utility>\n#include\
    \ <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\
    \n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include\
    \ <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge\
    \ {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src, const\
    \ int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\
    \n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/lowlink.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/graph/lowlink.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 8 \"include/emthrm/graph/lowlink.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Lowlink {\n  std::vector<int>\
    \ order, lowlink, articulation_points;\n  std::vector<Edge<CostType>> bridges;\n\
    \  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  explicit Lowlink(const\
    \ std::vector<std::vector<Edge<CostType>>>& graph)\n      : graph(graph) {\n \
    \   const int n = graph.size();\n    order.assign(n, -1);\n    lowlink.resize(n);\n\
    \    int t = 0;\n    for (int i = 0; i < n; ++i) {\n      if (order[i] == -1)\
    \ dfs(-1, i, &t);\n    }\n  }\n\n private:\n  void dfs(const int par, const int\
    \ ver, int* t) {\n    order[ver] = lowlink[ver] = (*t)++;\n    int num = 0;\n\
    \    bool is_articulation_point = false;\n    for (const Edge<CostType>& e : graph[ver])\
    \ {\n      if (order[e.dst] == -1) {\n        ++num;\n        dfs(ver, e.dst,\
    \ t);\n        lowlink[ver] = std::min(lowlink[ver], lowlink[e.dst]);\n      \
    \  if (order[ver] <= lowlink[e.dst]) {\n          is_articulation_point = true;\n\
    \          if (order[ver] < lowlink[e.dst]) {\n            bridges.emplace_back(std::min(ver,\
    \ e.dst), std::max(ver, e.dst),\n                                 e.cost);\n \
    \         }\n        }\n      } else if (e.dst != par) {\n        lowlink[ver]\
    \ = std::min(lowlink[ver], order[e.dst]);\n      }\n    }\n    if ((par == -1\
    \ && num >= 2) || (par != -1 && is_articulation_point)) {\n      articulation_points.emplace_back(ver);\n\
    \    }\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 14 \"test/graph/lowlink.1.test.cpp\"\
    \n\nint main() {\n  int v, e;\n  std::cin >> v >> e;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(v);\n  while (e--) {\n    int s, t;\n    std::cin >> s >> t;\n    graph[s].emplace_back(s,\
    \ t);\n    graph[t].emplace_back(t, s);\n  }\n  emthrm::Lowlink<bool> l(graph);\n\
    \  std::ranges::sort(l.bridges.begin(), l.bridges.end(), {},\n               \
    \     [](const emthrm::Edge<bool>& e) -> std::pair<int, int> {\n             \
    \         return std::make_pair(e.src, e.dst);\n                    });\n  for\
    \ (const emthrm::Edge<bool>& bridge : l.bridges) {\n    std::cout << bridge.src\
    \ << ' ' << bridge.dst << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/lowlink\uFF08\u6A4B\uFF09\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\n */\n\
    \n#include <algorithm>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/lowlink.hpp\"\n\n\
    int main() {\n  int v, e;\n  std::cin >> v >> e;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(v);\n  while (e--) {\n    int s, t;\n    std::cin >> s >> t;\n    graph[s].emplace_back(s,\
    \ t);\n    graph[t].emplace_back(t, s);\n  }\n  emthrm::Lowlink<bool> l(graph);\n\
    \  std::ranges::sort(l.bridges.begin(), l.bridges.end(), {},\n               \
    \     [](const emthrm::Edge<bool>& e) -> std::pair<int, int> {\n             \
    \         return std::make_pair(e.src, e.dst);\n                    });\n  for\
    \ (const emthrm::Edge<bool>& bridge : l.bridges) {\n    std::cout << bridge.src\
    \ << ' ' << bridge.dst << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/lowlink.hpp
  isVerificationFile: true
  path: test/graph/lowlink.1.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 16:57:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lowlink.1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lowlink.1.test.cpp
- /verify/test/graph/lowlink.1.test.cpp.html
title: "\u30B0\u30E9\u30D5/lowlink\uFF08\u6A4B\uFF09"
---
