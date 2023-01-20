---
title: 形式的冪級数 (formal power series)
documentation_of: include/emthrm/math/formal_power_series/formal_power_series.hpp
---

#### [重複組み合わせ](../modint.md)

$K$ 種類存在するとき

$$
  \sum_{n = 0}^\infty {}_K \mathrm{H}_n = \sum_{n = 0}^\infty \binom{K + n - 1}{n} x^n = \dfrac{1}{(1 - x)^K}
$$

となる。

#### [二項係数](./twelvefold_way/binomial_coefficient/binomial_coefficient.md)

$$
  \begin{split}
    (x + y)^n &= \sum_{k = 0}^{\infty} \binom{n}{k} x^k y^{n - k} \\
    (1 - rx)^{-d} &= \sum_{n = 0}^{\infty} \binom{n + d - 1}{d - 1} (rx)^n
  \end{split}
$$

#### 累積和

$$
  (1 + x^r + x^{2r} + \cdots) f = f \cdot \sum_{n = 0}^{\infty} x^{rn} = \frac{f}{1 - x^r}
$$

#### 階差数列

$$
  \sum_{n = 0}^{\infty} (a_n - a_{n - 1}) x^n = (1 - x) f
$$

#### [部分和問題](../../dynamic_programming/subset_sum_problem.md)

$$
  \prod_{i = 1}^N (1 + x^{a_i}) = \exp \left(\sum_{i = 0}^D \sum_{j = 1}^{\left\lfloor \frac{D}{j} \right\rfloor} \# \lbrace k \mid a_k = i \rbrace \frac{(-1)^{j - 1}}{j} x^{ji}\right) \bmod x^{D + 1}
$$

#### 係数の和

$n$ を素数、$\zeta_n$ を $1$ の原始 $n$ 乗根の一つとおくと、

$$
  \sum_{i = 0}^\infty {\lbrack x^{in} \rbrack} f = \frac{1}{n} \sum_{i = 0}^{n - 1} f(\zeta_n^i)
$$

が成り立つ。


## 時間計算量

||時間計算量|
|:--|:--|
|加減算|$O(N)$|
|スカラー倍|$O(N)$|
|乗算|$O(N\log{N})$|
|除算|$O(N\log{N})$|
|剰余演算|$O(N\log{N})$|
|ホーナー法 (Horner's rule)|$O(N)$|
|形式微分|$O(N)$|
|指数|$O(N\log{N})$|
|逆元|$O(N\log{N})$|
|対数|$O(N\log{N})$|
|累乗|$O(N\log{N} + \log{M})$|
|$f^{\mathrm{exponent}} \bmod \mathrm{md}$|$O((N + M)\log(N + M)\log{E})$ ?|
|平方根|数 $M$ の平方根を求めるときの時間計算量を $f(M)$ とおくと $O(N\log{N} + f(M))$|
|$f(x + c)$|$O(N\log{N})$|


## 仕様

```cpp
template <typename T>
struct FormalPowerSeries;
```

- `T`：係数の要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<T> coef;`|係数列|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`explicit FormalPowerSeries(const int deg = 0);`|$\mathrm{deg}$ 次まで係数列をもつオブジェクトを構築する。||
|`explicit FormalPowerSeries(const std::vector<T>& coef);`|係数列を $\mathrm{coef}$ とするオブジェクトを構築する。||
|`FormalPowerSeries(const std::initializer_list<T> init);`|初期化子リストを受け取るコンストラクタ||
|`template <typename InputIter> explicit FormalPowerSeries(const InputIter first, const InputIter last);`|イテレータ範囲コンストラクタ||
|`inline const T& operator[](const int term) const;`<br>`inline T& operator[](const int term);`|${\lbrack x^{\mathrm{term}} \rbrack}f$||
|`void resize(const int deg);`|$\mathrm{deg}$ 次まで係数列をもつ。||
|`void shrink();`|正規化を行う。||
|`int degree() const;`|現在の次数||
|`FormalPowerSeries& operator=(const std::vector<T>& coef_);`<br>`FormalPowerSeries& operator=(const FormalPowerSeries& x);`|代入演算子||
|`FormalPowerSeries& operator+=(const FormalPowerSeries& x);`<br>`FormalPowerSeries operator+(const FormalPowerSeries& x) const;`|加算||
|`FormalPowerSeries& operator-=(const FormalPowerSeries& x);`<br>`FormalPowerSeries operator-(const FormalPowerSeries& x) const;`|減算||
|`FormalPowerSeries& operator*=(const T x);`<br>`FormalPowerSeries& operator*=(const FormalPowerSeries& x);`<br>`FormalPowerSeries operator*(const T x) const;`<br>`FormalPowerSeries operator*(const FormalPowerSeries& x) const;`|乗算||
|`FormalPowerSeries& operator/=(const T x);`<br>`FormalPowerSeries& operator/=(const FormalPowerSeries& x);`<br>`FormalPowerSeries operator/(const T x) const;`<br>`FormalPowerSeries operator/(const FormalPowerSeries& x) const;`|除算||
|`FormalPowerSeries& operator%=(const FormalPowerSeries& x);`<br>`FormalPowerSeries operator%(const FormalPowerSeries& x) const;`|剰余演算||
|`FormalPowerSeries& operator<<=(const int n);`<br>`FormalPowerSeries operator<<(const int n) const;`|$x^n f$||
|`FormalPowerSeries& operator>>=(const int n);`<br>`FormalPowerSeries operator>>(const int n) const;`|$x^{-n} f$。ただし $\mathrm{deg}(f) < n$ のとき $0$ を返す。|
|`bool operator==(FormalPowerSeries x) const;`<br>`bool operator!=(const FormalPowerSeries& x) const;`|比較演算子||
|`FormalPowerSeries operator+() const;`|$+{f}$||
|`FormalPowerSeries operator-() const;`|$-{f}$||
|`T horner(const T x) const;`|$f(x)$||
|`FormalPowerSeries differential() const;`|$f^{\prime}$|$\mathrm{deg}(f) \geq 0$|
|`FormalPowerSeries exp(const int deg) const;`<br>`FormalPowerSeries exp() const;`|$\exp(f)$|${\lbrack x^0 \rbrack}f = 0$|
|`FormalPowerSeries inv(const int deg) const`<br>`FormalPowerSeries inv() const;`|$f \cdot g \equiv 1 \pmod{x^{\mathrm{deg} + 1}}$ を満たす $g$|${\lbrack x^0 \rbrack}f \neq 0$|
|`FormalPowerSeries log(const int deg) const`<br>`FormalPowerSeries log() const;`|$\ln{f}$|${\lbrack x^0 \rbrack}f = 1$|
|`FormalPowerSeries pow(long long exponent, const int deg) const`<br>`FormalPowerSeries pow(const long long exponent) const;`|$f^{\mathrm{exponent}}$||
|`FormalPowerSeries mod_pow(long long exponent, const FormalPowerSeries& md) const;`|$f^{\mathrm{exponent}} \bmod \mathrm{md}$||
|`FormalPowerSeries sqrt(const int deg) const`<br>`FormalPowerSeries sqrt() const;`|$\sqrt{f}$。ただし存在しないときは空列を返す。|
|`FormalPowerSeries translate(const T c) const;`|$f(x + c)$||

#### 静的メンバ関数

|名前|効果|
|:--|:--|
|`static void set_mult(const Mult mult);`|乗算を定義する。|
|`static void set_sqrt(const Sqrt sqrt);`|平方根の計算を定義する。|

#### メンバ型

|名前|説明|
|:--|:--|
|`Mult`|`std::function<std::vector<T>(const std::vector<T>&, const std::vector<T>&)>`|
|`Sqrt`|`std::function<bool(const T&, T*)>`|


## 参考文献

- ~~http://lattemalta.hatenablog.jp/entry/2019/09/29/231332~~
- https://maspypy.com/category/%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e8%a7%a3%e8%aa%ac
- https://science-log.com/%e3%83%9b%e3%83%bc%e3%83%a0%e3%83%9a%e3%83%bc%e3%82%b8/%e6%95%b0%e5%ad%a6top%e3%83%9a%e3%83%bc%e3%82%b8/%e8%a7%a3%e6%9e%90top/%e6%af%8d%e9%96%a2%e6%95%b0%e3%81%ab%e3%81%a4%e3%81%84%e3%81%a6/
- https://codeforces.com/blog/entry/56422
- ~~http://sugarknri.hatenablog.com/entry/2019/10/08/001359~~
- https://github.com/ei1333/library/tree/d7e8da80351ac962978692b1a60d2728783afb26/math/fps
- https://yukicoder.me/wiki/polynomial_techniques

#### 係数の和
- https://www.youtube.com/watch?v=bOXCLR3Wric


## TODO

- https://yukicoder.me/wiki/polynomial_techniques
- https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0-%e9%ab%98%e9%80%9f%e3%81%ab%e8%a8%88%e7%ae%97%e3%81%a7%e3%81%8d%e3%82%8b%e3%82%82%e3%81%ae
- https://37zigen.com/exponential-generating-function/
- https://drive.google.com/drive/folders/1CI4P9TUWcK_sGLkUBsA4ORNilIcNjB-N
- 疎な形式的冪級数
  - https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0-%e9%ab%98%e9%80%9f%e3%81%ab%e8%a8%88%e7%ae%97%e3%81%a7%e3%81%8d%e3%82%8b%e3%82%82%e3%81%ae#toc7
  - https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0-%e9%ab%98%e9%80%9f%e3%81%ab%e8%a8%88%e7%ae%97%e3%81%a7%e3%81%8d%e3%82%8b%e3%82%82%e3%81%ae#toc42
  - https://github.com/yosupo06/library-checker-problems/issues/767
  - https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse
  - https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse
  - https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse
  - https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse
  - https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse
- $g(f(x))$ を $O((N\log{N})^{1.5})$ で求める。
  - http://www.eecs.harvard.edu/~htk/publication/1978-jacm-brent-kung.pdf
  - https://qiita.com/hotman78/items/f0e6d2265badd84d429a#7-fgx
  - https://nyaannyaan.github.io/library/fps/fps-composition.hpp
  - https://judge.yosupo.jp/problem/composition_of_formal_power_series
  - 逆関数
    - https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0-%e9%ab%98%e9%80%9f%e3%81%ab%e8%a8%88%e7%ae%97%e3%81%a7%e3%81%8d%e3%82%8b%e3%82%82%e3%81%ae#toc9
- $\arcsin{f}$
  - https://codeforces.com/blog/entry/56422?#comment-401173
  - https://codeforces.com/blog/entry/56422?#comment-401217
  - https://codeforces.com/blog/entry/56422?#comment-401351
- black box linear algebra
  - https://yukicoder.me/wiki/black_box_linear_algebra
  - https://github.com/ICPCCamp/BlackBoxLinearAlgebra
  - https://nyaannyaan.github.io/library/matrix/black-box-linear-algebra.hpp
  - https://twitter.com/hamko_intel/status/944327890400829440
  - https://yukicoder.me/problems/no/444
- Lagrange inversion theorem
  - https://en.wikipedia.org/wiki/Lagrange_inversion_theorem
  - https://www.mathwills.com/posts/46
  - https://mathlog.info/articles/607
  - https://mathworld.wolfram.com/LagrangeInversionTheorem.html
  - https://twitter.com/kobae964/status/1466770150108311555
  - https://sotanishy.github.io/cp-library-cpp/misc/memo.hpp
  - https://atcoder.jp/contests/abc222/tasks/abc222_h
  - https://twitter.com/kobae964/status/1446833320919064577
  - https://kmjp.hatenablog.jp/entry/2021/10/11/1030
  - https://atcoder.jp/contests/xmascon22/tasks/xmascon22_d
- 記号的 Newton 法
  - https://qiita.com/hotman78/items/f0e6d2265badd84d429a#1%E8%A8%98%E5%8F%B7%E7%9A%84%E3%83%8B%E3%83%A5%E3%83%BC%E3%83%88%E3%83%B3%E6%B3%95
  - https://atcoder.jp/contests/abc222/tasks/abc222_h
  - https://twitter.com/tatyam_prime/status/1446841586252324866
- $\sum_{n = 0}^\infty \frac{n^a}{n!} x^n$
  - https://qiita.com/hotman78/items/90dba287b98629767d6c
- 多項式ハッシュ
  - https://yukicoder.me/wiki/polynomial_techniques
  - https://github.com/beet-aizu/library/blob/master/polynomial/hash.cpp
- ディリクレ級数 (Dirichlet series)
  - https://ja.wikipedia.org/wiki/%E3%83%87%E3%82%A3%E3%83%AA%E3%82%AF%E3%83%AC%E7%B4%9A%E6%95%B0
  - https://maspypy.com/%e6%95%b0%e5%ad%a6-%e7%95%b3%e3%81%bf%e8%be%bc%e3%81%bf%e5%85%a5%e9%96%80%ef%bc%9adirichlet%e7%a9%8d%e3%81%a8%e3%82%bc%e3%83%bc%e3%82%bf%e5%a4%89%e6%8f%9b%e3%83%bb%e3%83%a1%e3%83%93%e3%82%a6
  - https://maspypy.com/dirichlet-%e7%a9%8d%e3%81%a8%e3%80%81%e6%95%b0%e8%ab%96%e9%96%a2%e6%95%b0%e3%81%ae%e7%b4%af%e7%a9%8d%e5%92%8c
  - https://twitter.com/cureskol/status/1377226831359701006
  - https://yukicoder.me/problems/no/1532
  - https://atcoder.jp/contests/arc116/submissions/21399687
  - https://atcoder.jp/contests/abc020/submissions/21426601
- 桁 DP
  - https://qiita.com/ryuhe1/items/185e1a283f13ac638a53


## Submissons

- [指数](https://judge.yosupo.jp/submission/3788)
- [逆元](https://judge.yosupo.jp/submission/3787)
- [対数](https://judge.yosupo.jp/submission/3790)
- [累乗](https://judge.yosupo.jp/submission/99390)
- [`mod_pow(exponent, md)`](https://atcoder.jp/contests/abc135/submissions/10197576)
- [平方根](https://judge.yosupo.jp/submission/3786)
- [`translate(c)`](https://judge.yosupo.jp/submission/8212)
