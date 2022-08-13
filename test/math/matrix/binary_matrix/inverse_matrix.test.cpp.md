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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/binary_matrix.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624\"\n\n#include\
    \ <bitset>\n#include <iostream>\n\n#include \"../../../../math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n#include \"../../../../math/matrix/binary_matrix/gauss_jordan.hpp\"\n#include\
    \ \"../../../../math/matrix/binary_matrix/inverse_matrix.hpp\"\n\nint main() {\n\
    \  constexpr int N = 600;\n  using binary_matrix = BinaryMatrix<N>;\n  int n;\n\
    \  std::cin >> n;\n  binary_matrix a(n, n), v(n, 1);\n  for (int i = 0; i < n;\
    \ ++i) {\n    for (int j = 0; j < n; ++j) {\n      int a_ij;\n      std::cin >>\
    \ a_ij;\n      a[i][j] = a_ij;\n    }\n  }\n  for (int i = 0; i < n; ++i) {\n\
    \    int v_i;\n    std::cin >> v_i;\n    v[i][0] = v_i;\n  }\n  int t;\n  std::cin\
    \ >> t;\n  binary_matrix inv = inverse_matrix(a);\n  if (inv.nrow() == 0) {\n\
    \    a = a.pow(t);\n    binary_matrix av(n, n + 1);\n    for (int i = 0; i < n;\
    \ ++i) {\n      for (int j = 0; j < n; ++j) {\n        av[i][j] = a[i][j];\n \
    \     }\n      av[i][n] = v[i][0];\n    }\n    std::cout << (gauss_jordan(&a)\
    \ == gauss_jordan(&av) ?\n                  \"ambiguous\\n\" : \"none\\n\");\n\
    \  } else {\n    inv = inv.pow(t) * v;\n    for (int i = 0; i < n; ++i) {\n  \
    \    std::cout << inv[i][0] << \" \\n\"[i + 1 == n];\n    }\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - math/matrix/binary_matrix/binary_matrix.hpp
  - math/matrix/binary_matrix/gauss_jordan.hpp
  - math/matrix/binary_matrix/inverse_matrix.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
