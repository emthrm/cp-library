---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/ntt.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':question:'
    path: math/fps/fps.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':heavy_check_mark:'
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
      \u7684\u51AA\u7D1A\u6570 (\u5E73\u65B9\u6839)"
    links:
    - https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/ntt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570 (\u5E73\u65B9\u6839)\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../math/modint.hpp\"\
    \r\n#include \"../../../math/fps/fps.hpp\"\r\n#include \"../../../math/convolution/ntt.hpp\"\
    \r\n#include \"../../../math/mod_sqrt.hpp\"\r\n\r\nint main() {\r\n  ModInt::set_mod(998244353);\r\
    \n  NTT ntt;\r\n  FPS<ModInt>::set_mul([&](const std::vector<ModInt> &a, const\
    \ std::vector<ModInt> &b) -> std::vector<ModInt> {\r\n    return ntt.convolution(a,\
    \ b);\r\n  });\r\n  FPS<ModInt>::set_sqr([&](const ModInt &a, ModInt &res) ->\
    \ bool {\r\n    long long ans = mod_sqrt(a.val, ModInt::get_mod());\r\n    if\
    \ (ans == -1) {\r\n      return false;\r\n    } else {\r\n      res = ans;\r\n\
    \      return true;\r\n    }\r\n  });\r\n  int n;\r\n  std::cin >> n;\r\n  FPS<ModInt>\
    \ fps(n - 1);\r\n  for (int i = 0; i < n; ++i) std::cin >> fps[i];\r\n  fps =\
    \ fps.sqrt(n - 1);\r\n  if (fps.co.empty()) {\r\n    std::cout << \"-1\\n\";\r\
    \n  } else {\r\n    for (int i = 0; i < n; ++i) std::cout << fps[i] << \" \\n\"\
    [i + 1 == n];\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/fps/fps.hpp
  - math/convolution/ntt.hpp
  - math/mod_sqrt.hpp
  - math/mod_pow.hpp
  - util/xorshift.hpp
  isVerificationFile: true
  path: test/math/fps/fps.6.test.cpp
  requiredBy: []
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/fps/fps.6.test.cpp
layout: document
redirect_from:
- /verify/test/math/fps/fps.6.test.cpp
- /verify/test/math/fps/fps.6.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
  \u7D1A\u6570 (\u5E73\u65B9\u6839)"
---
