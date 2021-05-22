---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6570\u8AD6\u5909\u63DB"
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/number_theoretic_transform.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6570\u8AD6\u5909\u63DB\
    \r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../math/modint.hpp\"\
    \r\n#include \"../../../math/convolution/number_theoretic_transform.hpp\"\r\n\r\
    \nint main() {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\
    \n  NumberTheoreticTransform<0> ntt;\r\n  int n, m;\r\n  std::cin >> n >> m;\r\
    \n  std::vector<int> a(n), b(m);\r\n  for (int i = 0; i < n; ++i) std::cin >>\
    \ a[i];\r\n  for (int i = 0; i < m; ++i) std::cin >> b[i];\r\n  std::vector<ModInt>\
    \ ans = ntt.convolution(a, b);\r\n  for (int i = 0; i <= (n - 1) + (m - 1); ++i)\
    \ std::cout << ans[i] << \" \\n\"[i == (n - 1) + (m - 1)];\r\n  return 0;\r\n\
    }\r\n"
  dependsOn:
  - math/modint.hpp
  - math/convolution/number_theoretic_transform.hpp
  isVerificationFile: true
  path: test/math/convolution/number_theoretic_transform.test.cpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/convolution/number_theoretic_transform.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/number_theoretic_transform.test.cpp
- /verify/test/math/convolution/number_theoretic_transform.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6570\u8AD6\u5909\u63DB"
---
