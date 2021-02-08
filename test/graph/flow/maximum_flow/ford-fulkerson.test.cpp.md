---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/flow/maximum_flow/ford-fulkerson.hpp
    title: "Ford-Fulkerson \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford-Fulkerson\
      \ \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/maximum_flow/ford-fulkerson.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41\
    /Ford-Fulkerson \u6CD5\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \r\n\r\n#include <iostream>\r\n#include <limits>\r\n#include \"../../../../graph/flow/maximum_flow/ford-fulkerson.hpp\"\
    \r\n\r\nint main() {\r\n  int v, e;\r\n  std::cin >> v >> e;\r\n  FordFulkerson<long\
    \ long> ff(v);\r\n  while (e--) {\r\n    int ui, vi, ci;\r\n    std::cin >> ui\
    \ >> vi >> ci;\r\n    ff.add_edge(ui, vi, ci);\r\n  }\r\n  std::cout << ff.maximum_flow(0,\
    \ v - 1, std::numeric_limits<long long>::max()) << '\\n';\r\n  return 0;\r\n}\r\
    \n"
  dependsOn:
  - graph/flow/maximum_flow/ford-fulkerson.hpp
  isVerificationFile: true
  path: test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
- /verify/test/graph/flow/maximum_flow/ford-fulkerson.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford-Fulkerson \u6CD5"
---
