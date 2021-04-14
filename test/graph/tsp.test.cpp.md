---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/tsp.hpp
    title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C (traveling\
      \ salesman problem)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
    document_title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
      \u30F3\u554F\u984C"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
    \u30F3\u554F\u984C\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#include <limits>\r\n#include <vector>\r\n#include\
    \ \"../../graph/tsp.hpp\"\r\n\r\nint main() {\r\n  constexpr int INF = std::numeric_limits<int>::max();\r\
    \n  int v, e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<Edge<int>>>\
    \ g(v);\r\n  while (e--) {\r\n    int s, t, d;\r\n    std::cin >> s >> t >> d;\r\
    \n    g[s].emplace_back(s, t, d);\r\n  }\r\n  int ans = tsp(g, INF);\r\n  std::cout\
    \ << (ans == INF ? -1 : ans) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/tsp.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/graph/tsp.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tsp.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tsp.test.cpp
- /verify/test/graph/tsp.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C"
---
