---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix/binary_matrix/binary_matrix.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: math/matrix/binary_matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':heavy_check_mark:'
    path: math/matrix/binary_matrix/inverse_matrix.hpp
    title: "\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624
    document_title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      /\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/binary_matrix.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624\"\r\n\
    \r\n#include <bitset>\r\n#include <iostream>\r\n#include \"../../../../math/matrix/binary_matrix/binary_matrix.hpp\"\
    \r\n#include \"../../../../math/matrix/binary_matrix/inverse_matrix.hpp\"\r\n\
    #include \"../../../../math/matrix/binary_matrix/gauss_jordan.hpp\"\r\n\r\nint\
    \ main() {\r\n  constexpr int N = 600;\r\n  using binary_matrix = BinaryMatrix<N>;\r\
    \n  int n;\r\n  std::cin >> n;\r\n  binary_matrix a(n, n), v(n, 1);\r\n  for (int\
    \ i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {\r\n    int aij;\r\n    std::cin\
    \ >> aij;\r\n    a[i][j] = aij;\r\n  }\r\n  for (int i = 0; i < n; ++i) {\r\n\
    \    int vi;\r\n    std::cin >> vi;\r\n    v[i][0] = vi;\r\n  }\r\n  int t;\r\n\
    \  std::cin >> t;\r\n  binary_matrix inv = inverse_matrix(a);\r\n  if (inv.n ==\
    \ 0) {\r\n    a = a.pow(t);\r\n    binary_matrix av(n, n + 1);\r\n    for (int\
    \ i = 0; i < n; ++i) {\r\n      for (int j = 0; j < n; ++j) av[i][j] = a[i][j];\r\
    \n      av[i][n] = v[i][0];\r\n    }\r\n    int rank = gauss_jordan(a), rank_av\
    \ = gauss_jordan(av);\r\n    std::cout << (rank == rank_av ? \"ambiguous\\n\"\
    \ : \"none\\n\");\r\n  } else {\r\n    (inv = inv.pow(t)) *= v;\r\n    for (int\
    \ i = 0; i < n; ++i) std::cout << inv[i][0] << \" \\n\"[i + 1 == n];\r\n  }\r\n\
    \  return 0;\r\n}\r\n"
  dependsOn:
  - math/matrix/binary_matrix/binary_matrix.hpp
  - math/matrix/binary_matrix/inverse_matrix.hpp
  - math/matrix/binary_matrix/gauss_jordan.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
  requiredBy: []
  timestamp: '2021-03-04 20:20:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/binary_matrix/inverse_matrix.test.cpp
- /verify/test/math/matrix/binary_matrix/inverse_matrix.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9006\u884C\
  \u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
---
