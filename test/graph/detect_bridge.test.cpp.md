---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/detect_bridge.hpp
    title: "\u6A4B\u306E\u691C\u51FA"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    document_title: "\u30B0\u30E9\u30D5/\u6A4B\u306E\u691C\u51FA"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6A4B\u306E\u691C\u51FA\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n#include\
    \ \"../../graph/edge.hpp\"\r\n#include \"../../graph/detect_bridge.hpp\"\r\n\r\
    \nint main() {\r\n  int v, e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<Edge<bool>>>\
    \ graph(v);\r\n  while (e--) {\r\n    int s, t;\r\n    std::cin >> s >> t;\r\n\
    \    graph[s].emplace_back(s, t);\r\n    graph[t].emplace_back(t, s);\r\n  }\r\
    \n  std::vector<Edge<bool>> bridges = detect_bridge(graph);\r\n  std::sort(bridges.begin(),\
    \ bridges.end(), [](const Edge<bool> &a, const Edge<bool> &b) -> bool {\r\n  \
    \  return a.src != b.src ? a.src < b.src : a.dst != b.dst ? a.dst < b.dst : a.cost\
    \ < b.cost;\r\n  });\r\n  for (const Edge<bool> &e : bridges) std::cout << e.src\
    \ << ' ' << e.dst << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/detect_bridge.hpp
  isVerificationFile: true
  path: test/graph/detect_bridge.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/detect_bridge.test.cpp
layout: document
redirect_from:
- /verify/test/graph/detect_bridge.test.cpp
- /verify/test/graph/detect_bridge.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6A4B\u306E\u691C\u51FA"
---
