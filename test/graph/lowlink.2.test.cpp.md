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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    document_title: "\u30B0\u30E9\u30D5/lowlink (\u95A2\u7BC0\u70B9)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/lowlink (\u95A2\u7BC0\u70B9)\r\n */\r\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n\r\
    \n#include \"../../graph/edge.hpp\"\r\n#include \"../../graph/lowlink.hpp\"\r\n\
    \r\nint main() {\r\n  int v, e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<Edge<bool>>>\
    \ graph(v);\r\n  while (e--) {\r\n    int s, t;\r\n    std::cin >> s >> t;\r\n\
    \    graph[s].emplace_back(s, t);\r\n    graph[t].emplace_back(t, s);\r\n  }\r\
    \n  std::vector<int> articulation_points =\r\n      Lowlink<bool>(graph).articulation_points;\r\
    \n  std::sort(articulation_points.begin(), articulation_points.end());\r\n  for\
    \ (const int articulation_point : articulation_points) {\r\n    std::cout << articulation_point\
    \ << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/lowlink.hpp
  isVerificationFile: true
  path: test/graph/lowlink.2.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lowlink.2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lowlink.2.test.cpp
- /verify/test/graph/lowlink.2.test.cpp.html
title: "\u30B0\u30E9\u30D5/lowlink (\u95A2\u7BC0\u70B9)"
---
