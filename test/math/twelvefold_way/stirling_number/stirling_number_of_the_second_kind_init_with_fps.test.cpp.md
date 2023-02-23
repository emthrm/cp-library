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
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/convolution/number_theoretic_transform.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\
    \u30B0\u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\
    \u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/convolution/number_theoretic_transform.hpp\"\
    \n#include \"emthrm/math/formal_power_series/formal_power_series.hpp\"\n#include\
    \ \"emthrm/math/modint.hpp\"\n#include \"emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp\"\
    \n\nint main() {\n  constexpr int MOD = 998244353;\n  using ModInt = emthrm::MInt<MOD>;\n\
    \  emthrm::FormalPowerSeries<ModInt>::set_mult(\n      [](const std::vector<ModInt>&\
    \ a, const std::vector<ModInt>& b)\n          -> std::vector<ModInt> {\n     \
    \   static emthrm::NumberTheoreticTransform<MOD> ntt;\n        return ntt.convolution(a,\
    \ b);\n      });\n  int n;\n  std::cin >> n;\n  const std::vector<ModInt> s =\n\
    \      emthrm::stirling_number_of_the_second_kind_init_by_fps<MOD>(n);\n  for\
    \ (int i = 0; i <= n; ++i) {\n    std::cout << s[i] << \" \\n\"[i == n];\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/number_theoretic_transform.hpp
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  - include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
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
