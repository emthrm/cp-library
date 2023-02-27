---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
    title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
    document_title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
  bundledCode: "#line 1 \"test/graph/tree/heavy-light_decomposition.1.test.cpp\"\n\
    /*\n * @title \u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\n */\n\
    \n#include <functional>\n#include <iostream>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename Abelian>\nstruct FenwickTreeSupportingRangeAddQuery\
    \ {\n  explicit FenwickTreeSupportingRangeAddQuery(\n      const int n_, const\
    \ Abelian ID = 0)\n      : n(n_ + 1), ID(ID) {\n    data_const.assign(n, ID);\n\
    \    data_linear.assign(n, ID);\n  }\n\n  void add(int left, const int right,\
    \ const Abelian val) {\n    if (right < ++left) [[unlikely]] return;\n    for\
    \ (int i = left; i < n; i += i & -i) {\n      data_const[i] -= val * (left - 1);\n\
    \      data_linear[i] += val;\n    }\n    for (int i = right + 1; i < n; i +=\
    \ i & -i) {\n      data_const[i] += val * right;\n      data_linear[i] -= val;\n\
    \    }\n  }\n\n  Abelian sum(const int idx) const {\n    Abelian res = ID;\n \
    \   for (int i = idx; i > 0; i -= i & -i) {\n      res += data_linear[i];\n  \
    \  }\n    res *= idx;\n    for (int i = idx; i > 0; i -= i & -i) {\n      res\
    \ += data_const[i];\n    }\n    return res;\n  }\n\n  Abelian sum(const int left,\
    \ const int right) const {\n    return left < right ? sum(right) - sum(left) :\
    \ ID;\n  }\n\n  Abelian operator[](const int idx) const { return sum(idx, idx\
    \ + 1); }\n\n private:\n  const int n;\n  const Abelian ID;\n  std::vector<Abelian>\
    \ data_const, data_linear;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
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
    \n\n#line 14 \"test/graph/tree/heavy-light_decomposition.1.test.cpp\"\n\nint main()\
    \ {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    graph[a].emplace_back(a, b, 0);\n    graph[b].emplace_back(b,\
    \ a, 0);\n  }\n  emthrm::HeavyLightDecomposition<long long>\n      heavy_light_decomposition(graph,\
    \ 0);\n  emthrm::FenwickTreeSupportingRangeAddQuery<long long> bit(n - 1);\n \
    \ while (q--) {\n    int type;\n    std::cin >> type;\n    if (type == 0) {\n\
    \      int u, v;\n      std::cin >> u >> v;\n      std::cout << heavy_light_decomposition.query_e(\n\
    \                       u, v,\n                       [&bit](const int l, const\
    \ int r) -> long long {\n                         return bit.sum(l, r);\n    \
    \                   },\n                       std::plus<long long>(), 0LL)\n\
    \                << '\\n';\n    } else if (type == 1) {\n      int v, x;\n   \
    \   std::cin >> v >> x;\n      heavy_light_decomposition.update_subtree_e(\n \
    \         v,\n          [&bit, x](const int l, const int r) -> void {\n      \
    \      return bit.add(l, r, x);\n          });\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\n */\n\
    \n#include <functional>\n#include <iostream>\n#include <vector>\n\n#include \"\
    emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/heavy-light_decomposition.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    graph[a].emplace_back(a, b, 0);\n    graph[b].emplace_back(b,\
    \ a, 0);\n  }\n  emthrm::HeavyLightDecomposition<long long>\n      heavy_light_decomposition(graph,\
    \ 0);\n  emthrm::FenwickTreeSupportingRangeAddQuery<long long> bit(n - 1);\n \
    \ while (q--) {\n    int type;\n    std::cin >> type;\n    if (type == 0) {\n\
    \      int u, v;\n      std::cin >> u >> v;\n      std::cout << heavy_light_decomposition.query_e(\n\
    \                       u, v,\n                       [&bit](const int l, const\
    \ int r) -> long long {\n                         return bit.sum(l, r);\n    \
    \                   },\n                       std::plus<long long>(), 0LL)\n\
    \                << '\\n';\n    } else if (type == 1) {\n      int v, x;\n   \
    \   std::cin >> v >> x;\n      heavy_light_decomposition.update_subtree_e(\n \
    \         v,\n          [&bit, x](const int l, const int r) -> void {\n      \
    \      return bit.add(l, r, x);\n          });\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/heavy-light_decomposition.hpp
  isVerificationFile: true
  path: test/graph/tree/heavy-light_decomposition.1.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/heavy-light_decomposition.1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/heavy-light_decomposition.1.test.cpp
- /verify/test/graph/tree/heavy-light_decomposition.1.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
---
