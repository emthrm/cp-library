---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/matching/maximum_matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
  - icon: ':x:'
    path: include/emthrm/math/matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/maximum_matching.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E00\
      \u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
  - icon: ':x:'
    path: test/math/matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
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
  code: "#ifndef EMTHRM_MATH_MATRIX_GAUSS_JORDAN_HPP_\n#define EMTHRM_MATH_MATRIX_GAUSS_JORDAN_HPP_\n\
    \n#include <utility>\n\n#include \"emthrm/math/matrix/matrix.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T>\nint gauss_jordan(Matrix<T>* a, const T eps\
    \ = 1e-8,\n                 const bool is_extended = false) {\n  const int m =\
    \ a->nrow(), n = a->ncol();\n  int rank = 0;\n  for (int col = 0; col < (is_extended\
    \ ? n - 1 : n); ++col) {\n    int pivot = -1;\n    T mx = eps;\n    for (int row\
    \ = rank; row < m; ++row) {\n      const T abs = ((*a)[row][col] < 0 ? -(*a)[row][col]\
    \ : (*a)[row][col]);\n      if (abs > mx) {\n        pivot = row;\n        mx\
    \ = abs;\n      }\n    }\n    if (pivot == -1) continue;\n    std::swap((*a)[rank],\
    \ (*a)[pivot]);\n    T tmp = (*a)[rank][col];\n    for (int col2 = 0; col2 < n;\
    \ ++col2) {\n      (*a)[rank][col2] /= tmp;\n    }\n    for (int row = 0; row\
    \ < m; ++row) {\n      if (row != rank &&\n          ((*a)[row][col] < 0 ? -(*a)[row][col]\
    \ : (*a)[row][col]) > eps) {\n        tmp = (*a)[row][col];\n        for (int\
    \ col2 = 0; col2 < n; ++col2) {\n          (*a)[row][col2] -= (*a)[rank][col2]\
    \ * tmp;\n        }\n      }\n    }\n    ++rank;\n  }\n  return rank;\n}\n\n}\
    \  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MATRIX_GAUSS_JORDAN_HPP_\n"
  dependsOn:
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: false
  path: include/emthrm/math/matrix/gauss_jordan.hpp
  requiredBy:
  - include/emthrm/graph/flow/matching/maximum_matching.hpp
  - include/emthrm/math/matrix/linear_equation.hpp
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/flow/matching/maximum_matching.test.cpp
  - test/math/matrix/linear_equation.test.cpp
documentation_of: include/emthrm/math/matrix/gauss_jordan.hpp
layout: document
title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5\
  \ (Gauss\u2013Jordan elimination)"
---

行基本変形を用いて行列を行階段形に変形するアルゴリズムである．


## 時間計算量

$O(M^2 N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`gauss_jordan(&a, ε = 1e-8, 拡大係数行列か? = false)`|行列 $A$ のランク|$A$ は行階段形に変形される．<br>要素の型は実数型または `ModInt` である．|


## 参考

- http://drken1215.hatenablog.com/entry/2019/03/20/202800


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0004/review/4088546/emthrm/C++14
