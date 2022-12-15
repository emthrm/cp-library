---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp
    title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick\
      \ tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1490
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
      \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick tree"
    links:
    - https://yukicoder.me/problems/no/1490
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
    \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick tree\n */\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1490\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"emthrm/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp\"\
    \n\nint main() {\n  int h, w, n, m;\n  std::cin >> h >> w >> n >> m;\n  std::vector<int>\
    \ t(n), u(n), l(n), r(n), a(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin\
    \ >> t[i] >> u[i] >> l[i] >> r[i] >> a[i];\n    --t[i]; --u[i];\n    --l[i]; --r[i];\n\
    \  }\n  emthrm::FenwickTree2DSupportingRangeAddQuery<long long> bit(h, w);\n \
    \ while (m--) {\n    int x, y, b, c;\n    std::cin >> x >> y >> b >> c;\n    --x;\
    \ --y;\n    bit.add(std::max(x - b, 0), std::max(y - b, 0),\n            std::min(x\
    \ + b, h - 1), std::min(y + b, w - 1), c);\n  }\n  int ans = 0;\n  for (int i\
    \ = 0; i < n; ++i) {\n    ans += bit.sum(t[i], l[i], u[i], r[i]) < a[i];\n  }\n\
    \  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.test.cpp
- /verify/test/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\u7B97\u30AF\
  \u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick tree"
---
