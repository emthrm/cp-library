---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: graph/shortest_path/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    document_title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra \u6CD5"
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra\
    \ \u6CD5\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../graph/edge.hpp\"\
    \n#include \"../../../graph/shortest_path/dijkstra.hpp\"\n\nint main() {\n  int\
    \ n, m, s, t;\n  std::cin >> n >> m >> s >> t;\n  std::vector<std::vector<Edge<long\
    \ long>>> graph(n);\n  while (m--) {\n    int a, b, c;\n    std::cin >> a >> b\
    \ >> c;\n    graph[a].emplace_back(a, b, c);\n  }\n  Dijkstra<long long> dijkstra(graph);\n\
    \  const long long x = dijkstra.build(s)[t];\n  if (x == dijkstra.inf) {\n   \
    \ std::cout << \"-1\\n\";\n    return 0;\n  }\n  const std::vector<int> path =\
    \ dijkstra.build_path(t);\n  const int y = path.size() - 1;\n  std::cout << x\
    \ << ' ' << y << '\\n';\n  for (int i = 0; i < y; ++i) {\n    std::cout << path[i]\
    \ << ' ' << path[i + 1] << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/edge.hpp
  - graph/shortest_path/dijkstra.hpp
  isVerificationFile: true
  path: test/graph/shortest_path/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/shortest_path/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path/dijkstra.test.cpp
- /verify/test/graph/shortest_path/dijkstra.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra \u6CD5"
---
