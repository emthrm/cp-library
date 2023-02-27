---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp
    title: "Ford\u2013Fulkerson \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford\u2013\
      Fulkerson \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/graph/flow/maximum_flow/ford-fulkerson.test.cpp\"\n\
    /*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford\u2013\
    Fulkerson \u6CD5\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <limits>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T>\nstruct FordFulkerson {\n  struct Edge {\n\
    \    int dst, rev;\n    T cap;\n    explicit Edge(const int dst, const T cap,\
    \ const int rev)\n        : dst(dst), rev(rev), cap(cap) {}\n  };\n\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  explicit FordFulkerson(const int n)\n      : graph(n), timestamp(0),\
    \ is_used(n, -1) {}\n\n  void add_edge(const int src, const int dst, const T cap)\
    \ {\n    graph[src].emplace_back(dst, cap, graph[dst].size());\n    graph[dst].emplace_back(src,\
    \ 0, graph[src].size() - 1);\n  }\n\n  T maximum_flow(const int s, const int t,\n\
    \                 T limit = std::numeric_limits<T>::max()) {\n    T res = 0;\n\
    \    while (limit > 0) {\n      const T tmp = dfs(s, t, limit);\n      ++timestamp;\n\
    \      if (tmp == 0) break;\n      limit -= tmp;\n      res += tmp;\n    }\n \
    \   return res;\n  }\n\n private:\n  int timestamp;\n  std::vector<int> is_used;\n\
    \n  T dfs(const int ver, const int t, const T flow) {\n    if (ver == t) return\
    \ flow;\n    is_used[ver] = timestamp;\n    for (Edge& e : graph[ver]) {\n   \
    \   if (is_used[e.dst] < timestamp && e.cap > 0) {\n        const T tmp = dfs(e.dst,\
    \ t, std::min(flow, e.cap));\n        if (tmp > 0) {\n          e.cap -= tmp;\n\
    \          graph[e.dst][e.rev].cap += tmp;\n          return tmp;\n        }\n\
    \      }\n    }\n    return 0;\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 10\
    \ \"test/graph/flow/maximum_flow/ford-fulkerson.test.cpp\"\n\nint main() {\n \
    \ int v, e;\n  std::cin >> v >> e;\n  emthrm::FordFulkerson<long long> ford_fulkerson(v);\n\
    \  while (e--) {\n    int u_i, v_i, c_i;\n    std::cin >> u_i >> v_i >> c_i;\n\
    \    ford_fulkerson.add_edge(u_i, v_i, c_i);\n  }\n  std::cout << ford_fulkerson.maximum_flow(0,\
    \ v - 1) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford\u2013\
    Fulkerson \u6CD5\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp\"\
    \n\nint main() {\n  int v, e;\n  std::cin >> v >> e;\n  emthrm::FordFulkerson<long\
    \ long> ford_fulkerson(v);\n  while (e--) {\n    int u_i, v_i, c_i;\n    std::cin\
    \ >> u_i >> v_i >> c_i;\n    ford_fulkerson.add_edge(u_i, v_i, c_i);\n  }\n  std::cout\
    \ << ford_fulkerson.maximum_flow(0, v - 1) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp
  isVerificationFile: true
  path: test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
- /verify/test/graph/flow/maximum_flow/ford-fulkerson.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford\u2013Fulkerson\
  \ \u6CD5"
---
