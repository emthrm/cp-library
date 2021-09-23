/*
 * @brief 数学/約数列挙
 */
#define PROBLEM "https://atcoder.jp/contests/abc170/tasks/abc170_d"

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include "../../math/fast_divisor.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  Divisor divisor(*std::max_element(a.begin(), a.end()));
  std::multiset<int> s(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    s.erase(s.lower_bound(a[i]));
    bool meets = true;
    for (const int d : divisor.query(a[i])) {
      meets &= s.find(d) == s.end();
    }
    ans += meets;
    s.emplace(a[i]);
  }
  std::cout << ans << '\n';
  return 0;
}
