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
    /\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    \u7248\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/1421\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../../../math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n#include \"../../../../math/matrix/binary_matrix/linear_equation.hpp\"\n\nint\
    \ main() {\n  constexpr int N = 50, B = 30;\n  int n, m;\n  std::cin >> n >> m;\n\
    \  std::vector<std::vector<int>> b(m);\n  std::vector<int> y(m);\n  for (int i\
    \ = 0; i < m; ++i) {\n    int a;\n    std::cin >> a;\n    b[i].resize(a);\n  \
    \  for (int j = 0; j < a; ++j) {\n      std::cin >> b[i][j];\n      --b[i][j];\n\
    \    }\n    std::cin >> y[i];\n  }\n  std::vector<int> x(n, 0);\n  for (int bit\
    \ = 0; bit < B; ++bit) {\n    BinaryMatrix<N> a(m, n, false);\n    std::vector<bool>\
    \ v(m);\n    for (int i = 0; i < m; ++i) {\n      for (const int b_ij : b[i])\
    \ a[i].set(b_ij);\n      v[i] = y[i] >> bit & 1;\n    }\n    const std::vector<bool>\
    \ ans = linear_equation(a, v);\n    if (ans.empty()) {\n      std::cout << \"\
    -1\\n\";\n      return 0;\n    }\n    for (int i = 0; i < n; ++i) {\n      if\
    \ (ans[i]) x[i] |= 1 << bit;\n    }\n  }\n  for (int i = 0; i < n; ++i) {\n  \
    \  std::cout << x[i] << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/matrix/binary_matrix/binary_matrix.hpp
  - math/matrix/binary_matrix/linear_equation.hpp
  - math/matrix/binary_matrix/gauss_jordan.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/linear_equation.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
