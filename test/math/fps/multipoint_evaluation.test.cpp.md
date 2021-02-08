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
    path: math/fps/multipoint_evaluation.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/ntt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/multipoint\
    \ evaluation\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../math/modint.hpp\"\
    \r\n#include \"../../../math/fps/fps.hpp\"\r\n#include \"../../../math/convolution/ntt.hpp\"\
    \r\n#include \"../../../math/fps/multipoint_evaluation.hpp\"\r\n\r\nint main()\
    \ {\r\n  ModInt::set_mod(998244353);\r\n  NTT ntt;\r\n  FPS<ModInt>::set_mul([&](const\
    \ std::vector<ModInt> &a, const std::vector<ModInt> &b) -> std::vector<ModInt>\
    \ {\r\n    return ntt.convolution(a, b);\r\n  });\r\n  int n, m;\r\n  std::cin\
    \ >> n >> m;\r\n  FPS<ModInt> c(n - 1);\r\n  for (int i = 0; i < n; ++i) std::cin\
    \ >> c[i];\r\n  std::vector<ModInt> p(m);\r\n  for (int i = 0; i < m; ++i) std::cin\
    \ >> p[i];\r\n  MultipointEvaluation<FPS, ModInt> multieval(p);\r\n  multieval.calc(c);\r\
    \n  for (int i = 0; i < m; ++i) std::cout << multieval.val[i] << \" \\n\"[i +\
    \ 1 == m];\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/fps/fps.hpp
  - math/convolution/ntt.hpp
  - math/fps/multipoint_evaluation.hpp
  isVerificationFile: true
  path: test/math/fps/multipoint_evaluation.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/fps/multipoint_evaluation.test.cpp
layout: document
redirect_from:
- /verify/test/math/fps/multipoint_evaluation.test.cpp
- /verify/test/math/fps/multipoint_evaluation.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/multipoint evaluation"
---
