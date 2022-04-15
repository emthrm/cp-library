---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/bostan-mori.hpp
    title: "Bostan\u2013Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
    title: "\u7DDA\u5F62\u56DE\u5E30\u6570\u5217\u306E\u7B2C $N$ \u9805"
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013\
      Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/number_theoretic_transform.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013\
    Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"../../../math/convolution/number_theoretic_transform.hpp\"\
    \r\n#include \"../../../math/formal_power_series/formal_power_series.hpp\"\r\n\
    #include \"../../../math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp\"\
    \r\n#include \"../../../math/modint.hpp\"\r\n\r\nint main() {\r\n  using ModInt\
    \ = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\n  FormalPowerSeries<ModInt>::set_mult(\r\
    \n      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)\r\n   \
    \       -> std::vector<ModInt> {\r\n        static NumberTheoreticTransform<0>\
    \ ntt;\r\n        return ntt.convolution(a, b);\r\n      });\r\n  int d;\r\n \
    \ long long k;\r\n  std::cin >> d >> k;\r\n  FormalPowerSeries<ModInt> a(d - 1),\
    \ c(d);\r\n  c[0] = 1;\r\n  for (int i = 0; i < d; ++i) {\r\n    std::cin >> a[i];\r\
    \n  }\r\n  for (int i = 1; i <= d; ++i) {\r\n    std::cin >> c[i];\r\n    c[i]\
    \ = -c[i];\r\n  }\r\n  std::cout << nth_term_of_linear_recurrence_sequence(a,\
    \ c, k) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/convolution/number_theoretic_transform.hpp
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  - math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
  - math/formal_power_series/bostan-mori.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/bostan-mori.test.cpp
  requiredBy: []
  timestamp: '2022-02-27 17:53:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/bostan-mori.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/bostan-mori.test.cpp
- /verify/test/math/formal_power_series/bostan-mori.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013Mori \u306E\u30A2\
  \u30EB\u30B4\u30EA\u30BA\u30E0"
---
