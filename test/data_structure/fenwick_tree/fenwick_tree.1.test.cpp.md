---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/fenwick_tree/fenwick_tree.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (sum(left,\
    \ right))\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <iostream>\n\n#include \"emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::FenwickTree<long\
    \ long> bit(n);\n  while (q--) {\n    int com, x, y;\n    std::cin >> com >> x\
    \ >> y;\n    --x;\n    if (com == 0) {\n      bit.add(x, y);\n    } else if (com\
    \ == 1) {\n      --y;\n      std::cout << bit.sum(x, y + 1) << '\\n';\n    }\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
- /verify/test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (sum(left, right))"
---
