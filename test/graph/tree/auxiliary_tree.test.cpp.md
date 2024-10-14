---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/tree/auxiliary_tree.hpp
    title: "\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\u306E\u6700\u5C0F\
      \u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\u6728\u3092\u5727\
      \u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\u6728"
  - icon: ':question:'
    path: include/emthrm/graph/tree/euler_tour_technique.hpp
    title: Euler tour technique
  - icon: ':question:'
    path: include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (lowest common ancestor) Euler tour\
      \ technique \u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/typical90/tasks/typical90_ai
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u6307\u5B9A\u3055\u308C\u305F\u9802\
      \u70B9\u305F\u3061\u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\
      \u4FDD\u3063\u3066\u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\
      \u52A9\u7684\u306A\u6728"
    links:
    - https://atcoder.jp/contests/typical90/tasks/typical90_ai
  bundledCode: "#line 1 \"test/graph/tree/auxiliary_tree.test.cpp\"\n/*\n * @title\
    \ \u30B0\u30E9\u30D5/\u6728/\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\
    \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
    \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\
    \u6728\n *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/typical90/tasks/typical90_ai\n\
    \ */\n\n#include <iostream>\n#include <ranges>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/tree/auxiliary_tree.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <iterator>\n#line 7 \"include/emthrm/graph/tree/auxiliary_tree.hpp\"\n\
    #include <utility>\n#line 9 \"include/emthrm/graph/tree/auxiliary_tree.hpp\"\n\
    \n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef\
    \ EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp\"\
    \n\n\n\n#line 7 \"include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp\"\
    \n\n#line 1 \"include/emthrm/data_structure/sparse_table.hpp\"\n\n\n\n#line 5\
    \ \"include/emthrm/data_structure/sparse_table.hpp\"\n#include <bit>\n#include\
    \ <cassert>\n#include <functional>\n#line 9 \"include/emthrm/data_structure/sparse_table.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename Band>\nstruct SparseTable {\n  using\
    \ BinOp = std::function<Band(Band, Band)>;\n\n  SparseTable() = default;\n\n \
    \ explicit SparseTable(const std::vector<Band>& a, const BinOp bin_op) {\n   \
    \ init(a, bin_op);\n  }\n\n  void init(const std::vector<Band>& a, const BinOp\
    \ bin_op_) {\n    bin_op = bin_op_;\n    const int n = a.size();\n    assert(n\
    \ > 0);\n    lg.assign(n + 1, 0);\n    for (int i = 2; i <= n; ++i) {\n      lg[i]\
    \ = lg[i >> 1] + 1;\n    }\n    const int table_h = std::countr_zero(std::bit_floor(a.size()))\
    \ + 1;\n    data.assign(table_h, std::vector<Band>(n));\n    std::copy(a.begin(),\
    \ a.end(), data.front().begin());\n    for (int i = 1; i < table_h; ++i) {\n \
    \     for (int j = 0; j + (1 << i) <= n; ++j) {\n        data[i][j] = bin_op(data[i\
    \ - 1][j], data[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n\n  Band query(const\
    \ int left, const int right) const {\n    assert(left < right);\n    const int\
    \ h = lg[right - left];\n    return bin_op(data[h][left], data[h][right - (1 <<\
    \ h)]);\n  }\n\n private:\n  BinOp bin_op;\n  std::vector<int> lg;\n  std::vector<std::vector<Band>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/tree/euler_tour_technique.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/graph/tree/euler_tour_technique.hpp\"\n\n#line\
    \ 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 7 \"include/emthrm/graph/tree/euler_tour_technique.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename CostType>\nstruct EulerTourTechnique {\n  std::vector<int>\
    \ preorder, depth, left, right, down, up;\n  std::vector<CostType> tour;\n\n \
    \ explicit EulerTourTechnique(\n      const std::vector<std::vector<Edge<CostType>>>\
    \ &graph, const int root = 0)\n      : graph(graph) {\n    const int n = graph.size();\n\
    \    left.resize(n);\n    right.resize(n);\n    down.assign(n, -1);\n    up.assign(n,\
    \ (n - 1) << 1);\n    dfs(-1, root, 0);\n  }\n\n  template <typename Fn>\n  void\
    \ update_v(const int ver, const Fn f) const {\n    f(left[ver], right[ver] + 1);\n\
    \  }\n\n  template <typename T, typename Fn>\n  T query_v(const int ver, const\
    \ Fn f) const {\n    return f(left[ver], right[ver] + 1);\n  }\n\n  template <typename\
    \ T, typename Fn>\n  T query_e(const int u, const int v, const Fn f) const {\n\
    \    return f(down[u] + 1, down[v] + 1);\n  }\n\n  template <typename Fn>\n  void\
    \ update_subtree_e(const int ver, const Fn f) const {\n    f(down[ver] + 1, up[ver]);\n\
    \  }\n\n  template <typename T, typename Fn>\n  T query_subtree_e(const int ver,\
    \ const Fn f) const {\n    return f(down[ver] + 1, up[ver]);\n  }\n\n private:\n\
    \  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  void dfs(const int\
    \ par, const int ver, const int cur_depth) {\n    left[ver] = preorder.size();\n\
    \    preorder.emplace_back(ver);\n    depth.emplace_back(cur_depth);\n    for\
    \ (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst != par) {\n      \
    \  down[e.dst] = tour.size();\n        tour.emplace_back(e.cost);\n        dfs(ver,\
    \ e.dst, cur_depth + 1);\n        preorder.emplace_back(ver);\n        depth.emplace_back(cur_depth);\n\
    \        up[e.dst] = tour.size();\n        tour.emplace_back(-e.cost);\n     \
    \ }\n    }\n    right[ver] = preorder.size() - 1;\n  }\n};\n\n}  // namespace\
    \ emthrm\n\n\n#line 11 \"include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct LowestCommonAncestor\
    \ : EulerTourTechnique<CostType> {\n  explicit LowestCommonAncestor(\n      const\
    \ std::vector<std::vector<Edge<CostType>>>& graph,\n      const int root = 0)\n\
    \      : EulerTourTechnique<CostType>(graph, root) {\n    const int n = this->preorder.size();\n\
    \    std::vector<std::pair<int, int>> nodes(n);\n    for (int i = 0; i < n; ++i)\
    \ {\n      nodes[i] = {this->depth[i], this->preorder[i]};\n    }\n    sparse_table.init(\n\
    \        nodes,\n        [](const std::pair<int, int>& a, const std::pair<int,\
    \ int>& b)\n            -> std::pair<int, int> {\n          return std::min(a,\
    \ b);\n        });\n  }\n\n  int query(int u, int v) const {\n    u = this->left[u];\n\
    \    v = this->left[v];\n    if (u > v) std::swap(u, v);\n    return sparse_table.query(u,\
    \ v + 1).second;\n  }\n\n private:\n  SparseTable<std::pair<int, int>> sparse_table;\n\
    };\n\n}  // namespace emthrm\n\n\n#line 12 \"include/emthrm/graph/tree/auxiliary_tree.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct AuxiliaryTree {\n\
    \  LowestCommonAncestor<CostType> euler_tour;\n\n  explicit AuxiliaryTree(\n \
    \     const std::vector<std::vector<Edge<CostType>>>& graph, const int root =\
    \ 0)\n      : euler_tour(graph, root), depth(graph.size(), 0) {\n    const auto\
    \ dfs = [this, &graph](\n        auto dfs, const int par, const int ver) -> void\
    \ {\n      for (const Edge<CostType>& e : graph[ver]) {\n        if (e.dst ==\
    \ par) continue;\n        depth[e.dst] = depth[ver] + e.cost;\n        dfs(dfs,\
    \ ver, e.dst);\n      }\n    };\n    dfs(dfs, -1, root);\n  }\n\n  std::pair<std::vector<std::vector<Edge<CostType>>>,\n\
    \            std::vector<int>> query(std::vector<int> vertices) const {\n    if\
    \ (vertices.empty()) [[unlikely]] return {};\n    static std::vector<int> mp(depth.size(),\
    \ -1);\n    std::ranges::sort(vertices, {},\n                      [&](const int\
    \ v) -> int { return euler_tour.left[v]; });\n    std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n    std::vector<int> inv;\n    const auto add_vertex = [this, &graph,\
    \ &inv](const int v) -> void {\n      mp[v] = graph.size();\n      graph.emplace_back();\n\
    \      inv.emplace_back(v);\n    };\n    const auto add_edge = [this, &graph](int\
    \ u, int v) -> void {\n      const CostType cost = depth[v] - depth[u];\n    \
    \  u = mp[u];\n      v = mp[v];\n      graph[u].emplace_back(u, v, cost);\n  \
    \    graph[v].emplace_back(v, u, cost);\n    };\n    add_vertex(vertices.front());\n\
    \    std::vector<int> stck{vertices.front()};\n    for (const int i : std::views::iota(1,\
    \ std::ssize(vertices))) {\n      const int l = euler_tour.query(vertices[i -\
    \ 1], vertices[i]);\n      if (mp[l] == -1) add_vertex(l);\n      if (l != vertices[i\
    \ - 1]) {\n        const int depth_l = euler_tour.depth[euler_tour.left[l]];\n\
    \        int cur = stck.back();\n        stck.pop_back();\n        while (!stck.empty()\
    \ &&\n               euler_tour.depth[euler_tour.left[stck.back()]] > depth_l)\
    \ {\n          add_edge(stck.back(), cur);\n          cur = stck.back();\n   \
    \       stck.pop_back();\n        }\n        add_edge(l, cur);\n        if (stck.empty()\
    \ || stck.back() != l) stck.emplace_back(l);\n      }\n      add_vertex(vertices[i]);\n\
    \      stck.emplace_back(vertices[i]);\n    }\n    for (; stck.size() >= 2; stck.pop_back())\
    \ {\n      add_edge(stck.end()[-2], stck.back());\n    }\n    for (const int v\
    \ : inv) mp[v] = -1;\n    return {graph, inv};\n  }\n\n private:\n  std::vector<CostType>\
    \ depth;\n};\n\n}  // namespace emthrm\n\n\n#line 14 \"test/graph/tree/auxiliary_tree.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ graph(n);\n  for (const int i : std::views::iota(0, n - 1)) {\n    int a, b;\n\
    \    std::cin >> a >> b;\n    --a; --b;\n    graph[a].emplace_back(a, b, 1);\n\
    \    graph[b].emplace_back(b, a, 1);\n  }\n  const emthrm::AuxiliaryTree<int>\
    \ auxiliary_tree(graph);\n  int q;\n  std::cin >> q;\n  while (q--) {\n    int\
    \ k;\n    std::cin >> k;\n    std::vector<int> v(k);\n    for (int& v_i : v) std::cin\
    \ >> v_i, --v_i;\n    int ans = 0;\n    for (const std::vector<emthrm::Edge<int>>&\
    \ edges\n         : auxiliary_tree.query(v).first) {\n      for (const emthrm::Edge<int>&\
    \ e : edges) ans += e.cost;\n    }\n    std::cout << ans / 2 << '\\n';\n  }\n\
    \  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6728/\u6307\u5B9A\u3055\u308C\u305F\u9802\
    \u70B9\u305F\u3061\u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\
    \u4FDD\u3063\u3066\u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\
    \u52A9\u7684\u306A\u6728\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/typical90/tasks/typical90_ai\n */\n\n#include\
    \ <iostream>\n#include <ranges>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/tree/auxiliary_tree.hpp\"\n\nint main() {\n  int n;\n\
    \  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<int>>> graph(n);\n \
    \ for (const int i : std::views::iota(0, n - 1)) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    --a; --b;\n    graph[a].emplace_back(a, b, 1);\n    graph[b].emplace_back(b,\
    \ a, 1);\n  }\n  const emthrm::AuxiliaryTree<int> auxiliary_tree(graph);\n  int\
    \ q;\n  std::cin >> q;\n  while (q--) {\n    int k;\n    std::cin >> k;\n    std::vector<int>\
    \ v(k);\n    for (int& v_i : v) std::cin >> v_i, --v_i;\n    int ans = 0;\n  \
    \  for (const std::vector<emthrm::Edge<int>>& edges\n         : auxiliary_tree.query(v).first)\
    \ {\n      for (const emthrm::Edge<int>& e : edges) ans += e.cost;\n    }\n  \
    \  std::cout << ans / 2 << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/auxiliary_tree.hpp
  - include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp
  - include/emthrm/data_structure/sparse_table.hpp
  - include/emthrm/graph/tree/euler_tour_technique.hpp
  isVerificationFile: true
  path: test/graph/tree/auxiliary_tree.test.cpp
  requiredBy: []
  timestamp: '2024-08-10 05:09:34+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/graph/tree/auxiliary_tree.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/auxiliary_tree.test.cpp
- /verify/test/graph/tree/auxiliary_tree.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\
  \u3061\u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
  \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\u6728"
---
