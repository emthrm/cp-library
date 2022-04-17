/*
 * @brief 計算幾何学/計算幾何学 (線分と円の交差判定)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2276"
#define ERROR "1e-6"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>

#include "../../geometry/geometry.hpp"

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<geometry::Circle> people(n);
  for (int i = 0; i < n; ++i) {
    geometry::Point p;
    double r;
    std::cin >> p >> r;
    people[i] = geometry::Circle(p, r);
  }
  std::vector<double> l(n), r(n), comp;
  for (int i = 0; i < n; ++i) {
    const std::vector<geometry::Point> t =
        geometry::tangency(people[i], geometry::Point(0, 0));
    l[i] = t[0].arg();
    r[i] = t[1].arg();
    if (l[i] > r[i]) std::swap(l[i], r[i]);
    if (r[i] > geometry::PI &&
        geometry::has_intersected(
            people[i],
            geometry::Segment(geometry::Point(0, 0),
                              geometry::Point(2415, 0)))) {
      std::swap(l[i], r[i]);
      l[i] = 0;
    } else {
      if (l[i] < 0) l[i] = 0;
      if (r[i] > geometry::PI) r[i] = geometry::PI;
    }
    if (l[i] < geometry::PI) {
      comp.emplace_back(l[i]);
      comp.emplace_back(r[i]);
    }
  }
  std::vector<bool> is_used(n, true);
  for (int i = 0; i < n; ++i) {
    if (l[i] >= geometry::PI) is_used[i] = false;
    if (!is_used[i]) continue;
    for (int j = 0; j < n; ++j) {
      if (j != i && l[i] <= l[j] && r[j] <= r[i]) is_used[j] = false;
    }
  }
  std::vector<std::pair<double, double>> balls;
  for (int i = 0; i < n; ++i) {
    if (is_used[i]) balls.emplace_back(l[i], r[i]);
  }
  n = balls.size();
  if (n == 0) {
    std::cout << 0 << '\n';
    return 0;
  }
  std::sort(balls.begin(), balls.end());
  std::vector<std::vector<std::vector<double>>> dp(n,
      std::vector<std::vector<double>>(k + 1,
          std::vector<double>(2, std::numeric_limits<double>::lowest())));
  dp[0][0][false] = 0;
  dp[0][1][true] = balls[0].second - balls[0].first;
  for (int i = 1; i < n; ++i) {
    double left, right;
    std::tie(left, right) = balls[i];
    int x = i - 1;
    while (x >= 0 && balls[i].first <= balls[x].second) --x;
    ++x;
    if (x > i - 1) x = i - 1;
    for (int j = 0; j <= k; ++j) {
      if (j + 1 <= k) {
        dp[i][j + 1][true] =
            std::max(dp[i][j + 1][true],
                     dp[x][j][true] + right - std::max(balls[x].second, left));
        dp[i][j + 1][true] =
            std::max(dp[i][j + 1][true], dp[x][j][false] + right - left);
      }
      dp[i][j][false] =
          std::max(dp[i][j][false],
                   std::max(dp[i - 1][j][false], dp[i - 1][j][true]));
    }
  }
  double ans = 0;
  for (int y = 0; y <= k; ++y) {
    for (int z = 0; z < 2; ++z) {
      if (dp[n - 1][y][z] > ans) ans = dp[n - 1][y][z];
    }
  }
  std::cout << std::fixed << std::setprecision(7) << ans / geometry::PI << '\n';
  return 0;
}
