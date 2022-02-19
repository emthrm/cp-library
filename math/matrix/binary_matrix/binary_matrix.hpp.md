---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/matrix/binary_matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':heavy_check_mark:'
    path: math/matrix/binary_matrix/inverse_matrix.hpp
    title: "\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':heavy_check_mark:'
    path: math/matrix/binary_matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\
      \u5217\u7248"
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
    _deprecated_at_docs: docs/math/matrix/binary_matrix/binary_matrix.md
    document_title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/binary_matrix.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/**\r\n * @brief \u30D0\u30A4\u30CA\u30EA\u884C\u5217\r\n * @docs docs/math/matrix/binary_matrix/binary_matrix.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <bitset>\r\n#include <string>\r\n#include\
    \ <vector>\r\n\r\ntemplate <int N>\r\nstruct BinaryMatrix {\r\n  explicit BinaryMatrix(const\
    \ int m, const int n = N, const bool def = false)\r\n      : n(n), data(m, std::bitset<N>(std::string(n,\
    \ def ? '1' : '0'))) {}\r\n\r\n  int nrow() const { return data.size(); }\r\n\
    \  int ncol() const { return n; }\r\n\r\n  BinaryMatrix pow(long long exponent)\
    \ const {\r\n    BinaryMatrix res(n, n), tmp = *this;\r\n    for (int i = 0; i\
    \ < n; ++i) {\r\n      res[i].set(i);\r\n    }\r\n    for (; exponent > 0; exponent\
    \ >>= 1) {\r\n      if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n   \
    \ }\r\n    return res;\r\n  }\r\n\r\n  inline const std::bitset<N>& operator[](const\
    \ int i) const { return data[i]; }\r\n  inline std::bitset<N>& operator[](const\
    \ int i) { return data[i]; }\r\n\r\n  BinaryMatrix& operator=(const BinaryMatrix&\
    \ x) = default;\r\n\r\n  BinaryMatrix& operator+=(const BinaryMatrix& x) {\r\n\
    \    const int m = nrow();\r\n    for (int i = 0; i < m; ++i) {\r\n      data[i]\
    \ ^= x[i];\r\n    }\r\n    return *this;\r\n  }\r\n\r\n  BinaryMatrix& operator*=(const\
    \ BinaryMatrix& x) {\r\n    const int m = nrow(), l = x.ncol();\r\n    BinaryMatrix\
    \ t_x(l, n), res(m, l);\r\n    for (int i = 0; i < l; ++i) {\r\n      for (int\
    \ j = 0; j < n; ++j) {\r\n        t_x[i][j] = x[j][i];\r\n      }\r\n    }\r\n\
    \    for (int i = 0; i < m; ++i) {\r\n      for (int j = 0; j < l; ++j) {\r\n\
    \        if ((data[i] & t_x[j]).count() & 1) res[i].set(j);\r\n      }\r\n   \
    \ }\r\n    return *this = res;\r\n  }\r\n\r\n  BinaryMatrix operator+(const BinaryMatrix&\
    \ x) const {\r\n    return BinaryMatrix(*this) += x;\r\n  }\r\n  BinaryMatrix\
    \ operator*(const BinaryMatrix& x) const {\r\n    return BinaryMatrix(*this) *=\
    \ x;\r\n  }\r\n\r\n private:\r\n  int n;\r\n  std::vector<std::bitset<N>> data;\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/binary_matrix/binary_matrix.hpp
  requiredBy:
  - math/matrix/binary_matrix/gauss_jordan.hpp
  - math/matrix/binary_matrix/linear_equation.hpp
  - math/matrix/binary_matrix/inverse_matrix.hpp
  timestamp: '2022-02-17 20:33:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/matrix/binary_matrix/gauss_jordan.test.cpp
  - test/math/matrix/binary_matrix/linear_equation.test.cpp
  - test/math/matrix/binary_matrix/inverse_matrix.test.cpp
documentation_of: math/matrix/binary_matrix/binary_matrix.hpp
layout: document
redirect_from:
- /library/math/matrix/binary_matrix/binary_matrix.hpp
- /library/math/matrix/binary_matrix/binary_matrix.hpp.html
title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
---
# バイナリ行列

有限体 $\mathbb{F}_2$ 上の行列である．


## 使用法

||説明|
|:--:|:--:|
|`BinaryMatrix<N>(m, n = N, def = false)`|初期値 $\mathrm{def}$ の $M \times N$ 型バイナリ行列|
|`nrow()`|$M$|
|`ncol()`|$N$|
|`pow(exponent)`|$A^\mathrm{exponent}$|
|`operator()[i]`|$A$ の $i$ 行目|
|`operator=(x)`|代入|
|`operator+=(x)`<br>`operator+(x)`|加算|
|`operator+=(*)`<br>`operator+(*)`|乗算|

- [ガウス・ジョルダンの消去法](../gauss_jordan.md)

||説明|備考|
|:--:|:--:|:--:|
|`gauss_jordan(&a, 拡大係数行列か? = false)`|行列 $A$ のランク|$A$ は行階段形に変形される．|

- [連立一次方程式](../linear_equation.md)

||説明|備考|
|:--:|:--:|:--:|
|`linear_equation(a, b)`|$A \boldsymbol{x} = \boldsymbol{b}$ を満たす $\boldsymbol{x}$|解なしのときは空配列となる．|

- [逆行列](../inverse_matrix.md)

||説明|備考|
|:--:|:--:|:--:|
|`inverse(a)`|行列 $A$ の逆行列|存在しないときは空行列となる．|


## 参考

- http://drken1215.hatenablog.com/entry/2019/03/20/202800
- https://atcoder.jp/contests/utpc2014/submissions/428573


## Verified

- [行列累乗](https://atcoder.jp/contests/utpc2014/submissions/9308568)
- [ガウス・ジョルダンの消去法](https://yukicoder.me/submissions/414183)
- [連立一次方程式](https://yukicoder.me/submissions/626481)
- [逆行列](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2624/review/4088806/emthrm/C++14)
