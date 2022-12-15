---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 lowlink \u7248"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/lowlink.hpp
    title: lowlink
  - icon: ':question:'
    path: include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\u30EA\u30F3\u30B0\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
      \u5206\u89E3 lowlink \u7248"
    links:
    - https://atcoder.jp/contests/arc039/tasks/arc039_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/2-edge-connected_components_by_lowlink.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u5206\u89E3 lowlink \u7248\n */\n#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/arc039/tasks/arc039_d\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/2-edge-connected_components_by_lowlink.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<int>>>\
    \ graph(n);\n  while (m--) {\n    int x, y;\n    std::cin >> x >> y;\n    --x;\
    \ --y;\n    graph[x].emplace_back(x, y, 1);\n    graph[y].emplace_back(y, x, 1);\n\
    \  }\n  const emthrm::TwoEdgeConnectedComponents<int>\n      two_edge_connected_components(graph);\n\
    \  emthrm::LowestCommonAncestorByDoubling<int>\n      lca(two_edge_connected_components.g);\n\
    \  lca.build();\n  int q;\n  std::cin >> q;\n  while (q--) {\n    int a, b, c;\n\
    \    std::cin >> a >> b >> c;\n    --a; --b; --c;\n    a = two_edge_connected_components.id[a];\n\
    \    b = two_edge_connected_components.id[b];\n    c = two_edge_connected_components.id[c];\n\
    \    if (lca.distance(a, b) + lca.distance(b, c) == lca.distance(a, c)) {\n  \
    \    std::cout << \"OK\\n\";\n    } else {\n      std::cout << \"NG\\n\";\n  \
    \  }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/lowlink.hpp
  - include/emthrm/graph/tree/lowest_common_ancestor_by_doubling.hpp
  isVerificationFile: true
  path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
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
