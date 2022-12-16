---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
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
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_taylor_shift
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
      \u7684\u51AA\u7D1A\u6570 (translate(c))"
    links:
    - https://judge.yosupo.jp/problem/polynomial_taylor_shift
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/convolution/number_theoretic_transform.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570 (translate(c))\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_taylor_shift\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n#include \"emthrm/math/formal_power_series/formal_power_series.hpp\"\n#include\
    \ \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<0>;\n\
    \  ModInt::set_mod(998244353);\n  emthrm::FormalPowerSeries<ModInt>::set_mult(\n\
    \      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)\n      \
    \    -> std::vector<ModInt> {\n        static emthrm::NumberTheoreticTransform<0>\
    \ ntt;\n        return ntt.convolution(a, b);\n      });\n  int n, c;\n  std::cin\
    \ >> n >> c;\n  emthrm::FormalPowerSeries<ModInt> a(n - 1);\n  for (int i = 0;\
    \ i < n; ++i) {\n    std::cin >> a[i];\n  }\n  a = a.translate(c);\n  for (int\
    \ i = 0; i < n; ++i) {\n    std::cout << a[i] << \" \\n\"[i + 1 == n];\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/number_theoretic_transform.hpp
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/formal_power_series.7.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/formal_power_series.7.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/formal_power_series.7.test.cpp
- /verify/test/math/formal_power_series/formal_power_series.7.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
  \u7D1A\u6570 (translate(c))"
---
