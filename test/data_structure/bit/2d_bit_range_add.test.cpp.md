---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/bit/2d_bit_range_add.hpp
    title: "2\u6B21\u5143 BIT \u9818\u57DF\u52A0\u7B97\u7248"
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
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/BIT/2\u6B21\u5143 BIT \u9818\u57DF\
      \u52A0\u7B97\u7248"
    links:
    - https://codeforces.com/problemset/problem/1200/D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/bit/2d_bit_range_add.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/BIT/2\u6B21\u5143 BIT \u9818\
    \u57DF\u52A0\u7B97\u7248\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://codeforces.com/problemset/problem/1200/D\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n#include\
    \ \"../../../data_structure/bit/2d_bit_range_add.hpp\"\r\n\r\nint main() {\r\n\
    \  int n, k;\r\n  std::cin >> n >> k;\r\n  std::vector<std::vector<char>> cf(n,\
    \ std::vector<char>(n));\r\n  for (int i = 0; i < n; ++i) for (int j = 0; j <\
    \ n; ++j) std::cin >> cf[i][j];\r\n  BIT2DRangeAdd<int> bit(n, n);\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    int mn = n, mx = -1;\r\n    for (int j = 0; j <\
    \ n; ++j) {\r\n      if (cf[i][j] == 'B') {\r\n        if (j < mn) mn = j;\r\n\
    \        if (j > mx) mx = j;\r\n      }\r\n    }\r\n    if (mx == -1) {\r\n  \
    \    bit.add(0, 0, n - 1, n - 1, 1);\r\n      continue;\r\n    }\r\n    if (mx\
    \ - mn + 1 > k) continue;\r\n    bit.add(std::max(i - k + 1, 0), std::max(mx -\
    \ k + 1, 0), i, mn, 1);\r\n  }\r\n  for (int j = 0; j < n; ++j) {\r\n    int mn\
    \ = n, mx = -1;\r\n    for (int i = 0; i < n; ++i) {\r\n      if (cf[i][j] ==\
    \ 'B') {\r\n        if (i < mn) mn = i;\r\n        if (i > mx) mx = i;\r\n   \
    \   }\r\n    }\r\n    if (mx == -1) {\r\n      bit.add(0, 0, n - 1, n - 1, 1);\r\
    \n      continue;\r\n    }\r\n    if (mx - mn + 1 > k) continue;\r\n    bit.add(std::max(mx\
    \ - k + 1, 0), std::max(j - k + 1, 0), mn, j, 1);\r\n  }\r\n  int ans = 0;\r\n\
    \  for (int i = 0; i + k <= n; ++i) for (int j = 0; j + k <= n; ++j) {\r\n   \
    \ int sum = bit.sum(i, j, i, j);\r\n    if (sum > ans) ans = sum;\r\n  }\r\n \
    \ std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/bit/2d_bit_range_add.hpp
  isVerificationFile: true
  path: test/data_structure/bit/2d_bit_range_add.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 04:45:32+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/bit/2d_bit_range_add.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/bit/2d_bit_range_add.test.cpp
- /verify/test/data_structure/bit/2d_bit_range_add.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/BIT/2\u6B21\u5143 BIT \u9818\u57DF\u52A0\u7B97\
  \u7248"
---
