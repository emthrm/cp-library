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
  for (int i = 0; i < n; ++i) {
    std::cin >> flo[i];
  }
  geometry::Point wheel =
      geometry::intersection(
          geometry::Segment(geometry::Point(a, 0), geometry::Point(a, 200)), geometry::Segment(flo[0], flo[1]))
      + geometry::unit_vector(flo[1] - flo[0]);
  int ans = 0;
  for (int i = 0; i + 2 < n; ++i) {
    const double sta = std::atan2((flo[i + 1] - flo[i]).y,
                                  (flo[i + 1] - flo[i]).x);
    while (true) {
      int type = 0;
      geometry::Point p;
      bool must_skip = false;
      for (int j = i + 1; j <= i + 2 && j + 1 < n; ++j) {
        for (const geometry::Point& inter :
             geometry::intersection(geometry::Circle(wheel, 1),
                                    geometry::Segment(flo[j], flo[j + 1]))) {
          const double ar =
              std::atan2((inter - wheel).y, (inter - wheel).x) - sta;
          if (-EPS < ar && ar < geometry::PI / 2 + EPS) {
            if (type == 0) {
              type = 1;
              p = inter;
              must_skip = j > i + 1;
            } else if (type == 1) {
              if (ar > std::atan2((p - wheel).y, (p - wheel).x) - sta) {
                p = inter;
                must_skip = j > i + 1;
              }
            }
          }
        }
      }
      for (int j = i + 1; j <= i + 2 && j + 1 < n; ++j) {
        for (const geometry::Point& inter :
             geometry::intersection(geometry::Circle(wheel, std::sqrt(2)),
                                    geometry::Segment(flo[j], flo[j + 1]))) {
          const double ar =
              std::atan2((inter - wheel).y, (inter - wheel).x) - sta;
          if (geometry::PI / 4 - EPS < ar && ar < geometry::PI / 4 * 3 + EPS) {
            if (type == 0) {
              type = 2;
              p = inter;
              must_skip = j > i + 1;
            } else if (type == 1) {
              if (ar - geometry::PI / 4
                  > std::atan2((p - wheel).y, (p - wheel).x) - sta) {
                type = 2;
                p = inter;
                must_skip = j > i + 1;
              }
            } else if (type == 2) {
              if (ar > std::atan2((p - wheel).y, (p - wheel).x) - sta) {
                p = inter;
                must_skip = j > i + 1;
              }
            }
          }
        }
      }
      ans = (ans + std::max(type, 1)) % 4;
      if (type == 0) {
        wheel += geometry::unit_vector(flo[i + 1] - flo[i]);
      } else {
        wheel = p;
        i += must_skip;
        break;
      }
    }
  }
  while (wheel.x <= b) {
    wheel += geometry::unit_vector(flo[n - 1] - flo[n - 2]);
    ans = (ans + 1) % 4;
  }
  std::cout << std::vector<std::string>{"Red", "Green", "Blue", "White"}[ans]
            << '\n';
  return 0;
}
