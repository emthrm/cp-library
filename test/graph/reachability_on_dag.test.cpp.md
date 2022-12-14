---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: graph/reachability_on_dag.hpp
    title: "\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\u306E\u5230\u9054\
      \u53EF\u80FD\u6027\u5224\u5B9A"
  - icon: ':x:'
    path: graph/topological_sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 (topological sort)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30B0\u30E9\u30D5/\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\
      \u30D5\u4E0A\u306E\u5230\u9054\u53EF\u80FD\u6027\u5224\u5B9A"
    links:
    - https://atcoder.jp/contests/typical90/tasks/typical90_bg
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\
    \u30D5\u4E0A\u306E\u5230\u9054\u53EF\u80FD\u6027\u5224\u5B9A\n */\n#define IGNORE\n\
    #define PROBLEM \"https://atcoder.jp/contests/typical90/tasks/typical90_bg\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"../../graph/edge.hpp\"\n\
    #include \"../../graph/reachability_on_dag.hpp\"\n\nint main() {\n  int n, m,\
    \ q;\n  std::cin >> n >> m >> q;\n  std::vector<std::vector<Edge<bool>>> graph(n);\n\
    \  while (m--) {\n    int x, y;\n    std::cin >> x >> y;\n    --x; --y;\n    graph[x].emplace_back(x,\
    \ y);\n  }\n  std::vector<int> a(q), b(q);\n  for (int i = 0; i < q; ++i) {\n\
    \    std::cin >> a[i] >> b[i];\n    --a[i]; --b[i];\n  }\n  for (const bool ans\
    \ : reachability_on_dag(graph, a, b)) {\n    std::cout << (ans ? \"Yes\\n\" :\
    \ \"No\\n\");\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/edge.hpp
  - graph/reachability_on_dag.hpp
  - graph/topological_sort.hpp
  isVerificationFile: true
  path: test/graph/reachability_on_dag.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/reachability_on_dag.test.cpp
layout: document
redirect_from:
- /verify/test/graph/reachability_on_dag.test.cpp
- /verify/test/graph/reachability_on_dag.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\u306E\
  \u5230\u9054\u53EF\u80FD\u6027\u5224\u5B9A"
---
