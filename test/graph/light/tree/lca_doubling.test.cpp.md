---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/graph/light/tree/lca_doubling.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\r\n\r\n\
    #include <iostream>\r\n#include <vector>\r\n#line 2 \"graph/light/tree/lca_doubling.hpp\"\
    \n#include <cassert>\r\n#include <utility>\r\n#line 5 \"graph/light/tree/lca_doubling.hpp\"\
    \n\r\nstruct LCADoubling {\r\n  std::vector<int> depth, dist;\r\n\r\n  LCADoubling(const\
    \ std::vector<std::vector<int>> &graph) : graph(graph) {\r\n    n = graph.size();\r\
    \n    depth.resize(n);\r\n    dist.resize(n);\r\n    while ((1 << table_h) <=\
    \ n) ++table_h;\r\n    parent.resize(table_h, std::vector<int>(n));\r\n  }\r\n\
    \r\n  void build(int root = 0) {\r\n    is_built = true;\r\n    dfs(-1, root,\
    \ 0, 0);\r\n    for (int i = 0; i + 1 < table_h; ++i) for (int ver = 0; ver <\
    \ n; ++ver) {\r\n      parent[i + 1][ver] = parent[i][ver] == -1 ? -1 : parent[i][parent[i][ver]];\r\
    \n    }\r\n  }\r\n\r\n  int query(int u, int v) const {\r\n    assert(is_built);\r\
    \n    if (depth[u] > depth[v]) std::swap(u, v);\r\n    for (int i = 0; i < table_h;\
    \ ++i) {\r\n      if ((depth[v] - depth[u]) >> i & 1) v = parent[i][v];\r\n  \
    \  }\r\n    if (u == v) return u;\r\n    for (int i = table_h - 1; i >= 0; --i)\
    \ {\r\n      if (parent[i][u] != parent[i][v]) {\r\n        u = parent[i][u];\r\
    \n        v = parent[i][v];\r\n      }\r\n    }\r\n    return parent[0][u];\r\n\
    \  }\r\n\r\n  int distance(int u, int v) const {\r\n    assert(is_built);\r\n\
    \    return dist[u] + dist[v] - dist[query(u, v)] * 2;\r\n  }\r\n\r\nprivate:\r\
    \n  bool is_built = false;\r\n  int n, table_h = 1;\r\n  std::vector<std::vector<int>>\
    \ graph, parent;\r\n\r\n  void dfs(int par, int ver, int now_depth, int now_dist)\
    \ {\r\n    depth[ver] = now_depth;\r\n    dist[ver] = now_dist;\r\n    parent[0][ver]\
    \ = par;\r\n    for (int e : graph[ver]) {\r\n      if (e != par) dfs(ver, e,\
    \ now_depth + 1, now_dist + 1);\r\n    }\r\n  }\r\n};\r\n#line 6 \"test/graph/light/tree/lca_doubling.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    int k;\r\n    std::cin >>\
    \ k;\r\n    while (k--) {\r\n      int c;\r\n      std::cin >> c;\r\n      graph[i].emplace_back(c);\r\
    \n      graph[c].emplace_back(i);\r\n    }\r\n  }\r\n  LCADoubling lca(graph);\r\
    \n  lca.build(0);\r\n  int q;\r\n  std::cin >> q;\r\n  while (q--) {\r\n    int\
    \ u, v;\r\n    std::cin >> u >> v;\r\n    std::cout << lca.query(u, v) << '\\\
    n';\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../../graph/light/tree/lca_doubling.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    int k;\r\n    std::cin >>\
    \ k;\r\n    while (k--) {\r\n      int c;\r\n      std::cin >> c;\r\n      graph[i].emplace_back(c);\r\
    \n      graph[c].emplace_back(i);\r\n    }\r\n  }\r\n  LCADoubling lca(graph);\r\
    \n  lca.build(0);\r\n  int q;\r\n  std::cin >> q;\r\n  while (q--) {\r\n    int\
    \ u, v;\r\n    std::cin >> u >> v;\r\n    std::cout << lca.query(u, v) << '\\\
    n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/light/tree/lca_doubling.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/light/tree/lca_doubling.test.cpp
layout: document
redirect_from:
- /verify/test/graph/light/tree/lca_doubling.test.cpp
- /verify/test/graph/light/tree/lca_doubling.test.cpp.html
title: test/graph/light/tree/lca_doubling.test.cpp
---
