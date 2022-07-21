---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union-find/union-find.hpp
    title: union-find
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    document_title: "\u30B0\u30E9\u30D5/Kruskal \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/Kruskal \u6CD5\n */\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../graph/edge.hpp\"\n#include\
    \ \"../../graph/kruskal.hpp\"\n\nint main() {\n  int v, e;\n  std::cin >> v >>\
    \ e;\n  std::vector<std::vector<Edge<long long>>> edge(v);\n  for (int i = 0;\
    \ i < e; ++i) {\n    int s, t, w;\n    std::cin >> s >> t >> w;\n    edge[s].emplace_back(s,\
    \ t, w);\n    edge[t].emplace_back(t, s, w);\n  }\n  std::cout << kruskal(edge)\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - graph/edge.hpp
  - graph/kruskal.hpp
  - data_structure/union-find/union-find.hpp
  isVerificationFile: true
  path: test/graph/kruskal.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/graph/kruskal.test.cpp
- /verify/test/graph/kruskal.test.cpp.html
title: "\u30B0\u30E9\u30D5/Kruskal \u6CD5"
---
