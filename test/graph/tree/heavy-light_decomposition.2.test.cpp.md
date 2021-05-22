---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/tree/heavy-light_decomposition.hpp
    title: "HL \u5206\u89E3 (heavy-light decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    document_title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\
      \u901A\u7956\u5148)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\
    \u901A\u7956\u5148)\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../graph/edge.hpp\"\
    \r\n#include \"../../../graph/tree/heavy-light_decomposition.hpp\"\r\n\r\nint\
    \ main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<Edge<int>>>\
    \ graph(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    int k;\r\n    std::cin >>\
    \ k;\r\n    while (k--) {\r\n      int c;\r\n      std::cin >> c;\r\n      graph[i].emplace_back(i,\
    \ c, 1);\r\n      graph[c].emplace_back(c, i, 1);\r\n    }\r\n  }\r\n  HeavyLightDecomposition<int>\
    \ hld(graph, 0);\r\n  int q;\r\n  std::cin >> q;\r\n  while (q--) {\r\n    int\
    \ u, v;\r\n    std::cin >> u >> v;\r\n    std::cout << hld.lowest_common_ancestor(u,\
    \ v) << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/tree/heavy-light_decomposition.hpp
  isVerificationFile: true
  path: test/graph/tree/heavy-light_decomposition.2.test.cpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/heavy-light_decomposition.2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/heavy-light_decomposition.2.test.cpp
- /verify/test/graph/tree/heavy-light_decomposition.2.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\u901A\u7956\u5148\
  )"
---
