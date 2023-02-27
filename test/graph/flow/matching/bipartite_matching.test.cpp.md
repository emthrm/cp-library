---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/matching/bipartite_matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
      \u30B0/\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "#line 1 \"test/graph/flow/matching/bipartite_matching.test.cpp\"\n\
    /*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0\
    /\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
    \n *\n * verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/graph/flow/matching/bipartite_matching.hpp\"\
    \n\n\n\n#include <vector>\n\nnamespace emthrm {\n\nstruct BipartiteMatching {\n\
    \  std::vector<int> match;\n\n  explicit BipartiteMatching(const int n)\n    \
    \  : match(n, -1), n(n), t(0), is_alive(n, true), is_used(n, 0), graph(n) {}\n\
    \n  void add_edge(const int u, const int v) {\n    graph[u].emplace_back(v);\n\
    \    graph[v].emplace_back(u);\n  }\n\n  int solve() {\n    int res = 0;\n   \
    \ for (int i = 0; i < n; ++i) {\n      if (is_alive[i] && match[i] == -1) {\n\
    \        ++t;\n        res += dfs(i);\n      }\n    }\n    return res;\n  }\n\n\
    \  void fix(const int ver) {\n    is_alive[ver] = false;\n    if (match[ver] !=\
    \ -1) is_alive[match[ver]] = false;\n  }\n\n  int activate(const int ver) {\n\
    \    if (is_alive[ver]) return 0;\n    is_alive[ver] = true;\n    ++t;\n    return\
    \ dfs(ver) ? 1 : 0;\n  }\n\n  int deactivate(const int ver) {\n    if (!is_alive[ver])\
    \ return 0;\n    is_alive[ver] = false;\n    const int m = match[ver];\n    if\
    \ (m == -1) return 0;\n    match[ver] = match[m] = -1;\n    ++t;\n    return dfs(m)\
    \ ? 0 : -1;\n  }\n\n private:\n  const int n;\n  int t;\n  std::vector<bool> is_alive;\n\
    \  std::vector<int> is_used;\n  std::vector<std::vector<int>> graph;\n\n  bool\
    \ dfs(const int ver) {\n    is_used[ver] = t;\n    for (const int dst : graph[ver])\
    \ {\n      if (!is_alive[dst]) continue;\n      const int m = match[dst];\n  \
    \    if (m == -1 || (is_used[m] < t && dfs(m))) {\n        match[ver] = dst;\n\
    \        match[dst] = ver;\n        return true;\n      }\n    }\n    return false;\n\
    \  }\n};\n\n}  // namespace emthrm\n\n\n#line 10 \"test/graph/flow/matching/bipartite_matching.test.cpp\"\
    \n\nint main() {\n  int x, y, e;\n  std::cin >> x >> y >> e;\n  emthrm::BipartiteMatching\
    \ bipartite_matching(x + y);\n  while (e--) {\n    int x_i, y_i;\n    std::cin\
    \ >> x_i >> y_i;\n    bipartite_matching.add_edge(x_i, y_i + x);\n  }\n  std::cout\
    \ << bipartite_matching.solve() << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
    \u30B0\n *\n * verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/graph/flow/matching/bipartite_matching.hpp\"\
    \n\nint main() {\n  int x, y, e;\n  std::cin >> x >> y >> e;\n  emthrm::BipartiteMatching\
    \ bipartite_matching(x + y);\n  while (e--) {\n    int x_i, y_i;\n    std::cin\
    \ >> x_i >> y_i;\n    bipartite_matching.add_edge(x_i, y_i + x);\n  }\n  std::cout\
    \ << bipartite_matching.solve() << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/matching/bipartite_matching.hpp
  isVerificationFile: true
  path: test/graph/flow/matching/bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/matching/bipartite_matching.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/matching/bipartite_matching.test.cpp
- /verify/test/graph/flow/matching/bipartite_matching.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E8C\
  \u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
