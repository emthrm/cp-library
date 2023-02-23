---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/matrix/inverse_matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9006\u884C\u5217"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  code: "#ifndef EMTHRM_MATH_MATRIX_INVERSE_MATRIX_HPP_\n#define EMTHRM_MATH_MATRIX_INVERSE_MATRIX_HPP_\n\
    \n#include <algorithm>\n#include <iterator>\n#include <utility>\n\n#include \"\
    emthrm/math/matrix/matrix.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename T,\
    \ typename U = double>\nMatrix<U> inverse_matrix(const Matrix<T>& a, const U eps\
    \ = 1e-8) {\n  const int n = a.nrow();\n  Matrix<U> b(n, n << 1, 0);\n  for (int\
    \ i = 0; i < n; ++i) {\n    std::copy(a[i].begin(), a[i].end(), b[i].begin());\n\
    \    b[i][n + i] = 1;\n  }\n  for (int col = 0; col < n; ++col) {\n    int pivot\
    \ = -1;\n    U mx = eps;\n    for (int row = col; row < n; ++row) {\n      const\
    \ U abs = (b[row][col] < 0 ? -b[row][col] : b[row][col]);\n      if (abs > mx)\
    \ {\n        pivot = row;\n        mx = abs;\n      }\n    }\n    if (pivot ==\
    \ -1) return Matrix<U>(0, 0);\n    std::swap(b[col], b[pivot]);\n    U tmp = b[col][col];\n\
    \    for (int col2 = 0; col2 < (n << 1); ++col2) {\n      b[col][col2] /= tmp;\n\
    \    }\n    for (int row = 0; row < n; ++row) {\n      if (row != col && (b[row][col]\
    \ < 0 ? -b[row][col] : b[row][col]) > eps) {\n        tmp = b[row][col];\n   \
    \     for (int col2 = 0; col2 < (n << 1); ++col2) {\n          b[row][col2] -=\
    \ b[col][col2] * tmp;\n        }\n      }\n    }\n  }\n  Matrix<U> inv(n, n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::copy(std::next(b[i].begin(), n), b[i].end(),\
    \ inv[i].begin());\n  }\n  return inv;\n}\n\n}  // namespace emthrm\n\n#endif\
    \  // EMTHRM_MATH_MATRIX_INVERSE_MATRIX_HPP_\n"
  dependsOn:
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: false
  path: include/emthrm/math/matrix/inverse_matrix.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/matrix/inverse_matrix.test.cpp
documentation_of: include/emthrm/math/matrix/inverse_matrix.hpp
layout: document
title: "\u9006\u884C\u5217 (inverse matrix)"
---


## 時間計算量

$O(M^2 N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T, typename U = double>`<br>`Matrix<U> inverse_matrix(const Matrix<T>& a, const U eps = 1e-8);`|行列 $A$ の逆行列。ただし存在しないときは空行列を返す。|


## Submissons

https://judge.yosupo.jp/submission/50854
