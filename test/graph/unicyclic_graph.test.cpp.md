---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/unicyclic_graph.hpp
    title: unicyclic graph / 1-tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/1254
    document_title: "\u30B0\u30E9\u30D5/unicyclic graph"
    links:
    - https://yukicoder.me/problems/no/1254
  bundledCode: "#line 1 \"test/graph/unicyclic_graph.test.cpp\"\n/*\n * @title \u30B0\
    \u30E9\u30D5/unicyclic graph\n *\n * verification-helper: PROBLEM https://yukicoder.me/problems/no/1254\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <utility>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title\
    \ \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/unicyclic_graph.hpp\"\
    \n\n\n\n#include <cassert>\n#include <iterator>\n#include <queue>\n#line 8 \"\
    include/emthrm/graph/unicyclic_graph.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 10 \"include/emthrm/graph/unicyclic_graph.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct UnicyclicGraph\
    \ {\n  std::vector<bool> is_in_loop;\n  std::vector<int> belong, mapping;\n  std::vector<Edge<CostType>>\
    \ loop;\n  std::vector<std::vector<int>> invs;\n  std::vector<std::vector<std::vector<Edge<CostType>>>>\
    \ forest;\n\n  explicit UnicyclicGraph(const int n)\n      : is_in_loop(n, false),\
    \ belong(n, -1), mapping(n, -1), n(n), graph(n) {}\n\n  void add_edge(const int\
    \ src, const int dst, const CostType cost = 0) {\n    const int id = srcs.size();\n\
    \    srcs.emplace_back(src);\n    dsts.emplace_back(dst);\n    costs.emplace_back(cost);\n\
    \    graph[src].emplace_back(id);\n    if (dst != src) [[likely]] graph[dst].emplace_back(id);\n\
    \  }\n\n  void build() {\n    dfs(-1, 0);\n    std::queue<int> que;\n    for (const\
    \ Edge<CostType>& e : loop) {\n      const int root = e.src, forest_id = forest.size();\n\
    \      belong[root] = forest_id;\n      mapping[root] = 0;\n      std::vector<int>\
    \ inv{root};\n      std::vector<std::vector<Edge<CostType>>> tree(1);\n      que.emplace(root);\n\
    \      while (!que.empty()) {\n        const int ver = que.front();\n        que.pop();\n\
    \        for (const int id : graph[ver]) {\n          const int dst = destination(id,\
    \ ver);\n          if (belong[dst] == -1 && !is_in_loop[dst]) {\n            const\
    \ int idx = tree.size();\n            belong[dst] = forest_id;\n            mapping[dst]\
    \ = idx;\n            inv.emplace_back(dst);\n            tree[mapping[ver]].emplace_back(mapping[ver],\
    \ idx, costs[id]);\n            tree.emplace_back(std::vector<Edge<CostType>>{\n\
    \                Edge<CostType>(idx, mapping[ver], costs[id])});\n           \
    \ que.emplace(dst);\n          }\n        }\n      }\n      if (inv.size() ==\
    \ 1) {\n        belong[root] = mapping[root] = -1;\n      } else {\n        invs.emplace_back(inv);\n\
    \        forest.emplace_back(tree);\n      }\n    }\n  }\n\n private:\n  const\
    \ int n;\n  std::vector<int> srcs, dsts;\n  std::vector<CostType> costs;\n  std::vector<std::vector<int>>\
    \ graph;\n\n  int destination(const int id, const int s) const {\n    return (srcs[id]\
    \ == s ? dsts : srcs)[id];\n  }\n\n  bool dfs(const int prev_id, const int ver)\
    \ {\n    is_in_loop[ver] = true;\n    for (const int id : graph[ver]) {\n    \
    \  if (id == prev_id) continue;\n      const int dst = destination(id, ver);\n\
    \      loop.emplace_back(ver, dst, costs[id]);\n      if (is_in_loop[dst]) {\n\
    \        for (int i = loop.size() - 1; i >= 0; --i) {\n          if (loop[i].src\
    \ == dst) {\n            for (int j = 0; j < i; ++j) {\n              is_in_loop[loop[j].src]\
    \ = false;\n            }\n            loop.erase(loop.begin(), std::next(loop.begin(),\
    \ i));\n            return true;\n          }\n        }\n        assert(false);\n\
    \      }\n      if (dfs(id, dst)) return true;\n      loop.pop_back();\n    }\n\
    \    is_in_loop[ver] = false;\n    return false;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 15 \"test/graph/unicyclic_graph.test.cpp\"\n\nint main() {\n  int n;\n\
    \  std::cin >> n;\n  std::map<std::pair<int, int>, int> edges;\n  emthrm::UnicyclicGraph<bool>\
    \ namori(n);\n  for (int i = 0; i < n; ++i) {\n    int a, b;\n    std::cin >>\
    \ a >> b;\n    --a; --b;\n    edges[std::minmax(a, b)] = i;\n    namori.add_edge(a,\
    \ b, false);\n  }\n  namori.build();\n  std::vector<bool> bridge(n, false);\n\
    \  for (const emthrm::Edge<bool>& e : namori.loop) {\n    bridge[edges[std::minmax(e.src,\
    \ e.dst)]] = true;\n  }\n  std::vector<int> p;\n  for (int i = 0; i < n; ++i)\
    \ {\n    if (bridge[i]) p.emplace_back(i);\n  }\n  const int k = p.size();\n \
    \ std::cout << k << '\\n';\n  for (int i = 0; i < k; ++i) {\n    std::cout <<\
    \ p[i] + 1 << \" \\n\"[i + 1 == k];\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/unicyclic graph\n *\n * verification-helper:\
    \ PROBLEM https://yukicoder.me/problems/no/1254\n */\n\n#include <algorithm>\n\
    #include <iostream>\n#include <map>\n#include <utility>\n#include <vector>\n\n\
    #include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/unicyclic_graph.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::map<std::pair<int, int>,\
    \ int> edges;\n  emthrm::UnicyclicGraph<bool> namori(n);\n  for (int i = 0; i\
    \ < n; ++i) {\n    int a, b;\n    std::cin >> a >> b;\n    --a; --b;\n    edges[std::minmax(a,\
    \ b)] = i;\n    namori.add_edge(a, b, false);\n  }\n  namori.build();\n  std::vector<bool>\
    \ bridge(n, false);\n  for (const emthrm::Edge<bool>& e : namori.loop) {\n   \
    \ bridge[edges[std::minmax(e.src, e.dst)]] = true;\n  }\n  std::vector<int> p;\n\
    \  for (int i = 0; i < n; ++i) {\n    if (bridge[i]) p.emplace_back(i);\n  }\n\
    \  const int k = p.size();\n  std::cout << k << '\\n';\n  for (int i = 0; i <\
    \ k; ++i) {\n    std::cout << p[i] + 1 << \" \\n\"[i + 1 == k];\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/unicyclic_graph.hpp
  isVerificationFile: true
  path: test/graph/unicyclic_graph.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/unicyclic_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/unicyclic_graph.test.cpp
- /verify/test/graph/unicyclic_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/unicyclic graph"
---
