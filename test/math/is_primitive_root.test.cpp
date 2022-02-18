/*
 * @brief 数学/原始根判定
 */
#define PROBLEM "https://yukicoder.me/problems/no/1409"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../math/is_primitive_root.hpp"
#include "../../math/mod_pow.hpp"
#include "../../util/xorshift.hpp"

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int v, x;
    std::cin >> v >> x;
    const int p = v * x + 1;
    int root = 0;
    do {
      root = xor128.rand(1, p);
    } while (!is_primitive_root(root, p));
    const long long xth_root = mod_pow(root, v, p);
    std::vector<int> a(x, 1);
    for (int i = 1; i < x; ++i) {
      a[i] = a[i - 1] * xth_root % p;
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < x; ++i) {
      std::cout << a[i] << " \n"[i + 1 == x];
    }
  }
  return 0;
}
