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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/union-find.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\
    \n */\n#define PROBLEM \"https://atcoder.jp/contests/arc099/tasks/arc099_e\"\n\
    // #define PROBLEM \"https://atcoder.jp/contests/arc099/tasks/arc099_c\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <map>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n#include \"../../data_structure/union-find/union-find.hpp\"\
    \n#include \"../../graph/edge.hpp\"\n#include \"../../graph/is_bipartite.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  int ans = m;\n  std::vector<std::vector<bool>>\
    \ is_adjacent(n, std::vector<bool>(n, false));\n  while (m--) {\n    int a, b;\n\
    \    std::cin >> a >> b;\n    --a; --b;\n    is_adjacent[a][b] = true;\n    is_adjacent[b][a]\
    \ = true;\n  }\n  UnionFind union_find(n);\n  std::vector<std::vector<Edge<bool>>>\
    \ graph(n);\n  for (int i = 0; i < n; ++i) {\n    for (int j = i + 1; j < n; ++j)\
    \ {\n      if (!is_adjacent[i][j]) {\n        union_find.unite(i, j);\n      \
    \  graph[i].emplace_back(i, j);\n        graph[j].emplace_back(j, i);\n      }\n\
    \    }\n  }\n  std::vector<int> color;\n  if (!is_bipartite(graph, &color)) {\n\
    \    std::cout << \"-1\\n\";\n    return 0;\n  }\n  std::vector<bool> dp(n + 1,\
    \ false);\n  dp[0] = true;\n  std::map<int, int> mp;\n  for (int i = 0; i < n;\
    \ ++i) {\n    mp[union_find.root(i)] += color[i];\n  }\n  for (const std::pair<int,\
    \ int>& pr : mp) {\n    int root, size;\n    std::tie(root, size) = pr;\n    for\
    \ (int i = n; i >= 0; --i) {\n      if (dp[i]) {\n        dp[i] = false;\n   \
    \     if (i + size <= n) dp[i + size] = true;\n        if (i + union_find.size(root)\
    \ - size <= n) {\n          dp[i + union_find.size(root) - size] = true;\n   \
    \     }\n      }\n    }\n  }\n  for (int i = 0; i <= n; ++i) {\n    if (dp[i])\
    \ ans = std::min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);\n  }\n  std::cout\
    \ << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - data_structure/union-find/union-find.hpp
  - graph/edge.hpp
  - graph/is_bipartite.hpp
  isVerificationFile: true
  path: test/graph/is_bipartite.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/is_bipartite.test.cpp
layout: document
redirect_from:
- /verify/test/graph/is_bipartite.test.cpp
- /verify/test/graph/is_bipartite.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
---
