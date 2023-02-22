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
  bundledCode: "#line 1 \"include/emthrm/math/lagrange_interpolation.hpp\"\n/**\n\
    \ * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u7248\
    \n * @docs docs/math/lagrange_interpolation.md\n */\n\n#ifndef EMTHRM_MATH_LAGRANGE_INTERPOLATION_HPP_\n\
    #define EMTHRM_MATH_LAGRANGE_INTERPOLATION_HPP_\n\n#include <algorithm>\n#if __cplusplus\
    \ >= 201703L\n# include <functional>\n#endif  // __cplusplus >= 201703L\n#include\
    \ <iterator>\n#if __cplusplus >= 201703L\n# include <numeric>\n#endif  // __cplusplus\
    \ >= 201703L\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\n\
    T lagrange_interpolation(const std::vector<T>& x, const std::vector<T>& y,\n \
    \                        const T t) {\n  const auto it = std::find(x.begin(),\
    \ x.end(), t);\n  if (it != x.end()) return y[std::distance(x.begin(), it)];\n\
    \  const int n = x.size();\n  T res = 0;\n  for (int i = 0; i < n; ++i) {\n  \
    \  T den = t - x[i];\n    for (int j = 0; j < n; ++j) {\n      if (j != i) den\
    \ *= x[i] - x[j];\n    }\n    res += y[i] / den;\n  }\n#if __cplusplus >= 201703L\n\
    \  return std::transform_reduce(\n      x.begin(), x.end(), res, std::multiplies<T>(),\n\
    \      [t](const T& x_i) -> T { return t - x_i; })\n#else\n  for (int i = 0; i\
    \ < n; ++i) {\n    res *= t - x[i];\n  }\n  return res;\n#endif  // __cplusplus\
    \ >= 201703L\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_LAGRANGE_INTERPOLATION_HPP_\n"
  code: "/**\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\
    \u7248\n * @docs docs/math/lagrange_interpolation.md\n */\n\n#ifndef EMTHRM_MATH_LAGRANGE_INTERPOLATION_HPP_\n\
    #define EMTHRM_MATH_LAGRANGE_INTERPOLATION_HPP_\n\n#include <algorithm>\n#if __cplusplus\
    \ >= 201703L\n# include <functional>\n#endif  // __cplusplus >= 201703L\n#include\
    \ <iterator>\n#if __cplusplus >= 201703L\n# include <numeric>\n#endif  // __cplusplus\
    \ >= 201703L\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\n\
    T lagrange_interpolation(const std::vector<T>& x, const std::vector<T>& y,\n \
    \                        const T t) {\n  const auto it = std::find(x.begin(),\
    \ x.end(), t);\n  if (it != x.end()) return y[std::distance(x.begin(), it)];\n\
    \  const int n = x.size();\n  T res = 0;\n  for (int i = 0; i < n; ++i) {\n  \
    \  T den = t - x[i];\n    for (int j = 0; j < n; ++j) {\n      if (j != i) den\
    \ *= x[i] - x[j];\n    }\n    res += y[i] / den;\n  }\n#if __cplusplus >= 201703L\n\
    \  return std::transform_reduce(\n      x.begin(), x.end(), res, std::multiplies<T>(),\n\
    \      [t](const T& x_i) -> T { return t - x_i; })\n#else\n  for (int i = 0; i\
    \ < n; ++i) {\n    res *= t - x[i];\n  }\n  return res;\n#endif  // __cplusplus\
    \ >= 201703L\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_LAGRANGE_INTERPOLATION_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2023-02-21 03:04:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/lagrange_interpolation.test.cpp
documentation_of: include/emthrm/math/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/lagrange_interpolation.hpp
- /library/include/emthrm/math/lagrange_interpolation.hpp.html
title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u7248"
---
# ラグランジュ補間 (Lagrange interpolation)

$1 \leq i < j \leq N,\ x_i \neq x_j$ を満たす $(x_i, y_i)$ に対して $f(x_i) = y_i$ を満たす $N - 1$ 次以下の多項式 $f$ を求める。


### ラグランジュの補間多項式 (interpolation polynomial in the Lagrange form)

$$
  f(x) = \sum_{i = 1}^N f(x_i) \prod_{j \neq i} \dfrac{x - x_j}{x_i - x_j} = \sum_{i = 1}^N \dfrac{f(x_i)}{g^{\prime}(x_i)} \prod_{j \neq i} (x - x_j) \text{ where } g(x) = \prod_{i = 1}^N (x - x_i).
$$


## 時間計算量

||時間計算量|
|:--|:--|
|評価版|$O(N^2)$|
|評価版2|$O(N)$|
|多項式補間|$O(N(\log{N})^2)$|


## 仕様

### 評価版

|名前|戻り値|要件|
|:--|:--|:--|
|`template <typename T>`<br>`T lagrange_interpolation(const std::vector<T>& x, const std::vector<T>& y, const T t);`|$f(x_i) = y_i$ を満たす $f(t)$|$x_i$ は互いに異なる。|
|`template <typename T>`<br>`T lagrange_interpolation(const std::vector<T>& y, const T t);`|$f(i) = y_i$ を満たす $f(t)$|$t < 0,\ N \leq t$|


### 多項式補間

|名前|戻り値|備考|
|:--|:--|:--|
|`template <template <typename> class C, typename T>`<br>`C<T> polynomial_interpolation(const std::vector<T>& x, const std::vector<T>& y);`|$f(x_i) = y_i$ を満たす $f$|`C` は冪級数を表す構造体である。|


## 参考文献

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


## Submissons

- [評価版](https://atcoder.jp/contests/arc033/submissions/10088080)
- [評価版2](https://atcoder.jp/contests/arc033/submissions/10510969)
- [多項式補間](https://judge.yosupo.jp/submission/3794)
