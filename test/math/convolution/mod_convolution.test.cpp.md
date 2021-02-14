---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/fft.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  - icon: ':question:'
    path: math/convolution/mod_convolution.hpp
    title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u4EFB\u610F\u306E\u6CD5\
      \u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
    links:
    - https://atcoder.jp/contests/atc001/tasks/fft_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/mod_convolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u4EFB\u610F\u306E\u6CD5\
    \u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F\r\n */\r\n#define IGNORE\r\n\
    #define PROBLEM \"https://atcoder.jp/contests/atc001/tasks/fft_c\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include \"../../../math/modint.hpp\"\r\n\
    #include \"../../../math/convolution/mod_convolution.hpp\"\r\n\r\nint main() {\r\
    \n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(1000000001);\r\n  int n;\r\n\
    \  std::cin >> n;\r\n  std::vector<ModInt> a(n + 1, 0), b(n + 1, 0);\r\n  for\
    \ (int i = 1; i <= n; ++i) std::cin >> a[i] >> b[i];\r\n  std::vector<ModInt>\
    \ ans = mod_convolution(a, b);\r\n  for (int i = 1; i <= n * 2; ++i) std::cout\
    \ << ans[i] << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/convolution/mod_convolution.hpp
  - math/convolution/fft.hpp
  isVerificationFile: true
  path: test/math/convolution/mod_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-02-15 03:05:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/convolution/mod_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/mod_convolution.test.cpp
- /verify/test/math/convolution/mod_convolution.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\
  \u3067\u306E\u7573\u307F\u8FBC\u307F"
---
