---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC (minimum cost $s$-$t$-flow)\
      \ \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5 (successive shortest path algorithm)\
      \ \u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
      \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\
      \u53CD\u5FA9\u6CD5\u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#line 1 \"test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\
    \u5FA9\u6CD5\u7248\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T, typename U>\nstruct MinimumCostSTFlow {\n\
    \  struct Edge {\n    int dst, rev;\n    T cap;\n    U cost;\n    explicit Edge(const\
    \ int dst, const T cap, const U cost, const int rev)\n        : dst(dst), rev(rev),\
    \ cap(cap), cost(cost) {}\n  };\n\n  const U uinf;\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  explicit MinimumCostSTFlow(const int n,\n                      \
    \       const U uinf = std::numeric_limits<U>::max())\n      : uinf(uinf), graph(n),\
    \ tinf(std::numeric_limits<T>::max()), n(n),\n        has_negative_edge(false),\
    \ prev_v(n, -1), prev_e(n, -1), dist(n),\n        potential(n, 0) {}\n\n  void\
    \ add_edge(const int src, const int dst, const T cap, const U cost) {\n    has_negative_edge\
    \ |= cost < 0;\n    graph[src].emplace_back(dst, cap, cost, graph[dst].size());\n\
    \    graph[dst].emplace_back(src, 0, -cost, graph[src].size() - 1);\n  }\n\n \
    \ U solve(const int s, const int t, T flow) {\n    if (flow == 0) [[unlikely]]\
    \ return 0;\n    U res = 0;\n    has_negative_edge ? bellman_ford(s) : dijkstra(s);\n\
    \    while (true) {\n      if (dist[t] == uinf) return uinf;\n      res += calc(s,\
    \ t, &flow);\n      if (flow == 0) break;\n      dijkstra(s);\n    }\n    return\
    \ res;\n  }\n\n  U solve(const int s, const int t) {\n    U res = 0;\n    T flow\
    \ = tinf;\n    bellman_ford(s);\n    while (potential[t] < 0 && dist[t] != uinf)\
    \ {\n      res += calc(s, t, &flow);\n      dijkstra(s);\n    }\n    return res;\n\
    \  }\n\n  std::pair<T, U> minimum_cost_maximum_flow(const int s, const int t,\n\
    \                                            const T flow) {\n    if (flow ==\
    \ 0) [[unlikely]] return {0, 0};\n    T f = flow;\n    U cost = 0;\n    has_negative_edge\
    \ ? bellman_ford(s) : dijkstra(s);\n    while (dist[t] != uinf) {\n      cost\
    \ += calc(s, t, &f);\n      if (f == 0) break;\n      dijkstra(s);\n    }\n  \
    \  return {flow - f, cost};\n  }\n\n private:\n  const T tinf;\n  const int n;\n\
    \  bool has_negative_edge;\n  std::vector<int> prev_v, prev_e;\n  std::vector<U>\
    \ dist, potential;\n  std::priority_queue<std::pair<U, int>, std::vector<std::pair<U,\
    \ int>>,\n                      std::greater<std::pair<U, int>>> que;\n\n  void\
    \ bellman_ford(const int s) {\n    std::fill(dist.begin(), dist.end(), uinf);\n\
    \    dist[s] = 0;\n    bool is_updated = true;\n    for (int step = 0; step <\
    \ n && is_updated; ++step) {\n      is_updated = false;\n      for (int i = 0;\
    \ i < n; ++i) {\n        if (dist[i] == uinf) continue;\n        for (int j =\
    \ 0; std::cmp_less(j, graph[i].size()); ++j) {\n          const Edge& e = graph[i][j];\n\
    \          if (e.cap > 0 && dist[e.dst] > dist[i] + e.cost) {\n            dist[e.dst]\
    \ = dist[i] + e.cost;\n            prev_v[e.dst] = i;\n            prev_e[e.dst]\
    \ = j;\n            is_updated = true;\n          }\n        }\n      }\n    }\n\
    \    assert(!is_updated);\n    for (int i = 0; i < n; ++i) {\n      if (dist[i]\
    \ != uinf) potential[i] += dist[i];\n    }\n  }\n\n  void dijkstra(const int s)\
    \ {\n    std::fill(dist.begin(), dist.end(), uinf);\n    dist[s] = 0;\n    que.emplace(0,\
    \ s);\n    while (!que.empty()) {\n      const auto [d, ver] = que.top();\n  \
    \    que.pop();\n      if (dist[ver] < d) continue;\n      for (int i = 0; std::cmp_less(i,\
    \ graph[ver].size()); ++i) {\n        const Edge& e = graph[ver][i];\n       \
    \ const U nxt = dist[ver] + e.cost + potential[ver] - potential[e.dst];\n    \
    \    if (e.cap > 0 && dist[e.dst] > nxt) {\n          dist[e.dst] = nxt;\n   \
    \       prev_v[e.dst] = ver;\n          prev_e[e.dst] = i;\n          que.emplace(dist[e.dst],\
    \ e.dst);\n        }\n      }\n    }\n    for (int i = 0; i < n; ++i) {\n    \
    \  if (dist[i] != uinf) potential[i] += dist[i];\n    }\n  }\n\n  U calc(const\
    \ int s, const int t, T* flow) {\n    T f = *flow;\n    for (int v = t; v != s;\
    \ v = prev_v[v]) {\n      f = std::min(f, graph[prev_v[v]][prev_e[v]].cap);\n\
    \    }\n    *flow -= f;\n    for (int v = t; v != s; v = prev_v[v]) {\n      Edge&\
    \ e = graph[prev_v[v]][prev_e[v]];\n      e.cap -= f;\n      graph[v][e.rev].cap\
    \ += f;\n    }\n    return potential[t] * f;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 10 \"test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp\"\
    \n\nint main() {\n  int v, e, f;\n  std::cin >> v >> e >> f;\n  emthrm::MinimumCostSTFlow<int,\
    \ int> minimum_cost_flow(v);\n  while (e--) {\n    int u, v, c, d;\n    std::cin\
    \ >> u >> v >> c >> d;\n    minimum_cost_flow.add_edge(u, v, c, d);\n  }\n  const\
    \ int ans = minimum_cost_flow.solve(0, v - 1, f);\n  std::cout << (ans == minimum_cost_flow.uinf\
    \ ? -1 : ans) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\
    \u5FA9\u6CD5\u7248\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\nint main() {\n  int v, e, f;\n  std::cin >> v >> e >> f;\n  emthrm::MinimumCostSTFlow<int,\
    \ int> minimum_cost_flow(v);\n  while (e--) {\n    int u, v, c, d;\n    std::cin\
    \ >> u >> v >> c >> d;\n    minimum_cost_flow.add_edge(u, v, c, d);\n  }\n  const\
    \ int ans = minimum_cost_flow.solve(0, v - 1, f);\n  std::cout << (ans == minimum_cost_flow.uinf\
    \ ? -1 : ans) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: true
  path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 16:52:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
  \u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5\
  \u7248"
---
