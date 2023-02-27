---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/heavy-light_decomposition.hpp
    title: "HL \u5206\u89E3 (heavy-light decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    document_title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\
      \u901A\u7956\u5148)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/graph/tree/heavy-light_decomposition.2.test.cpp\"\n\
    /*\n * @title \u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\u901A\
    \u7956\u5148)\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/tree/heavy-light_decomposition.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <utility>\n#line 7 \"include/emthrm/graph/tree/heavy-light_decomposition.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 9 \"include/emthrm/graph/tree/heavy-light_decomposition.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename CostType>\nstruct HeavyLightDecomposition {\n\
    \  std::vector<int> parent, subtree, id, inv, head;\n  std::vector<CostType> cost;\n\
    \n  explicit HeavyLightDecomposition(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n      const int root = 0)\n      : graph(graph) {\n    const int n =\
    \ graph.size();\n    parent.assign(n, -1);\n    subtree.assign(n, 1);\n    dfs1(root);\n\
    \    id.resize(n);\n    inv.resize(n);\n    head.assign(n, root);\n    int cur_id\
    \ = 0;\n    dfs2(root, &cur_id);\n  }\n\n  template <typename Fn>\n  void update_v(int\
    \ u, int v, const Fn f) const {\n    while (true) {\n      if (id[u] > id[v])\
    \ std::swap(u, v);\n      f(std::max(id[head[v]], id[u]), id[v] + 1);\n      if\
    \ (head[u] == head[v]) break;\n      v = parent[head[v]];\n    }\n  }\n\n  template\
    \ <typename F, typename G, typename T>\n  T query_v(int u, int v, const F f, const\
    \ G g, const T id_t) const {\n    T left = id_t, right = id_t;\n    while (true)\
    \ {\n      if (id_t[u] > id_t[v]) {\n        std::swap(u, v);\n        std::swap(left,\
    \ right);\n      }\n      left = g(left, f(std::max(id_t[head[v]], id_t[u]), id_t[v]\
    \ + 1));\n      if (head[u] == head[v]) break;\n      v = parent[head[v]];\n \
    \   }\n    return g(left, right);\n  }\n\n  template <typename Fn>\n  void update_subtree_v(const\
    \ int ver, const Fn f) const {\n    f(id[ver], id[ver] + subtree[ver]);\n  }\n\
    \n  template <typename T, typename Fn>\n  T query_subtree_v(const int ver, const\
    \ Fn f) const {\n    return f(id[ver], id[ver] + subtree[ver]);\n  }\n\n  template\
    \ <typename Fn>\n  void update_e(int u, int v, const Fn f) const {\n    while\
    \ (true) {\n      if (id[u] > id[v]) std::swap(u, v);\n      if (head[u] == head[v])\
    \ {\n        f(id[u], id[v]);\n        break;\n      } else {\n        f(id[head[v]]\
    \ - 1, id[v]);\n        v = parent[head[v]];\n      }\n    }\n  }\n\n  template\
    \ <typename F, typename G, typename T>\n  T query_e(int u, int v, const F f, const\
    \ G g, const T id_t) const {\n    T left = id_t, right = id_t;\n    while (true)\
    \ {\n      if (id[u] > id[v]) {\n        std::swap(u, v);\n        std::swap(left,\
    \ right);\n      }\n      if (head[u] == head[v]) {\n        left = g(left, f(id[u],\
    \ id[v]));\n        break;\n      } else {\n        left = g(left, f(id[head[v]]\
    \ - 1, id[v]));\n        v = parent[head[v]];\n      }\n    }\n    return g(left,\
    \ right);\n  }\n\n  template <typename Fn>\n  void update_subtree_e(const int\
    \ ver, const Fn f) const {\n    f(id[ver], id[ver] + subtree[ver] - 1);\n  }\n\
    \n  template <typename T, typename Fn>\n  T query_subtree_e(const int ver, const\
    \ Fn f) const {\n    return f(id[ver], id[ver] + subtree[ver] - 1);\n  }\n\n \
    \ int lowest_common_ancestor(int u, int v) const {\n    while (true) {\n     \
    \ if (id[u] > id[v]) std::swap(u, v);\n      if (head[u] == head[v]) break;\n\
    \      v = parent[head[v]];\n    }\n    return u;\n  }\n\n private:\n  std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n\n  void dfs1(const int ver) {\n    for (int i = 0; std::cmp_less(i,\
    \ graph[ver].size()); ++i) {\n      Edge<CostType>& e = graph[ver][i];\n     \
    \ if (e.dst != parent[ver]) [[likely]] {\n        parent[e.dst] = ver;\n     \
    \   dfs1(e.dst);\n        subtree[ver] += subtree[e.dst];\n        if (subtree[e.dst]\
    \ > subtree[graph[ver].front().dst]) {\n          std::swap(e, graph[ver].front());\n\
    \        }\n      }\n    }\n  }\n\n  void dfs2(const int ver, int* cur_id) {\n\
    \    id[ver] = (*cur_id)++;\n    inv[id[ver]] = ver;\n    for (const Edge<CostType>&\
    \ e : graph[ver]) {\n      if (e.dst != parent[ver]) [[likely]] {\n        head[e.dst]\
    \ = (e.dst == graph[ver].front().dst ? head[ver] : e.dst);\n        cost.emplace_back(e.cost);\n\
    \        dfs2(e.dst, cur_id);\n      }\n    }\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 12 \"test/graph/tree/heavy-light_decomposition.2.test.cpp\"\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ graph(n);\n  for (int i = 0; i < n; ++i) {\n    int k;\n    std::cin >> k;\n\
    \    while (k--) {\n      int c;\n      std::cin >> c;\n      graph[i].emplace_back(i,\
    \ c, 1);\n      graph[c].emplace_back(c, i, 1);\n    }\n  }\n  const emthrm::HeavyLightDecomposition<int>\n\
    \      heavy_light_decomposition(graph, 0);\n  int q;\n  std::cin >> q;\n  while\
    \ (q--) {\n    int u, v;\n    std::cin >> u >> v;\n    std::cout << heavy_light_decomposition.lowest_common_ancestor(u,\
    \ v) << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\
    \u901A\u7956\u5148)\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/tree/heavy-light_decomposition.hpp\"\n\nint main() {\n\
    \  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<int>>> graph(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    int k;\n    std::cin >> k;\n    while (k--)\
    \ {\n      int c;\n      std::cin >> c;\n      graph[i].emplace_back(i, c, 1);\n\
    \      graph[c].emplace_back(c, i, 1);\n    }\n  }\n  const emthrm::HeavyLightDecomposition<int>\n\
    \      heavy_light_decomposition(graph, 0);\n  int q;\n  std::cin >> q;\n  while\
    \ (q--) {\n    int u, v;\n    std::cin >> u >> v;\n    std::cout << heavy_light_decomposition.lowest_common_ancestor(u,\
    \ v) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/heavy-light_decomposition.hpp
  isVerificationFile: true
  path: test/graph/tree/heavy-light_decomposition.2.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/heavy-light_decomposition.2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/heavy-light_decomposition.2.test.cpp
- /verify/test/graph/tree/heavy-light_decomposition.2.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\u901A\u7956\u5148\
  )"
---
