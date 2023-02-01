---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/inverse_matrix.hpp
    title: "\u9006\u884C\u5217 (inverse matrix)"
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
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    document_title: "\u6570\u5B66/\u884C\u5217/\u9006\u884C\u5217"
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/matrix/inverse_matrix.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u884C\u5217/\u9006\u884C\u5217\n */\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include <iostream>\n\
    \n#include \"emthrm/math/matrix/inverse_matrix.hpp\"\n#include \"emthrm/math/matrix/matrix.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<998244353>;\n\
    \  int n;\n  std::cin >> n;\n  emthrm::Matrix<ModInt> a(n, n);\n  for (int i =\
    \ 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      std::cin >> a[i][j];\n\
    \    }\n  }\n  const emthrm::Matrix<ModInt> b = emthrm::inverse_matrix(a, ModInt(0));\n\
    \  if (b.nrow() == 0) {\n    std::cout << \"-1\\n\";\n  } else {\n    for (int\
    \ i = 0; i < n; ++i) {\n      for (int j = 0; j < n; ++j) {\n        std::cout\
    \ << b[i][j] << \" \\n\"[j + 1 == n];\n      }\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/matrix/inverse_matrix.hpp
  - include/emthrm/math/matrix/matrix.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/matrix/inverse_matrix.test.cpp
  requiredBy: []
  timestamp: '2023-01-30 16:05:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix/inverse_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/inverse_matrix.test.cpp
- /verify/test/math/matrix/inverse_matrix.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u9006\u884C\u5217"
---
