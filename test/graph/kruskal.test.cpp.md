---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/union-find/union-find.hpp
    title: union-find
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/kruskal.hpp
    title: "Kruskal \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    document_title: "\u30B0\u30E9\u30D5/Kruskal \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/graph/kruskal.test.cpp\"\n/*\n * @title \u30B0\u30E9\
    \u30D5/Kruskal \u6CD5\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/kruskal.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <ranges>\n#line 7 \"include/emthrm/graph/kruskal.hpp\"\
    \n\n#line 1 \"include/emthrm/data_structure/union-find/union-find.hpp\"\n\n\n\n\
    #include <utility>\n#line 6 \"include/emthrm/data_structure/union-find/union-find.hpp\"\
    \n\nnamespace emthrm {\n\nstruct UnionFind {\n  explicit UnionFind(const int n)\
    \ : data(n, -1) {}\n\n  int root(const int ver) {\n    return data[ver] < 0 ?\
    \ ver : data[ver] = root(data[ver]);\n  }\n\n  bool unite(int u, int v) {\n  \
    \  u = root(u);\n    v = root(v);\n    if (u == v) return false;\n    if (data[u]\
    \ > data[v]) std::swap(u, v);\n    data[u] += data[v];\n    data[v] = u;\n   \
    \ return true;\n  }\n\n  bool is_same(const int u, const int v) { return root(u)\
    \ == root(v); }\n\n  int size(const int ver) { return -data[root(ver)]; }\n\n\
    \ private:\n  std::vector<int> data;\n};\n\n}  // namespace emthrm\n\n\n#line\
    \ 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 10 \"include/emthrm/graph/kruskal.hpp\"\n\nnamespace emthrm {\n\ntemplate\
    \ <typename CostType>\nCostType kruskal(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\n  const int n = graph.size();\n  const auto jv = graph | std::views::join;\n\
    \  std::vector<Edge<CostType>> edges(jv.begin(), jv.end());\n  std::ranges::sort(edges);\n\
    \  CostType res = 0;\n  UnionFind uf(n);\n  for (const Edge<CostType>& e : edges)\
    \ {\n    if (uf.unite(e.src, e.dst)) res += e.cost;\n  }\n  return res;\n}\n\n\
    }  // namespace emthrm\n\n\n#line 12 \"test/graph/kruskal.test.cpp\"\n\nint main()\
    \ {\n  int v, e;\n  std::cin >> v >> e;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> edge(v);\n  for (int i = 0; i < e; ++i) {\n    int s, t, w;\n    std::cin\
    \ >> s >> t >> w;\n    edge[s].emplace_back(s, t, w);\n    edge[t].emplace_back(t,\
    \ s, w);\n  }\n  std::cout << emthrm::kruskal(edge) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/Kruskal \u6CD5\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\n */\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/kruskal.hpp\"\n\nint main() {\n  int v, e;\n  std::cin\
    \ >> v >> e;\n  std::vector<std::vector<emthrm::Edge<long long>>> edge(v);\n \
    \ for (int i = 0; i < e; ++i) {\n    int s, t, w;\n    std::cin >> s >> t >> w;\n\
    \    edge[s].emplace_back(s, t, w);\n    edge[t].emplace_back(t, s, w);\n  }\n\
    \  std::cout << emthrm::kruskal(edge) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/kruskal.hpp
  - include/emthrm/data_structure/union-find/union-find.hpp
  isVerificationFile: true
  path: test/graph/kruskal.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/graph/kruskal.test.cpp
- /verify/test/graph/kruskal.test.cpp.html
title: "\u30B0\u30E9\u30D5/Kruskal \u6CD5"
---
