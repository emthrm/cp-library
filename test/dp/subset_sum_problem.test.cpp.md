---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/subset_sum_problem.hpp
    title: "\u90E8\u5206\u548C\u554F\u984C (subset sum problem)"
  - icon: ':heavy_check_mark:'
    path: math/convolution/ntt.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':question:'
    path: math/fps/fps.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
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
    PROBLEM: https://judge.yosupo.jp/problem/sharp_p_subset_sum
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u90E8\u5206\u548C\u554F\u984C"
    links:
    - https://judge.yosupo.jp/problem/sharp_p_subset_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/ntt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u90E8\u5206\u548C\u554F\u984C\
    \r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../math/modint.hpp\"\
    \r\n#include \"../../math/convolution/ntt.hpp\"\r\n#include \"../../math/fps/fps.hpp\"\
    \r\n#include \"../../dp/subset_sum_problem.hpp\"\r\n\r\nint main() {\r\n  using\
    \ ModInt = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\n  NTT<0> ntt;\r\n  FPS<ModInt>::set_mul([&](const\
    \ std::vector<ModInt> &a, const std::vector<ModInt> &b) -> std::vector<ModInt>\
    \ {\r\n    return ntt.convolution(a, b);\r\n  });\r\n  int n, t;\r\n  std::cin\
    \ >> n >> t;\r\n  std::vector<int> s(n);\r\n  for (int i = 0; i < n; ++i) std::cin\
    \ >> s[i];\r\n  std::vector<ModInt> p = subset_sum_problem<ModInt>(s, t);\r\n\
    \  for (int i = 1; i <= t; ++i) std::cout << p[i] << \" \\n\"[i == t];\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/convolution/ntt.hpp
  - math/fps/fps.hpp
  - dp/subset_sum_problem.hpp
  isVerificationFile: true
  path: test/dp/subset_sum_problem.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dp/subset_sum_problem.test.cpp
layout: document
redirect_from:
- /verify/test/dp/subset_sum_problem.test.cpp
- /verify/test/dp/subset_sum_problem.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u90E8\u5206\u548C\u554F\u984C"
---
