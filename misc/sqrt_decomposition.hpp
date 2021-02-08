#pragma once
#include <cmath>
#include <vector>

struct SqrtDecomposition {
  int b, n;
  std::vector<int> left, right;
  std::vector<bool> need_to_be_eval;

  SqrtDecomposition(int n_) : b(std::sqrt(n_)) {
    n = (n_ + b - 1) / b;
    left.resize(n);
    right.resize(n);
    need_to_be_eval.assign(n, false);
    for (int i = 0; i < n; ++i) {
      left[i] = b * i;
      right[i] = i + 1 == n ? n_ : b * (i + 1);
    }
  }

  template <typename T> void partial_update(int idx, T val);

  template <typename T> void total_update(int idx, T val);

  template <typename T>
  void update(int l, int r, T val) {
    if (r <= l) return;
    int l_b = l / b, r_b = (r - 1) / b;
    if (l_b < r_b) {
      if (l == left[l_b]) {
        total_update(l_b, val);
      } else {
        for (int i = l; i < right[l_b]; ++i) partial_update(i, val);
      }
      for (int i = l_b + 1; i < r_b; ++i) total_update(i, val);
      if (r == right[r_b]) {
        total_update(r_b, val);
      } else {
        for (int i = left[r_b]; i < r; ++i) partial_update(i, val);
      }
    } else {
      for (int i = l; i < r; ++i) partial_update(i, val);
    }
  }

  template <typename T> void partial_query(int idx, T &val);

  template <typename T> void total_query(int idx, T &val);

  template <typename T>
  T query(int l, int r, const T UNITY) {
    int l_b = l / b, r_b = (r - 1) / b;
    T res = UNITY;
    if (l_b < r_b) {
      if (l == left[l_b]) {
        total_query(l_b, res);
      } else {
        for (int i = l; i < right[l_b]; ++i) partial_query(i, res);
      }
      for (int i = l_b + 1; i < r_b; ++i) total_query(i, res);
      if (r == right[r_b]) {
        total_query(r_b, res);
      } else {
        for (int i = left[r_b]; i < r; ++i) partial_query(i, res);
      }
    } else {
      for (int i = l; i < r; ++i) partial_query(i, res);
    }
    return res;
  }
};
