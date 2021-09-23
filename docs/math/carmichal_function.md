# カーマイケル関数 (Carmichael function)

$n \in \mathbb{N}^+$ に対して，

$$\forall a \in \mathbb{N}^+,\ a \perp n \implies a^x \equiv 1 \pmod{n}$$

を満たす最小の正の整数 $x$ を $\lambda(n)$ と定義する．

素因数分解 $n = \prod_{i = 1}^k p_i^{e_i}$ に対して

$$\lambda(n) = \begin{cases} 1 & (n = 1, 2) \\ 2 & (n = 4) \\ 2^{e - 2} & (\exists e \geq 3 \text{ s.t. } n = 2^e) \\ (p - 1)p^{e - 1} & (\exists p \text{ : 奇素数},\ e \in \mathbb{N}^+ \text{ s.t. } n = p^e) \\ \mathrm{lcm} (\lambda(p_1^{e_1}),\ldots, \lambda(p_k^{e_k})) & (\text{otherwise}) \end{cases}$$

が成り立つ．


## 使用法

||説明|
|:--:|:--:|
|`carmichal_function(n)`|カーマイケル関数 $\lambda(n)$|

- 数表

||説明|
|:--:|:--:|
|`carmichal_function_init(low, high)`|カーマイケル関数 $\lambda(n) \ (\mathrm{low} \leq n \leq \mathrm{high})$ の数表|


## 参考

- http://integers.hatenablog.com/entry/2017/06/08/191649
- https://en.wikipedia.org/wiki/Carmichael_function
- https://github.com/spaghetti-source/algorithm/blob/8af3698b8a7583035857280ab324c8ae75c70374/number_theory/carmichael_lambda.cc


## ToDo

- https://onlinejudge.u-aizu.ac.jp/problems/2720
