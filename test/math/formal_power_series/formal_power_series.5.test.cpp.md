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
    PROBLEM: https://atcoder.jp/contests/abc135/tasks/abc135_d
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
      \u7684\u51AA\u7D1A\u6570 (mod_pow(exponend, md))"
    links:
    - https://atcoder.jp/contests/abc135/tasks/abc135_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/mod_convolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570 (mod_pow(exponend, md))\r\n */\r\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc135/tasks/abc135_d\"\r\n\r\n#include <algorithm>\r\
    \n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n\r\n#include\
    \ \"../../../math/convolution/mod_convolution.hpp\"\r\n#include \"../../../math/formal_power_series/formal_power_series.hpp\"\
    \r\n#include \"../../../math/modint.hpp\"\r\n\r\nint main() {\r\n  using ModInt\
    \ = MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\n  FormalPowerSeries<ModInt>::set_mult(\r\
    \n      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)\r\n   \
    \       -> std::vector<ModInt> {\r\n        return mod_convolution(a, b);\r\n\
    \      });\r\n  constexpr int D = 6, M = 13;\r\n  std::string s;\r\n  std::cin\
    \ >> s;\r\n  std::reverse(s.begin(), s.end());\r\n  int q[D]{};\r\n  for (int\
    \ i = 0; i < s.length(); ++i) {\r\n    if (s[i] == '?') ++q[i % D];\r\n  }\r\n\
    \  std::vector<FormalPowerSeries<ModInt>> f(D, FormalPowerSeries<ModInt>(M));\r\
    \n  FormalPowerSeries<ModInt> md(M);\r\n  md[0] = -1;\r\n  md[M] = 1;\r\n  for\
    \ (int i = 0; i < D; ++i) {\r\n    int base = 1;\r\n    for (int j = 0; j < i;\
    \ ++j) {\r\n      base *= 10;\r\n    }\r\n    for (int j = 0; j < 10; ++j) {\r\
    \n      ++f[i][base * j % M];\r\n    }\r\n    f[i] = f[i].mod_pow(q[i], md);\r\
    \n  }\r\n  for (int i = 1; i < D; ++i) {\r\n    f.front() *= f[i];\r\n  }\r\n\
    \  f.front() %= md;\r\n  int idx = D - 1, w = 1;\r\n  for (int i = 0; i < s.length();\
    \ ++i) {\r\n    if (s[i] != '?') {\r\n      idx = (idx - w * (s[i] - '0')) % M;\r\
    \n      if (idx < 0) idx += M;\r\n    }\r\n    w = w * 10 % M;\r\n  }\r\n  std::cout\
    \ << f.front()[idx] << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/convolution/mod_convolution.hpp
  - math/modint.hpp
  - math/convolution/fast_fourier_transform.hpp
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/formal_power_series.5.test.cpp
  requiredBy: []
  timestamp: '2022-02-27 17:53:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/formal_power_series.5.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/formal_power_series.5.test.cpp
- /verify/test/math/formal_power_series/formal_power_series.5.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
  \u7D1A\u6570 (mod_pow(exponend, md))"
---
