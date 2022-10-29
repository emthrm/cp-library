---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728"
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/segment_tree.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"\
    ../../data_structure/segment_tree.hpp\"\n#include \"../../math/modint.hpp\"\n\n\
    int main() {\n  using ModInt = MInt<0>;\n  ModInt::set_mod(998244353);\n  int\
    \ n, q;\n  std::cin >> n >> q;\n  struct M {\n    using Monoid = std::pair<ModInt,\
    \ ModInt>;\n    static Monoid id() { return {1, 0}; }\n    static Monoid merge(const\
    \ Monoid& a, const Monoid& b) {\n      return {a.first * b.first, a.second * b.first\
    \ + b.second};\n    }\n  };\n  std::vector<M::Monoid> f(n);\n  for (int i = 0;\
    \ i < n; ++i) {\n    std::cin >> f[i].first >> f[i].second;\n  }\n  SegmentTree<M>\
    \ seg(f);\n  while (q--) {\n    int query;\n    std::cin >> query;\n    if (query\
    \ == 0) {\n      int p, c, d;\n      std::cin >> p >> c >> d;\n      seg.set(p,\
    \ {c, d});\n    } else if (query == 1) {\n      int l, r, x;\n      std::cin >>\
    \ l >> r >> x;\n      const M::Monoid ans = seg.get(l, r);\n      std::cout <<\
    \ ans.first * x + ans.second << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/segment_tree.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/data_structure/segment_tree.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/segment_tree.test.cpp
- /verify/test/data_structure/segment_tree.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
