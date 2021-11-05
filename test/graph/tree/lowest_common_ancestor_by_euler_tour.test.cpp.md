---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/tree/euler_tour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC (Euler tour)"
  - icon: ':heavy_check_mark:'
    path: graph/tree/lowest_common_ancestor_by_euler_tour.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
      \u30FC\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148\
      \ \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \ \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u7248\r\n */\r\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include \"../../../graph/edge.hpp\"\r\n\
    #include \"../../../graph/tree/lowest_common_ancestor_by_euler_tour.hpp\"\r\n\
    #include \"../../../data_structure/lazy_segment_tree.hpp\"\r\n\r\nint main() {\r\
    \n  int n, q;\r\n  std::cin >> n >> q;\r\n  std::vector<std::vector<Edge<long\
    \ long>>> graph(n);\r\n  for (int i = 0; i < n - 1; ++i) {\r\n    int a, b;\r\n\
    \    std::cin >> a >> b;\r\n    graph[a].emplace_back(a, b, 0);\r\n    graph[b].emplace_back(b,\
    \ a, 0);\r\n  }\r\n  LowestCommonAncestor<long long> lca(graph, 0);\r\n  struct\
    \ Node {\r\n    using Monoid = struct {\r\n      int cnt;\r\n      long long sum;\r\
    \n    };\r\n    using OperatorMonoid = int;\r\n    static constexpr Monoid m_id()\
    \ { return Monoid{0, 0}; }\r\n    static constexpr OperatorMonoid o_id() { return\
    \ 0; }\r\n    static Monoid m_merge(const Monoid &a, const Monoid &b) { return\
    \ Monoid{a.cnt + b.cnt, a.sum + b.sum}; }\r\n    static OperatorMonoid o_merge(const\
    \ OperatorMonoid &a, const OperatorMonoid &b) { return a + b; }\r\n    static\
    \ Monoid apply(Monoid a, const OperatorMonoid &b) {\r\n      a.sum += b * a.cnt;\r\
    \n      return a;\r\n    }\r\n  };\r\n  std::vector<Node::Monoid> init(lca.cost.size(),\
    \ Node::Monoid{0, 0});\r\n  for (int i = 1; i < n; ++i) {\r\n    init[lca.down[i]].cnt\
    \ = 1;\r\n    init[lca.up[i]].cnt = -1;\r\n  }\r\n  LazySegmentTree<Node> seg(init);\r\
    \n  auto fn = [&seg](int a, int b) -> long long { return seg.get(a, b).sum; };\r\
    \n  while (q--) {\r\n    int query;\r\n    std::cin >> query;\r\n    if (query\
    \ == 0) {\r\n      int u, v;\r\n      std::cin >> u >> v;\r\n      int l = lca.query(u,\
    \ v);\r\n      std::cout << lca.e_query<long long>(l, u, fn) + lca.e_query<long\
    \ long>(l, v, fn) << '\\n';\r\n    } else if (query == 1) {\r\n      int v, x;\r\
    \n      std::cin >> v >> x;\r\n      lca.subtree_e_update(v, [&seg, x](int a,\
    \ int b) { seg.apply(a, b, x); });\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/tree/lowest_common_ancestor_by_euler_tour.hpp
  - graph/tree/euler_tour.hpp
  - data_structure/sparse_table.hpp
  - data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
  requiredBy: []
  timestamp: '2021-08-17 16:32:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
- /verify/test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\
  \u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
---
