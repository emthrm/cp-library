/*
 * @brief 文字列/ローリングハッシュ
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "../../string/rolling_hash.hpp"

int main() {
  std::string t, p;
  std::cin >> t >> p;
  const int t_size = t.length(), p_size = p.length();
  RollingHash<> rolling_hash_t(t), rolling_hash_p(p);
  for (int i = 0; i < t_size; ++i) {
    if (i + p_size <= t_size &&
        rolling_hash_t.get(i, i + p_size) == rolling_hash_p.get(0, p_size)) {
      std::cout << i << '\n';
    }
  }
  return 0;
}
