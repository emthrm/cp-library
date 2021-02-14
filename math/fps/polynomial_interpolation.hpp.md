---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/fps/multipoint_evaluation.hpp
    title: multipoint evaluation
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/fps/polynomial_interpolation.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u591A\u9805\u5F0F\u88DC\
      \u9593"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/lagrange_interpolation.md
    document_title: "\u591A\u9805\u5F0F\u88DC\u9593"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/fps/polynomial_interpolation.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u591A\u9805\u5F0F\u88DC\u9593\r\n * @docs docs/math/lagrange_interpolation.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <functional>\r\n#include <vector>\r\n#include\
    \ \"multipoint_evaluation.hpp\"\r\n\r\ntemplate <template <typename> class C,\
    \ typename T>\r\nC<T> polynomial_interpolation(const std::vector<T> &x, const\
    \ std::vector<T> &y) {\r\n  MultipointEvaluation<C, T> multieval(x);\r\n  multieval.calc(multieval.node[1].differential());\r\
    \n  int n = x.size();\r\n  std::function<C<T>(int)> calc = [&](int pos) {\r\n\
    \    if (pos >= n) return C<T>{y[pos - n] / multieval.val[pos - n]};\r\n    return\
    \ calc(pos << 1) * multieval.node[(pos << 1) + 1] + calc((pos << 1) + 1) * multieval.node[pos\
    \ << 1];\r\n  };\r\n  return calc(1);\r\n}\r\n"
  dependsOn:
  - math/fps/multipoint_evaluation.hpp
  isVerificationFile: false
  path: math/fps/polynomial_interpolation.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/fps/polynomial_interpolation.test.cpp
documentation_of: math/fps/polynomial_interpolation.hpp
layout: document
redirect_from:
- /library/math/fps/polynomial_interpolation.hpp
- /library/math/fps/polynomial_interpolation.hpp.html
title: "\u591A\u9805\u5F0F\u88DC\u9593"
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

ラグランジュ補間
- https://mathtrain.jp/hokan
- https://tubo28.me/compprog/algorithm/lagrange_interpolation/

多項式補間
- https://github.com/ei1333/library/blob/master/math/fps/polynomial-interpolation.cpp


## ToDo

- スプライン補間 (spline interpolation)
  - https://en.wikipedia.org/wiki/Spline_interpolation
  - https://docs.google.com/presentation/d/1n-RR-AjQN8oq0DkDKBFi9Ccg53HsDUHKtOsC8z7S-To
- ニュートン補間 (Newtonian interpolation)
  - https://ja.wikipedia.org/wiki/%E3%83%8B%E3%83%A5%E3%83%BC%E3%83%88%E3%83%B3%E8%A3%9C%E9%96%93
  - https://twitter.com/noshi91/status/1160191749416898560


## Verified

- [評価版](https://atcoder.jp/contests/arc033/submissions/10088080)
- [評価版2](https://atcoder.jp/contests/arc033/submissions/10510969)
- [多項式補間](https://judge.yosupo.jp/submission/3794)
