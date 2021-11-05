---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/unicyclic_graph.hpp
    title: unicyclic graph (1-tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1254
    document_title: "\u30B0\u30E9\u30D5/unicyclic graph"
    links:
    - https://yukicoder.me/problems/no/1254
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/unicyclic graph\r\n */\r\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1254\"\r\n\r\n#include <iostream>\r\n#include\
    \ <map>\r\n#include <utility>\r\n#include <vector>\r\n#include \"../../graph/edge.hpp\"\
    \r\n#include \"../../graph/unicyclic_graph.hpp\"\r\n\r\nint main() {\r\n  int\
    \ n;\r\n  std::cin >> n;\r\n  std::map<std::pair<int, int>, int> edge;\r\n  UnicyclicGraph<bool>\
    \ namori(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    int a, b;\r\n    std::cin\
    \ >> a >> b;\r\n    --a; --b;\r\n    if (a > b) std::swap(a, b);\r\n    edge[{a,\
    \ b}] = i;\r\n    namori.add_edge(a, b, false);\r\n  }\r\n  namori.build();\r\n\
    \  std::vector<bool> bridge(n, false);\r\n  for (const Edge<bool> &e : namori.loop)\
    \ {\r\n    int a = e.src, b = e.dst;\r\n    if (a > b) std::swap(a, b);\r\n  \
    \  bridge[edge[{a, b}]] = true;\r\n  }\r\n  std::vector<int> p;\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    if (bridge[i]) p.emplace_back(i);\r\n  }\r\n  int\
    \ k = p.size();\r\n  std::cout << k << '\\n';\r\n  for (int i = 0; i < k; ++i)\
    \ std::cout << p[i] + 1 << \" \\n\"[i + 1 == k];\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/unicyclic_graph.hpp
  isVerificationFile: true
  path: test/graph/unicyclic_graph.test.cpp
  requiredBy: []
  timestamp: '2021-04-19 05:48:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/unicyclic_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/unicyclic_graph.test.cpp
- /verify/test/graph/unicyclic_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/unicyclic graph"
---
