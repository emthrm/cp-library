---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30D5\u30FC\
      \u30EA\u30A8\u5909\u63DB"
    links:
    - https://atcoder.jp/contests/atc001/tasks/fft_c
  bundledCode: "#line 1 \"test/math/convolution/fast_fourier_transform.test.cpp\"\n\
    /*\r\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/atc001/tasks/fft_c\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"math/convolution/fast_fourier_transform.hpp\"\
    \n#include <algorithm>\r\n#include <cassert>\r\n#include <cmath>\r\n#include <utility>\r\
    \n#line 7 \"math/convolution/fast_fourier_transform.hpp\"\n\r\nnamespace fast_fourier_transform\
    \ {\r\nusing Real = double;\r\nstruct Complex {\r\n  Real re, im;\r\n  Complex(Real\
    \ re = 0, Real im = 0) : re(re), im(im) {}\r\n  inline Complex operator+(const\
    \ Complex &x) const { return Complex(re + x.re, im + x.im); }\r\n  inline Complex\
    \ operator-(const Complex &x) const { return Complex(re - x.re, im - x.im); }\r\
    \n  inline Complex operator*(const Complex &x) const { return Complex(re * x.re\
    \ - im * x.im, re * x.im + im * x.re); }\r\n  inline Complex mul_real(Real r)\
    \ const { return Complex(re * r, im * r); }\r\n  inline Complex mul_pin(Real r)\
    \ const { return Complex(-im * r, re * r); }\r\n  inline Complex conj() const\
    \ { return Complex(re, -im); }\r\n};\r\n\r\nstd::vector<int> butterfly{0};\r\n\
    std::vector<std::vector<Complex>> zeta{{{1, 0}}};\r\n\r\nvoid init(int n) {\r\n\
    \  const int prev_n = butterfly.size();\r\n  if (n <= prev_n) return;\r\n  butterfly.resize(n);\r\
    \n  const int prev = zeta.size(), lg = __builtin_ctz(n);\r\n  for (int i = 1;\
    \ i < prev_n; ++i) butterfly[i] <<= lg - prev;\r\n  for (int i = prev_n; i < n;\
    \ ++i) butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));\r\n  zeta.resize(lg);\r\
    \n  for (int i = prev; i < lg; ++i) {\r\n    zeta[i].resize(1 << i);\r\n    Real\
    \ angle = -3.14159265358979323846 * 2 / (1 << (i + 1));\r\n    for (int j = 0;\
    \ j < (1 << (i - 1)); ++j) {\r\n      zeta[i][j << 1] = zeta[i - 1][j];\r\n  \
    \    Real theta = angle * ((j << 1) + 1);\r\n      zeta[i][(j << 1) + 1] = {std::cos(theta),\
    \ std::sin(theta)};\r\n    }\r\n  }\r\n}\r\n\r\nvoid dft(std::vector<Complex>\
    \ &a) {\r\n  const int n = a.size();\r\n  assert(__builtin_popcount(n) == 1);\r\
    \n  init(n);\r\n  const int shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    const int j = butterfly[i] >> shift;\r\
    \n    if (i < j) std::swap(a[i], a[j]);\r\n  }\r\n  for (int block = 1, den =\
    \ 0; block < n; block <<= 1, ++den) {\r\n    for (int i = 0; i < n; i += (block\
    \ << 1)) for (int j = 0; j < block; ++j) {\r\n      Complex tmp = a[i + j + block]\
    \ * zeta[den][j];\r\n      a[i + j + block] = a[i + j] - tmp;\r\n      a[i + j]\
    \ = a[i + j] + tmp;\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nstd::vector<Complex>\
    \ real_dft(const std::vector<T> &a) {\r\n  const int n = a.size();\r\n  int lg\
    \ = 1;\r\n  while ((1 << lg) < n) ++lg;\r\n  std::vector<Complex> c(1 << lg);\r\
    \n  for (int i = 0; i < n; ++i) c[i].re = a[i];\r\n  dft(c);\r\n  return c;\r\n\
    }\r\n\r\nvoid idft(std::vector<Complex> &a) {\r\n  const int n = a.size();\r\n\
    \  dft(a);\r\n  std::reverse(a.begin() + 1, a.end());\r\n  Real r = 1.0 / n;\r\
    \n  for (int i = 0; i < n; ++i) a[i] = a[i].mul_real(r);\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nstd::vector<Real> convolution(const std::vector<T> &a, const\
    \ std::vector<T> &b) {\r\n  const int a_size = a.size(), b_size = b.size(), c_size\
    \ = a_size + b_size - 1;\r\n  int lg = 1;\r\n  while ((1 << lg) < c_size) ++lg;\r\
    \n  const int n = 1 << lg, half = n >> 1, quarter = half >> 1;\r\n  std::vector<Complex>\
    \ c(n);\r\n  for (int i = 0; i < a_size; ++i) c[i].re = a[i];\r\n  for (int i\
    \ = 0; i < b_size; ++i) c[i].im = b[i];\r\n  dft(c);\r\n  c[0] = Complex(c[0].re\
    \ * c[0].im, 0);\r\n  for (int i = 1; i < half; ++i) {\r\n    Complex i_square\
    \ = c[i] * c[i], j_square = c[n - i] * c[n - i];\r\n    c[i] = (j_square.conj()\
    \ - i_square).mul_pin(0.25);\r\n    c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);\r\
    \n  }\r\n  c[half] = Complex(c[half].re * c[half].im, 0);\r\n  c[0] = (c[0] +\
    \ c[half] + (c[0] - c[half]).mul_pin(1)).mul_real(0.5);\r\n  const int den = __builtin_ctz(half);\r\
    \n  for (int i = 1; i < quarter; ++i) {\r\n    const int j = half - i;\r\n   \
    \ Complex tmp1 = c[i] + c[j].conj(), tmp2 = ((c[i] - c[j].conj()) * zeta[den][j]).mul_pin(1);\r\
    \n    c[i] = (tmp1 - tmp2).mul_real(0.5);\r\n    c[j] = (tmp1 + tmp2).mul_real(0.5).conj();\r\
    \n  }\r\n  if (quarter > 0) c[quarter] = c[quarter].conj();\r\n  c.resize(half);\r\
    \n  idft(c);\r\n  std::vector<Real> res(c_size);\r\n  for (int i = 0; i < c_size;\
    \ ++i) res[i] = (i & 1 ? c[i >> 1].im : c[i >> 1].re);\r\n  return res;\r\n}\r\
    \n}  // fast_fourier_transform\r\n#line 10 \"test/math/convolution/fast_fourier_transform.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> a(n +\
    \ 1, 0), b(n + 1, 0);\r\n  for (int i = 1; i <= n; ++i) std::cin >> a[i] >> b[i];\r\
    \n  std::vector<fast_fourier_transform::Real> ans = fast_fourier_transform::convolution(a,\
    \ b);\r\n  for (int i = 1; i <= n * 2; ++i) std::cout << static_cast<long long>(ans[i]\
    \ + 0.5) << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/atc001/tasks/fft_c\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../math/convolution/fast_fourier_transform.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> a(n\
    \ + 1, 0), b(n + 1, 0);\r\n  for (int i = 1; i <= n; ++i) std::cin >> a[i] >>\
    \ b[i];\r\n  std::vector<fast_fourier_transform::Real> ans = fast_fourier_transform::convolution(a,\
    \ b);\r\n  for (int i = 1; i <= n * 2; ++i) std::cout << static_cast<long long>(ans[i]\
    \ + 0.5) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/convolution/fast_fourier_transform.hpp
  isVerificationFile: true
  path: test/math/convolution/fast_fourier_transform.test.cpp
  requiredBy: []
  timestamp: '2021-08-15 23:02:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/convolution/fast_fourier_transform.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/fast_fourier_transform.test.cpp
- /verify/test/math/convolution/fast_fourier_transform.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\
  \u5909\u63DB"
---
