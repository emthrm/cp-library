---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (sum(left,\
      \ right))"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/fenwick_tree.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree\
    \ (sum(left, right))\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \r\n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  FenwickTree<long\
    \ long> bit(n);\r\n  while (q--) {\r\n    int com, x, y;\r\n    std::cin >> com\
    \ >> x >> y;\r\n    --x;\r\n    if (com == 0) {\r\n      bit.add(x, y);\r\n  \
    \  } else if (com == 1) {\r\n      --y;\r\n      std::cout << bit.sum(x, y + 1)\
    \ << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/fenwick_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
  requiredBy: []
  timestamp: '2021-04-24 04:29:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
- /verify/test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (sum(left, right))"
---
