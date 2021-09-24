---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: graph/noshi_graph.hpp
    title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  - icon: ':question:'
    path: graph/shortest_path/dijkstra.hpp
    title: "Dijkstra \u6CD5"
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
    document_title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\
      \u30C6\u30AF"
    links:
    - https://codeforces.com/problemset/problem/786/B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\
    \u30C6\u30AF\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://codeforces.com/problemset/problem/786/B\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../graph/noshi_graph.hpp\"\
    \r\n#include \"../../graph/shortest_path/dijkstra.hpp\"\r\n\r\nint main() {\r\n\
    \  int n, q, s;\r\n  std::cin >> n >> q >> s; --s;\r\n  NoshiGraph<long long>\
    \ graph(n);\r\n  while (q--) {\r\n    int t, v;\r\n    std::cin >> t >> v;\r\n\
    \    --v;\r\n    if (t == 1) {\r\n      int u, w;\r\n      std::cin >> u >> w;\r\
    \n      --u;\r\n      graph.add_edge(v, u, w);\r\n    } else {\r\n      int l,\
    \ r, w;\r\n      std::cin >> l >> r >> w;\r\n      --l; --r;\r\n      if (t ==\
    \ 2) {\r\n        graph.add_edge(v, v + 1, l, r + 1, w);\r\n      } else if (t\
    \ == 3) {\r\n        graph.add_edge(l, r + 1, v, v + 1, w);\r\n      }\r\n   \
    \ }\r\n  }\r\n  Dijkstra<long long> dij(graph.graph);\r\n  std::vector<long long>\
    \ ans = dij.build(s);\r\n  for (int i = 0; i < n; ++i) std::cout << (ans[i] ==\
    \ dij.inf ? -1 : ans[i]) << \" \\n\"[i + 1 == n];\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/noshi_graph.hpp
  - graph/edge.hpp
  - graph/shortest_path/dijkstra.hpp
  isVerificationFile: true
  path: test/graph/noshi_graph.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/noshi_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/noshi_graph.test.cpp
- /verify/test/graph/noshi_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
---
