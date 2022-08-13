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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp: line\
    \ 6: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../../data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp\"\
    \n#include \"../../../graph/edge.hpp\"\n#include \"../../../graph/tree/heavy-light_decomposition.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::vector<Edge<long\
    \ long>>> graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    graph[a].emplace_back(a, b, 0);\n    graph[b].emplace_back(b,\
    \ a, 0);\n  }\n  HeavyLightDecomposition<long long> heavy_light_decomposition(graph,\
    \ 0);\n  FenwickTreeSupportingRangeAddQuery<long long> bit(n - 1);\n  const auto\
    \ f = [&bit](const int l, const int r) -> long long {\n    return bit.sum(l, r);\n\
    \  };\n  const auto g = [](const long long a, const long long b) -> long long\
    \ {\n    return a + b;\n  };\n  while (q--) {\n    int type;\n    std::cin >>\
    \ type;\n    if (type == 0) {\n      int u, v;\n      std::cin >> u >> v;\n  \
    \    std::cout << heavy_light_decomposition.query_e(u, v, f, g, 0LL) << '\\n';\n\
    \    } else if (type == 1) {\n      int v, x;\n      std::cin >> v >> x;\n   \
    \   heavy_light_decomposition.update_subtree_e(\n          v,\n          [&bit,\
    \ x](const int l, const int r) -> void {\n            return bit.add(l, r, x);\n\
    \          });\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
  - graph/edge.hpp
  - graph/tree/heavy-light_decomposition.hpp
  isVerificationFile: true
  path: test/graph/tree/heavy-light_decomposition.1.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/heavy-light_decomposition.1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/heavy-light_decomposition.1.test.cpp
- /verify/test/graph/tree/heavy-light_decomposition.1.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
---
