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
    path: include/emthrm/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.hpp
    title: submodular quadratic pseudo-Boolean optimisation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/submodular\
      \ quadratic pseudo-Boolean optimisation"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903
  bundledCode: "#line 1 \"test/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/submodular\
    \ quadratic pseudo-Boolean optimisation\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903\n\
    \ */\n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/graph/flow/maximum_flow/dinic.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <limits>\n#include <queue>\n#include <utility>\n#line 9 \"include/emthrm/graph/flow/maximum_flow/dinic.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct Dinic {\n  struct Edge\
    \ {\n    int dst, rev;\n    T cap;\n    explicit Edge(const int dst, const T cap,\
    \ const int rev)\n        : dst(dst), rev(rev), cap(cap) {}\n  };\n\n  std::vector<std::vector<Edge>>\
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
    \ }\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.hpp\"\
    \n\n\n\n#include <cassert>\n#line 7 \"include/emthrm/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp\"\n/**\n\
    \ * @title \u6700\u5927\u6D41\u30B3\u30F3\u30BB\u30D7\u30C8\n */\n\n#ifndef EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n\
    #define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n\n#include <concepts>\n\
    #line 10 \"include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <template <typename> class C, typename T>\nconcept MaximumFlow\
    \ = requires (C<T> mf) {\n  {mf.add_edge(std::declval<int>(), std::declval<int>(),\
    \ std::declval<T>())}\n      -> std::same_as<void>;\n  {mf.maximum_flow(std::declval<int>(),\
    \ std::declval<int>())}\n      -> std::same_as<T>;\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n#line 9 \"include/emthrm/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <template <typename> class C, typename T>\n\
    requires MaximumFlow<C, T>\nstruct SubmodularQPBO {\n  explicit SubmodularQPBO(const\
    \ int n)\n      : inf(std::numeric_limits<T>::max()), n(n), res(0) {}\n\n  void\
    \ add_neq(const int u, const int v, const T cost) {\n    assert(cost >= 0);\n\
    \    us.emplace_back(u);\n    vs.emplace_back(v);\n    costs.emplace_back(cost);\n\
    \  }\n\n  void add(const int v, bool group, T cost) {\n    if (cost < 0) {\n \
    \     cost = -cost;\n      res += cost;\n      group = !group;\n    }\n    if\
    \ (group) {\n      add_neq(-2, v, cost);  // -2 represents S.\n    } else {\n\
    \      add_neq(v, -1, cost);  // -1 represents T.\n    }\n  }\n\n  void add_or(const\
    \ std::vector<int>& v, const bool group, const T cost) {\n    assert(cost >= 0);\n\
    \    add(n, group, cost);\n    if (group) {\n      for (const int e : v) add_neq(n,\
    \ e, inf);\n    } else {\n      for (const int e : v) add_neq(e, n, inf);\n  \
    \  }\n    ++n;\n  }\n\n  void add_or(const int u, const int v, const bool group,\
    \ const T cost) {\n    add_or({u, v}, group, cost);\n  }\n\n  void add_eq(const\
    \ std::vector<int>& v, const bool group, T cost) {\n    assert(cost <= 0);\n \
    \   cost = -cost;\n    res += cost;\n    add_or(v, !group, cost);\n  }\n\n  void\
    \ add_eq(const int u, const int v, const bool group, const T cost) {\n    add_eq({u,\
    \ v}, group, cost);\n  }\n\n  T solve() {\n    C<T> mf(n + 2);\n    const int\
    \ neq_size = costs.size();\n    for (int i = 0; i < neq_size; ++i) {\n      mf.add_edge(us[i]\
    \ < 0 ? us[i] + n + 2 : us[i],\n                  vs[i] < 0 ? vs[i] + n + 2 :\
    \ vs[i], costs[i]);\n    }\n    return mf.maximum_flow(n, n + 1, inf) - res;\n\
    \  }\n\n private:\n  const T inf;\n  int n;\n  T res;\n  std::vector<int> us,\
    \ vs;\n  std::vector<T> costs;\n};\n\n}  // namespace emthrm\n\n\n#line 13 \"\
    test/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.test.cpp\"\
    \n\nint main() {\n  int r, c;\n  std::cin >> r >> c;\n  std::vector<std::string>\
    \ s(r);\n  for (int i = 0; i < r; ++i) {\n    std::cin >> s[i];\n  }\n  std::vector<std::vector<int>>\
    \ id(r, std::vector<int>(c, -1));\n  int n = 0;\n  for (int i = 0; i < r; ++i)\
    \ {\n    for (int j = 0; j < c; ++j) {\n      if (s[i][j] == '#') id[i][j] = n++;\n\
    \    }\n  }\n  emthrm::SubmodularQPBO<emthrm::Dinic, int> submodular_qpbo(n);\n\
    \  for (int i = 0; i < r; ++i) {\n    for (int j = 0; j < c; ++j) {\n      if\
    \ (id[i][j] == -1) continue;\n      if (i + 1 < r && id[i + 1][j] != -1) {\n \
    \       submodular_qpbo.add_eq(id[i][j], id[i + 1][j], 0, -1);\n      }\n    \
    \  if (j + 1 < c && id[i][j + 1] != -1) {\n        submodular_qpbo.add_eq(id[i][j],\
    \ id[i][j + 1], 1, -1);\n      }\n    }\n  }\n  std::cout << n + submodular_qpbo.solve()\
    \ << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/submodular\
    \ quadratic pseudo-Boolean optimisation\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903\n\
    \ */\n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include\
    \ \"emthrm/graph/flow/maximum_flow/dinic.hpp\"\n#include \"emthrm/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.hpp\"\
    \n\nint main() {\n  int r, c;\n  std::cin >> r >> c;\n  std::vector<std::string>\
    \ s(r);\n  for (int i = 0; i < r; ++i) {\n    std::cin >> s[i];\n  }\n  std::vector<std::vector<int>>\
    \ id(r, std::vector<int>(c, -1));\n  int n = 0;\n  for (int i = 0; i < r; ++i)\
    \ {\n    for (int j = 0; j < c; ++j) {\n      if (s[i][j] == '#') id[i][j] = n++;\n\
    \    }\n  }\n  emthrm::SubmodularQPBO<emthrm::Dinic, int> submodular_qpbo(n);\n\
    \  for (int i = 0; i < r; ++i) {\n    for (int j = 0; j < c; ++j) {\n      if\
    \ (id[i][j] == -1) continue;\n      if (i + 1 < r && id[i + 1][j] != -1) {\n \
    \       submodular_qpbo.add_eq(id[i][j], id[i + 1][j], 0, -1);\n      }\n    \
    \  if (j + 1 < c && id[i][j + 1] != -1) {\n        submodular_qpbo.add_eq(id[i][j],\
    \ id[i][j + 1], 1, -1);\n      }\n    }\n  }\n  std::cout << n + submodular_qpbo.solve()\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/maximum_flow/dinic.hpp
  - include/emthrm/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.hpp
  - include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp
  isVerificationFile: true
  path: test/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.test.cpp
  requiredBy: []
  timestamp: '2024-04-03 22:42:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.test.cpp
- /verify/test/graph/flow/maximum_flow/submodular_quadratic_pseudo-boolean_optimisation.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/submodular quadratic\
  \ pseudo-Boolean optimisation"
---
