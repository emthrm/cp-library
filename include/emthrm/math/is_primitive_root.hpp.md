---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/euler_phi/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
  - icon: ':question:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':question:'
    path: include/emthrm/math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/primitive_root.md
    document_title: "\u539F\u59CB\u6839\u5224\u5B9A"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/is_primitive_root.hpp: line 14: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u539F\u59CB\u6839\u5224\u5B9A\n * @docs docs/math/primitive_root.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_\n#define EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_\n\
    \n#include <algorithm>\n#include <map>\n#include <utility>\n#include <vector>\n\
    \n#include \"emthrm/math/euler_phi/euler_phi.hpp\"\n#include \"emthrm/math/mod_pow.hpp\"\
    \n#include \"emthrm/math/prime_factorization.hpp\"\n\nnamespace emthrm {\n\nbool\
    \ is_primitive_root(long long root, const int m) {\n  if ((root %= m) < 0) root\
    \ += m;\n  if (std::__gcd(static_cast<int>(root), m) > 1) return false;\n  static\
    \ std::map<int, int> phi;\n  if (!phi.count(m)) phi[m] = euler_phi(m);\n  const\
    \ int phi_m = phi[m];\n  static std::map<int, std::vector<int>> primes;\n  if\
    \ (!primes.count(phi_m)) {\n    std::vector<int> tmp;\n    for (const std::pair<int,\
    \ int>& pr : prime_factorization(phi_m)) {\n      tmp.emplace_back(pr.first);\n\
    \    }\n    primes[phi_m] = tmp;\n  }\n  for (const int p : primes[phi_m]) {\n\
    \    if (mod_pow(root, phi_m / p, m) == 1) return false;\n  }\n  return true;\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_\n"
  dependsOn:
  - include/emthrm/math/euler_phi/euler_phi.hpp
  - include/emthrm/math/mod_pow.hpp
  - include/emthrm/math/prime_factorization.hpp
  isVerificationFile: false
  path: include/emthrm/math/is_primitive_root.hpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/is_primitive_root.test.cpp
documentation_of: include/emthrm/math/is_primitive_root.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/is_primitive_root.hpp
- /library/include/emthrm/math/is_primitive_root.hpp.html
title: "\u539F\u59CB\u6839\u5224\u5B9A"
---
# 原始根 (primitive root)

$n \in \mathbb{N}^+,\ g \in \mathbb{Z}$ に対して $\mathrm{ord}_n(g) = \varphi(n)$ が成り立つとき，$g \bmod n$ を「$n$ を法とする原始根」と呼ぶ．

$n = 2, 4, p^k, 2p^k$ ($p \in \mathbb{P} \setminus \lbrace 2 \rbrace,\ k \in \mathbb{N}^+$) のときのみ $\varphi(\varphi(n))$ 個原始根が存在する．


### 位数 (multiplicative order)

$a \perp n$ を満たす $a \in \mathbb{Z},\ n \in \mathbb{N}^+$ に対して $a^k \equiv 1 \pmod{n}$ を満たす最小の $k \in \mathbb{N}^+$ である．


### 指数 (index)

$n$ を法とする原始根を $g$ とすると，任意の $a \in \mathbb{Z}$ に対して $g^e \equiv a \pmod{n}$ を満たす $0 \leq e < \varphi(n)$ がただ一つ存在する．この $e$ を「$g$ を底とする $a$ の指数」と呼び，$\mathrm{Ind}_g(a)$ と表す．


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


## TODO

- 高速化
  - https://twitter.com/noshi91/status/1317022141599002624
- 原始根を求める．
  - https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp#L142
  - https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/primitive_root.cpp
  - https://judge.yosupo.jp/problem/primitive_root
- 位数
  - https://github.com/beet-aizu/library/blob/e480647072b3a5cb2016e9137c024ccc043a897f/mod/order.cpp


## Verified

- [原始根判定](https://yukicoder.me/submissions/624631)
