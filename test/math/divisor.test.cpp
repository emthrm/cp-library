/*
 * @title 数学/約数列挙
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932"

#include <iostream>
#include <vector>

#include "emthrm/math/divisor.hpp"

int main() {
  long long n;
  std::cin >> n;
  std::vector<long long> d = emthrm::divisor(n);
  d.pop_back();
  int ans1 = 0;
  const int ans2 = d.size();
  while (!d.empty()) {
    ++ans1;
    std::vector<long long> nxt;
    for (const long long e : d) {
      if (d.back() % e != 0) nxt.emplace_back(e);
    }
    d = nxt;
  }
  std::cout << ans1 << ' ' << ans2 << '\n';
  return 0;
}
