---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/union-find/union-find.hpp
    title: union-find
  - icon: ':x:'
    path: include/emthrm/graph/connencted_component_of_complement_graph.hpp
    title: "\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\
      \u6210\u5206\u5206\u89E3"
    links:
    - https://codeforces.com/problemset/problem/1242/B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/union-find/union-find.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\
    \u6210\u5206\u5206\u89E3\n */\n#define IGNORE\n#define PROBLEM \"https://codeforces.com/problemset/problem/1242/B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/data_structure/union-find/union-find.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/connencted_component_of_complement_graph.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n    --a;\
    \ --b;\n    graph[a].emplace_back(a, b);\n    graph[b].emplace_back(b, a);\n \
    \ }\n  emthrm::UnionFind union_find =\n      emthrm::connencted_component_of_complement_graph(graph);\n\
    \  int ans = 0;\n  for (int i = 0; i < n; ++i) {\n    ans += union_find.root(i)\
    \ == i;\n  }\n  std::cout << ans - 1 << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/union-find/union-find.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/connencted_component_of_complement_graph.hpp
  isVerificationFile: true
  path: test/graph/connencted_component_of_complement_graph.test.cpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/connencted_component_of_complement_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/connencted_component_of_complement_graph.test.cpp
- /verify/test/graph/connencted_component_of_complement_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\
  \u89E3"
---
