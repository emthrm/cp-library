---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/noshi_graph.hpp
    title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  - icon: ':question:'
    path: include/emthrm/graph/shortest_path/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://codeforces.com/problemset/problem/786/B
    document_title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\
      \u30C6\u30AF"
    links:
    - https://codeforces.com/problemset/problem/786/B
  bundledCode: "#line 1 \"test/graph/noshi_graph.test.cpp\"\n/*\n * @title \u30B0\u30E9\
    \u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://codeforces.com/problemset/problem/786/B\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/noshi_graph.hpp\"\
    \n\n\n\n#include <bit>\n#line 6 \"include/emthrm/graph/noshi_graph.hpp\"\n\n#line\
    \ 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 8 \"include/emthrm/graph/noshi_graph.hpp\"\n\nnamespace emthrm {\n\ntemplate\
    \ <typename CostType>\nstruct NoshiGraph {\n  std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n\n  explicit NoshiGraph(const int n)\n      : p2(std::bit_ceil(static_cast<unsigned\
    \ int>(n))) {\n    const int dbl = p2 << 1, hlf = p2 >> 1;\n    graph.resize(dbl\
    \ + p2);\n    for (int i = 1; i < hlf; ++i) {\n      add_edge(i + p2, (i << 1)\
    \ + p2);\n      add_edge(i + p2, (i << 1) + 1 + p2);\n      add_edge((i << 1)\
    \ + dbl, i + dbl);\n      add_edge((i << 1) + 1 + dbl, i + dbl);\n    }\n    for\
    \ (int src = p2 + hlf, dst = 0; dst < p2; ++src, dst += 2) {\n      add_edge(src,\
    \ dst);\n      add_edge(src, dst + 1);\n    }\n    for (int src = 0, dst = dbl\
    \ + hlf; src < p2; src += 2, ++dst) {\n      add_edge(src, dst);\n      add_edge(src\
    \ + 1, dst);\n    }\n  }\n\n  void add_edge(const int src, const int dst, const\
    \ CostType cost = 0) {\n    graph[src].emplace_back(src, dst, cost);\n  }\n\n\
    \  void add_edge(int src_l, int src_r, int dst_l, int dst_r,\n               \
    \ const CostType cost) {\n    if (src_r <= src_l || dst_r <= dst_l) [[unlikely]]\
    \ return;\n    const int src_id = graph.size(), dst_id = src_id + 1;\n    graph.emplace_back();\n\
    \    graph.emplace_back();\n    if ((dst_l += p2) & 1) add_edge(dst_id, dst_l++\
    \ - p2);\n    if ((dst_r += p2) & 1) add_edge(dst_id, --dst_r - p2);\n    for\
    \ (dst_l >>= 1, dst_r >>= 1; dst_l < dst_r; dst_l >>= 1, dst_r >>= 1) {\n    \
    \  if (dst_l & 1) add_edge(dst_id, dst_l++ + p2);\n      if (dst_r & 1) add_edge(dst_id,\
    \ --dst_r + p2);\n    }\n    add_edge(src_id, dst_id, cost);\n    if ((src_l +=\
    \ p2) & 1) add_edge(src_l++ - p2, src_id);\n    if ((src_r += p2) & 1) add_edge(--src_r\
    \ - p2, src_id);\n    for (src_l >>= 1, src_r >>= 1; src_l < src_r; src_l >>=\
    \ 1, src_r >>= 1) {\n      if (src_l & 1) add_edge(src_l++ + (p2 << 1), src_id);\n\
    \      if (src_r & 1) add_edge(--src_r + (p2 << 1), src_id);\n    }\n  }\n\n private:\n\
    \  const int p2;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <limits>\n#include <queue>\n#include <utility>\n#line 11 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 13 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename CostType>\nstruct Dijkstra {\n  const CostType inf;\n\
    \n  Dijkstra(const std::vector<std::vector<Edge<CostType>>>& graph,\n        \
    \   const CostType inf = std::numeric_limits<CostType>::max())\n      : inf(inf),\
    \ is_built(false), graph(graph) {}\n\n  std::vector<CostType> build(const int\
    \ s) {\n    is_built = true;\n    const int n = graph.size();\n    std::vector<CostType>\
    \ dist(n, inf);\n    dist[s] = 0;\n    prev.assign(n, -1);\n    std::priority_queue<std::pair<CostType,\
    \ int>,\n                        std::vector<std::pair<CostType, int>>,\n    \
    \                    std::greater<std::pair<CostType, int>>> que;\n    que.emplace(0,\
    \ s);\n    while (!que.empty()) {\n      const auto [d, ver] = que.top();\n  \
    \    que.pop();\n      if (d > dist[ver]) continue;\n      for (const Edge<CostType>&\
    \ e : graph[ver]) {\n        if (dist[ver] + e.cost < dist[e.dst]) {\n       \
    \   dist[e.dst] = dist[ver] + e.cost;\n          prev[e.dst] = ver;\n        \
    \  que.emplace(dist[e.dst], e.dst);\n        }\n      }\n    }\n    return dist;\n\
    \  }\n\n  std::vector<int> build_path(int t) const {\n    assert(is_built);\n\
    \    std::vector<int> res;\n    for (; t != -1; t = prev[t]) {\n      res.emplace_back(t);\n\
    \    }\n    std::reverse(res.begin(), res.end());\n    return res;\n  }\n\n private:\n\
    \  bool is_built;\n  std::vector<int> prev;\n  std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n};\n\n}  // namespace emthrm\n\n\n#line 13 \"test/graph/noshi_graph.test.cpp\"\
    \n\nint main() {\n  int n, q, s;\n  std::cin >> n >> q >> s;\n  --s;\n  emthrm::NoshiGraph<long\
    \ long> graph(n);\n  while (q--) {\n    int t, v;\n    std::cin >> t >> v;\n \
    \   --v;\n    if (t == 1) {\n      int u, w;\n      std::cin >> u >> w;\n    \
    \  --u;\n      graph.add_edge(v, u, w);\n    } else {\n      int l, r, w;\n  \
    \    std::cin >> l >> r >> w;\n      --l; --r;\n      if (t == 2) {\n        graph.add_edge(v,\
    \ v + 1, l, r + 1, w);\n      } else if (t == 3) {\n        graph.add_edge(l,\
    \ r + 1, v, v + 1, w);\n      }\n    }\n  }\n  emthrm::Dijkstra<long long> dijkstra(graph.graph);\n\
    \  const std::vector<long long> ans = dijkstra.build(s);\n  for (int i = 0; i\
    \ < n; ++i) {\n    std::cout << (ans[i] == dijkstra.inf ? -1 : ans[i]) << \" \\\
    n\"[i + 1 == n];\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\
    \u30C6\u30AF\n *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM\
    \ https://codeforces.com/problemset/problem/786/B\n */\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"emthrm/graph/noshi_graph.hpp\"\n#include \"emthrm/graph/shortest_path/dijkstra.hpp\"\
    \n\nint main() {\n  int n, q, s;\n  std::cin >> n >> q >> s;\n  --s;\n  emthrm::NoshiGraph<long\
    \ long> graph(n);\n  while (q--) {\n    int t, v;\n    std::cin >> t >> v;\n \
    \   --v;\n    if (t == 1) {\n      int u, w;\n      std::cin >> u >> w;\n    \
    \  --u;\n      graph.add_edge(v, u, w);\n    } else {\n      int l, r, w;\n  \
    \    std::cin >> l >> r >> w;\n      --l; --r;\n      if (t == 2) {\n        graph.add_edge(v,\
    \ v + 1, l, r + 1, w);\n      } else if (t == 3) {\n        graph.add_edge(l,\
    \ r + 1, v, v + 1, w);\n      }\n    }\n  }\n  emthrm::Dijkstra<long long> dijkstra(graph.graph);\n\
    \  const std::vector<long long> ans = dijkstra.build(s);\n  for (int i = 0; i\
    \ < n; ++i) {\n    std::cout << (ans[i] == dijkstra.inf ? -1 : ans[i]) << \" \\\
    n\"[i + 1 == n];\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/noshi_graph.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/shortest_path/dijkstra.hpp
  isVerificationFile: true
  path: test/graph/noshi_graph.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/graph/noshi_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/noshi_graph.test.cpp
- /verify/test/graph/noshi_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
---
