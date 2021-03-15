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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra\
    \ \u6CD5\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../graph/edge.hpp\"\
    \r\n#include \"../../../graph/shortest_path/dijkstra.hpp\"\r\n\r\nint main() {\r\
    \n  int n, m, s, t;\r\n  std::cin >> n >> m >> s >> t;\r\n  std::vector<std::vector<Edge<long\
    \ long>>> graph(n);\r\n  while (m--) {\r\n    int a, b, c;\r\n    std::cin >>\
    \ a >> b >> c;\r\n    graph[a].emplace_back(a, b, c);\r\n  }\r\n  Dijkstra<long\
    \ long> dij(graph);\r\n  long long x = dij.build(s)[t];\r\n  if (x == dij.inf)\
    \ {\r\n    std::cout << \"-1\\n\";\r\n    return 0;\r\n  }\r\n  std::vector<int>\
    \ path = dij.build_path(t);\r\n  int y = static_cast<int>(path.size()) - 1;\r\n\
    \  std::cout << x << ' ' << y << '\\n';\r\n  for (int i = 0; i < y; ++i) std::cout\
    \ << path[i] << ' ' << path[i + 1] << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/shortest_path/dijkstra.hpp
  isVerificationFile: true
  path: test/graph/shortest_path/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/shortest_path/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path/dijkstra.test.cpp
- /verify/test/graph/shortest_path/dijkstra.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra \u6CD5"
---
