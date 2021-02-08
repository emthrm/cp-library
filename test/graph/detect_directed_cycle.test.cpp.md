---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/detect_directed_cycle.hpp
    title: "\u9589\u8DEF\u306E\u691C\u51FA \u6709\u5411\u30B0\u30E9\u30D5\u7248"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
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
    document_title: "\u30B0\u30E9\u30D5/\u9589\u8DEF\u306E\u691C\u51FA \u6709\u5411\
      \u30B0\u30E9\u30D5\u7248"
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u9589\u8DEF\u306E\u691C\u51FA \u6709\u5411\
    \u30B0\u30E9\u30D5\u7248\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../graph/edge.hpp\"\
    \r\n#include \"../../graph/detect_directed_cycle.hpp\"\r\n\r\nint main() {\r\n\
    \  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<Edge<int>>>\
    \ graph(n);\r\n  for (int i = 0; i < m; ++i) {\r\n    int u, v;\r\n    std::cin\
    \ >> u >> v;\r\n    graph[u].emplace_back(u, v, i);\r\n  }\r\n  std::vector<int>\
    \ e;\r\n  for (const Edge<int> &edge : detect_directed_cycle(graph)) e.emplace_back(edge.cost);\r\
    \n  if (e.empty()) {\r\n    std::cout << \"-1\\n\";\r\n  } else {\r\n    std::cout\
    \ << e.size() << '\\n';\r\n    for (int ver : e) std::cout << ver << '\\n';\r\n\
    \  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/detect_directed_cycle.hpp
  isVerificationFile: true
  path: test/graph/detect_directed_cycle.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/detect_directed_cycle.test.cpp
layout: document
redirect_from:
- /verify/test/graph/detect_directed_cycle.test.cpp
- /verify/test/graph/detect_directed_cycle.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u9589\u8DEF\u306E\u691C\u51FA \u6709\u5411\u30B0\u30E9\
  \u30D5\u7248"
---
