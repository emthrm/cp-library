---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss\u2013Jordan elimination)"
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/matrix/gauss_jordan.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_MATH_MATRIX_LINEAR_EQUATION_HPP_\n#define EMTHRM_MATH_MATRIX_LINEAR_EQUATION_HPP_\n\
    \n#include <algorithm>\n#include <cmath>\n#include <vector>\n\n#include \"emthrm/math/matrix/gauss_jordan.hpp\"\
    \n#include \"emthrm/math/matrix/matrix.hpp\"\n\nnamespace emthrm {\n\ntemplate\
    \ <typename T, typename U = double>\nstd::vector<U> linear_equation(const Matrix<T>&\
    \ a, const std::vector<T>& b,\n                               const U eps = 1e-8)\
    \ {\n  const int m = a.nrow(), n = a.ncol();\n  Matrix<U> c(m, n + 1);\n  for\
    \ (int i = 0; i < m; ++i) {\n    std::copy(a[i].begin(), a[i].end(), c[i].begin());\n\
    \    c[i].back() = b[i];\n  }\n  const int rank = gauss_jordan(&c, eps, true);\n\
    \  for (int row = rank; row < m; ++row) {\n    if ((c[row].back() < 0 ? -c[row].back()\
    \ : c[row].back()) > eps) {\n      return std::vector<U>{};\n    }\n  }\n  std::vector<U>\
    \ res(n, 0);\n  for (int i = 0, j = 0; i < rank; ++i) {\n    while ((c[i][j] <\
    \ 0 ? -c[i][j] : c[i][j]) <= eps) ++j;\n    res[j++] = c[i].back();\n  }\n  return\
    \ res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MATRIX_LINEAR_EQUATION_HPP_\n"
  dependsOn:
  - include/emthrm/math/matrix/gauss_jordan.hpp
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: false
  path: include/emthrm/math/matrix/linear_equation.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/matrix/linear_equation.test.cpp
documentation_of: include/emthrm/math/matrix/linear_equation.hpp
layout: document
title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
---


## 時間計算量

$O(M^2 N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`linear_equation(a, b, ε = 1e-8)`|$A \boldsymbol{x} = \boldsymbol{b}$ を満たす $\boldsymbol{x}$|解なしのときは空配列となる．|


## TODO

- https://sotanishy.github.io/cp-library-cpp/math/system_of_linear_equations.cpp
- https://judge.yosupo.jp/problem/system_of_linear_equations
- LU 分解
  - https://ja.wikipedia.org/wiki/LU%E5%88%86%E8%A7%A3
  - https://github.com/satanic0258/Cpp_snippet/blob/master/src/math/LUdecomposition.cpp
  - http://www.prefield.com/algorithm/math/LU.html
- 疎行列の連立一次方程式
  - https://drive.google.com/file/d/1D7sRmUy-0XnZCay8Tr1PldJVFRM2NII5


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2171/review/5899058/emthrm/C++17
