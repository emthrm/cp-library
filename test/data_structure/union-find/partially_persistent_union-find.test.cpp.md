---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union-find/partially_persistent_union-find.hpp
    title: "\u90E8\u5206\u6C38\u7D9A union-find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/agc002/tasks/agc002_d
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u90E8\u5206\u6C38\u7D9A\
      \ union-find"
    links:
    - https://atcoder.jp/contests/agc002/tasks/agc002_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/partially_persistent_union-find.hpp: line 6: #pragma\
    \ once found in a non-first line\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u90E8\u5206\u6C38\
    \u7D9A union-find\n */\n#define PROBLEM \"https://atcoder.jp/contests/agc002/tasks/agc002_d\"\
    \n\n#include <iostream>\n\n#include \"../../../data_structure/union-find/partially_persistent_union-find.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  PartiallyPersistentUnionFind\
    \ union_find(n);\n  for (int i = 1; i <= m; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    --a; --b;\n    union_find.unite(i, a, b);\n  }\n  int q;\n \
    \ std::cin >> q;\n  while (q--) {\n    int x, y, z;\n    std::cin >> x >> y >>\
    \ z;\n    --x; --y;\n    int lb = 0, ub = m;\n    while (ub - lb > 1) {\n    \
    \  const int mid = (lb + ub) >> 1;\n      (union_find.size(mid, x) + (union_find.is_same(mid,\
    \ x, y) ?\n       0 : union_find.size(mid, y)) >= z ? ub : lb) = mid;\n    }\n\
    \    std::cout << lb + 1 << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/union-find/partially_persistent_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/partially_persistent_union-find.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union-find/partially_persistent_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/partially_persistent_union-find.test.cpp
- /verify/test/data_structure/union-find/partially_persistent_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u90E8\u5206\u6C38\u7D9A union-find"
---
