---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    document_title: "\u30B0\u30E9\u30D5/lowlink (\u6A4B)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/lowlink (\u6A4B)\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\r\n\r\n\
    #include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n#include \"\
    ../../graph/edge.hpp\"\r\n#include \"../../graph/lowlink.hpp\"\r\n\r\nint main()\
    \ {\r\n  int v, e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<Edge<bool>>>\
    \ graph(v);\r\n  while (e--) {\r\n    int s, t;\r\n    std::cin >> s >> t;\r\n\
    \    graph[s].emplace_back(s, t);\r\n    graph[t].emplace_back(t, s);\r\n  }\r\
    \n  Lowlink<bool> low(graph);\r\n  std::sort(low.bridge.begin(), low.bridge.end(),\
    \ [](const Edge<bool> &a, const Edge<bool> &b) -> bool {\r\n    return a.src !=\
    \ b.src ? a.src < b.src : a.dst != b.dst ? a.dst < b.dst : a.cost < b.cost;\r\n\
    \  });\r\n  for (const Edge<bool> &e : low.bridge) std::cout << e.src << ' ' <<\
    \ e.dst << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/lowlink.hpp
  isVerificationFile: true
  path: test/graph/lowlink.1.test.cpp
  requiredBy: []
  timestamp: '2021-04-18 15:42:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lowlink.1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lowlink.1.test.cpp
- /verify/test/graph/lowlink.1.test.cpp.html
title: "\u30B0\u30E9\u30D5/lowlink (\u6A4B)"
---
