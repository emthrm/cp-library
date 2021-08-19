---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/convolution/and_convolution.hpp
    title: "\u6DFB\u3048\u5B57 and \u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':warning:'
    path: math/convolution/or_convolution.hpp
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
  bundledCode: "#line 2 \"math/convolution/fast_mobius_transform.hpp\"\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nstd::vector<T> fast_mobius_transform(std::vector<T>\
    \ a, bool adds_superset, const T ID = 0) {\r\n  int n = a.size(), p = 1;\r\n \
    \ while ((1 << p) < n) ++p;\r\n  n = 1 << p;\r\n  a.resize(n, ID);\r\n  if (adds_superset)\
    \ {\r\n    for (int i = 1; i < n; i <<= 1) for (int s = 0; s < n; ++s) {\r\n \
    \     if (s & i) continue;\r\n      a[s] -= a[s | i];\r\n    }\r\n  } else {\r\
    \n    for (int i = 1; i < n; i <<= 1) for (int s = 0; s < n; ++s) {\r\n      if\
    \ (s & i) continue;\r\n      a[s | i] -= a[s];\r\n    }\r\n  }\r\n  return a;\r\
    \n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<T>\
    \ fast_mobius_transform(std::vector<T> a, bool adds_superset, const T ID = 0)\
    \ {\r\n  int n = a.size(), p = 1;\r\n  while ((1 << p) < n) ++p;\r\n  n = 1 <<\
    \ p;\r\n  a.resize(n, ID);\r\n  if (adds_superset) {\r\n    for (int i = 1; i\
    \ < n; i <<= 1) for (int s = 0; s < n; ++s) {\r\n      if (s & i) continue;\r\n\
    \      a[s] -= a[s | i];\r\n    }\r\n  } else {\r\n    for (int i = 1; i < n;\
    \ i <<= 1) for (int s = 0; s < n; ++s) {\r\n      if (s & i) continue;\r\n   \
    \   a[s | i] -= a[s];\r\n    }\r\n  }\r\n  return a;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/fast_mobius_transform.hpp
  requiredBy:
  - math/convolution/and_convolution.hpp
  - math/convolution/or_convolution.hpp
  timestamp: '2021-08-18 00:31:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/convolution/fast_mobius_transform.test.cpp
  - test/math/convolution/and_convolution.test.cpp
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
