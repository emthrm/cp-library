$x$ の最下位ビットは `x & -x` である．

> http://hos.ac/slides/20140319_bit.pdf

---

$x \equiv i \pmod{n}$ かつ $0 \leq x \leq r$ を満たす整数 $x$ の個数は `(r - i + n) / n` である．

> https://twitter.com/xuzijian629/status/1139538453031342080

---

$A + B = (A \oplus B) + 2(A \wedge B)$ が成り立つ．

> https://www.youtube.com/watch?v=lWETOlGiuaI

---

両者の条件が異なる場合, Grundy 数は適用できない．

---

$n \leq 10^9$ を満たす自然数 $n$ の約数の個数の最大値は $800$ 程度である．

> プログラミングコンテストチャレンジブック \[第2版\] p.267

---

$a, c \in \mathbb{N},\ b \in \mathbb{N}^+$ に対して

- $ab < c \iff a < \left\lfloor \frac{c}{b} \right\rfloor$
- $ab \leq c \iff a \leq \left\lfloor \frac{c}{b} \right\rfloor$

が成り立つ．

> https://hackmd.io/@qLethon/B1ZGcrbnI

---

$f_i(x) \mathrel{:=} \min(\max(x + a_i, b_i), c_i)$ とおくと

$$\begin{aligned} f_2 \circ f_1(x) &= \min(\max(\min(\max(x + a_1, b_1), c_1) + a_2, b_2), c_2) \\ &= \min(\max(\min(\max(x + a_1 + a_2, b_1 + a_2), c_1 + a_2), b_2), c_2) \\ &= \min(\min(\max(\max(x + a_1 + a_2, b_1 + a_2), b_2), \max(c_1 + a_2, b_2)), c_2) \\ &= \min(\min(\max(x + a_1 + a_2, \max(b_1 + a_2, b_2)), \max(c_1 + a_2, b_2)), c_2) \\ &= \min(\max(x + a_1 + a_2, \max(b_1 + a_2, b_2)), \min(\max(c_1 + a_2, b_2), c_2)) \\ &= \min(\max(x + A, B), C) \end{aligned}$$

が成り立つ．ただし $A \mathrel{:=} a_1 + a_2,\ B \mathrel{:=} \max(b_1 + a_2, b_2),\ C \mathrel{:=} \min(\max(c_1 + a_2, b_2), c_2)$ である．

> https://atcoder.jp/contests/abc196/editorial/948

---

$x > 0$ ならば `std::sqrt(x * x) == x` が成り立つ．

> https://fixedpoint.jp/2016/03/18/sqrt-of-square-of-fp-number.html
