---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/inverse_element/inverse_element.md
    document_title: "\u9006\u5143\u306E\u6570\u8868"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/inverse_element/inv_init.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u9006\u5143\u306E\u6570\u8868\r\n * @docs docs/math/inverse_element/inverse_element.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n\r\nstd::vector<long long> inv_init(int\
    \ val, int mod) {\r\n  std::vector<long long> inv(val + 1, 0);\r\n  inv[1] = 1;\r\
    \n  for (int i = 2; i <= val; ++i) {\r\n    inv[i] = mod - inv[mod % i] * (mod\
    \ / i) % mod;\r\n    if (inv[i] == mod) inv[i] = 0;\r\n  }\r\n  return inv;\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/inverse_element/inv_init.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/inverse_element/inv_init.hpp
layout: document
redirect_from:
- /library/math/inverse_element/inv_init.hpp
- /library/math/inverse_element/inv_init.hpp.html
title: "\u9006\u5143\u306E\u6570\u8868"
---
# 逆元 (inverse element)

$ax \equiv 1 \pmod{m}$ を満たす $x = a^{-1}$．


## 時間計算量

||時間計算量|
|:--:|:--:|
|拡張 Euclid の互除法版|$O(\log{M})$|
|拡張 Euclid の互除法版2|$O(\log{M})$|
|Fermat の小定理版|$O(\log{M})$|
|オイラーの定理版|$O(\sqrt{M})$|
|数表|$O(N)$|


## 使用法

- 拡張 Euclid の互除法版

||説明|備考|
|:--:|:--:|:--:|
|`mod_inv_extgcd(a, mod)`|$a$ の逆元|存在しない場合は $-1$ となる．|

- 拡張 Euclid の互除法版2

||説明|備考|
|:--:|:--:|:--:|
|`mod_inv_extgcd2(a, mod)`|$a$ の逆元|存在しない場合は $-1$ となる．|

- Fermat の小定理版

||説明|備考|
|:--:|:--:|:--:|
|`mod_inv_fermat(a, mod)`|$a$ の逆元|$\mathrm{mod}$ は素数でなければならない．|

- オイラーの定理版

||説明|
|:--:|:--:|
|`mod_inv_phi(a, mod)`|$a$ の逆元|

- 数表

||説明|備考|
|:--:|:--:|:--:|
|`inv_init(val, mod)`|$\mathrm{val}$ 以下の逆元の数表|$a! \perp \mathrm{mod}$|

e.g. $0 \leq a < \mathrm{mod}$ を満たす素数


## 参考

- https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
- https://github.com/kirika-comp/articles/blob/pre-releases/pre-seisuuron.pdf

数表
- http://drken1215.hatenablog.com/entry/2018/06/08/210000


## Verified

- 拡張 Euclid の互除法版
- 拡張 Euclid の互除法版2
- Fermat の小定理版
- オイラーの定理版
- [数表](https://atcoder.jp/contests/dwacon2017-honsen/submissions/9318092)
