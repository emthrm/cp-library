#ifndef EMTHRM_MATH_MATRIX_MATRIX_HPP_
#define EMTHRM_MATH_MATRIX_MATRIX_HPP_

#include <vector>

namespace emthrm {

template <typename T>
struct Matrix {
  explicit Matrix(const int m, const int n, const T def = 0)
      : data(m, std::vector<T>(n, def)) {}

  int nrow() const { return data.size(); }
  int ncol() const { return data.front().size(); }

  Matrix pow(long long exponent) const {
    const int n = nrow();
    Matrix<T> res(n, n, 0), tmp = *this;
    for (int i = 0; i < n; ++i) {
      res[i][i] = 1;
    }
    for (; exponent > 0; exponent >>= 1) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
    }
    return res;
  }

  inline const std::vector<T>& operator[](const int i) const { return data[i]; }
  inline std::vector<T>& operator[](const int i) { return data[i]; }

  Matrix& operator=(const Matrix& x) = default;

  Matrix& operator+=(const Matrix& x) {
    const int m = nrow(), n = ncol();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        data[i][j] += x[i][j];
      }
    }
    return *this;
  }

  Matrix& operator-=(const Matrix& x) {
    const int m = nrow(), n = ncol();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        data[i][j] -= x[i][j];
      }
    }
    return *this;
  }

  Matrix& operator*=(const Matrix& x) {
    const int m = nrow(), l = ncol(), n = x.ncol();
    std::vector<std::vector<T>> res(m, std::vector<T>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int k = 0; k < l; ++k) {
        for (int j = 0; j < n; ++j) {
          res[i][j] += data[i][k] * x[k][j];
        }
      }
    }
    data.swap(res);
    return *this;
  }

  Matrix operator+(const Matrix& x) const { return Matrix(*this) += x; }
  Matrix operator-(const Matrix& x) const { return Matrix(*this) -= x; }
  Matrix operator*(const Matrix& x) const { return Matrix(*this) *= x; }

 private:
  std::vector<std::vector<T>> data;
};

}  // namespace emthrm

#endif  // EMTHRM_MATH_MATRIX_MATRIX_HPP_
