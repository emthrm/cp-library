---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union-find/union-find.hpp
    title: union-find
  - icon: ':x:'
    path: graph/connencted_component_of_complement_graph.hpp
    title: "\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
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
    document_title: "\u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\
      \u6210\u5206\u5206\u89E3"
    links:
    - https://codeforces.com/problemset/problem/1242/B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\
    \u6210\u5206\u5206\u89E3\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://codeforces.com/problemset/problem/1242/B\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../graph/connencted_component_of_complement_graph.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<Edge<bool>>>\
    \ graph(n);\r\n  while (m--) {\r\n    int a, b;\r\n    std::cin >> a >> b;\r\n\
    \    --a; --b;\r\n    graph[a].emplace_back(a, b);\r\n    graph[b].emplace_back(b,\
    \ a);\r\n  }\r\n  UnionFind uf = connencted_component_of_complement_graph(graph);\r\
    \n  int ans = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n    ans += uf.root(i) ==\
    \ i;\r\n  }\r\n  std::cout << ans - 1 << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/connencted_component_of_complement_graph.hpp
  - graph/edge.hpp
  - data_structure/union-find/union-find.hpp
  isVerificationFile: true
  path: test/graph/connencted_component_of_complement_graph.test.cpp
  requiredBy: []
  timestamp: '2021-04-27 21:35:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/connencted_component_of_complement_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/connencted_component_of_complement_graph.test.cpp
- /verify/test/graph/connencted_component_of_complement_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\
  \u89E3"
---
