---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/chromatic_number.hpp
    title: "\u5F69\u8272\u6570 (chromatic number)"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    document_title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u5F69\u8272\u6570\r\n */\r\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/chromatic_number\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n\r\n#include \"../../graph/chromatic_number.hpp\"\r\n#include\
    \ \"../../graph/edge.hpp\"\r\n\r\nint main() {\r\n  int n, m;\r\n  std::cin >>\
    \ n >> m;\r\n  std::vector<std::vector<Edge<bool>>> graph(n);\r\n  while (m--)\
    \ {\r\n    int u, v;\r\n    std::cin >> u >> v;\r\n    graph[u].emplace_back(u,\
    \ v);\r\n    graph[v].emplace_back(v, u);\r\n  }\r\n  std::cout << chromatic_number(graph)\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/chromatic_number.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/graph/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 23:25:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/graph/chromatic_number.test.cpp
- /verify/test/graph/chromatic_number.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
---
