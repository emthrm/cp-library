---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: graph/eulerian_trail_in_directed_graph.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\u30D5\u7248"
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
    document_title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\
      \u30B0\u30E9\u30D5\u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\
    \u30B0\u30E9\u30D5\u7248\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n#include\
    \ \"../../graph/edge.hpp\"\r\n#include \"../../graph/eulerian_trail_in_directed_graph.hpp\"\
    \r\n\r\nint main() {\r\n  while (true) {\r\n    int n;\r\n    std::cin >> n;\r\
    \n    if (n == 0) break;\r\n    std::vector<std::vector<Edge<bool>>> graph(26);\r\
    \n    while (n--) {\r\n      std::string word;\r\n      std::cin >> word;\r\n\
    \      graph[word.front() - 'a'].emplace_back(word.front() - 'a', word.back()\
    \ - 'a');\r\n    }\r\n    std::vector<int> trail = eulerian_trail_in_directed_graph(graph);\r\
    \n    std::cout << (!trail.empty() && trail.front() == trail.back() ? \"OK\\n\"\
    \ : \"NG\\n\");\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/eulerian_trail_in_directed_graph.hpp
  isVerificationFile: true
  path: test/graph/eulerian_trail_in_directed_graph.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/eulerian_trail_in_directed_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/eulerian_trail_in_directed_graph.test.cpp
- /verify/test/graph/eulerian_trail_in_directed_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\
  \u30D5\u7248"
---
