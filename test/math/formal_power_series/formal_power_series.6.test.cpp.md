---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':question:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':x:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':x:'
    path: math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':question:'
    path: util/xorshift.hpp
    title: xorshift
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
      \u7684\u51AA\u7D1A\u6570 (\u5E73\u65B9\u6839)"
    links:
    - https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
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
  code: "/*\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570 (\u5E73\u65B9\u6839)\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../math/convolution/number_theoretic_transform.hpp\"\
    \n#include \"../../../math/formal_power_series/formal_power_series.hpp\"\n#include\
    \ \"../../../math/mod_sqrt.hpp\"\n#include \"../../../math/modint.hpp\"\n\nint\
    \ main() {\n  using ModInt = MInt<0>;\n  ModInt::set_mod(998244353);\n  FormalPowerSeries<ModInt>::set_mult(\n\
    \      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)\n      \
    \    -> std::vector<ModInt> {\n        static NumberTheoreticTransform<0> ntt;\n\
    \        return ntt.convolution(a, b);\n      });\n  FormalPowerSeries<ModInt>::set_sqrt(\n\
    \      [](const ModInt& a, ModInt* res) -> bool {\n        const long long ans\
    \ = mod_sqrt(a.v, ModInt::get_mod());\n        if (ans == -1) {\n          return\
    \ false;\n        } else {\n          *res = ans;\n          return true;\n  \
    \      }\n      });\n  int n;\n  std::cin >> n;\n  FormalPowerSeries<ModInt> a(n\
    \ - 1);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  a = a.sqrt(n\
    \ - 1);\n  if (a.coef.empty()) {\n    std::cout << \"-1\\n\";\n  } else {\n  \
    \  for (int i = 0; i < n; ++i) {\n      std::cout << a[i] << \" \\n\"[i + 1 ==\
    \ n];\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/convolution/number_theoretic_transform.hpp
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  - math/mod_sqrt.hpp
  - util/xorshift.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/formal_power_series.6.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/formal_power_series/formal_power_series.6.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/formal_power_series.6.test.cpp
- /verify/test/math/formal_power_series/formal_power_series.6.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
  \u7D1A\u6570 (\u5E73\u65B9\u6839)"
---
