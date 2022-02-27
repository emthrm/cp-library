---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
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
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
      \u7684\u51AA\u7D1A\u6570 (\u7D2F\u4E57)"
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/number_theoretic_transform.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570 (\u7D2F\u4E57)\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../../math/convolution/number_theoretic_transform.hpp\"\
    \r\n#include \"../../../math/formal_power_series/formal_power_series.hpp\"\r\n\
    #include \"../../../math/modint.hpp\"\r\n\r\nint main() {\r\n  using ModInt =\
    \ MInt<0>;\r\n  ModInt::set_mod(998244353);\r\n  FormalPowerSeries<ModInt>::set_mult(\r\
    \n      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)\r\n   \
    \       -> std::vector<ModInt> {\r\n        static NumberTheoreticTransform<0>\
    \ ntt;\r\n        return ntt.convolution(a, b);\r\n      });\r\n  int n, m;\r\n\
    \  std::cin >> n >> m;\r\n  FormalPowerSeries<ModInt> a(n - 1);\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    std::cin >> a[i];\r\n  }\r\n  a = a.pow(m, n - 1);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    std::cout << a[i] << \" \\n\"[i + 1 ==\
    \ n];\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/convolution/number_theoretic_transform.hpp
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/formal_power_series.4.test.cpp
  requiredBy: []
  timestamp: '2022-02-27 17:53:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/formal_power_series.4.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/formal_power_series.4.test.cpp
- /verify/test/math/formal_power_series/formal_power_series.4.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
  \u7D1A\u6570 (\u7D2F\u4E57)"
---
