/*
 * @brief 数学/原始根判定
 */
#define PROBLEM "https://yukicoder.me/problems/no/1409"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "emthrm/math/is_primitive_root.hpp"
#include "emthrm/math/mod_pow.hpp"

int main() {
  int t;
  std::cin >> t;
  std::mt19937_64 engine(std::random_device {} ());
  while (t--) {
    int v, x;
    std::cin >> v >> x;
    const int p = v * x + 1;
    std::uniform_int_distribution<int> dist(1, p - 1);
    int root = 0;
    do {
      root = dist(engine);
    } while (!emthrm::is_primitive_root(root, p));
    std::vector<int> a(x, emthrm::mod_pow(root, v, p));
    a.front() = 1;
    std::partial_sum(
        a.begin(), a.end(), a.begin(),
        [p](const int l, const int r) -> int { return l * r % p; });
    std::sort(a.begin(), a.end());
    for (int i = 0; i < x; ++i) {
      std::cout << a[i] << " \n"[i + 1 == x];
    }
  }
  return 0;
}
