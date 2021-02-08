---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext_gcd.hpp
    title: "\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5 (extended Euclidean algorithm)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/crt.test.cpp
    title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/crt.hpp\"\n#include <algorithm>\r\n#include <utility>\r\
    \n#include <vector>\r\n#line 2 \"math/ext_gcd.hpp\"\n#include <tuple>\r\n#line\
    \ 4 \"math/ext_gcd.hpp\"\n\r\ntemplate <typename T>\r\nstd::pair<T, T> ext_gcd(T\
    \ a, T b) {\r\n  if (b == 0) return {1, 0};\r\n  T fst, snd; std::tie(fst, snd)\
    \ = ext_gcd(b, a % b);\r\n  return {snd, fst - a / b * snd};\r\n}\r\n#line 6 \"\
    math/crt.hpp\"\n\r\ntemplate <typename T>\r\nstd::pair<T, T> crt(const std::vector<T>\
    \ &b, const std::vector<T> &m) {\r\n  T x = 0, md = 1;\r\n  int n = b.size();\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    T g = std::__gcd(md, m[i]);\r\n    if\
    \ ((b[i] - x) % g != 0) return {0, -1};\r\n    x += md * ((b[i] - x) / g * ext_gcd(md,\
    \ m[i]).first % (m[i] / g));\r\n    md *= m[i] / g;\r\n  }\r\n  return {x < 0\
    \ ? x + md : x, md};\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\
    \n#include \"ext_gcd.hpp\"\r\n\r\ntemplate <typename T>\r\nstd::pair<T, T> crt(const\
    \ std::vector<T> &b, const std::vector<T> &m) {\r\n  T x = 0, md = 1;\r\n  int\
    \ n = b.size();\r\n  for (int i = 0; i < n; ++i) {\r\n    T g = std::__gcd(md,\
    \ m[i]);\r\n    if ((b[i] - x) % g != 0) return {0, -1};\r\n    x += md * ((b[i]\
    \ - x) / g * ext_gcd(md, m[i]).first % (m[i] / g));\r\n    md *= m[i] / g;\r\n\
    \  }\r\n  return {x < 0 ? x + md : x, md};\r\n}\r\n"
  dependsOn:
  - math/ext_gcd.hpp
  isVerificationFile: false
  path: math/crt.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/crt.test.cpp
documentation_of: math/crt.hpp
layout: document
title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
---

連立合同式

$$x \equiv b_i \pmod{m_i} \ (i = 1, 2,\ldots, k)$$

について

$$b_i \equiv b_j \pmod{\gcd(m_i, m_j)} \ (1 \leq \forall i, j \leq k)$$

が成り立つならば連立合同式を満たす

$$x \equiv r \pmod{\mathrm{lcm}(m_1, m_2,..., m_k)}$$

が一意に存在する．


## 時間計算量

$\mathrm{lcm}(m_1, m_2,..., m_k) = \mathrm{lcm}(M)$ とおくと $O(N \log{\mathrm{lcm}(M)})$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`crt(b, m)`|$x \equiv r \pmod{\mathrm{lcm}(m_1,...)} \text{ s.t. } x \equiv b_i \pmod{m_i}$|存在しない場合は $(0, -1)$ となる．|


## 参考

- https://qiita.com/drken/items/ae02240cd1f8edfc86fd
- https://mathtrain.jp/remainder


## ToDo

- Garner のアルゴリズム
  - https://qiita.com/drken/items/ae02240cd1f8edfc86fd
  - https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/garner.cpp
  - https://www.creativ.xyz/ect-gcd-crt-garner-927/
  - http://kirika-comp.hatenablog.com/entry/2017/12/18/143923
  - http://sugarknri.hatenablog.com/entry/2018/06/28/144407
  - https://lumakernel.github.io/ecasdqina/math/number-theory/Garner
  - https://cp-algorithms.com/algebra/chinese-remainder-theorem.html
  - http://flex.phys.tohoku.ac.jp/~maru/implementations/garner.php
- Lucas の定理 (Lucas's theorem)
  - https://en.wikipedia.org/wiki/Lucas%27s_theorem
  - https://mathtrain.jp/lucastheorem
  - http://spinda2.blog48.fc2.com/blog-entry-399.html
  - https://ferin-tech.hatenablog.com/entry/2018/01/17/010829


## Verified

https://yukicoder.me/submissions/444959
