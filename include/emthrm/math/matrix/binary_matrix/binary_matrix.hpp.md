---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/binary_matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss\u2013Jordan elimination) \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp
    title: "\u9006\u884C\u5217 (inverse matrix) \u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      \u7248"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/binary_matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation) \u30D0\u30A4\
      \u30CA\u30EA\u884C\u5217\u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/binary_matrix/gauss_jordan.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u30AC\u30A6\
      \u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5 \u30D0\u30A4\
      \u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9006\u884C\
      \u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/binary_matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9023\u7ACB\
      \u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n\n\n\n#include <bitset>\n#include <string>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\ntemplate <int N>\nstruct BinaryMatrix {\n  explicit BinaryMatrix(const\
    \ int m, const int n = N, const bool def = false)\n      : n(n), data(m, std::bitset<N>(std::string(n,\
    \ def ? '1' : '0'))) {}\n\n  int nrow() const { return data.size(); }\n  int ncol()\
    \ const { return n; }\n\n  BinaryMatrix pow(long long exponent) const {\n    BinaryMatrix\
    \ res(n, n), tmp = *this;\n    for (int i = 0; i < n; ++i) {\n      res[i].set(i);\n\
    \    }\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1) res\
    \ *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  inline const std::bitset<N>&\
    \ operator[](const int i) const { return data[i]; }\n  inline std::bitset<N>&\
    \ operator[](const int i) { return data[i]; }\n\n  BinaryMatrix& operator=(const\
    \ BinaryMatrix& x) = default;\n\n  BinaryMatrix& operator+=(const BinaryMatrix&\
    \ x) {\n    const int m = nrow();\n    for (int i = 0; i < m; ++i) {\n      data[i]\
    \ ^= x[i];\n    }\n    return *this;\n  }\n\n  BinaryMatrix& operator*=(const\
    \ BinaryMatrix& x) {\n    const int m = nrow(), l = x.ncol();\n    BinaryMatrix\
    \ t_x(l, n), res(m, l);\n    for (int i = 0; i < l; ++i) {\n      for (int j =\
    \ 0; j < n; ++j) {\n        t_x[i][j] = x[j][i];\n      }\n    }\n    for (int\
    \ i = 0; i < m; ++i) {\n      for (int j = 0; j < l; ++j) {\n        if ((data[i]\
    \ & t_x[j]).count() & 1) res[i].set(j);\n      }\n    }\n    return *this = res;\n\
    \  }\n\n  BinaryMatrix operator+(const BinaryMatrix& x) const {\n    return BinaryMatrix(*this)\
    \ += x;\n  }\n  BinaryMatrix operator*(const BinaryMatrix& x) const {\n    return\
    \ BinaryMatrix(*this) *= x;\n  }\n\n private:\n  int n;\n  std::vector<std::bitset<N>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_MATRIX_BINARY_MATRIX_BINARY_MATRIX_HPP_\n#define EMTHRM_MATH_MATRIX_BINARY_MATRIX_BINARY_MATRIX_HPP_\n\
    \n#include <bitset>\n#include <string>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\ntemplate <int N>\nstruct BinaryMatrix {\n  explicit BinaryMatrix(const\
    \ int m, const int n = N, const bool def = false)\n      : n(n), data(m, std::bitset<N>(std::string(n,\
    \ def ? '1' : '0'))) {}\n\n  int nrow() const { return data.size(); }\n  int ncol()\
    \ const { return n; }\n\n  BinaryMatrix pow(long long exponent) const {\n    BinaryMatrix\
    \ res(n, n), tmp = *this;\n    for (int i = 0; i < n; ++i) {\n      res[i].set(i);\n\
    \    }\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1) res\
    \ *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  inline const std::bitset<N>&\
    \ operator[](const int i) const { return data[i]; }\n  inline std::bitset<N>&\
    \ operator[](const int i) { return data[i]; }\n\n  BinaryMatrix& operator=(const\
    \ BinaryMatrix& x) = default;\n\n  BinaryMatrix& operator+=(const BinaryMatrix&\
    \ x) {\n    const int m = nrow();\n    for (int i = 0; i < m; ++i) {\n      data[i]\
    \ ^= x[i];\n    }\n    return *this;\n  }\n\n  BinaryMatrix& operator*=(const\
    \ BinaryMatrix& x) {\n    const int m = nrow(), l = x.ncol();\n    BinaryMatrix\
    \ t_x(l, n), res(m, l);\n    for (int i = 0; i < l; ++i) {\n      for (int j =\
    \ 0; j < n; ++j) {\n        t_x[i][j] = x[j][i];\n      }\n    }\n    for (int\
    \ i = 0; i < m; ++i) {\n      for (int j = 0; j < l; ++j) {\n        if ((data[i]\
    \ & t_x[j]).count() & 1) res[i].set(j);\n      }\n    }\n    return *this = res;\n\
    \  }\n\n  BinaryMatrix operator+(const BinaryMatrix& x) const {\n    return BinaryMatrix(*this)\
    \ += x;\n  }\n  BinaryMatrix operator*(const BinaryMatrix& x) const {\n    return\
    \ BinaryMatrix(*this) *= x;\n  }\n\n private:\n  int n;\n  std::vector<std::bitset<N>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MATRIX_BINARY_MATRIX_BINARY_MATRIX_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
  requiredBy:
  - include/emthrm/math/matrix/binary_matrix/linear_equation.hpp
  - include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp
  - include/emthrm/math/matrix/binary_matrix/gauss_jordan.hpp
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/matrix/binary_matrix/linear_equation.test.cpp
  - test/math/matrix/binary_matrix/gauss_jordan.test.cpp
  - test/math/matrix/binary_matrix/inverse_matrix.test.cpp
documentation_of: include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
layout: document
title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
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