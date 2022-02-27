---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/detect_directed_cycle.hpp
    title: "\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    document_title: "\u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/detect_directed_cycle.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA\
    \r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../graph/detect_directed_cycle.hpp\"\
    \r\n#include \"../../graph/edge.hpp\"\r\n\r\nint main() {\r\n  int n, m;\r\n \
    \ std::cin >> n >> m;\r\n  std::vector<std::vector<Edge<int>>> graph(n);\r\n \
    \ for (int i = 0; i < m; ++i) {\r\n    int u, v;\r\n    std::cin >> u >> v;\r\n\
    \    graph[u].emplace_back(u, v, i);\r\n  }\r\n  std::vector<int> e;\r\n  for\
    \ (const Edge<int>& edge : detect_directed_cycle(graph)) {\r\n    e.emplace_back(edge.cost);\r\
    \n  }\r\n  if (e.empty()) {\r\n    std::cout << \"-1\\n\";\r\n  } else {\r\n \
    \   std::cout << e.size() << '\\n';\r\n    for (const int ver : e) std::cout <<\
    \ ver << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/detect_directed_cycle.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/graph/detect_directed_cycle.test.cpp
  requiredBy: []
  timestamp: '2022-02-23 17:39:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/detect_directed_cycle.test.cpp
layout: document
redirect_from:
- /verify/test/graph/detect_directed_cycle.test.cpp
- /verify/test/graph/detect_directed_cycle.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
---
