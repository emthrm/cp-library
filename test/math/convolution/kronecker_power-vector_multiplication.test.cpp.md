---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp
    title: "\u30AF\u30ED\u30CD\u30C3\u30AB\u30FC\u51AA (Kronecker power) \u3068\u30D9\
      \u30AF\u30C8\u30EB\u306E\u7A4D"
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u30AF\u30ED\u30CD\u30C3\
      \u30AB\u30FC\u51AA\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D"
    links:
    - https://atcoder.jp/contests/abc288/tasks/abc288_g
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/convolution/kronecker_power-vector_multiplication.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u30AF\u30ED\u30CD\u30C3\
    \u30AB\u30FC\u51AA\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D\n */\n#define IGNORE\n\
    #define PROBLEM \"https://atcoder.jp/contests/abc288/tasks/abc288_g\"\n\n#include\
    \ <cmath>\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/convolution/kronecker_power-vector_multiplication.hpp\"\
    \n#include \"emthrm/math/matrix/matrix.hpp\"\n\nint main() {\n  int n;\n  std::cin\
    \ >> n;\n  const int m = std::llround(std::pow(3, n));\n  std::vector<int> a(m);\n\
    \  for (int i = 0; i < m; ++i) {\n    std::cin >> a[i];\n  }\n  emthrm::Matrix<int>\
    \ inv(3, 3);\n  inv[0][1] = inv[1][0] = inv[1][2] = inv[2][1] = 1;\n  inv[0][2]\
    \ = inv[1][1] = inv[2][0] = -1;\n  const std::vector<int> b =\n      emthrm::kronecker_power_vector_multiplication(inv,\
    \ a);\n  for (int i = 0; i < m; ++i) {\n    std::cout << b[i] << \" \\n\"[i +\
    \ 1 == m];\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: true
  path: test/math/convolution/kronecker_power-vector_multiplication.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 00:46:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/convolution/kronecker_power-vector_multiplication.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/kronecker_power-vector_multiplication.test.cpp
- /verify/test/math/convolution/kronecker_power-vector_multiplication.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u30AF\u30ED\u30CD\u30C3\u30AB\u30FC\
  \u51AA\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D"
---
