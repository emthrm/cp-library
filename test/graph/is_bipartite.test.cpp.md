---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union-find/union-find.hpp
    title: union-find
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/is_bipartite.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc099/tasks/arc099_e
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
    links:
    - https://atcoder.jp/contests/arc099/tasks/arc099_c
    - https://atcoder.jp/contests/arc099/tasks/arc099_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/union-find.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\
    \r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/arc099/tasks/arc099_e\"\
    \r\n// #define PROBLEM \"https://atcoder.jp/contests/arc099/tasks/arc099_c\"\r\
    \n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <map>\r\n#include\
    \ <tuple>\r\n#include <utility>\r\n#include <vector>\r\n\r\n#include \"../../data_structure/union-find/union-find.hpp\"\
    \r\n#include \"../../graph/edge.hpp\"\r\n#include \"../../graph/is_bipartite.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  int ans = m;\r\
    \n  std::vector<std::vector<bool>> is_adjacent(n, std::vector<bool>(n, false));\r\
    \n  while (m--) {\r\n    int a, b;\r\n    std::cin >> a >> b;\r\n    --a; --b;\r\
    \n    is_adjacent[a][b] = true;\r\n    is_adjacent[b][a] = true;\r\n  }\r\n  UnionFind\
    \ union_find(n);\r\n  std::vector<std::vector<Edge<bool>>> graph(n);\r\n  for\
    \ (int i = 0; i < n; ++i) {\r\n    for (int j = i + 1; j < n; ++j) {\r\n     \
    \ if (!is_adjacent[i][j]) {\r\n        union_find.unite(i, j);\r\n        graph[i].emplace_back(i,\
    \ j);\r\n        graph[j].emplace_back(j, i);\r\n      }\r\n    }\r\n  }\r\n \
    \ std::vector<int> color;\r\n  if (!is_bipartite(graph, &color)) {\r\n    std::cout\
    \ << \"-1\\n\";\r\n    return 0;\r\n  }\r\n  std::vector<bool> dp(n + 1, false);\r\
    \n  dp[0] = true;\r\n  std::map<int, int> mp;\r\n  for (int i = 0; i < n; ++i)\
    \ {\r\n    mp[union_find.root(i)] += color[i];\r\n  }\r\n  for (const std::pair<int,\
    \ int>& pr : mp) {\r\n    int root, size;\r\n    std::tie(root, size) = pr;\r\n\
    \    for (int i = n; i >= 0; --i) {\r\n      if (dp[i]) {\r\n        dp[i] = false;\r\
    \n        if (i + size <= n) dp[i + size] = true;\r\n        if (i + union_find.size(root)\
    \ - size <= n) {\r\n          dp[i + union_find.size(root) - size] = true;\r\n\
    \        }\r\n      }\r\n    }\r\n  }\r\n  for (int i = 0; i <= n; ++i) {\r\n\
    \    if (dp[i]) ans = std::min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1) /\
    \ 2);\r\n  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/union-find/union-find.hpp
  - graph/edge.hpp
  - graph/is_bipartite.hpp
  isVerificationFile: true
  path: test/graph/is_bipartite.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 23:25:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/is_bipartite.test.cpp
layout: document
redirect_from:
- /verify/test/graph/is_bipartite.test.cpp
- /verify/test/graph/is_bipartite.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
---
