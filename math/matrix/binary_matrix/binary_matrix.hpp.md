---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/matrix/binary_matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':x:'
    path: math/matrix/binary_matrix/inverse_matrix.hpp
    title: "\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':x:'
    path: math/matrix/binary_matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\
      \u5217\u7248"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/matrix/binary_matrix/gauss_jordan.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u30AC\u30A6\
      \u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5 \u30D0\u30A4\
      \u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':x:'
    path: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9006\u884C\
      \u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  - icon: ':x:'
    path: test/math/matrix/binary_matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9023\u7ACB\
      \u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/matrix/binary_matrix/binary_matrix.md
    document_title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/binary_matrix.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/**\n * @brief \u30D0\u30A4\u30CA\u30EA\u884C\u5217\n * @docs docs/math/matrix/binary_matrix/binary_matrix.md\n\
    \ */\n\n#pragma once\n#include <bitset>\n#include <string>\n#include <vector>\n\
    \ntemplate <int N>\nstruct BinaryMatrix {\n  explicit BinaryMatrix(const int m,\
    \ const int n = N, const bool def = false)\n      : n(n), data(m, std::bitset<N>(std::string(n,\
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
    \ data;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/binary_matrix/binary_matrix.hpp
  requiredBy:
  - math/matrix/binary_matrix/inverse_matrix.hpp
  - math/matrix/binary_matrix/linear_equation.hpp
  - math/matrix/binary_matrix/gauss_jordan.hpp
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/matrix/binary_matrix/inverse_matrix.test.cpp
  - test/math/matrix/binary_matrix/gauss_jordan.test.cpp
  - test/math/matrix/binary_matrix/linear_equation.test.cpp
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
