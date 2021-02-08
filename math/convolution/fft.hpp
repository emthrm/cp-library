#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <utility>
#include <vector>

namespace fft {
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

void calc(int n) {
  int prev_n = butterfly.size();
  if (n <= prev_n) return;
  butterfly.resize(n);
  int prev_lg = zeta.size(), lg = __builtin_ctz(n);
  for (int i = 1; i < prev_n; ++i) butterfly[i] <<= lg - prev_lg;
  for (int i = prev_n; i < n; ++i) butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));
  zeta.resize(lg);
  for (int i = prev_lg; i < lg; ++i) {
    zeta[i].resize(1 << i);
    Real angle = -3.14159265358979323846 * 2 / (1 << (i + 1));
    for (int j = 0; j < (1 << (i - 1)); ++j) {
      zeta[i][j << 1] = zeta[i - 1][j];
      Real theta = angle * ((j << 1) + 1);
      zeta[i][(j << 1) + 1] = {std::cos(theta), std::sin(theta)};
    }
  }
}

void sub_dft(std::vector<Complex> &a) {
  int n = a.size();
  assert(__builtin_popcount(n) == 1);
  calc(n);
  int shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);
  for (int i = 0; i < n; ++i) {
    int j = butterfly[i] >> shift;
    if (i < j) std::swap(a[i], a[j]);
  }
  for (int block = 1; block < n; block <<= 1) {
    int den = __builtin_ctz(block);
    for (int i = 0; i < n; i += (block << 1)) for (int j = 0; j < block; ++j) {
      Complex tmp = a[i + j + block] * zeta[den][j];
      a[i + j + block] = a[i + j] - tmp;
      a[i + j] = a[i + j] + tmp;
    }
  }
}

template <typename T>
std::vector<Complex> dft(const std::vector<T> &a) {
  int sz = a.size(), lg = 1;
  while ((1 << lg) < sz) ++lg;
  std::vector<Complex> c(1 << lg);
  for (int i = 0; i < sz; ++i) c[i].re = a[i];
  sub_dft(c);
  return c;
}

std::vector<Real> real_idft(std::vector<Complex> &a) {
  int n = a.size(), half = n >> 1, quarter = half >> 1;
  assert(__builtin_popcount(n) == 1);
  calc(n);
  a[0] = (a[0] + a[half] + (a[0] - a[half]).mul_pin(1)).mul_real(0.5);
  int den = __builtin_ctz(half);
  for (int i = 1; i < quarter; ++i) {
    int j = half - i;
    Complex tmp1 = a[i] + a[j].conj(), tmp2 = ((a[i] - a[j].conj()) * zeta[den][j]).mul_pin(1);
    a[i] = (tmp1 - tmp2).mul_real(0.5);
    a[j] = (tmp1 + tmp2).mul_real(0.5).conj();
  }
  if (quarter > 0) a[quarter] = a[quarter].conj();
  a.resize(half);
  sub_dft(a);
  std::reverse(a.begin() + 1, a.end());
  Real r = 1.0 / half;
  std::vector<Real> res(n);
  for (int i = 0; i < n; ++i) res[i] = (i & 1 ? a[i >> 1].im : a[i >> 1].re) * r;
  return res;
}

void idft(std::vector<Complex> &a) {
  int n = a.size();
  sub_dft(a);
  std::reverse(a.begin() + 1, a.end());
  Real r = 1.0 / n;
  for (int i = 0; i < n; ++i) a[i] = a[i].mul_real(r);
}

template <typename T>
std::vector<Real> convolution(const std::vector<T> &a, const std::vector<T> &b) {
  int a_sz = a.size(), b_sz = b.size(), sz = a_sz + b_sz - 1, lg = 1;
  while ((1 << lg) < sz) ++lg;
  int n = 1 << lg;
  std::vector<Complex> c(n);
  for (int i = 0; i < a_sz; ++i) c[i].re = a[i];
  for (int i = 0; i < b_sz; ++i) c[i].im = b[i];
  sub_dft(c);
  c[0] = Complex(c[0].re * c[0].im, 0);
  int half = n >> 1;
  for (int i = 1; i < half; ++i) {
    Complex i_square = c[i] * c[i], j_square = c[n - i] * c[n - i];
    c[i] = (j_square.conj() - i_square).mul_pin(0.25);
    c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);
  }
  c[half] = Complex(c[half].re * c[half].im, 0);
  std::vector<Real> res = real_idft(c);
  res.resize(sz);
  return res;
}
}  // fft
