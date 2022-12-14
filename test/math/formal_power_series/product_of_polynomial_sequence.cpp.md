---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':warning:'
    path: math/formal_power_series/product_of_polynomial_sequence.hpp
    title: "\u591A\u9805\u5F0F\u5217\u306E\u76F8\u4E57"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u591A\u9805\
      \u5F0F\u5217\u306E\u76F8\u4E57"
    links:
    - https://judge.yosupo.jp/problem/product_of_polynomial_sequence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/number_theoretic_transform.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u591A\u9805\
    \u5F0F\u5217\u306E\u76F8\u4E57\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/product_of_polynomial_sequence\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\n#include \"\
    ../../../math/convolution/number_theoretic_transform.hpp\"\n#include \"../../../math/formal_power_series/formal_power_series.hpp\"\
    \n#include \"../../../math/formal_power_series/product_of_polynomial_sequence.hpp\"\
    \n#include \"../../../math/modint.hpp\"\n\nint main() {\n  using ModInt = MInt<0>;\n\
    \  ModInt::set_mod(998244353);\n  FormalPowerSeries<ModInt>::set_mult(\n     \
    \ [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)\n          ->\
    \ std::vector<ModInt> {\n        static NumberTheoreticTransform<0> ntt;\n   \
    \     return ntt.convolution(a, b);\n      });\n  int n;\n  std::cin >> n;\n \
    \ int degree = 0;\n  std::vector<FormalPowerSeries<ModInt>> f(n);\n  for (int\
    \ i = 0; i < n; ++i) {\n    int d;\n    std::cin >> d;\n    degree += d;\n   \
    \ f[i].resize(d);\n    for (int j = 0; j <= d; ++j) {\n      std::cin >> f[i][j];\n\
    \    }\n  }\n  FormalPowerSeries<ModInt> a = product_of_polynomial_sequence(f);\n\
    \  assert(a.degree() <= degree);\n  a.resize(degree);\n  for (int i = 0; i <=\
    \ degree; ++i) {\n    std::cout << a[i] << \" \\n\"[i == degree];\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - math/convolution/number_theoretic_transform.hpp
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  - math/formal_power_series/product_of_polynomial_sequence.hpp
  isVerificationFile: false
  path: test/math/formal_power_series/product_of_polynomial_sequence.cpp
  requiredBy: []
  timestamp: '2022-11-18 19:47:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/math/formal_power_series/product_of_polynomial_sequence.cpp
layout: document
redirect_from:
- /library/test/math/formal_power_series/product_of_polynomial_sequence.cpp
- /library/test/math/formal_power_series/product_of_polynomial_sequence.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u591A\u9805\u5F0F\u5217\
  \u306E\u76F8\u4E57"
---
