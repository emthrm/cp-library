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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/lowlink (\u95A2\u7BC0\u70B9)\n */\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"\
    ../../graph/edge.hpp\"\n#include \"../../graph/lowlink.hpp\"\n\nint main() {\n\
    \  int v, e;\n  std::cin >> v >> e;\n  std::vector<std::vector<Edge<bool>>> graph(v);\n\
    \  while (e--) {\n    int s, t;\n    std::cin >> s >> t;\n    graph[s].emplace_back(s,\
    \ t);\n    graph[t].emplace_back(t, s);\n  }\n  std::vector<int> articulation_points\
    \ =\n      Lowlink<bool>(graph).articulation_points;\n  std::sort(articulation_points.begin(),\
    \ articulation_points.end());\n  for (const int articulation_point : articulation_points)\
    \ {\n    std::cout << articulation_point << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/edge.hpp
  - graph/lowlink.hpp
  isVerificationFile: true
  path: test/graph/lowlink.2.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lowlink.2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lowlink.2.test.cpp
- /verify/test/graph/lowlink.2.test.cpp.html
title: "\u30B0\u30E9\u30D5/lowlink (\u95A2\u7BC0\u70B9)"
---
