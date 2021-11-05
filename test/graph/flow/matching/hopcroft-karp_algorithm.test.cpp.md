---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/flow/matching/hopcroft-karp_algorithm.hpp
    title: Hopcroft-Karp algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
      \u30B0/Hopcroft-Karp algorithm"
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/matching/hopcroft-karp_algorithm.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/Hopcroft-Karp algorithm\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../../graph/flow/matching/hopcroft-karp_algorithm.hpp\"\
    \r\n\r\nint main() {\r\n  int l, r, m;\r\n  std::cin >> l >> r >> m;\r\n  HopcroftKarp\
    \ hopcroft_karp(l, r);\r\n  while (m--) {\r\n    int a, b;\r\n    std::cin >>\
    \ a >> b;\r\n    hopcroft_karp.add_edge(a, b);\r\n  }\r\n  std::cout << hopcroft_karp.solve()\
    \ << '\\n';\r\n  for (int i = 0; i < l; ++i) {\r\n    if (hopcroft_karp.match[i]\
    \ != -1) {\r\n      std::cout << i << ' ' << hopcroft_karp.match[i] - l << '\\\
    n';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/flow/matching/hopcroft-karp_algorithm.hpp
  isVerificationFile: true
  path: test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp
  requiredBy: []
  timestamp: '2021-09-14 04:44:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp
- /verify/test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/Hopcroft-Karp\
  \ algorithm"
---
