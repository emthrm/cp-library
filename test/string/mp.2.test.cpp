/*
 * @brief 文字列/MP 法 (period(idx))
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/problemset/problem/1138/D"

#include <algorithm>
#include <iostream>
#include <string>
#include "../../string/mp.hpp"

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int zero = std::count(s.begin(), s.end(), '0'), one = std::count(s.begin(), s.end(), '1');
  MP mp(t);
  std::string ans = "";
  int period = mp.period(t.length()), pos = 0;
  while (true) {
    if (t[pos] == '0') {
      if (zero == 0) break;
      ans += '0';
      --zero;
    } else {
      if (one == 0) break;
      ans += '1';
      --one;
    }
    pos = (pos + 1) % period;
  }
  while (zero--) ans += '0';
  while (one--) ans += '1';
  std::cout << ans << '\n';
  return 0;
}
