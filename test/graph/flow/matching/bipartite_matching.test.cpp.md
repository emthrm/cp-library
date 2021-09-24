---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/flow/matching/bipartite_matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
      \u30B0/\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/matching/bipartite_matching.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
    \u30B0\r\n */\r\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../../graph/flow/matching/bipartite_matching.hpp\"\
    \r\n\r\nint main() {\r\n  int x, y, e;\r\n  std::cin >> x >> y >> e;\r\n  BipartiteMatching\
    \ bipartite_matching(x + y);\r\n  while (e--) {\r\n    int x_i, y_i;\r\n    std::cin\
    \ >> x_i >> y_i;\r\n    bipartite_matching.add_edge(x_i, y_i + x);\r\n  }\r\n\
    \  std::cout << bipartite_matching.solve() << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/flow/matching/bipartite_matching.hpp
  isVerificationFile: true
  path: test/graph/flow/matching/bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '2021-09-14 04:44:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/matching/bipartite_matching.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/matching/bipartite_matching.test.cpp
- /verify/test/graph/flow/matching/bipartite_matching.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E8C\
  \u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
