#ifndef EMTHRM_MATH_CONVOLUTION_NUMBER_THEORETIC_TRANSFORM_HPP_
#define EMTHRM_MATH_CONVOLUTION_NUMBER_THEORETIC_TRANSFORM_HPP_

#include <algorithm>
#include <bit>
#include <cassert>
#include <iterator>
#include <utility>
#include <vector>

#include "emthrm/math/modint.hpp"

namespace emthrm {

template <unsigned int T>
struct NumberTheoreticTransform {
  using ModInt = MInt<T>;

  NumberTheoreticTransform() {
    for (int i = 0; i < 23; ++i) {
      if (primes[i][0] == ModInt::get_mod()) [[unlikely]] {
        n_max = 1 << primes[i][2];
        root = ModInt(primes[i][1]).pow((primes[i][0] - 1) >> primes[i][2]);
        return;
      }
    }
    assert(false);
  }

  template <typename U>
  std::vector<ModInt> dft(const std::vector<U>& a) {
    std::vector<ModInt> b(std::bit_ceil(a.size()), 0);
    std::copy(a.begin(), a.end(), b.begin());
    calc(&b);
    return b;
  }

  void idft(std::vector<ModInt>* a) {
    assert(std::has_single_bit(a->size()));
    calc(a);
    std::reverse(std::next(a->begin()), a->end());
    const int n = a->size();
    const ModInt inv_n = ModInt::inv(n);
    for (int i = 0; i < n; ++i) {
      (*a)[i] *= inv_n;
    }
  }

  template <typename U>
  std::vector<ModInt> convolution(const std::vector<U>& a,
                                  const std::vector<U>& b) {
    const int a_size = a.size(), b_size = b.size();
    const int c_size = a_size + b_size - 1;
    const int n = std::bit_ceil(static_cast<unsigned int>(c_size));
    std::vector<ModInt> c(n, 0), d(n, 0);
    std::copy(a.begin(), a.end(), c.begin());
    calc(&c);
    std::copy(b.begin(), b.end(), d.begin());
    calc(&d);
    for (int i = 0; i < n; ++i) {
      c[i] *= d[i];
    }
    idft(&c);
    c.resize(c_size);
    return c;
  }

 private:
  const int primes[23][3]{
    {16957441, 329, 14},
    {17006593, 26, 15},
    {19529729, 770, 17},
    {167772161, 3, 25},
    {469762049, 3, 26},
    {645922817, 3, 23},
    {897581057, 3, 23},
    {924844033, 5, 21},
    {935329793, 3, 22},
    {943718401, 7, 22},
    {950009857, 7, 21},
    {962592769, 7, 21},
    {975175681, 17, 21},
    {976224257, 3, 20},
    {985661441, 3, 22},
    {998244353, 3, 23},
    {1004535809, 3, 21},
    {1007681537, 3, 20},
    {1012924417, 5, 21},
    {1045430273, 3, 20},
    {1051721729, 6, 20},
    {1053818881, 7, 20},
    {1224736769, 3, 24}
  };

  int n_max;
  ModInt root;
  std::vector<int> butterfly{0};
  std::vector<std::vector<ModInt>> omega{{1}};

  void calc(std::vector<ModInt>* a) {
    const int n = a->size(), prev_n = butterfly.size();
    if (n > prev_n) {
      assert(n <= n_max);
      butterfly.resize(n);
      const int prev_lg = omega.size(), lg = std::countr_zero(a->size());
      for (int i = 1; i < prev_n; ++i) {
        butterfly[i] <<= lg - prev_lg;
      }
      for (int i = prev_n; i < n; ++i) {
        butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));
      }
      omega.resize(lg);
      for (int i = prev_lg; i < lg; ++i) {
        omega[i].resize(1 << i);
        const ModInt tmp = root.pow((ModInt::get_mod() - 1) >> (i + 1));
        for (int j = 0; j < (1 << (i - 1)); ++j) {
          omega[i][j << 1] = omega[i - 1][j];
          omega[i][(j << 1) + 1] = omega[i - 1][j] * tmp;
        }
      }
    }
    const int shift =
        std::countr_zero(butterfly.size()) - std::countr_zero(a->size());
    for (int i = 0; i < n; ++i) {
      const int j = butterfly[i] >> shift;
      if (i < j) std::swap((*a)[i], (*a)[j]);
    }
    for (int block = 1, den = 0; block < n; block <<= 1, ++den) {
      for (int i = 0; i < n; i += (block << 1)) {
        for (int j = 0; j < block; ++j) {
          const ModInt tmp = (*a)[i + j + block] * omega[den][j];
          (*a)[i + j + block] = (*a)[i + j] - tmp;
          (*a)[i + j] += tmp;
        }
      }
    }
  }
};

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_NUMBER_THEORETIC_TRANSFORM_HPP_
