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
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\
    \u30B0\u30E9\u30D5\u7248\n */\n#define IGNORE\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"../../graph/edge.hpp\"\
    \n#include \"../../graph/eulerian_trail_in_directed_graph.hpp\"\n\nint main()\
    \ {\n  constexpr int SIGMA = 26;\n  while (true) {\n    int n;\n    std::cin >>\
    \ n;\n    if (n == 0) break;\n    std::vector<std::vector<Edge<bool>>> graph(SIGMA);\n\
    \    while (n--) {\n      std::string word;\n      std::cin >> word;\n      graph[word.front()\
    \ - 'a'].emplace_back(word.front() - 'a',\n                                  \
    \           word.back() - 'a');\n    }\n    const std::vector<Edge<bool>> trail\
    \ =\n        eulerian_trail_in_directed_graph(graph);\n    std::cout << (!trail.empty()\
    \ && trail.front().src == trail.back().dst ?\n                  \"OK\\n\" : \"\
    NG\\n\");\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/edge.hpp
  - graph/eulerian_trail_in_directed_graph.hpp
  isVerificationFile: true
  path: test/graph/eulerian_trail_in_directed_graph.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
