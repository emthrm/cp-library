/*
 * @brief 計算幾何学/計算幾何学 (線分と円の交差判定)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2276"
#define ERROR "1e-6"

#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include "../../geometry/geometry.hpp"

int main() {
  constexpr int INF = 0x3f3f3f3f;
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
    std::vector<geometry::Point> t = geometry::tangency(people[i], geometry::Point(0, 0));
    l[i] = t[0].arg(); r[i] = t[1].arg();
    if (l[i] > r[i]) std::swap(l[i], r[i]);
    if (r[i] > geometry::PI && geometry::has_intersected(people[i], geometry::Segment(geometry::Point(0, 0), geometry::Point(2415, 0)))) {
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
  std::vector<bool> use(n, true);
  for (int i = 0; i < n; ++i) {
    if (l[i] >= geometry::PI) use[i] = false;
    if (!use[i]) continue;
    for (int j = 0; j < n; ++j) {
      if (j != i && l[i] <= l[j] && r[j] <= r[i]) use[j] = false;
    }
  }
  std::vector<std::pair<double, double>> ball;
  for (int i = 0; i < n; ++i) {
    if (use[i]) ball.emplace_back(l[i], r[i]);
  }
  n = ball.size();
  if (n == 0) {
    std::cout << 0 << '\n';
    return 0;
  }
  std::sort(ball.begin(), ball.end());
  std::vector<std::vector<std::vector<double>>> dp(n, std::vector<std::vector<double>>(k + 1, std::vector<double>(2, -INF)));
  dp[0][0][false] = 0;
  dp[0][1][true] = ball[0].second - ball[0].first;
  for (int i = 1; i < n; ++i) {
    double left, right; std::tie(left, right) = ball[i];
    int x = i - 1;
    while (x >= 0 && ball[i].first <= ball[x].second) --x;
    ++x;
    if (x > i - 1) x = i - 1;
    for (int j = 0; j <= k; ++j) {
      if (j + 1 <= k) {
        if (dp[x][j][true] + right - std::max(ball[x].second, left) > dp[i][j + 1][true]) {
          dp[i][j + 1][true] = dp[x][j][true] + right - std::max(ball[x].second, left);
        }
        if (dp[x][j][false] + right - left > dp[i][j + 1][true]) {
          dp[i][j + 1][true] = dp[x][j][false] + right - left;
        }
      }
      if (std::max(dp[i - 1][j][false], dp[i - 1][j][true]) > dp[i][j][false]) {
        dp[i][j][false] = std::max(dp[i - 1][j][false], dp[i - 1][j][true]);
      }
    }
  }
  double ans = 0;
  for (int y = 0; y <= k; ++y) for (int z = 0; z < 2; ++z) {
    if (dp[n - 1][y][z] > ans) ans = dp[n - 1][y][z];
  }
  std::cout << ans / geometry::PI << '\n';
  return 0;
}
