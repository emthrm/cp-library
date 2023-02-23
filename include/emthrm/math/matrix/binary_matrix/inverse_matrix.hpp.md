---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9006\u884C\
      \u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/matrix/binary_matrix/binary_matrix.md
    document_title: "\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp: line 12: unable\
    \ to process #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\
    \n * @docs docs/math/matrix/binary_matrix/binary_matrix.md\n */\n\n#ifndef EMTHRM_MATH_MATRIX_BINARY_MATRIX_INVERSE_MATRIX_HPP_\n\
    #define EMTHRM_MATH_MATRIX_BINARY_MATRIX_INVERSE_MATRIX_HPP_\n\n#include <cassert>\n\
    #include <utility>\n\n#include \"emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int N>\nBinaryMatrix<N> inverse_matrix(const\
    \ BinaryMatrix<N>& a) {\n  const int n = a.nrow();\n  BinaryMatrix<N> b(n, n <<\
    \ 1, 0);\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n\
    \      b[i][j] = a[i][j];\n    }\n    b[i][n + i] = 1;\n  }\n  for (int col =\
    \ 0; col < n; ++col) {\n    int pivot = -1;\n    for (int row = col; row < n;\
    \ ++row) {\n      if (b[row][col]) {\n        pivot = row;\n        break;\n \
    \     }\n    }\n    if (pivot == -1) return BinaryMatrix<N>(0, 0);\n    std::swap(b[col],\
    \ b[pivot]);\n    for (int row = 0; row < n; ++row) {\n      if (row != col &&\
    \ b[row][col]) b[row] ^= b[col];\n    }\n  }\n  BinaryMatrix<N> inv(n, n);\n \
    \ for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      inv[i][j]\
    \ = b[i][n + j];\n    }\n  }\n  return inv;\n}\n\n}  // namespace emthrm\n\n#endif\
    \  // EMTHRM_MATH_MATRIX_BINARY_MATRIX_INVERSE_MATRIX_HPP_\n"
  dependsOn:
  - include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
  isVerificationFile: false
  path: include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/matrix/binary_matrix/inverse_matrix.test.cpp
documentation_of: include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp
- /library/include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp.html
title: "\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
---
# バイナリ行列

有限体 $\mathbb{F}_2$ 上の行列である。


## 仕様

```cpp
template <int N>
struct BinaryMatrix;
```

- `N`：列数の最大値

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit BinaryMatrix(const int m, const int n = N, const bool def = false);`|初期値 $\mathrm{def}$ の $M \times N$ 型バイナリ行列を表すオブジェクトを構築する。|
|`int nrow() const;`|$M$|
|`int ncol() const;`|$N$|
|`BinaryMatrix pow(long long exponent) const;`|$A^\mathrm{exponent}$|
|`inline const std::bitset<N>& operator[](const int i) const`<br>`inline std::bitset<N>& operator[](const int i);`|$A$ の $i$ 行目|
|`BinaryMatrix& operator=(const BinaryMatrix& x);`|代入演算子|
|`BinaryMatrix& operator+=(const BinaryMatrix& x);`<br>`BinaryMatrix operator+(const BinaryMatrix& x) const;`|加算|
|`BinaryMatrix& operator*=(const BinaryMatrix& x);`<br>`BinaryMatrix operator*(const BinaryMatrix& x) const;`|乗算|


### [ガウス・ジョルダンの消去法](../gauss_jordan.md)

|名前|戻り値|備考|
|:--|:--|:--|
|`template <bool IS_EXTENDED = false, int N>`<br>`int gauss_jordan(BinaryMatrix<N>* a);`|行列 $A$ のランク|`is_extended` は $A$ が拡大係数行列かを表す。<br>$A$ は行階段形に変形される。|


### [連立一次方程式](../linear_equation.md)

|名前|戻り値|
|:--|:--|
|`template <int N>`<br>`std::vector<bool> linear_equation(const BinaryMatrix<N>& a, const std::vector<bool>& b);`|$A \boldsymbol{x} = \boldsymbol{b}$ を満たす $\boldsymbol{x}$。ただし解なしのときは空配列を返す。|


### [逆行列](../inverse_matrix.md)

|名前|戻り値|
|:--|:--|
|`template <int N>`<br>`BinaryMatrix<N> inverse_matrix(const BinaryMatrix<N>& a);`|行列 $A$ の逆行列。ただし存在しないときは空行列を返す。|


## 参考文献

- http://drken1215.hatenablog.com/entry/2019/03/20/202800
- https://atcoder.jp/contests/utpc2014/submissions/428573


## Submissons

- [行列累乗](https://atcoder.jp/contests/utpc2014/submissions/9308568)
- [ガウス・ジョルダンの消去法](https://yukicoder.me/submissions/414183)
- [連立一次方程式](https://yukicoder.me/submissions/626481)
- [逆行列](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2624/review/4088806/emthrm/C++14)
