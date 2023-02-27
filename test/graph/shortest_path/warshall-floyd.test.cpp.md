---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/shortest_path/warshall-floyd.hpp
    title: "Warshall\u2013Floyd \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526
    document_title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall\u2013\
      Floyd \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526
  bundledCode: "#line 1 \"test/graph/shortest_path/warshall-floyd.test.cpp\"\n/*\n\
    \ * @title \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall\u2013Floyd\
    \ \u6CD5\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/shortest_path/warshall-floyd.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iterator>\n#line 7 \"include/emthrm/graph/shortest_path/warshall-floyd.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct WarshallFloyd {\n  std::vector<std::vector<T>>\
    \ graph, dist;\n\n  WarshallFloyd(const std::vector<std::vector<T>>& graph, const\
    \ T inf)\n      : graph(graph), dist(graph), inf(inf), n(graph.size()),\n    \
    \    internal(n, std::vector<int>(n, -1)) {\n    for (int k = 0; k < n; ++k) {\n\
    \      for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < n; ++j) {\n\
    \          if (dist[i][k] + dist[k][j] < dist[i][j]) {\n            dist[i][j]\
    \ = dist[i][k] + dist[k][j];\n            internal[i][j] = k;\n          }\n \
    \       }\n      }\n    }\n  }\n\n  void add(const int src, const int dst, const\
    \ T cost) {\n    srcs.emplace_back(src);\n    dsts.emplace_back(dst);\n    costs.emplace_back(cost);\n\
    \  }\n\n  void calc() {\n    const int m = srcs.size();\n    for (int i = 0; i\
    \ < m; ++i) {\n      graph[srcs[i]][dsts[i]] = std::min(graph[srcs[i]][dsts[i]],\
    \ costs[i]);\n      if (costs[i] <= dist[srcs[i]][dsts[i]]) {\n        dist[srcs[i]][dsts[i]]\
    \ = costs[i];\n        internal[srcs[i]][dsts[i]] = -1;\n      }\n    }\n    std::vector<int>\
    \ vers(m * 2);\n    std::copy(srcs.begin(), srcs.end(), vers.begin());\n    std::copy(dsts.begin(),\
    \ dsts.end(), std::next(vers.begin(), m));\n    std::sort(vers.begin(), vers.end());\n\
    \    vers.erase(std::unique(vers.begin(), vers.end()), vers.end());\n    for (const\
    \ int ver : vers) {\n      for (int i = 0; i < n; ++i) {\n        for (int j =\
    \ 0; j < n; ++j) {\n          if (dist[i][j] > dist[i][ver] + dist[ver][j]) {\n\
    \            dist[i][j] = dist[i][ver] + dist[ver][j];\n            internal[i][j]\
    \ = ver;\n          }\n        }\n      }\n    }\n    srcs.clear();\n    dsts.clear();\n\
    \    costs.clear();\n  }\n\n  bool has_negative_cycle() const {\n    for (int\
    \ i = 0; i < n; ++i) {\n      if (dist[i][i] < 0) return true;\n    }\n    return\
    \ false;\n  }\n\n  std::vector<int> build_path(const int s, const int t) const\
    \ {\n    std::vector<int> res;\n    if (dist[s][t] != inf) {\n      build_path(s,\
    \ t, &res);\n      res.emplace_back(t);\n    }\n    return res;\n  }\n\n private:\n\
    \  const T inf;\n  const int n;\n  std::vector<int> srcs, dsts;\n  std::vector<T>\
    \ costs;\n  std::vector<std::vector<int>> internal;\n\n  void build_path(const\
    \ int s, const int t, std::vector<int>* path) const {\n    const int k = internal[s][t];\n\
    \    if (k == -1) {\n      (*path).emplace_back(s);\n    } else {\n      build_path(s,\
    \ k, path);\n      build_path(k, t, path);\n    }\n  }\n};\n\n}  // namespace\
    \ emthrm\n\n\n#line 11 \"test/graph/shortest_path/warshall-floyd.test.cpp\"\n\n\
    int main() {\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\n  while (true)\
    \ {\n    int n, k;\n    std::cin >> n >> k;\n    if (n == 0 && k == 0) [[unlikely]]\
    \ break;\n    std::vector<std::vector<long long>> graph(n,\n                 \
    \                             std::vector<long long>(n, LINF));\n    for (int\
    \ i = 0; i < n; ++i) {\n      graph[i][i] = 0;\n    }\n    emthrm::WarshallFloyd<long\
    \ long> warshall_floyd(graph, LINF);\n    while (k--) {\n      int type;\n   \
    \   std::cin >> type;\n      if (type == 0) {\n        int a, b;\n        std::cin\
    \ >> a >> b;\n        --a; --b;\n        std::cout << (warshall_floyd.dist[a][b]\
    \ == LINF ?\n                      -1 : warshall_floyd.dist[a][b])\n         \
    \         << '\\n';\n      } else if (type == 1) {\n        int c, d;\n      \
    \  long long e;\n        std::cin >> c >> d >> e;\n        --c; --d;\n       \
    \ warshall_floyd.add(c, d, e);\n        warshall_floyd.add(d, c, e);\n       \
    \ warshall_floyd.calc();\n      }\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall\u2013\
    Floyd \u6CD5\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/shortest_path/warshall-floyd.hpp\"\
    \n\nint main() {\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\n  while\
    \ (true) {\n    int n, k;\n    std::cin >> n >> k;\n    if (n == 0 && k == 0)\
    \ [[unlikely]] break;\n    std::vector<std::vector<long long>> graph(n,\n    \
    \                                          std::vector<long long>(n, LINF));\n\
    \    for (int i = 0; i < n; ++i) {\n      graph[i][i] = 0;\n    }\n    emthrm::WarshallFloyd<long\
    \ long> warshall_floyd(graph, LINF);\n    while (k--) {\n      int type;\n   \
    \   std::cin >> type;\n      if (type == 0) {\n        int a, b;\n        std::cin\
    \ >> a >> b;\n        --a; --b;\n        std::cout << (warshall_floyd.dist[a][b]\
    \ == LINF ?\n                      -1 : warshall_floyd.dist[a][b])\n         \
    \         << '\\n';\n      } else if (type == 1) {\n        int c, d;\n      \
    \  long long e;\n        std::cin >> c >> d >> e;\n        --c; --d;\n       \
    \ warshall_floyd.add(c, d, e);\n        warshall_floyd.add(d, c, e);\n       \
    \ warshall_floyd.calc();\n      }\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/shortest_path/warshall-floyd.hpp
  isVerificationFile: true
  path: test/graph/shortest_path/warshall-floyd.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/shortest_path/warshall-floyd.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path/warshall-floyd.test.cpp
- /verify/test/graph/shortest_path/warshall-floyd.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall\u2013Floyd \u6CD5"
---
