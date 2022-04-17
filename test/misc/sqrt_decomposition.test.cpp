/*
 * @brief その他/平方分割
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <iostream>
#include <vector>

#include "../../misc/sqrt_decomposition.hpp"

std::vector<long long> a, b, lazy;

template <typename T>
void SqrtDecomposition::partial_update(const int idx, const T val) {
  a[idx] += val;
  b[idx / block_size] += val;
}

template <typename T>
void SqrtDecomposition::total_update(const int idx, const T val) {
  lazy[idx] += val;
  to_be_eval[idx] = true;
}

template <typename T>
void SqrtDecomposition::partial_query(const int idx, T* val) {
  const int block = idx / block_size;
  if (to_be_eval[block]) {
    for (int i = ls[block]; i < rs[block]; ++i) {
      partial_update(i, lazy[block]);
    }
    lazy[block] = 0;
    to_be_eval[block] = false;
  }
  *val += a[idx];
}

template <typename T>
void SqrtDecomposition::total_query(const int idx, T* val) {
  *val += b[idx] + lazy[idx] * (rs[idx] - ls[idx]);
}

int main() {
  int n, q;
  std::cin >> n >> q;
  SqrtDecomposition sqrt_decomposition(n);
  a.assign(n, 0);
  b.assign(sqrt_decomposition.n, 0);
  lazy.assign(sqrt_decomposition.n, 0);
  while (q--) {
    int type, s, t;
    std::cin >> type >> s >> t;
    --s; --t;
    if (type == 0) {
      int x;
      std::cin >> x;
      sqrt_decomposition.update(s, t + 1, x);
    } else if (type == 1) {
      std::cout << sqrt_decomposition.query(s, t + 1, 0LL) << '\n';
    }
  }
  return 0;
}
