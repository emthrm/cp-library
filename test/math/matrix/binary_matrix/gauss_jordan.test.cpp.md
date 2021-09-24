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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/184
    document_title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      /\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5\
      \ \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    links:
    - https://yukicoder.me/problems/no/184
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
    /\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5\
    \ \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/184\"\
    \r\n\r\n#include <bitset>\r\n#include <iostream>\r\n#include \"../../../../math/matrix/binary_matrix/binary_matrix.hpp\"\
    \r\n#include \"../../../../math/matrix/binary_matrix/gauss_jordan.hpp\"\r\n\r\n\
    int main() {\r\n  constexpr int N = 61;\r\n  int n;\r\n  std::cin >> n;\r\n  BinaryMatrix<N>\
    \ mat(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    long long a;\r\n    std::cin\
    \ >> a;\r\n    mat[i] = std::bitset<N>(a);\r\n  }\r\n  int rank = gauss_jordan(mat);\r\
    \n  long long ans = 1LL << rank;\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\
    \n}\r\n"
  dependsOn:
  - math/matrix/binary_matrix/binary_matrix.hpp
  - math/matrix/binary_matrix/gauss_jordan.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/gauss_jordan.test.cpp
  requiredBy: []
  timestamp: '2021-03-04 17:06:38+09:00'
  verificationStatus: TEST_ACCEPTED
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
