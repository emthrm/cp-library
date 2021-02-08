---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/inverse_element/mod_inv_fermat.hpp
    title: "\u9006\u5143 Fermat \u306E\u5C0F\u5B9A\u7406\u7248"
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/linear_congruence.test.cpp
    title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/inverse_element/mod_inv_fermat.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\
    \n#include \"inverse_element/mod_inv_fermat.hpp\"\r\n\r\ntemplate <typename T>\r\
    \nstd::pair<long long, long long> linear_congruence(const std::vector<T> &a, const\
    \ std::vector<T> &b, const std::vector<T> &m) {\r\n  long long x = 0, mod = 1;\r\
    \n  int n = a.size();\r\n  for (int i = 0; i < n; ++i) {\r\n    long long l =\
    \ mod * a[i], r = -x * a[i] + b[i], g = std::__gcd(l, static_cast<long long>(m[i]));\r\
    \n    if (r % g != 0) return {0, -1};\r\n    x += mod * (r / g * mod_inv_fermat(l\
    \ / g, m[i] / g) % (m[i] / g));\r\n    mod *= m[i] / g;\r\n  }\r\n  return {x\
    \ < 0 ? x + mod : x, mod};\r\n}\r\n"
  dependsOn:
  - math/inverse_element/mod_inv_fermat.hpp
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/linear_congruence.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/linear_congruence.test.cpp
documentation_of: math/linear_congruence.hpp
layout: document
title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (linear congruence)"
---

$$A_i x \equiv B_i \pmod{M_i} \ (i = 1, 2,\ldots, N) \text{．}$$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`linear_congruence(a, b, m)`|$mk + x \ (k \in \mathbb{Z}) \text{ s.t. } A_i x \equiv B_i \pmod{M_i}$|存在しない場合は $(0, -1)$ となる．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.261-262


## Verified

https://atcoder.jp/contests/ddcc2019-qual/submissions/9318157
