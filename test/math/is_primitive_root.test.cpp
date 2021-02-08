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
  ModInt::set_mod(p);
  std::vector<int> memo(p - 1);
  for (int root = 2; ; ++root) {
    if (is_primitive_root(root, p)) {
      for (int i = 0; i < p - 1; ++i) memo[i] = ModInt(root).pow(i).val;
      break;
    }
  }
  std::vector<int> a(p, 0), b(p, 0);
  for (int i = 1; i < p; ++i) std::cin >> a[i];
  for (int i = 1; i < p; ++i) std::cin >> b[i];
  ModInt::set_mod(998244353);
  NTT ntt;
  std::vector<ModInt> A(p - 1, 0), B(p - 1, 0);
  for (int i = 0; i < p - 1; ++i) {
    A[i] = a[memo[i]];
    B[i] = b[memo[i]];
  }
  std::vector<ModInt> C = ntt.convolution(A, B);
  for (int i = p - 1; i < C.size(); ++i) C[i % (p - 1)] += C[i];
  std::vector<ModInt> ans(p, 0);
  for (int i = 0; i < p - 1; ++i) ans[memo[i]] = C[i];
  for (int i = 1; i < p; ++i) std::cout << ans[i] << " \n"[i + 1 == p];
  return 0;
}
