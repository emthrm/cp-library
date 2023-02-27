---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/2-edge-connected_components_by_imos.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206 (2-edge-connected component)\
      \ \u5206\u89E3 \u3044\u3082\u3059\u6CD5\u7248"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/enumerate_bridges.hpp
    title: "\u6A4B\u306E\u691C\u51FA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
      \u5206\u89E3 \u3044\u3082\u3059\u6CD5\u7248"
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/graph/2-edge-connected_components_by_imos.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\
    \u89E3 \u3044\u3082\u3059\u6CD5\u7248\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/two_edge_connected_components\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/2-edge-connected_components_by_imos.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <set>\n#include <queue>\n#include <ranges>\n\
    #include <utility>\n#line 10 \"include/emthrm/graph/2-edge-connected_components_by_imos.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/enumerate_bridges.hpp\"\n\n\n\n#line 6 \"include/emthrm/graph/enumerate_bridges.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 8 \"include/emthrm/graph/enumerate_bridges.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <typename CostType>\nstd::vector<Edge<CostType>> enumerate_bridges(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n =\
    \ graph.size();\n  std::vector<Edge<CostType>> res;\n  std::vector<int> depth(n,\
    \ -1), imos(n, 0);\n  const auto dfs = [&graph, &res, &depth, &imos](\n      auto\
    \ dfs, const int par, const int ver) -> void {\n    bool has_multiple_edges =\
    \ false;\n    for (const Edge<CostType>& e : graph[ver]) {\n      if (depth[e.dst]\
    \ == -1) {\n        depth[e.dst] = depth[ver] + 1;\n        dfs(dfs, ver, e.dst);\n\
    \        if (imos[e.dst] == 0) {\n          res.emplace_back(std::min(ver, e.dst),\
    \ std::max(ver, e.dst), e.cost);\n        }\n        imos[ver] += imos[e.dst];\n\
    \      } else if (!has_multiple_edges && e.dst == par) {\n        has_multiple_edges\
    \ = true;\n      } else if (depth[e.dst] < depth[ver]) {\n        ++imos[ver];\n\
    \        --imos[e.dst];\n      }\n    }\n  };\n  for (int i = 0; i < n; ++i) {\n\
    \    if (depth[i] == -1) {\n      depth[i] = 0;\n      dfs(dfs, -1, i);\n    }\n\
    \  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 13 \"include/emthrm/graph/2-edge-connected_components_by_imos.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType, bool IS_FULL_VER = false>\n\
    struct TwoEdgeConnectedComponentsByImos {\n  std::vector<int> id;\n  std::vector<Edge<CostType>>\
    \ bridge;\n  std::vector<std::vector<int>> vertices;\n  std::vector<std::vector<Edge<CostType>>>\
    \ g;\n\n  explicit TwoEdgeConnectedComponentsByImos(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : bridge(enumerate_bridges(graph)) {\n    const int n = graph.size();\n\
    \    id.assign(n, -1);\n    std::set<std::pair<int, int>> st;\n    for (const\
    \ Edge<CostType>& e : bridge) st.emplace(e.src, e.dst);\n    int m = 0;\n    std::queue<int>\
    \ que;\n    for (int i = 0; i < n; ++i) {\n      if (id[i] != -1) continue;\n\
    \      que.emplace(i);\n      id[i] = m++;\n      if constexpr (IS_FULL_VER) vertices.emplace_back(std::vector<int>{i});\n\
    \      while (!que.empty()) {\n        const int ver = que.front();\n        que.pop();\n\
    \        for (const int e : graph[ver]\n                         | std::views::transform(&Edge<CostType>::dst))\
    \ {\n          if (id[e] == -1 && !st.contains(std::minmax(ver, e))) {\n     \
    \       id[e] = id[i];\n            if constexpr (IS_FULL_VER) vertices.back().emplace_back(e);\n\
    \            que.emplace(e);\n          }\n        }\n      }\n    }\n    g.resize(m);\n\
    \    for (const Edge<CostType>& e : bridge) {\n      const int u = id[e.src],\
    \ v = id[e.dst];\n      g[u].emplace_back(u, v, e.cost);\n      g[v].emplace_back(v,\
    \ u, e.cost);\n    }\n    if constexpr (IS_FULL_VER) {\n      for (int i = 0;\
    \ i < m; ++i) {\n        std::sort(vertices[i].begin(), vertices[i].end());\n\
    \      }\n    }\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 12 \"test/graph/2-edge-connected_components_by_imos.test.cpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n    graph[a].emplace_back(a,\
    \ b);\n    graph[b].emplace_back(b, a);\n  }\n  const std::vector<std::vector<int>>\
    \ ans =\n      emthrm::TwoEdgeConnectedComponentsByImos<bool, true>(graph).vertices;\n\
    \  const int k = ans.size();\n  std::cout << k << '\\n';\n  for (int i = 0; i\
    \ < k; ++i) {\n    const int l = ans[i].size();\n    std::cout << l << ' ';\n\
    \    for (int j = 0; j < l; ++j) {\n      std::cout << ans[i][j] << \" \\n\"[j\
    \ + 1 == l];\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u5206\u89E3 \u3044\u3082\u3059\u6CD5\u7248\n *\n * verification-helper: PROBLEM\
    \ https://judge.yosupo.jp/problem/two_edge_connected_components\n */\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"emthrm/graph/2-edge-connected_components_by_imos.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n\nint main() {\n  int n, m;\n  std::cin\
    \ >> n >> m;\n  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);\n  while\
    \ (m--) {\n    int a, b;\n    std::cin >> a >> b;\n    graph[a].emplace_back(a,\
    \ b);\n    graph[b].emplace_back(b, a);\n  }\n  const std::vector<std::vector<int>>\
    \ ans =\n      emthrm::TwoEdgeConnectedComponentsByImos<bool, true>(graph).vertices;\n\
    \  const int k = ans.size();\n  std::cout << k << '\\n';\n  for (int i = 0; i\
    \ < k; ++i) {\n    const int l = ans[i].size();\n    std::cout << l << ' ';\n\
    \    for (int j = 0; j < l; ++j) {\n      std::cout << ans[i][j] << \" \\n\"[j\
    \ + 1 == l];\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/2-edge-connected_components_by_imos.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/enumerate_bridges.hpp
  isVerificationFile: true
  path: test/graph/2-edge-connected_components_by_imos.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/2-edge-connected_components_by_imos.test.cpp
layout: document
redirect_from:
- /verify/test/graph/2-edge-connected_components_by_imos.test.cpp
- /verify/test/graph/2-edge-connected_components_by_imos.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
  \ \u3044\u3082\u3059\u6CD5\u7248"
---
