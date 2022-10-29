---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
    title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
      \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp: line\
    \ 6: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
    \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include <iostream>\n\n#include \"../../../data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  FenwickTreeSupportingRangeAddQuery<long\
    \ long> bit(n);\n  while (q--) {\n    int kind, s, t;\n    std::cin >> kind >>\
    \ s >> t;\n    --s; --t;\n    if (kind == 0) {\n      int x;\n      std::cin >>\
    \ x;\n      bit.add(s, t + 1, x);\n    } else if (kind == 1) {\n      std::cout\
    \ << bit.sum(s, t + 1) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.test.cpp
- /verify/test/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\u7B97\u30AF\
  \u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
---
