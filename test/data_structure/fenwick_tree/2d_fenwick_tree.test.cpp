/*
 * @title データ構造/Fenwick tree/2次元 Fenwick tree
 */
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include <iostream>
#include <tuple>
#include <queue>

#include "emthrm/data_structure/fenwick_tree/2d_fenwick_tree.hpp"

int main() {
  int h, w, t, q;
  std::cin >> h >> w >> t >> q;
  emthrm::FenwickTree2D<int> baked(h, w), unbaked(h, w);
  std::queue<std::tuple<int, int, int>> que;
  while (q--) {
    int t_i, c, h_1, w_1;
    std::cin >> t_i >> c >> h_1 >> w_1;
    --h_1; --w_1;
    while (!que.empty() && std::get<0>(que.front()) <= t_i) {
      const int y = std::get<1>(que.front()), x = std::get<2>(que.front());
      que.pop();
      unbaked.add(y, x, -1);
      baked.add(y, x, 1);
    }
    if (c == 0) {
      unbaked.add(h_1, w_1, 1);
      que.emplace(t_i + t, h_1, w_1);
    } else if (c == 1) {
      if (baked.get(h_1, w_1) == 1) baked.add(h_1, w_1, -1);
    } else if (c == 2) {
      int h_2, w_2;
      std::cin >> h_2 >> w_2;
      --h_2; --w_2;
      std::cout << baked.sum(h_1, w_1, h_2, w_2) << ' '
                << unbaked.sum(h_1, w_1, h_2, w_2) << '\n';
    }
  }
  return 0;
}
