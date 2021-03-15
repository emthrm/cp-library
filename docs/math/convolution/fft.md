---
title: 高速フーリエ変換 (fast Fourier transform)
documentation_of: math/convolution/fft.hpp
---

離散フーリエ変換 (discrete Fourier transform, DFT)

$$F(k) = \sum_{j = 0}^{N - 1} f(j) ξ_N^{-jk}$$

を高速に行うアルゴリズムである．

畳み込み

$$C_k = \sum_{i = 0}^k A_i B_{k - i}$$

の計算にしばしば用いられる．

- クーリー-テューキー型アルゴリズム (Cooley-Tukey FFT algorithm)


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`butterfly`|バタフライ演算用の配列||
|`zeta[i][j]`|$1$ の $2^{i + 1}$ 乗根 $\xi_{2^{i + 1}}^{-j}$||
|`calc(n)`|サイズ $N$ の数列に対して離散フーリエ変換を行うための前処理を行う．||
|`sub_dft(a)`|複素数列 $A$ に対して離散フーリエ変換を行う．||
|`dft(a)`|実数列 $A$ に対して離散フーリエ変換を行ったもの||
|`real_idft(a)`|複素数列 $A$ に対して逆離散フーリエ変換を行ったもの|$A$ は実数列に対して離散フーリエ変換を行ったものでなければならない．|
|`idft(a)`|複素数列 $A$ に対して逆離散フーリエ変換を行う．||
|`convolution(a, b)`|実数列 $A$ と $B$ の畳み込み||


## 実装

実数列 $A$ と $B$ の畳み込み $C$ を考える．

複素数列 $P_i = A_i + B_i \sqrt{-1} \ (0 \leq i < N = 2^e,\ e \in \mathbb{N})$ に DFT を行うと,
対応する多項式 $P(x)$ に関して $P(\xi_N^{-i})$ が分かる．

$$\overline{P(\overline{x})} = A(x) - B(x) \sqrt{-1}$$

より

$$\overline{P(\overline{\xi_N^{-i}})} = \overline{P(ξ_N^i)} = A(ξ_N^{-i}) - B(ξ_N^{-i}) \sqrt{-1}$$

が成り立つ．すなわち

$$\overline{P_i} = \begin{cases} A_0 - B_0 \sqrt{-1} & (N = 0) \\ A_{N - i} - B_{N - i} \sqrt{-1} & (1 \leq i < N) \end{cases}$$

が成り立つ．よって

$$A_i = \begin{cases} \dfrac{P_0 + \overline{P_0}}{2} & (i = 0) \\ \dfrac{P_i + \overline{P_{N - i}}}{2} & (1 \leq i < N) \end{cases}$$

$$B_i = \begin{cases} \dfrac{P_0 - \overline{P_0}}{2 \sqrt{-1}} & (i = 0) \\ \dfrac{P_i - \overline{P_{N - i}}}{2 \sqrt{-1}} & (1 \leq i < N) \end{cases}$$

となる．$R_i = A_i B_i$ とおくと

$$R_i = \begin{cases} \dfrac{P_0^2 - \overline{P_0}^2}{4 \sqrt{-1}} = -\Re(R_0) \Im(R_0) & (i = 0) \\ \dfrac{P_i^2 - \overline{P_{N - i}}^2}{4 \sqrt{-1}} = \dfrac{\overline{P_{N - i}^2} - P_i^2}{4} & (1 \leq i < N) \end{cases}$$

と変形できる．ここで $D_i = C_{2i} + C_{2i+1} \sqrt{-1}$ に DFT を行うとすると

$$R_i = \begin{cases} \Re(D_0) + \Im(D_0) & (i = 0) \\ D_i - (D_i - \overline{D_{\frac{N}{2} - i}}) \dfrac{1 + \xi_N^{-i} \sqrt{-1}}{2} & (1 \leq i \leq \frac{N}{4}) \end{cases}$$

$$\overline{R_{\frac{N}{2} - i}} = \begin{cases} \Re(D_0) - \Im(D_0) & (i = 0) \\ \overline{D_{\frac{N}{2} - i}} + (D_i - \overline{D_{\frac{N}{2} - i}}) \dfrac{1 + \xi_N^{-1} \sqrt{-1}}{2} & (1 \leq i \leq \frac{N}{4}) \end{cases}$$

となる．変形すると

- $i = 0$ において

$$D_0 = \frac{(R_0 + R_{\frac{N}{2}}) + (R_0 + R_{\frac{N}{2}}) \sqrt{-1}}{2} \text{，}$$

- $1 \leq i \leq \frac{N}{4}$ において

$$\begin{aligned} D_i = \overline{D_{\frac{N}{2} - i}} &= \frac{(R_i + R_{\frac{N}{2} - i}) - (R_i - R_{\frac{N}{2} - i}) (-\xi_N^i) \sqrt{-1}}{2} \\ &= \frac{(R_i + R_{\frac{N}{2} - i}) - (R_i - R_{\frac{N}{2} - i}) \xi_N^{-(\frac{N}{2} - i)} \sqrt{-1}}{2} \end{aligned}$$

となる．$R_i$ は既に求めたので $D$ に対して IDFT を行えばよい．


## 参考

- https://www.slideshare.net/chokudai/fft-49066791
- https://lumakernel.github.io/ecasdqina/math/FFT/introduction
- https://www.creativ.xyz/fast-fourier-transform
- https://lumakernel.github.io/ecasdqina/math/FFT/standard
- http://xn--w6q13e505b.jp/method/fft/rft.html
- https://ei1333.github.io/luzhiled/snippets/math/fast-fourier-transform.html


## ToDo

- https://www.slideshare.net/chokudai/fft-49066791
- four-step FFT / six-step FFT
  - http://xn--w6q13e505b.jp/method/fft/2dfft.html
  - https://lumakernel.github.io/ecasdqina/math/FFT/FFT2
  - https://todo314.hatenadiary.org/entry/20130811/1376221445
  - https://github.com/beet-aizu/library/blob/master/convolution/convolution2D.cpp
  - https://github.com/eandbsoftware/libraryCPP/blob/master/!FMT.cpp
- nine-step FFT
  - http://xn--w6q13e505b.jp/method/fft/2dfft.html
- twiddle factor
  - https://en.wikipedia.org/wiki/Twiddle_factor
- Stockham 型
  - http://wwwa.pikara.ne.jp/okojisan/stockham/index.html
  - http://with137d.hatenablog.com/entry/20111224/1324757391
  - http://xn--w6q13e505b.jp/method/fft/implement.html
- k-基底 FFT
  - http://xn--w6q13e505b.jp/method/fft/radix.html
  - http://wwwa.pikara.ne.jp/okojisan/stockham/stockham3.html
- 多変数の畳み込み
  - https://37zigen.com/truncated-multivariate-convolution/
  - https://judge.yosupo.jp/problem/multivariate_convolution


## Verified

https://atcoder.jp/contests/atc001/submissions/9309929
