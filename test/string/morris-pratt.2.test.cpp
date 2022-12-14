/*
 * @brief 文字列/Morris–Pratt algorithm (period(idx))
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/problemset/problem/1138/D"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

#include "emthrm/string/morris-pratt.hpp"

int main() {
  constexpr int SIGMA = 2;
  std::string s, t;
  std::cin >> s >> t;
  int num[2];
  for (int c = 0; c < SIGMA; ++c) {
    num[c] = std::count(s.begin(), s.end(), '0' + c);
  }
  const MorrisPratt morris_pratt(t);
  std::string ans = "";
  const int period = morris_pratt.period(t.length());
  for (int pos = 0; num[t[pos] - '0'] > 0; pos = (pos + 1) % period) {
    ans += t[pos];
    --num[t[pos] - '0'];
  }
  for (int c = 0; c < SIGMA; ++c) {
    ans += std::string(num[c], '0' + c);
  }
  std::cout << ans << '\n';
  return 0;
}
