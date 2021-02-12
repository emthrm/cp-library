---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/warshall-floyd.hpp
    title: "Warshall-Floyd \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526
    document_title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall-Floyd\
      \ \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526
  bundledCode: "#line 1 \"test/graph/shortest_path/warshall-floyd.test.cpp\"\n/*\r\
    \n * @brief \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall-Floyd \u6CD5\
    \r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"graph/shortest_path/warshall-floyd.hpp\"\
    \n#include <set>\r\n#line 4 \"graph/shortest_path/warshall-floyd.hpp\"\n\r\ntemplate\
    \ <typename T>\r\nstruct WarshallFloyd {\r\n  std::vector<std::vector<T>> graph,\
    \ dist;\r\n\r\n  WarshallFloyd(const std::vector<std::vector<T>> &graph, const\
    \ T inf) : graph(graph), dist(graph), inf(inf) {\r\n    n = graph.size();\r\n\
    \    internal.assign(n, std::vector<int>(n, -1));\r\n    for (int k = 0; k < n;\
    \ ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {\r\n      if (dist[i][j]\
    \ > dist[i][k] + dist[k][j]) {\r\n        dist[i][j] = dist[i][k] + dist[k][j];\r\
    \n        internal[i][j] = k;\r\n      }\r\n    }\r\n  }\r\n\r\n  void add(int\
    \ src, int dst, T cost) {\r\n    srcs.emplace_back(src);\r\n    dsts.emplace_back(dst);\r\
    \n    costs.emplace_back(cost);\r\n  }\r\n\r\n  void calc() {\r\n    std::set<int>\
    \ vers;\r\n    int sz = srcs.size();\r\n    for (int i = 0; i < sz; ++i) {\r\n\
    \      int s = srcs[i], t = dsts[i];\r\n      T cost = costs[i];\r\n      if (cost\
    \ < graph[s][t]) graph[s][t] = cost;\r\n      if (dist[s][t] >= cost) {\r\n  \
    \      dist[s][t] = cost;\r\n        internal[s][t] = -1;\r\n      }\r\n     \
    \ vers.emplace(s);\r\n      vers.emplace(t);\r\n    }\r\n    for (int v : vers)\
    \ {\r\n      for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {\r\n   \
    \     if (dist[i][j] > dist[i][v] + dist[v][j]) {\r\n          dist[i][j] = dist[i][v]\
    \ + dist[v][j];\r\n          internal[i][j] = v;\r\n        }\r\n      }\r\n \
    \   }\r\n    srcs.clear();\r\n    dsts.clear();\r\n    costs.clear();\r\n  }\r\
    \n\r\n  bool has_negative_cycle() const {\r\n    for (int i = 0; i < n; ++i) {\r\
    \n      if (dist[i][i] < 0) return true;\r\n    }\r\n    return false;\r\n  }\r\
    \n\r\n  std::vector<int> build_path(int s, int t) const {\r\n    std::vector<int>\
    \ res;\r\n    if (dist[s][t] != inf) {\r\n      build_path(s, t, res);\r\n   \
    \   res.emplace_back(t);\r\n    }\r\n    return res;\r\n  }\r\n\r\nprivate:\r\n\
    \  const T inf;\r\n  int n;\r\n  std::vector<std::vector<int>> internal;\r\n \
    \ std::vector<int> srcs, dsts;\r\n  std::vector<T> costs;\r\n\r\n  void build_path(int\
    \ s, int t, std::vector<int> &path) const {\r\n    int k = internal[s][t];\r\n\
    \    if (k == -1) {\r\n      path.emplace_back(s);\r\n    } else {\r\n      build_path(s,\
    \ k, path);\r\n      build_path(k, t, path);\r\n    }\r\n  }\r\n};\r\n#line 9\
    \ \"test/graph/shortest_path/warshall-floyd.test.cpp\"\n\r\nint main() {\r\n \
    \ constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n  while (true) {\r\n   \
    \ int n, k;\r\n    std::cin >> n >> k;\r\n    if (n == 0 && k == 0) break;\r\n\
    \    std::vector<std::vector<long long>> graph(n, std::vector<long long>(n, LINF));\r\
    \n    for (int i = 0; i < n; ++i) graph[i][i] = 0;\r\n    WarshallFloyd<long long>\
    \ wf(graph, LINF);\r\n    while (k--) {\r\n      int flag;\r\n      std::cin >>\
    \ flag;\r\n      if (flag == 0) {\r\n        int a, b;\r\n        std::cin >>\
    \ a >> b;\r\n        --a; --b;\r\n        std::cout << (wf.dist[a][b] == LINF\
    \ ? -1 : wf.dist[a][b]) << '\\n';\r\n      } else {\r\n        int c, d;\r\n \
    \       long long e;\r\n        std::cin >> c >> d >> e;\r\n        --c; --d;\r\
    \n        wf.add(c, d, e);\r\n        wf.add(d, c, e);\r\n        wf.calc();\r\
    \n      }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall-Floyd\
    \ \u6CD5\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../graph/shortest_path/warshall-floyd.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n\
    \  while (true) {\r\n    int n, k;\r\n    std::cin >> n >> k;\r\n    if (n ==\
    \ 0 && k == 0) break;\r\n    std::vector<std::vector<long long>> graph(n, std::vector<long\
    \ long>(n, LINF));\r\n    for (int i = 0; i < n; ++i) graph[i][i] = 0;\r\n   \
    \ WarshallFloyd<long long> wf(graph, LINF);\r\n    while (k--) {\r\n      int\
    \ flag;\r\n      std::cin >> flag;\r\n      if (flag == 0) {\r\n        int a,\
    \ b;\r\n        std::cin >> a >> b;\r\n        --a; --b;\r\n        std::cout\
    \ << (wf.dist[a][b] == LINF ? -1 : wf.dist[a][b]) << '\\n';\r\n      } else {\r\
    \n        int c, d;\r\n        long long e;\r\n        std::cin >> c >> d >> e;\r\
    \n        --c; --d;\r\n        wf.add(c, d, e);\r\n        wf.add(d, c, e);\r\n\
    \        wf.calc();\r\n      }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/shortest_path/warshall-floyd.hpp
  isVerificationFile: true
  path: test/graph/shortest_path/warshall-floyd.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/shortest_path/warshall-floyd.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path/warshall-floyd.test.cpp
- /verify/test/graph/shortest_path/warshall-floyd.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall-Floyd \u6CD5"
---
