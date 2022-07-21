---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/convolution/and_convolution.hpp
    title: "\u6DFB\u3048\u5B57 and \u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':warning:'
    path: math/convolution/or_convolution.hpp
    title: "\u6DFB\u3048\u5B57 or \u3067\u306E\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/convolution/and_convolution.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 and \u3067\u306E\
      \u7573\u307F\u8FBC\u307F"
  - icon: ':x:'
    path: test/math/convolution/fast_mobius_transform.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\
      \u5909\u63DB"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/fast_mobius_transform.hpp\"\n#include <vector>\n\
    \ntemplate <typename T>\nstd::vector<T> fast_mobius_transform(std::vector<T> a,\n\
    \                                     const bool adds_superset, const T id = 0)\
    \ {\n  int n = a.size(), p = 1;\n  while ((1 << p) < n) ++p;\n  n = 1 << p;\n\
    \  a.resize(n, id);\n  if (adds_superset) {\n    for (int i = 1; i < n; i <<=\
    \ 1) {\n      for (int s = 0; s < n; ++s) {\n        if (s & i) continue;\n  \
    \      a[s] -= a[s | i];\n      }\n    }\n  } else {\n    for (int i = 1; i <\
    \ n; i <<= 1) {\n      for (int s = 0; s < n; ++s) {\n        if (s & i) continue;\n\
    \        a[s | i] -= a[s];\n      }\n    }\n  }\n  return a;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nstd::vector<T>\
    \ fast_mobius_transform(std::vector<T> a,\n                                  \
    \   const bool adds_superset, const T id = 0) {\n  int n = a.size(), p = 1;\n\
    \  while ((1 << p) < n) ++p;\n  n = 1 << p;\n  a.resize(n, id);\n  if (adds_superset)\
    \ {\n    for (int i = 1; i < n; i <<= 1) {\n      for (int s = 0; s < n; ++s)\
    \ {\n        if (s & i) continue;\n        a[s] -= a[s | i];\n      }\n    }\n\
    \  } else {\n    for (int i = 1; i < n; i <<= 1) {\n      for (int s = 0; s <\
    \ n; ++s) {\n        if (s & i) continue;\n        a[s | i] -= a[s];\n      }\n\
    \    }\n  }\n  return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/fast_mobius_transform.hpp
  requiredBy:
  - math/convolution/or_convolution.hpp
  - math/convolution/and_convolution.hpp
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/convolution/and_convolution.test.cpp
  - test/math/convolution/fast_mobius_transform.test.cpp
documentation_of: math/convolution/fast_mobius_transform.hpp
layout: document
title: "\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (fast Mobius transform)"
---

$f(S) = \sum_{S \subseteq T} (-1)^{\lvert T \setminus S \rvert} g(T)$ または $f(S) = \sum_{T \subseteq S} (-1)^{\lvert S \setminus T \rvert} g(T)$ を高速に求める．

[高速ゼータ変換](fast_zeta_transform.md)の逆変換と考えることができる．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`fast_mobius_transform(a, 上位集合に対するメビウス変換か?, 単位元 = 0)`|$A$ に高速メビウス変換を行ったもの|


## 参考

- https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
- https://naoyat.hatenablog.jp/entry/zeta-moebius
- ~~https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform~~


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2446/review/4183902/emthrm/C++14
