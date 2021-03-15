---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/binary_matrix/binary_matrix.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: math/matrix/binary_matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':heavy_check_mark:'
    path: math/matrix/binary_matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\
      \u5217\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1421
    document_title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      /\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      \u7248"
    links:
    - https://yukicoder.me/problems/no/1421
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/binary_matrix.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    \u7248\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/1421\"\r\n\
    \r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../../math/matrix/binary_matrix/binary_matrix.hpp\"\
    \r\n#include \"../../../../math/matrix/binary_matrix/linear_equation.hpp\"\r\n\
    \r\nint main() {\r\n  constexpr int N = 50, B = 30;\r\n  using binary_matrix =\
    \ BinaryMatrix<N>;\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>>\
    \ b(m);\r\n  std::vector<int> y(m);\r\n  for (int i = 0; i < m; ++i) {\r\n   \
    \ int a;\r\n    std::cin >> a;\r\n    b[i].resize(a);\r\n    for (int j = 0; j\
    \ < a; ++j) {\r\n      std::cin >> b[i][j];\r\n      --b[i][j];\r\n    }\r\n \
    \   std::cin >> y[i];\r\n  }\r\n  std::vector<int> x(n, 0);\r\n  for (int bit\
    \ = 0; bit < B; ++bit) {\r\n    binary_matrix a(m, n, 0);\r\n    std::vector<bool>\
    \ v(m);\r\n    for (int i = 0; i < m; ++i) {\r\n      for (int bij : b[i]) a[i][bij]\
    \ = 1;\r\n      v[i] = y[i] >> bit & 1;\r\n    }\r\n    std::vector<bool> ans\
    \ = linear_equation(a, v);\r\n    if (ans.empty()) {\r\n      std::cout << \"\
    -1\\n\";\r\n      return 0;\r\n    }\r\n    for (int i = 0; i < n; ++i) x[i] |=\
    \ ans[i] << bit;\r\n  }\r\n  for (int i = 0; i < n; ++i) std::cout << x[i] <<\
    \ '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/matrix/binary_matrix/binary_matrix.hpp
  - math/matrix/binary_matrix/linear_equation.hpp
  - math/matrix/binary_matrix/gauss_jordan.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/linear_equation.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 03:49:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix/binary_matrix/linear_equation.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/binary_matrix/linear_equation.test.cpp
- /verify/test/math/matrix/binary_matrix/linear_equation.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9023\u7ACB\
  \u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
---
