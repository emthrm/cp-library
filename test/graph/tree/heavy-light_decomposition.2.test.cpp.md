---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/heavy-light_decomposition.hpp
    title: "HL \u5206\u89E3 (heavy-light decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    document_title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\
      \u901A\u7956\u5148)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\
    \u901A\u7956\u5148)\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/tree/heavy-light_decomposition.hpp\"\n\nint main() {\n\
    \  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<int>>> graph(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    int k;\n    std::cin >> k;\n    while (k--)\
    \ {\n      int c;\n      std::cin >> c;\n      graph[i].emplace_back(i, c, 1);\n\
    \      graph[c].emplace_back(c, i, 1);\n    }\n  }\n  const emthrm::HeavyLightDecomposition<int>\n\
    \      heavy_light_decomposition(graph, 0);\n  int q;\n  std::cin >> q;\n  while\
    \ (q--) {\n    int u, v;\n    std::cin >> u >> v;\n    std::cout << heavy_light_decomposition.lowest_common_ancestor(u,\
    \ v) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/heavy-light_decomposition.hpp
  isVerificationFile: true
  path: test/graph/tree/heavy-light_decomposition.2.test.cpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/heavy-light_decomposition.2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/heavy-light_decomposition.2.test.cpp
- /verify/test/graph/tree/heavy-light_decomposition.2.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\u901A\u7956\u5148\
  )"
---
