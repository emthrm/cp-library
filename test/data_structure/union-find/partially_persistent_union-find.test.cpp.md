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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/partially_persistent_union-find.hpp: line 6: #pragma\
    \ once found in a non-first line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u90E8\u5206\u6C38\
    \u7D9A union-find\r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/agc002/tasks/agc002_d\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../data_structure/union-find/partially_persistent_union-find.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  PartiallyPersistentUnionFind\
    \ uf(n);\r\n  for (int i = 1; i <= m; ++i) {\r\n    int a, b;\r\n    std::cin\
    \ >> a >> b;\r\n    --a; --b;\r\n    uf.unite(i, a, b);\r\n  }\r\n  int q;\r\n\
    \  std::cin >> q;\r\n  while (q--) {\r\n    int x, y, z;\r\n    std::cin >> x\
    \ >> y >> z;\r\n    --x; --y;\r\n    int lb = 0, ub = m;\r\n    while (ub - lb\
    \ > 1) {\r\n      const int mid = (lb + ub) >> 1;\r\n      (uf.size(mid, x) +\
    \ (uf.is_same(mid, x, y) ? 0 : uf.size(mid, y)) >= z ? ub : lb) = mid;\r\n   \
    \ }\r\n    std::cout << lb + 1 << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/union-find/partially_persistent_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/partially_persistent_union-find.test.cpp
  requiredBy: []
  timestamp: '2021-09-24 01:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union-find/partially_persistent_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/partially_persistent_union-find.test.cpp
- /verify/test/data_structure/union-find/partially_persistent_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u90E8\u5206\u6C38\u7D9A union-find"
---
