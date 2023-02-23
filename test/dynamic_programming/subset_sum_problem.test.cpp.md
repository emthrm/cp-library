---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/subset_sum_problem.hpp
    title: "\u90E8\u5206\u548C\u554F\u984C (subset sum problem)"
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
    PROBLEM: https://judge.yosupo.jp/problem/sharp_p_subset_sum
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u90E8\u5206\u548C\u554F\u984C"
    links:
    - https://judge.yosupo.jp/problem/sharp_p_subset_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/dynamic_programming/subset_sum_problem.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u90E8\u5206\u548C\u554F\u984C\
    \n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"emthrm/dynamic_programming/subset_sum_problem.hpp\"\
    \n#include \"emthrm/math/convolution/number_theoretic_transform.hpp\"\n#include\
    \ \"emthrm/math/formal_power_series/formal_power_series.hpp\"\n#include \"emthrm/math/modint.hpp\"\
    \n\nint main() {\n  constexpr int MOD = 998244353;\n  using ModInt = emthrm::MInt<MOD>;\n\
    \  emthrm::FormalPowerSeries<ModInt>::set_mult(\n      [](const std::vector<ModInt>&\
    \ a, const std::vector<ModInt>& b)\n          -> std::vector<ModInt> {\n     \
    \   static emthrm::NumberTheoreticTransform<MOD> ntt;\n        return ntt.convolution(a,\
    \ b);\n      });\n  int n, t;\n  std::cin >> n >> t;\n  std::vector<int> s(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> s[i];\n  }\n  const std::vector<ModInt>\
    \ p = emthrm::subset_sum_problem<ModInt>(s, t);\n  for (int i = 1; i <= t; ++i)\
    \ {\n    std::cout << p[i] << \" \\n\"[i == t];\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/subset_sum_problem.hpp
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  - include/emthrm/math/convolution/number_theoretic_transform.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/dynamic_programming/subset_sum_problem.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/subset_sum_problem.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/subset_sum_problem.test.cpp
- /verify/test/dynamic_programming/subset_sum_problem.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u90E8\u5206\u548C\u554F\u984C"
---
