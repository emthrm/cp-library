---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728"
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/lazy_segment_tree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n\r\n#include <iostream>\r\n#include <utility>\r\n#include <vector>\r\n#include\
    \ \"../../math/modint.hpp\"\r\n#include \"../../data_structure/lazy_segment_tree.hpp\"\
    \r\n\r\nint main() {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\
    \n  int n, q;\r\n  std::cin >> n >> q;\r\n  struct Node {\r\n    using Monoid\
    \ = std::pair<ModInt, int>;\r\n    using OperatorMonoid = std::pair<ModInt, ModInt>;\r\
    \n    static Monoid m_id() { return {0, 0}; }\r\n    static OperatorMonoid o_id()\
    \ { return {1, 0}; }\r\n    static Monoid m_merge(const Monoid &a, const Monoid\
    \ &b) { return {a.first + b.first, a.second + b.second}; }\r\n    static OperatorMonoid\
    \ o_merge(const OperatorMonoid &a, const OperatorMonoid &b) {\r\n      return\
    \ {b.first * a.first, b.first * a.second + b.second};\r\n    }\r\n    static Monoid\
    \ apply(const Monoid &a, const OperatorMonoid &b) {\r\n      return {a.first *\
    \ b.first + b.second * a.second, a.second};\r\n    }\r\n  };\r\n  std::vector<Node::Monoid>\
    \ a(n, {0, 1});\r\n  for (int i = 0; i < n; ++i) std::cin >> a[i].first;\r\n \
    \ LazySegmentTree<Node> seg(a);\r\n  while (q--) {\r\n    int query, l, r;\r\n\
    \    std::cin >> query >> l >> r;\r\n    if (query == 0) {\r\n      int b, c;\r\
    \n      std::cin >> b >> c;\r\n      seg.apply(l, r, {b, c});\r\n    } else if\
    \ (query == 1) {\r\n      std::cout << seg.get(l, r).first << '\\n';\r\n    }\r\
    \n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/data_structure/lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/lazy_segment_tree.test.cpp
- /verify/test/data_structure/lazy_segment_tree.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728"
---
