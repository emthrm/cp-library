---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union-find/union-find.hpp
    title: "union-find \u6728"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/mst/kruskal.hpp
    title: "Kruskal \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    document_title: "\u30B0\u30E9\u30D5/\u6700\u5C0F\u5168\u57DF\u6728/Kruskal \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6700\u5C0F\u5168\u57DF\u6728/Kruskal\
    \ \u6CD5\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../graph/edge.hpp\"\
    \r\n#include \"../../../graph/mst/kruskal.hpp\"\r\n\r\nint main() {\r\n  int v,\
    \ e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<Edge<long long>>> edge(v);\r\
    \n  for (int i = 0; i < e; ++i) {\r\n    int s, t, w;\r\n    std::cin >> s >>\
    \ t >> w;\r\n    edge[s].emplace_back(s, t, w);\r\n    edge[t].emplace_back(t,\
    \ s, w);\r\n  }\r\n  std::cout << kruskal(edge) << '\\n';\r\n  return 0;\r\n}\r\
    \n"
  dependsOn:
  - graph/edge.hpp
  - graph/mst/kruskal.hpp
  - data_structure/union-find/union-find.hpp
  isVerificationFile: true
  path: test/graph/mst/kruskal.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/mst/kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/graph/mst/kruskal.test.cpp
- /verify/test/graph/mst/kruskal.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6700\u5C0F\u5168\u57DF\u6728/Kruskal \u6CD5"
---
