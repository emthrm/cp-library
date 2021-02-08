#pragma once
#include <utility>
#include <vector>

template <typename T>
struct Matrix {
  Matrix(int m, int n, T val = 0) : dat(m, std::vector<T>(n, val)) {}

  int height() const { return dat.size(); }

  int width() const { return dat.front().size(); }

  Matrix pow(long long exponent) const {
    int n = height();
    Matrix<T> tmp = *this, res(n, n, 0);
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }

  inline const std::vector<T> &operator[](const int idx) const { return dat[idx]; }
  inline std::vector<T> &operator[](const int idx) { return dat[idx]; }

  Matrix &operator=(const Matrix &x) {
    int m = x.height(), n = x.width();
    dat.resize(m, std::vector<T>(n));
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] = x[i][j];
    return *this;
  }

  Matrix &operator+=(const Matrix &x) {
    int m = height(), n = width();
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] += x[i][j];
    return *this;
  }

  Matrix &operator-=(const Matrix &x) {
    int m = height(), n = width();
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] -= x[i][j];
    return *this;
  }

  Matrix &operator*=(const Matrix &x) {
    int m = height(), n = x.width(), l = width();
    std::vector<std::vector<T>> res(m, std::vector<T>(n, 0));
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
      for (int k = 0; k < l; ++k) res[i][j] += dat[i][k] * x[k][j];
    }
    std::swap(dat, res);
    return *this;
  }

  Matrix operator+(const Matrix &x) const { return Matrix(*this) += x; }

  Matrix operator-(const Matrix &x) const { return Matrix(*this) -= x; }

  Matrix operator*(const Matrix &x) const { return Matrix(*this) *= x; }

private:
  std::vector<std::vector<T>> dat;
};
