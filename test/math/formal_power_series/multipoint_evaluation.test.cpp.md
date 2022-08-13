---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/multipoint_evaluation.hpp
    title: multipoint evaluation
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
    PROBLEM: https://judge.yosupo.jp/problem/multipoint_evaluation
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/multipoint\
      \ evaluation"
    links:
    - https://judge.yosupo.jp/problem/multipoint_evaluation
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/number_theoretic_transform.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/multipoint\
    \ evaluation\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../math/convolution/number_theoretic_transform.hpp\"\
    \n#include \"../../../math/formal_power_series/formal_power_series.hpp\"\n#include\
    \ \"../../../math/formal_power_series/multipoint_evaluation.hpp\"\n#include \"\
    ../../../math/modint.hpp\"\n\nint main() {\n  using ModInt = MInt<0>;\n  ModInt::set_mod(998244353);\n\
    \  FormalPowerSeries<ModInt>::set_mult(\n      [](const std::vector<ModInt>& a,\
    \ const std::vector<ModInt>& b)\n          -> std::vector<ModInt> {\n        static\
    \ NumberTheoreticTransform<0> ntt;\n        return ntt.convolution(a, b);\n  \
    \    });\n  int n, m;\n  std::cin >> n >> m;\n  FormalPowerSeries<ModInt> c(n\
    \ - 1);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> c[i];\n  }\n  std::vector<ModInt>\
    \ p(m);\n  for (int i = 0; i < m; ++i) {\n    std::cin >> p[i];\n  }\n  MultipointEvaluation<FormalPowerSeries,\
    \ ModInt> multipoint_evaluation(p);\n  multipoint_evaluation.build(c);\n  for\
    \ (int i = 0; i < m; ++i) {\n    std::cout << multipoint_evaluation.f_x[i] <<\
    \ \" \\n\"[i + 1 == m];\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/convolution/number_theoretic_transform.hpp
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  - math/formal_power_series/multipoint_evaluation.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/multipoint_evaluation.test.cpp
  requiredBy: []
  timestamp: '2022-08-08 06:04:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/multipoint_evaluation.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/multipoint_evaluation.test.cpp
- /verify/test/math/formal_power_series/multipoint_evaluation.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/multipoint evaluation"
---
