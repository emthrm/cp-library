---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/flow/maximum_flow/ford-fulkerson.hpp
    title: "Ford\u2013Fulkerson \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford\u2013\
      Fulkerson \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
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
    \ graph/flow/maximum_flow/ford-fulkerson.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford\u2013\
    Fulkerson \u6CD5\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <iostream>\n\n#include \"../../../../graph/flow/maximum_flow/ford-fulkerson.hpp\"\
    \n\nint main() {\n  int v, e;\n  std::cin >> v >> e;\n  FordFulkerson<long long>\
    \ ford_fulkerson(v);\n  while (e--) {\n    int u_i, v_i, c_i;\n    std::cin >>\
    \ u_i >> v_i >> c_i;\n    ford_fulkerson.add_edge(u_i, v_i, c_i);\n  }\n  std::cout\
    \ << ford_fulkerson.maximum_flow(0, v - 1) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - graph/flow/maximum_flow/ford-fulkerson.hpp
  isVerificationFile: true
  path: test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
- /verify/test/graph/flow/maximum_flow/ford-fulkerson.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford\u2013Fulkerson\
  \ \u6CD5"
---
