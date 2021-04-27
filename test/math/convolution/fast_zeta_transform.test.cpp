/*
 * @brief 数学/畳み込み/高速ゼータ変換
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc100/tasks/arc100_c"

#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include "../../../math/convolution/fast_zeta_transform.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(1 << n, {0, 0});
  for (int i = 0; i < (1 << n); ++i) std::cin >> a[i].first;
  std::vector<std::pair<int, int>> f = fast_zeta_transform(a, false, {0, 0},
    [](std::pair<int, int> a, std::pair<int, int> b) -> std::pair<int, int> {
      std::vector<int> tmp{a.first, a.second, b.first, b.second};
      std::sort(tmp.begin(), tmp.end(), std::greater<int>());
      return {tmp[0], tmp[1]};
    }
  );
  std::vector<int> ans(1 << n);
  for (int i = 0; i < (1 << n); ++i) ans[i] = f[i].first + f[i].second;
  for (int i = 1; i < (1 << n); ++i) {
    if (ans[i - 1] > ans[i]) ans[i] = ans[i - 1];
    std::cout << ans[i] << '\n';
  }
  return 0;
}
