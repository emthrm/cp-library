#ifndef EMTHRM_MATH_CONVOLUTION_KRONECKER_POWER_VECTOR_MULTIPLICATION_HPP_
#define EMTHRM_MATH_CONVOLUTION_KRONECKER_POWER_VECTOR_MULTIPLICATION_HPP_

#include <cassert>
#include <cmath>
#include <vector>

#include "emthrm/math/matrix/matrix.hpp"

namespace emthrm {

template <typename T>
std::vector<T> kronecker_power_vector_multiplication(const Matrix<T>& g,
                                                     std::vector<T> v) {
  const int d = g.nrow(), n = v.size();
  assert(std::llround(std::pow(d, std::log(n) / std::log(d))) == n);
  Matrix<T> tmp(d, 1);
  for (int block = 1; block < n; block *= d) {
    for (int i = 0; i < n; i += block * d) {
      for (int j = 0; j < block; ++j) {
        for (int x = 0; x < d; ++x) {
          tmp[x][0] = v[i + j + block * x];
        }
        tmp = g * tmp;
        for (int x = 0; x < d; ++x) {
          v[i + j + block * x] = tmp[x][0];
        }
      }
    }
  }
  return v;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_KRONECKER_POWER_VECTOR_MULTIPLICATION_HPP_
