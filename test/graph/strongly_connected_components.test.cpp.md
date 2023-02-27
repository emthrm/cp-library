---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206 (strongly connected components) \u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/scc
    document_title: "\u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/graph/strongly_connected_components.test.cpp\"\n/*\n\
    \ * @title \u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n *\n\
    \ * verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc\n */\n\n\
    #include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/strongly_connected_components.hpp\"\
    \n\n\n\n// #include <algorithm>\n#include <ranges>\n#line 7 \"include/emthrm/graph/strongly_connected_components.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 9 \"include/emthrm/graph/strongly_connected_components.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename CostType, bool IS_FULL_VER = false>\nstruct StronglyConnectedComponents\
    \ {\n  std::vector<int> id;\n  std::vector<std::vector<int>> vertices;\n  std::vector<std::vector<Edge<CostType>>>\
    \ g;\n\n  explicit StronglyConnectedComponents(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : n(graph.size()), is_used(n, false), graph(graph), rgraph(n)\
    \ {\n    for (int i = 0; i < n; ++i) {\n      if (!is_used[i]) dfs(i);\n    }\n\
    \    id.assign(n, -1);\n    order.reserve(n);\n    for (int i = 0; i < n; ++i)\
    \ {\n      for (const Edge<CostType>& e : graph[i]) {\n        rgraph[e.dst].emplace_back(e.dst,\
    \ e.src, e.cost);\n      }\n    }\n    int m = 0;\n    for (int i = n - 1; i >=\
    \ 0; --i) {\n      if (id[order[i]] == -1) {\n        if constexpr (IS_FULL_VER)\
    \ vertices.emplace_back();\n        rdfs(order[i], m++);\n      }\n    }\n   \
    \ g.resize(m);\n    for (int i = 0; i < n; ++i) {\n      for (const Edge<CostType>&\
    \ e : graph[i]) {\n        if (id[i] != id[e.dst]) g[id[i]].emplace_back(id[i],\
    \ id[e.dst], e.cost);\n      }\n    }\n    // if constexpr (IS_FULL_VER) {\n \
    \   //   for (int i = 0; i < m; ++i) {\n    //     std::sort(vertices[i].begin(),\
    \ vertices[i].end());\n    //   }\n    // }\n  }\n\n private:\n  const int n;\n\
    \  std::vector<bool> is_used;\n  std::vector<int> order;\n  const std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n  std::vector<std::vector<Edge<CostType>>> rgraph;\n\n  void dfs(const\
    \ int ver) {\n    is_used[ver] = true;\n    for (const int e : graph[ver]\n  \
    \                   | std::views::transform(&Edge<CostType>::dst)) {\n      if\
    \ (!is_used[e]) dfs(e);\n    }\n    order.emplace_back(ver);\n  }\n\n  void rdfs(const\
    \ int ver, const int m) {\n    id[ver] = m;\n    if constexpr (IS_FULL_VER) vertices.back().emplace_back(ver);\n\
    \    for (const int e : rgraph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (id[e] == -1) rdfs(e, m);\n    }\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 12 \"test/graph/strongly_connected_components.test.cpp\"\n\nint main()\
    \ {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n    graph[a].emplace_back(a,\
    \ b);\n  }\n  const std::vector<std::vector<int>> ans =\n      emthrm::StronglyConnectedComponents<bool,\
    \ true>(graph).vertices;\n  const int k = ans.size();\n  std::cout << k << '\\\
    n';\n  for (int i = 0; i < k; ++i) {\n    const int l = ans[i].size();\n    std::cout\
    \ << l << ' ';\n    for (int j = 0; j < l; ++j) {\n      std::cout << ans[i][j]\
    \ << \" \\n\"[j + 1 == l];\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc\n */\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/strongly_connected_components.hpp\"\n\nint main() {\n\
    \  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n    graph[a].emplace_back(a,\
    \ b);\n  }\n  const std::vector<std::vector<int>> ans =\n      emthrm::StronglyConnectedComponents<bool,\
    \ true>(graph).vertices;\n  const int k = ans.size();\n  std::cout << k << '\\\
    n';\n  for (int i = 0; i < k; ++i) {\n    const int l = ans[i].size();\n    std::cout\
    \ << l << ' ';\n    for (int j = 0; j < l; ++j) {\n      std::cout << ans[i][j]\
    \ << \" \\n\"[j + 1 == l];\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: test/graph/strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/graph/strongly_connected_components.test.cpp
- /verify/test/graph/strongly_connected_components.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
