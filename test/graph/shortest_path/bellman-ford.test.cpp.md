---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/bellman-ford.hpp
    title: "Bellman\u2013Ford \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    document_title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman\u2013\
      Ford \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
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
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman\u2013\
    Ford \u6CD5\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../graph/edge.hpp\"\
    \n#include \"../../../graph/shortest_path/bellman-ford.hpp\"\n\nint main() {\n\
    \  int v, e, r;\n  std::cin >> v >> e >> r;\n  std::vector<std::vector<Edge<long\
    \ long>>> graph(v);\n  while (e--) {\n    int s, t, d;\n    std::cin >> s >> t\
    \ >> d;\n    graph[s].emplace_back(s, t, d);\n  }\n  BellmanFord<long long> bellman_ford(graph);\n\
    \  if (bellman_ford.has_negative_cycle(r)) {\n    std::cout << \"NEGATIVE CYCLE\\\
    n\";\n    return 0;\n  }\n  for (int i = 0; i < v; ++i) {\n    if (bellman_ford.dist[i]\
    \ == bellman_ford.inf) {\n      std::cout << \"INF\\n\";\n    } else {\n     \
    \ std::cout << bellman_ford.dist[i] << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/edge.hpp
  - graph/shortest_path/bellman-ford.hpp
  isVerificationFile: true
  path: test/graph/shortest_path/bellman-ford.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/shortest_path/bellman-ford.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path/bellman-ford.test.cpp
- /verify/test/graph/shortest_path/bellman-ford.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman\u2013Ford \u6CD5"
---
