/**
 * @brief 任意の法の下での畳み込み
 * @docs docs/math/convolution/number_theoretic_transform.md
 */

#pragma once
#include <cmath>
#include <vector>
#include "../modint.hpp"
#include "fast_fourier_transform.hpp"

template <int T>
std::vector<MInt<T>> mod_convolution(const std::vector<MInt<T>> &a, const std::vector<MInt<T>> &b, const int pre = 15) {
  using ModInt = MInt<T>;
  const int a_size = a.size(), b_size = b.size(), c_size = a_size + b_size - 1;
  int lg = 1;
  while ((1 << lg) < c_size) ++lg;
  const int n = 1 << lg, mask = (1 << pre) - 1;
  std::vector<fast_fourier_transform::Complex> A(n), B(n);
  for (int i = 0; i < a_size; ++i) {
    const int a_i = a[i].val;
    A[i] = fast_fourier_transform::Complex(a_i & mask, a_i >> pre);
  }
  for (int i = 0; i < b_size; ++i) {
    const int b_i = b[i].val;
    B[i] = fast_fourier_transform::Complex(b_i & mask, b_i >> pre);
  }
  fast_fourier_transform::dft(A);
  fast_fourier_transform::dft(B);
  const int half = n >> 1;
  fast_fourier_transform::Complex tmp_a = A[0], tmp_b = B[0];
  A[0] = {tmp_a.re * tmp_b.re, tmp_a.im * tmp_b.im};
  B[0] = {tmp_a.re * tmp_b.im + tmp_a.im * tmp_b.re, 0};
  for (int i = 1; i < half; ++i) {
    const int j = n - i;
    fast_fourier_transform::Complex a_l_i = (A[i] + A[j].conj()).mul_real(0.5), a_h_i = (A[j].conj() - A[i]).mul_pin(0.5);
    fast_fourier_transform::Complex b_l_i = (B[i] + B[j].conj()).mul_real(0.5), b_h_i = (B[j].conj() - B[i]).mul_pin(0.5);
    fast_fourier_transform::Complex a_l_j = (A[j] + A[i].conj()).mul_real(0.5), a_h_j = (A[i].conj() - A[j]).mul_pin(0.5);
    fast_fourier_transform::Complex b_l_j = (B[j] + B[i].conj()).mul_real(0.5), b_h_j = (B[i].conj() - B[j]).mul_pin(0.5);
    A[i] = a_l_i * b_l_i + (a_h_i * b_h_i).mul_pin(1);
    B[i] = a_l_i * b_h_i + a_h_i * b_l_i;
    A[j] = a_l_j * b_l_j + (a_h_j * b_h_j).mul_pin(1);
    B[j] = a_l_j * b_h_j + a_h_j * b_l_j;
  }
  tmp_a = A[half]; tmp_b = B[half];
  A[half] = {tmp_a.re * tmp_b.re, tmp_a.im * tmp_b.im};
  B[half] = {tmp_a.re * tmp_b.im + tmp_a.im * tmp_b.re, 0};
  fast_fourier_transform::idft(A);
  fast_fourier_transform::idft(B);
  std::vector<ModInt> res(c_size);
  ModInt tmp1 = 1 << pre, tmp2 = 1LL << (pre << 1);
  for (int i = 0; i < c_size; ++i) {
    res[i] = std::llround(A[i].re);
    res[i] += tmp1 * std::llround(B[i].re);
    res[i] += tmp2 * std::llround(A[i].im);
  }
  return res;
}
