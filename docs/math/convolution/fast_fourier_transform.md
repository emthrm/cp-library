---
title: 高速フーリエ変換 (fast Fourier transform)
documentation_of: include/emthrm/math/convolution/fast_fourier_transform.hpp
---

離散フーリエ変換 (discrete Fourier transform)

$$
  F(t) = \sum_{x = 0}^{N - 1} f(x) \zeta_N^{-tx} = \sum_{x = 0}^{N - 1} f(x) \exp\left(-i \frac{2 \pi tx}{N} \right)
$$

を高速に行うアルゴリズムである．

畳み込み (convolution) $C_k = \sum_{i = 0}^k A_i B_{k - i}$ の計算にしばしば用いられる．



## 時間計算量

$O(N\log{N})$


## 使用法

- Cooley–Tukey algorithm

||説明|
|:--:|:--:|
|`butterfly`|バタフライ演算用の配列|
|`zeta[i][j]`|$1$ の $2^{i + 1}$ 乗根 $\xi_{2^{i + 1}}^{-j}$|
|`init(n)`|サイズ $N$ の数列に対して離散フーリエ変換を行うための前処理を行う．|
|`dft(&a)`|複素数列 $A$ に対して離散フーリエ変換を行う．|
|`real_dft(a)`|実数列 $A$ に対して離散フーリエ変換を行ったもの|
|`idft(&a)`|複素数列 $A$ に対して逆離散フーリエ変換を行う．|
|`convolution(a, b)`|実数列 $A$ と $B$ の畳み込み|


## 実装

実数列 $a$ と $b$ の畳み込み $c$ を考える．

複素数列 $p_i = a_i + b_i \sqrt{-1}$ ($0 \leq i < N = 2^e,\ e \in \mathbb{N}$) に離散フーリエ変換を行うと，対応する多項式 $p(x) = \sum_{i = 0}^{N - 1} p_i x^i$ に対して $p(\xi_N^{-i}) = \sum_{j = 0}^{N - 1} p_j \zeta_{N}^{-ij}$ が分かる．

$\overline{p(\overline{x})} = a(x) - b(x) \sqrt{-1}$ より $\overline{p(ξ_N^{-i})} = \overline{p(\overline{\xi_N^i})} = a(ξ_N^i) - b(ξ_N^i) \sqrt{-1}$ が成り立つ．すなわち

$$
  \overline{P_i} =
  \begin{cases}
    A_0 - B_0 \sqrt{-1} & (N = 0), \\
    A_{N - i} - B_{N - i} \sqrt{-1} & (1 \leq i < N)
  \end{cases}
$$

が成り立つ．$A_0, B_0 \in \mathbb{R},\ A_i = \overline{A_{n - i}}$ ($1 \leq i < N$) より

$$
  \begin{split}
    A_i &=
    \begin{cases}
      \dfrac{P_0 + \overline{P_0}}{2} & (i = 0), \\
      \dfrac{P_i + \overline{P_{N - i}}}{2} & (1 \leq i < N),
    \end{cases} \\
    B_i &=
    \begin{cases}
      \dfrac{P_0 - \overline{P_0}}{2 \sqrt{-1}} & (i = 0), \\
      \dfrac{P_i - \overline{P_{N - i}}}{2 \sqrt{-1}} & (1 \leq i < N)
    \end{cases}
  \end{split}
$$

となる．$C_i = A_i B_i$ より

$$
  C_i =
  \begin{cases}
    \dfrac{P_0^2 - \overline{P_0}^2}{4 \sqrt{-1}} = \Re(P_0) \Im(P_0) & (i = 0), \\
    \dfrac{P_i^2 - \overline{P_{N - i}}^2}{4 \sqrt{-1}} = (\overline{P_{N - i}^2} - P_i^2)\dfrac{\sqrt{-1}}{4} & (1 \leq i < N)
  \end{cases}
$$

と変形できる．ここで $d_i = c_{2i} + c_{2i+1} \sqrt{-1}$ に離散フーリエ変換を行うと

$$
  \begin{split}
    C_i &=
    \begin{cases}
      \Re(D_0) + \Im(D_0) & (i = 0), \\
      D_i - (D_i - \overline{D_{\frac{N}{2} - i}}) \dfrac{1 + \xi_N^{-i} \sqrt{-1}}{2} & (1 \leq i \leq \frac{N}{4}),
    \end{cases} \\
    \overline{C_{\frac{N}{2} - i}} &=
    \begin{cases}
      \Re(D_0) - \Im(D_0) & (i = 0), \\
      \overline{D_{\frac{N}{2} - i}} + (D_i - \overline{D_{\frac{N}{2} - i}}) \dfrac{1 + \xi_N^{-i} \sqrt{-1}}{2} & (1 \leq i \leq \frac{N}{4})
    \end{cases}
  \end{split}
$$

となる．変形すると

- $i = 0$ に対して

$$
  D_0 = \frac{(C_0 + \overline{C_{\frac{N}{2}}}) + (C_0 - \overline{C_{\frac{N}{2}}}) \sqrt{-1}}{2} = \frac{(C_0 + C_{\frac{N}{2}}) + (C_0 - C_{\frac{N}{2}}) \sqrt{-1}}{2},
$$

- $1 \leq i \leq \frac{N}{4}$ に対して

$$
  \begin{split}
    D_i &= \frac{(C_i + \overline{C_{\frac{N}{2} - i}}) - (C_i - \overline{C_{\frac{N}{2} - i}}) (-\xi_N^i) \sqrt{-1}}{2} = \frac{(C_i + \overline{C_{\frac{N}{2} - i}}) - (C_i - \overline{C_{\frac{N}{2} - i}}) \xi_N^{-(\frac{N}{2} - i)} \sqrt{-1}}{2}, \\
    \overline{D_{\frac{N}{2} - i}} &= \frac{(C_i + \overline{C_{\frac{N}{2} - i}}) + (C_i - \overline{C_{\frac{N}{2} - i}}) (-\xi_N^i) \sqrt{-1}}{2} = \frac{(C_i + \overline{C_{\frac{N}{2} - i}}) + (C_i - \overline{C_{\frac{N}{2} - i}}) \xi_N^{-(\frac{N}{2} - i)} \sqrt{-1}}{2}
  \end{split}
$$

となる．$C$ は既に求めたので $D$ に対して逆離散フーリエ変換を行えばよい．


## 参考

- https://www.slideshare.net/chokudai/fft-49066791
- ~~https://lumakernel.github.io/ecasdqina/math/FFT/introduction~~
- https://www.creativ.xyz/fast-fourier-transform
- ~~https://lumakernel.github.io/ecasdqina/math/FFT/standard~~
- http://xn--w6q13e505b.jp/method/fft/rft.html
- https://ei1333.github.io/luzhiled/snippets/math/fast-fourier-transform.html


## TODO

- https://www.slideshare.net/chokudai/fft-49066791
- four-step fast Fourier transform / six-step fast Fourier transform
  - http://xn--w6q13e505b.jp/method/fft/2dfft.html
  - ~~https://lumakernel.github.io/ecasdqina/math/FFT/FFT2~~
  - https://todo314.hatenadiary.org/entry/20130811/1376221445
  - https://github.com/beet-aizu/library/blob/master/convolution/convolution2D.cpp
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!FMT.cpp~~
- nine-step fast Fourier transform
  - http://xn--w6q13e505b.jp/method/fft/2dfft.html
- twiddle factor
  - https://en.wikipedia.org/wiki/Twiddle_factor
- Stockham fast Fourier transform
  - http://wwwa.pikara.ne.jp/okojisan/stockham/index.html
  - http://with137d.hatenablog.com/entry/20111224/1324757391
  - http://xn--w6q13e505b.jp/method/fft/implement.html
- split-radix fast Fourier transform
  - https://en.wikipedia.org/wiki/Split-radix_FFT_algorithm
  - http://xn--w6q13e505b.jp/method/fft/radix.html
  - http://wwwa.pikara.ne.jp/okojisan/stockham/stockham3.html
- 多変数の畳み込み
  - https://37zigen.com/truncated-multivariate-convolution/
  - https://judge.yosupo.jp/problem/multivariate_convolution
  - https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
  - https://yukicoder.me/problems/no/1783
- 表現論上の高速フーリエ変換
  - https://hackmd.io/@koboshi/rJpHiXa-O


## Verified

https://atcoder.jp/contests/atc001/submissions/25081106
