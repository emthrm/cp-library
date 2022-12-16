---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/convolution/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  - icon: ':question:'
    path: include/emthrm/math/convolution/mod_convolution.hpp
    title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/bernoulli_number.hpp
    title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570 (Bernoulli number)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp
    title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\
      \u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
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
      \u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570\u7248"
    links:
    - https://yukicoder.me/problems/no/665
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/convolution/mod_convolution.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\
    \u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\
    \u7D1A\u6570\u7248\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/665\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/convolution/mod_convolution.hpp\"\
    \n#include \"emthrm/math/formal_power_series/faulhaber_by_fps.hpp\"\n#include\
    \ \"emthrm/math/formal_power_series/formal_power_series.hpp\"\n#include \"emthrm/math/modint.hpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<0>;\n  ModInt::set_mod(1000000007);\n\
    \  emthrm::FormalPowerSeries<ModInt>::set_mult(\n      [](const std::vector<ModInt>&\
    \ a, const std::vector<ModInt>& b)\n          -> std::vector<ModInt> {\n     \
    \   return emthrm::mod_convolution(a, b);\n      });\n  long long n;\n  int k;\n\
    \  std::cin >> n >> k;\n  std::cout << emthrm::faulhaber_by_fps<0>(n + 1, k) <<\
    \ '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/mod_convolution.hpp
  - include/emthrm/math/convolution/fast_fourier_transform.hpp
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp
  - include/emthrm/math/formal_power_series/bernoulli_number.hpp
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/faulhaber_by_fps.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
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
