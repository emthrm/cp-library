---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
    title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/tree/heavy-light_decomposition.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp: line\
    \ 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\"\r\n\
    \r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../../data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp\"\
    \r\n#include \"../../../graph/edge.hpp\"\r\n#include \"../../../graph/tree/heavy-light_decomposition.hpp\"\
    \r\n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  std::vector<std::vector<Edge<long\
    \ long>>> graph(n);\r\n  for (int i = 0; i < n - 1; ++i) {\r\n    int a, b;\r\n\
    \    std::cin >> a >> b;\r\n    graph[a].emplace_back(a, b, 0);\r\n    graph[b].emplace_back(b,\
    \ a, 0);\r\n  }\r\n  HeavyLightDecomposition<long long> heavy_light_decomposition(graph,\
    \ 0);\r\n  FenwickTreeSupportingRangeAddQuery<long long> bit(n - 1);\r\n  const\
    \ auto f = [&bit](const int l, const int r) -> long long {\r\n    return bit.sum(l,\
    \ r);\r\n  };\r\n  const auto g = [](const long long a, const long long b) ->\
    \ long long {\r\n    return a + b;\r\n  };\r\n  while (q--) {\r\n    int type;\r\
    \n    std::cin >> type;\r\n    if (type == 0) {\r\n      int u, v;\r\n      std::cin\
    \ >> u >> v;\r\n      std::cout << heavy_light_decomposition.query_e(u, v, f,\
    \ g, 0LL) << '\\n';\r\n    } else if (type == 1) {\r\n      int v, x;\r\n    \
    \  std::cin >> v >> x;\r\n      heavy_light_decomposition.update_subtree_e(\r\n\
    \          v,\r\n          [&bit, x](const int l, const int r) -> void {\r\n \
    \           return bit.add(l, r, x);\r\n          });\r\n    }\r\n  }\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
  - graph/edge.hpp
  - graph/tree/heavy-light_decomposition.hpp
  isVerificationFile: true
  path: test/graph/tree/heavy-light_decomposition.1.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/heavy-light_decomposition.1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/heavy-light_decomposition.1.test.cpp
- /verify/test/graph/tree/heavy-light_decomposition.1.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
---
