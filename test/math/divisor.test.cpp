/*
 * @brief 数学/約数列挙
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932"

#include <iostream>
#include <vector>
#include "../../math/divisor.hpp"

int main() {
  long long n;
  std::cin >> n;
  std::vector<long long> d = divisor(n);
  d.pop_back();
  int cnt = 0, m = d.size();
  while (!d.empty()) {
    ++cnt;
    std::vector<long long> tmp;
    for (long long e : d) {
      if (d.back() % e != 0) tmp.emplace_back(e);
    }
    d = tmp;
  }
  std::cout << cnt << ' ' << m << '\n';
  return 0;
}
