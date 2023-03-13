---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/and_convolution.hpp
    title: "\u6DFB\u3048\u5B57 and \u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':warning:'
    path: include/emthrm/math/convolution/or_convolution.hpp
    title: "\u6DFB\u3048\u5B57 or \u3067\u306E\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/convolution/and_convolution.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 and \u3067\u306E\
      \u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: test/math/convolution/fast_mobius_transform.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\
      \u5909\u63DB"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/convolution/fast_mobius_transform.hpp\"\
    \n\n\n\n#include <bit>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <bool\
    \ ADDS_SUPERSET, typename T>\nstd::vector<T> fast_mobius_transform(std::vector<T>\
    \ a, const T id = 0) {\n  const int n = std::bit_ceil(a.size());\n  a.resize(n,\
    \ id);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int s = 0; s < n; ++s) {\n\
    \      if (s & i) continue;\n      if constexpr (ADDS_SUPERSET) {\n        a[s]\
    \ -= a[s | i];\n      } else {\n        a[s | i] -= a[s];\n      }\n    }\n  }\n\
    \  return a;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_CONVOLUTION_FAST_MOBIUS_TRANSFORM_HPP_\n#define EMTHRM_MATH_CONVOLUTION_FAST_MOBIUS_TRANSFORM_HPP_\n\
    \n#include <bit>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <bool ADDS_SUPERSET,\
    \ typename T>\nstd::vector<T> fast_mobius_transform(std::vector<T> a, const T\
    \ id = 0) {\n  const int n = std::bit_ceil(a.size());\n  a.resize(n, id);\n  for\
    \ (int i = 1; i < n; i <<= 1) {\n    for (int s = 0; s < n; ++s) {\n      if (s\
    \ & i) continue;\n      if constexpr (ADDS_SUPERSET) {\n        a[s] -= a[s |\
    \ i];\n      } else {\n        a[s | i] -= a[s];\n      }\n    }\n  }\n  return\
    \ a;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_CONVOLUTION_FAST_MOBIUS_TRANSFORM_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/convolution/fast_mobius_transform.hpp
  requiredBy:
  - include/emthrm/math/convolution/or_convolution.hpp
  - include/emthrm/math/convolution/and_convolution.hpp
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/convolution/and_convolution.test.cpp
  - test/math/convolution/fast_mobius_transform.test.cpp
documentation_of: include/emthrm/math/convolution/fast_mobius_transform.hpp
layout: document
title: "\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (fast Mobius transform)"
---

$f(S) = \sum_{S \subseteq T} (-1)^{\lvert T \setminus S \rvert} g(T)$ または $f(S) = \sum_{T \subseteq S} (-1)^{\lvert S \setminus T \rvert} g(T)$ を高速に求める。

[高速ゼータ変換](fast_zeta_transform.md)の逆変換と考えることができる。


## 時間計算量

$O(N\log{N})$


## 仕様

|名前|戻り値|備考|
|:--|:--|:--|
|`template <bool ADDS_SUPERSET, typename T>`<br>`std::vector<T> fast_mobius_transform(std::vector<T> a, const T id = 0);`|$A$ に高速メビウス変換を行ったもの|`ADDS_SUPERSET` は上位集合に対する変換かを表す。|


## 参考文献

- https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
- https://naoyat.hatenablog.jp/entry/zeta-moebius
- ~~https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform~~


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2446/review/4183902/emthrm/C++14
