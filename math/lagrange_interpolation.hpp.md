---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/lagrange_interpolation.test.cpp
    title: "\u6570\u5B66/\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\
      \u7248"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/lagrange_interpolation.md
    document_title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\
      \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/lagrange_interpolation.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\
    \u7248\r\n * @docs docs/math/lagrange_interpolation.md\r\n */\r\n\r\n#pragma once\r\
    \n#include <algorithm>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nT\
    \ lagrange_interpolation(const std::vector<T> &x, const std::vector<T> &y, T t)\
    \ {\r\n  auto it = std::find(x.begin(), x.end(), t);\r\n  if (it != x.end()) return\
    \ y[it - x.begin()];\r\n  int n = x.size();\r\n  T res = 0;\r\n  for (int i =\
    \ 0; i < n; ++i) {\r\n    T den = t - x[i];\r\n    for (int j = 0; j < n; ++j)\
    \ {\r\n      if (j != i) den *= x[i] - x[j];\r\n    }\r\n    res += y[i] / den;\r\
    \n  }\r\n  for (int i = 0; i < n; ++i) res *= t - x[i];\r\n  return res;\r\n}\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/lagrange_interpolation.test.cpp
documentation_of: math/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/math/lagrange_interpolation.hpp
- /library/math/lagrange_interpolation.hpp.html
title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u7248"
---
# ラグランジュ補間 (Lagrange interpolation)

$x_i \neq x_j \ (1 \leq i < j \leq N)$ を満たす $(x_i, y_i)$ について $f(x_i) = y_i$ を満たす $N - 1$ 次以下の多項式 $f$ を求める．


### ラグランジュの補間多項式 (interpolation polynomial in the Lagrange form)

$$f(x) = \sum_{i = 1}^N f(x_i) \prod_{j \neq i} \dfrac{x - x_j}{x_i - x_j} = \sum_{i = 1}^N \dfrac{f(x_i)}{g^{\prime}(x_i)} \prod_{j \neq i} (x - x_j) \text{ where } g(x) = \prod_{i = 1}^N (x - x_i). \\ \left( \because g^{\prime}(x) = \sum_{i = 1}^N \prod_{j \neq i} (x - x_j) \text{ より } g^{\prime}(x_i) = \prod_{j \neq i} (x - x_j)\text{．}\right)$$


## 時間計算量

||時間計算量|
|:--:|:--:|
|評価版|$O(N^2)$|
|評価版2|$O(N)$|
|多項式補間|$O(N(\log{N})^2)$|


## 使用法

- 評価版

||説明|備考|
|:--:|:--:|:--:|
|`lagrange_interpolation(x, y, t)`|$f(t) \text{ s.t. } f(x_i) = y_i$|$x$ は互いに異なる．|

- 評価版2

||説明|備考|
|:--:|:--:|:--:|
|`lagrange_interpolation(y, t)`|$f(t) \text{ s.t. } f(i) = y_i$|$t < 0,\ N \leq t$|

- 多項式補間

||説明|
|:--:|:--:|
|`polynomial_interpolation<多項式>(x, y)`|$f \text{ s.t. } f(x_i) = y_i$|


## 参考

- ラグランジュ補間
  - https://mathtrain.jp/hokan
  - https://tubo28.me/compprog/algorithm/lagrange_interpolation/
- スプライン補間 (spline interpolation)
  - https://en.wikipedia.org/wiki/Spline_interpolation
  - https://docs.google.com/presentation/d/1n-RR-AjQN8oq0DkDKBFi9Ccg53HsDUHKtOsC8z7S-To
- 多項式補間
  - https://github.com/ei1333/library/blob/master/math/fps/polynomial-interpolation.cpp


## ToDo

- ニュートン補間 (Newtonian interpolation)
  - https://ja.wikipedia.org/wiki/%E3%83%8B%E3%83%A5%E3%83%BC%E3%83%88%E3%83%B3%E8%A3%9C%E9%96%93
  - https://twitter.com/noshi91/status/1160191749416898560


## Verified

- [評価版](https://atcoder.jp/contests/arc033/submissions/10088080)
- [評価版2](https://atcoder.jp/contests/arc033/submissions/10510969)
- [多項式補間](https://judge.yosupo.jp/submission/3794)
