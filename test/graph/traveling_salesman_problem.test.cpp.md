---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/traveling_salesman_problem.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\
    \u30F3\u554F\u984C\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \n\n#include <iostream>\n#include <limits>\n#include <vector>\n\n#include \"../../graph/traveling_salesman_problem.hpp\"\
    \n\nint main() {\n  constexpr int INF = std::numeric_limits<int>::max();\n  int\
    \ v, e;\n  std::cin >> v >> e;\n  std::vector<std::vector<Edge<int>>> g(v);\n\
    \  while (e--) {\n    int s, t, d;\n    std::cin >> s >> t >> d;\n    g[s].emplace_back(s,\
    \ t, d);\n  }\n  const int ans = traveling_salesman_problem(g, INF);\n  std::cout\
    \ << (ans == INF ? -1 : ans) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - graph/traveling_salesman_problem.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/graph/traveling_salesman_problem.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/traveling_salesman_problem.test.cpp
layout: document
redirect_from:
- /verify/test/graph/traveling_salesman_problem.test.cpp
- /verify/test/graph/traveling_salesman_problem.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C"
---
