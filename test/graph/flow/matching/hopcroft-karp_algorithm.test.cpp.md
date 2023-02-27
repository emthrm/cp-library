---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/matching/hopcroft-karp_algorithm.hpp
    title: "Hopcroft\u2013Karp algorithm"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
      \u30B0/Hopcroft\u2013Karp algorithm"
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/Hopcroft\u2013Karp algorithm\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/bipartitematching\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/graph/flow/matching/hopcroft-karp_algorithm.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <queue>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\nstruct HopcroftKarp {\n  std::vector<int> match;\n\n  explicit HopcroftKarp(const\
    \ int left, const int right)\n      : match(left + right, -1), left(left), t(0),\
    \ level(left),\n        is_used(left, -1), graph(left) {}\n\n  void add_edge(const\
    \ int u, const int v) {\n    graph[u].emplace_back(left + v);\n  }\n\n  int solve()\
    \ {\n    int res = 0;\n    while (true) {\n      std::fill(level.begin(), level.end(),\
    \ -1);\n      std::queue<int> que;\n      for (int i = 0; i < left; ++i) {\n \
    \       if (match[i] == -1) {\n          que.emplace(i);\n          level[i] =\
    \ 0;\n        }\n      }\n      while (!que.empty()) {\n        const int ver\
    \ = que.front();\n        que.pop();\n        for (const int dst : graph[ver])\
    \ {\n          if (match[dst] != -1 && level[match[dst]] == -1) {\n          \
    \  level[match[dst]] = level[ver] + 1;\n            que.emplace(match[dst]);\n\
    \          }\n        }\n      }\n      int tmp = 0;\n      for (int i = 0; i\
    \ < left; ++i) {\n        if (match[i] == -1) {\n          tmp += dfs(i);\n  \
    \        ++t;\n        }\n      }\n      if (tmp == 0) break;\n      res += tmp;\n\
    \    }\n    return res;\n  }\n\n private:\n  const int left;\n  int t;\n  std::vector<int>\
    \ level, is_used;\n  std::vector<std::vector<int>> graph;\n\n  bool dfs(const\
    \ int ver) {\n    is_used[ver] = t;\n    for (const int dst : graph[ver]) {\n\
    \      const int m = match[dst];\n      if (m == -1 || (is_used[m] < t && level[m]\
    \ == level[ver] + 1 && dfs(m))) {\n        is_used[ver] = t;\n        match[ver]\
    \ = dst;\n        match[dst] = ver;\n        return true;\n      }\n    }\n  \
    \  return false;\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 10 \"test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp\"\
    \n\nint main() {\n  int l, r, m;\n  std::cin >> l >> r >> m;\n  emthrm::HopcroftKarp\
    \ hopcroft_karp(l, r);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n\
    \    hopcroft_karp.add_edge(a, b);\n  }\n  std::cout << hopcroft_karp.solve()\
    \ << '\\n';\n  for (int i = 0; i < l; ++i) {\n    if (hopcroft_karp.match[i] !=\
    \ -1) {\n      std::cout << i << ' ' << hopcroft_karp.match[i] - l << '\\n';\n\
    \    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/Hopcroft\u2013Karp algorithm\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/bipartitematching\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/graph/flow/matching/hopcroft-karp_algorithm.hpp\"\
    \n\nint main() {\n  int l, r, m;\n  std::cin >> l >> r >> m;\n  emthrm::HopcroftKarp\
    \ hopcroft_karp(l, r);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n\
    \    hopcroft_karp.add_edge(a, b);\n  }\n  std::cout << hopcroft_karp.solve()\
    \ << '\\n';\n  for (int i = 0; i < l; ++i) {\n    if (hopcroft_karp.match[i] !=\
    \ -1) {\n      std::cout << i << ' ' << hopcroft_karp.match[i] - l << '\\n';\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/matching/hopcroft-karp_algorithm.hpp
  isVerificationFile: true
  path: test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp
- /verify/test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/Hopcroft\u2013\
  Karp algorithm"
---
