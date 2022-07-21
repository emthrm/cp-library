---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/matrix/binary_matrix/binary_matrix.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
  - icon: ':x:'
    path: math/matrix/binary_matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/184
    document_title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      /\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5\
      \ \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    links:
    - https://yukicoder.me/problems/no/184
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/binary_matrix.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5\
    \ \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/184\"\
    \n\n#include <bitset>\n#include <iostream>\n\n#include \"../../../../math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n#include \"../../../../math/matrix/binary_matrix/gauss_jordan.hpp\"\n\nint main()\
    \ {\n  constexpr int B = 61;\n  int n;\n  std::cin >> n;\n  BinaryMatrix<B> matrix(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    long long a;\n    std::cin >> a;\n    matrix[i]\
    \ = std::bitset<B>(a);\n  }\n  std::cout << (1LL << gauss_jordan(&matrix)) <<\
    \ '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/matrix/binary_matrix/binary_matrix.hpp
  - math/matrix/binary_matrix/gauss_jordan.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/gauss_jordan.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/matrix/binary_matrix/gauss_jordan.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/binary_matrix/gauss_jordan.test.cpp
- /verify/test/math/matrix/binary_matrix/gauss_jordan.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u30AC\u30A6\
  \u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5 \u30D0\u30A4\u30CA\
  \u30EA\u884C\u5217\u7248"
---
