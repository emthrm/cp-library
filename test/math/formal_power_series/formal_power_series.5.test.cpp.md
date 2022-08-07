---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  - icon: ':question:'
    path: math/convolution/mod_convolution.hpp
    title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':question:'
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/mod_convolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570 (mod_pow(exponend, md))\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc135/tasks/abc135_d\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <vector>\n\
    \n#include \"../../../math/convolution/mod_convolution.hpp\"\n#include \"../../../math/formal_power_series/formal_power_series.hpp\"\
    \n#include \"../../../math/modint.hpp\"\n\nint main() {\n  using ModInt = MInt<0>;\n\
    \  ModInt::set_mod(1000000007);\n  FormalPowerSeries<ModInt>::set_mult(\n    \
    \  [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)\n          ->\
    \ std::vector<ModInt> {\n        return mod_convolution(a, b);\n      });\n  constexpr\
    \ int D = 6, M = 13;\n  std::string s;\n  std::cin >> s;\n  std::reverse(s.begin(),\
    \ s.end());\n  int q[D]{};\n  for (int i = 0; i < s.length(); ++i) {\n    if (s[i]\
    \ == '?') ++q[i % D];\n  }\n  std::vector<FormalPowerSeries<ModInt>> f(D, FormalPowerSeries<ModInt>(M));\n\
    \  FormalPowerSeries<ModInt> md(M);\n  md[0] = -1;\n  md[M] = 1;\n  for (int i\
    \ = 0; i < D; ++i) {\n    int base = 1;\n    for (int j = 0; j < i; ++j) {\n \
    \     base *= 10;\n    }\n    for (int j = 0; j < 10; ++j) {\n      ++f[i][base\
    \ * j % M];\n    }\n    f[i] = f[i].mod_pow(q[i], md);\n  }\n  for (int i = 1;\
    \ i < D; ++i) {\n    f.front() *= f[i];\n  }\n  f.front() %= md;\n  int idx =\
    \ D - 1, w = 1;\n  for (int i = 0; i < s.length(); ++i) {\n    if (s[i] != '?')\
    \ {\n      idx = (idx - w * (s[i] - '0')) % M;\n      if (idx < 0) idx += M;\n\
    \    }\n    w = w * 10 % M;\n  }\n  std::cout << f.front()[idx] << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - math/convolution/mod_convolution.hpp
  - math/modint.hpp
  - math/convolution/fast_fourier_transform.hpp
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/formal_power_series.5.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
