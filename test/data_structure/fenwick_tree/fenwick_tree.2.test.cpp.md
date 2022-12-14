---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree
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
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (lower_bound(val))"
    links:
    - https://atcoder.jp/contests/arc033/tasks/arc033_3
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/fenwick_tree.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (lower_bound(val))\n\
    \ */\n#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/arc033/tasks/arc033_3\"\
    \n\n#include <iostream>\n\n#include \"../../../data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\nint main() {\n  constexpr int M = 200000;\n  FenwickTree<int> bit(M + 1);\n\
    \  int q;\n  std::cin >> q;\n  while (q--) {\n    int t, x;\n    std::cin >> t\
    \ >> x;\n    if (t == 1) {\n      bit.add(x, 1);\n    } else if (t == 2) {\n \
    \     const int ans = bit.lower_bound(x);\n      std::cout << ans << '\\n';\n\
    \      bit.add(ans, -1);\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/fenwick_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp
- /verify/test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (lower_bound(val))"
---
