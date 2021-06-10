/*
 * @brief 数学/多項式
 */
#define IGNORE
#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include <iostream>
#include <tuple>
#include "../../math/modint.hpp"
#include "../../math/polynomial.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  int n, m;
  std::cin >> n >> m;
  Polynomial<ModInt> f(n - 1), g(m - 1);
  for (int i = 0; i < n; ++i) std::cin >> f[i];
  for (int i = 0; i < m; ++i) std::cin >> g[i];
  Polynomial<ModInt> q, r;
  std::tie(q, r) = f.divide(g);
  q.shrink();
  r.shrink();
  int u = (q == Polynomial<ModInt>({0}) ? 0 : q.degree() + 1);
  int v = (r == Polynomial<ModInt>({0}) ? 0 : r.degree() + 1);
  std::cout << u << ' ' << v << '\n';
  for (int i = 0; i < u; ++i) std::cout << q[i] << " \n"[i + 1 == u];
  for (int i = 0; i < v; ++i) std::cout << r[i] << " \n"[i + 1 == v];
  return 0;
}
