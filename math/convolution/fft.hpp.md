---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: math/convolution/mod_convolution.hpp
    title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/light/tree/centroid_decomposition.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/centroid_decomposition.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
  - icon: ':x:'
    path: test/math/convolution/fft.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\
      \u5909\u63DB"
  - icon: ':x:'
    path: test/math/convolution/mod_convolution.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\
      \u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: test/math/fps/faulhaber_with_fps.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      \u7248"
  - icon: ':x:'
    path: test/math/fps/fps.5.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570 (mod_pow(exponend, md))"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/fft.hpp\"\n#include <algorithm>\r\n#include\
    \ <cassert>\r\n#include <cmath>\r\n#include <utility>\r\n#include <vector>\r\n\
    \r\nnamespace fft {\r\nusing Real = double;\r\nstruct Complex {\r\n  Real re,\
    \ im;\r\n  Complex(Real re = 0, Real im = 0) : re(re), im(im) {}\r\n  inline Complex\
    \ operator+(const Complex &x) const { return Complex(re + x.re, im + x.im); }\r\
    \n  inline Complex operator-(const Complex &x) const { return Complex(re - x.re,\
    \ im - x.im); }\r\n  inline Complex operator*(const Complex &x) const { return\
    \ Complex(re * x.re - im * x.im, re * x.im + im * x.re); }\r\n  inline Complex\
    \ mul_real(Real r) const { return Complex(re * r, im * r); }\r\n  inline Complex\
    \ mul_pin(Real r) const { return Complex(-im * r, re * r); }\r\n  inline Complex\
    \ conj() const { return Complex(re, -im); }\r\n};\r\n\r\nstd::vector<int> butterfly{0};\r\
    \nstd::vector<std::vector<Complex>> zeta{{{1, 0}}};\r\n\r\nvoid calc(int n) {\r\
    \n  int prev_n = butterfly.size();\r\n  if (n <= prev_n) return;\r\n  butterfly.resize(n);\r\
    \n  int prev_lg = zeta.size(), lg = __builtin_ctz(n);\r\n  for (int i = 1; i <\
    \ prev_n; ++i) butterfly[i] <<= lg - prev_lg;\r\n  for (int i = prev_n; i < n;\
    \ ++i) butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));\r\n  zeta.resize(lg);\r\
    \n  for (int i = prev_lg; i < lg; ++i) {\r\n    zeta[i].resize(1 << i);\r\n  \
    \  Real angle = -3.14159265358979323846 * 2 / (1 << (i + 1));\r\n    for (int\
    \ j = 0; j < (1 << (i - 1)); ++j) {\r\n      zeta[i][j << 1] = zeta[i - 1][j];\r\
    \n      Real theta = angle * ((j << 1) + 1);\r\n      zeta[i][(j << 1) + 1] =\
    \ {std::cos(theta), std::sin(theta)};\r\n    }\r\n  }\r\n}\r\n\r\nvoid sub_dft(std::vector<Complex>\
    \ &a) {\r\n  int n = a.size();\r\n  assert(__builtin_popcount(n) == 1);\r\n  calc(n);\r\
    \n  int shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    int j = butterfly[i] >> shift;\r\n    if (i < j)\
    \ std::swap(a[i], a[j]);\r\n  }\r\n  for (int block = 1; block < n; block <<=\
    \ 1) {\r\n    int den = __builtin_ctz(block);\r\n    for (int i = 0; i < n; i\
    \ += (block << 1)) for (int j = 0; j < block; ++j) {\r\n      Complex tmp = a[i\
    \ + j + block] * zeta[den][j];\r\n      a[i + j + block] = a[i + j] - tmp;\r\n\
    \      a[i + j] = a[i + j] + tmp;\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nstd::vector<Complex> dft(const std::vector<T> &a) {\r\n  int sz = a.size(),\
    \ lg = 1;\r\n  while ((1 << lg) < sz) ++lg;\r\n  std::vector<Complex> c(1 << lg);\r\
    \n  for (int i = 0; i < sz; ++i) c[i].re = a[i];\r\n  sub_dft(c);\r\n  return\
    \ c;\r\n}\r\n\r\nstd::vector<Real> real_idft(std::vector<Complex> &a) {\r\n  int\
    \ n = a.size(), half = n >> 1, quarter = half >> 1;\r\n  assert(__builtin_popcount(n)\
    \ == 1);\r\n  calc(n);\r\n  a[0] = (a[0] + a[half] + (a[0] - a[half]).mul_pin(1)).mul_real(0.5);\r\
    \n  int den = __builtin_ctz(half);\r\n  for (int i = 1; i < quarter; ++i) {\r\n\
    \    int j = half - i;\r\n    Complex tmp1 = a[i] + a[j].conj(), tmp2 = ((a[i]\
    \ - a[j].conj()) * zeta[den][j]).mul_pin(1);\r\n    a[i] = (tmp1 - tmp2).mul_real(0.5);\r\
    \n    a[j] = (tmp1 + tmp2).mul_real(0.5).conj();\r\n  }\r\n  if (quarter > 0)\
    \ a[quarter] = a[quarter].conj();\r\n  a.resize(half);\r\n  sub_dft(a);\r\n  std::reverse(a.begin()\
    \ + 1, a.end());\r\n  Real r = 1.0 / half;\r\n  std::vector<Real> res(n);\r\n\
    \  for (int i = 0; i < n; ++i) res[i] = (i & 1 ? a[i >> 1].im : a[i >> 1].re)\
    \ * r;\r\n  return res;\r\n}\r\n\r\nvoid idft(std::vector<Complex> &a) {\r\n \
    \ int n = a.size();\r\n  sub_dft(a);\r\n  std::reverse(a.begin() + 1, a.end());\r\
    \n  Real r = 1.0 / n;\r\n  for (int i = 0; i < n; ++i) a[i] = a[i].mul_real(r);\r\
    \n}\r\n\r\ntemplate <typename T>\r\nstd::vector<Real> convolution(const std::vector<T>\
    \ &a, const std::vector<T> &b) {\r\n  int a_sz = a.size(), b_sz = b.size(), sz\
    \ = a_sz + b_sz - 1, lg = 1;\r\n  while ((1 << lg) < sz) ++lg;\r\n  int n = 1\
    \ << lg;\r\n  std::vector<Complex> c(n);\r\n  for (int i = 0; i < a_sz; ++i) c[i].re\
    \ = a[i];\r\n  for (int i = 0; i < b_sz; ++i) c[i].im = b[i];\r\n  sub_dft(c);\r\
    \n  c[0] = Complex(c[0].re * c[0].im, 0);\r\n  int half = n >> 1;\r\n  for (int\
    \ i = 1; i < half; ++i) {\r\n    Complex i_square = c[i] * c[i], j_square = c[n\
    \ - i] * c[n - i];\r\n    c[i] = (j_square.conj() - i_square).mul_pin(0.25);\r\
    \n    c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);\r\n  }\r\n  c[half]\
    \ = Complex(c[half].re * c[half].im, 0);\r\n  std::vector<Real> res = real_idft(c);\r\
    \n  res.resize(sz);\r\n  return res;\r\n}\r\n}  // fft\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <cmath>\r\
    \n#include <utility>\r\n#include <vector>\r\n\r\nnamespace fft {\r\nusing Real\
    \ = double;\r\nstruct Complex {\r\n  Real re, im;\r\n  Complex(Real re = 0, Real\
    \ im = 0) : re(re), im(im) {}\r\n  inline Complex operator+(const Complex &x)\
    \ const { return Complex(re + x.re, im + x.im); }\r\n  inline Complex operator-(const\
    \ Complex &x) const { return Complex(re - x.re, im - x.im); }\r\n  inline Complex\
    \ operator*(const Complex &x) const { return Complex(re * x.re - im * x.im, re\
    \ * x.im + im * x.re); }\r\n  inline Complex mul_real(Real r) const { return Complex(re\
    \ * r, im * r); }\r\n  inline Complex mul_pin(Real r) const { return Complex(-im\
    \ * r, re * r); }\r\n  inline Complex conj() const { return Complex(re, -im);\
    \ }\r\n};\r\n\r\nstd::vector<int> butterfly{0};\r\nstd::vector<std::vector<Complex>>\
    \ zeta{{{1, 0}}};\r\n\r\nvoid calc(int n) {\r\n  int prev_n = butterfly.size();\r\
    \n  if (n <= prev_n) return;\r\n  butterfly.resize(n);\r\n  int prev_lg = zeta.size(),\
    \ lg = __builtin_ctz(n);\r\n  for (int i = 1; i < prev_n; ++i) butterfly[i] <<=\
    \ lg - prev_lg;\r\n  for (int i = prev_n; i < n; ++i) butterfly[i] = (butterfly[i\
    \ >> 1] >> 1) | ((i & 1) << (lg - 1));\r\n  zeta.resize(lg);\r\n  for (int i =\
    \ prev_lg; i < lg; ++i) {\r\n    zeta[i].resize(1 << i);\r\n    Real angle = -3.14159265358979323846\
    \ * 2 / (1 << (i + 1));\r\n    for (int j = 0; j < (1 << (i - 1)); ++j) {\r\n\
    \      zeta[i][j << 1] = zeta[i - 1][j];\r\n      Real theta = angle * ((j <<\
    \ 1) + 1);\r\n      zeta[i][(j << 1) + 1] = {std::cos(theta), std::sin(theta)};\r\
    \n    }\r\n  }\r\n}\r\n\r\nvoid sub_dft(std::vector<Complex> &a) {\r\n  int n\
    \ = a.size();\r\n  assert(__builtin_popcount(n) == 1);\r\n  calc(n);\r\n  int\
    \ shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);\r\n  for (int i\
    \ = 0; i < n; ++i) {\r\n    int j = butterfly[i] >> shift;\r\n    if (i < j) std::swap(a[i],\
    \ a[j]);\r\n  }\r\n  for (int block = 1; block < n; block <<= 1) {\r\n    int\
    \ den = __builtin_ctz(block);\r\n    for (int i = 0; i < n; i += (block << 1))\
    \ for (int j = 0; j < block; ++j) {\r\n      Complex tmp = a[i + j + block] *\
    \ zeta[den][j];\r\n      a[i + j + block] = a[i + j] - tmp;\r\n      a[i + j]\
    \ = a[i + j] + tmp;\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nstd::vector<Complex>\
    \ dft(const std::vector<T> &a) {\r\n  int sz = a.size(), lg = 1;\r\n  while ((1\
    \ << lg) < sz) ++lg;\r\n  std::vector<Complex> c(1 << lg);\r\n  for (int i = 0;\
    \ i < sz; ++i) c[i].re = a[i];\r\n  sub_dft(c);\r\n  return c;\r\n}\r\n\r\nstd::vector<Real>\
    \ real_idft(std::vector<Complex> &a) {\r\n  int n = a.size(), half = n >> 1, quarter\
    \ = half >> 1;\r\n  assert(__builtin_popcount(n) == 1);\r\n  calc(n);\r\n  a[0]\
    \ = (a[0] + a[half] + (a[0] - a[half]).mul_pin(1)).mul_real(0.5);\r\n  int den\
    \ = __builtin_ctz(half);\r\n  for (int i = 1; i < quarter; ++i) {\r\n    int j\
    \ = half - i;\r\n    Complex tmp1 = a[i] + a[j].conj(), tmp2 = ((a[i] - a[j].conj())\
    \ * zeta[den][j]).mul_pin(1);\r\n    a[i] = (tmp1 - tmp2).mul_real(0.5);\r\n \
    \   a[j] = (tmp1 + tmp2).mul_real(0.5).conj();\r\n  }\r\n  if (quarter > 0) a[quarter]\
    \ = a[quarter].conj();\r\n  a.resize(half);\r\n  sub_dft(a);\r\n  std::reverse(a.begin()\
    \ + 1, a.end());\r\n  Real r = 1.0 / half;\r\n  std::vector<Real> res(n);\r\n\
    \  for (int i = 0; i < n; ++i) res[i] = (i & 1 ? a[i >> 1].im : a[i >> 1].re)\
    \ * r;\r\n  return res;\r\n}\r\n\r\nvoid idft(std::vector<Complex> &a) {\r\n \
    \ int n = a.size();\r\n  sub_dft(a);\r\n  std::reverse(a.begin() + 1, a.end());\r\
    \n  Real r = 1.0 / n;\r\n  for (int i = 0; i < n; ++i) a[i] = a[i].mul_real(r);\r\
    \n}\r\n\r\ntemplate <typename T>\r\nstd::vector<Real> convolution(const std::vector<T>\
    \ &a, const std::vector<T> &b) {\r\n  int a_sz = a.size(), b_sz = b.size(), sz\
    \ = a_sz + b_sz - 1, lg = 1;\r\n  while ((1 << lg) < sz) ++lg;\r\n  int n = 1\
    \ << lg;\r\n  std::vector<Complex> c(n);\r\n  for (int i = 0; i < a_sz; ++i) c[i].re\
    \ = a[i];\r\n  for (int i = 0; i < b_sz; ++i) c[i].im = b[i];\r\n  sub_dft(c);\r\
    \n  c[0] = Complex(c[0].re * c[0].im, 0);\r\n  int half = n >> 1;\r\n  for (int\
    \ i = 1; i < half; ++i) {\r\n    Complex i_square = c[i] * c[i], j_square = c[n\
    \ - i] * c[n - i];\r\n    c[i] = (j_square.conj() - i_square).mul_pin(0.25);\r\
    \n    c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);\r\n  }\r\n  c[half]\
    \ = Complex(c[half].re * c[half].im, 0);\r\n  std::vector<Real> res = real_idft(c);\r\
    \n  res.resize(sz);\r\n  return res;\r\n}\r\n}  // fft\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/fft.hpp
  requiredBy:
  - math/convolution/mod_convolution.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/fps/fps.5.test.cpp
  - test/math/fps/faulhaber_with_fps.test.cpp
  - test/math/convolution/mod_convolution.test.cpp
  - test/math/convolution/fft.test.cpp
  - test/graph/tree/centroid_decomposition.test.cpp
  - test/graph/light/tree/centroid_decomposition.test.cpp
documentation_of: math/convolution/fft.hpp
layout: document
title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
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
|`calc(n)`|サイズ $N$ の数列に対して DFT を行うための事前処理を行う．||
|`sub_dft(a)`|複素数列 $A$ に対して DFT を行う．||
|`dft(a)`|実数列 $A$ に対して DFT を行ったもの||
|`real_idft(a)`|複素数列 $A$ に対して IDFT を行ったもの|$A$ は実数列に対して DFT を行ったものでなければならない．|
|`idft(a)`|複素数列 $A$ に対して IDFT を行う．||
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


## Verified

https://atcoder.jp/contests/atc001/submissions/9309929
