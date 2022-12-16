---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/matrix/determinant.hpp
    title: "\u884C\u5217\u5F0F (determinant)"
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    document_title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217\u5F0F"
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/matrix/determinant.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u884C\u5217/\u884C\u5217\u5F0F\n */\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include <iostream>\n\
    \n#include \"emthrm/math/matrix/determinant.hpp\"\n#include \"emthrm/math/matrix/matrix.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<0>;\n\
    \  ModInt::set_mod(998244353);\n  int n;\n  std::cin >> n;\n  emthrm::Matrix<int>\
    \ a(n, n);\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n\
    \      std::cin >> a[i][j];\n    }\n  }\n  std::cout << emthrm::det(a, ModInt(0))\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/matrix/determinant.hpp
  - include/emthrm/math/matrix/matrix.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/matrix/determinant.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix/determinant.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/determinant.test.cpp
- /verify/test/math/matrix/determinant.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217\u5F0F"
---
