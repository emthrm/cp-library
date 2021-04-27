---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728 (range minimum query and range add query)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/lazy_segment_tree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728 (range minimum query and range add query)\r\n */\r\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \r\n\r\n#include <iostream>\r\n#include <limits>\r\n#include <vector>\r\n#include\
    \ \"../../data_structure/lazy_segment_tree.hpp\"\r\n\r\nint main() {\r\n  int\
    \ n, q;\r\n  std::cin >> n >> q;\r\n  LazySegmentTree<monoid::RangeMinimumAndAddQuery<long\
    \ long, std::numeric_limits<long long>::max()>> rmq(std::vector<long long>(n,\
    \ 0));\r\n  while (q--) {\r\n    int query, s, t;\r\n    std::cin >> query >>\
    \ s >> t;\r\n    if (query == 0) {\r\n      int x;\r\n      std::cin >> x;\r\n\
    \      rmq.apply(s, t + 1, x);\r\n    } else if (query == 1) {\r\n      std::cout\
    \ << rmq.get(s, t + 1) << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/data_structure/range_minimum_query_and_range_add_query.test.cpp
  requiredBy: []
  timestamp: '2021-04-27 20:26:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/range_minimum_query_and_range_add_query.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/range_minimum_query_and_range_add_query.test.cpp
- /verify/test/data_structure/range_minimum_query_and_range_add_query.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728 (range minimum query and range add query)"
---
