---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: graph/is_bipartite.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
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
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
    links:
    - https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\
    \r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../graph/edge.hpp\"\
    \r\n#include \"../../graph/is_bipartite.hpp\"\r\n\r\nint main() {\r\n  int n,\
    \ m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<Edge<bool>>> graph(n);\r\
    \n  for (int i = 0; i < m; ++i) {\r\n    int a, b;\r\n    std::cin >> a >> b;\r\
    \n    --a; --b;\r\n    graph[a].emplace_back(a, b);\r\n    graph[b].emplace_back(b,\
    \ a);\r\n  }\r\n  std::vector<int> color;\r\n  if (is_bipartite(graph, color))\
    \ {\r\n    int black = 0, white = 0;\r\n    for (int i = 0; i < n; ++i) ++(color[i]\
    \ == 1 ? black : white);\r\n    std::cout << static_cast<long long>(black) * white\
    \ - m << '\\n';\r\n  } else {\r\n    std::cout << static_cast<long long>(n) *\
    \ (n - 1) / 2 - m << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/is_bipartite.hpp
  isVerificationFile: true
  path: test/graph/is_bipartite.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/is_bipartite.test.cpp
layout: document
redirect_from:
- /verify/test/graph/is_bipartite.test.cpp
- /verify/test/graph/is_bipartite.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
---
