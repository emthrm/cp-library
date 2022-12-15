---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: include/emthrm/math/convolution/and_convolution.hpp
    title: "\u6DFB\u3048\u5B57 and \u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':warning:'
    path: include/emthrm/math/convolution/or_convolution.hpp
    title: "\u6DFB\u3048\u5B57 or \u3067\u306E\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/convolution/and_convolution.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 and \u3067\u306E\
      \u7573\u307F\u8FBC\u307F"
  - icon: ':x:'
    path: test/math/convolution/fast_zeta_transform.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\
      \u63DB"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/convolution/fast_zeta_transform.hpp\"\
    \n\n\n\n#include <functional>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate\
    \ <typename Ring>\nstd::vector<Ring> fast_zeta_transform(\n    std::vector<Ring>\
    \ a, const bool adds_superset, const Ring ID = 0,\n    const std::function<Ring(const\
    \ Ring&, const Ring&)> fn =\n        [](const Ring& a, const Ring& b) -> Ring\
    \ { return a + b; }) {\n  int n = a.size(), p = 1;\n  while ((1 << p) < n) ++p;\n\
    \  n = 1 << p;\n  a.resize(n, ID);\n  if (adds_superset) {\n    for (int i = 1;\
    \ i < n; i <<= 1) {\n      for (int s = 0; s < n; ++s) {\n        if (s & i) continue;\n\
    \        a[s] = fn(a[s], a[s | i]);\n      }\n    }\n  } else {\n    for (int\
    \ i = 1; i < n; i <<= 1) {\n      for (int s = 0; s < n; ++s) {\n        if (s\
    \ & i) continue;\n        a[s | i] = fn(a[s | i], a[s]);\n      }\n    }\n  }\n\
    \  return a;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_CONVOLUTION_FAST_ZETA_TRANSFORM_HPP_\n#define EMTHRM_MATH_CONVOLUTION_FAST_ZETA_TRANSFORM_HPP_\n\
    \n#include <functional>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ Ring>\nstd::vector<Ring> fast_zeta_transform(\n    std::vector<Ring> a, const\
    \ bool adds_superset, const Ring ID = 0,\n    const std::function<Ring(const Ring&,\
    \ const Ring&)> fn =\n        [](const Ring& a, const Ring& b) -> Ring { return\
    \ a + b; }) {\n  int n = a.size(), p = 1;\n  while ((1 << p) < n) ++p;\n  n =\
    \ 1 << p;\n  a.resize(n, ID);\n  if (adds_superset) {\n    for (int i = 1; i <\
    \ n; i <<= 1) {\n      for (int s = 0; s < n; ++s) {\n        if (s & i) continue;\n\
    \        a[s] = fn(a[s], a[s | i]);\n      }\n    }\n  } else {\n    for (int\
    \ i = 1; i < n; i <<= 1) {\n      for (int s = 0; s < n; ++s) {\n        if (s\
    \ & i) continue;\n        a[s | i] = fn(a[s | i], a[s]);\n      }\n    }\n  }\n\
    \  return a;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_CONVOLUTION_FAST_ZETA_TRANSFORM_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/convolution/fast_zeta_transform.hpp
  requiredBy:
  - include/emthrm/math/convolution/or_convolution.hpp
  - include/emthrm/math/convolution/and_convolution.hpp
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/convolution/fast_zeta_transform.test.cpp
  - test/math/convolution/and_convolution.test.cpp
documentation_of: include/emthrm/math/convolution/fast_zeta_transform.hpp
layout: document
title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB (fast zeta transform)"
---

$g(S) = \sum_{S \subseteq T} f(T)$ または $g(S) = \sum_{T \subseteq S} f(T)$ を高速に求める．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`fast_zeta_transform(a, 上位集合に対するゼータ変換か?, 単位元 = 0, 二項演算 = 加法)`|$A$ に高速ゼータ変換を行ったもの|


## 参考

- https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
- https://naoyat.hatenablog.jp/entry/zeta-moebius
- https://todo314.hatenadiary.org/entry/20120614/1339695202
- http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#qef794e9
- ~~https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform~~


## Verified

https://atcoder.jp/contests/arc100/submissions/10208329
