---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/dinic.hpp
    title: "Dinic \u6CD5"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp
    title: "\u6700\u5927\u6D41\u30B3\u30F3\u30BB\u30D7\u30C8"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
    title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\
      \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615
  bundledCode: "#line 1 \"test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\
    \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615\n */\n\
    \n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/flow/maximum_flow/dinic.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <limits>\n#include <queue>\n#include <utility>\n\
    #line 9 \"include/emthrm/graph/flow/maximum_flow/dinic.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nstruct Dinic {\n  struct Edge {\n    int dst, rev;\n\
    \    T cap;\n    explicit Edge(const int dst, const T cap, const int rev)\n  \
    \      : dst(dst), rev(rev), cap(cap) {}\n  };\n\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  explicit Dinic(const int n) : graph(n), level(n), itr(n) {}\n\n\
    \  void add_edge(const int src, const int dst, const T cap) {\n    graph[src].emplace_back(dst,\
    \ cap, graph[dst].size());\n    graph[dst].emplace_back(src, 0, graph[src].size()\
    \ - 1);\n  }\n\n  T maximum_flow(const int s, const int t,\n                 T\
    \ limit = std::numeric_limits<T>::max()) {\n    T res = 0;\n    while (limit >\
    \ 0) {\n      std::fill(level.begin(), level.end(), -1);\n      level[s] = 0;\n\
    \      std::queue<int> que;\n      que.emplace(s);\n      while (!que.empty())\
    \ {\n        const int ver = que.front();\n        que.pop();\n        for (const\
    \ Edge& e : graph[ver]) {\n          if (level[e.dst] == -1 && e.cap > 0) {\n\
    \            level[e.dst] = level[ver] + 1;\n            que.emplace(e.dst);\n\
    \          }\n        }\n      }\n      if (level[t] == -1) break;\n      std::fill(itr.begin(),\
    \ itr.end(), 0);\n      while (limit > 0) {\n        const T f = dfs(s, t, limit);\n\
    \        if (f == 0) break;\n        limit -= f;\n        res += f;\n      }\n\
    \    }\n    return res;\n  }\n\n private:\n  std::vector<int> level, itr;\n\n\
    \  T dfs(const int ver, const int t, const T flow) {\n    if (ver == t) return\
    \ flow;\n    for (; std::cmp_less(itr[ver], graph[ver].size()); ++itr[ver]) {\n\
    \      Edge& e = graph[ver][itr[ver]];\n      if (level[ver] < level[e.dst] &&\
    \ e.cap > 0) {\n        const T tmp = dfs(e.dst, t, std::min(flow, e.cap));\n\
    \        if (tmp > 0) {\n          e.cap -= tmp;\n          graph[e.dst][e.rev].cap\
    \ += tmp;\n          return tmp;\n        }\n      }\n    }\n    return 0;\n \
    \ }\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp\"\
    \n\n\n\n#line 1 \"include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp\"\n\
    /**\n * @title \u6700\u5927\u6D41\u30B3\u30F3\u30BB\u30D7\u30C8\n */\n\n#ifndef\
    \ EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n#define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n\
    \n#include <concepts>\n#line 10 \"include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <template <typename> class C, typename T>\n\
    concept MaximumFlow = requires (C<T> mf) {\n  {mf.add_edge(std::declval<int>(),\
    \ std::declval<int>(), std::declval<T>())}\n      -> std::same_as<void>;\n  {mf.maximum_flow(std::declval<int>(),\
    \ std::declval<int>())}\n      -> std::same_as<T>;\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n#line 5 \"include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <template <typename> class C, typename T>\n\
    requires MaximumFlow<C, T>\nstruct MaximumFlowWithLowerBoundConstraint {\n  explicit\
    \ MaximumFlowWithLowerBoundConstraint(const int n)\n      : n(n), sum_lb(0), mf(n\
    \ + 2) {}\n\n  void add_edge(const int src, const int dst, const T lb, const T\
    \ ub) {\n    mf.add_edge(src, dst, ub - lb);\n    mf.add_edge(n, dst, lb);\n \
    \   mf.add_edge(src, n + 1, lb);\n    sum_lb += lb;\n  }\n\n  T solve(const int\
    \ s, const int t) {\n    const T a = mf.maximum_flow(n, n + 1);\n    const T b\
    \ = mf.maximum_flow(s, n + 1);\n    const T c = mf.maximum_flow(n, t);\n    const\
    \ T d = mf.maximum_flow(s, t);\n    return a + b == sum_lb && b == c ? b + d :\
    \ -1;\n  }\n\n private:\n  const int n;\n  T sum_lb;\n  C<T> mf;\n};\n\n}  //\
    \ namespace emthrm\n\n\n#line 12 \"test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp\"\
    \n\nint main() {\n  while (true) {\n    int n, m;\n    std::cin >> n >> m;\n \
    \   if (n == 0 && m == 0) [[unlikely]] break;\n    std::vector<int> u(m), v(m);\n\
    \    for (int i = 0; i < m; ++i) {\n      std::cin >> u[i] >> v[i];\n      --u[i];\
    \ --v[i];\n    }\n    const int s = m + n, t = m + n + 1;\n    const auto solve\
    \ =\n        [m, n, s, t, &u, &v](const int lb, const int ub) -> bool {\n    \
    \      emthrm::MaximumFlowWithLowerBoundConstraint<emthrm::Dinic, int>\n     \
    \         lower_bound_constraint(m + n + 2);\n          for (int i = 0; i < m;\
    \ ++i) {\n            lower_bound_constraint.add_edge(s, i, 1, 1);\n         \
    \ }\n          for (int i = 0; i < n; ++i) {\n            lower_bound_constraint.add_edge(m\
    \ + i, t, lb, ub);\n          }\n          for (int i = 0; i < m; ++i) {\n   \
    \         lower_bound_constraint.add_edge(i, m + u[i], 0, 1);\n            lower_bound_constraint.add_edge(i,\
    \ m + v[i], 0, 1);\n          }\n          return lower_bound_constraint.solve(s,\
    \ t) != -1;\n        };\n    int lb = 0, ub = n;\n    for (int i = 0, j = 1; i\
    \ < n; ++i) {\n      while (j <= n && !solve(i, j)) ++j;\n      if (j > n) break;\n\
    \      if (ub - lb >= j - i) {\n        lb = i;\n        ub = j;\n      }\n  \
    \    if (i == j) ++j;\n    }\n    std::cout << lb << ' ' << ub << '\\n';\n  }\n\
    \  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\
    \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615\n */\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/flow/maximum_flow/dinic.hpp\"\
    \n#include \"emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp\"\
    \n\nint main() {\n  while (true) {\n    int n, m;\n    std::cin >> n >> m;\n \
    \   if (n == 0 && m == 0) [[unlikely]] break;\n    std::vector<int> u(m), v(m);\n\
    \    for (int i = 0; i < m; ++i) {\n      std::cin >> u[i] >> v[i];\n      --u[i];\
    \ --v[i];\n    }\n    const int s = m + n, t = m + n + 1;\n    const auto solve\
    \ =\n        [m, n, s, t, &u, &v](const int lb, const int ub) -> bool {\n    \
    \      emthrm::MaximumFlowWithLowerBoundConstraint<emthrm::Dinic, int>\n     \
    \         lower_bound_constraint(m + n + 2);\n          for (int i = 0; i < m;\
    \ ++i) {\n            lower_bound_constraint.add_edge(s, i, 1, 1);\n         \
    \ }\n          for (int i = 0; i < n; ++i) {\n            lower_bound_constraint.add_edge(m\
    \ + i, t, lb, ub);\n          }\n          for (int i = 0; i < m; ++i) {\n   \
    \         lower_bound_constraint.add_edge(i, m + u[i], 0, 1);\n            lower_bound_constraint.add_edge(i,\
    \ m + v[i], 0, 1);\n          }\n          return lower_bound_constraint.solve(s,\
    \ t) != -1;\n        };\n    int lb = 0, ub = n;\n    for (int i = 0, j = 1; i\
    \ < n; ++i) {\n      while (j <= n && !solve(i, j)) ++j;\n      if (j > n) break;\n\
    \      if (ub - lb >= j - i) {\n        lb = i;\n        ub = j;\n      }\n  \
    \    if (i == j) ++j;\n    }\n    std::cout << lb << ' ' << ub << '\\n';\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/maximum_flow/dinic.hpp
  - include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
  - include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp
  isVerificationFile: true
  path: test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
- /verify/test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\u5C0F\u6D41\
  \u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
---
