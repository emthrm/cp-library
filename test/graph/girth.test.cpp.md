---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/girth_in_directed_graph.hpp
    title: "\u5185\u5468 \u6709\u5411\u30B0\u30E9\u30D5\u7248"
  - icon: ':heavy_check_mark:'
    path: graph/girth_in_undirected_graph.hpp
    title: "\u5185\u5468 \u7121\u5411\u30B0\u30E9\u30D5\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1320
    document_title: "\u30B0\u30E9\u30D5/\u5185\u5468"
    links:
    - https://yukicoder.me/problems/no/1320
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
    \ graph/girth_in_directed_graph.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u5185\u5468\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/1320\"\
    \n\n#include <iostream>\n#include <limits>\n#include <vector>\n\n#include \"../../graph/girth_in_directed_graph.hpp\"\
    \n#include \"../../graph/girth_in_undirected_graph.hpp\"\n\nint main() {\n  constexpr\
    \ long long LINF = std::numeric_limits<long long>::max();\n  int t, n, m;\n  std::cin\
    \ >> t >> n >> m;\n  if (t == 0) {\n    std::vector<Edge<long long>> edges;\n\
    \    while (m--) {\n      int u, v, w;\n      std::cin >> u >> v >> w;\n     \
    \ --u; --v;\n      edges.emplace_back(u, v, w);\n    }\n    const long long ans\
    \ = girth_in_undirected_graph(n, edges, LINF);\n    std::cout << (ans == LINF\
    \ ? -1 : ans) << '\\n';\n  } else if (t == 1) {\n    std::vector<std::vector<Edge<long\
    \ long>>> graph(n);\n    while (m--) {\n      int u, v, w;\n      std::cin >>\
    \ u >> v >> w;\n      --u; --v;\n      graph[u].emplace_back(u, v, w);\n    }\n\
    \    const long long ans = girth_in_directed_graph(graph, LINF);\n    std::cout\
    \ << (ans == LINF ? -1 : ans) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/girth_in_directed_graph.hpp
  - graph/edge.hpp
  - graph/girth_in_undirected_graph.hpp
  isVerificationFile: true
  path: test/graph/girth.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/girth.test.cpp
layout: document
redirect_from:
- /verify/test/graph/girth.test.cpp
- /verify/test/graph/girth.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5185\u5468"
---
