#ifndef EMTHRM_MATH_CONVOLUTION_FAST_FOURIER_TRANSFORM_HPP_
#define EMTHRM_MATH_CONVOLUTION_FAST_FOURIER_TRANSFORM_HPP_

#include <algorithm>
#include <bit>
#include <cassert>
#include <cmath>
#include <iterator>
#include <utility>
#include <vector>

namespace emthrm {

namespace fast_fourier_transform {

using Real = double;

struct Complex {
  Real re, im;
  explicit Complex(const Real re = 0, const Real im = 0) : re(re), im(im) {}
  inline Complex operator+(const Complex& x) const {
    return Complex(re + x.re, im + x.im);
  }
  inline Complex operator-(const Complex& x) const {
    return Complex(re - x.re, im - x.im);
  }
  inline Complex operator*(const Complex& x) const {
    return Complex(re * x.re - im * x.im, re * x.im + im * x.re);
  }
  inline Complex mul_real(const Real r) const {
    return Complex(re * r, im * r);
  }
  inline Complex mul_pin(const Real r) const {
    return Complex(-im * r, re * r);
  }
  inline Complex conj() const { return Complex(re, -im); }
};

std::vector<int> butterfly{0};
std::vector<std::vector<Complex>> zeta{{Complex(1, 0)}};

void init(const int n) {
  const int prev_n = butterfly.size();
  if (n <= prev_n) return;
  butterfly.resize(n);
  const int prev_lg = zeta.size();
  const int lg = std::countr_zero(static_cast<unsigned int>(n));
  for (int i = 1; i < prev_n; ++i) {
    butterfly[i] <<= lg - prev_lg;
  }
  for (int i = prev_n; i < n; ++i) {
    butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));
  }
  zeta.resize(lg);
  for (int i = prev_lg; i < lg; ++i) {
    zeta[i].resize(1 << i);
    const Real angle = -3.14159265358979323846 * 2 / (1 << (i + 1));
    for (int j = 0; j < (1 << (i - 1)); ++j) {
      zeta[i][j << 1] = zeta[i - 1][j];
      const Real theta = angle * ((j << 1) + 1);
      zeta[i][(j << 1) + 1] = Complex(std::cos(theta), std::sin(theta));
    }
  }
}

void dft(std::vector<Complex>* a) {
  assert(std::has_single_bit(a->size()));
  const int n = a->size();
  init(n);
  const int shift =
      std::countr_zero(butterfly.size()) - std::countr_zero(a->size());
  for (int i = 0; i < n; ++i) {
    const int j = butterfly[i] >> shift;
    if (i < j) std::swap((*a)[i], (*a)[j]);
  }
  for (int block = 1, den = 0; block < n; block <<= 1, ++den) {
    for (int i = 0; i < n; i += (block << 1)) {
      for (int j = 0; j < block; ++j) {
        const Complex tmp = (*a)[i + j + block] * zeta[den][j];
        (*a)[i + j + block] = (*a)[i + j] - tmp;
        (*a)[i + j] = (*a)[i + j] + tmp;
      }
    }
  }
}

template <typename T>
std::vector<Complex> real_dft(const std::vector<T>& a) {
  const int n = a.size();
  std::vector<Complex> c(std::bit_ceil(a.size()));
  for (int i = 0; i < n; ++i) {
    c[i].re = a[i];
  }
  dft(&c);
  return c;
}

void idft(std::vector<Complex>* a) {
  const int n = a->size();
  dft(a);
  std::reverse(std::next(a->begin()), a->end());
  const Real r = 1. / n;
  for (int i = 0; i < n; ++i) {
    (*a)[i] = (*a)[i].mul_real(r);
  }
}

template <typename T>
std::vector<Real> convolution(const std::vector<T>& a,
                              const std::vector<T>& b) {
  const int a_size = a.size(), b_size = b.size(), c_size = a_size + b_size - 1;
  const int n = std::max(std::bit_ceil(static_cast<unsigned int>(c_size)), 2);
  const int hlf = n >> 1, qtr = hlf >> 1;
  std::vector<Complex> c(n);
  for (int i = 0; i < a_size; ++i) {
    c[i].re = a[i];
  }
  for (int i = 0; i < b_size; ++i) {
    c[i].im = b[i];
  }
  dft(&c);
  c.front() = Complex(c.front().re * c.front().im, 0);
  for (int i = 1; i < hlf; ++i) {
    const Complex i_square = c[i] * c[i], j_square = c[n - i] * c[n - i];
    c[i] = (j_square.conj() - i_square).mul_pin(0.25);
    c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);
  }
  c[hlf] = Complex(c[hlf].re * c[hlf].im, 0);
  c.front() = (c.front() + c[hlf]
               + (c.front() - c[hlf]).mul_pin(1)).mul_real(0.5);
  const int den = std::countr_zero(hlf);
  for (int i = 1; i < qtr; ++i) {
    const int j = hlf - i;
    const Complex tmp1 = c[i] + c[j].conj();
    const Complex tmp2 = ((c[i] - c[j].conj()) * zeta[den][j]).mul_pin(1);
    c[i] = (tmp1 - tmp2).mul_real(0.5);
    c[j] = (tmp1 + tmp2).mul_real(0.5).conj();
  }
  if (qtr > 0) c[qtr] = c[qtr].conj();
  c.resize(hlf);
  idft(&c);
  std::vector<Real> res(c_size);
  for (int i = 0; i < c_size; i += 2) {
    res[i] = c[i >> 1].re;
  }
  for (int i = 1; i < c_size; i += 2) {
    res[i] = c[i >> 1].im;
  }
  return res;
}

}  // namespace fast_fourier_transform

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_FAST_FOURIER_TRANSFORM_HPP_
