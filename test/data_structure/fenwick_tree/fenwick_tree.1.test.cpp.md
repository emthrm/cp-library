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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/fenwick_tree.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (sum(left,\
    \ right))\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <iostream>\n\n#include \"../../../data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  FenwickTree<long long>\
    \ bit(n);\n  while (q--) {\n    int com, x, y;\n    std::cin >> com >> x >> y;\n\
    \    --x;\n    if (com == 0) {\n      bit.add(x, y);\n    } else if (com == 1)\
    \ {\n      --y;\n      std::cout << bit.sum(x, y + 1) << '\\n';\n    }\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - data_structure/fenwick_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
- /verify/test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (sum(left, right))"
---
