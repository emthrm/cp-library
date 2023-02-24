/*
 * @title 数学/一元二次方程式
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1039
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/geometry/geometry.hpp"
#include "emthrm/math/quadratic_equation.hpp"

int main() {
  constexpr double EPS = 1e-8;
  constexpr int INF = 0x3f3f3f3f;
  while (true) {
    int n, m;
    std::cin >> n >> m;
    if (n == 0 && m == 0) break;
    std::vector<std::pair<emthrm::geometry::Point, double>> dog;
    for (int i = 0; i < n; ++i) {
      emthrm::geometry::Point d;
      double v;
      std::cin >> d >> v;
      dog.emplace_back(d, v);
    }
    std::vector<int> ans(n, 0);
    while (m--) {
      emthrm::geometry::Point fp, fv;
      std::cin >> fp >> fv;
      std::vector<double> t(n, INF);
      for (int i = 0; i < n; ++i) {
        const auto [d, v] = dog[i];
        for (std::vector<double> ans =
                 emthrm::quadratic_equation(fv.norm() - v * v,
                                    emthrm::geometry::dot(fp - d, fv) * 2,
                                    (fp - d).norm());
             !ans.empty(); ans.pop_back()) {
          if (ans.back() >= 0) t[i] = ans.back();
        }
      }
      const double frisbee = *std::min_element(t.begin(), t.end());
      for (int i = 0; i < n; ++i) {
        if (std::abs(t[i] - INF) < EPS) continue;
        if (std::abs(frisbee - t[i]) < EPS) ++ans[i];
        const emthrm::geometry::Point cat = fp + fv * t[i];
        dog[i].first += (cat - dog[i].first) * frisbee / t[i];
      }
    }
    for (int i = 0; i < n; ++i) {
      std::cout << ans[i] << " \n"[i + 1 == n];
    }
  }
  return 0;
}
