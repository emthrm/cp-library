---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/ntt.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':question:'
    path: math/fps/fps.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.hpp
    title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868\
      \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\
      \u30B0\u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\
      \u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/ntt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\
    \u30F3\u30B0\u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\
    \u6570\u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248\r\n */\r\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\r\n\r\
    \n#include <iostream>\r\n#include <vector>\r\n#include \"../../../../math/modint.hpp\"\
    \r\n#include \"../../../../math/convolution/ntt.hpp\"\r\n#include \"../../../../math/fps/fps.hpp\"\
    \r\n#include \"../../../../math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.hpp\"\
    \r\n\r\nint main() {\r\n  ModInt::set_mod(998244353);\r\n  NTT ntt;\r\n  FPS<ModInt>::set_mul([&](const\
    \ std::vector<ModInt> &a, const std::vector<ModInt> &b) -> std::vector<ModInt>\
    \ {\r\n    return ntt.convolution(a, b);\r\n  });\r\n  int n;\r\n  std::cin >>\
    \ n;\r\n  Combinatorics com(n);\r\n  std::vector<ModInt> s = stirling_number_of_the_second_kind_init_with_fps(n,\
    \ com);\r\n  for (int i = 0; i <= n; ++i) std::cout << s[i] << \" \\n\"[i == n];\r\
    \n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/convolution/ntt.hpp
  - math/fps/fps.hpp
  - math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
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
