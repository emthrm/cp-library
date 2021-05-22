---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/binary_matrix/binary_matrix.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: math/matrix/binary_matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/binary_matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9023\u7ACB\
      \u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/matrix/binary_matrix/binary_matrix.md
    document_title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\
      \u30EA\u884C\u5217\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/linear_equation.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\r\n * @brief \u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\
    \u30EA\u884C\u5217\u7248\r\n * @docs docs/math/matrix/binary_matrix/binary_matrix.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n#include \"binary_matrix.hpp\"\
    \r\n#include \"gauss_jordan.hpp\"\r\n\r\ntemplate <int Col>\r\nstd::vector<bool>\
    \ linear_equation(const BinaryMatrix<Col> &a, const std::vector<bool> &b) {\r\n\
    \  BinaryMatrix<Col> mat(a.m, a.n + 1);\r\n  for (int i = 0; i < a.m; ++i) {\r\
    \n    for (int j = 0; j < a.n; ++j) mat[i][j] = a[i][j];\r\n    mat[i][a.n] =\
    \ b[i];\r\n  }\r\n  int rank = gauss_jordan(mat, true);\r\n  for (int row = rank;\
    \ row < a.m; ++row) {\r\n    if (mat[row][a.n]) return std::vector<bool>();\r\n\
    \  }\r\n  std::vector<bool> res(a.n, false);\r\n  for (int i = 0, j; i < rank;\
    \ ++i) {\r\n    j = (i == 0 ? mat[i]._Find_first() : mat[i]._Find_next(j));\r\n\
    \    res[j] = mat[i][a.n];\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - math/matrix/binary_matrix/binary_matrix.hpp
  - math/matrix/binary_matrix/gauss_jordan.hpp
  isVerificationFile: false
  path: math/matrix/binary_matrix/linear_equation.hpp
  requiredBy: []
  timestamp: '2021-03-07 03:49:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/matrix/binary_matrix/linear_equation.test.cpp
documentation_of: math/matrix/binary_matrix/linear_equation.hpp
layout: document
redirect_from:
- /library/math/matrix/binary_matrix/linear_equation.hpp
- /library/math/matrix/binary_matrix/linear_equation.hpp.html
title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\u5217\
  \u7248"
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
