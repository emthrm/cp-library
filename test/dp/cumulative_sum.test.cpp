/*
 * @brief 動的計画法/2次元累積和
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc086/tasks/arc089_b"

#include <iostream>
#include "../../dp/cumulative_sum.hpp"

int main() {
  int n, k;
  std::cin >> n >> k;
  CumulativeSum<int> black(k * 2, k * 2), white(k * 2, k * 2);
  while (n--) {
    int x, y;
    char c;
    std::cin >> x >> y >> c;
    x %= k * 2;
    y %= k * 2;
    (c == 'B' ? black : white).add(y, x, 1);
  }
  black.build();
  white.build();
  int ans = 0;
  for (int i = k - 1; i < k * 2; ++i) for (int j = k - 1; j < k * 2; ++j) {
    int b = black.query(i - k + 1, j - k + 1, i, j)
            + black.query(0, 0, i - k, j - k)
            + black.query(0, j + 1, i - k, k * 2 - 1)
            + black.query(i + 1, 0, k * 2 - 1, j - k)
            + black.query(i + 1, j + 1, k * 2 - 1, k * 2 - 1);
    int w = white.query(0, j - k + 1, i - k, j)
            + white.query(i - k + 1, 0, i, j - k)
            + white.query(i - k + 1, j + 1, i, k * 2 - 1)
            + white.query(i + 1, j - k + 1, k * 2 - 1, j);
    if (b + w > ans) ans = b + w;
  }
  for (int i = k - 1; i < k * 2; ++i) for (int j = k - 1; j < k * 2; ++j) {
    int b = black.query(0, j - k + 1, i - k, j)
            + black.query(i - k + 1, 0, i, j - k)
            + black.query(i - k + 1, j + 1, i, k * 2 - 1)
            + black.query(i + 1, j - k + 1, k * 2 - 1, j);
    int w = white.query(i - k + 1, j - k + 1, i, j)
            + white.query(0, 0, i - k, j - k)
            + white.query(0, j + 1, i - k, k * 2 - 1)
            + white.query(i + 1, 0, k * 2 - 1, j - k)
            + white.query(i + 1, j + 1, k * 2 - 1, k * 2 - 1);
    if (b + w > ans) ans = b + w;
  }
  std::cout << ans << '\n';
  return 0;
}
