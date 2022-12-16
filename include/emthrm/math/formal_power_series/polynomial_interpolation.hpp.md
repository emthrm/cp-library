---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/multipoint_evaluation.hpp
    title: multipoint evaluation
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/polynomial_interpolation.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u591A\u9805\u5F0F\u88DC\
      \u9593"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/lagrange_interpolation.md
    document_title: "\u591A\u9805\u5F0F\u88DC\u9593"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/formal_power_series/polynomial_interpolation.hpp: line 12:\
    \ unable to process #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u591A\u9805\u5F0F\u88DC\u9593\n * @docs docs/math/lagrange_interpolation.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_POLYNOMIAL_INTERPOLATION_HPP_\n\
    #define EMTHRM_MATH_FORMAL_POWER_SERIES_POLYNOMIAL_INTERPOLATION_HPP_\n\n#include\
    \ <functional>\n#include <vector>\n\n#include \"emthrm/math/formal_power_series/multipoint_evaluation.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <template <typename> class C, typename T>\n\
    C<T> polynomial_interpolation(const std::vector<T>& x,\n                     \
    \         const std::vector<T>& y) {\n  MultipointEvaluation<C, T> m(x);\n  m.build(m.subproduct_tree[1].differential());\n\
    \  const int n = x.size();\n  const std::function<C<T>(int)> f = [&y, &m, n, &f](const\
    \ int node) -> C<T> {\n    return node >= n ? C<T>{y[node - n] / m.f_x[node -\
    \ n]} :\n                       f(node << 1) * m.subproduct_tree[(node << 1) +\
    \ 1]\n                       + f((node << 1) + 1) * m.subproduct_tree[node <<\
    \ 1];\n  };\n  return f(1);\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_POLYNOMIAL_INTERPOLATION_HPP_\n"
  dependsOn:
  - include/emthrm/math/formal_power_series/multipoint_evaluation.hpp
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/polynomial_interpolation.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/polynomial_interpolation.test.cpp
documentation_of: include/emthrm/math/formal_power_series/polynomial_interpolation.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/formal_power_series/polynomial_interpolation.hpp
- /library/include/emthrm/math/formal_power_series/polynomial_interpolation.hpp.html
title: "\u591A\u9805\u5F0F\u88DC\u9593"
---
# ラグランジュ補間 (Lagrange interpolation)

$1 \leq i < j \leq N,\ x_i \neq x_j$ を満たす $(x_i, y_i)$ に対して $f(x_i) = y_i$ を満たす $N - 1$ 次以下の多項式 $f$ を求める．


### ラグランジュの補間多項式 (interpolation polynomial in the Lagrange form)

$$
  f(x) = \sum_{i = 1}^N f(x_i) \prod_{j \neq i} \dfrac{x - x_j}{x_i - x_j} = \sum_{i = 1}^N \dfrac{f(x_i)}{g^{\prime}(x_i)} \prod_{j \neq i} (x - x_j) \text{ where } g(x) = \prod_{i = 1}^N (x - x_i).
$$


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
|`lagrange_interpolation(x, y, t)`|$f(x_i) = y_i$ を満たす $f(t)$|$x_i$ は互いに異なる．|

- 評価版2

||説明|備考|
|:--:|:--:|:--:|
|`lagrange_interpolation(y, t)`|$f(i) = y_i$ を満たす $f(t)$|$t < 0,\ N \leq t$|

- 多項式補間

||説明|
|:--:|:--:|
|`polynomial_interpolation<多項式>(x, y)`|$f(x_i) = y_i$ を満たす $f$|


## 参考

ラグランジュ補間
- https://mathtrain.jp/hokan
- https://tubo28.me/compprog/algorithm/lagrange_interpolation/

多項式補間
- https://github.com/ei1333/library/blob/c5a89ad7cb3855ebb448da00a629504e26adce24/math/fps/polynomial-interpolation.cpp


## TODO

- スプライン補間 (spline interpolation)
  - https://en.wikipedia.org/wiki/Spline_interpolation
  - https://docs.google.com/presentation/d/1n-RR-AjQN8oq0DkDKBFi9Ccg53HsDUHKtOsC8z7S-To
- ニュートン補間 (Newtonian interpolation)
  - https://ja.wikipedia.org/wiki/%E3%83%8B%E3%83%A5%E3%83%BC%E3%83%88%E3%83%B3%E8%A3%9C%E9%96%93
  - https://twitter.com/noshi91/status/1160191749416898560
- shift of sampling points of polynomial
  - https://ei1333.hateblo.jp/entry/2021/07/08/221742
  - https://hly1204.github.io/library/math/formal_power_series/sample_points_shift.hpp
  - https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial


## Verified

- [評価版](https://atcoder.jp/contests/arc033/submissions/10088080)
- [評価版2](https://atcoder.jp/contests/arc033/submissions/10510969)
- [多項式補間](https://judge.yosupo.jp/submission/3794)
