/*
 * @brief 数学/形式的冪級数/ファウルハーバーの公式 形式的冪級数版
 */
#define PROBLEM "https://yukicoder.me/problems/no/665"

#include <iostream>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/fps/fps.hpp"
#include "../../../math/convolution/mod_convolution.hpp"
#include "../../../math/fps/faulhaber_with_fps.hpp"

int main() {
  ModInt::set_mod(1000000007);
  FPS<ModInt>::set_mul([&](const std::vector<ModInt> &a, const std::vector<ModInt> &b) -> std::vector<ModInt> {
    return mod_convolution(a, b);
  });
  long long n;
  int k;
  std::cin >> n >> k;
  Combinatorics com(k + 1);
  std::cout << faulhaber(n + 1, k, com) << '\n';
  return 0;
}
