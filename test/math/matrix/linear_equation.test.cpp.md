---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/shortest_path/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  - icon: ':question:'
    path: include/emthrm/math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss\u2013Jordan elimination)"
  - icon: ':x:'
    path: include/emthrm/math/matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\
    \u5F0F\n */\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171\"\
    \n#define ERROR \"1e-8\"\n\n#include <iomanip>\n#include <iostream>\n#include\
    \ <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/shortest_path/dijkstra.hpp\"\
    \n#include \"emthrm/math/matrix/linear_equation.hpp\"\n#include \"emthrm/math/matrix/matrix.hpp\"\
    \n\nint main() {\n  while (true) {\n    int n, s, t;\n    std::cin >> n >> s >>\
    \ t;\n    if (n == 0 && s == 0 && t == 0) break;\n    --s; --t;\n    std::vector<int>\
    \ q(n);\n    for (int i = 0; i < n; ++i) {\n      std::cin >> q[i];\n    }\n \
    \   std::vector<std::vector<emthrm::Edge<int>>> graph(n);\n    for (int i = 0;\
    \ i < n; ++i) {\n      for (int j = 0; j < n; ++j) {\n        int a;\n       \
    \ std::cin >> a;\n        if (a > 0) graph[i].emplace_back(i, j, a);\n      }\n\
    \    }\n    emthrm::Dijkstra<int> dijkstra(graph);\n    const std::vector<int>\
    \ dist = dijkstra.build(t);\n    if (dist[s] == dijkstra.inf) {\n      std::cout\
    \ << \"impossible\\n\";\n      continue;\n    }\n    emthrm::Matrix<int> a(n,\
    \ n, 0);\n    std::vector<int> b(n, 0);\n    for (int i = 0; i < n; ++i) {\n \
    \     if (i == t) {\n        a[i][i] = 1;\n      } else {\n        std::vector<emthrm::Edge<int>>\
    \ edges;\n        if (q[i] == 0) {\n          edges = graph[i];\n        } else\
    \ if (q[i] == 1) {\n          for (const emthrm::Edge<int>& e : graph[i]) {\n\
    \            if (dist[e.dst] + e.cost == dist[i]) edges.emplace_back(e);\n   \
    \       }\n        }\n        a[i][i] = -edges.size();\n        for (const emthrm::Edge<int>&\
    \ e : edges) {\n          ++a[i][e.dst];\n          b[i] -= e.cost;\n        }\n\
    \      }\n    }\n    std::cout << std::fixed << std::setprecision(8)\n       \
    \       << emthrm::linear_equation(a, b)[s] << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/shortest_path/dijkstra.hpp
  - include/emthrm/math/matrix/linear_equation.hpp
  - include/emthrm/math/matrix/gauss_jordan.hpp
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: true
  path: test/math/matrix/linear_equation.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/matrix/linear_equation.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/linear_equation.test.cpp
- /verify/test/math/matrix/linear_equation.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
---
