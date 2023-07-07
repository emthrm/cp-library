---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/convolution/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  - icon: ':question:'
    path: include/emthrm/math/convolution/mod_convolution.hpp
    title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc135/tasks/abc135_d
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
      \u7684\u51AA\u7D1A\u6570 (mod_pow)"
    links:
    - https://atcoder.jp/contests/abc135/tasks/abc135_d
  bundledCode: "#line 1 \"test/math/formal_power_series/formal_power_series.5.test.cpp\"\
    \n/*\n * @title \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570 (mod_pow)\n *\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc135/tasks/abc135_d\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include\
    \ <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/math/convolution/mod_convolution.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/convolution/mod_convolution.hpp\"\n#include\
    \ <bit>\n#include <cmath>\n#line 8 \"include/emthrm/math/convolution/mod_convolution.hpp\"\
    \n\n#line 1 \"include/emthrm/math/convolution/fast_fourier_transform.hpp\"\n\n\
    \n\n#line 6 \"include/emthrm/math/convolution/fast_fourier_transform.hpp\"\n#include\
    \ <cassert>\n#line 8 \"include/emthrm/math/convolution/fast_fourier_transform.hpp\"\
    \n#include <iterator>\n#line 11 \"include/emthrm/math/convolution/fast_fourier_transform.hpp\"\
    \n\nnamespace emthrm {\n\nnamespace fast_fourier_transform {\n\nusing Real = double;\n\
    \nstruct Complex {\n  Real re, im;\n  explicit Complex(const Real re = 0, const\
    \ Real im = 0) : re(re), im(im) {}\n  inline Complex operator+(const Complex&\
    \ x) const {\n    return Complex(re + x.re, im + x.im);\n  }\n  inline Complex\
    \ operator-(const Complex& x) const {\n    return Complex(re - x.re, im - x.im);\n\
    \  }\n  inline Complex operator*(const Complex& x) const {\n    return Complex(re\
    \ * x.re - im * x.im, re * x.im + im * x.re);\n  }\n  inline Complex mul_real(const\
    \ Real r) const {\n    return Complex(re * r, im * r);\n  }\n  inline Complex\
    \ mul_pin(const Real r) const {\n    return Complex(-im * r, re * r);\n  }\n \
    \ inline Complex conj() const { return Complex(re, -im); }\n};\n\nstd::vector<int>\
    \ butterfly{0};\nstd::vector<std::vector<Complex>> zeta{{Complex(1, 0)}};\n\n\
    void init(const int n) {\n  const int prev_n = butterfly.size();\n  if (n <= prev_n)\
    \ return;\n  butterfly.resize(n);\n  const int prev_lg = zeta.size();\n  const\
    \ int lg = std::countr_zero(static_cast<unsigned int>(n));\n  for (int i = 1;\
    \ i < prev_n; ++i) {\n    butterfly[i] <<= lg - prev_lg;\n  }\n  for (int i =\
    \ prev_n; i < n; ++i) {\n    butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1)\
    \ << (lg - 1));\n  }\n  zeta.resize(lg);\n  for (int i = prev_lg; i < lg; ++i)\
    \ {\n    zeta[i].resize(1 << i);\n    const Real angle = -3.14159265358979323846\
    \ * 2 / (1 << (i + 1));\n    for (int j = 0; j < (1 << (i - 1)); ++j) {\n    \
    \  zeta[i][j << 1] = zeta[i - 1][j];\n      const Real theta = angle * ((j <<\
    \ 1) + 1);\n      zeta[i][(j << 1) + 1] = Complex(std::cos(theta), std::sin(theta));\n\
    \    }\n  }\n}\n\nvoid dft(std::vector<Complex>* a) {\n  assert(std::has_single_bit(a->size()));\n\
    \  const int n = a->size();\n  init(n);\n  const int shift =\n      std::countr_zero(butterfly.size())\
    \ - std::countr_zero(a->size());\n  for (int i = 0; i < n; ++i) {\n    const int\
    \ j = butterfly[i] >> shift;\n    if (i < j) std::swap((*a)[i], (*a)[j]);\n  }\n\
    \  for (int block = 1, den = 0; block < n; block <<= 1, ++den) {\n    for (int\
    \ i = 0; i < n; i += (block << 1)) {\n      for (int j = 0; j < block; ++j) {\n\
    \        const Complex tmp = (*a)[i + j + block] * zeta[den][j];\n        (*a)[i\
    \ + j + block] = (*a)[i + j] - tmp;\n        (*a)[i + j] = (*a)[i + j] + tmp;\n\
    \      }\n    }\n  }\n}\n\ntemplate <typename T>\nstd::vector<Complex> real_dft(const\
    \ std::vector<T>& a) {\n  const int n = a.size();\n  std::vector<Complex> c(std::bit_ceil(a.size()));\n\
    \  for (int i = 0; i < n; ++i) {\n    c[i].re = a[i];\n  }\n  dft(&c);\n  return\
    \ c;\n}\n\nvoid idft(std::vector<Complex>* a) {\n  const int n = a->size();\n\
    \  dft(a);\n  std::reverse(std::next(a->begin()), a->end());\n  const Real r =\
    \ 1. / n;\n  std::transform(a->begin(), a->end(), a->begin(),\n              \
    \   [r](const Complex& c) -> Complex { return c.mul_real(r); });\n}\n\ntemplate\
    \ <typename T>\nstd::vector<Real> convolution(const std::vector<T>& a,\n     \
    \                         const std::vector<T>& b) {\n  const int a_size = a.size(),\
    \ b_size = b.size(), c_size = a_size + b_size - 1;\n  const int n = std::max(std::bit_ceil(static_cast<unsigned\
    \ int>(c_size)), 2U);\n  const int hlf = n >> 1, qtr = hlf >> 1;\n  std::vector<Complex>\
    \ c(n);\n  for (int i = 0; i < a_size; ++i) {\n    c[i].re = a[i];\n  }\n  for\
    \ (int i = 0; i < b_size; ++i) {\n    c[i].im = b[i];\n  }\n  dft(&c);\n  c.front()\
    \ = Complex(c.front().re * c.front().im, 0);\n  for (int i = 1; i < hlf; ++i)\
    \ {\n    const Complex i_square = c[i] * c[i], j_square = c[n - i] * c[n - i];\n\
    \    c[i] = (j_square.conj() - i_square).mul_pin(0.25);\n    c[n - i] = (i_square.conj()\
    \ - j_square).mul_pin(0.25);\n  }\n  c[hlf] = Complex(c[hlf].re * c[hlf].im, 0);\n\
    \  c.front() = (c.front() + c[hlf]\n               + (c.front() - c[hlf]).mul_pin(1)).mul_real(0.5);\n\
    \  const int den = std::countr_zero(static_cast<unsigned int>(hlf));\n  for (int\
    \ i = 1; i < qtr; ++i) {\n    const int j = hlf - i;\n    const Complex tmp1 =\
    \ c[i] + c[j].conj();\n    const Complex tmp2 = ((c[i] - c[j].conj()) * zeta[den][j]).mul_pin(1);\n\
    \    c[i] = (tmp1 - tmp2).mul_real(0.5);\n    c[j] = (tmp1 + tmp2).mul_real(0.5).conj();\n\
    \  }\n  if (qtr > 0) c[qtr] = c[qtr].conj();\n  c.resize(hlf);\n  idft(&c);\n\
    \  std::vector<Real> res(c_size);\n  for (int i = 0; i < c_size; i += 2) {\n \
    \   res[i] = c[i >> 1].re;\n  }\n  for (int i = 1; i < c_size; i += 2) {\n   \
    \ res[i] = c[i >> 1].im;\n  }\n  return res;\n}\n\n}  // namespace fast_fourier_transform\n\
    \n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\
    \n#ifndef ARBITRARY_MODINT\n#line 6 \"include/emthrm/math/modint.hpp\"\n#endif\n\
    #include <compare>\n#line 9 \"include/emthrm/math/modint.hpp\"\n// #include <numeric>\n\
    #line 12 \"include/emthrm/math/modint.hpp\"\n\nnamespace emthrm {\n\n#ifndef ARBITRARY_MODINT\n\
    template <unsigned int M>\nstruct MInt {\n  unsigned int v;\n\n  constexpr MInt()\
    \ : v(0) {}\n  constexpr MInt(const long long x) : v(x >= 0 ? x % M : x % M +\
    \ M) {}\n  static constexpr MInt raw(const int x) {\n    MInt x_;\n    x_.v =\
    \ x;\n    return x_;\n  }\n\n  static constexpr int get_mod() { return M; }\n\
    \  static constexpr void set_mod(const int divisor) {\n    assert(std::cmp_equal(divisor,\
    \ M));\n  }\n\n  static void init(const int x) {\n    inv<true>(x);\n    fact(x);\n\
    \    fact_inv(x);\n  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const\
    \ int n) {\n    // assert(0 <= n && n < M && std::gcd(n, M) == 1);\n    static\
    \ std::vector<MInt> inverse{0, 1};\n    const int prev = inverse.size();\n   \
    \ if (n < prev) return inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"\
    n!\" and \"M\" must be disjoint.\n      inverse.resize(n + 1);\n      for (int\
    \ i = prev; i <= n; ++i) {\n        inverse[i] = -inverse[M % i] * raw(M / i);\n\
    \      }\n      return inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned\
    \ int a = n, b = M; b;) {\n      const unsigned int q = a / b;\n      std::swap(a\
    \ -= q * b, b);\n      std::swap(u -= q * v, v);\n    }\n    return u;\n  }\n\n\
    \  static MInt fact(const int n) {\n    static std::vector<MInt> factorial{1};\n\
    \    if (const int prev = factorial.size(); n >= prev) {\n      factorial.resize(n\
    \ + 1);\n      for (int i = prev; i <= n; ++i) {\n        factorial[i] = factorial[i\
    \ - 1] * i;\n      }\n    }\n    return factorial[n];\n  }\n\n  static MInt fact_inv(const\
    \ int n) {\n    static std::vector<MInt> f_inv{1};\n    if (const int prev = f_inv.size();\
    \ n >= prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n\
    \      for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n\
    \      }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
    \ int k) {\n    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();\n   \
    \ return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :\n            \
    \                      fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const\
    \ int n, const int k) {\n    return n < 0 || n < k || k < 0 ? MInt() : fact(n)\
    \ * fact_inv(n - k);\n  }\n  static MInt nHk(const int n, const int k) {\n   \
    \ return n < 0 || k < 0 ? MInt() : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n\
    \  static MInt large_nCk(long long n, const int k) {\n    if (n < 0 || n < k ||\
    \ k < 0) [[unlikely]] return MInt();\n    inv<true>(k);\n    MInt res = 1;\n \
    \   for (int i = 1; i <= k; ++i) {\n      res *= inv(i) * n--;\n    }\n    return\
    \ res;\n  }\n\n  constexpr MInt pow(long long exponent) const {\n    MInt res\
    \ = 1, tmp = *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent\
    \ & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  constexpr\
    \ MInt& operator+=(const MInt& x) {\n    if ((v += x.v) >= M) v -= M;\n    return\
    \ *this;\n  }\n  constexpr MInt& operator-=(const MInt& x) {\n    if ((v += M\
    \ - x.v) >= M) v -= M;\n    return *this;\n  }\n  constexpr MInt& operator*=(const\
    \ MInt& x) {\n    v = (unsigned long long){v} * x.v % M;\n    return *this;\n\
    \  }\n  MInt& operator/=(const MInt& x) { return *this *= inv(x.v); }\n\n  constexpr\
    \ auto operator<=>(const MInt& x) const = default;\n\n  constexpr MInt& operator++()\
    \ {\n    if (++v == M) [[unlikely]] v = 0;\n    return *this;\n  }\n  constexpr\
    \ MInt operator++(int) {\n    const MInt res = *this;\n    ++*this;\n    return\
    \ res;\n  }\n  constexpr MInt& operator--() {\n    v = (v == 0 ? M - 1 : v - 1);\n\
    \    return *this;\n  }\n  constexpr MInt operator--(int) {\n    const MInt res\
    \ = *this;\n    --*this;\n    return res;\n  }\n\n  constexpr MInt operator+()\
    \ const { return *this; }\n  constexpr MInt operator-() const { return raw(v ?\
    \ M - v : 0); }\n\n  constexpr MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  constexpr MInt operator-(const MInt& x) const { return MInt(*this)\
    \ -= x; }\n  constexpr MInt operator*(const MInt& x) const { return MInt(*this)\
    \ *= x; }\n  MInt operator/(const MInt& x) const { return MInt(*this) /= x; }\n\
    \n  friend std::ostream& operator<<(std::ostream& os, const MInt& x) {\n    return\
    \ os << x.v;\n  }\n  friend std::istream& operator>>(std::istream& is, MInt& x)\
    \ {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return is;\n  }\n};\n\
    #else  // ARBITRARY_MODINT\ntemplate <int ID>\nstruct MInt {\n  unsigned int v;\n\
    \n  constexpr MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0 ? x % mod()\
    \ : x % mod() + mod()) {}\n  static constexpr MInt raw(const int x) {\n    MInt\
    \ x_;\n    x_.v = x;\n    return x_;\n  }\n\n  static int get_mod() { return mod();\
    \ }\n  static void set_mod(const unsigned int divisor) { mod() = divisor; }\n\n\
    \  static void init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n\
    \  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n\
    \    // assert(0 <= n && n < mod() && std::gcd(x, mod()) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[mod() % i] * raw(mod() / i);\n      }\n   \
    \   return inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned int a\
    \ = n, b = mod(); b;) {\n      const unsigned int q = a / b;\n      std::swap(a\
    \ -= q * b, b);\n      std::swap(u -= q * v, v);\n    }\n    return u;\n  }\n\n\
    \  static MInt fact(const int n) {\n    static std::vector<MInt> factorial{1};\n\
    \    if (const int prev = factorial.size(); n >= prev) {\n      factorial.resize(n\
    \ + 1);\n      for (int i = prev; i <= n; ++i) {\n        factorial[i] = factorial[i\
    \ - 1] * i;\n      }\n    }\n    return factorial[n];\n  }\n\n  static MInt fact_inv(const\
    \ int n) {\n    static std::vector<MInt> f_inv{1};\n    if (const int prev = f_inv.size();\
    \ n >= prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n\
    \      for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n\
    \      }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
    \ int k) {\n    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();\n   \
    \ return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :\n            \
    \                      fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const\
    \ int n, const int k) {\n    return n < 0 || n < k || k < 0 ? MInt() : fact(n)\
    \ * fact_inv(n - k);\n  }\n  static MInt nHk(const int n, const int k) {\n   \
    \ return n < 0 || k < 0 ? MInt() : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n\
    \  static MInt large_nCk(long long n, const int k) {\n    if (n < 0 || n < k ||\
    \ k < 0) [[unlikely]] return MInt();\n    inv<true>(k);\n    MInt res = 1;\n \
    \   for (int i = 1; i <= k; ++i) {\n      res *= inv(i) * n--;\n    }\n    return\
    \ res;\n  }\n\n  MInt pow(long long exponent) const {\n    MInt res = 1, tmp =\
    \ *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1)\
    \ res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  MInt& operator+=(const\
    \ MInt& x) {\n    if ((v += x.v) >= mod()) v -= mod();\n    return *this;\n  }\n\
    \  MInt& operator-=(const MInt& x) {\n    if ((v += mod() - x.v) >= mod()) v -=\
    \ mod();\n    return *this;\n  }\n  MInt& operator*=(const MInt& x) {\n    v =\
    \ (unsigned long long){v} * x.v % mod();\n    return *this;\n    }\n  MInt& operator/=(const\
    \ MInt& x) { return *this *= inv(x.v); }\n\n  auto operator<=>(const MInt& x)\
    \ const = default;\n\n  MInt& operator++() {\n    if (++v == mod()) [[unlikely]]\
    \ v = 0;\n    return *this;\n  }\n  MInt operator++(int) {\n    const MInt res\
    \ = *this;\n    ++*this;\n    return res;\n  }\n  MInt& operator--() {\n    v\
    \ = (v == 0 ? mod() - 1 : v - 1);\n    return *this;\n  }\n  MInt operator--(int)\
    \ {\n    const MInt res = *this;\n    --*this;\n    return res;\n  }\n\n  MInt\
    \ operator+() const { return *this; }\n  MInt operator-() const { return raw(v\
    \ ? mod() - v : 0); }\n\n  MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  MInt operator-(const MInt& x) const { return MInt(*this) -= x; }\n\
    \  MInt operator*(const MInt& x) const { return MInt(*this) *= x; }\n  MInt operator/(const\
    \ MInt& x) const { return MInt(*this) /= x; }\n\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const MInt& x) {\n    return os << x.v;\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return\
    \ is;\n  }\n\n private:\n  static unsigned int& mod() {\n    static unsigned int\
    \ divisor = 0;\n    return divisor;\n  }\n};\n#endif  // ARBITRARY_MODINT\n\n\
    }  // namespace emthrm\n\n\n#line 11 \"include/emthrm/math/convolution/mod_convolution.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int PRECISION = 15, unsigned int T>\nstd::vector<MInt<T>>\
    \ mod_convolution(const std::vector<MInt<T>>& a,\n                           \
    \          const std::vector<MInt<T>>& b) {\n  using ModInt = MInt<T>;\n  const\
    \ int a_size = a.size(), b_size = b.size(), c_size = a_size + b_size - 1;\n  const\
    \ int n = std::max(std::bit_ceil(static_cast<unsigned int>(c_size)), 2U);\n  constexpr\
    \ int mask = (1 << PRECISION) - 1;\n  std::vector<fast_fourier_transform::Complex>\
    \ x(n), y(n);\n  std::transform(\n      a.begin(), a.end(), x.begin(),\n     \
    \ [mask](const MInt<T>& x) -> fast_fourier_transform::Complex {\n        return\
    \ fast_fourier_transform::Complex(x.v & mask, x.v >> PRECISION);\n      });\n\
    \  fast_fourier_transform::dft(&x);\n  std::transform(\n      b.begin(), b.end(),\
    \ y.begin(),\n      [mask](const MInt<T>& y) -> fast_fourier_transform::Complex\
    \ {\n        return fast_fourier_transform::Complex(y.v & mask, y.v >> PRECISION);\n\
    \      });\n  fast_fourier_transform::dft(&y);\n  const int half = n >> 1;\n \
    \ fast_fourier_transform::Complex tmp_a = x.front(), tmp_b = y.front();\n  x.front()\
    \ =\n      fast_fourier_transform::Complex(tmp_a.re * tmp_b.re, tmp_a.im * tmp_b.im);\n\
    \  y.front() =\n      fast_fourier_transform::Complex(\n          tmp_a.re * tmp_b.im\
    \ + tmp_a.im * tmp_b.re, 0);\n  for (int i = 1; i < half; ++i) {\n    const int\
    \ j = n - i;\n    const fast_fourier_transform::Complex a_l_i =\n        (x[i]\
    \ + x[j].conj()).mul_real(0.5);\n    const fast_fourier_transform::Complex a_h_i\
    \ =\n        (x[j].conj() - x[i]).mul_pin(0.5);\n    const fast_fourier_transform::Complex\
    \ b_l_i =\n        (y[i] + y[j].conj()).mul_real(0.5);\n    const fast_fourier_transform::Complex\
    \ b_h_i =\n        (y[j].conj() - y[i]).mul_pin(0.5);\n    const fast_fourier_transform::Complex\
    \ a_l_j =\n        (x[j] + x[i].conj()).mul_real(0.5);\n    const fast_fourier_transform::Complex\
    \ a_h_j =\n        (x[i].conj() - x[j]).mul_pin(0.5);\n    const fast_fourier_transform::Complex\
    \ b_l_j =\n        (y[j] + y[i].conj()).mul_real(0.5);\n    const fast_fourier_transform::Complex\
    \ b_h_j =\n        (y[i].conj() - y[j]).mul_pin(0.5);\n    x[i] = a_l_i * b_l_i\
    \ + (a_h_i * b_h_i).mul_pin(1);\n    y[i] = a_l_i * b_h_i + a_h_i * b_l_i;\n \
    \   x[j] = a_l_j * b_l_j + (a_h_j * b_h_j).mul_pin(1);\n    y[j] = a_l_j * b_h_j\
    \ + a_h_j * b_l_j;\n  }\n  tmp_a = x[half];\n  tmp_b = y[half];\n  x[half] = fast_fourier_transform::Complex(\n\
    \      tmp_a.re * tmp_b.re, tmp_a.im * tmp_b.im);\n  y[half] = fast_fourier_transform::Complex(\n\
    \      tmp_a.re * tmp_b.im + tmp_a.im * tmp_b.re, 0);\n  fast_fourier_transform::idft(&x);\n\
    \  fast_fourier_transform::idft(&y);\n  std::vector<ModInt> res(c_size);\n  const\
    \ ModInt tmp1 = 1 << PRECISION, tmp2 = 1LL << (PRECISION << 1);\n  for (int i\
    \ = 0; i < c_size; ++i) {\n    res[i] = tmp1 * std::llround(y[i].re) + tmp2 *\
    \ std::llround(x[i].im)\n             + std::llround(x[i].re);\n  }\n  return\
    \ res;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n#include <functional>\n#include <initializer_list>\n#line 9 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n#include <numeric>\n#line 11 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct FormalPowerSeries {\n\
    \  std::vector<T> coef;\n\n  explicit FormalPowerSeries(const int deg = 0) : coef(deg\
    \ + 1, 0) {}\n  explicit FormalPowerSeries(const std::vector<T>& coef) : coef(coef)\
    \ {}\n  FormalPowerSeries(const std::initializer_list<T> init)\n      : coef(init.begin(),\
    \ init.end()) {}\n  template <typename InputIter>\n  explicit FormalPowerSeries(const\
    \ InputIter first, const InputIter last)\n      : coef(first, last) {}\n\n  inline\
    \ const T& operator[](const int term) const { return coef[term]; }\n  inline T&\
    \ operator[](const int term) { return coef[term]; }\n\n  using Mult = std::function<std::vector<T>(const\
    \ std::vector<T>&,\n                                            const std::vector<T>&)>;\n\
    \  using Sqrt = std::function<bool(const T&, T*)>;\n  static void set_mult(const\
    \ Mult mult) { get_mult() = mult; }\n  static void set_sqrt(const Sqrt sqrt) {\
    \ get_sqrt() = sqrt; }\n\n  void resize(const int deg) { coef.resize(deg + 1,\
    \ 0); }\n  void shrink() {\n    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();\n\
    \  }\n  int degree() const { return std::ssize(coef) - 1; }\n\n  FormalPowerSeries&\
    \ operator=(const std::vector<T>& coef_) {\n    coef = coef_;\n    return *this;\n\
    \  }\n  FormalPowerSeries& operator=(const FormalPowerSeries& x) = default;\n\n\
    \  FormalPowerSeries& operator+=(const FormalPowerSeries& x) {\n    const int\
    \ deg_x = x.degree();\n    if (deg_x > degree()) resize(deg_x);\n    for (int\
    \ i = 0; i <= deg_x; ++i) {\n      coef[i] += x[i];\n    }\n    return *this;\n\
    \  }\n  FormalPowerSeries& operator-=(const FormalPowerSeries& x) {\n    const\
    \ int deg_x = x.degree();\n    if (deg_x > degree()) resize(deg_x);\n    for (int\
    \ i = 0; i <= deg_x; ++i) {\n      coef[i] -= x[i];\n    }\n    return *this;\n\
    \  }\n  FormalPowerSeries& operator*=(const T x) {\n    for (T& e : coef) e *=\
    \ x;\n    return *this;\n  }\n  FormalPowerSeries& operator*=(const FormalPowerSeries&\
    \ x) {\n    return *this = get_mult()(coef, x.coef);\n  }\n  FormalPowerSeries&\
    \ operator/=(const T x) {\n    assert(x != 0);\n    return *this *= static_cast<T>(1)\
    \ / x;\n  }\n  FormalPowerSeries& operator/=(const FormalPowerSeries& x) {\n \
    \   const int n = degree() - x.degree() + 1;\n    if (n <= 0) return *this = FormalPowerSeries();\n\
    \    const std::vector<T> tmp = get_mult()(\n        std::vector<T>(coef.rbegin(),\
    \ std::next(coef.rbegin(), n)),\n        FormalPowerSeries(\n            x.coef.rbegin(),\n\
    \            std::next(x.coef.rbegin(), std::min(x.degree() + 1, n)))\n      \
    \  .inv(n - 1).coef);\n    return *this = FormalPowerSeries(std::prev(tmp.rend(),\
    \ n), tmp.rend());\n  }\n  FormalPowerSeries& operator%=(const FormalPowerSeries&\
    \ x) {\n    if (x.degree() == 0) return *this = FormalPowerSeries{0};\n    *this\
    \ -= *this / x * x;\n    resize(x.degree() - 1);\n    return *this;\n  }\n  FormalPowerSeries&\
    \ operator<<=(const int n) {\n    coef.insert(coef.begin(), n, 0);\n    return\
    \ *this;\n  }\n  FormalPowerSeries& operator>>=(const int n) {\n    if (degree()\
    \ < n) return *this = FormalPowerSeries();\n    coef.erase(coef.begin(), coef.begin()\
    \ + n);\n    return *this;\n  }\n\n  bool operator==(FormalPowerSeries x) const\
    \ {\n    x.shrink();\n    FormalPowerSeries y = *this;\n    y.shrink();\n    return\
    \ x.coef == y.coef;\n  }\n\n  FormalPowerSeries operator+() const { return *this;\
    \ }\n  FormalPowerSeries operator-() const {\n    FormalPowerSeries res = *this;\n\
    \    for (T& e : res.coef) e = -e;\n    return res;\n  }\n\n  FormalPowerSeries\
    \ operator+(const FormalPowerSeries& x) const {\n    return FormalPowerSeries(*this)\
    \ += x;\n  }\n  FormalPowerSeries operator-(const FormalPowerSeries& x) const\
    \ {\n    return FormalPowerSeries(*this) -= x;\n  }\n  FormalPowerSeries operator*(const\
    \ T x) const {\n    return FormalPowerSeries(*this) *= x;\n  }\n  FormalPowerSeries\
    \ operator*(const FormalPowerSeries& x) const {\n    return FormalPowerSeries(*this)\
    \ *= x;\n  }\n  FormalPowerSeries operator/(const T x) const {\n    return FormalPowerSeries(*this)\
    \ /= x;\n  }\n  FormalPowerSeries operator/(const FormalPowerSeries& x) const\
    \ {\n    return FormalPowerSeries(*this) /= x;\n  }\n  FormalPowerSeries operator%(const\
    \ FormalPowerSeries& x) const {\n    return FormalPowerSeries(*this) %= x;\n \
    \ }\n  FormalPowerSeries operator<<(const int n) const {\n    return FormalPowerSeries(*this)\
    \ <<= n;\n  }\n  FormalPowerSeries operator>>(const int n) const {\n    return\
    \ FormalPowerSeries(*this) >>= n;\n  }\n\n  T horner(const T x) const {\n    return\
    \ std::accumulate(\n        coef.rbegin(), coef.rend(), static_cast<T>(0),\n \
    \       [x](const T l, const T r) -> T { return l * x + r; });\n  }\n\n  FormalPowerSeries\
    \ differential() const {\n    const int deg = degree();\n    assert(deg >= 0);\n\
    \    FormalPowerSeries res(std::max(deg - 1, 0));\n    for (int i = 1; i <= deg;\
    \ ++i) {\n      res[i - 1] = coef[i] * i;\n    }\n    return res;\n  }\n\n  FormalPowerSeries\
    \ exp(const int deg) const {\n    assert(coef[0] == 0);\n    const int n = coef.size();\n\
    \    const FormalPowerSeries one{1};\n    FormalPowerSeries res = one;\n    for\
    \ (int i = 1; i <= deg; i <<= 1) {\n      res *= FormalPowerSeries(coef.begin(),\n\
    \                               std::next(coef.begin(), std::min(n, i << 1)))\n\
    \             - res.log((i << 1) - 1) + one;\n      res.coef.resize(i << 1);\n\
    \    }\n    res.resize(deg);\n    return res;\n  }\n  FormalPowerSeries exp()\
    \ const { return exp(degree()); }\n\n  FormalPowerSeries inv(const int deg) const\
    \ {\n    assert(coef[0] != 0);\n    const int n = coef.size();\n    FormalPowerSeries\
    \ res{static_cast<T>(1) / coef[0]};\n    for (int i = 1; i <= deg; i <<= 1) {\n\
    \      res = res + res - res * res * FormalPowerSeries(\n          coef.begin(),\
    \ std::next(coef.begin(), std::min(n, i << 1)));\n      res.coef.resize(i << 1);\n\
    \    }\n    res.resize(deg);\n    return res;\n  }\n  FormalPowerSeries inv()\
    \ const { return inv(degree()); }\n\n  FormalPowerSeries log(const int deg) const\
    \ {\n    assert(coef[0] == 1);\n    FormalPowerSeries integrand = differential()\
    \ * inv(deg - 1);\n    integrand.resize(deg);\n    for (int i = deg; i > 0; --i)\
    \ {\n      integrand[i] = integrand[i - 1] / i;\n    }\n    integrand[0] = 0;\n\
    \    return integrand;\n  }\n  FormalPowerSeries log() const { return log(degree());\
    \ }\n\n  FormalPowerSeries pow(long long exponent, const int deg) const {\n  \
    \  const int n = coef.size();\n    if (exponent == 0) {\n      FormalPowerSeries\
    \ res(deg);\n      if (deg != -1) [[unlikely]] res[0] = 1;\n      return res;\n\
    \    }\n    assert(deg >= 0);\n    for (int i = 0; i < n; ++i) {\n      if (coef[i]\
    \ == 0) continue;\n      if (i > deg / exponent) break;\n      const long long\
    \ shift = exponent * i;\n      T tmp = 1, base = coef[i];\n      for (long long\
    \ e = exponent; e > 0; e >>= 1) {\n        if (e & 1) tmp *= base;\n        base\
    \ *= base;\n      }\n      const FormalPowerSeries res = ((*this >> i) / coef[i]).log(deg\
    \ - shift);\n      return ((res * exponent).exp(deg - shift) * tmp) << shift;\n\
    \    }\n    return FormalPowerSeries(deg);\n  }\n  FormalPowerSeries pow(const\
    \ long long exponent) const {\n    return pow(exponent, degree());\n  }\n\n  FormalPowerSeries\
    \ mod_pow(long long exponent,\n                            const FormalPowerSeries&\
    \ md) const {\n    const int deg = md.degree() - 1;\n    if (deg < 0) [[unlikely]]\
    \ return FormalPowerSeries(-1);\n    const FormalPowerSeries inv_rev_md =\n  \
    \      FormalPowerSeries(md.coef.rbegin(), md.coef.rend()).inv();\n    const auto\
    \ mod_mult = [&md, &inv_rev_md, deg](\n        FormalPowerSeries* multiplicand,\
    \ const FormalPowerSeries& multiplier)\n        -> void {\n      *multiplicand\
    \ *= multiplier;\n      if (deg < multiplicand->degree()) {\n        const int\
    \ n = multiplicand->degree() - deg;\n        const FormalPowerSeries quotient\
    \ =\n            FormalPowerSeries(multiplicand->coef.rbegin(),\n            \
    \                  std::next(multiplicand->coef.rbegin(), n))\n            * FormalPowerSeries(\n\
    \                  inv_rev_md.coef.begin(),\n                  std::next(inv_rev_md.coef.begin(),\
    \ std::min(deg + 2, n)));\n        *multiplicand -=\n            FormalPowerSeries(std::prev(quotient.coef.rend(),\
    \ n),\n                              quotient.coef.rend()) * md;\n        multiplicand->resize(deg);\n\
    \      }\n      multiplicand->shrink();\n    };\n    FormalPowerSeries res{1},\
    \ base = *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent\
    \ & 1) mod_mult(&res, base);\n      mod_mult(&base, base);\n    }\n    return\
    \ res;\n  }\n\n  FormalPowerSeries sqrt(const int deg) const {\n    const int\
    \ n = coef.size();\n    if (coef[0] == 0) {\n      for (int i = 1; i < n; ++i)\
    \ {\n        if (coef[i] == 0) continue;\n        if (i & 1) return FormalPowerSeries(-1);\n\
    \        const int shift = i >> 1;\n        if (deg < shift) break;\n        FormalPowerSeries\
    \ res = (*this >> i).sqrt(deg - shift);\n        if (res.coef.empty()) return\
    \ FormalPowerSeries(-1);\n        res <<= shift;\n        res.resize(deg);\n \
    \       return res;\n      }\n      return FormalPowerSeries(deg);\n    }\n  \
    \  T s;\n    if (!get_sqrt()(coef.front(), &s)) return FormalPowerSeries(-1);\n\
    \    FormalPowerSeries res{s};\n    const T half = static_cast<T>(1) / 2;\n  \
    \  for (int i = 1; i <= deg; i <<= 1) {\n      res = (FormalPowerSeries(coef.begin(),\n\
    \                               std::next(coef.begin(), std::min(n, i << 1)))\n\
    \             * res.inv((i << 1) - 1) + res) * half;\n    }\n    res.resize(deg);\n\
    \    return res;\n  }\n  FormalPowerSeries sqrt() const { return sqrt(degree());\
    \ }\n\n  FormalPowerSeries translate(const T c) const {\n    const int n = coef.size();\n\
    \    std::vector<T> fact(n, 1), inv_fact(n, 1);\n    for (int i = 1; i < n; ++i)\
    \ {\n      fact[i] = fact[i - 1] * i;\n    }\n    inv_fact[n - 1] = static_cast<T>(1)\
    \ / fact[n - 1];\n    for (int i = n - 1; i > 0; --i) {\n      inv_fact[i - 1]\
    \ = inv_fact[i] * i;\n    }\n    std::vector<T> g(n), ex(n);\n    for (int i =\
    \ 0; i < n; ++i) {\n      g[i] = coef[i] * fact[i];\n    }\n    std::reverse(g.begin(),\
    \ g.end());\n    T pow_c = 1;\n    for (int i = 0; i < n; ++i) {\n      ex[i]\
    \ = pow_c * inv_fact[i];\n      pow_c *= c;\n    }\n    const std::vector<T> conv\
    \ = get_mult()(g, ex);\n    FormalPowerSeries res(n - 1);\n    for (int i = 0;\
    \ i < n; ++i) {\n      res[i] = conv[n - 1 - i] * inv_fact[i];\n    }\n    return\
    \ res;\n  }\n\n private:\n  static Mult& get_mult() {\n    static Mult mult =\
    \ [](const std::vector<T>& a, const std::vector<T>& b)\n        -> std::vector<T>\
    \ {\n      const int n = a.size(), m = b.size();\n      std::vector<T> res(n +\
    \ m - 1, 0);\n      for (int i = 0; i < n; ++i) {\n        for (int j = 0; j <\
    \ m; ++j) {\n          res[i + j] += a[i] * b[j];\n        }\n      }\n      return\
    \ res;\n    };\n    return mult;\n  }\n  static Sqrt& get_sqrt() {\n    static\
    \ Sqrt sqrt = [](const T&, T*) -> bool { return false; };\n    return sqrt;\n\
    \  }\n};\n\n}  // namespace emthrm\n\n\n#line 16 \"test/math/formal_power_series/formal_power_series.5.test.cpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<1000000007>;\n  emthrm::FormalPowerSeries<ModInt>::set_mult(\n\
    \      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)\n      \
    \    -> std::vector<ModInt> {\n        return emthrm::mod_convolution(a, b);\n\
    \      });\n  constexpr int D = 6, M = 13;\n  std::string s;\n  std::cin >> s;\n\
    \  std::reverse(s.begin(), s.end());\n  int q[D]{};\n  for (int i = 0; std::cmp_less(i,\
    \ s.length()); ++i) {\n    if (s[i] == '?') ++q[i % D];\n  }\n  std::vector<emthrm::FormalPowerSeries<ModInt>>\
    \ f(\n      D, emthrm::FormalPowerSeries<ModInt>(M));\n  emthrm::FormalPowerSeries<ModInt>\
    \ md(M);\n  md[0] = -1;\n  md[M] = 1;\n  for (int i = 0; i < D; ++i) {\n    int\
    \ base = 1;\n    for (int j = 0; j < i; ++j) {\n      base *= 10;\n    }\n   \
    \ for (int j = 0; j < 10; ++j) {\n      ++f[i][base * j % M];\n    }\n    f[i]\
    \ = f[i].mod_pow(q[i], md);\n  }\n  for (int i = 1; i < D; ++i) {\n    f.front()\
    \ *= f[i];\n  }\n  f.front() %= md;\n  int idx = D - 1, w = 1;\n  for (int i =\
    \ 0; std::cmp_less(i, s.length()); ++i) {\n    if (s[i] != '?') {\n      idx =\
    \ (idx - w * (s[i] - '0')) % M;\n      if (idx < 0) idx += M;\n    }\n    w =\
    \ w * 10 % M;\n  }\n  std::cout << f.front()[idx] << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570 (mod_pow)\n *\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc135/tasks/abc135_d\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include\
    \ <utility>\n#include <vector>\n\n#include \"emthrm/math/convolution/mod_convolution.hpp\"\
    \n#include \"emthrm/math/formal_power_series/formal_power_series.hpp\"\n#include\
    \ \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<1000000007>;\n\
    \  emthrm::FormalPowerSeries<ModInt>::set_mult(\n      [](const std::vector<ModInt>&\
    \ a, const std::vector<ModInt>& b)\n          -> std::vector<ModInt> {\n     \
    \   return emthrm::mod_convolution(a, b);\n      });\n  constexpr int D = 6, M\
    \ = 13;\n  std::string s;\n  std::cin >> s;\n  std::reverse(s.begin(), s.end());\n\
    \  int q[D]{};\n  for (int i = 0; std::cmp_less(i, s.length()); ++i) {\n    if\
    \ (s[i] == '?') ++q[i % D];\n  }\n  std::vector<emthrm::FormalPowerSeries<ModInt>>\
    \ f(\n      D, emthrm::FormalPowerSeries<ModInt>(M));\n  emthrm::FormalPowerSeries<ModInt>\
    \ md(M);\n  md[0] = -1;\n  md[M] = 1;\n  for (int i = 0; i < D; ++i) {\n    int\
    \ base = 1;\n    for (int j = 0; j < i; ++j) {\n      base *= 10;\n    }\n   \
    \ for (int j = 0; j < 10; ++j) {\n      ++f[i][base * j % M];\n    }\n    f[i]\
    \ = f[i].mod_pow(q[i], md);\n  }\n  for (int i = 1; i < D; ++i) {\n    f.front()\
    \ *= f[i];\n  }\n  f.front() %= md;\n  int idx = D - 1, w = 1;\n  for (int i =\
    \ 0; std::cmp_less(i, s.length()); ++i) {\n    if (s[i] != '?') {\n      idx =\
    \ (idx - w * (s[i] - '0')) % M;\n      if (idx < 0) idx += M;\n    }\n    w =\
    \ w * 10 % M;\n  }\n  std::cout << f.front()[idx] << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/mod_convolution.hpp
  - include/emthrm/math/convolution/fast_fourier_transform.hpp
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/formal_power_series.5.test.cpp
  requiredBy: []
  timestamp: '2023-05-14 18:31:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/formal_power_series.5.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/formal_power_series.5.test.cpp
- /verify/test/math/formal_power_series/formal_power_series.5.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\u51AA\
  \u7D1A\u6570 (mod_pow)"
---
