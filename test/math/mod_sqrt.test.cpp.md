---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59"
  - icon: ':heavy_check_mark:'
    path: util/xorshift.hpp
    title: xorshift
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/mod_sqrt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u5E73\u65B9\u5270\u4F59\n */\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include <iostream>\n\n#include\
    \ \"../../math/mod_sqrt.hpp\"\n\nint main() {\n  int t;\n  std::cin >> t;\n  while\
    \ (t--) {\n    int y, p;\n    std::cin >> y >> p;\n    std::cout << mod_sqrt(y,\
    \ p) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/mod_sqrt.hpp
  - util/xorshift.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/mod_sqrt.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/mod_sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/math/mod_sqrt.test.cpp
- /verify/test/math/mod_sqrt.test.cpp.html
title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
---
