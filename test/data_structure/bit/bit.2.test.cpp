/*
 * @brief データ構造/BIT/binary indexed tree (lower_bound(val))
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc033/tasks/arc033_3"

#include <iostream>
#include "../../../data_structure/bit/bit.hpp"

int main() {
  BIT<int> bit(200001);
  int q;
  std::cin >> q;
  while (q--) {
    int t, x;
    std::cin >> t >> x;
    if (t == 1) {
      bit.add(x, 1);
    } else if (t == 2) {
      int ans = bit.lower_bound(x);
      std::cout << ans << '\n';
      bit.add(ans, -1);
    }
  }
  return 0;
}
