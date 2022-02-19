---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: graph/shortest_path/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  - icon: ':question:'
    path: math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss-Jordan elimination)"
  - icon: ':x:'
    path: math/matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-8
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171
    document_title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\
      \u5F0F"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\
    \u5F0F\r\n */\r\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171\"\
    \r\n#define ERROR \"1e-8\"\r\n\r\n#include <iomanip>\r\n#include <iostream>\r\n\
    #include <vector>\r\n\r\n#include \"../../../graph/edge.hpp\"\r\n#include \"../../../graph/shortest_path/dijkstra.hpp\"\
    \r\n#include \"../../../math/matrix/linear_equation.hpp\"\r\n#include \"../../../math/matrix/matrix.hpp\"\
    \r\n\r\nint main() {\r\n  while (true) {\r\n    int n, s, t;\r\n    std::cin >>\
    \ n >> s >> t;\r\n    if (n == 0 && s == 0 && t == 0) break;\r\n    --s; --t;\r\
    \n    std::vector<int> q(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      std::cin\
    \ >> q[i];\r\n    }\r\n    std::vector<std::vector<Edge<int>>> graph(n);\r\n \
    \   for (int i = 0; i < n; ++i) {\r\n      for (int j = 0; j < n; ++j) {\r\n \
    \       int a;\r\n        std::cin >> a;\r\n        if (a > 0) graph[i].emplace_back(i,\
    \ j, a);\r\n      }\r\n    }\r\n    Dijkstra<int> dijkstra(graph);\r\n    const\
    \ std::vector<int> dist = dijkstra.build(t);\r\n    if (dist[s] == dijkstra.inf)\
    \ {\r\n      std::cout << \"impossible\\n\";\r\n      continue;\r\n    }\r\n \
    \   Matrix<int> a(n, n, 0);\r\n    std::vector<int> b(n, 0);\r\n    for (int i\
    \ = 0; i < n; ++i) {\r\n      if (i == t) {\r\n        a[i][i] = 1;\r\n      }\
    \ else {\r\n        std::vector<Edge<int>> edges;\r\n        if (q[i] == 0) {\r\
    \n          edges = graph[i];\r\n        } else if (q[i] == 1) {\r\n         \
    \ for (const Edge<int>& e : graph[i]) {\r\n            if (dist[e.dst] + e.cost\
    \ == dist[i]) edges.emplace_back(e);\r\n          }\r\n        }\r\n        a[i][i]\
    \ = -edges.size();\r\n        for (const Edge<int>& e : edges) {\r\n         \
    \ ++a[i][e.dst];\r\n          b[i] -= e.cost;\r\n        }\r\n      }\r\n    }\r\
    \n    std::cout << std::fixed << std::setprecision(8)\r\n              << linear_equation(a,\
    \ b)[s] << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/shortest_path/dijkstra.hpp
  - math/matrix/linear_equation.hpp
  - math/matrix/gauss_jordan.hpp
  - math/matrix/matrix.hpp
  isVerificationFile: true
  path: test/math/matrix/linear_equation.test.cpp
  requiredBy: []
  timestamp: '2022-02-17 20:33:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/matrix/linear_equation.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/linear_equation.test.cpp
- /verify/test/math/matrix/linear_equation.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
---
