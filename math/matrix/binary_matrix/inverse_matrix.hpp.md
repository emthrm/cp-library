---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/matrix/binary_matrix/binary_matrix.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9006\u884C\
      \u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/matrix/binary_matrix/binary_matrix.md
    document_title: "\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/inverse_matrix.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\n * @brief \u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\
    \n * @docs docs/math/matrix/binary_matrix/binary_matrix.md\n */\n\n#pragma once\n\
    #include <cassert>\n#include <utility>\n\n#include \"./binary_matrix.hpp\"\n\n\
    template <int N>\nBinaryMatrix<N> inverse_matrix(const BinaryMatrix<N>& a) {\n\
    \  const int n = a.nrow();\n  BinaryMatrix<N> b(n, n << 1, 0);\n  for (int i =\
    \ 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      b[i][j] = a[i][j];\n\
    \    }\n    b[i][n + i] = 1;\n  }\n  for (int col = 0; col < n; ++col) {\n   \
    \ int pivot = -1;\n    for (int row = col; row < n; ++row) {\n      if (b[row][col])\
    \ {\n        pivot = row;\n        break;\n      }\n    }\n    if (pivot == -1)\
    \ return BinaryMatrix<N>(0, 0);\n    std::swap(b[col], b[pivot]);\n    for (int\
    \ row = 0; row < n; ++row) {\n      if (row != col && b[row][col]) b[row] ^= b[col];\n\
    \    }\n  }\n  BinaryMatrix<N> inv(n, n);\n  for (int i = 0; i < n; ++i) {\n \
    \   for (int j = 0; j < n; ++j) {\n      inv[i][j] = b[i][n + j];\n    }\n  }\n\
    \  return inv;\n}\n"
  dependsOn:
  - math/matrix/binary_matrix/binary_matrix.hpp
  isVerificationFile: false
  path: math/matrix/binary_matrix/inverse_matrix.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/matrix/binary_matrix/inverse_matrix.test.cpp
documentation_of: math/matrix/binary_matrix/inverse_matrix.hpp
layout: document
redirect_from:
- /library/math/matrix/binary_matrix/inverse_matrix.hpp
- /library/math/matrix/binary_matrix/inverse_matrix.hpp.html
title: "\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
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
