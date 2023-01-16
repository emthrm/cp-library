# 原始根 (primitive root)

$n \in \mathbb{N}^+,\ g \in \mathbb{Z}$ に対して $\mathrm{ord}_n(g) = \varphi(n)$ が成り立つとき、$g \bmod n$ を「$n$ を法とする原始根」と呼ぶ。

$n = 2, 4, p^k, 2p^k$ ($p \in \mathbb{P} \setminus \lbrace 2 \rbrace,\ k \in \mathbb{N}^+$) のときのみ $\varphi(\varphi(n))$ 個原始根が存在する。


### 位数 (multiplicative order)

$a \perp n$ を満たす $a \in \mathbb{Z},\ n \in \mathbb{N}^+$ に対して $a^k \equiv 1 \pmod{n}$ を満たす最小の $k \in \mathbb{N}^+$ である。


### 指数 (index)

$n$ を法とする原始根を $g$ とすると、任意の $a \in \mathbb{Z}$ に対して $g^e \equiv a \pmod{n}$ を満たす $0 \leq e < \varphi(n)$ がただ一つ存在する。この $e$ を「$g$ を底とする $a$ の指数」と呼び、$\mathrm{Ind}_g(a)$ と表す。


## 時間計算量

||時間計算量|
|:--|:--|
|原始根判定|$O(\sqrt{M})$|


## 仕様

### 原始根判定

|名前|効果・戻り値|
|:--|:--|
|`is_primitive_root(root, m)`|$\mathrm{root}$ は $m$ を法とする原始根であるか|


## 参考文献

- https://ja.wikipedia.org/wiki/%E6%8C%87%E6%95%B0_(%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96)
- https://37zigen.com/primitive-root/

原始根判定
- https://lumakernel.github.io/ecasdqina/math/general
- https://hackmd.io/@qLethon/SJV41ERNL


## TODO

- 高速化
  - https://twitter.com/noshi91/status/1317022141599002624
- 原始根を求める。
  - https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp#L142
  - https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/primitive_root.cpp
  - https://judge.yosupo.jp/problem/primitive_root
- 位数
  - https://github.com/beet-aizu/library/blob/e480647072b3a5cb2016e9137c024ccc043a897f/mod/order.cpp


## Submissons

- [原始根判定](https://yukicoder.me/submissions/624631)
