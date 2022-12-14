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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\
    \u30C6\u30AF\n */\n#define IGNORE\n#define PROBLEM \"https://codeforces.com/problemset/problem/786/B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../graph/noshi_graph.hpp\"\
    \n#include \"../../graph/shortest_path/dijkstra.hpp\"\n\nint main() {\n  int n,\
    \ q, s;\n  std::cin >> n >> q >> s;\n  --s;\n  NoshiGraph<long long> graph(n);\n\
    \  while (q--) {\n    int t, v;\n    std::cin >> t >> v;\n    --v;\n    if (t\
    \ == 1) {\n      int u, w;\n      std::cin >> u >> w;\n      --u;\n      graph.add_edge(v,\
    \ u, w);\n    } else {\n      int l, r, w;\n      std::cin >> l >> r >> w;\n \
    \     --l; --r;\n      if (t == 2) {\n        graph.add_edge(v, v + 1, l, r +\
    \ 1, w);\n      } else if (t == 3) {\n        graph.add_edge(l, r + 1, v, v +\
    \ 1, w);\n      }\n    }\n  }\n  Dijkstra<long long> dijkstra(graph.graph);\n\
    \  const std::vector<long long> ans = dijkstra.build(s);\n  for (int i = 0; i\
    \ < n; ++i) {\n    std::cout << (ans[i] == dijkstra.inf ? -1 : ans[i]) << \" \\\
    n\"[i + 1 == n];\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/noshi_graph.hpp
  - graph/edge.hpp
  - graph/shortest_path/dijkstra.hpp
  isVerificationFile: true
  path: test/graph/noshi_graph.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/noshi_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/noshi_graph.test.cpp
- /verify/test/graph/noshi_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
---
