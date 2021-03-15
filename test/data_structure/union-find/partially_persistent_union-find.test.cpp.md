---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/union-find/partially_persistent_union-find.hpp
    title: "\u90E8\u5206\u6C38\u7D9A union-find \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/\u90E8\u5206\
      \u6C38\u7D9A union-find \u6728"
    links:
    - https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/partially_persistent_union-find.hpp: line 6: #pragma\
    \ once found in a non-first line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/\u90E8\u5206\
    \u6C38\u7D9A union-find \u6728\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"\
    https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../data_structure/union-find/partially_persistent_union-find.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  PartiallyPersistentUnionFind\
    \ uf(n);\r\n  for (int i = 0; i < m; ++i) {\r\n    int a, b;\r\n    std::cin >>\
    \ a >> b;\r\n    --a; --b;\r\n    uf.unite(i, a, b);\r\n  }\r\n  int q;\r\n  std::cin\
    \ >> q;\r\n  while (q--) {\r\n    int x, y;\r\n    std::cin >> x >> y;\r\n   \
    \ --x; --y;\r\n    if (!uf.same(m - 1, x, y)) {\r\n      std::cout << \"-1\\n\"\
    ;\r\n      continue;\r\n    }\r\n    int lb = -1, ub = m - 1;\r\n    while (ub\
    \ - lb > 1) {\r\n      int mid = (lb + ub) / 2;\r\n      (uf.same(mid, x, y) ?\
    \ ub : lb) = mid;\r\n    }\r\n    std::cout << ub + 1 << '\\n';\r\n  }\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - data_structure/union-find/partially_persistent_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/partially_persistent_union-find.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/union-find/partially_persistent_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/partially_persistent_union-find.test.cpp
- /verify/test/data_structure/union-find/partially_persistent_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/\u90E8\u5206\u6C38\u7D9A\
  \ union-find \u6728"
---
