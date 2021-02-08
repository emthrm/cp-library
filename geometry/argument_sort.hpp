#pragma once
#include <algorithm>
#include <utility>
#include <vector>

void argument_sort(std::vector<std::pair<int, int>> &ps) {
  using Point = std::pair<int, int>;
  std::vector<Point> orthant[4];
  for (const Point &p : ps) {
    if (p.second >= 0) {
      orthant[p.first >= 0 ? 2 : 3].emplace_back(p);
    } else {
      orthant[p.first >= 0].emplace_back(p);
    }
  }
  ps.clear();
  for (int i = 0; i < 4; ++i) {
    if (i == 2) {
      std::sort(orthant[i].begin(), orthant[i].end(), [](const Point &a, const Point &b) -> bool {
        if (a.first == 0 && a.second == 0) return !(b.first == 0 && b.second == 0);
        if (b.first == 0 && b.second == 0) return false;
        return static_cast<long long>(a.first) * b.second - static_cast<long long>(a.second) * b.first > 0;
      });
    } else {
      std::sort(orthant[i].begin(), orthant[i].end(), [](const Point &a, const Point &b) -> bool {
        return static_cast<long long>(a.first) * b.second - static_cast<long long>(a.second) * b.first > 0;
      });
    }
    for (const Point &p : orthant[i]) ps.emplace_back(p);
  }
}
