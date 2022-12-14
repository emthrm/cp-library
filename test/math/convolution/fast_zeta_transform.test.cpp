/*
 * @brief 数学/畳み込み/高速ゼータ変換
 */
#define PROBLEM "https://atcoder.jp/contests/arc100/tasks/arc100_e"
// #define PROBLEM "https://atcoder.jp/contests/arc100/tasks/arc100_c"

#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/math/convolution/fast_zeta_transform.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(1 << n, {0, 0});
  for (int i = 0; i < (1 << n); ++i) {
    std::cin >> a[i].first;
  }
  const std::function<std::pair<int, int>(const std::pair<int, int>&,
                                          const std::pair<int, int>&)> max =
      [](const std::pair<int, int>& a, const std::pair<int, int>& b)
          -> std::pair<int, int> {
        int tmp[]{a.first, a.second, b.first, b.second};
        std::sort(tmp, tmp + 4, std::greater<int>());
        return {tmp[0], tmp[1]};
      };
  a = fast_zeta_transform(a, false, {0, 0}, max);
  std::vector<int> ans(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    ans[i] = a[i].first + a[i].second;
  }
  for (int i = 1; i < (1 << n); ++i) {
    ans[i] = std::max(ans[i], ans[i - 1]);
    std::cout << ans[i] << '\n';
  }
  return 0;
}
