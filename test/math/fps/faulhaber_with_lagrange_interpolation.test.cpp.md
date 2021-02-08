---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/fps/faulhaber_with_lagrange_interpolation.hpp
    title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\
      \u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u7248"
  - icon: ':question:'
    path: math/lagrange_interpolation2.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u72482"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/665
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\
      \u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\u30E9\u30F3\
      \u30B8\u30E5\u88DC\u9593\u7248"
    links:
    - https://yukicoder.me/problems/no/665
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/fps/faulhaber_with_lagrange_interpolation.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\
    \u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\u30E9\u30F3\
    \u30B8\u30E5\u88DC\u9593\u7248\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/665\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../math/fps/faulhaber_with_lagrange_interpolation.hpp\"\
    \r\n\r\nint main() {\r\n  ModInt::set_mod(1000000007);\r\n  long long n;\r\n \
    \ int k;\r\n  std::cin >> n >> k;\r\n  std::cout << faulhaber(n + 1, k) << '\\\
    n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/fps/faulhaber_with_lagrange_interpolation.hpp
  - math/modint.hpp
  - math/lagrange_interpolation2.hpp
  isVerificationFile: true
  path: test/math/fps/faulhaber_with_lagrange_interpolation.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/fps/faulhaber_with_lagrange_interpolation.test.cpp
layout: document
redirect_from:
- /verify/test/math/fps/faulhaber_with_lagrange_interpolation.test.cpp
- /verify/test/math/fps/faulhaber_with_lagrange_interpolation.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
  \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\
  \u9593\u7248"
---
