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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/2-edge-connected_components_by_lowlink.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u5206\u89E3 lowlink \u7248\n */\n#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/arc039/tasks/arc039_d\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../graph/2-edge-connected_components_by_lowlink.hpp\"\
    \n#include \"../../graph/edge.hpp\"\n#include \"../../graph/tree/lowest_common_ancestor_by_doubling.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<Edge<int>>>\
    \ graph(n);\n  while (m--) {\n    int x, y;\n    std::cin >> x >> y;\n    --x;\
    \ --y;\n    graph[x].emplace_back(x, y, 1);\n    graph[y].emplace_back(y, x, 1);\n\
    \  }\n  const TwoEdgeConnectedComponents<int> two_edge_connected_components(graph);\n\
    \  LowestCommonAncestorByDoubling<int> lca(two_edge_connected_components.g);\n\
    \  lca.build();\n  int q;\n  std::cin >> q;\n  while (q--) {\n    int a, b, c;\n\
    \    std::cin >> a >> b >> c;\n    --a; --b; --c;\n    a = two_edge_connected_components.id[a];\n\
    \    b = two_edge_connected_components.id[b];\n    c = two_edge_connected_components.id[c];\n\
    \    if (lca.distance(a, b) + lca.distance(b, c) == lca.distance(a, c)) {\n  \
    \    std::cout << \"OK\\n\";\n    } else {\n      std::cout << \"NG\\n\";\n  \
    \  }\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/2-edge-connected_components_by_lowlink.hpp
  - graph/edge.hpp
  - graph/lowlink.hpp
  - graph/tree/lowest_common_ancestor_by_doubling.hpp
  isVerificationFile: true
  path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
