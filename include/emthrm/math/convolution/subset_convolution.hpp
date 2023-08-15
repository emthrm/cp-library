#ifndef EMTHRM_MATH_CONVOLUTION_SUBSET_CONVOLUTION_HPP_
#define EMTHRM_MATH_CONVOLUTION_SUBSET_CONVOLUTION_HPP_

#include <array>
#include <bit>
#include <cassert>
#include <utility>
#include <vector>

namespace emthrm {

template <int MaxN, typename T>
std::vector<T> subset_convolution(
    const std::vector<T>& f, const std::vector<T>& g) {
  using Polynomial = std::array<T, MaxN + 1>;
  assert(std::has_single_bit(f.size()) && f.size() == g.size());
  const int n = std::countr_zero(f.size());
  assert(n <= MaxN);
  const int domain_size = 1 << n;
  const auto ranked_zeta_transform =
      [n, domain_size](const std::vector<T>& f) -> std::vector<Polynomial> {
    std::vector a(domain_size, Polynomial{});
    for (int i = 0; i < domain_size; ++i) {
      a[i][std::popcount(static_cast<unsigned int>(i))] = f[i];
    }
    for (int bit = 1; bit < domain_size; bit <<= 1) {
      for (int i = 0; i < domain_size; ++i) {
        if ((i & bit) == 0) {
          for (int degree = 0; degree <= n; ++degree) {
            a[i | bit][degree] += a[i][degree];
          }
        }
      }
    }
    return a;
  };
  std::vector<Polynomial> a = ranked_zeta_transform(f);
  const std::vector<Polynomial> b = ranked_zeta_transform(g);
  for (int i = 0; i < domain_size; ++i) {
    // Hadamard product
    for (int degree_of_a = n; degree_of_a >= 0; --degree_of_a) {
      const T tmp = std::exchange(a[i][degree_of_a], T{});
      for (int degree_of_b = 0; degree_of_a + degree_of_b <= n; ++degree_of_b) {
        a[i][degree_of_a + degree_of_b] += tmp * b[i][degree_of_b];
      }
    }
  }
  for (int bit = 1; bit < domain_size; bit <<= 1) {
    for (int i = 0; i < domain_size; ++i) {
      if ((i & bit) == 0) {
        for (int degree = 0; degree <= n; ++degree) {
          a[i | bit][degree] -= a[i][degree];
        }
      }
    }
  }
  std::vector<T> c(domain_size);
  for (int i = 0; i < domain_size; ++i) {
    c[i] = a[i][std::popcount(static_cast<unsigned int>(i))];
  }
  return c;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_SUBSET_CONVOLUTION_HPP_
