---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy:
  - icon: ':x:'
    path: include/emthrm/graph/matrix_tree_theorem.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/matrix_tree_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/determinant.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/matrix/matrix.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_MATH_MATRIX_DETERMINANT_HPP_\n#define EMTHRM_MATH_MATRIX_DETERMINANT_HPP_\n\
    \n#include <algorithm>\n#include <utility>\n\n#include \"emthrm/math/matrix/matrix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T, typename U>\nU det(const Matrix<T>&\
    \ a, const U eps) {\n  const int n = a.nrow();\n  Matrix<U> b(n, n);\n  for (int\
    \ i = 0; i < n; ++i) {\n    std::copy(a[i].begin(), a[i].end(), b[i].begin());\n\
    \  }\n  U res = 1;\n  for (int j = 0; j < n; ++j) {\n    int pivot = -1;\n   \
    \ U mx = eps;\n    for (int i = j; i < n; ++i) {\n      const U abs = (b[i][j]\
    \ < 0 ? -b[i][j] : b[i][j]);\n      if (abs > mx) {\n        pivot = i;\n    \
    \    mx = abs;\n      }\n    }\n    if (pivot == -1) return 0;\n    if (pivot\
    \ != j) {\n      std::swap(b[j], b[pivot]);\n      res = -res;\n    }\n    res\
    \ *= b[j][j];\n    for (int k = j + 1; k < n; ++k) {\n      b[j][k] /= b[j][j];\n\
    \    }\n    for (int i = j + 1; i < n; ++i) {\n      for (int k = j + 1; k < n;\
    \ ++k) {\n        b[i][k] -= b[i][j] * b[j][k];\n      }\n    }\n  }\n  return\
    \ res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MATRIX_DETERMINANT_HPP_\n"
  dependsOn:
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: false
  path: include/emthrm/math/matrix/determinant.hpp
  requiredBy:
  - include/emthrm/graph/matrix_tree_theorem.hpp
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/matrix/determinant.test.cpp
  - test/graph/matrix_tree_theorem.test.cpp
documentation_of: include/emthrm/math/matrix/determinant.hpp
layout: document
title: "\u884C\u5217\u5F0F (determinant)"
---


## 時間計算量

$O(N^3)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T, typename U>`<br>`U det(const Matrix<T>& a, const U eps);`|$\lvert A \rvert$|


## 参考文献

- https://github.com/beet-aizu/library/blob/ebcad58b8480962339b18e316b826e56752b90c8/matrix/matrix.cpp


## TODO

- 固有多項式 (characteristic polynomial)
  - https://ja.wikipedia.org/wiki/%E5%9B%BA%E6%9C%89%E5%A4%9A%E9%A0%85%E5%BC%8F
  - https://github.com/yosupo06/library-checker-problems/issues/665
  - https://judge.yosupo.jp/problem/characteristic_polynomial
  - https://yukicoder.me/problems/no/1907
- 任意の法の下での行列式
  - https://judge.yosupo.jp/problem/matrix_det_arbitrary_mod
  - https://github.com/yosupo06/library-checker-problems/issues/750


## Submissons

https://judge.yosupo.jp/submission/2714
