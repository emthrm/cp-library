#ifndef EMTHRM_MISC_SQRT_DECOMPOSITION_HPP_
#define EMTHRM_MISC_SQRT_DECOMPOSITION_HPP_

#include <cmath>
#include <vector>

namespace emthrm {

struct SqrtDecomposition {
  const int block_size, n;
  std::vector<int> ls, rs;
  std::vector<bool> to_be_eval;

  explicit SqrtDecomposition(const int n_)
      : block_size(std::round(std::sqrt(n_))),
        n((n_ + block_size - 1) / block_size) {
    ls.resize(n);
    rs.resize(n);
    to_be_eval.assign(n, false);
    for (int i = 0; i < n; ++i) {
      ls[i] = block_size * i;
      rs[i] = (i + 1 == n ? n_ : block_size * (i + 1));
    }
  }

  template <typename T> void partial_update(const int idx, const T val);

  template <typename T> void total_update(const int idx, const T val);

  template <typename T>
  void update(const int l, const int r, const T val) {
    if (r <= l) [[unlikely]] return;
    const int b_l = l / block_size, b_r = (r - 1) / block_size;
    if (b_l < b_r) {
      if (l == ls[b_l]) {
        total_update(b_l, val);
      } else {
        for (int i = l; i < rs[b_l]; ++i) {
          partial_update(i, val);
        }
      }
      for (int i = b_l + 1; i < b_r; ++i) {
        total_update(i, val);
      }
      if (r == rs[b_r]) {
        total_update(b_r, val);
      } else {
        for (int i = ls[b_r]; i < r; ++i) {
          partial_update(i, val);
        }
      }
    } else {
      for (int i = l; i < r; ++i) {
        partial_update(i, val);
      }
    }
  }

  template <typename T> void partial_query(const int idx, T* val);

  template <typename T> void total_query(const int idx, T* val);

  template <typename T>
  T query(const int l, const int r, const T id) {
    const int b_l = l / block_size, b_r = (r - 1) / block_size;
    T res = id;
    if (b_l < b_r) {
      if (l == ls[b_l]) {
        total_query(b_l, &res);
      } else {
        for (int i = l; i < rs[b_l]; ++i) {
          partial_query(i, &res);
        }
      }
      for (int i = b_l + 1; i < b_r; ++i) {
        total_query(i, &res);
      }
      if (r == rs[b_r]) {
        total_query(b_r, &res);
      } else {
        for (int i = ls[b_r]; i < r; ++i) {
          partial_query(i, &res);
        }
      }
    } else {
      for (int i = l; i < r; ++i) {
        partial_query(i, &res);
      }
    }
    return res;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_MISC_SQRT_DECOMPOSITION_HPP_
