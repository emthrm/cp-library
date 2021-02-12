---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/binary_matrix/binary_matrix.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/inverse_matrix.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\r\n * @brief \u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\
    \r\n * @docs docs/math/matrix/binary_matrix/binary_matrix.md\r\n */\r\n\r\n#pragma\
    \ once\r\n#include <cassert>\r\n#include <utility>\r\n#include \"binary_matrix.hpp\"\
    \r\n\r\ntemplate <int COL>\r\nbool inverse(const BinaryMatrix<COL> &mat, BinaryMatrix<COL>\
    \ &inv) {\r\n  int n = mat.n;\r\n  BinaryMatrix<COL> gauss_jordan(n, n << 1, 0);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    for (int j = 0; j < n; ++j) gauss_jordan[i][j]\
    \ = mat[i][j];\r\n    gauss_jordan[i][n + i] = 1;\r\n  }\r\n  for (int col = 0;\
    \ col < n; ++col) {\r\n    int pivot = -1;\r\n    for (int row = col; row < n;\
    \ ++row) {\r\n      if (gauss_jordan[row][col]) {\r\n        pivot = row;\r\n\
    \        break;\r\n      }\r\n    }\r\n    if (pivot == -1) return false;\r\n\
    \    std::swap(gauss_jordan[col], gauss_jordan[pivot]);\r\n    for (int row =\
    \ 0; row < n; ++row) {\r\n      if (row != col && gauss_jordan[row][col]) gauss_jordan[row]\
    \ ^= gauss_jordan[col];\r\n    }\r\n  }\r\n  assert(inv.n == n && inv.m == n);\r\
    \n  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) inv[i][j] = gauss_jordan[i][n\
    \ + j];\r\n  return true;\r\n}\r\n"
  dependsOn:
  - math/matrix/binary_matrix/binary_matrix.hpp
  isVerificationFile: false
  path: math/matrix/binary_matrix/inverse_matrix.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
|`inverse(mat, inv)`|行列 $\mathrm{mat}$ の逆行列が存在するか．|$\mathrm{inv}$ に逆行列が格納される．|


## 参考

- http://drken1215.hatenablog.com/entry/2019/03/20/202800
- https://atcoder.jp/contests/utpc2014/submissions/428573


## Verified

- [行列累乗](https://atcoder.jp/contests/utpc2014/submissions/9308568)
- [ガウス・ジョルダンの消去法](https://yukicoder.me/submissions/414183)
- [連立一次方程式](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1308/review/4088796/emthrm/C++14)
- [逆行列](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2624/review/4088806/emthrm/C++14)
