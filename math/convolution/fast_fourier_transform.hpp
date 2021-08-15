#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <utility>
#include <vector>

namespace fast_fourier_transform {
using Real = double;
struct Complex {
  Real re, im;
  Complex(Real re = 0, Real im = 0) : re(re), im(im) {}
  inline Complex operator+(const Complex &x) const { return Complex(re + x.re, im + x.im); }
  inline Complex operator-(const Complex &x) const { return Complex(re - x.re, im - x.im); }
  inline Complex operator*(const Complex &x) const { return Complex(re * x.re - im * x.im, re * x.im + im * x.re); }
  inline Complex mul_real(Real r) const { return Complex(re * r, im * r); }
  inline Complex mul_pin(Real r) const { return Complex(-im * r, re * r); }
  inline Complex conj() const { return Complex(re, -im); }
};

std::vector<int> butterfly{0};
std::vector<std::vector<Complex>> zeta{{{1, 0}}};

void init(int n) {
  const int prev_n = butterfly.size();
  if (n <= prev_n) return;
  butterfly.resize(n);
  const int prev = zeta.size(), lg = __builtin_ctz(n);
  for (int i = 1; i < prev_n; ++i) butterfly[i] <<= lg - prev;
  for (int i = prev_n; i < n; ++i) butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));
  zeta.resize(lg);
  for (int i = prev; i < lg; ++i) {
    zeta[i].resize(1 << i);
    Real angle = -3.14159265358979323846 * 2 / (1 << (i + 1));
    for (int j = 0; j < (1 << (i - 1)); ++j) {
      zeta[i][j << 1] = zeta[i - 1][j];
      Real theta = angle * ((j << 1) + 1);
      zeta[i][(j << 1) + 1] = {std::cos(theta), std::sin(theta)};
    }
  }
}

void dft(std::vector<Complex> &a) {
  const int n = a.size();
  assert(__builtin_popcount(n) == 1);
  init(n);
  const int shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);
  for (int i = 0; i < n; ++i) {
    const int j = butterfly[i] >> shift;
    if (i < j) std::swap(a[i], a[j]);
  }
  for (int block = 1, den = 0; block < n; block <<= 1, ++den) {
    for (int i = 0; i < n; i += (block << 1)) for (int j = 0; j < block; ++j) {
      Complex tmp = a[i + j + block] * zeta[den][j];
      a[i + j + block] = a[i + j] - tmp;
      a[i + j] = a[i + j] + tmp;
    }
  }
}

template <typename T>
std::vector<Complex> real_dft(const std::vector<T> &a) {
  const int n = a.size();
  int lg = 1;
  while ((1 << lg) < n) ++lg;
  std::vector<Complex> c(1 << lg);
  for (int i = 0; i < n; ++i) c[i].re = a[i];
  dft(c);
  return c;
}

void idft(std::vector<Complex> &a) {
  const int n = a.size();
  dft(a);
  std::reverse(a.begin() + 1, a.end());
  Real r = 1.0 / n;
  for (int i = 0; i < n; ++i) a[i] = a[i].mul_real(r);
}

template <typename T>
std::vector<Real> convolution(const std::vector<T> &a, const std::vector<T> &b) {
  const int a_size = a.size(), b_size = b.size(), c_size = a_size + b_size - 1;
  int lg = 1;
  while ((1 << lg) < c_size) ++lg;
  const int n = 1 << lg, half = n >> 1, quarter = half >> 1;
  std::vector<Complex> c(n);
  for (int i = 0; i < a_size; ++i) c[i].re = a[i];
  for (int i = 0; i < b_size; ++i) c[i].im = b[i];
  dft(c);
  c[0] = Complex(c[0].re * c[0].im, 0);
  for (int i = 1; i < half; ++i) {
    Complex i_square = c[i] * c[i], j_square = c[n - i] * c[n - i];
    c[i] = (j_square.conj() - i_square).mul_pin(0.25);
    c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);
  }
  c[half] = Complex(c[half].re * c[half].im, 0);
  c[0] = (c[0] + c[half] + (c[0] - c[half]).mul_pin(1)).mul_real(0.5);
  const int den = __builtin_ctz(half);
  for (int i = 1; i < quarter; ++i) {
    const int j = half - i;
    Complex tmp1 = c[i] + c[j].conj(), tmp2 = ((c[i] - c[j].conj()) * zeta[den][j]).mul_pin(1);
    c[i] = (tmp1 - tmp2).mul_real(0.5);
    c[j] = (tmp1 + tmp2).mul_real(0.5).conj();
  }
  if (quarter > 0) c[quarter] = c[quarter].conj();
  c.resize(half);
  idft(c);
  std::vector<Real> res(c_size);
  for (int i = 0; i < c_size; ++i) res[i] = (i & 1 ? c[i >> 1].im : c[i >> 1].re);
  return res;
}
}  // fast_fourier_transform
