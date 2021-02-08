/*
 * @brief 計算幾何学/計算幾何学 (線分と円の交点)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2316"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "../../geometry/geometry.hpp"

int main() {
  constexpr double EPS = 1e-8;
  int n, a, b;
  std::cin >> n >> a >> b;
  std::vector<geometry::Point> flo(n);
  for (int i = 0; i < n; ++i) std::cin >> flo[i];
  geometry::Point now = geometry::intersection(geometry::Segment(geometry::Point(a, 0), geometry::Point(a, 200)), geometry::Segment(flo[0], flo[1])) + (flo[1] - flo[0]).unit_vector();
  int ans = 0;
  for (int i = 0; i + 2 < n; ++i) {
    double sta = std::atan2((flo[i + 1] - flo[i]).y, (flo[i + 1] - flo[i]).x);
    while (true) {
      int type = 0;
      geometry::Point p;
      bool skip;
      for (int j = i + 1; j <= i + 2 && j + 1 < n; ++j) {
        for (const geometry::Point &inter : geometry::intersection(geometry::Circle(now, 1), geometry::Segment(flo[j], flo[j + 1]))) {
          double ar = std::atan2((inter - now).y, (inter - now).x) - sta;
          if (-EPS < ar && ar < geometry::PI / 2 + EPS) {
            if (type == 0) {
              type = 1;
              p = inter;
              skip = j > i + 1;
            } else if (type == 1) {
              if (ar > std::atan2((p - now).y, (p - now).x) - sta) {
                p = inter;
                skip = j > i + 1;
              }
            }
          }
        }
      }
      for (int j = i + 1; j <= i + 2 && j + 1 < n; ++j) {
        for (const geometry::Point &inter : geometry::intersection(geometry::Circle(now, std::sqrt(2)), geometry::Segment(flo[j], flo[j + 1]))) {
          double ar = std::atan2((inter - now).y, (inter - now).x) - sta;
          if (geometry::PI / 4 - EPS < ar && ar < geometry::PI / 4 * 3 + EPS) {
            if (type == 0) {
              type = 2;
              p = inter;
              skip = j > i + 1;
            } else if (type == 1) {
              if (ar - geometry::PI / 4 > std::atan2((p - now).y, (p - now).x) - sta) {
                type = 2;
                p = inter;
                skip = j > i + 1;
              }
            } else if (type == 2) {
              if (ar > std::atan2((p - now).y, (p - now).x) - sta) {
                p = inter;
                skip = j > i + 1;
              }
            }
          }
        }
      }
      (ans += std::max(type, 1)) %= 4;
      if (type == 0) {
        now += (flo[i + 1] - flo[i]).unit_vector();
      } else {
        now = p;
        i += skip;
        break;
      }
    }
  }
  while (now.x <= b) {
    now += (flo[n - 1] - flo[n - 2]).unit_vector();
    (ans += 1) %= 4;
  }
  std::cout << std::vector<std::string>({"Red", "Green", "Blue", "White"})[ans] << '\n';
  return 0;
}
