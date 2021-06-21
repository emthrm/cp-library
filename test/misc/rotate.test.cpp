/*
 * @brief その他/回転
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2953"

#include <iostream>
#include <set>
#include <vector>
#include "../../misc/rotate.hpp"

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<char>> c(h, std::vector<char>(w));
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) std::cin >> c[i][j];
  c = rotate(c, 45);
  h = c.size();
  w = c.front().size();
  std::set<int> hor, ver;
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
    if (c[i][j] == 'B') {
      hor.emplace(i);
      ver.emplace(j);
    }
  }
  int ans = 0;
  if (hor.size() >= 2 && *hor.rbegin() - *hor.begin() > ans) ans = *hor.rbegin() - *hor.begin();
  if (ver.size() >= 2 && *ver.rbegin() - *ver.begin() > ans) ans = *ver.rbegin() - *ver.begin();
  std::cout << ans << '\n';
  return 0;
}
