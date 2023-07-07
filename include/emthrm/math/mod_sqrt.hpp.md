---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/formal_power_series/formal_power_series.6.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570\uFF08\u5E73\u65B9\u6839\uFF09"
  - icon: ':heavy_check_mark:'
    path: test/math/mod_sqrt.test.cpp
    title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/mod_sqrt.hpp\"\n\n\n\n#include <random>\n\
    \n#line 1 \"include/emthrm/math/mod_pow.hpp\"\n\n\n\nnamespace emthrm {\n\nlong\
    \ long mod_pow(long long x, long long n, const int m) {\n  if ((x %= m) < 0) x\
    \ += m;\n  long long res = 1;\n  for (; n > 0; n >>= 1) {\n    if (n & 1) res\
    \ = (res * x) % m;\n    x = (x * x) % m;\n  }\n  return res;\n}\n\n}  // namespace\
    \ emthrm\n\n\n#line 7 \"include/emthrm/math/mod_sqrt.hpp\"\n\nnamespace emthrm\
    \ {\n\nlong long mod_sqrt(long long a, const int p) {\n  if ((a %= p) < 0) a +=\
    \ p;\n  if (a == 0) [[unlikely]] return 0;\n  if (p == 2) [[unlikely]] return\
    \ 1;\n  if (mod_pow(a, (p - 1) >> 1, p) == p - 1) return -1;\n  if (p % 4 == 3)\
    \ return mod_pow(a, (p + 1) >> 2, p);\n  int s = 1, q = (p - 1) >> 1;\n  for (;\
    \ !(q & 1); q >>= 1) {\n    ++s;\n  }\n  static std::mt19937_64 engine(std::random_device\
    \ {} ());\n  std::uniform_int_distribution<> dist(2, p - 1);\n  long long z;\n\
    \  do {\n    z = dist(engine);\n  } while (mod_pow(z, (p - 1) >> 1, p) == 1);\n\
    \  int m = s;\n  long long c = mod_pow(z, q, p), r = mod_pow(a, (q - 1) >> 1,\
    \ p);\n  long long t = a * r % p * r % p;\n  r = (r * a) % p;\n  while (t != 1)\
    \ {\n    long long t2 = t * t % p;\n    for (int i = 1; i < m; ++i) {\n      if\
    \ (t2 == 1) {\n        const long long b = mod_pow(c, 1 << (m - i - 1), p);\n\
    \        m = i;\n        r = (r * b) % p;\n        c = b * b % p;\n        t =\
    \ (t * c) % p;\n        break;\n      }\n      t2 = (t2 * t2) % p;\n    }\n  }\n\
    \  return r;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_MOD_SQRT_HPP_\n#define EMTHRM_MATH_MOD_SQRT_HPP_\n\n\
    #include <random>\n\n#include \"emthrm/math/mod_pow.hpp\"\n\nnamespace emthrm\
    \ {\n\nlong long mod_sqrt(long long a, const int p) {\n  if ((a %= p) < 0) a +=\
    \ p;\n  if (a == 0) [[unlikely]] return 0;\n  if (p == 2) [[unlikely]] return\
    \ 1;\n  if (mod_pow(a, (p - 1) >> 1, p) == p - 1) return -1;\n  if (p % 4 == 3)\
    \ return mod_pow(a, (p + 1) >> 2, p);\n  int s = 1, q = (p - 1) >> 1;\n  for (;\
    \ !(q & 1); q >>= 1) {\n    ++s;\n  }\n  static std::mt19937_64 engine(std::random_device\
    \ {} ());\n  std::uniform_int_distribution<> dist(2, p - 1);\n  long long z;\n\
    \  do {\n    z = dist(engine);\n  } while (mod_pow(z, (p - 1) >> 1, p) == 1);\n\
    \  int m = s;\n  long long c = mod_pow(z, q, p), r = mod_pow(a, (q - 1) >> 1,\
    \ p);\n  long long t = a * r % p * r % p;\n  r = (r * a) % p;\n  while (t != 1)\
    \ {\n    long long t2 = t * t % p;\n    for (int i = 1; i < m; ++i) {\n      if\
    \ (t2 == 1) {\n        const long long b = mod_pow(c, 1 << (m - i - 1), p);\n\
    \        m = i;\n        r = (r * b) % p;\n        c = b * b % p;\n        t =\
    \ (t * c) % p;\n        break;\n      }\n      t2 = (t2 * t2) % p;\n    }\n  }\n\
    \  return r;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOD_SQRT_HPP_\n"
  dependsOn:
  - include/emthrm/math/mod_pow.hpp
  isVerificationFile: false
  path: include/emthrm/math/mod_sqrt.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/formal_power_series/formal_power_series.6.test.cpp
  - test/math/mod_sqrt.test.cpp
documentation_of: include/emthrm/math/mod_sqrt.hpp
layout: document
title: "\u5E73\u65B9\u5270\u4F59 (quadratic residue)"
---

# 平方剰余 (quadratic residue)

$x^2 \equiv a \pmod{p}$ を満たす $x$ が存在すれば、$a \in \mathbb{Z}$ は法 $p$ の下で平方剰余であり、そうでなければ平方非剰余である。


### ルジャンドル記号 (Legendre symbol)

整数 $a$、奇素数 $p$ に対して

$$
  \left(\dfrac{a}{p} \right) \mathrel{:=}
   \begin{cases}
     1 & (a \not\equiv 0 \pmod{p} \wedge a \text{ は法 } p \text{ の下で平方剰余}), \\
     -1 & (a \text{ は法 } p \text{ の下で平方非剰余}), \\
     0 & (a \equiv 0 \pmod{p})
   \end{cases}
$$

と定義する。


### オイラーの基準 (Euler's criterion)

整数 $a \neq 0$、奇素数 $p$ に対して $a \perp p$ ならば

$$
  \left(\dfrac{a}{p} \right) \equiv a^{\frac{p - 1}{2}} \pmod{p}
$$

が成り立つ。


### Tonelli–Shanks algorithm

整数 $a$、奇素数 $p$ に対して $x^2 \equiv a \pmod{p}$ が成り立つ $x$ ($0 \leq x < p$) を求めるアルゴリズムである。

以下では剰余演算のときに $p$ を法とする。

1. 一般性を失わず $0 \leq a < p$ とできる。

   $a = 0$ ならば $x = 0$ として終了する。

   $a$ が平方非剰余ならば条件を満たす $x$ は存在しないとして終了する。

2. $p = q2^s + 1$ を満たす奇数 $q$、正整数 $s$ を求める。

   $p$ は奇素数より $q, s$ は一意に決まる。

3. 平方非剰余 $z$ を一つ求め、$m = s,\ c \equiv z^q,\ t \equiv a^q,\ r \equiv a^{\frac{q + 1}{2}}$ とする。このとき

   - $c^{2^{m - 1}} \equiv -1 \quad (\because z \text{ は平方非剰余} \wedge c^{2^{m - 1}} \equiv z^{q \cdot 2^{m - 1}} = z^{\frac{p - 1}{2}})$、

   - $t^{2^{m - 1}} \equiv 1 \quad (\because a \text{ は平方剰余} \wedge t^{2^{m - 1}} \equiv a^{q \cdot 2^{m - 1}} = a^{\frac{p - 1}{2}})$、

   - $r^2 \equiv at \quad (\because r^2 \equiv a^{q + 1})$

   が成り立つ。この3式を成り立たせつつ $t \equiv 1$ となる $m, c, r$ を求めればよい。

4. $t \equiv 1$ ならば $x = r$ として終了する。

5. $t^{2^i} \equiv 1$ を満たす最小の正整数 $i$ を求める。

   上の2式目より $i = m - 1$ はこれを満たすので $1 \leq i \leq m - 1$ を満たす。

   $t \not\equiv 1$ より $t^{2^{i - 1}} \equiv -1$ が成り立つ。

   - $m \leftarrow i$、

   - $c \leftarrow c^{2^{m - i}} \quad (\because (c^{2^{m - i}})^{2^{i - 1}} = c^{2^{m - 1}} \equiv -1)$、

   - $t \leftarrow tc^{2^{m - i}} \quad (\because (tc^{2^{m - i}})^{2^{i - 1}} = t^{2^{i - 1}}c^{2^{m - 1}} \equiv -1 \cdot -1 \equiv 1)$、

   - $r \leftarrow rc^{2^{m - 1 - i}} \quad (\because (rc^{2^{m - 1 - i}})^2 \equiv r^2 c^{2^{m - i}} \equiv atc^{2^{m - i}})$

   と更新しても3式は成り立つ。この操作で $m$ は減少している。$m = 1$ のとき2式目より $t \equiv 1$ が成り立つため、有限ステップで解は求まる。

6. 4に戻る。


### ヤコビ記号 (Jacobi symbol)

整数 $a$、正の奇数 $p$ に対して $p$ の素因数分解を $p = \prod_i p_i^{e_i}$ とすると

$$
  \left(\dfrac{a}{p} \right) \mathrel{:=} \prod_i \left(\dfrac{a}{p_i} \right)^{e_i}
$$

と定義される。


## 時間計算量

||時間計算量|
|:--|:--|
|平方剰余||
|ヤコビ記号|$O(\log{\max \lbrace A, P \rbrace})$ ?|


## 仕様

### 平方剰余

|名前|戻り値|要件|
|:--|:--|:--|
|`long long mod_sqrt(long long a, const int p);`|$x^2 \equiv a \pmod{p}$ を満たす $x$。ただし存在しないときは $-1$ を返す。|$p \in \mathbb{P}$|


### ヤコビ記号

|名前|戻り値|
|:--|:--|
|`int jacobi_symbol(long long a, long long p);`|$\left(\dfrac{a}{p} \right)$|


## 参考文献

平方剰余
- Carl Friedrich Gauss: Disquisitiones Arithmeticae (1801).
- Daniel Shanks: Five number-theoretic algorithms, *Proceedings of the second Manitoba conference on numerical mathematics*, pp. 51–70 (1973).
- ~~https://lumakernel.github.io/ecasdqina/math/number-theory/Tonelli-Shanks~~
- https://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm
- ~~http://sugarknri.hatenablog.com/entry/2018/02/16/115740~~
- https://github.com/ei1333/library/blob/e24eaf375ae60018ba6af9079f690db319719e09/math/combinatorics/mod-sqrt.cpp

ルジャンドル記号
- Adrien Marie Legendre: Essai sur la Théorie des Nombres (1798).

ヤコビ記号
- Carl Gustav Jacob Jacobi: Über die Kreistheilung und ihre Anwendung auf die Zahlentheorie, *Journal für die reine und angewandte Mathematik*, Vol. 30, pp. 166–182 (1846).
- https://en.wikipedia.org/wiki/Jacobi_symbol
- https://judge.yosupo.jp/submission/300


## TODO

- $x^k \equiv a \pmod{p}$ ($a, k \in \mathbb{Z},\ k \geq 0,\ p \in \mathbb{P}$) を満たす $x$ を求める。
  - https://yukicoder.me/problems/3866
  - https://judge.yosupo.jp/problem/kth_root_mod
- Cipolla's algorithm
  - https://en.wikipedia.org/wiki/Cipolla%27s_algorithm
  - https://37zigen.com/cipolla-algorithm/
  - https://judge.yosupo.jp/submission/1843
  - https://judge.yosupo.jp/submission/1669


## Submissons

- [平方剰余](https://judge.yosupo.jp/submission/3782)
- [ヤコビ記号](https://yukicoder.me/submissions/429338)
