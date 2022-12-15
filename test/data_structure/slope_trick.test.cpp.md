---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/slope_trick.hpp
    title: slope trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc123/tasks/arc123_d
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/slope trick"
    links:
    - https://atcoder.jp/contests/arc123/tasks/arc123_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/slope_trick.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/slope trick\n */\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc123/tasks/arc123_d\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\n#include \"emthrm/data_structure/slope_trick.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  emthrm::SlopeTrick<long\
    \ long> slope_trick(0);\n  slope_trick.abs_x_minus_a(0);\n  slope_trick.abs_x_minus_a(a.front());\n\
    \  for (int i = 1; i < n; ++i) {\n    slope_trick.translate(std::max(a[i] - a[i\
    \ - 1], 0));\n    slope_trick.cumulative_min();\n    slope_trick.abs_x_minus_a(0);\n\
    \    slope_trick.abs_x_minus_a(a[i]);\n  }\n  std::cout << slope_trick.min() <<\
    \ '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/slope_trick.hpp
  isVerificationFile: true
  path: test/data_structure/slope_trick.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/slope_trick.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/slope_trick.test.cpp
- /verify/test/data_structure/slope_trick.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/slope trick"
---
