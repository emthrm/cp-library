---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/lcm_convolution.hpp
    title: "\u6DFB\u3048\u5B57 lcm \u3067\u306E\u7573\u307F\u8FBC\u307F"
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
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 lcm\
      \ \u3067\u306E\u7573\u307F\u8FBC\u307F"
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/lcm_convolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57\
    \ lcm \u3067\u306E\u7573\u307F\u8FBC\u307F\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../../math/convolution/lcm_convolution.hpp\"\
    \r\n#include \"../../../math/modint.hpp\"\r\n\r\nint main() {\r\n  using ModInt\
    \ = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\n  int n;\r\n  std::cin >> n;\r\
    \n  std::vector<ModInt> a(n + 1, 0), b(n + 1, 0);\r\n  for (int i = 1; i <= n;\
    \ ++i) {\r\n    std::cin >> a[i];\r\n  }\r\n  for (int i = 1; i <= n; ++i) {\r\
    \n    std::cin >> b[i];\r\n  }\r\n  const std::vector<ModInt> c = lcm_convolution(a,\
    \ b, n);\r\n  for (int i = 1; i <= n; ++i) {\r\n    std::cout << c[i] << \" \\\
    n\"[i == n];\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/convolution/lcm_convolution.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/math/convolution/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-02-20 12:20:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/convolution/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/lcm_convolution.test.cpp
- /verify/test/math/convolution/lcm_convolution.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 lcm \u3067\u306E\u7573\
  \u307F\u8FBC\u307F"
---
