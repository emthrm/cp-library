/*
 * @brief 数学/写像12相/二項係数
 */
#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>
#include <string>
#include "../../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    std::string n = "";
    int idx = 2;
    for (; s[idx] != ','; ++idx) n += s[idx];
    std::string k = s.substr(idx + 1);
    if (s[0] == 'C') {
      std::cout << ModInt::nCk(stoi(n), stoi(k)) << '\n';
    } else if (s[0] == 'P') {
      std::cout << ModInt::nPk(stoi(n), stoi(k)) << '\n';
    } else {
      std::cout << ModInt::nHk(stoi(n), stoi(k)) << '\n';
    }
  }
  return 0;
}
