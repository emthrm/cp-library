/*
 * @brief 数学/写像12相/二項係数
 */
#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    const auto it = std::find(s.begin(), s.end(), ',');
    const int n = std::stoi(std::string(std::next(s.begin(), 2), it));
    const int k = std::stoi(std::string(std::next(it), std::prev(s.end())));
    if (s.front() == 'C') {
      std::cout << ModInt::nCk(n, k) << '\n';
    } else if (s.front() == 'P') {
      std::cout << ModInt::nPk(n, k) << '\n';
    } else if (s.front() == 'H') {
      std::cout << ModInt::nHk(n, k) << '\n';
    }
  }
  return 0;
}
