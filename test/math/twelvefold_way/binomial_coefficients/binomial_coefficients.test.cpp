/*
 * @brief 数学/写像12相/二項係数/二項係数
 */
#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>
#include <string>
#include "../../../../math/modint.hpp"
#include "../../../../math/twelvefold_way/binomial_coefficients/binomial_coefficients.hpp"

int main() {
  constexpr int MOD = 1000000007;
  BinomialCoefficients bc(MOD, 1000000);
  using ModInt = MInt<0>;
  ModInt::set_mod(MOD);
  ModInt::init(1999999);
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    std::string n = "";
    int idx = 2;
    while (true) {
      char c = s[idx];
      if (c == ',') break;
      n += c;
      ++idx;
    }
    std::string k = s.substr(idx + 1);
    if (s[0] == 'C') {
      std::cout << bc.query(std::stoi(n), std::stoi(k));
    } else if (s[0] == 'P') {
      std::cout << ModInt::nPk(std::stoi(n), std::stoi(k));
    } else {
      std::cout << ModInt::nHk(std::stoi(n), std::stoi(k));
    }
    std::cout << '\n';
  }
  return 0;
}
