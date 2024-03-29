#ifndef EMTHRM_MATH_CONVOLUTION_MOD_CONVOLUTION_HPP_
#define EMTHRM_MATH_CONVOLUTION_MOD_CONVOLUTION_HPP_

#include <algorithm>
#include <bit>
#include <cmath>
#include <vector>

#include "emthrm/math/convolution/fast_fourier_transform.hpp"
#include "emthrm/math/modint.hpp"

namespace emthrm {

template <int PRECISION = 15, unsigned int T>
std::vector<MInt<T>> mod_convolution(const std::vector<MInt<T>>& a,
                                     const std::vector<MInt<T>>& b) {
  using ModInt = MInt<T>;
  const int a_size = a.size(), b_size = b.size(), c_size = a_size + b_size - 1;
  const int n = std::max(std::bit_ceil(static_cast<unsigned int>(c_size)), 2U);
  constexpr int mask = (1 << PRECISION) - 1;
  std::vector<fast_fourier_transform::Complex> x(n), y(n);
  std::transform(
      a.begin(), a.end(), x.begin(),
      [mask](const MInt<T>& x) -> fast_fourier_transform::Complex {
        return fast_fourier_transform::Complex(x.v & mask, x.v >> PRECISION);
      });
  fast_fourier_transform::dft(&x);
  std::transform(
      b.begin(), b.end(), y.begin(),
      [mask](const MInt<T>& y) -> fast_fourier_transform::Complex {
        return fast_fourier_transform::Complex(y.v & mask, y.v >> PRECISION);
      });
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
  const ModInt tmp1 = 1 << PRECISION, tmp2 = 1LL << (PRECISION << 1);
  for (int i = 0; i < c_size; ++i) {
    res[i] = tmp1 * std::llround(y[i].re) + tmp2 * std::llround(x[i].im)
             + std::llround(x[i].re);
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_MOD_CONVOLUTION_HPP_
