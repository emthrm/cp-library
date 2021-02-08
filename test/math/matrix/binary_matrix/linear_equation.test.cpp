/*
 * @brief 数学/行列/バイナリ行列/連立一次方程式 バイナリ行列版
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308"

#include <cmath>
#include <iostream>
#include <vector>
#include "../../../../math/matrix/binary_matrix/binary_matrix.hpp"
#include "../../../../math/matrix/binary_matrix/linear_equation.hpp"

int main() {
  while (true) {
    int m, n, d;
    std::cin >> m >> n >> d;
    if (m == 0 && n == 0 && d == 0) break;
    std::vector<std::vector<int>> s(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) std::cin >> s[i][j];
    BinaryMatrix<625> bm(n * m, n * m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      int now = i * m + j;
      bm[now][now] = 1;
      for (int x = j - d; x <= j + d; ++x) {
        if (0 <= x && x < m) {
          int y = i + d - std::abs(x - j);
          if (0 <= y && y < n) bm[now][y * m + x] = 1;
          y = i - (d - std::abs(x - j));
          if (0 <= y && y < n) bm[now][y * m + x] = 1;
        }
      }
    }
    std::vector<int> v(n * m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) v[i * m + j] = s[i][j] == 1;
    std::cout << !linear_equation(bm, v).empty() << '\n';
  }
  return 0;
}
