---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/2-edge-connected_components_by_lowlink.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 lowlink \u7248"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: lowlink
  - icon: ':question:'
    path: graph/tree/lowest_common_ancestor_by_doubling.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\u30EA\u30F3\u30B0\u7248"
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
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
      \u5206\u89E3 lowlink \u7248"
    links:
    - https://atcoder.jp/contests/arc039/tasks/arc039_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/2-edge-connected_components_by_lowlink.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u5206\u89E3 lowlink \u7248\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc039/tasks/arc039_d\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../graph/2-edge-connected_components_by_lowlink.hpp\"\
    \r\n#include \"../../graph/edge.hpp\"\r\n#include \"../../graph/tree/lowest_common_ancestor_by_doubling.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<Edge<int>>>\
    \ graph(n);\r\n  while (m--) {\r\n    int x, y;\r\n    std::cin >> x >> y;\r\n\
    \    --x; --y;\r\n    graph[x].emplace_back(x, y, 1);\r\n    graph[y].emplace_back(y,\
    \ x, 1);\r\n  }\r\n  const TwoEdgeConnectedComponents<int> two_edge_connected_components(graph);\r\
    \n  LowestCommonAncestorByDoubling<int> lca(two_edge_connected_components.g);\r\
    \n  lca.build();\r\n  int q;\r\n  std::cin >> q;\r\n  while (q--) {\r\n    int\
    \ a, b, c;\r\n    std::cin >> a >> b >> c;\r\n    --a; --b; --c;\r\n    a = two_edge_connected_components.id[a];\r\
    \n    b = two_edge_connected_components.id[b];\r\n    c = two_edge_connected_components.id[c];\r\
    \n    if (lca.distance(a, b) + lca.distance(b, c) == lca.distance(a, c)) {\r\n\
    \      std::cout << \"OK\\n\";\r\n    } else {\r\n      std::cout << \"NG\\n\"\
    ;\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/2-edge-connected_components_by_lowlink.hpp
  - graph/edge.hpp
  - graph/lowlink.hpp
  - graph/tree/lowest_common_ancestor_by_doubling.hpp
  isVerificationFile: true
  path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 23:25:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/2-edge-connected_components_by_lowlink.test.cpp
layout: document
redirect_from:
- /verify/test/graph/2-edge-connected_components_by_lowlink.test.cpp
- /verify/test/graph/2-edge-connected_components_by_lowlink.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
  \ lowlink \u7248"
---
