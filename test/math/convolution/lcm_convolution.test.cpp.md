---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/convolution/lcm_convolution.hpp
    title: "\u6DFB\u3048\u5B57 lcm \u3067\u306E\u7573\u307F\u8FBC\u307F"
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
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 lcm\
      \ \u3067\u306E\u7573\u307F\u8FBC\u307F"
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/lcm_convolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 lcm\
    \ \u3067\u306E\u7573\u307F\u8FBC\u307F\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../math/convolution/lcm_convolution.hpp\"\
    \n#include \"../../../math/modint.hpp\"\n\nint main() {\n  using ModInt = MInt<0>;\n\
    \  ModInt::set_mod(998244353);\n  int n;\n  std::cin >> n;\n  std::vector<ModInt>\
    \ a(n + 1, 0), b(n + 1, 0);\n  for (int i = 1; i <= n; ++i) {\n    std::cin >>\
    \ a[i];\n  }\n  for (int i = 1; i <= n; ++i) {\n    std::cin >> b[i];\n  }\n \
    \ const std::vector<ModInt> c = lcm_convolution(a, b, n);\n  for (int i = 1; i\
    \ <= n; ++i) {\n    std::cout << c[i] << \" \\n\"[i == n];\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - math/convolution/lcm_convolution.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/math/convolution/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/convolution/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/lcm_convolution.test.cpp
- /verify/test/math/convolution/lcm_convolution.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 lcm \u3067\u306E\u7573\
  \u307F\u8FBC\u307F"
---
