---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206 (2-edge-connected component)\
      \ \u5206\u89E3 lowlink \u7248"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/lowlink.hpp
    title: lowlink
  - icon: ':question:'
    path: include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (lowest common ancestor) \u30C0\u30D6\
      \u30EA\u30F3\u30B0\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/arc039/tasks/arc039_d
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
      \u5206\u89E3 lowlink \u7248"
    links:
    - https://atcoder.jp/contests/arc039/tasks/arc039_d
  bundledCode: "#line 1 \"test/graph/2-edge-connected_components_by_lowlink.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\
    \u89E3 lowlink \u7248\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/arc039/tasks/arc039_d\n */\n\n#include <iostream>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp\"\
    \n\n\n\n// #include <algorithm>\n#include <ranges>\n#line 7 \"include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/lowlink.hpp\"\n\n\n\n#include <algorithm>\n#line\
    \ 6 \"include/emthrm/graph/lowlink.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
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
    \    }\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 10 \"include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType, bool IS_FULL_VER = false>\n\
    struct TwoEdgeConnectedComponents : Lowlink<CostType> {\n  std::vector<int> id;\n\
    \  std::vector<std::vector<int>> vertices;\n  std::vector<std::vector<Edge<CostType>>>\
    \ g;\n\n  explicit TwoEdgeConnectedComponents(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : Lowlink<CostType>(graph) {\n    const int n = graph.size();\n\
    \    id.assign(n, -1);\n    int m = 0;\n    for (int i = 0; i < n; ++i) {\n  \
    \    if (id[i] == -1) dfs(-1, i, &m);\n    }\n    g.resize(m);\n    for (const\
    \ Edge<CostType>& e : this->bridges) {\n      const int u = id[e.src], v = id[e.dst];\n\
    \      g[u].emplace_back(u, v, e.cost);\n      g[v].emplace_back(v, u, e.cost);\n\
    \    }\n    // if constexpr (IS_FULL_VER) {\n    //   for (int i = 0; i < m; ++i)\
    \ {\n    //     std::sort(vertices[i].begin(), vertices[i].end());\n    //   }\n\
    \    // }\n  }\n\n private:\n  void dfs(const int par, const int ver, int* m)\
    \ {\n    if (par != -1 && this->order[par] >= this->lowlink[ver]) {\n      id[ver]\
    \ = id[par];\n    } else {\n      id[ver] = (*m)++;\n      if constexpr (IS_FULL_VER)\
    \ vertices.emplace_back();\n    }\n    if constexpr (IS_FULL_VER) vertices[id[ver]].emplace_back(ver);\n\
    \    for (const int e : this->graph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (id[e] == -1) dfs(ver, e, m);\n    }\n  }\n};\n\n}  // namespace\
    \ emthrm\n\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\
    \n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include\
    \ <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge\
    \ {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src, const\
    \ int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\
    \n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp\"\
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
    }  // namespace emthrm\n\n\n#line 14 \"test/graph/2-edge-connected_components_by_lowlink.test.cpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ graph(n);\n  while (m--) {\n    int x, y;\n    std::cin >> x >> y;\n    --x;\
    \ --y;\n    graph[x].emplace_back(x, y, 1);\n    graph[y].emplace_back(y, x, 1);\n\
    \  }\n  const emthrm::TwoEdgeConnectedComponents<int>\n      two_edge_connected_components(graph);\n\
    \  emthrm::LowestCommonAncestorByDoubling<int>\n      lca(two_edge_connected_components.g);\n\
    \  lca.build();\n  int q;\n  std::cin >> q;\n  while (q--) {\n    int a, b, c;\n\
    \    std::cin >> a >> b >> c;\n    --a; --b; --c;\n    a = two_edge_connected_components.id[a];\n\
    \    b = two_edge_connected_components.id[b];\n    c = two_edge_connected_components.id[c];\n\
    \    if (lca.distance(a, b) + lca.distance(b, c) == lca.distance(a, c)) {\n  \
    \    std::cout << \"OK\\n\";\n    } else {\n      std::cout << \"NG\\n\";\n  \
    \  }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u5206\u89E3 lowlink \u7248\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/arc039/tasks/arc039_d\n */\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"emthrm/graph/2-edge-connected_components_by_lowlink.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ graph(n);\n  while (m--) {\n    int x, y;\n    std::cin >> x >> y;\n    --x;\
    \ --y;\n    graph[x].emplace_back(x, y, 1);\n    graph[y].emplace_back(y, x, 1);\n\
    \  }\n  const emthrm::TwoEdgeConnectedComponents<int>\n      two_edge_connected_components(graph);\n\
    \  emthrm::LowestCommonAncestorByDoubling<int>\n      lca(two_edge_connected_components.g);\n\
    \  lca.build();\n  int q;\n  std::cin >> q;\n  while (q--) {\n    int a, b, c;\n\
    \    std::cin >> a >> b >> c;\n    --a; --b; --c;\n    a = two_edge_connected_components.id[a];\n\
    \    b = two_edge_connected_components.id[b];\n    c = two_edge_connected_components.id[c];\n\
    \    if (lca.distance(a, b) + lca.distance(b, c) == lca.distance(a, c)) {\n  \
    \    std::cout << \"OK\\n\";\n    } else {\n      std::cout << \"NG\\n\";\n  \
    \  }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/lowlink.hpp
  - include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp
  isVerificationFile: true
  path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/graph/2-edge-connected_components_by_lowlink.test.cpp
layout: document
redirect_from:
- /verify/test/graph/2-edge-connected_components_by_lowlink.test.cpp
- /verify/test/graph/2-edge-connected_components_by_lowlink.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
  \ lowlink \u7248"
---
