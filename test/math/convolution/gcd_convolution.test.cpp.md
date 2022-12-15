---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/gcd_convolution.hpp
    title: "\u6DFB\u3048\u5B57 gcd \u3067\u306E\u7573\u307F\u8FBC\u307F"
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
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 gcd\
      \ \u3067\u306E\u7573\u307F\u8FBC\u307F"
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/convolution/gcd_convolution.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 gcd\
    \ \u3067\u306E\u7573\u307F\u8FBC\u307F\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/convolution/gcd_convolution.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<0>;\n\
    \  ModInt::set_mod(998244353);\n  int n;\n  std::cin >> n;\n  std::vector<ModInt>\
    \ a(n + 1, 0), b(n + 1, 0);\n  for (int i = 1; i <= n; ++i) {\n    std::cin >>\
    \ a[i];\n  }\n  for (int i = 1; i <= n; ++i) {\n    std::cin >> b[i];\n  }\n \
    \ const std::vector<ModInt> c = emthrm::gcd_convolution(a, b);\n  for (int i =\
    \ 1; i <= n; ++i) {\n    std::cout << c[i] << \" \\n\"[i == n];\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/gcd_convolution.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/convolution/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/convolution/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/gcd_convolution.test.cpp
- /verify/test/math/convolution/gcd_convolution.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 gcd \u3067\u306E\u7573\
  \u307F\u8FBC\u307F"
---
