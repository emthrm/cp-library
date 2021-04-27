---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp:\
    \ line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
    \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick tree\r\n */\r\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1490\"\r\n\r\n#include <algorithm>\r\
    \n#include <iostream>\r\n#include <vector>\r\n#include \"../../../data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp\"\
    \r\n\r\nint main() {\r\n  int h, w, n, m;\r\n  std::cin >> h >> w >> n >> m;\r\
    \n  std::vector<int> t(n), u(n), l(n), r(n), a(n);\r\n  for (int i = 0; i < n;\
    \ ++i) {\r\n    std::cin >> t[i] >> u[i] >> l[i] >> r[i] >> a[i];\r\n    --t[i];\
    \ --u[i];\r\n    --l[i]; --r[i];\r\n  }\r\n  FenwickTree2DSupportingRangeAddQuery<long\
    \ long> bit(h, w);\r\n  while (m--) {\r\n    int x, y, b, c;\r\n    std::cin >>\
    \ x >> y >> b >> c;\r\n    --x; --y;\r\n    bit.add(std::max(x - b, 0), std::max(y\
    \ - b, 0), std::min(x + b, h - 1), std::min(y + b, w - 1), c);\r\n  }\r\n  int\
    \ ans = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n    ans += bit.sum(t[i], l[i],\
    \ u[i], r[i]) < a[i];\r\n  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n\
    }\r\n"
  dependsOn:
  - data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/2d_bit_range_add.test.cpp
  requiredBy: []
  timestamp: '2021-04-24 04:37:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/2d_bit_range_add.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/2d_bit_range_add.test.cpp
- /verify/test/data_structure/fenwick_tree/2d_bit_range_add.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\u7B97\u30AF\
  \u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick tree"
---
