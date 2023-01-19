---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    document_title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/mod_sqrt.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5E73\u65B9\u5270\u4F59\n */\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include <iostream>\n\n#include\
    \ \"emthrm/math/mod_sqrt.hpp\"\n\nint main() {\n  int t;\n  std::cin >> t;\n \
    \ while (t--) {\n    int y, p;\n    std::cin >> y >> p;\n    std::cout << emthrm::mod_sqrt(y,\
    \ p) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/mod_sqrt.hpp
  - include/emthrm/math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/mod_sqrt.test.cpp
  requiredBy: []
  timestamp: '2023-01-19 21:24:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/mod_sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/math/mod_sqrt.test.cpp
- /verify/test/math/mod_sqrt.test.cpp.html
title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
---
