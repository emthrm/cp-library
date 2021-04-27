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
  - icon: ':x:'
    path: test/math/matrix/binary_matrix/binary_matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u30D0\u30A4\
      \u30CA\u30EA\u884C\u5217"
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/math/matrix/binary_matrix/binary_matrix.md
    document_title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/binary_matrix.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/**\r\n * @brief \u30D0\u30A4\u30CA\u30EA\u884C\u5217\r\n * @docs docs/math/matrix/binary_matrix/binary_matrix.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <bitset>\r\n#include <vector>\r\n\r\ntemplate\
    \ <int Col = 2500>\r\nstruct BinaryMatrix {\r\n  int m, n;\r\n\r\n  BinaryMatrix(int\
    \ m, int n = Col, bool def = false) : m(m), n(n), dat(m, std::bitset<Col>(0))\
    \ {\r\n    if (def) {\r\n      for (int i = 0; i < m; ++i) for (int j = 0; j <\
    \ n; ++j) dat[i][j] = 1;\r\n    }\r\n  }\r\n\r\n  BinaryMatrix pow(long long exponent)\
    \ const {\r\n    BinaryMatrix tmp = *this, res(n, n);\r\n    for (int i = 0; i\
    \ < n; ++i) res[i][i] = 1;\r\n    while (exponent > 0) {\r\n      if (exponent\
    \ & 1) res *= tmp;\r\n      tmp *= tmp;\r\n      exponent >>= 1;\r\n    }\r\n\
    \    return res;\r\n  }\r\n\r\n  inline const std::bitset<Col> &operator[](const\
    \ int idx) const { return dat[idx]; }\r\n  inline std::bitset<Col> &operator[](const\
    \ int idx) { return dat[idx]; }\r\n\r\n  BinaryMatrix &operator=(const BinaryMatrix\
    \ &x) {\r\n    m = x.m;\r\n    n = x.n;\r\n    dat.resize(m);\r\n    for (int\
    \ i = 0; i < m; ++i) dat[i] = x[i];\r\n    return *this;\r\n  }\r\n\r\n  BinaryMatrix\
    \ &operator+=(const BinaryMatrix &x) {\r\n    for (int i = 0; i < m; ++i) dat[i]\
    \ ^= x[i];\r\n    return *this;\r\n  }\r\n\r\n  BinaryMatrix &operator*=(const\
    \ BinaryMatrix &x) {\r\n    int height = m, width = x.n;\r\n    BinaryMatrix t_x(x.n,\
    \ x.m), res(height, width);\r\n    for (int i = 0; i < x.n; ++i) for (int j =\
    \ 0; j < x.m; ++j) t_x[i][j] = x[j][i];\r\n    for (int i = 0; i < height; ++i)\
    \ for (int j = 0; j < width; ++j) res[i][j] = ((dat[i] & t_x[j]).count() & 1);\r\
    \n    *this = res;\r\n    return *this;\r\n  }\r\n\r\n  BinaryMatrix operator+(const\
    \ BinaryMatrix &x) const { return BinaryMatrix(*this) += x; }\r\n\r\n  BinaryMatrix\
    \ operator*(const BinaryMatrix &x) const { return BinaryMatrix(*this) *= x; }\r\
    \n\r\nprivate:\r\n  std::vector<std::bitset<Col>> dat;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/binary_matrix/binary_matrix.hpp
  requiredBy:
  - math/matrix/binary_matrix/linear_equation.hpp
  - math/matrix/binary_matrix/gauss_jordan.hpp
  - math/matrix/binary_matrix/inverse_matrix.hpp
  timestamp: '2021-03-04 17:06:38+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/matrix/binary_matrix/gauss_jordan.test.cpp
  - test/math/matrix/binary_matrix/linear_equation.test.cpp
  - test/math/matrix/binary_matrix/inverse_matrix.test.cpp
  - test/math/matrix/binary_matrix/binary_matrix.test.cpp
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

||説明|備考|
|:--:|:--:|:--:|
|`BinaryMatrix(m, n = COL, def = false)`|初期値 $\mathrm{def}$ の $M \times N$ 型バイナリ行列|`COL` はコンパイル時定数である．|
|`m`|行の数||
|`n`|列の数||
|`pow(n)`|$A^n$||
|`operator()[idx]`|$A$ の $\mathrm{idx}$ 行目|
|`=`, `+=`, `*=`, `+`, `*`|||

- [ガウス・ジョルダンの消去法](../gauss_jordan.md)

||説明|備考|
|:--:|:--:|:--:|
|`gauss_jordan(mat, 拡大係数行列か? = false)`|行列 $\mathrm{mat}$ のランク|$\mathrm{mat}$ は行階段形に変形される．|

- [連立一次方程式](../linear_equation.md)

||説明|備考|
|:--:|:--:|:--:|
|`linear_equation(a, b)`|$x \text{ s.t. } A \boldsymbol{x} = \boldsymbol{b}$|解なしの場合は空配列となる．|

- [逆行列](../inverse_matrix.md)

||説明|備考|
|:--:|:--:|:--:|
|`inverse(mat)`|行列 $\mathrm{mat}$ の逆行列|存在しない場合は空行列となる．|


## 参考

- http://drken1215.hatenablog.com/entry/2019/03/20/202800
- https://atcoder.jp/contests/utpc2014/submissions/428573


## Verified

- [行列累乗](https://atcoder.jp/contests/utpc2014/submissions/9308568)
- [ガウス・ジョルダンの消去法](https://yukicoder.me/submissions/414183)
- [連立一次方程式](https://yukicoder.me/submissions/626481)
- [逆行列](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2624/review/4088806/emthrm/C++14)