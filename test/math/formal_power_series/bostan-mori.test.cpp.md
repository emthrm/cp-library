---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':x:'
    path: math/formal_power_series/bostan-mori.hpp
    title: "Bostan\u2013Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  - icon: ':question:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':x:'
    path: math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
    title: "\u7DDA\u5F62\u56DE\u5E30\u6570\u5217\u306E\u7B2C $N$ \u9805"
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013\
      Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/number_theoretic_transform.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013\
    Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <iostream>\n\n#include \"../../../math/convolution/number_theoretic_transform.hpp\"\
    \n#include \"../../../math/formal_power_series/formal_power_series.hpp\"\n#include\
    \ \"../../../math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp\"\
    \n#include \"../../../math/modint.hpp\"\n\nint main() {\n  using ModInt = MInt<0>;\n\
    \  ModInt::set_mod(998244353);\n  FormalPowerSeries<ModInt>::set_mult(\n     \
    \ [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)\n          ->\
    \ std::vector<ModInt> {\n        static NumberTheoreticTransform<0> ntt;\n   \
    \     return ntt.convolution(a, b);\n      });\n  int d;\n  long long k;\n  std::cin\
    \ >> d >> k;\n  FormalPowerSeries<ModInt> a(d - 1), c(d);\n  c[0] = 1;\n  for\
    \ (int i = 0; i < d; ++i) {\n    std::cin >> a[i];\n  }\n  for (int i = 1; i <=\
    \ d; ++i) {\n    std::cin >> c[i];\n    c[i] = -c[i];\n  }\n  std::cout << nth_term_of_linear_recurrence_sequence(a,\
    \ c, k) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/convolution/number_theoretic_transform.hpp
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  - math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
  - math/formal_power_series/bostan-mori.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/bostan-mori.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/formal_power_series/bostan-mori.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/bostan-mori.test.cpp
- /verify/test/math/formal_power_series/bostan-mori.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013Mori \u306E\u30A2\
  \u30EB\u30B4\u30EA\u30BA\u30E0"
---
