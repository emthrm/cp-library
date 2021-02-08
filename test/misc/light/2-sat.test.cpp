#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <iostream>
#include <string>
#include <vector>
#include "../../../misc/light/2-sat.hpp"

int main() {
  std::string p, cnf;
  int n, m;
  std::cin >> p >> cnf >> n >> m;
  TwoSat ts(n);
  while (m--) {
    int a, b, zero;
    std::cin >> a >> b >> zero;
    if (a < 0) {
      a = ts.negate(-a - 1);
    } else {
      --a;
    }
    if (b < 0) {
      b = ts.negate(-b - 1);
    } else {
      --b;
    }
    ts.add_or(a, b);
  }
  std::vector<bool> ans = ts.build();
  std::cout << "s ";
  if (ans.empty()) {
    std::cout << "UNSATISFIABLE\n";
    return 0;
  }
  std::cout << "SATISFIABLE\nv ";
  for (int i = 0; i < n; ++i) std::cout << (i + 1) * (ans[i] ? 1 : -1) << ' ';
  std::cout << "0\n";
  return 0;
}
