---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  - icon: ':question:'
    path: math/convolution/mod_convolution.hpp
    title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/bernoulli_number.hpp
    title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570 (Bernoulli number)"
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/faulhaber_by_fps.hpp
    title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\
      \u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
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
      \u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570\u7248"
    links:
    - https://yukicoder.me/problems/no/665
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/mod_convolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\
    \u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\
    \u7D1A\u6570\u7248\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/665\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../math/modint.hpp\"\
    \r\n#include \"../../../math/formal_power_series/formal_power_series.hpp\"\r\n\
    #include \"../../../math/convolution/mod_convolution.hpp\"\r\n#include \"../../../math/formal_power_series/faulhaber_by_fps.hpp\"\
    \r\n\r\nint main() {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\
    \n  FormalPowerSeries<ModInt>::set_mul([&](const std::vector<ModInt> &a, const\
    \ std::vector<ModInt> &b) -> std::vector<ModInt> {\r\n    return mod_convolution(a,\
    \ b);\r\n  });\r\n  long long n;\r\n  int k;\r\n  std::cin >> n >> k;\r\n  std::cout\
    \ << faulhaber_by_fps<0>(n + 1, k) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  - math/convolution/mod_convolution.hpp
  - math/convolution/fast_fourier_transform.hpp
  - math/formal_power_series/faulhaber_by_fps.hpp
  - math/formal_power_series/bernoulli_number.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/faulhaber_by_fps.test.cpp
  requiredBy: []
  timestamp: '2021-08-15 23:02:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/faulhaber_by_fps.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/faulhaber_by_fps.test.cpp
- /verify/test/math/formal_power_series/faulhaber_by_fps.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
  \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
---
