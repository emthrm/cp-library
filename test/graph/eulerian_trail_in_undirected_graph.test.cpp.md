---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/eulerian_trail_in_undirected_graph.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\u7248"
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
    document_title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\
      \u30B0\u30E9\u30D5\u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0086
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/eulerian_trail_in_undirected_graph.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\
    \u30B0\u30E9\u30D5\u7248\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0086\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n#include\
    \ \"../../graph/eulerian_trail_in_undirected_graph.hpp\"\r\n\r\nint main() {\r\
    \n  int ai, bi;\r\n  while (std::cin >> ai >> bi) {\r\n    --ai; --bi;\r\n   \
    \ std::vector<int> a{ai}, b{bi};\r\n    while (true) {\r\n      std::cin >> ai\
    \ >> bi;\r\n      if (ai == 0 && bi == 0) break;\r\n      --ai; --bi;\r\n    \
    \  a.emplace_back(ai);\r\n      b.emplace_back(bi);\r\n    }\r\n    int n = std::max(*std::max_element(a.begin(),\
    \ a.end()), *std::max_element(b.begin(), b.end())) + 1;\r\n    EulerianTrailInUndirectedGraph\
    \ et(n);\r\n    for (int i = 0; i < a.size(); ++i) et.add_edge(a[i], b[i]);\r\n\
    \    std::cout << (et.build(0) && et.trail.back() == 1 ? \"OK\\n\" : \"NG\\n\"\
    );\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/eulerian_trail_in_undirected_graph.hpp
  isVerificationFile: true
  path: test/graph/eulerian_trail_in_undirected_graph.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/eulerian_trail_in_undirected_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/eulerian_trail_in_undirected_graph.test.cpp
- /verify/test/graph/eulerian_trail_in_undirected_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\
  \u30D5\u7248"
---
