---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/euler_phi/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/primitive_root.md
    document_title: "\u539F\u59CB\u6839\u5224\u5B9A"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/is_primitive_root.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u539F\u59CB\u6839\u5224\u5B9A\r\n * @docs docs/math/primitive_root.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\n#include <map>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n#include \"euler_phi/euler_phi.hpp\"\r\n#include\
    \ \"prime_factorization.hpp\"\r\n#include \"mod_pow.hpp\"\r\n\r\nbool is_primitive_root(long\
    \ long root, long long m) {\r\n  if ((root %= m) < 0) root += m;\r\n  if (std::__gcd(root,\
    \ m) > 1) return false;\r\n  static std::map<long long, long long> phi;\r\n  if\
    \ (phi.count(m) == 0) phi[m] = euler_phi(m);\r\n  long long phi_m = phi[m];\r\n\
    \  static std::map<long long, std::vector<std::pair<long long, int>>> pf;\r\n\
    \  if (pf.count(phi_m) == 0) pf[phi_m] = prime_factorization(phi_m);\r\n  for\
    \ (const std::pair<long long, int> &pr : pf[phi_m]) {\r\n    if (mod_pow(root,\
    \ phi_m / pr.first, m) == 1) return false;\r\n  }\r\n  return true;\r\n}\r\n"
  dependsOn:
  - math/euler_phi/euler_phi.hpp
  - math/prime_factorization.hpp
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/is_primitive_root.hpp
  requiredBy: []
  timestamp: '2021-03-03 13:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/is_primitive_root.test.cpp
documentation_of: math/is_primitive_root.hpp
layout: document
redirect_from:
- /library/math/is_primitive_root.hpp
- /library/math/is_primitive_root.hpp.html
title: "\u539F\u59CB\u6839\u5224\u5B9A"
---
# 原始根 (primitive root)

$n \in \mathbb{N}^+,\ g \in \mathbb{Z}$ に対して $\mathrm{ord}_n(g) = \varphi(n)$ が成り立つとき，$g \bmod n$ を「$n$ を法とする原始根」と呼ぶ．

$n = 2, 4, p^k, 2p^k \ (p \in \mathbb{P} \setminus \lbrace 2 \rbrace,\ k \in \mathbb{N}^+)$ のときのみ $\varphi(\varphi(n))$ 個原始根が存在する．


### 位数 (multiplicative order)

$a \perp n$ を満たす $a \in \mathbb{Z},\ n \in \mathbb{N}^+$ に対して $a^k \equiv 1 \pmod{n}$ を満たす最小の $k \in \mathbb{N}^+$ である．


### 指数 (index)

$n$ を法とする原始根を $g$ とすると，$\forall a \in \mathbb{Z}$ に対して $g^e \equiv a \pmod{n}$ を満たす $0 \leq e < \varphi(n)$ がただ一つ存在する．この $e$ を「$g$ を底とする $a$ の指数」と呼び，$\mathrm{Ind}_g(a)$ と表す．


## 時間計算量

||時間計算量|
|:--:|:--:|
|原始根判定|$O(\sqrt{M})$|


## 使用法

- 原始根判定

||説明|
|:--:|:--:|
|`is_primitive_root(root, m)`|$\mathrm{root}$ は $m$ を法とする原始根であるか|


## 参考

- https://ja.wikipedia.org/wiki/%E6%8C%87%E6%95%B0_(%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96)
- https://37zigen.com/primitive-root/

原始根判定
  - https://lumakernel.github.io/ecasdqina/math/general
  - https://hackmd.io/@qLethon/SJV41ERNL


## ToDo

- 高速化
  - https://twitter.com/noshi91/status/1317022141599002624
- 原始根を求める
  - https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp#L142
  - https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/primitive_root.cpp
- 位数
  - https://github.com/beet-aizu/library/blob/e480647072b3a5cb2016e9137c024ccc043a897f/mod/order.cpp


## Verified

- [原始根判定](https://yukicoder.me/submissions/624631)
