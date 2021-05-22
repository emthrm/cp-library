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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/girth_in_undirected_graph.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u5185\u5468\r\n */\r\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1320\"\r\n\r\n#include <iostream>\r\n#include\
    \ <limits>\r\n#include <vector>\r\n#include \"../../graph/girth_in_undirected_graph.hpp\"\
    \r\n#include \"../../graph/girth_in_directed_graph.hpp\"\r\n\r\nint main() {\r\
    \n  constexpr long long LINF = std::numeric_limits<long long>::max();\r\n  int\
    \ t, n, m;\r\n  std::cin >> t >> n >> m;\r\n  if (t == 0) {\r\n    std::vector<Edge<long\
    \ long>> edges;\r\n    while (m--) {\r\n      int u, v, w;\r\n      std::cin >>\
    \ u >> v >> w;\r\n      --u; --v;\r\n      edges.emplace_back(u, v, w);\r\n  \
    \  }\r\n    long long ans = girth_in_undirected_graph(n, edges, LINF);\r\n   \
    \ std::cout << (ans == LINF ? -1 : ans) << '\\n';\r\n  } else if (t == 1) {\r\n\
    \    std::vector<std::vector<Edge<long long>>> graph(n);\r\n    while (m--) {\r\
    \n      int u, v, w;\r\n      std::cin >> u >> v >> w;\r\n      --u; --v;\r\n\
    \      graph[u].emplace_back(u, v, w);\r\n    }\r\n    long long ans = girth_in_directed_graph(graph,\
    \ LINF);\r\n    std::cout << (ans == LINF ? -1 : ans) << '\\n';\r\n  }\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - graph/girth_in_undirected_graph.hpp
  - graph/edge.hpp
  - graph/girth_in_directed_graph.hpp
  isVerificationFile: true
  path: test/graph/girth.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 17:25:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/girth.test.cpp
layout: document
redirect_from:
- /verify/test/graph/girth.test.cpp
- /verify/test/graph/girth.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5185\u5468"
---
