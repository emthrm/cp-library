/*
 * @brief 数学/行列/連立一次方程式
 */
#define IGNORE
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0004"

#include <iomanip>
#include <iostream>
#include <vector>
#include "../../../math/matrix/matrix.hpp"
#include "../../../math/matrix/gauss_jordan.hpp"
#include "../../../math/matrix/linear_equation.hpp"

int main() {
  constexpr double EPS = 1e-8;
  std::cout << std::fixed << std::setprecision(3);
  int a, b, c, d, e, f;
  while (std::cin >> a >> b >> c >> d >> e >> f) {
    Matrix<int> l(2, 2);
    l[0][0] = a; l[0][1] = b;
    l[1][0] = d; l[1][1] = e;
    std::vector<int> r{c, f};
    std::vector<double> ans = linear_equation(l, r, EPS);
    std::cout << ans[0] << ' ' << ans[1] << '\n';
  }
  return 0;
}
