/*
 * @title その他/回転
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include "emthrm/misc/rotate.hpp"

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<char>> c(h, std::vector<char>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cin >> c[i][j];
    }
  }
  c = emthrm::rotate<45>(c);
  h = c.size();
  w = c.front().size();
  int y_min = h, y_max = -1, x_min = w, x_max = -1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (c[i][j] == 'B') {
        y_min = std::min(y_min, i);
        y_max = std::max(y_max, i);
        x_min = std::min(x_min, j);
        x_max = std::max(x_max, j);
      }
    }
  }
  std::cout << std::max(y_max - y_min, x_max - x_min) << '\n';
  return 0;
}
