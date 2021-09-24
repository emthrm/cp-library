---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: graph/topological_sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 (topological sort)"
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
    document_title: "\u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
      \u30FC\u30C8"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../graph/edge.hpp\"\
    \r\n#include \"../../graph/topological_sort.hpp\"\r\n\r\nint main() {\r\n  int\
    \ v, e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<Edge<bool>>> graph(v);\r\
    \n  while (e--) {\r\n    int s, t;\r\n    std::cin >> s >> t;\r\n    graph[s].emplace_back(s,\
    \ t);\r\n  }\r\n  for (const int ver : topological_sort(graph)) std::cout << ver\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/topological_sort.hpp
  isVerificationFile: true
  path: test/graph/topological_sort.test.cpp
  requiredBy: []
  timestamp: '2021-08-19 19:52:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/topological_sort.test.cpp
layout: document
redirect_from:
- /verify/test/graph/topological_sort.test.cpp
- /verify/test/graph/topological_sort.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---
