/*
 * @title 数学/約数列挙
 */
#define PROBLEM "https://atcoder.jp/contests/abc170/tasks/abc170_d"

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include "emthrm/math/fast_divisor.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  const emthrm::Divisor divisor(*std::max_element(a.begin(), a.end()));
  std::multiset<int> s(a.begin(), a.end());
  std::cout << std::ranges::count_if(
                   a,
                   [&divisor, &s](const int a_i) -> bool {
                     s.erase(s.lower_bound(a_i));
                     const bool res = std::ranges::all_of(
                         divisor.query(a_i),
                         [&s](const int d) -> bool { return !s.contains(d); });
                     s.emplace(a_i);
                     return res;
                   })
            << '\n';
  return 0;
}
