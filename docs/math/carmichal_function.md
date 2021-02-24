# カーマイケル関数 (Carmichael function)

$n = \prod_{i = 1}^k p_i^{e_i}$ と素因数分解されるとすると

$$\lambda(n) = \begin{cases} 1 & (n = 1, 2) \\ 2 & (n = 4) \\ 2^{e - 2} & (\exists e \geq 3 \text{ s.t. } n = 2^e) \\ (p - 1)p^{e - 1} & (\exists p \text{ : 奇素数},\ e \in \mathbb{N} \text{ s.t. } n = p^e) \\ \mathrm{lcm} (\lambda(p_1^{e_1}),\ldots, \lambda(p_k^{e_k})) & (\text{otherwise}) \end{cases}$$

で定義される $\lambda$ である．


### カーマイケルの定理 (Carmichael's theorem)

$n$ を $2$ 以上の任意の自然数とする．

$n$ と互いに素な任意の底 $a \ (1 \leq a \leq n)$ に対して

$$a^{\lambda(n)} \equiv 1 \pmod{n}$$

が成り立つ．


## 使用法

||説明|
|:--:|:--:|
|`carmichal_function(n)`|$\lambda(n)$|

- 数表

||説明|
|:--:|:--:|
|`carmichal_function(low, high)`|カーマイケル関数 $\lambda(n) \ (\mathrm{low} \leq n \leq \mathrm{high})$ の数表|


## 参考

- http://integers.hatenablog.com/entry/2017/06/08/191649
- https://en.wikipedia.org/wiki/Carmichael_function
- https://github.com/spaghetti-source/algorithm/blob/master/number_theory/carmichael_lambda.cc


## ToDo

- https://onlinejudge.u-aizu.ac.jp/problems/2720


## Verified

-
- 数表
