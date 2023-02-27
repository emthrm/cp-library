---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528 $\boldsymbol{b}$-\u30D5\u30ED\u30FC (minimum\
      \ cost $\boldsymbol{b}$-flow) \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5 (successive\
      \ shortest path algorithm) \u7248"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp
    title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\
      \u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
      \u6D41/\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\
      \u6D41"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230
  bundledCode: "#line 1 \"test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\
    \u6D41\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <limits>\n#include\
    \ <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\
    \n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include\
    \ <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge\
    \ {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src, const\
    \ int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\
    \n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp\"\
    \n#include <cassert>\n#include <functional>\n#line 8 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp\"\
    \n#include <numeric>\n#include <queue>\n#include <utility>\n#line 12 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T, typename U>\nstruct MinimumCostBFlow\
    \ {\n  struct Edge {\n    int dst, rev;\n    T cap;\n    U cost;\n    explicit\
    \ Edge(const int dst, const T cap, const U cost, const int rev)\n        : dst(dst),\
    \ rev(rev), cap(cap), cost(cost) {}\n  };\n\n  const U uinf;\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  explicit MinimumCostBFlow(const int n,\n                       \
    \     const U uinf = std::numeric_limits<U>::max())\n      : uinf(uinf), graph(n\
    \ + 2), n(n), res(0), b(n + 2, 0) {}\n\n  void add_edge(int src, int dst, const\
    \ T cap, U cost) {\n    if (cost < 0) {\n      b[src] -= cap;\n      b[dst] +=\
    \ cap;\n      res += cost * cap;\n      std::swap(src, dst);\n      cost = -cost;\n\
    \    }\n    graph[src].emplace_back(dst, cap, cost, graph[dst].size());\n    graph[dst].emplace_back(src,\
    \ 0, -cost, graph[src].size() - 1);\n  }\n\n  void supply_or_demand(const int\
    \ ver, const T amount) { b[ver] += amount; }\n\n  U solve() {\n    assert(std::reduce(b.begin(),\
    \ b.end(), static_cast<T>(0)) == 0);\n    T flow = 0;\n    for (int i = 0; i <\
    \ n; ++i) {\n      if (b[i] > 0) {\n        add_edge(n, i, b[i], 0);\n       \
    \ flow += b[i];\n      } else if (b[i] < 0) {\n        add_edge(i, n + 1, -b[i],\
    \ 0);\n      }\n    }\n    std::vector<int> prev_v(n + 2, -1), prev_e(n + 2, -1);\n\
    \    std::vector<U> dist(n + 2), potential(n + 2, 0);\n    std::priority_queue<std::pair<U,\
    \ int>, std::vector<std::pair<U, int>>,\n                        std::greater<std::pair<U,\
    \ int>>> que;\n    while (flow > 0) {\n      std::fill(dist.begin(), dist.end(),\
    \ uinf);\n      dist[n] = 0;\n      que.emplace(0, n);\n      while (!que.empty())\
    \ {\n        const auto [d, ver] = que.top();\n        que.pop();\n        if\
    \ (d > dist[ver]) continue;\n        for (int i = 0; std::cmp_less(i, graph[ver].size());\
    \ ++i) {\n          const Edge& e = graph[ver][i];\n          const U nxt = dist[ver]\
    \ + e.cost + potential[ver] - potential[e.dst];\n          if (e.cap > 0 && dist[e.dst]\
    \ > nxt) {\n            dist[e.dst] = nxt;\n            prev_v[e.dst] = ver;\n\
    \            prev_e[e.dst] = i;\n            que.emplace(dist[e.dst], e.dst);\n\
    \          }\n        }\n      }\n      if (dist[n + 1] == uinf) return uinf;\n\
    \      for (int i = 0; i < n + 2; ++i) {\n        if (dist[i] != uinf) potential[i]\
    \ += dist[i];\n      }\n      T f = flow;\n      for (int v = n + 1; v != n; v\
    \ = prev_v[v]) {\n        f = std::min(f, graph[prev_v[v]][prev_e[v]].cap);\n\
    \      }\n      flow -= f;\n      res += potential[n + 1] * f;\n      for (int\
    \ v = n + 1; v != n; v = prev_v[v]) {\n        Edge& e = graph[prev_v[v]][prev_e[v]];\n\
    \        e.cap -= f;\n        graph[v][e.rev].cap += f;\n      }\n    }\n    return\
    \ res;\n  }\n\n  U solve(const int s, const int t, const T flow) {\n    supply_or_demand(s,\
    \ flow);\n    supply_or_demand(t, -flow);\n    return solve();\n  }\n\n private:\n\
    \  int n;\n  U res;\n  std::vector<T> b;\n};\n\n}  // namespace emthrm\n\n\n#line\
    \ 1 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp\"\
    \n\n\n\n#include <concepts>\n#line 7 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <template <typename, typename> class C, typename\
    \ T, typename U>\nrequires requires (C<T, U> mcf) {\n  {mcf.add_edge(std::declval<int>(),\
    \ std::declval<int>(),\n                std::declval<T>(), std::declval<U>())}\n\
    \      -> std::same_as<void>;\n  {mcf.solve(std::declval<int>(), std::declval<int>(),\
    \ std::declval<T>())}\n      -> std::same_as<U>;\n}\nstruct MinimumCostFlowWithLowerBoundConstraint\
    \ {\n  const U uinf;\n\n  explicit MinimumCostFlowWithLowerBoundConstraint(\n\
    \      const int n, const U m, const U uinf = std::numeric_limits<U>::max())\n\
    \      : uinf(uinf), m(m), sum_lb(0), mcf(n, uinf) {}\n\n  void add_edge(const\
    \ int src, const int dst, const T lb, const T ub,\n                const U cost)\
    \ {\n    mcf.add_edge(src, dst, ub - lb, cost);\n    mcf.add_edge(src, dst, lb,\
    \ cost - m);\n    sum_lb += lb;\n  }\n\n  U solve(const int s, const int t, const\
    \ T flow) {\n    const U tmp = mcf.solve(s, t, flow);\n    return tmp == uinf\
    \ ? uinf : tmp + m * sum_lb;\n  }\n\n private:\n  const U m;\n  T sum_lb;\n  C<T,\
    \ U> mcf;\n};\n\n}  // namespace emthrm\n\n\n#line 15 \"test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp\"\
    \n\nint main() {\n  constexpr int INF = std::numeric_limits<int>::max();\n  int\
    \ n, m;\n  std::cin >> n >> m;\n  emthrm::MinimumCostFlowWithLowerBoundConstraint<\n\
    \      emthrm::MinimumCostBFlow, long long, long long>\n          lower_bound_constraint(n,\
    \ INF);\n  std::vector<std::vector<emthrm::Edge<int>>> graph(n);\n  while (m--)\
    \ {\n    int x, y, s;\n    std::cin >> x >> y >> s;\n    lower_bound_constraint.add_edge(y,\
    \ x, 1, INF, -s);\n    graph[x].emplace_back(x, y, s);\n  }\n  std::vector<long\
    \ long> dp(n, 0);\n  for (int i = n - 2; i >= 0; --i) {\n    for (const emthrm::Edge<int>&\
    \ e : graph[i]) {\n      dp[i] = std::max(dp[i], dp[e.dst] + e.cost);\n    }\n\
    \  }\n  lower_bound_constraint.add_edge(0, n - 1, 0, INF, dp[0]);\n  std::cout\
    \ << lower_bound_constraint.solve(0, 0, 0) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\
    \u6D41\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <limits>\n#include\
    \ <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp\"\
    \n#include \"emthrm/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp\"\
    \n\nint main() {\n  constexpr int INF = std::numeric_limits<int>::max();\n  int\
    \ n, m;\n  std::cin >> n >> m;\n  emthrm::MinimumCostFlowWithLowerBoundConstraint<\n\
    \      emthrm::MinimumCostBFlow, long long, long long>\n          lower_bound_constraint(n,\
    \ INF);\n  std::vector<std::vector<emthrm::Edge<int>>> graph(n);\n  while (m--)\
    \ {\n    int x, y, s;\n    std::cin >> x >> y >> s;\n    lower_bound_constraint.add_edge(y,\
    \ x, 1, INF, -s);\n    graph[x].emplace_back(x, y, s);\n  }\n  std::vector<long\
    \ long> dp(n, 0);\n  for (int i = n - 2; i >= 0; --i) {\n    for (const emthrm::Edge<int>&\
    \ e : graph[i]) {\n      dp[i] = std::max(dp[i], dp[e.dst] + e.cost);\n    }\n\
    \  }\n  lower_bound_constraint.add_edge(0, n - 1, 0, INF, dp[0]);\n  std::cout\
    \ << lower_bound_constraint.solve(0, 0, 0) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp
  - include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp
  isVerificationFile: true
  path: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
  \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
---
