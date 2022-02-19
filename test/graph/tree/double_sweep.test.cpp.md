---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/tree/double_sweep.hpp
    title: double sweep
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    document_title: "\u30B0\u30E9\u30D5/\u6728/double sweep"
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6728/double sweep\r\n */\r\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\r\n\r\n#include <iostream>\r\
    \n#include <tuple>\r\n#include <vector>\r\n\r\n#include \"../../../graph/edge.hpp\"\
    \r\n#include \"../../../graph/tree/double_sweep.hpp\"\r\n\r\nint main() {\r\n\
    \  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<Edge<long long>>> graph(n);\r\
    \n  for (int i = 0; i < n - 1; ++i) {\r\n    int a, b, c;\r\n    std::cin >> a\
    \ >> b >> c;\r\n    graph[a].emplace_back(a, b, c);\r\n    graph[b].emplace_back(b,\
    \ a, c);\r\n  }\r\n  long long x;\r\n  std::vector<int> u;\r\n  std::tie(x, u)\
    \ = double_sweep(graph);\r\n  const int y = u.size();\r\n  std::cout << x << '\
    \ ' << y << '\\n';\r\n  for (int i = 0; i < y; ++i) {\r\n    std::cout << u[i]\
    \ << \" \\n\"[i + 1 == y];\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/tree/double_sweep.hpp
  isVerificationFile: true
  path: test/graph/tree/double_sweep.test.cpp
  requiredBy: []
  timestamp: '2022-02-15 13:02:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/double_sweep.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/double_sweep.test.cpp
- /verify/test/graph/tree/double_sweep.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/double sweep"
---
