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
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 2 \"graph/shortest_path/warshall-floyd.hpp\"\
    \n#include <algorithm>\r\n#include <iterator>\r\n#line 5 \"graph/shortest_path/warshall-floyd.hpp\"\
    \n\r\ntemplate <typename T>\r\nstruct WarshallFloyd {\r\n  std::vector<std::vector<T>>\
    \ graph, dist;\r\n\r\n  WarshallFloyd(const std::vector<std::vector<T>>& graph,\
    \ const T inf)\r\n      : graph(graph), dist(graph), inf(inf), n(graph.size()),\r\
    \n        internal(n, std::vector<int>(n, -1)) {\r\n    for (int k = 0; k < n;\
    \ ++k) {\r\n      for (int i = 0; i < n; ++i) {\r\n        for (int j = 0; j <\
    \ n; ++j) {\r\n          if (dist[i][k] + dist[k][j] < dist[i][j]) {\r\n     \
    \       dist[i][j] = dist[i][k] + dist[k][j];\r\n            internal[i][j] =\
    \ k;\r\n          }\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  void add(const\
    \ int src, const int dst, const T cost) {\r\n    srcs.emplace_back(src);\r\n \
    \   dsts.emplace_back(dst);\r\n    costs.emplace_back(cost);\r\n  }\r\n\r\n  void\
    \ calc() {\r\n    const int m = srcs.size();\r\n    for (int i = 0; i < m; ++i)\
    \ {\r\n      graph[srcs[i]][dsts[i]] = std::min(graph[srcs[i]][dsts[i]], costs[i]);\r\
    \n      if (costs[i] <= dist[srcs[i]][dsts[i]]) {\r\n        dist[srcs[i]][dsts[i]]\
    \ = costs[i];\r\n        internal[srcs[i]][dsts[i]] = -1;\r\n      }\r\n    }\r\
    \n    std::vector<int> vers(m * 2);\r\n    std::copy(srcs.begin(), srcs.end(),\
    \ vers.begin());\r\n    std::copy(dsts.begin(), dsts.end(), std::next(vers.begin(),\
    \ m));\r\n    std::sort(vers.begin(), vers.end());\r\n    vers.erase(std::unique(vers.begin(),\
    \ vers.end()), vers.end());\r\n    for (const int ver : vers) {\r\n      for (int\
    \ i = 0; i < n; ++i) {\r\n        for (int j = 0; j < n; ++j) {\r\n          if\
    \ (dist[i][j] > dist[i][ver] + dist[ver][j]) {\r\n            dist[i][j] = dist[i][ver]\
    \ + dist[ver][j];\r\n            internal[i][j] = ver;\r\n          }\r\n    \
    \    }\r\n      }\r\n    }\r\n    srcs.clear();\r\n    dsts.clear();\r\n    costs.clear();\r\
    \n  }\r\n\r\n  bool has_negative_cycle() const {\r\n    for (int i = 0; i < n;\
    \ ++i) {\r\n      if (dist[i][i] < 0) return true;\r\n    }\r\n    return false;\r\
    \n  }\r\n\r\n  std::vector<int> build_path(const int s, const int t) const {\r\
    \n    std::vector<int> res;\r\n    if (dist[s][t] != inf) {\r\n      build_path(s,\
    \ t, &res);\r\n      res.emplace_back(t);\r\n    }\r\n    return res;\r\n  }\r\
    \n\r\n private:\r\n  const T inf;\r\n  const int n;\r\n  std::vector<int> srcs,\
    \ dsts;\r\n  std::vector<T> costs;\r\n  std::vector<std::vector<int>> internal;\r\
    \n\r\n  void build_path(const int s, const int t, std::vector<int>* path) const\
    \ {\r\n    const int k = internal[s][t];\r\n    if (k == -1) {\r\n      (*path).emplace_back(s);\r\
    \n    } else {\r\n      build_path(s, k, path);\r\n      build_path(k, t, path);\r\
    \n    }\r\n  }\r\n};\r\n#line 10 \"test/graph/shortest_path/warshall-floyd.test.cpp\"\
    \n\r\nint main() {\r\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n \
    \ while (true) {\r\n    int n, k;\r\n    std::cin >> n >> k;\r\n    if (n == 0\
    \ && k == 0) break;\r\n    std::vector<std::vector<long long>> graph(n,\r\n  \
    \                                            std::vector<long long>(n, LINF));\r\
    \n    for (int i = 0; i < n; ++i) {\r\n      graph[i][i] = 0;\r\n    }\r\n   \
    \ WarshallFloyd<long long> warshall_floyd(graph, LINF);\r\n    while (k--) {\r\
    \n      int type;\r\n      std::cin >> type;\r\n      if (type == 0) {\r\n   \
    \     int a, b;\r\n        std::cin >> a >> b;\r\n        --a; --b;\r\n      \
    \  std::cout << (warshall_floyd.dist[a][b] == LINF ?\r\n                     \
    \ -1 : warshall_floyd.dist[a][b])\r\n                  << '\\n';\r\n      } else\
    \ if (type == 1) {\r\n        int c, d;\r\n        long long e;\r\n        std::cin\
    \ >> c >> d >> e;\r\n        --c; --d;\r\n        warshall_floyd.add(c, d, e);\r\
    \n        warshall_floyd.add(d, c, e);\r\n        warshall_floyd.calc();\r\n \
    \     }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall-Floyd\
    \ \u6CD5\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../../graph/shortest_path/warshall-floyd.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n\
    \  while (true) {\r\n    int n, k;\r\n    std::cin >> n >> k;\r\n    if (n ==\
    \ 0 && k == 0) break;\r\n    std::vector<std::vector<long long>> graph(n,\r\n\
    \                                              std::vector<long long>(n, LINF));\r\
    \n    for (int i = 0; i < n; ++i) {\r\n      graph[i][i] = 0;\r\n    }\r\n   \
    \ WarshallFloyd<long long> warshall_floyd(graph, LINF);\r\n    while (k--) {\r\
    \n      int type;\r\n      std::cin >> type;\r\n      if (type == 0) {\r\n   \
    \     int a, b;\r\n        std::cin >> a >> b;\r\n        --a; --b;\r\n      \
    \  std::cout << (warshall_floyd.dist[a][b] == LINF ?\r\n                     \
    \ -1 : warshall_floyd.dist[a][b])\r\n                  << '\\n';\r\n      } else\
    \ if (type == 1) {\r\n        int c, d;\r\n        long long e;\r\n        std::cin\
    \ >> c >> d >> e;\r\n        --c; --d;\r\n        warshall_floyd.add(c, d, e);\r\
    \n        warshall_floyd.add(d, c, e);\r\n        warshall_floyd.calc();\r\n \
    \     }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/shortest_path/warshall-floyd.hpp
  isVerificationFile: true
  path: test/graph/shortest_path/warshall-floyd.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/shortest_path/warshall-floyd.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path/warshall-floyd.test.cpp
- /verify/test/graph/shortest_path/warshall-floyd.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall-Floyd \u6CD5"
---
