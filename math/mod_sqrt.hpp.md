---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':question:'
    path: util/xorshift.hpp
    title: xorshift
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/formal_power_series.6.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570 (\u5E73\u65B9\u6839)"
  - icon: ':heavy_check_mark:'
    path: test/math/mod_sqrt.test.cpp
    title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/quadratic_residue.md
    document_title: "\u5E73\u65B9\u5270\u4F59"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/mod_sqrt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u5E73\u65B9\u5270\u4F59\r\n * @docs docs/math/quadratic_residue.md\r\
    \n */\r\n\r\n#pragma once\r\n#include \"mod_pow.hpp\"\r\n#include \"../util/xorshift.hpp\"\
    \r\n\r\nlong long mod_sqrt(long long a, int p) {\r\n  if ((a %= p) < 0) a += p;\r\
    \n  if (a == 0) return 0;\r\n  if (p == 2) return 1;\r\n  int half_p = (p - 1)\
    \ >> 1;\r\n  if (mod_pow(a, half_p, p) == p - 1) return -1;\r\n  if (p % 4 ==\
    \ 3) return mod_pow(a, (p + 1) >> 2, p);\r\n  int s = 1, q = half_p;\r\n  for\
    \ (; !(q & 1); q >>= 1, ++s);\r\n  long long z;\r\n  do {\r\n    z = xor128.rand(2,\
    \ p);\r\n  } while (mod_pow(z, half_p, p) == 1);\r\n  int m = s;\r\n  long long\
    \ c = mod_pow(z, q, p), r = mod_pow(a, (q - 1) >> 1, p), t = a * r % p * r % p;\r\
    \n  (r *= a) %= p;\r\n  while (t != 1) {\r\n    long long t2 = t * t % p;\r\n\
    \    for (int i = 1; i < m; ++i) {\r\n      if (t2 == 1) {\r\n        long long\
    \ b = mod_pow(c, 1 << (m - i - 1), p);\r\n        m = i;\r\n        (r *= b) %=\
    \ p;\r\n        c = b * b % p;\r\n        (t *= c) %= p;\r\n        break;\r\n\
    \      }\r\n      (t2 *= t2) %= p;\r\n    }\r\n  }\r\n  return r;\r\n}\r\n"
  dependsOn:
  - math/mod_pow.hpp
  - util/xorshift.hpp
  isVerificationFile: false
  path: math/mod_sqrt.hpp
  requiredBy: []
  timestamp: '2021-02-15 03:05:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/mod_sqrt.test.cpp
  - test/math/formal_power_series/formal_power_series.6.test.cpp
documentation_of: math/mod_sqrt.hpp
layout: document
redirect_from:
- /library/math/mod_sqrt.hpp
- /library/math/mod_sqrt.hpp.html
title: "\u5E73\u65B9\u5270\u4F59"
---
# 平方剰余 (quadratic residue)

$x^2 \equiv a \pmod{p}$ を満たす $x$ が存在する場合，$a \in \mathbb{Z}$ は法 $p$ の下で平方剰余，そうでない場合，平方非剰余である．


### ルジャンドル記号 (Legendre symbol)

整数 $a$, 奇素数 $p$ に対して

$$\left(\dfrac{a}{p} \right) = \begin{cases} 1 & (a \not\equiv 0 \pmod{p} \wedge a \text{ は法 } p \text{ の下で平方剰余}) \\ -1 & (a \text{ は法 } p \text{ の下で平方非剰余}) \\ 0 & (a \equiv 0 \pmod{p}) \end{cases}$$

と定義する．


### オイラーの基準 (Euler's criterion)

整数 $a \neq 0$, 奇素数 $p$ に対して $a \perp p$ ならば

$$\left(\dfrac{a}{p} \right) \equiv a^{\frac{p - 1}{2}} \pmod{p} \text{．}$$


### Tonelli–Shanks algorithm

整数 $a$, 奇素数 $p$ に対して $x^2 \equiv a \pmod{p}$ が成り立つ $x \ (0 \leq x < p)$ を求めるアルゴリズムである．

以下では剰余演算について $p$ を法する．

1. 一般性を失わず $0 \leq a < p$ とできる．

   $a = 0$ ならば $x = 0$ として終了する．

   $a$ が平方非剰余ならば条件を満たす $x$ は存在しないとして終了する．

2. $p = q2^s + 1$ を満たす奇数 $q$, 正整数 $s$ を求める．

   $p$ は奇素数より $q, s$ は一意に決まる．

3. 平方非剰余 $z$ を一つ求め, $m = s,\ c \equiv z^q,\ t \equiv a^q,\ r \equiv a^{\frac{q + 1}{2}}$ とする．

   このとき

   - $c^{2^{m - 1}} \equiv -1 \ (\because z \text{ は平方非剰余かつ } c^{2^{m - 1}} \equiv z^{q2^{m - 1}} = z^{\frac{p - 1}{2}})$，

   - $t^{2^{m - 1}} \equiv 1 \ (\because a \text{ は平方剰余かつ } t^{2^{m - 1}} \equiv a^{q2^{m - 1}} = a^{\frac{p - 1}{2}})$，

   - $r^2 \equiv at \ (\because r^2 \equiv a^{q + 1})$

   が成り立つ．この3式を成り立たせつつ $t \equiv 1$ となる $m, c, r$ を求めればよい．

4. $t \equiv 1$ ならば $x = r$ として終了する．

5. $t^{2^i} \equiv 1$ を満たす最小の正整数 $i$ を求める．

   上の2式目より $i = m - 1$ はこれを満たすので $1 \leq i \leq m - 1$．

   $t \not\equiv 1$ より $t^{2^{i - 1}} \equiv -1$．

   - $m \leftarrow i$，

   - $c \leftarrow c^{2^{m - i}} \ (\because (c^{2^{m - i}})^{2^{i - 1}} = c^{2^{m - 1}} \equiv -1)$，

   - $t \leftarrow tc^{2^{m - i}} \ (\because (tc^{2^{m - i}})^{2^{i - 1}} = t^{2^{i - 1}}c^{2^{m - 1}} \equiv -1 \cdot -1 \equiv 1)$，

   - $r \leftarrow rc^{2^{m - 1 - i}} \ (\because (rc^{2^{m - 1 - i}})^2 \equiv r^2 c^{2^{m - i}} \equiv atc^{2^{m - i}})$

   と更新しても3式は成り立つ．この操作において $m$ は減少しており，$m = 1$ のとき2式目より $t \equiv 1$ なので，有限ステップで解は求まる．

6. 4に戻る．


### ヤコビ記号

整数 $a$, 奇数 $p > 0$ に対して $p$ の素因数分解を $p = \prod_i p_i^{e_i}$ とすると

$$\left(\dfrac{a}{p} \right) = \prod_i \left(\dfrac{a}{p_i} \right)^{e_i}$$

と定義する．


## 時間計算量

||時間計算量|
|:--:|:--:|
|平方剰余||
|ヤコビ記号|$O(\log{\max \lbrace A, P \rbrace})$ ?|


## 使用法

- 平方剰余

||説明|備考|
|:--:|:--:|:--:|
|`mod_sqrt(a, p)`|$x \text{ s.t. } x^2 \equiv a \pmod{p}$|$p \in \mathbb{P}$<br>存在しない場合は $-1$ となる．|

- ヤコビ記号

||説明|
|:--:|:--:|
|`jacobi_symbol(a, p)`|$\left(\dfrac{a}{p} \right)$|


## 参考

平方剰余
- https://lumakernel.github.io/ecasdqina/math/number-theory/Tonelli-Shanks
- https://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm
- http://sugarknri.hatenablog.com/entry/2018/02/16/115740
- https://github.com/ei1333/library/blob/e24eaf375ae60018ba6af9079f690db319719e09/math/combinatorics/mod-sqrt.cpp

ヤコビ記号
- https://en.wikipedia.org/wiki/Jacobi_symbol
- https://judge.yosupo.jp/submission/300


## ToDo

- $x^k \equiv a \pmod{p} \ (a, k \in \mathbb{Z},\ k \geq 0,\ p \in \mathbb{P})$ を満たす $x$ を求める．
  - https://yukicoder.me/problems/3866
  - https://judge.yosupo.jp/problem/kth_root_mod
- Cipolla's algorithm
  - https://en.wikipedia.org/wiki/Cipolla%27s_algorithm
  - https://37zigen.com/cipolla-algorithm/
  - https://judge.yosupo.jp/submission/1843
  - https://judge.yosupo.jp/submission/1669


## Verified

- [平方剰余](https://judge.yosupo.jp/submission/3782)
- [ヤコビ記号](https://yukicoder.me/submissions/429338)
