/**
 * @brief バイナリ行列
 * @docs docs/math/matrix/binary_matrix/binary_matrix.md
 */

#ifndef EMTHRM_MATH_MATRIX_BINARY_MATRIX_BINARY_MATRIX_HPP_
#define EMTHRM_MATH_MATRIX_BINARY_MATRIX_BINARY_MATRIX_HPP_

#include <bitset>
#include <string>
#include <vector>

namespace emthrm {

template <int N>
struct BinaryMatrix {
  explicit BinaryMatrix(const int m, const int n = N, const bool def = false)
      : n(n), data(m, std::bitset<N>(std::string(n, def ? '1' : '0'))) {}

  int nrow() const { return data.size(); }
  int ncol() const { return n; }

  BinaryMatrix pow(long long exponent) const {
    BinaryMatrix res(n, n), tmp = *this;
    for (int i = 0; i < n; ++i) {
      res[i].set(i);
    }
    for (; exponent > 0; exponent >>= 1) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
    }
    return res;
  }

  inline const std::bitset<N>& operator[](const int i) const { return data[i]; }
  inline std::bitset<N>& operator[](const int i) { return data[i]; }

  BinaryMatrix& operator=(const BinaryMatrix& x) = default;

  BinaryMatrix& operator+=(const BinaryMatrix& x) {
    const int m = nrow();
    for (int i = 0; i < m; ++i) {
      data[i] ^= x[i];
    }
    return *this;
  }

  BinaryMatrix& operator*=(const BinaryMatrix& x) {
    const int m = nrow(), l = x.ncol();
    BinaryMatrix t_x(l, n), res(m, l);
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < n; ++j) {
        t_x[i][j] = x[j][i];
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < l; ++j) {
        if ((data[i] & t_x[j]).count() & 1) res[i].set(j);
      }
    }
    return *this = res;
  }

  BinaryMatrix operator+(const BinaryMatrix& x) const {
    return BinaryMatrix(*this) += x;
  }
  BinaryMatrix operator*(const BinaryMatrix& x) const {
    return BinaryMatrix(*this) *= x;
  }

 private:
  int n;
  std::vector<std::bitset<N>> data;
};

}  // namespace emthrm

#endif  // EMTHRM_MATH_MATRIX_BINARY_MATRIX_BINARY_MATRIX_HPP_
