# Eulerian number

$$A_n(x) = \sum_{m = 0}^n A(n, m) x^m$$

で定義される $A(n, m)$ である．ただし $A_n(x)$ は

$$\sum_{n = 0}^{\infty} A_n(x) \dfrac{t^n}{t!} = \dfrac{x - 1}{x - e^{(x - 1)t}}$$

で定義される Eulerian polynomials である．

$$A(n, m) = \begin{cases} 1 & (m = 0) \\ 0 & (n = m > 0) \\ (n - m) A(n - 1, m - 1) + (m + 1) A(n - 1, m) & (0 < m < n) \end{cases}$$

なる漸化式より計算ができる．

一般項

$$A(n, m) = \sum_{k = 0}^m (-1)^k \binom{n + 1}{k} (m + 1 - k)^n$$

である．


## 時間計算量

||時間計算量|
|:--:|:--:|
|数表|$O(NM)$|
|数表 形式的冪級数版|$O(N\log{N})$|


## 使用法

- 数表

||説明|
|:--:|:--:|
|`eulerian_number_init(n, m)`|Eulerian number $A(i, j) \ (0 \leq i \leq n,\ 0 \leq j \leq m)$|

- 数表 形式的冪級数版

||説明|備考|
|:--:|:--:|:--:|
|`eulerian_number_init_with_fps(n, Combinatorics)`|Eulerian number $A(n, j) \ (0 \leq j \leq n)$|`Combinatorics` は $n + 1$ 以上で定義されていなければならない．|


## 参考

- https://en.wikipedia.org/wiki/Eulerian_number
- http://oeis.org/wiki/Eulerian_numbers,_triangle_of
- https://min-25.hatenablog.com/entry/2015/04/07/160154


## Verified

- 数表
- 数表 形式的冪級数版
