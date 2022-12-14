---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/2-edge-connected_components_by_imos.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 \u3044\u3082\u3059\
      \u6CD5\u7248"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/enumerate_bridges.hpp
    title: "\u6A4B\u306E\u691C\u51FA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
      \u5206\u89E3 \u3044\u3082\u3059\u6CD5\u7248"
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
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
    \ graph/2-edge-connected_components_by_imos.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u5206\u89E3 \u3044\u3082\u3059\u6CD5\u7248\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../graph/2-edge-connected_components_by_imos.hpp\"\
    \n#include \"../../graph/edge.hpp\"\n\nint main() {\n  int n, m;\n  std::cin >>\
    \ n >> m;\n  std::vector<std::vector<Edge<bool>>> graph(n);\n  while (m--) {\n\
    \    int a, b;\n    std::cin >> a >> b;\n    graph[a].emplace_back(a, b);\n  \
    \  graph[b].emplace_back(b, a);\n  }\n  const std::vector<std::vector<int>> ans\
    \ =\n      TwoEdgeConnectedComponentsByImos<bool>(graph, true).vertices;\n  const\
    \ int k = ans.size();\n  std::cout << k << '\\n';\n  for (int i = 0; i < k; ++i)\
    \ {\n    const int l = ans[i].size();\n    std::cout << l << ' ';\n    for (int\
    \ j = 0; j < l; ++j) {\n      std::cout << ans[i][j] << \" \\n\"[j + 1 == l];\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/2-edge-connected_components_by_imos.hpp
  - graph/edge.hpp
  - graph/enumerate_bridges.hpp
  isVerificationFile: true
  path: test/graph/2-edge-connected_components_by_imos.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/2-edge-connected_components_by_imos.test.cpp
layout: document
redirect_from:
- /verify/test/graph/2-edge-connected_components_by_imos.test.cpp
- /verify/test/graph/2-edge-connected_components_by_imos.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
  \ \u3044\u3082\u3059\u6CD5\u7248"
---
