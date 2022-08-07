---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':question:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp
    title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868\
      \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\
      \u30B0\u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\
      \u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
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
  code: "/*\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\
    \u30B0\u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\
    \u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../../math/convolution/number_theoretic_transform.hpp\"\
    \n#include \"../../../../math/formal_power_series/formal_power_series.hpp\"\n\
    #include \"../../../../math/modint.hpp\"\n#include \"../../../../math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp\"\
    \n\nint main() {\n  using ModInt = MInt<0>;\n  ModInt::set_mod(998244353);\n \
    \ FormalPowerSeries<ModInt>::set_mult(\n      [](const std::vector<ModInt>& a,\
    \ const std::vector<ModInt>& b)\n          -> std::vector<ModInt> {\n        static\
    \ NumberTheoreticTransform<0> ntt;\n        return ntt.convolution(a, b);\n  \
    \    });\n  int n;\n  std::cin >> n;\n  const std::vector<ModInt> s =\n      stirling_number_of_the_second_kind_init_by_fps<0>(n);\n\
    \  for (int i = 0; i <= n; ++i) {\n    std::cout << s[i] << \" \\n\"[i == n];\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - math/convolution/number_theoretic_transform.hpp
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  - math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.test.cpp
- /verify/test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\
  /\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868 \u5F62\
  \u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
---
