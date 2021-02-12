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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/graph/light/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"graph/light/scc.hpp\"\
    \n// #include <algorithm>\r\n#line 4 \"graph/light/scc.hpp\"\n\r\nstruct SCC {\r\
    \n  std::vector<int> id;\r\n  std::vector<std::vector<int>> vertices, comp;\r\n\
    \r\n  SCC(const std::vector<std::vector<int>> &graph, bool heavy = false) : graph(graph),\
    \ heavy(heavy) {\r\n    n = graph.size();\r\n    rev_graph.resize(n);\r\n    for\
    \ (int i = 0; i < n; ++i) for (int e : graph[i]) rev_graph[e].emplace_back(i);\r\
    \n    used.assign(n, false);\r\n    id.assign(n, -1);\r\n    for (int i = 0; i\
    \ < n; ++i) {\r\n      if (!used[i]) dfs(i);\r\n    }\r\n    int now = 0;\r\n\
    \    for (int i = n - 1; i >= 0; --i) {\r\n      if (id[order[i]] == -1) {\r\n\
    \        if (heavy) vertices.emplace_back();\r\n        rev_dfs(order[i], now++);\r\
    \n      }\r\n    }\r\n    comp.resize(now);\r\n    for (int i = 0; i < n; ++i)\
    \ for (int e : graph[i]) {\r\n      if (id[i] != id[e]) comp[id[i]].emplace_back(id[e]);\r\
    \n    }\r\n    // if (heavy) {\r\n    //   for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(),\
    \ vertices[i].end());\r\n    // }\r\n  }\r\n\r\nprivate:\r\n  bool heavy;\r\n\
    \  int n;\r\n  std::vector<std::vector<int>> graph, rev_graph;\r\n  std::vector<bool>\
    \ used;\r\n  std::vector<int> order;\r\n\r\n  void dfs(int ver) {\r\n    used[ver]\
    \ = true;\r\n    for (int e : graph[ver]) {\r\n      if (!used[e]) dfs(e);\r\n\
    \    }\r\n    order.emplace_back(ver);\r\n  }\r\n\r\n  void rev_dfs(int ver, int\
    \ now) {\r\n    id[ver] = now;\r\n    if (heavy) vertices[now].emplace_back(ver);\r\
    \n    for (int e : rev_graph[ver]) {\r\n      if (id[e] == -1) rev_dfs(e, now);\r\
    \n    }\r\n  }\r\n};\r\n#line 6 \"test/graph/light/scc.test.cpp\"\n\r\nint main()\
    \ {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  while (m--) {\r\n    int a, b;\r\n    std::cin >> a >> b;\r\n\
    \    graph[a].emplace_back(b);\r\n  }\r\n  SCC scc(graph, true);\r\n  int k =\
    \ scc.vertices.size();\r\n  std::cout << k << '\\n';\r\n  for (int i = 0; i <\
    \ k; ++i) {\r\n    int l = scc.vertices[i].size();\r\n    std::cout << l << '\
    \ ';\r\n    for (int j = 0; j < l; ++j) std::cout << scc.vertices[i][j] << \"\
    \ \\n\"[j + 1 == l];\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#include \"../../../graph/light/scc.hpp\"\r\n\r\nint main()\
    \ {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  while (m--) {\r\n    int a, b;\r\n    std::cin >> a >> b;\r\n\
    \    graph[a].emplace_back(b);\r\n  }\r\n  SCC scc(graph, true);\r\n  int k =\
    \ scc.vertices.size();\r\n  std::cout << k << '\\n';\r\n  for (int i = 0; i <\
    \ k; ++i) {\r\n    int l = scc.vertices[i].size();\r\n    std::cout << l << '\
    \ ';\r\n    for (int j = 0; j < l; ++j) std::cout << scc.vertices[i][j] << \"\
    \ \\n\"[j + 1 == l];\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/light/scc.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/light/scc.test.cpp
layout: document
redirect_from:
- /verify/test/graph/light/scc.test.cpp
- /verify/test/graph/light/scc.test.cpp.html
title: test/graph/light/scc.test.cpp
---
