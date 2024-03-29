---
title: [
  Eulerian number,
  Eulerian number 形式的冪級数版
]
documentation_of: [
  //include/emthrm/math/formal_power_series/eulerian_number.hpp,
  //include/emthrm/math/formal_power_series/eulerian_number_by_fps.hpp
]
---

# Eulerian number

$$
  A_n(x) = \sum_{m = 0}^n A(n, m) x^m
$$

で定義される $A(n, m)$ である。ただし $A_n(x)$ は

$$
  \sum_{n = 0}^{\infty} A_n(x) \dfrac{t^n}{t!} = \dfrac{x - 1}{x - e^{(x - 1)t}}
$$

で定義される Eulerian polynomials である。

$$
  A(n, m) =
  \begin{cases}
    1 & (m = 0), \\
    0 & (n = m > 0), \\
    (n - m) A(n - 1, m - 1) + (m + 1) A(n - 1, m) & (0 < m < n)
  \end{cases}
$$

という漸化式をもつ。

一般項

$$
  A(n, m) = \sum_{k = 0}^m (-1)^k \binom{n + 1}{k} (m + 1 - k)^n
$$

である。


## 時間計算量

||時間計算量|
|:--|:--|
||$O(NM)$|
|形式的冪級数版|$O(N\log{N})$|


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> eulerian_number(const int n, const int m);`|Eulerian number $A(i, j)$ ($0 \leq i \leq n,\ 0 \leq j \leq m$) の数表|


### 形式的冪級数版

|名前|戻り値|
|:--|:--|
|`template <unsigned int T>`<br>`std::vector<MInt<T>> eulerian_number_init_by_fps(const int n);`|Eulerian number $A(n, j)$ ($0 \leq j \leq n$) の数表|


## 参考文献

- Leonhard Euler: Institutiones calculi differentialis (1755).
- https://en.wikipedia.org/wiki/Eulerian_number
- http://oeis.org/wiki/Eulerian_numbers,_triangle_of
- ~~https://min-25.hatenablog.com/entry/2015/04/07/160154~~
