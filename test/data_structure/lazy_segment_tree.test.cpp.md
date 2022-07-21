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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/lazy_segment_tree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"\
    ../../data_structure/lazy_segment_tree.hpp\"\n#include \"../../math/modint.hpp\"\
    \n\nint main() {\n  using ModInt = MInt<0>;\n  ModInt::set_mod(998244353);\n \
    \ int n, q;\n  std::cin >> n >> q;\n  struct M {\n    using Monoid = std::pair<ModInt,\
    \ int>;\n    using OperatorMonoid = std::pair<ModInt, ModInt>;\n    static Monoid\
    \ m_id() { return {0, 0}; }\n    static OperatorMonoid o_id() { return {1, 0};\
    \ }\n    static Monoid m_merge(const Monoid& a, const Monoid& b) {\n      return\
    \ {a.first + b.first, a.second + b.second};\n    }\n    static OperatorMonoid\
    \ o_merge(const OperatorMonoid& a,\n                                  const OperatorMonoid&\
    \ b) {\n      return {b.first * a.first, b.first * a.second + b.second};\n   \
    \ }\n    static Monoid apply(const Monoid& a, const OperatorMonoid& b) {\n   \
    \   return {a.first * b.first + b.second * a.second, a.second};\n    }\n  };\n\
    \  std::vector<M::Monoid> a(n, {0, 1});\n  for (int i = 0; i < n; ++i) {\n   \
    \ std::cin >> a[i].first;\n  }\n  LazySegmentTree<M> seg(a);\n  while (q--) {\n\
    \    int query, l, r;\n    std::cin >> query >> l >> r;\n    if (query == 0) {\n\
    \      int b, c;\n      std::cin >> b >> c;\n      seg.apply(l, r, {b, c});\n\
    \    } else if (query == 1) {\n      std::cout << seg.get(l, r).first << '\\n';\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/lazy_segment_tree.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/data_structure/lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
