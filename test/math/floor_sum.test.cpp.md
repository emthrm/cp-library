---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/floor_sum.hpp
    title: sum of floor of linear
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    document_title: "\u6570\u5B66/sum of floor of linear"
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/floor_sum.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/sum of floor of linear\n */\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#include <iostream>\n\
    \n#include \"emthrm/math/floor_sum.hpp\"\n\nint main() {\n  int t;\n  std::cin\
    \ >> t;\n  while (t--) {\n    int n, m, a, b;\n    std::cin >> n >> m >> a >>\
    \ b;\n    std::cout << emthrm::floor_sum(a, b, m, n) << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/math/floor_sum.hpp
  isVerificationFile: true
  path: test/math/floor_sum.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/floor_sum.test.cpp
layout: document
redirect_from:
- /verify/test/math/floor_sum.test.cpp
- /verify/test/math/floor_sum.test.cpp.html
title: "\u6570\u5B66/sum of floor of linear"
---
