---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: math/convolution/mod_convolution.hpp
    title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/centroid_decomposition.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
  - icon: ':x:'
    path: test/math/convolution/fast_fourier_transform.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\
      \u5909\u63DB"
  - icon: ':x:'
    path: test/math/convolution/mod_convolution.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\
      \u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/faulhaber_by_fps.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      \u7248"
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/formal_power_series.5.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
      \u7D1A\u6570 (mod_pow(exponend, md))"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/fast_fourier_transform.hpp\"\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n#include <cmath>\r\n#include <iterator>\r\
    \n#include <utility>\r\n#include <vector>\r\n\r\nnamespace fast_fourier_transform\
    \ {\r\n\r\nusing Real = double;\r\n\r\nstruct Complex {\r\n  Real re, im;\r\n\
    \  explicit Complex(const Real re = 0, const Real im = 0) : re(re), im(im) {}\r\
    \n  inline Complex operator+(const Complex& x) const {\r\n    return Complex(re\
    \ + x.re, im + x.im);\r\n  }\r\n  inline Complex operator-(const Complex& x) const\
    \ {\r\n    return Complex(re - x.re, im - x.im);\r\n  }\r\n  inline Complex operator*(const\
    \ Complex& x) const {\r\n    return Complex(re * x.re - im * x.im, re * x.im +\
    \ im * x.re);\r\n  }\r\n  inline Complex mul_real(const Real r) const {\r\n  \
    \  return Complex(re * r, im * r);\r\n  }\r\n  inline Complex mul_pin(const Real\
    \ r) const {\r\n    return Complex(-im * r, re * r);\r\n  }\r\n  inline Complex\
    \ conj() const { return Complex(re, -im); }\r\n};\r\n\r\nstd::vector<int> butterfly{0};\r\
    \nstd::vector<std::vector<Complex>> zeta{{Complex(1, 0)}};\r\n\r\nvoid init(const\
    \ int n) {\r\n  const int prev_n = butterfly.size();\r\n  if (n <= prev_n) return;\r\
    \n  butterfly.resize(n);\r\n  const int prev_lg = zeta.size(), lg = __builtin_ctz(n);\r\
    \n  for (int i = 1; i < prev_n; ++i) {\r\n    butterfly[i] <<= lg - prev_lg;\r\
    \n  }\r\n  for (int i = prev_n; i < n; ++i) {\r\n    butterfly[i] = (butterfly[i\
    \ >> 1] >> 1) | ((i & 1) << (lg - 1));\r\n  }\r\n  zeta.resize(lg);\r\n  for (int\
    \ i = prev_lg; i < lg; ++i) {\r\n    zeta[i].resize(1 << i);\r\n    const Real\
    \ angle = -3.14159265358979323846 * 2 / (1 << (i + 1));\r\n    for (int j = 0;\
    \ j < (1 << (i - 1)); ++j) {\r\n      zeta[i][j << 1] = zeta[i - 1][j];\r\n  \
    \    const Real theta = angle * ((j << 1) + 1);\r\n      zeta[i][(j << 1) + 1]\
    \ = Complex(std::cos(theta), std::sin(theta));\r\n    }\r\n  }\r\n}\r\n\r\nvoid\
    \ dft(std::vector<Complex>* a) {\r\n  const int n = a->size();\r\n  assert(__builtin_popcount(n)\
    \ == 1);\r\n  init(n);\r\n  const int shift = __builtin_ctz(butterfly.size())\
    \ - __builtin_ctz(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    const int j =\
    \ butterfly[i] >> shift;\r\n    if (i < j) std::swap((*a)[i], (*a)[j]);\r\n  }\r\
    \n  for (int block = 1, den = 0; block < n; block <<= 1, ++den) {\r\n    for (int\
    \ i = 0; i < n; i += (block << 1)) {\r\n      for (int j = 0; j < block; ++j)\
    \ {\r\n        const Complex tmp = (*a)[i + j + block] * zeta[den][j];\r\n   \
    \     (*a)[i + j + block] = (*a)[i + j] - tmp;\r\n        (*a)[i + j] = (*a)[i\
    \ + j] + tmp;\r\n      }\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\n\
    std::vector<Complex> real_dft(const std::vector<T>& a) {\r\n  const int n = a.size();\r\
    \n  int lg = 1;\r\n  while ((1 << lg) < n) ++lg;\r\n  std::vector<Complex> c(1\
    \ << lg);\r\n  for (int i = 0; i < n; ++i) {\r\n    c[i].re = a[i];\r\n  }\r\n\
    \  dft(&c);\r\n  return c;\r\n}\r\n\r\nvoid idft(std::vector<Complex>* a) {\r\n\
    \  const int n = a->size();\r\n  dft(a);\r\n  std::reverse(std::next(a->begin()),\
    \ a->end());\r\n  const Real r = 1. / n;\r\n  for (int i = 0; i < n; ++i) {\r\n\
    \    (*a)[i] = (*a)[i].mul_real(r);\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\
    \nstd::vector<Real> convolution(const std::vector<T>& a,\r\n                 \
    \             const std::vector<T>& b) {\r\n  const int a_size = a.size(), b_size\
    \ = b.size(), c_size = a_size + b_size - 1;\r\n  int lg = 1;\r\n  while ((1 <<\
    \ lg) < c_size) ++lg;\r\n  const int n = 1 << lg, hlf = n >> 1, qtr = hlf >> 1;\r\
    \n  std::vector<Complex> c(n);\r\n  for (int i = 0; i < a_size; ++i) {\r\n   \
    \ c[i].re = a[i];\r\n  }\r\n  for (int i = 0; i < b_size; ++i) {\r\n    c[i].im\
    \ = b[i];\r\n  }\r\n  dft(&c);\r\n  c.front() = Complex(c.front().re * c.front().im,\
    \ 0);\r\n  for (int i = 1; i < hlf; ++i) {\r\n    const Complex i_square = c[i]\
    \ * c[i], j_square = c[n - i] * c[n - i];\r\n    c[i] = (j_square.conj() - i_square).mul_pin(0.25);\r\
    \n    c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);\r\n  }\r\n  c[hlf]\
    \ = Complex(c[hlf].re * c[hlf].im, 0);\r\n  c.front() = (c.front() + c[hlf]\r\n\
    \               + (c.front() - c[hlf]).mul_pin(1)).mul_real(0.5);\r\n  const int\
    \ den = __builtin_ctz(hlf);\r\n  for (int i = 1; i < qtr; ++i) {\r\n    const\
    \ int j = hlf - i;\r\n    const Complex tmp1 = c[i] + c[j].conj();\r\n    const\
    \ Complex tmp2 = ((c[i] - c[j].conj()) * zeta[den][j]).mul_pin(1);\r\n    c[i]\
    \ = (tmp1 - tmp2).mul_real(0.5);\r\n    c[j] = (tmp1 + tmp2).mul_real(0.5).conj();\r\
    \n  }\r\n  if (qtr > 0) c[qtr] = c[qtr].conj();\r\n  c.resize(hlf);\r\n  idft(&c);\r\
    \n  std::vector<Real> res(c_size);\r\n  for (int i = 0; i < c_size; i += 2) {\r\
    \n    res[i] = c[i >> 1].re;\r\n  }\r\n  for (int i = 1; i < c_size; i += 2) {\r\
    \n    res[i] = c[i >> 1].im;\r\n  }\r\n  return res;\r\n}\r\n\r\n}  // namespace\
    \ fast_fourier_transform\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <cmath>\r\
    \n#include <iterator>\r\n#include <utility>\r\n#include <vector>\r\n\r\nnamespace\
    \ fast_fourier_transform {\r\n\r\nusing Real = double;\r\n\r\nstruct Complex {\r\
    \n  Real re, im;\r\n  explicit Complex(const Real re = 0, const Real im = 0) :\
    \ re(re), im(im) {}\r\n  inline Complex operator+(const Complex& x) const {\r\n\
    \    return Complex(re + x.re, im + x.im);\r\n  }\r\n  inline Complex operator-(const\
    \ Complex& x) const {\r\n    return Complex(re - x.re, im - x.im);\r\n  }\r\n\
    \  inline Complex operator*(const Complex& x) const {\r\n    return Complex(re\
    \ * x.re - im * x.im, re * x.im + im * x.re);\r\n  }\r\n  inline Complex mul_real(const\
    \ Real r) const {\r\n    return Complex(re * r, im * r);\r\n  }\r\n  inline Complex\
    \ mul_pin(const Real r) const {\r\n    return Complex(-im * r, re * r);\r\n  }\r\
    \n  inline Complex conj() const { return Complex(re, -im); }\r\n};\r\n\r\nstd::vector<int>\
    \ butterfly{0};\r\nstd::vector<std::vector<Complex>> zeta{{Complex(1, 0)}};\r\n\
    \r\nvoid init(const int n) {\r\n  const int prev_n = butterfly.size();\r\n  if\
    \ (n <= prev_n) return;\r\n  butterfly.resize(n);\r\n  const int prev_lg = zeta.size(),\
    \ lg = __builtin_ctz(n);\r\n  for (int i = 1; i < prev_n; ++i) {\r\n    butterfly[i]\
    \ <<= lg - prev_lg;\r\n  }\r\n  for (int i = prev_n; i < n; ++i) {\r\n    butterfly[i]\
    \ = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));\r\n  }\r\n  zeta.resize(lg);\r\
    \n  for (int i = prev_lg; i < lg; ++i) {\r\n    zeta[i].resize(1 << i);\r\n  \
    \  const Real angle = -3.14159265358979323846 * 2 / (1 << (i + 1));\r\n    for\
    \ (int j = 0; j < (1 << (i - 1)); ++j) {\r\n      zeta[i][j << 1] = zeta[i - 1][j];\r\
    \n      const Real theta = angle * ((j << 1) + 1);\r\n      zeta[i][(j << 1) +\
    \ 1] = Complex(std::cos(theta), std::sin(theta));\r\n    }\r\n  }\r\n}\r\n\r\n\
    void dft(std::vector<Complex>* a) {\r\n  const int n = a->size();\r\n  assert(__builtin_popcount(n)\
    \ == 1);\r\n  init(n);\r\n  const int shift = __builtin_ctz(butterfly.size())\
    \ - __builtin_ctz(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    const int j =\
    \ butterfly[i] >> shift;\r\n    if (i < j) std::swap((*a)[i], (*a)[j]);\r\n  }\r\
    \n  for (int block = 1, den = 0; block < n; block <<= 1, ++den) {\r\n    for (int\
    \ i = 0; i < n; i += (block << 1)) {\r\n      for (int j = 0; j < block; ++j)\
    \ {\r\n        const Complex tmp = (*a)[i + j + block] * zeta[den][j];\r\n   \
    \     (*a)[i + j + block] = (*a)[i + j] - tmp;\r\n        (*a)[i + j] = (*a)[i\
    \ + j] + tmp;\r\n      }\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\n\
    std::vector<Complex> real_dft(const std::vector<T>& a) {\r\n  const int n = a.size();\r\
    \n  int lg = 1;\r\n  while ((1 << lg) < n) ++lg;\r\n  std::vector<Complex> c(1\
    \ << lg);\r\n  for (int i = 0; i < n; ++i) {\r\n    c[i].re = a[i];\r\n  }\r\n\
    \  dft(&c);\r\n  return c;\r\n}\r\n\r\nvoid idft(std::vector<Complex>* a) {\r\n\
    \  const int n = a->size();\r\n  dft(a);\r\n  std::reverse(std::next(a->begin()),\
    \ a->end());\r\n  const Real r = 1. / n;\r\n  for (int i = 0; i < n; ++i) {\r\n\
    \    (*a)[i] = (*a)[i].mul_real(r);\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\
    \nstd::vector<Real> convolution(const std::vector<T>& a,\r\n                 \
    \             const std::vector<T>& b) {\r\n  const int a_size = a.size(), b_size\
    \ = b.size(), c_size = a_size + b_size - 1;\r\n  int lg = 1;\r\n  while ((1 <<\
    \ lg) < c_size) ++lg;\r\n  const int n = 1 << lg, hlf = n >> 1, qtr = hlf >> 1;\r\
    \n  std::vector<Complex> c(n);\r\n  for (int i = 0; i < a_size; ++i) {\r\n   \
    \ c[i].re = a[i];\r\n  }\r\n  for (int i = 0; i < b_size; ++i) {\r\n    c[i].im\
    \ = b[i];\r\n  }\r\n  dft(&c);\r\n  c.front() = Complex(c.front().re * c.front().im,\
    \ 0);\r\n  for (int i = 1; i < hlf; ++i) {\r\n    const Complex i_square = c[i]\
    \ * c[i], j_square = c[n - i] * c[n - i];\r\n    c[i] = (j_square.conj() - i_square).mul_pin(0.25);\r\
    \n    c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);\r\n  }\r\n  c[hlf]\
    \ = Complex(c[hlf].re * c[hlf].im, 0);\r\n  c.front() = (c.front() + c[hlf]\r\n\
    \               + (c.front() - c[hlf]).mul_pin(1)).mul_real(0.5);\r\n  const int\
    \ den = __builtin_ctz(hlf);\r\n  for (int i = 1; i < qtr; ++i) {\r\n    const\
    \ int j = hlf - i;\r\n    const Complex tmp1 = c[i] + c[j].conj();\r\n    const\
    \ Complex tmp2 = ((c[i] - c[j].conj()) * zeta[den][j]).mul_pin(1);\r\n    c[i]\
    \ = (tmp1 - tmp2).mul_real(0.5);\r\n    c[j] = (tmp1 + tmp2).mul_real(0.5).conj();\r\
    \n  }\r\n  if (qtr > 0) c[qtr] = c[qtr].conj();\r\n  c.resize(hlf);\r\n  idft(&c);\r\
    \n  std::vector<Real> res(c_size);\r\n  for (int i = 0; i < c_size; i += 2) {\r\
    \n    res[i] = c[i >> 1].re;\r\n  }\r\n  for (int i = 1; i < c_size; i += 2) {\r\
    \n    res[i] = c[i >> 1].im;\r\n  }\r\n  return res;\r\n}\r\n\r\n}  // namespace\
    \ fast_fourier_transform\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/fast_fourier_transform.hpp
  requiredBy:
  - math/convolution/mod_convolution.hpp
  timestamp: '2022-02-16 22:30:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/convolution/mod_convolution.test.cpp
  - test/math/convolution/fast_fourier_transform.test.cpp
  - test/math/formal_power_series/faulhaber_by_fps.test.cpp
  - test/math/formal_power_series/formal_power_series.5.test.cpp
  - test/graph/tree/centroid_decomposition.test.cpp
documentation_of: math/convolution/fast_fourier_transform.hpp
layout: document
title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
---

離散フーリエ変換 (discrete Fourier transform)

$$F(t) = \sum_{x = 0}^{N - 1} f(x) \zeta_N^{-tx} = \sum_{x = 0}^{N - 1} f(x) \exp\left(-i \frac{2 \pi tx}{N} \right)$$

を高速に行うアルゴリズムである．

畳み込み (convolution) $C_k = \sum_{i = 0}^k A_i B_{k - i}$ の計算にしばしば用いられる．



## 時間計算量

$O(N\log{N})$


## 使用法

- Cooley-Tukey algorithm

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

$$\overline{P_i} = \begin{cases} A_0 - B_0 \sqrt{-1} & (N = 0), \\ A_{N - i} - B_{N - i} \sqrt{-1} & (1 \leq i < N) \end{cases}$$

が成り立つ．$A_0, B_0 \in \mathbb{R},\ A_i = \overline{A_{n - i}}$ ($1 \leq i < N$) より

$$A_i = \begin{cases} \dfrac{P_0 + \overline{P_0}}{2} & (i = 0), \\ \dfrac{P_i + \overline{P_{N - i}}}{2} & (1 \leq i < N), \end{cases}$$

$$B_i = \begin{cases} \dfrac{P_0 - \overline{P_0}}{2 \sqrt{-1}} & (i = 0), \\ \dfrac{P_i - \overline{P_{N - i}}}{2 \sqrt{-1}} & (1 \leq i < N) \end{cases}$$

となる．$C_i = A_i B_i$ より

$$C_i = \begin{cases} \dfrac{P_0^2 - \overline{P_0}^2}{4 \sqrt{-1}} = \Re(P_0) \Im(P_0) & (i = 0), \\ \dfrac{P_i^2 - \overline{P_{N - i}}^2}{4 \sqrt{-1}} = (\overline{P_{N - i}^2} - P_i^2)\dfrac{\sqrt{-1}}{4} & (1 \leq i < N) \end{cases}$$

と変形できる．ここで $d_i = c_{2i} + c_{2i+1} \sqrt{-1}$ に離散フーリエ変換を行うと

$$C_i = \begin{cases} \Re(D_0) + \Im(D_0) & (i = 0), \\ D_i - (D_i - \overline{D_{\frac{N}{2} - i}}) \dfrac{1 + \xi_N^{-i} \sqrt{-1}}{2} & (1 \leq i \leq \frac{N}{4}), \end{cases}$$

$$\overline{C_{\frac{N}{2} - i}} = \begin{cases} \Re(D_0) - \Im(D_0) & (i = 0), \\ \overline{D_{\frac{N}{2} - i}} + (D_i - \overline{D_{\frac{N}{2} - i}}) \dfrac{1 + \xi_N^{-i} \sqrt{-1}}{2} & (1 \leq i \leq \frac{N}{4}) \end{cases}$$

となる．変形すると

- $i = 0$ に対して

$$D_0 = \frac{(C_0 + \overline{C_{\frac{N}{2}}}) + (C_0 - \overline{C_{\frac{N}{2}}}) \sqrt{-1}}{2} = \frac{(C_0 + C_{\frac{N}{2}}) + (C_0 - C_{\frac{N}{2}}) \sqrt{-1}}{2},$$

- $1 \leq i \leq \frac{N}{4}$ に対して

$$\begin{split} D_i &= \frac{(C_i + \overline{C_{\frac{N}{2} - i}}) - (C_i - \overline{C_{\frac{N}{2} - i}}) (-\xi_N^i) \sqrt{-1}}{2} = \frac{(C_i + \overline{C_{\frac{N}{2} - i}}) - (C_i - \overline{C_{\frac{N}{2} - i}}) \xi_N^{-(\frac{N}{2} - i)} \sqrt{-1}}{2}, \\ \overline{D_{\frac{N}{2} - i}} &= \frac{(C_i + \overline{C_{\frac{N}{2} - i}}) + (C_i - \overline{C_{\frac{N}{2} - i}}) (-\xi_N^i) \sqrt{-1}}{2} = \frac{(C_i + \overline{C_{\frac{N}{2} - i}}) + (C_i - \overline{C_{\frac{N}{2} - i}}) \xi_N^{-(\frac{N}{2} - i)} \sqrt{-1}}{2} \end{split}$$

となる．$C$ は既に求めたので $D$ に対して逆離散フーリエ変換を行えばよい．


## 参考

- https://www.slideshare.net/chokudai/fft-49066791
- ~~https://lumakernel.github.io/ecasdqina/math/FFT/introduction~~
- https://www.creativ.xyz/fast-fourier-transform
- ~~https://lumakernel.github.io/ecasdqina/math/FFT/standard~~
- http://xn--w6q13e505b.jp/method/fft/rft.html
- https://ei1333.github.io/luzhiled/snippets/math/fast-fourier-transform.html


## ToDo

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
