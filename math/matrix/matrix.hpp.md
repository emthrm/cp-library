---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/flow/matching/tutte_theorem.hpp
    title: "\u30BF\u30C3\u30C8\u306E\u5B9A\u7406"
  - icon: ':x:'
    path: graph/matrix_tree_theorem.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':question:'
    path: math/matrix/determinant.hpp
    title: "\u884C\u5217\u5F0F (determinant)"
  - icon: ':question:'
    path: math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss-Jordan elimination)"
  - icon: ':heavy_check_mark:'
    path: math/matrix/inverse_matrix.hpp
    title: "\u9006\u884C\u5217 (inverse matrix)"
  - icon: ':x:'
    path: math/matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/tutte_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u30BF\
      \u30C3\u30C8\u306E\u5B9A\u7406"
  - icon: ':x:'
    path: test/graph/matrix_tree_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/determinant.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217\u5F0F"
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/inverse_matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9006\u884C\u5217"
  - icon: ':x:'
    path: test/math/matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/matrix.hpp\"\n#include <utility>\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename T>\r\nstruct Matrix {\r\n  Matrix(int m,\
    \ int n, T val = 0) : dat(m, std::vector<T>(n, val)) {}\r\n\r\n  int height()\
    \ const { return dat.size(); }\r\n\r\n  int width() const { return dat.front().size();\
    \ }\r\n\r\n  Matrix pow(long long exponent) const {\r\n    int n = height();\r\
    \n    Matrix<T> tmp = *this, res(n, n, 0);\r\n    for (int i = 0; i < n; ++i)\
    \ res[i][i] = 1;\r\n    while (exponent > 0) {\r\n      if (exponent & 1) res\
    \ *= tmp;\r\n      tmp *= tmp;\r\n      exponent >>= 1;\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  inline const std::vector<T> &operator[](const int idx)\
    \ const { return dat[idx]; }\r\n  inline std::vector<T> &operator[](const int\
    \ idx) { return dat[idx]; }\r\n\r\n  Matrix &operator=(const Matrix &x) {\r\n\
    \    int m = x.height(), n = x.width();\r\n    dat.resize(m, std::vector<T>(n));\r\
    \n    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] = x[i][j];\r\
    \n    return *this;\r\n  }\r\n\r\n  Matrix &operator+=(const Matrix &x) {\r\n\
    \    int m = height(), n = width();\r\n    for (int i = 0; i < m; ++i) for (int\
    \ j = 0; j < n; ++j) dat[i][j] += x[i][j];\r\n    return *this;\r\n  }\r\n\r\n\
    \  Matrix &operator-=(const Matrix &x) {\r\n    int m = height(), n = width();\r\
    \n    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] -= x[i][j];\r\
    \n    return *this;\r\n  }\r\n\r\n  Matrix &operator*=(const Matrix &x) {\r\n\
    \    int m = height(), n = x.width(), l = width();\r\n    std::vector<std::vector<T>>\
    \ res(m, std::vector<T>(n, 0));\r\n    for (int i = 0; i < m; ++i) for (int j\
    \ = 0; j < n; ++j) {\r\n      for (int k = 0; k < l; ++k) res[i][j] += dat[i][k]\
    \ * x[k][j];\r\n    }\r\n    std::swap(dat, res);\r\n    return *this;\r\n  }\r\
    \n\r\n  Matrix operator+(const Matrix &x) const { return Matrix(*this) += x; }\r\
    \n\r\n  Matrix operator-(const Matrix &x) const { return Matrix(*this) -= x; }\r\
    \n\r\n  Matrix operator*(const Matrix &x) const { return Matrix(*this) *= x; }\r\
    \n\r\nprivate:\r\n  std::vector<std::vector<T>> dat;\r\n};\r\n"
  code: "#pragma once\r\n#include <utility>\r\n#include <vector>\r\n\r\ntemplate <typename\
    \ T>\r\nstruct Matrix {\r\n  Matrix(int m, int n, T val = 0) : dat(m, std::vector<T>(n,\
    \ val)) {}\r\n\r\n  int height() const { return dat.size(); }\r\n\r\n  int width()\
    \ const { return dat.front().size(); }\r\n\r\n  Matrix pow(long long exponent)\
    \ const {\r\n    int n = height();\r\n    Matrix<T> tmp = *this, res(n, n, 0);\r\
    \n    for (int i = 0; i < n; ++i) res[i][i] = 1;\r\n    while (exponent > 0) {\r\
    \n      if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n      exponent >>=\
    \ 1;\r\n    }\r\n    return res;\r\n  }\r\n\r\n  inline const std::vector<T> &operator[](const\
    \ int idx) const { return dat[idx]; }\r\n  inline std::vector<T> &operator[](const\
    \ int idx) { return dat[idx]; }\r\n\r\n  Matrix &operator=(const Matrix &x) {\r\
    \n    int m = x.height(), n = x.width();\r\n    dat.resize(m, std::vector<T>(n));\r\
    \n    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] = x[i][j];\r\
    \n    return *this;\r\n  }\r\n\r\n  Matrix &operator+=(const Matrix &x) {\r\n\
    \    int m = height(), n = width();\r\n    for (int i = 0; i < m; ++i) for (int\
    \ j = 0; j < n; ++j) dat[i][j] += x[i][j];\r\n    return *this;\r\n  }\r\n\r\n\
    \  Matrix &operator-=(const Matrix &x) {\r\n    int m = height(), n = width();\r\
    \n    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] -= x[i][j];\r\
    \n    return *this;\r\n  }\r\n\r\n  Matrix &operator*=(const Matrix &x) {\r\n\
    \    int m = height(), n = x.width(), l = width();\r\n    std::vector<std::vector<T>>\
    \ res(m, std::vector<T>(n, 0));\r\n    for (int i = 0; i < m; ++i) for (int j\
    \ = 0; j < n; ++j) {\r\n      for (int k = 0; k < l; ++k) res[i][j] += dat[i][k]\
    \ * x[k][j];\r\n    }\r\n    std::swap(dat, res);\r\n    return *this;\r\n  }\r\
    \n\r\n  Matrix operator+(const Matrix &x) const { return Matrix(*this) += x; }\r\
    \n\r\n  Matrix operator-(const Matrix &x) const { return Matrix(*this) -= x; }\r\
    \n\r\n  Matrix operator*(const Matrix &x) const { return Matrix(*this) *= x; }\r\
    \n\r\nprivate:\r\n  std::vector<std::vector<T>> dat;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/matrix.hpp
  requiredBy:
  - graph/flow/matching/tutte_theorem.hpp
  - graph/matrix_tree_theorem.hpp
  - math/matrix/determinant.hpp
  - math/matrix/inverse_matrix.hpp
  - math/matrix/gauss_jordan.hpp
  - math/matrix/linear_equation.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/flow/matching/tutte_theorem.test.cpp
  - test/graph/matrix_tree_theorem.test.cpp
  - test/math/matrix/inverse_matrix.test.cpp
  - test/math/matrix/matrix.test.cpp
  - test/math/matrix/linear_equation.test.cpp
  - test/math/matrix/determinant.test.cpp
documentation_of: math/matrix/matrix.hpp
layout: document
title: "\u884C\u5217 (matrix)"
---


## 時間計算量

|処理|時間計算量|
|:--:|:--:|
|加算|$O(MN)$|
|減算|$O(MN)$|
|乗算|$O(N^3)$|
|行列累乗|$O(N^3 \log{M})$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Matrix<T>(m, n, val = 0)`|初期値 $\mathrm{val}$ の $M \times N$ 型行列||
|`height()`|行の数||
|`width()`|列の数||
|`pow(n)`|$A^n$|半環上で成立する．|
|`operator[](idx)`|$A$ の $\mathrm{idx}$ 行目||
|`operator=(x)`|代入||
|`operator+=(x)`<br>`operator+(x)`|加算||
|`operator-=(x)`<br>`operator-(x)`|減算||
|`operator*=(x)`<br>`operator*(x)`|乗算|半環上で成立する．|


## 参考

- https://ei1333.github.io/luzhiled/snippets/math/matrix.html


## ToDo

- https://github.com/eandbsoftware/libraryCPP/blob/master/!Matrix.cpp
- 疎行列 (sparse matrix)
  - https://ja.wikipedia.org/wiki/%E7%96%8E%E8%A1%8C%E5%88%97
  - https://github.com/ei1333/library/blob/master/math/sparse-matrix.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Math/SparseMatrix.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Math/SparseSquareMatrix.cpp
  - https://judge.yosupo.jp/problem/sparse_matrix_det
  - https://atcoder.jp/contests/indeednow-finala-open/tasks/indeednow_2015_finala_e
- 正方行列 (square matrix)
  - https://ja.wikipedia.org/wiki/%E6%AD%A3%E6%96%B9%E8%A1%8C%E5%88%97
  - https://github.com/beet-aizu/library/blob/master/matrix/squarematrix.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Math/SquareMatrix.cpp
- ウェーブレット行列 (wavelet matrix)
  - https://www.hamayanhamayan.com/entry/2017/06/13/103352
  - https://takeda25.hatenablog.jp/entry/20130303/1362301095
  - http://miti-7.hatenablog.com/entry/2018/04/28/152259
  - https://scrapbox.io/data-structures/Wavelet_Matrix
  - https://www.dropbox.com/sh/9lknvq4xay709cn/AAAX61z5W1m20MPkJ8V53l5ma/%23WaveletMatrix.cpp?dl=0
  - https://www.pandanoir.info/entry/2016/03/01/230031
  - https://github.com/MitI-7/Algorithm/wiki/%E3%82%A6%E3%82%A7%E3%83%BC%E3%83%96%E3%83%AC%E3%83%83%E3%83%88%E8%A1%8C%E5%88%97
  - https://anta1.hatenadiary.org/entry/20130114/1358113488
  - https://docs.google.com/presentation/d/1J7jl8BLHkbukicFzSP7zNYTcwF-DPevCUfVxD4VjzX0
  - https://algoogle.hadrori.jp/algorithm/wavelet.html
  - https://ei1333.github.io/algorithm/wavelet-matrix.html
  - https://ei1333.github.io/luzhiled/snippets/structure/wavelet-matrix.html
  - https://github.com/ei1333/library/tree/master/structure/wavelet
  - https://github.com/beet-aizu/library/blob/master/datastructure/waveletmatrix.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/data_structure/wavelet_matrix.cc
  - https://github.com/eandbsoftware/libraryCPP/blob/master/%23WaveletMatrix.cpp
  - https://ferin-tech.hatenablog.com/entry/2019/11/09/yukicoder_No.924_%E7%B4%B2%E6%98%9F
  - https://wiki.kimiyuki.net/wavelet%20matrix
  - https://judge.yosupo.jp/problem/rectangle_sum
- ウェーブレット木
  - https://www.slideshare.net/pfi/ss-15916040
  - https://takeda25.hatenablog.jp/entry/20120804/1344066875
  - https://echizen-tm.hatenadiary.org/entry/20100822/1282489619
  - https://github.com/eandbsoftware/libraryCPP/blob/master/%23WaveletTree.cpp
  - https://jetbead.hatenablog.com/entry/20130202/1359735146
  - https://drive.google.com/file/d/1NQb6ZXrPZuWI0gNBhJUQAvONjGqFxgUX
- 固有値, 固有ベクトル
  - https://ja.wikipedia.org/wiki/%E5%9B%BA%E6%9C%89%E5%80%A4
  - http://www.prefield.com/algorithm/math/eigensystem.html
- ハフニアン (hafnian)
  - https://mathtrain.jp/pfaffian
  - https://en.wikipedia.org/wiki/Hafnian
  - https://github.com/yosupo06/library-checker-problems/issues/467
  - https://judge.yosupo.jp/problem/hafnian_of_matrix


## Verified

https://judge.yosupo.jp/submission/45071
