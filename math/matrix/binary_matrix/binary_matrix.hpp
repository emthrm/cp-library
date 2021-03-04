/**
 * @brief バイナリ行列
 * @docs docs/math/matrix/binary_matrix/binary_matrix.md
 */

#pragma once
#include <bitset>
#include <vector>

template <int Col = 2500>
struct BinaryMatrix {
  int m, n;

  BinaryMatrix(int m, int n = Col, bool def = false) : m(m), n(n), dat(m, std::bitset<Col>(0)) {
    if (def) {
      for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] = 1;
    }
  }

  BinaryMatrix pow(long long exponent) const {
    BinaryMatrix tmp = *this, res(n, n);
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }

  inline const std::bitset<Col> &operator[](const int idx) const { return dat[idx]; }
  inline std::bitset<Col> &operator[](const int idx) { return dat[idx]; }

  BinaryMatrix &operator=(const BinaryMatrix &x) {
    m = x.m;
    n = x.n;
    dat.resize(m);
    for (int i = 0; i < m; ++i) dat[i] = x[i];
    return *this;
  }

  BinaryMatrix &operator+=(const BinaryMatrix &x) {
    for (int i = 0; i < m; ++i) dat[i] ^= x[i];
    return *this;
  }

  BinaryMatrix &operator*=(const BinaryMatrix &x) {
    int height = m, width = x.n;
    BinaryMatrix t_x(x.n, x.m), res(height, width);
    for (int i = 0; i < x.n; ++i) for (int j = 0; j < x.m; ++j) t_x[i][j] = x[j][i];
    for (int i = 0; i < height; ++i) for (int j = 0; j < width; ++j) res[i][j] = ((dat[i] & t_x[j]).count() & 1);
    *this = res;
    return *this;
  }

  BinaryMatrix operator+(const BinaryMatrix &x) const { return BinaryMatrix(*this) += x; }

  BinaryMatrix operator*(const BinaryMatrix &x) const { return BinaryMatrix(*this) *= x; }

private:
  std::vector<std::bitset<Col>> dat;
};
