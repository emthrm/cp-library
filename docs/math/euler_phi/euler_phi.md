# オイラーの $\varphi$ 関数 (Euler's totient function)

$n \in \mathbb{N}^+$ に対して

$$
  \varphi(n) \mathrel{:=} \# \lbrace k \in \lbrace 1, 2, \ldots, n \rbrace \mid k \perp n \rbrace
$$

と定義される $\varphi(n)$ である。素因数分解 $n = \prod_{i = 1}^k p_i^{e_i}$ に対して

$$
  \varphi(n) = n \prod_{i = 1}^k \left(1 - \frac{1}{p_i}\right)
$$

が成り立つ。


### オイラーの定理

$n \perp a$ を満たす $n, a \in \mathbb{N}^+$ に対して $a^{\varphi(n)} \equiv 1 \pmod{n}$ が成り立つ。


## 時間計算量

||時間計算量|
|:--|:--|
||$O(\sqrt{N})$|
|数表|$O(N\log{\log{N}})$|
|数表2|$O\left(\sqrt{H}\log{\log{H}} + \frac{(H - L)\sqrt{H}}{\log{H}}\right)$ ?|


## 仕様

|名前|効果・戻り値|
|:--|:--|
|`euler_phi(n)`|$\varphi(n)$|

### 数表

|名前|効果・戻り値|
|:--|:--|
|`euler_phi_init(n)`|$\varphi(i)$ ($1 \leq i \leq n$) の数表|

### 数表2

|名前|効果・戻り値|
|:--|:--|
|`euler_phi_init2(low, high)`|$\varphi(i)$ ($\mathrm{low} \leq i < \mathrm{high}$) の数表|


## 参考文献

- https://ei1333.github.io/algorithm/euler-phi.html

数表2
- https://github.com/spaghetti-source/algorithm/blob/87f5b3e4a3c10d8b85048f4fc4e4842ad11e9670/number_theory/euler_phi.cc


## TODO

- $\sum_{i = 1}^n \varphi(i)$ を $O(N^{\frac{2}{3}})$ で求める。
  - https://yukicoder.me/wiki/sum_totient
  - https://min-25.hatenablog.com/entry/2018/11/11/172216
  - https://judge.yosupo.jp/problem/sum_of_totient_function


## Submissons

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088206/emthrm/C++14
- [数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088232/emthrm/C++14)
- [数表2](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088268/emthrm/C++14)
