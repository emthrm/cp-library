---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/jacobi_symbol.test.cpp
    title: "\u6570\u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/quadratic_residue.md
    document_title: "\u30E4\u30B3\u30D3\u8A18\u53F7"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/jacobi_symbol.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u30E4\u30B3\u30D3\u8A18\u53F7\n * @docs docs/math/quadratic_residue.md\n\
    \ */\n\n#pragma once\n#include <cassert>\n#include <utility>\n\nint jacobi_symbol(long\
    \ long a, long long p) {\n  assert(p > 0 && p & 1);\n  if (p == 1) return 1;\n\
    \  if ((a %= p) < 0) a += p;\n  if (a == 0) return 0;\n  int res = 1;\n  while\
    \ (a > 0) {\n    const int p2 = __builtin_ctzll(a);\n    if ((p2 & 1) && ((p +\
    \ 2) & 4)) res = -res;\n    a >>= p2;\n    if (a & p & 2) res = -res;\n    std::swap(a,\
    \ p);\n    a %= p;\n  }\n  return p == 1 ? res : 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/jacobi_symbol.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/jacobi_symbol.test.cpp
documentation_of: math/jacobi_symbol.hpp
layout: document
redirect_from:
- /library/math/jacobi_symbol.hpp
- /library/math/jacobi_symbol.hpp.html
title: "\u30E4\u30B3\u30D3\u8A18\u53F7"
---
# 平方剰余 (quadratic residue)

$x^2 \equiv a \pmod{p}$ を満たす $x$ が存在すれば，$a \in \mathbb{Z}$ は法 $p$ の下で平方剰余であり，そうでなければ平方非剰余である．


### ルジャンドル記号 (Legendre symbol)

整数 $a$，奇素数 $p$ に対して

$$
  \left(\dfrac{a}{p} \right) \mathrel{:=}
   \begin{cases}
     1 & (a \not\equiv 0 \pmod{p} \wedge a \text{ は法 } p \text{ の下で平方剰余}), \\
     -1 & (a \text{ は法 } p \text{ の下で平方非剰余}), \\
     0 & (a \equiv 0 \pmod{p})
   \end{cases}
$$

と定義する．


### オイラーの基準 (Euler's criterion)

整数 $a \neq 0$，奇素数 $p$ に対して $a \perp p$ ならば

$$
  \left(\dfrac{a}{p} \right) \equiv a^{\frac{p - 1}{2}} \pmod{p}
$$

が成り立つ．


### Tonelli–Shanks algorithm

整数 $a$，奇素数 $p$ に対して $x^2 \equiv a \pmod{p}$ が成り立つ $x$ ($0 \leq x < p$) を求めるアルゴリズムである．

以下では剰余演算のときに $p$ を法とする．

1. 一般性を失わず $0 \leq a < p$ とできる．

   $a = 0$ ならば $x = 0$ として終了する．

   $a$ が平方非剰余ならば条件を満たす $x$ は存在しないとして終了する．

2. $p = q2^s + 1$ を満たす奇数 $q$，正整数 $s$ を求める．

   $p$ は奇素数より $q, s$ は一意に決まる．

3. 平方非剰余 $z$ を一つ求め，$m = s,\ c \equiv z^q,\ t \equiv a^q,\ r \equiv a^{\frac{q + 1}{2}}$ とする．このとき

   - $c^{2^{m - 1}} \equiv -1 \quad (\because z \text{ は平方非剰余} \wedge c^{2^{m - 1}} \equiv z^{q \cdot 2^{m - 1}} = z^{\frac{p - 1}{2}})$，

   - $t^{2^{m - 1}} \equiv 1 \quad (\because a \text{ は平方剰余} \wedge t^{2^{m - 1}} \equiv a^{q \cdot 2^{m - 1}} = a^{\frac{p - 1}{2}})$，

   - $r^2 \equiv at \quad (\because r^2 \equiv a^{q + 1})$

   が成り立つ．この3式を成り立たせつつ $t \equiv 1$ となる $m, c, r$ を求めればよい．

4. $t \equiv 1$ ならば $x = r$ として終了する．

5. $t^{2^i} \equiv 1$ を満たす最小の正整数 $i$ を求める．

   上の2式目より $i = m - 1$ はこれを満たすので $1 \leq i \leq m - 1$ を満たす．

   $t \not\equiv 1$ より $t^{2^{i - 1}} \equiv -1$ が成り立つ．

   - $m \leftarrow i$，

   - $c \leftarrow c^{2^{m - i}} \quad (\because (c^{2^{m - i}})^{2^{i - 1}} = c^{2^{m - 1}} \equiv -1)$，

   - $t \leftarrow tc^{2^{m - i}} \quad (\because (tc^{2^{m - i}})^{2^{i - 1}} = t^{2^{i - 1}}c^{2^{m - 1}} \equiv -1 \cdot -1 \equiv 1)$，

   - $r \leftarrow rc^{2^{m - 1 - i}} \quad (\because (rc^{2^{m - 1 - i}})^2 \equiv r^2 c^{2^{m - i}} \equiv atc^{2^{m - i}})$

   と更新しても3式は成り立つ．この操作で $m$ は減少している．$m = 1$ のとき2式目より $t \equiv 1$ が成り立つため，有限ステップで解は求まる．

6. 4に戻る．


### ヤコビ記号

整数 $a$，正の奇数 $p$ に対して $p$ の素因数分解を $p = \prod_i p_i^{e_i}$ とすると

$$
  \left(\dfrac{a}{p} \right) \mathrel{:=} \prod_i \left(\dfrac{a}{p_i} \right)^{e_i}
$$

と定義される．


## 時間計算量

||時間計算量|
|:--:|:--:|
|平方剰余||
|ヤコビ記号|$O(\log{\max \lbrace A, P \rbrace})$ ?|


## 使用法

- 平方剰余

||説明|備考|
|:--:|:--:|:--:|
|`mod_sqrt(a, p)`|$x^2 \equiv a \pmod{p}$ を満たす $x$|$p \in \mathbb{P}$<br>存在しないときは $-1$ となる．|

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

- $x^k \equiv a \pmod{p}$ ($a, k \in \mathbb{Z},\ k \geq 0,\ p \in \mathbb{P}$) を満たす $x$ を求める．
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
