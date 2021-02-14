/*
 * @brief 数学/原始根判定
 */
#define PROBLEM "https://yukicoder.me/problems/no/931"

#include <iostream>
#include <vector>
#include "../../math/modint.hpp"
#include "../../math/is_primitive_root.hpp"
#include "../../math/convolution/ntt.hpp"

int main() {
  int p;
  std::cin >> p;
  MInt<0>::set_mod(p);
  std::vector<MInt<0>> memo(p - 1);
  for (int root = 2; ; ++root) {
    if (is_primitive_root(root, p)) {
      for (int i = 0; i < p - 1; ++i) memo[i] = MInt<0>(root).pow(i);
      break;
    }
  }
  std::vector<int> a(p, 0), b(p, 0);
  for (int i = 1; i < p; ++i) std::cin >> a[i];
  for (int i = 1; i < p; ++i) std::cin >> b[i];
  MInt<1>::set_mod(998244353);
  NTT<1> ntt;
  std::vector<MInt<1>> A(p - 1, 0), B(p - 1, 0);
  for (int i = 0; i < p - 1; ++i) {
    A[i] = a[memo[i].val];
    B[i] = b[memo[i].val];
  }
  std::vector<MInt<1>> C = ntt.convolution(A, B);
  for (int i = p - 1; i < C.size(); ++i) C[i % (p - 1)] += C[i];
  std::vector<MInt<1>> ans(p, 0);
  for (int i = 0; i < p - 1; ++i) ans[memo[i].val] = C[i];
  for (int i = 1; i < p; ++i) std::cout << ans[i] << " \n"[i + 1 == p];
  return 0;
}
