/*
 * @brief ゲーム/ニム
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc013/tasks/arc013_3"

#include <iostream>
#include <vector>
#include "../../game/nim.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> tofu;
  while (n--) {
    int x, y, z, m;
    std::cin >> x >> y >> z >> m;
    int x_mn = x, x_mx = 0, y_mn = y, y_mx = 0, z_mn = z, z_mx = 0;
    while (m--) {
      int xi, yi, zi;
      std::cin >> xi >> yi >> zi;
      if (xi < x_mn) x_mn = xi;
      if (xi > x_mx) x_mx = xi;
      if (yi < y_mn) y_mn = yi;
      if (yi > y_mx) y_mx = yi;
      if (zi < z_mn) z_mn = zi;
      if (zi > z_mx) z_mx = zi;
    }
    tofu.emplace_back(x_mn);
    tofu.emplace_back(x - 1 - x_mx);
    tofu.emplace_back(y_mn);
    tofu.emplace_back(y - 1 - y_mx);
    tofu.emplace_back(z_mn);
    tofu.emplace_back(z - 1 - z_mx);
  }
  std::cout << (nim(tofu) ? "WIN\n" : "LOSE\n");
  return 0;
}
