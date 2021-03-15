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
  - icon: ':x:'
    path: test/math/convolution/fzt.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\
      \u63DB"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/fzt.hpp\"\n#include <vector>\r\n\r\ntemplate\
    \ <typename Ring, typename Fn>\r\nstd::vector<Ring> fzt(std::vector<Ring> a,\r\
    \n                      bool is_superset,\r\n                      const Ring\
    \ ID = 0,\r\n                      Fn fn = [](const Ring &a, const Ring &b) ->\
    \ Ring { return a + b; }) {\r\n  int n = a.size(), p = 1;\r\n  while ((1 << p)\
    \ < n) ++p;\r\n  n = 1 << p;\r\n  a.resize(n, ID);\r\n  if (is_superset) {\r\n\
    \    for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {\r\n      if\
    \ ((j & i) == 0) a[j] = fn(a[j], a[j | i]);\r\n    }\r\n  } else {\r\n    for\
    \ (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {\r\n      if ((j &\
    \ i) == 0) a[j | i] = fn(a[j | i], a[j]);\r\n    }\r\n  }\r\n  return a;\r\n}\r\
    \n"
  code: "#pragma once\r\n#include <vector>\r\n\r\ntemplate <typename Ring, typename\
    \ Fn>\r\nstd::vector<Ring> fzt(std::vector<Ring> a,\r\n                      bool\
    \ is_superset,\r\n                      const Ring ID = 0,\r\n               \
    \       Fn fn = [](const Ring &a, const Ring &b) -> Ring { return a + b; }) {\r\
    \n  int n = a.size(), p = 1;\r\n  while ((1 << p) < n) ++p;\r\n  n = 1 << p;\r\
    \n  a.resize(n, ID);\r\n  if (is_superset) {\r\n    for (int i = 1; i < n; i <<=\
    \ 1) for (int j = 0; j < n; ++j) {\r\n      if ((j & i) == 0) a[j] = fn(a[j],\
    \ a[j | i]);\r\n    }\r\n  } else {\r\n    for (int i = 1; i < n; i <<= 1) for\
    \ (int j = 0; j < n; ++j) {\r\n      if ((j & i) == 0) a[j | i] = fn(a[j | i],\
    \ a[j]);\r\n    }\r\n  }\r\n  return a;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/fzt.hpp
  requiredBy:
  - math/convolution/and_convolution.hpp
  - math/convolution/or_convolution.hpp
  timestamp: '2021-02-13 04:45:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/convolution/fzt.test.cpp
  - test/math/convolution/and_convolution.test.cpp
documentation_of: math/convolution/fzt.hpp
layout: document
title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB (fast zeta transform)"
---

$g(S) = \sum_{S \subseteq T} f(T)$ または $g(S) = \sum_{T \subseteq S} f(T)$ を高速に求める．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`fzt(a, 上位集合に対する FZT か?, 単位元 = 0, 二項演算 = +)`|$A$ に高速ゼータ変換を行ったもの|


## 参考

- http://topcoder.g.hatena.ne.jp/iwiwi/20120422/1335065228
- https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
- https://todo314.hatenadiary.org/entry/20120614/1339695202
- http://compro.tsutajiro.com/archive/181015_incexc.pdf
- http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#qef794e9
- https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform


## Verified

https://atcoder.jp/contests/arc100/submissions/10208329
