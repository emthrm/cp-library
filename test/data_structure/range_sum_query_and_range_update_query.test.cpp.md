---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728 (range sum query and range update query)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/lazy_segment_tree.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728 (range sum query and range update query)\n */\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n\n#include <iostream>\n\n#include \"emthrm/data_structure/lazy_segment_tree.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::LazySegmentTree<emthrm::monoid::RangeSumAndUpdateQuery<long\
    \ long>>\n      rsq(emthrm::monoid::RangeSumAndUpdateQuery<long long>::init(n));\n\
    \  while (q--) {\n    int query, s, t;\n    std::cin >> query >> s >> t;\n   \
    \ if (query == 0) {\n      int x;\n      std::cin >> x;\n      rsq.apply(s, t\
    \ + 1, x);\n    } else if (query == 1) {\n      std::cout << rsq.get(s, t + 1).sum\
    \ << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/data_structure/range_sum_query_and_range_update_query.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/range_sum_query_and_range_update_query.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/range_sum_query_and_range_update_query.test.cpp
- /verify/test/data_structure/range_sum_query_and_range_update_query.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728 (range sum query and range update query)"
---
