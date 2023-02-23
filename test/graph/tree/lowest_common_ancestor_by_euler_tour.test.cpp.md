---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: include/emthrm/data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/euler_tour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC (Euler tour)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/lazy_segment_tree.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \ \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u7248\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/data_structure/lazy_segment_tree.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    graph[a].emplace_back(a, b, 0);\n    graph[b].emplace_back(b,\
    \ a, 0);\n  }\n  emthrm::LowestCommonAncestor<long long> lowest_common_ancestor(graph,\
    \ 0);\n  struct M {\n    using Monoid = struct { int num; long long sum; };\n\
    \    using OperatorMonoid = int;\n    static constexpr Monoid m_id() { return\
    \ Monoid{0, 0}; }\n    static constexpr OperatorMonoid o_id() { return 0; }\n\
    \    static Monoid m_merge(const Monoid& a, const Monoid& b) {\n      return Monoid{a.num\
    \ + b.num, a.sum + b.sum};\n    }\n    static OperatorMonoid o_merge(const OperatorMonoid&\
    \ a,\n                                  const OperatorMonoid& b) {\n      return\
    \ a + b;\n    }\n    static Monoid apply(Monoid a, const OperatorMonoid& b) {\n\
    \      a.sum += b * a.num;\n      return a;\n    }\n  };\n  std::vector<M::Monoid>\
    \ init((n - 1) * 2, M::Monoid{0, 0});\n  for (int i = 1; i < n; ++i) {\n    init[lowest_common_ancestor.down[i]].num\
    \ = 1;\n    init[lowest_common_ancestor.up[i]].num = -1;\n  }\n  emthrm::LazySegmentTree<M>\
    \ seg(init);\n  const auto fn = [&seg](const int a, const int b) -> long long\
    \ {\n    return seg.get(a, b).sum;\n  };\n  while (q--) {\n    int type;\n   \
    \ std::cin >> type;\n    if (type == 0) {\n      int u, v;\n      std::cin >>\
    \ u >> v;\n      const int lca = lowest_common_ancestor.query(u, v);\n      std::cout\
    \ << lowest_common_ancestor.query_e<long long>(lca, u, fn)\n                 \
    \  + lowest_common_ancestor.query_e<long long>(lca, v, fn)\n                <<\
    \ '\\n';\n    } else if (type == 1) {\n      int v, x;\n      std::cin >> v >>\
    \ x;\n      lowest_common_ancestor.update_subtree_e(\n          v, [&seg, x](const\
    \ int a, const int b) { seg.apply(a, b, x); });\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/lazy_segment_tree.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp
  - include/emthrm/data_structure/sparse_table.hpp
  - include/emthrm/graph/tree/euler_tour.hpp
  isVerificationFile: true
  path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
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
