/*
 * @brief その他/2-SAT
 */
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <iostream>
#include <string>
#include <vector>

#include "../../misc/2-sat.hpp"

int main() {
  std::string p, cnf;
  int n, m;
  std::cin >> p >> cnf >> n >> m;
  TwoSat two_sat(n);
  while (m--) {
    int a, b, zero;
    std::cin >> a >> b >> zero;
    if (a < 0) {
      a = two_sat.negate(-a - 1);
    } else {
      --a;
    }
    if (b < 0) {
      b = two_sat.negate(-b - 1);
    } else {
      --b;
    }
    two_sat.add_or(a, b);
  }
  const std::vector<bool> ans = two_sat.build();
  std::cout << "s ";
  if (ans.empty()) {
    std::cout << "UNSATISFIABLE\n";
    return 0;
  }
  std::cout << "SATISFIABLE\nv ";
  for (int i = 0; i < n; ++i) {
    std::cout << (i + 1) * (ans[i] ? 1 : -1) << ' ';
  }
  std::cout << "0\n";
  return 0;
}
