---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
      \u30DE\u30C3\u30C1\u30F3\u30B0"
  - icon: ':question:'
    path: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC (minimum cost $s$-$t$-flow)\
      \ \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5 (successive shortest path algorithm)\
      \ \u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
      \u30B0/\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
      \u30DE\u30C3\u30C1\u30F3\u30B0"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429
  bundledCode: "#line 1 \"test/graph/flow/matching/weighted_bipartite_matching.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
    \u30DE\u30C3\u30C1\u30F3\u30B0\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429\n */\n\
    \n#include <iostream>\n#include <string>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n#include <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n\
    #line 11 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T, typename U>\nstruct MinimumCostSTFlow\
    \ {\n  struct Edge {\n    int dst, rev;\n    T cap;\n    U cost;\n    explicit\
    \ Edge(const int dst, const T cap, const U cost, const int rev)\n        : dst(dst),\
    \ rev(rev), cap(cap), cost(cost) {}\n  };\n\n  const U uinf;\n  std::vector<std::vector<Edge>>\
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
    \n\n#line 8 \"include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct WeightedBipartiteMatching\
    \ {\n  explicit WeightedBipartiteMatching(const int left, const int right)\n \
    \     : is_built(false), left(left), right(right), mcf(left + right + 2) {}\n\n\
    \  void add_edge(const int src, const int dst, const T cost) {\n    mcf.add_edge(src,\
    \ left + dst, 1, -cost);\n  }\n\n  T solve() {\n    assert(!is_built);\n    is_built\
    \ = true;\n    const int s = left + right, t = left + right + 1;\n    for (int\
    \ i = 0; i < left; ++i) {\n      mcf.add_edge(s, i, 1, 0);\n    }\n    for (int\
    \ i = 0; i < right; ++i) {\n      mcf.add_edge(left + i, t, 1, 0);\n    }\n  \
    \  return -mcf.minimum_cost_maximum_flow(s, t, left).second;\n  }\n\n  std::vector<int>\
    \ matching() const {\n    assert(is_built);\n    std::vector<int> res(left, -1);\n\
    \    for (int i = 0; i < left; ++i) {\n      for (const auto& e : mcf.graph[i])\
    \ {\n        if (e.cap == 0 && left <= e.dst && e.dst < left + right) {\n    \
    \      res[i] = e.dst - left;\n          break;\n        }\n      }\n    }\n \
    \   return res;\n  }\n\n private:\n  bool is_built;\n  const int left, right;\n\
    \  MinimumCostSTFlow<int, T> mcf;\n};\n\n}  // namespace emthrm\n\n\n#line 13\
    \ \"test/graph/flow/matching/weighted_bipartite_matching.test.cpp\"\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<int>> w(n, std::vector<int>(n));\n\
    \  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      std::\
    \ cin >> w[i][j];\n    }\n  }\n  std::vector<std::vector<int>> e(n, std::vector<int>(n));\n\
    \  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      std::\
    \ cin >> e[i][j];\n    }\n  }\n  std::vector<std::string> f(n);\n  long long ans\
    \ = 0;\n  for (int i = 0; i < n; ++i) {\n    std::cin >> f[i];\n    for (int j\
    \ = 0; j < n; ++j) {\n      if (f[i][j] == 'o') ans += e[i][j];\n    }\n  }\n\
    \  emthrm::WeightedBipartiteMatching<long long>\n      weighted_bipartite_matching(n,\
    \ n);\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n  \
    \    weighted_bipartite_matching.add_edge(i, j,\n                            \
    \               f[i][j] == 'o' ? e[i][j] : -w[i][j]);\n    }\n  }\n  std::cout\
    \ << ans - weighted_bipartite_matching.solve() << '\\n';\n  std::vector<std::string>\
    \ taro(n, std::string(n, '.'));\n  const std::vector<int> matching = weighted_bipartite_matching.matching();\n\
    \  for (int i = 0; i < n; ++i) {\n    taro[i][matching[i]] = 'o';\n  }\n  std::vector<int>\
    \ r, c;\n  std::vector<std::string> operate;\n  for (int i = 0; i < n; ++i) {\n\
    \    for (int j = 0; j < n; ++j) {\n      if (f[i][j] != taro[i][j]) {\n     \
    \   r.emplace_back(i);\n        c.emplace_back(j);\n        operate.emplace_back(f[i][j]\
    \ == 'o' ? \"erase\" : \"write\");\n      }\n    }\n  }\n  const int cnt = r.size();\n\
    \  std::cout << cnt << '\\n';\n  for (int i = 0; i < cnt; ++i) {\n    std::cout\
    \ << r[i] + 1 << ' ' << c[i] + 1 << ' ' << operate[i] << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
    \u30DE\u30C3\u30C1\u30F3\u30B0\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429\n */\n\
    \n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"emthrm/graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<int>>\
    \ w(n, std::vector<int>(n));\n  for (int i = 0; i < n; ++i) {\n    for (int j\
    \ = 0; j < n; ++j) {\n      std:: cin >> w[i][j];\n    }\n  }\n  std::vector<std::vector<int>>\
    \ e(n, std::vector<int>(n));\n  for (int i = 0; i < n; ++i) {\n    for (int j\
    \ = 0; j < n; ++j) {\n      std:: cin >> e[i][j];\n    }\n  }\n  std::vector<std::string>\
    \ f(n);\n  long long ans = 0;\n  for (int i = 0; i < n; ++i) {\n    std::cin >>\
    \ f[i];\n    for (int j = 0; j < n; ++j) {\n      if (f[i][j] == 'o') ans += e[i][j];\n\
    \    }\n  }\n  emthrm::WeightedBipartiteMatching<long long>\n      weighted_bipartite_matching(n,\
    \ n);\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n  \
    \    weighted_bipartite_matching.add_edge(i, j,\n                            \
    \               f[i][j] == 'o' ? e[i][j] : -w[i][j]);\n    }\n  }\n  std::cout\
    \ << ans - weighted_bipartite_matching.solve() << '\\n';\n  std::vector<std::string>\
    \ taro(n, std::string(n, '.'));\n  const std::vector<int> matching = weighted_bipartite_matching.matching();\n\
    \  for (int i = 0; i < n; ++i) {\n    taro[i][matching[i]] = 'o';\n  }\n  std::vector<int>\
    \ r, c;\n  std::vector<std::string> operate;\n  for (int i = 0; i < n; ++i) {\n\
    \    for (int j = 0; j < n; ++j) {\n      if (f[i][j] != taro[i][j]) {\n     \
    \   r.emplace_back(i);\n        c.emplace_back(j);\n        operate.emplace_back(f[i][j]\
    \ == 'o' ? \"erase\" : \"write\");\n      }\n    }\n  }\n  const int cnt = r.size();\n\
    \  std::cout << cnt << '\\n';\n  for (int i = 0; i < cnt; ++i) {\n    std::cout\
    \ << r[i] + 1 << ' ' << c[i] + 1 << ' ' << operate[i] << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp
  - include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: true
  path: test/graph/flow/matching/weighted_bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/graph/flow/matching/weighted_bipartite_matching.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/matching/weighted_bipartite_matching.test.cpp
- /verify/test/graph/flow/matching/weighted_bipartite_matching.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E8C\
  \u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\u30DE\u30C3\u30C1\
  \u30F3\u30B0"
---
