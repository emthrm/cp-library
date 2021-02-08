---
title: 形式的冪級数 (formal power series)
documentation_of: math/fps/fps.hpp
---


### 操作

- 累積和

  $$(1 + x^r + x^{2r} + \cdots)f = f \sum_{n = 0}^{\infty} x^{rn} = \dfrac{f}{1 - x^r} \text{．}$$

  特に $r = 1$ のとき

  $$(1 + x + x^2 + \cdots)f = f \sum_{n = 0}^{\infty} x^n = \dfrac{f}{1 - x} \text{．}$$

- 階差数列

  $$\sum_{n = 0}^{\infty} (A_n - A_{n - 1}) x^n = (1 - x)f \text{．}$$

- [部分和問題](../../dp/subset_sum_problem.md)

  $$\prod_{i = 1}^N (1 + x^{C_i}) = \exp \left(\sum_{i = 0}^D \sum_{j = 1}^{\left\lfloor \frac{D}{j} \right\rfloor} \# \lbrace k \mid C_k = i \rbrace \dfrac{(-1)^{j - 1}}{j} x^{ji}\right) \bmod x^{D + 1} \text{．}$$


### 公式

- [重複組み合わせ](modint.md)

  $N$ 種類存在するとき

  $$\sum_{n = 0}^{\infty} \binom{N + n - 1}{n} x^n = \dfrac{1}{(1 - x)^N} \text{．}$$

- [二項係数](twelvefold_way/binomial_coefficient/binomial_coefficient.md)

  $$(x + y)^n = \sum_{k = 0}^{\infty} \binom{n}{k} x^k y^{n - k} \text{，}$$

  $$(1 - rx)^{-d} = \sum_{n = 0}^{\infty} \binom{n + d - 1}{d - 1} (rx)^n \text{．}$$


## 時間計算量

||時間計算量|
|:--:|:--:|
|加減算|$O(N)$|
|スカラー倍|$O(N)$|
|乗算|$O(N\log{N})$|
|除算|$O(N\log{N})$|
|剰余演算|$O(N\log{N})$|
|ホーナー法 (Horner's rule)|$O(N)$|
|形式微積分|$O(N)$|
|指数|$O(N\log{N})$|
|逆元|$O(N\log{N})$|
|対数|$O(N\log{N})$|
|冪乗|$O(N\log{N} + \log{M})$|
|`mod_pow(exponent, md)`|$O((N + M)\log(N + M)\log{E})$ ?|
|平方根|数 $M$ の平方根を求めるときの計算量を $f(M)$ とおくと $O(N\log{N} + f(M))$．|
|`translate(c)`|$O(N\log{N})$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`FPS<T>(deg = 0)`|次数 $\mathrm{deg}$ の形式的冪級数||
|`FPS<T>(co)`|数列 $\mathrm{co}$ の母関数||
|`co`|係数||
|`operator()[term]`|$[x^{\mathrm{term}}]f$||
|`set_mul(mul)`|乗算を定義する．||
|`set_sqr(sqr)`|平方根の計算を定義する．||
|`resize(deg)`|先頭 $\mathrm{deg}$ 次を考える．||
|`shrink()`|正規化を行う．||
|`degree()`|次数||
|`operator=(new_co)`|数列 $\mathrm{new\_co}$ を代入する．||
|`operator=(x)`|形式的冪級数 $x$ を代入する．||
|`operator+=(x)`<br>`operator+(x)`|加算||
|`operator-=(x)`<br>`operator-(x)`|減算||
|`operator*=(x)`<br>`operator*(x)`|乗算||
|`operator/=(x)`<br>`operator/(x)`|除算||
|`operator%=(x)`<br>`operator%(x)`|剰余演算||
|`operator<<=(n)`<br>`operator<<(n)`|$x^n f$||
|`operator>>=(n)`<br>`operator>>(n)`|$x^{-n} f$|$\mathrm{deg}(f) < n$ のとき $0$ となる．|
|`operator==(x)`|$f = x$ であるか．||
|`operator!=(x)`|$f \neq x$ であるか．||
|`operator+()`|$+{f}$||
|`operator-()`|$-{f}$||
|`horner(val)`|$f(\mathrm{val})$||
|`differential()`|$f^{\prime}$|$\mathrm{deg}(f) \geq 0$|
|`integral()`|$\int{f}$||
|`exp(deg = n)`|$\exp(f)$|$[x^0]f = 0$|
|`inv(deg = n)`|$g \text{ s.t. } f \cdot g \equiv 1 \pmod{x^{\mathrm{deg} + 1}}$|$[x^0]f \neq 0$|
|`log(deg = n)`|$\ln{f}$|$[x^0]f = 1$|
|`pow(exponent, deg = n)`|$f^{\mathrm{exponent}}$||
|`mod_pow(exponent, md)`|$f^{\mathrm{exponent}} \bmod \mathrm{md}$||
|`sqrt(deg = n)`|$\sqrt{f}$|存在しない場合は空列となる．|
|`translate(c)`|$f(x + c)$||


## 参考

- http://lattemalta.hatenablog.jp/entry/2019/09/29/231332
- https://maspypy.com/category/%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e8%a7%a3%e8%aa%ac
- https://science-log.com/%e3%83%9b%e3%83%bc%e3%83%a0%e3%83%9a%e3%83%bc%e3%82%b8/%e6%95%b0%e5%ad%a6top%e3%83%9a%e3%83%bc%e3%82%b8/%e8%a7%a3%e6%9e%90top/%e6%af%8d%e9%96%a2%e6%95%b0%e3%81%ab%e3%81%a4%e3%81%84%e3%81%a6/
- https://codeforces.com/blog/entry/56422
- http://sugarknri.hatenablog.com/entry/2019/10/08/001359
- https://github.com/ei1333/library/blob/master/math/fps/formal-power-series.cpp


## ToDo

- https://yukicoder.me/wiki/polynomial_techniques
- https://drive.google.com/drive/folders/1CI4P9TUWcK_sGLkUBsA4ORNilIcNjB-N
- $g(f(x))$ を $O((N\log{N})^{1.5})$ で求める．
  - http://www.eecs.harvard.edu/~htk/publication/1978-jacm-brent-kung.pdf
  - https://judge.yosupo.jp/problem/composition_of_formal_power_series
- $\arcsin{f}$
  - https://codeforces.com/blog/entry/56422?#comment-401173
  - https://codeforces.com/blog/entry/56422?#comment-401217
  - https://codeforces.com/blog/entry/56422?#comment-401351
- Berlekamp–Massey algorithm
  - https://en.wikipedia.org/wiki/Berlekamp%E2%80%93Massey_algorithm
  - https://de.wikipedia.org/wiki/Berlekamp-Massey-Algorithmus
  - https://yukicoder.me/wiki/polynomial_techniques
  - http://sugarknri.hatenablog.com/entry/2017/11/18/234217
  - https://qiita.com/kenmaro/items/4042b646d39255b623b8
  - https://haruya12.hatenadiary.org/entry/20160131/1454252059
  - https://github.com/beet-aizu/library/blob/master/polynomial/berlekampmassey.cpp
  - https://github.com/ei1333/library/blob/master/math/fps/berlekamp-massey.cpp
  - https://yukicoder.me/submissions/427818
  - https://judge.yosupo.jp/problem/find_linear_recurrence
- 多項式ハッシュ
  - https://yukicoder.me/wiki/polynomial_techniques
  - https://github.com/beet-aizu/library/blob/master/polynomial/hash.cpp


## Verified

- [指数](https://judge.yosupo.jp/submission/3788)
- [逆元](https://judge.yosupo.jp/submission/3787)
- [対数](https://judge.yosupo.jp/submission/3790)
- [累乗](https://judge.yosupo.jp/submission/7464)
- [`mod_pow(exponent, md)`](https://atcoder.jp/contests/abc135/submissions/10197576)
- [平方根](https://judge.yosupo.jp/submission/3786)
- [`translate(c)`](https://judge.yosupo.jp/submission/8212)
