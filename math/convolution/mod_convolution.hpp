/**
 * @brief 任意の法の下での畳み込み
 * @docs docs/math/convolution/number_theoretic_transform.md
 */

#pragma once
#include <cmath>
#include <vector>

#include "../modint.hpp"
#include "./fast_fourier_transform.hpp"

template <int T>
std::vector<MInt<T>> mod_convolution(const std::vector<MInt<T>>& a,
                                     const std::vector<MInt<T>>& b,
                                     const int pre = 15) {
  using ModInt = MInt<T>;
  const int a_size = a.size(), b_size = b.size(), c_size = a_size + b_size - 1;
  int lg = 1;
  while ((1 << lg) < c_size) ++lg;
  const int n = 1 << lg, mask = (1 << pre) - 1;
  std::vector<fast_fourier_transform::Complex> x(n), y(n);
  for (int i = 0; i < a_size; ++i) {
    const int a_i = a[i].v;
    x[i] = fast_fourier_transform::Complex(a_i & mask, a_i >> pre);
  }
  fast_fourier_transform::dft(&x);
  for (int i = 0; i < b_size; ++i) {
    const int b_i = b[i].v;
    y[i] = fast_fourier_transform::Complex(b_i & mask, b_i >> pre);
  }
  fast_fourier_transform::dft(&y);
  const int half = n >> 1;
  fast_fourier_transform::Complex tmp_a = x.front(), tmp_b = y.front();
  x.front() =
      fast_fourier_transform::Complex(tmp_a.re * tmp_b.re, tmp_a.im * tmp_b.im);
  y.front() =
      fast_fourier_transform::Complex(
          tmp_a.re * tmp_b.im + tmp_a.im * tmp_b.re, 0);
  for (int i = 1; i < half; ++i) {
    const int j = n - i;
    const fast_fourier_transform::Complex a_l_i =
        (x[i] + x[j].conj()).mul_real(0.5);
    const fast_fourier_transform::Complex a_h_i =
        (x[j].conj() - x[i]).mul_pin(0.5);
    const fast_fourier_transform::Complex b_l_i =
        (y[i] + y[j].conj()).mul_real(0.5);
    const fast_fourier_transform::Complex b_h_i =
        (y[j].conj() - y[i]).mul_pin(0.5);
    const fast_fourier_transform::Complex a_l_j =
        (x[j] + x[i].conj()).mul_real(0.5);
    const fast_fourier_transform::Complex a_h_j =
        (x[i].conj() - x[j]).mul_pin(0.5);
    const fast_fourier_transform::Complex b_l_j =
        (y[j] + y[i].conj()).mul_real(0.5);
    const fast_fourier_transform::Complex b_h_j =
        (y[i].conj() - y[j]).mul_pin(0.5);
    x[i] = a_l_i * b_l_i + (a_h_i * b_h_i).mul_pin(1);
    y[i] = a_l_i * b_h_i + a_h_i * b_l_i;
    x[j] = a_l_j * b_l_j + (a_h_j * b_h_j).mul_pin(1);
    y[j] = a_l_j * b_h_j + a_h_j * b_l_j;
  }
  tmp_a = x[half];
  tmp_b = y[half];
  x[half] = fast_fourier_transform::Complex(
      tmp_a.re * tmp_b.re, tmp_a.im * tmp_b.im);
  y[half] = fast_fourier_transform::Complex(
      tmp_a.re * tmp_b.im + tmp_a.im * tmp_b.re, 0);
  fast_fourier_transform::idft(&x);
  fast_fourier_transform::idft(&y);
  std::vector<ModInt> res(c_size);
  const ModInt tmp1 = 1 << pre, tmp2 = 1LL << (pre << 1);
  for (int i = 0; i < c_size; ++i) {
    res[i] = tmp1 * std::llround(y[i].re) + tmp2 * std::llround(x[i].im)
             + std::llround(x[i].re);
  }
  return res;
}
