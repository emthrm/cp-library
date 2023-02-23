---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp
    title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\
      \u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u7248"
  - icon: ':question:'
    path: include/emthrm/math/lagrange_interpolation2.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u72482"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\
    \u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\u30E9\u30F3\
    \u30B8\u30E5\u88DC\u9593\u7248\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/665\"\
    \n\n#include <iostream>\n\n#include \"emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nint main() {\n  constexpr int MOD = 1000000007;\n\
    \  long long n;\n  int k;\n  std::cin >> n >> k;\n  std::cout << emthrm::faulhaber_by_lagrange_interpolation<MOD>(n\
    \ + 1, k)\n            << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp
  - include/emthrm/math/lagrange_interpolation2.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/faulhaber_by_lagrange_interpolation.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:19:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/faulhaber_by_lagrange_interpolation.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/faulhaber_by_lagrange_interpolation.test.cpp
- /verify/test/math/formal_power_series/faulhaber_by_lagrange_interpolation.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
  \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\
  \u9593\u7248"
---
