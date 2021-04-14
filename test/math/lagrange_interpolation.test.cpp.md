---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/lagrange_interpolation.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u7248"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
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
    document_title: "\u6570\u5B66/\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\
      \ \u8A55\u4FA1\u7248"
    links:
    - https://atcoder.jp/contests/arc033/tasks/arc033_4
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/lagrange_interpolation.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\
    \ \u8A55\u4FA1\u7248\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc033/tasks/arc033_4\"\
    \r\n\r\n#include <iostream>\r\n#include <numeric>\r\n#include <vector>\r\n#include\
    \ \"../../math/modint.hpp\"\r\n#include \"../../math/lagrange_interpolation.hpp\"\
    \r\n\r\nint main() {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\
    \n  int n;\r\n  std::cin >> n;\r\n  std::vector<ModInt> x(n + 1);\r\n  std::iota(x.begin(),\
    \ x.end(), 0);\r\n  std::vector<ModInt> a(n + 1);\r\n  for (int i = 0; i <= n;\
    \ ++i) std::cin >> a[i];\r\n  ModInt t;\r\n  std::cin >> t;\r\n  std::cout <<\
    \ lagrange_interpolation(x, a, t) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/lagrange_interpolation.hpp
  isVerificationFile: true
  path: test/math/lagrange_interpolation.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/lagrange_interpolation.test.cpp
layout: document
redirect_from:
- /verify/test/math/lagrange_interpolation.test.cpp
- /verify/test/math/lagrange_interpolation.test.cpp.html
title: "\u6570\u5B66/\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\
  \u7248"
---
