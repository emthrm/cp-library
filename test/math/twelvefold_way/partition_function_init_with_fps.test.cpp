/*
 * @brief 数学/写像12相/分割数 $n = m$ 版
 */
#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/convolution/ntt.hpp"
#include "../../../math/fps/fps.hpp"
#include "../../../math/twelvefold_way/partition_function_init_with_fps.hpp"

int main() {
  ModInt::set_mod(998244353);
  NTT ntt;
  FPS<ModInt>::set_mul([&](const std::vector<ModInt> &a, const std::vector<ModInt> &b) -> std::vector<ModInt> {
    return ntt.convolution(a, b);
  });
  int n;
  std::cin >> n;
  std::vector<ModInt> p = partition_function_init_with_fps<ModInt>(n);
  for (int i = 0; i <= n; ++i) std::cout << p[i] << " \n"[i == n];
  return 0;
}
