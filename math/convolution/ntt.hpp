/**
 * @brief 数論変換
 * @docs docs/math/convolution/ntt.md
 */

#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
#include "../modint.hpp"

struct NTT {
  NTT() {
    for (int i = 0; i < 23; ++i) {
      if (primes[i][0] == ModInt::get_mod()) {
        n_max = 1 << primes[i][2];
        root = ModInt(primes[i][1]).pow((ModInt::get_mod() - 1) >> primes[i][2]);
        return;
      }
    }
    assert(false);
  }

  void sub_dft(std::vector<ModInt> &a) {
    int n = a.size();
    assert(__builtin_popcount(n) == 1);
    calc(n);
    int shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);
    for (int i = 0; i < n; ++i) {
      int j = butterfly[i] >> shift;
      if (i < j) std::swap(a[i], a[j]);
    }
    for (int block = 1; block < n; block <<= 1) {
      int den = __builtin_ctz(block);
      for (int i = 0; i < n; i += (block << 1)) for (int j = 0; j < block; ++j) {
        ModInt tmp = a[i + j + block] * omega[den][j];
        a[i + j + block] = a[i + j] - tmp;
        a[i + j] += tmp;
      }
    }
  }

  template <typename T>
  std::vector<ModInt> dft(const std::vector<T> &a) {
    int n = a.size(), lg = 1;
    while ((1 << lg) < n) ++lg;
    std::vector<ModInt> A(1 << lg, 0);
    for (int i = 0; i < n; ++i) A[i] = a[i];
    sub_dft(A);
    return A;
  }

  void idft(std::vector<ModInt> &a) {
    int n = a.size();
    assert(__builtin_popcount(n) == 1);
    sub_dft(a);
    std::reverse(a.begin() + 1, a.end());
    ModInt inv_n = ModInt(1) / n;
    for (int i = 0; i < n; ++i) a[i] *= inv_n;
  }

  template <typename T>
  std::vector<ModInt> convolution(const std::vector<T> &a, const std::vector<T> &b) {
    int a_sz = a.size(), b_sz = b.size(), sz = a_sz + b_sz - 1, lg = 1;
    while ((1 << lg) < sz) ++lg;
    int n = 1 << lg;
    std::vector<ModInt> A(n, 0), B(n, 0);
    for (int i = 0; i < a_sz; ++i) A[i] = a[i];
    for (int i = 0; i < b_sz; ++i) B[i] = b[i];
    sub_dft(A);
    sub_dft(B);
    for (int i = 0; i < n; ++i) A[i] *= B[i];
    idft(A);
    A.resize(sz);
    return A;
  }

private:
  int primes[23][3]{
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

  void calc(int n) {
    int prev_n = butterfly.size();
    if (n <= prev_n) return;
    assert(n <= n_max);
    butterfly.resize(n);
    int prev_lg = omega.size(), lg = __builtin_ctz(n);
    for (int i = 1; i < prev_n; ++i) butterfly[i] <<= lg - prev_lg;
    for (int i = prev_n; i < n; ++i) butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));
    omega.resize(lg);
    for (int i = prev_lg; i < lg; ++i) {
      omega[i].resize(1 << i);
      ModInt tmp = root.pow((ModInt::get_mod() - 1) / (1 << (i + 1)));
      for (int j = 0; j < (1 << (i - 1)); ++j) {
        omega[i][j << 1] = omega[i - 1][j];
        omega[i][(j << 1) + 1] = omega[i - 1][j] * tmp;
      }
    }
  }
};
