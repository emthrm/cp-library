#ifndef EMTHRM_MATH_CONVOLUTION_NUMBER_THEORETIC_TRANSFORM_HPP_
#define EMTHRM_MATH_CONVOLUTION_NUMBER_THEORETIC_TRANSFORM_HPP_

#if __has_include(<atcoder/convolution>)
# include <atcoder/convolution>
# include <atcoder/modint>
#else
# include <algorithm>
# include <bit>
# include <cassert>
# include <iterator>
# include <map>
# include <utility>
#endif
#include <vector>

#include "emthrm/math/modint.hpp"

namespace emthrm {

#if __has_include(<atcoder/convolution>)

template <unsigned int T>
struct NumberTheoreticTransform {
  using ModInt = MInt<T>;

  NumberTheoreticTransform() = default;

  template <typename U>
  std::vector<ModInt> dft(const std::vector<U>& a);

  void idft(std::vector<ModInt>* a);

  template <typename U>
  std::vector<ModInt> convolution(
      const std::vector<U>& a, const std::vector<U>& b) const {
    const int a_size = a.size(), b_size = b.size();
    std::vector<atcoder::static_modint<T>> c(a_size), d(b_size);
    for (int i = 0; i < a_size; ++i) {
      c[i] = atcoder::static_modint<T>::raw(ModInt(a[i]).v);
    }
    for (int i = 0; i < b_size; ++i) {
      d[i] = atcoder::static_modint<T>::raw(ModInt(b[i]).v);
    }
    c = atcoder::convolution(c, d);
    const int c_size = c.size();
    std::vector<ModInt> res(c_size);
    for (int i = 0; i < c_size; ++i) {
      res[i] = ModInt::raw(c[i].val());
    }
    return res;
  }
};

#else  // __has_include(<atcoder/convolution>)

template <unsigned int T>
struct NumberTheoreticTransform {
  using ModInt = MInt<T>;

  NumberTheoreticTransform()
      : n_max(1 << init().first), root(ModInt::raw(init().second)) {}

  template <typename U>
  std::vector<ModInt> dft(const std::vector<U>& a) {
    std::vector<ModInt> b(std::bit_ceil(a.size()), 0);
    std::ranges::copy(a, b.begin());
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
  std::vector<ModInt> convolution(
      const std::vector<U>& a, const std::vector<U>& b) const {
    const int a_size = a.size(), b_size = b.size();
    const int c_size = a_size + b_size - 1;
    if (std::min(a_size, b_size) <= 60) {
      std::vector<ModInt> c(c_size, 0);
      if (a_size > b_size) {
        for (int i = 0; i < a_size; ++i) {
          for (int j = 0; j < b_size; ++j) {
            c[i + j] += ModInt(a[i]) * b[j];
          }
        }
      } else {
        for (int j = 0; j < b_size; ++j) {
          for (int i = 0; i < a_size; ++i) {
            c[i + j] += ModInt(b[j]) * a[i];
          }
        }
      }
      return c;
    }
    const int n = std::bit_ceil(static_cast<unsigned int>(c_size));
    std::vector<ModInt> c(n, 0), d(n, 0);
    std::ranges::copy(a, c.begin());
    calc(&c);
    std::ranges::copy(b, d.begin());
    calc(&d);
    for (int i = 0; i < n; ++i) {
      c[i] *= d[i];
    }
    idft(&c);
    c.resize(c_size);
    return c;
  }

 private:
  static std::pair<int, int> init() {
    static const std::map<int, std::pair<int, int>> primes{
        {16957441, {14, 102066830}},  // 329
        {17006593, {15, 608991743}},  // 26
        {19529729, {17, 927947839}},  // 770
        {167772161, {25, 243}},  // 3
        {469762049, {26, 2187}},  // 3
        {645922817, {23, 680782677}},  // 3
        {897581057, {23, 126991183}},  // 3
        {924844033, {21, 480100938}},  // 5
        {935329793, {22, 945616399}},  // 3
        {943718401, {22, 39032610}},  // 7
        {950009857, {21, 912960248}},  // 7
        {962592769, {21, 762567211}},  // 7
        {975175681, {21, 973754139}},  // 17
        {976224257, {20, 168477898}},  // 3
        {985661441, {22, 157780640}},  // 3
        {998244353, {23, 15311432}},  // 3
        {1004535809, {21, 840453100}},  // 3
        {1007681537, {20, 283888334}},  // 3
        {1012924417, {21, 428116421}},  // 5
        {1045430273, {20, 328125745}},  // 3
        {1051721729, {20, 234350985}},  // 6
        {1053818881, {20, 309635616}},  // 7
        {1224736769, {24, 304180829}}};  // 3
    return primes.at(T);
  }

  const int n_max;
  const ModInt root;

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

#endif  // __has_include(<atcoder/convolution>)

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_NUMBER_THEORETIC_TRANSFORM_HPP_
