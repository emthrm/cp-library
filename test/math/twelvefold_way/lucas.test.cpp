#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc117/tasks/arc117_c"

#include <iostream>
#include <map>
#include <string>
#include "../../../math/modint.hpp"
#include "../../../math/twelvefold_way/lucas.hpp"

int main() {
  constexpr int C = 3;
  using ModInt = MInt<C>;
  const std::string BWR = "BWR";
  std::map<char, int> mp;
  for (int i = 0; i < C; ++i) mp[BWR[i]] = i;

  int n;
  std::cin >> n;
  std::string c;
  std::cin >> c;
  ModInt ans = 0;
  for (int i = 0; i < n; ++i) ans += lucas<C>(n - 1, i) * mp[c[i]];
  if (n % 2 == 0) ans = -ans;
  std::cout << BWR[ans.val] << '\n';
  return 0;
}
