# 数論変換 (number theoretic transform) / 高速剰余変換 (fast modulo transform)

剰余環 $\mathbb{Z} / m\mathbb{Z}$ 上で離散フーリエ変換を高速に行うアルゴリズムである。

特に $2^x \geq n$ を満たす $x, k \in \mathbb{N}$ を用いて表される素数 $p = 2^x k + 1$ は、$p$ の原始根 $\omega$ に対して

$$
  \omega^{p - 1} \equiv 1 \pmod{p}
$$

すなわち

$$
  (\omega^k)^{2^x} \equiv 1 \pmod{p}
$$

が成り立つので、条件を満たす。


## 時間計算量

$O(N\log{N})$


## 仕様

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`NumberTheoreticTransform<T>()`|数論変換を考える。||
|`dft(a)`|整数列 $A$ に対して数論変換を行ったもの||
|`idft(&a)`|$A$ に対して数論変換の逆変換を行う。||
|`convolution(a, b)`|整数列 $A$ と $B$ の畳み込み|$\max_i{C_i} \leq (\max_i{A_i})(\max_i{B_i})(\min \lbrace \lvert A \rvert, \lvert B \rvert \rbrace)$|

### 任意の法の下での畳み込み

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`mod_convolution(a, b, 精度 = 15)`|$A$ と $B$ の畳み込み|$(\text{精度}) \geq \log_2{\sqrt{m}}$ でなければならない。|

e.g. $(\text{精度}) = 15$ のとき $m \leq 2^{30} = 1073741824$。


## 参考文献

- https://ei1333.github.io/luzhiled/snippets/math/fast-fourier-transform.html
- ~~https://lumakernel.github.io/ecasdqina/math/FFT/NumberTheoreticTransform~~
- http://xn--w6q13e505b.jp/method/fft/modular.html
- http://www.cs.t-kougei.ac.jp/nsim/method/fmtbase.htm

#### 任意の法の下での畳み込み
- ~~https://min-25.hatenablog.com/entry/2017/09/23/085053~~
- https://ei1333.github.io/luzhiled/snippets/math/arbitrary-mod-convolution.html
- https://sotanishy.github.io/cp-library-cpp/convolution/arbitrary_mod_convolution.hpp


## TODO

- 数論変換を用いた任意の法の下での畳み込み
  - https://math314.hateblo.jp/entry/2015/05/07/014908
  - https://naoyat.hatenablog.jp/entry/DFT-and-NTT
  - https://ei1333.github.io/algorithm/fft.html
  - ~~https://lumakernel.github.io/ecasdqina/math/FFT/NumberTheoreticTransform~~
  - https://github.com/spaghetti-source/algorithm/blob/master/math/fast_modulo_transform.cc
  - https://satanic0258.github.io/snippets/math/NTT.html
  - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  - https://github.com/yosupo06/library-checker-problems/issues/664
  - https://judge.yosupo.jp/problem/convolution_mod_2_64
  - https://judge.yosupo.jp/problem/convolution_mod_large
  - https://judge.yosupo.jp/problem/mul_mod2n_convolution
  - https://github.com/yosupo06/library-checker-problems/issues/728


## Submissons

- [数論変換](https://judge.yosupo.jp/submission/3591)
- [任意の法の下での畳み込み](https://atcoder.jp/contests/atc001/submissions/25084524)
