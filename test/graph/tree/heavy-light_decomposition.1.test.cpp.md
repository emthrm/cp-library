---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
    title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
    document_title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\"\n\n#include\
    \ <functional>\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/heavy-light_decomposition.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    graph[a].emplace_back(a, b, 0);\n    graph[b].emplace_back(b,\
    \ a, 0);\n  }\n  emthrm::HeavyLightDecomposition<long long>\n      heavy_light_decomposition(graph,\
    \ 0);\n  emthrm::FenwickTreeSupportingRangeAddQuery<long long> bit(n - 1);\n \
    \ while (q--) {\n    int type;\n    std::cin >> type;\n    if (type == 0) {\n\
    \      int u, v;\n      std::cin >> u >> v;\n      std::cout << heavy_light_decomposition.query_e(\n\
    \                       u, v,\n                       [&bit](const int l, const\
    \ int r) -> long long {\n                         return bit.sum(l, r);\n    \
    \                   },\n                       std::plus<long long>(), 0LL)\n\
    \                << '\\n';\n    } else if (type == 1) {\n      int v, x;\n   \
    \   std::cin >> v >> x;\n      heavy_light_decomposition.update_subtree_e(\n \
    \         v,\n          [&bit, x](const int l, const int r) -> void {\n      \
    \      return bit.add(l, r, x);\n          });\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/heavy-light_decomposition.hpp
  isVerificationFile: true
  path: test/graph/tree/heavy-light_decomposition.1.test.cpp
  requiredBy: []
  timestamp: '2023-02-03 18:44:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/heavy-light_decomposition.1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/heavy-light_decomposition.1.test.cpp
- /verify/test/graph/tree/heavy-light_decomposition.1.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
---
