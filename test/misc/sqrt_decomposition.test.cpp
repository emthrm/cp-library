/*
 * @brief その他/平方分割
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <iostream>
#include <vector>
#include "../../misc/sqrt_decomposition.hpp"

std::vector<long long> A, B, lazy;

template <typename T>
void SqrtDecomposition::partial_update(int idx, T val) {
  A[idx] += val;
  B[idx / b] += val;
}

template <typename T>
void SqrtDecomposition::total_update(int idx, T val) {
  lazy[idx] += val;
  need_to_be_eval[idx] = true;
}

template <typename T>
void SqrtDecomposition::partial_query(int idx, T &val) {
  int block = idx / b;
  if (need_to_be_eval[block]) {
    for (int i = left[block]; i < right[block]; ++i) partial_update(i, lazy[block]);
    lazy[block] = 0;
    need_to_be_eval[block] = false;
  }
  val += A[idx];
}

template <typename T>
void SqrtDecomposition::total_query(int idx, T &val) {
  val += B[idx] + lazy[idx] * (right[idx] - left[idx]);
}

int main() {
  int n, q;
  std::cin >> n >> q;
  SqrtDecomposition sd(n);
  A.assign(n, 0);
  B.assign(sd.n, 0);
  lazy.assign(sd.n, 0);
  while (q--) {
    int query, s, t;
    std::cin >> query >> s >> t;
    --s; --t;
    if (query == 0) {
      int x;
      std::cin >> x;
      sd.update(s, t + 1, x);
    } else if (query == 1) {
      std::cout << sd.query(s, t + 1, 0LL) << '\n';
    }
  }
  return 0;
}

