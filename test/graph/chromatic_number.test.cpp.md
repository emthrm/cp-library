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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u5F69\u8272\u6570\n */\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"../../graph/chromatic_number.hpp\"\n#include \"\
    ../../graph/edge.hpp\"\n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n \
    \ std::vector<std::vector<Edge<bool>>> graph(n);\n  while (m--) {\n    int u,\
    \ v;\n    std::cin >> u >> v;\n    graph[u].emplace_back(u, v);\n    graph[v].emplace_back(v,\
    \ u);\n  }\n  std::cout << chromatic_number(graph) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - graph/chromatic_number.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/graph/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/graph/chromatic_number.test.cpp
- /verify/test/graph/chromatic_number.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
---
