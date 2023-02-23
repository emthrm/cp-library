---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/bostan-mori.hpp
    title: "Bostan\u2013Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
    title: "\u7DDA\u5F62\u56DE\u5E30\u6570\u5217\u306E\u7B2C $N$ \u9805"
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013\
      Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/convolution/number_theoretic_transform.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013\
    Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <iostream>\n\n#include \"emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n#include \"emthrm/math/formal_power_series/formal_power_series.hpp\"\n#include\
    \ \"emthrm/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nint main() {\n  constexpr int MOD = 998244353;\n\
    \  using ModInt = emthrm::MInt<MOD>;\n  emthrm::FormalPowerSeries<ModInt>::set_mult(\n\
    \      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)\n      \
    \    -> std::vector<ModInt> {\n        static emthrm::NumberTheoreticTransform<MOD>\
    \ ntt;\n        return ntt.convolution(a, b);\n      });\n  int d;\n  long long\
    \ k;\n  std::cin >> d >> k;\n  emthrm::FormalPowerSeries<ModInt> a(d - 1), c(d);\n\
    \  c[0] = 1;\n  for (int i = 0; i < d; ++i) {\n    std::cin >> a[i];\n  }\n  for\
    \ (int i = 1; i <= d; ++i) {\n    std::cin >> c[i];\n    c[i] = -c[i];\n  }\n\
    \  std::cout << emthrm::nth_term_of_linear_recurrence_sequence(a, c, k) << '\\\
    n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/number_theoretic_transform.hpp
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  - include/emthrm/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
  - include/emthrm/math/formal_power_series/bostan-mori.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/bostan-mori.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
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
